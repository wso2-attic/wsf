/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <config.h>

#include <sys/ioctl.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>

#ifdef HAVE_LINUX_IF_H
# include <linux/if.h>
#else
# ifdef HAVE_NET_IF_H
#  include <sys/sockio.h>
#  include <net/if.h>
#  include <net/if_arp.h>
# endif
# ifdef HAVE_NET_IF_TYPES_H
#  include <net/if_types.h>
# endif
# ifdef HAVE_NET_IF_DL_H
#  include <net/if_dl.h>
# endif
#endif

#include <platforms/unix/axutil_uuid_gen_unix.h>
#include <platforms/axutil_platform_auto_sense.h>


/* We need these static variables to track throughout the program execution */
static axis2_bool_t axutil_uuid_gen_is_first = AXIS2_TRUE;
static struct axutil_uuid_st axutil_uuid_static;


axutil_uuid_t* AXIS2_CALL
axutil_uuid_gen_v1()
{
    struct timeval time_now;
    struct timeval tv;
    unsigned long long time_val;
    unsigned long long time_val2;
    unsigned short int clck = 0;
    axutil_uuid_t *ret_uuid = NULL;
    unsigned short int time_high_version = 0;

    if (AXIS2_TRUE == axutil_uuid_gen_is_first)
    {
        char *mac_addr = axutil_uuid_get_mac_addr();
        memcpy(axutil_uuid_static.mac, mac_addr, 6);
        axutil_uuid_static.time_seq = 0;
        axutil_uuid_static.clock = 0;
        free(mac_addr);
        axutil_uuid_gen_is_first = AXIS2_FALSE;
    }
    /*
     *  GENERATE TIME
     */

    /* determine current system time and sequence counter */
    if (gettimeofday(&time_now, NULL) == -1)
        return NULL;

    /* check whether system time changed since last retrieve */
    if (!(time_now.tv_sec  == axutil_uuid_static.time_last.tv_sec
        && time_now.tv_usec ==
        axutil_uuid_static.time_last.tv_usec))
    {
        /* reset time sequence counter and continue */
        axutil_uuid_static.time_seq = 0;
    }

    /* until we are out of UUIDs per tick, increment
    the time/tick sequence counter and continue */
    while (axutil_uuid_static.time_seq < UUIDS_PER_TICK)
    {
        axutil_uuid_static.time_seq++;
    }
    /* sleep for 1000ns (1us) */
    tv.tv_sec  = 0;
    tv.tv_usec = 1;
    /*
        The following select causes severe performance problems. 
        Hence commenting out. I am not sure why this is required. - Samisa.    
    select(0, NULL, NULL, NULL, &tv);*/

    time_val = (unsigned long long)time_now.tv_sec * 10000000ull;
    time_val += (unsigned long long)time_now.tv_usec * 10ull;

    ret_uuid = malloc(sizeof(axutil_uuid_t));

    time_val += UUID_TIMEOFFSET;
    /* compensate for low resolution system clock by adding
       the time/tick sequence counter */
    if (axutil_uuid_static.time_seq > 0)
        time_val += (unsigned long long)axutil_uuid_static.time_seq;

    time_val2 = time_val;
    ret_uuid->time_low = (unsigned long)time_val2;
    time_val2 >>= 32;
    ret_uuid->time_mid = (unsigned short int)time_val2;
    time_val2 >>= 16;
    time_high_version = (unsigned short int)time_val2;

    /* store the 60 LSB of the time in the UUID and make version 1*/
    time_high_version <<= 4;
    time_high_version &= 0xFFF0;
    time_high_version |= 0x0001;
    ret_uuid->time_high_version = time_high_version;

    /*
      *  GENERATE CLOCK
      */

    /* retrieve current clock sequence */
    clck = axutil_uuid_static.clock;

    /* generate new random clock sequence (initially or if the
       time has stepped backwards) or else just increase it */
    if (clck == 0 || (time_now.tv_sec < axutil_uuid_static.time_last.tv_sec ||
        (time_now.tv_sec == axutil_uuid_static.time_last.tv_sec
        && time_now.tv_usec < axutil_uuid_static.time_last.tv_usec)))
    {
        srand(time_now.tv_usec);
        clck = rand();
    }
    else
    {
        clck++;
    }
    clck %= (2 << 14);

    /* store back new clock sequence */
    axutil_uuid_static.clock = clck;

    clck &= 0x1FFF;
    clck |= 0x2000;

    /*
     *  FINISH
     */
    /* remember current system time for next iteration */
    axutil_uuid_static.time_last.tv_sec  = time_now.tv_sec;
    axutil_uuid_static.time_last.tv_usec = time_now.tv_usec;

    if (! ret_uuid)
    {
        return NULL;
    }
    ret_uuid->clock_variant = clck;
    memcpy(ret_uuid->mac_addr, axutil_uuid_static.mac, 6);
    return ret_uuid;
}


axis2_char_t* AXIS2_CALL
axutil_platform_uuid_gen(char *s)
{
    axutil_uuid_t *uuid_struct = NULL;
    axis2_char_t *uuid_str = NULL;
    unsigned char mac[7];
    char mac_hex[13];

    if (! s)
    {
        return NULL;
    }
    uuid_struct = axutil_uuid_gen_v1();
    if (! uuid_struct)
    {
        return NULL;
    }
    uuid_str = s;
    if (! uuid_str)
    {
        return NULL;
    }
    memcpy(mac, uuid_struct->mac_addr, 6);
    sprintf(mac_hex, "%02x%02x%02x%02x%02x%02x", mac[0], mac[1], mac[2], mac[3]
        , mac[4], mac[5]);
    sprintf(uuid_str, "%08x-%04x-%04x-%04x-%s", uuid_struct->time_low,
        uuid_struct->time_mid, uuid_struct->time_high_version,
        uuid_struct->clock_variant, mac_hex);
    free(uuid_struct);
    uuid_struct = NULL;
    return uuid_str;
}

#ifdef HAVE_LINUX_IF_H   /* Linux */

char * AXIS2_CALL
axutil_uuid_get_mac_addr()
{
    struct ifreq ifr;
    struct ifreq *IFR;
    struct ifconf ifc;
    struct sockaddr *sa;
    int s = 0;
    int i = 0;
    char *buffer = NULL;
    char buf[1024];
    int ok = AXIS2_FALSE;

    if ((s = socket(PF_INET, SOCK_DGRAM, 0)) < 0)
        return NULL;

    ifc.ifc_len = sizeof(buf);
    ifc.ifc_buf = buf;
    ioctl(s, SIOCGIFCONF, &ifc);
    IFR = ifc.ifc_req;

    for(i = ifc.ifc_len/sizeof(struct ifreq); --i >=0; IFR++)
    {
        strcpy(ifr.ifr_name, IFR->ifr_name);
        /*sprintf(ifr.ifr_name, "eth0");*/
        if (ioctl(s, SIOCGIFFLAGS, &ifr) == 0)
        {
            if(!(ifr.ifr_flags & IFF_LOOPBACK))
            {
                if (ioctl(s, SIOCGIFHWADDR, &ifr) == 0)
                {
                    ok = AXIS2_TRUE;
                    break;
                }
            }
        }
    }
    buffer = (char*)malloc(6 * sizeof(char));
    if(ok)
    {
        sa = (struct sockaddr *) & ifr.ifr_addr;
        for (i = 0; i < 6; i++)
            buffer[i] = (unsigned char)(sa->sa_data[i] & 0xff);
    }
    else
    {
        for (i = 0; i < 6; i++)
            buffer[i] = (unsigned char)((AXIS2_LOCAL_MAC_ADDR[i]) - '0');
    }
    close(s);
    return buffer;
}

#else

#ifdef IS_MACOSX  /* Darwin */

#ifndef max
# define        max(a,b)        ((a) > (b) ? (a) : (b))
#endif /* !max */

char * AXIS2_CALL
axutil_uuid_get_mac_addr()
{
    struct ifconf ifc;
    struct ifreq *ifr;
    int sockfd;
    char buffer[512], *cp, *cplim;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        perror("socket failed");
        return NULL;
    }

    ifc.ifc_len = 512;
    ifc.ifc_buf = buffer;

    if (ioctl(sockfd, SIOCGIFCONF, (char *)&ifc) < 0)
    {
        perror("ioctl error");
        close(sockfd);
        return NULL;
    }

    ifr = ifc.ifc_req;

    cplim = buffer + ifc.ifc_len;

    char * macaddr = NULL;

    for (cp = buffer; cp < cplim && macaddr == NULL;)
    {
        ifr = (struct ifreq *)cp;
        if (ifr->ifr_addr.sa_family == AF_LINK)
        {
            struct sockaddr_dl *sdl = (struct sockaddr_dl *) & ifr->ifr_addr;

            /* just take the ethernet adapters */
            if (sdl->sdl_type == IFT_ETHER)
            {
                macaddr = (char *)ether_ntoa(LLADDR(sdl));
            }
        }
        cp += sizeof(ifr->ifr_name) + max(sizeof(ifr->ifr_addr), ifr->ifr_addr.sa_len);

    }

    close(sockfd);
    return macaddr;
}
# else /* Solaris-ish */

/* code modified from that posted on:
* http://forum.sun.com/jive/thread.jspa?threadID=84804&tstart=30
*/


char * AXIS2_CALL
axutil_uuid_get_mac_addr()
{
    char hostname[MAXHOSTNAMELEN];
    char *data_ptr;
    struct hostent *he;
    struct arpreq ar;
    struct sockaddr_in *sa;
    int s;
    int i;

    if (gethostname(hostname, sizeof(hostname)) < 0)
    	return NULL;
    if ((he = gethostbyname(hostname)) == NULL)
    	return NULL;
    if ((s = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
    	return NULL;
    memset(&ar, 0, sizeof(ar));
    sa = (struct sockaddr_in *)((void *)&(ar.arp_pa));
    sa->sin_family = AF_INET;
    memcpy(&(sa->sin_addr), *(he->h_addr_list), sizeof(struct in_addr));
    if (ioctl(s, SIOCGARP, &ar) < 0) {
    	close(s);
    	return NULL;
    }
    close(s);
    if (!(ar.arp_flags & ATF_COM))
    	return NULL;
	data_ptr = malloc(6*sizeof(char));
    for (i = 0; i < 6; i++)
    	data_ptr[i] = (unsigned char)(ar.arp_ha.sa_data[i] & 0xff);

    return data_ptr;
}

/*
    int sock;
    int i;
    struct lifconf lic;
    struct lifreq *lifrs;
    struct lifnum num;
*/
    /* How many interfaces do we have? */
 /*   sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_IP);
    num.lifn_family = AF_INET;
    num.lifn_flags = 0;
    ioctl(sock, SIOCGLIFNUM, &num);
*/
    /* get details of the interfaces */
 /*   lifrs = malloc((num.lifn_count + 1) * sizeof(*lifrs));
    if (! lifrs)
    {*/
        /*exit(1); *//* what is the right error handling here ? */
/*    }
    lic.lifc_family = AF_INET;
    lic.lifc_flags = 0;
    lic.lifc_len = sizeof(lifrs);
    lic.lifc_buf = (caddr_t)lifrs;
    ioctl(sock, SIOCGLIFCONF, &lic);
*/
    /* Get the ethernet address for each of them */
 /*   for (i = 0;i < num.lifn_count;i++)
    {
        struct sockaddr_in *soapip, *soapmac;
        struct arpreq ar;
*/
        /* Get IP address of interface i */
 /*       ioctl(sock, SIOCGLIFADDR, &(lifrs[ i ]));
        soapip = (struct sockaddr_in *) & (lifrs[ i ].lifr_addr);
*/

        /* Get ethernet address */
/*        soapmac = (struct sockaddr_in *) & (ar.arp_pa);
        *soapmac = *soapip;

        if (ioctl(sock, SIOCGARP, &ar) == 0)
        {
            int j;
            char *buffer = malloc(6);

            if (buffer)
            {
                for (j = 0 ; j < 6 ; ++j)
                {
                    buffer[j] = ((unsigned char *) & (ar.arp_ha.sa_data))[j];
                }
            }
            close(sock);
            free(lifrs);
            return buffer;
        }
    }
    close(sock);
    free(lifrs);
    return NULL;
}*/
# endif
#endif
