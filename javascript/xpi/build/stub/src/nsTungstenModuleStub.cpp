/*
 * Copyright 2005,2006 WSO2, Inc. http://www.wso2.org
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "stdio.h"
#include "stdlib.h"
#include "nsMemory.h"
#include "plstr.h"

#include "nscore.h"
#include "nsModule.h"
#include "prlink.h"

#include "nsString.h"
#include "nsStringAPI.h"
#include "nsILocalFile.h"
#include "nsEmbedString.h"
#include "nsISimpleEnumerator.h"
#include "nsDirectoryServiceDefs.h"

#define AXIS2C_CLIENT_HOME_DIR "AXIS2C_HOME"
#define AXIS2C_CLIENT_HOME_ENV "AXIS2C_HOME"
#define AXIS2C_HOME_ENV "AXIS2C_HOME"
#define AXIS2C_HOME_DIR "deploy"

//TODO: Extend this to any platforms
//anyway still win libs and linux libs are different
#define MOZ_DLL_PREFIX "lib"
//////////////////////////////////////////////////
// supporting tools

#ifndef WIN32

const char* axis2_libs[] = 
{
  /* axis2 libraries */
  MOZ_DLL_PREFIX "axis2_minizip" MOZ_DLL_SUFFIX, 
  MOZ_DLL_PREFIX "axis2_util" MOZ_DLL_SUFFIX,
  MOZ_DLL_PREFIX "axis2_parser" MOZ_DLL_SUFFIX,
  MOZ_DLL_PREFIX "axis2_axiom" MOZ_DLL_SUFFIX,
  /*MOZ_DLL_PREFIX "axis2_wom" MOZ_DLL_SUFFIX,  */
  MOZ_DLL_PREFIX "axis2_wsdl" MOZ_DLL_SUFFIX,
  MOZ_DLL_PREFIX "axis2_xml_schema" MOZ_DLL_SUFFIX, 
  MOZ_DLL_PREFIX "woden_wsdl" MOZ_DLL_SUFFIX, 
  MOZ_DLL_PREFIX "woden" MOZ_DLL_SUFFIX,
  MOZ_DLL_PREFIX "axis2_engine" MOZ_DLL_SUFFIX,
  MOZ_DLL_PREFIX "axis2_http_sender" MOZ_DLL_SUFFIX,
  MOZ_DLL_PREFIX "axis2_http_receiver" MOZ_DLL_SUFFIX,
  
}; 

const char* axis2_addr_lib=
  /* addressing library */
  MOZ_DLL_PREFIX "axis2_mod_addr" MOZ_DLL_SUFFIX;

const char* skel_lib = 
  /* component library */
  MOZ_DLL_PREFIX "tungsten_skel" MOZ_DLL_SUFFIX;

#else

const char* axis2_libs[] = 
{
  /* axis2 libraries */
  "iconv" MOZ_DLL_SUFFIX,
  "zlib1" MOZ_DLL_SUFFIX,
  "libxml2" MOZ_DLL_SUFFIX, 
  "axis2_util" MOZ_DLL_SUFFIX,
  "axis2_parser" MOZ_DLL_SUFFIX,
  "axiom" MOZ_DLL_SUFFIX,
  "axis2_wsdl" MOZ_DLL_SUFFIX,
  "axis2_engine" MOZ_DLL_SUFFIX,
  "axis2_http_sender" MOZ_DLL_SUFFIX,
  "axis2_http_receiver" MOZ_DLL_SUFFIX,
}; 

const char* axis2_addr_lib=
  /* addressing library */
  "axis2_mod_addr" MOZ_DLL_SUFFIX;

const char* skel_lib = 
  /* component library */
  "tungsten_skel" MOZ_DLL_SUFFIX;


#endif /** ifndef win32 */

//////////////////////////////////////////////////
// Define the module
NS_EXPORT nsresult PR_CALLBACK
NSGetModule(nsIComponentManager* aCompMgr,
            nsIFile* aLocation,
            nsIModule* *aResult)
{

  nsresult rv;
  FILE* flog = NULL;
  /////////////////////////////////////////////////////////// 
  //Following code traverse from tungsten_stub to
  // ../../../ -> Extension folder
  nsEmbedCString path;
  aLocation-> GetNativeLeafName (path); //libaxis2.so

  nsCOMPtr<nsIFile> components;
  aLocation-> GetParent(getter_AddRefs ( components) ); //components
 
  nsCOMPtr<nsIFile> extension;
  components-> GetParent(getter_AddRefs ( extension) ); //extension folder

  /////////////////////////////////////////////////////////// 
  //Following code traverse from extension to
  //deploy/lib
  flog = fopen("wsrequest.xpi.log", "w+");
  extension -> GetNativeLeafName (path); //libaxis2.so
  if ( path.Equals("bin" ) )
  {
    printf(" Natural case\n" );
    printf(" Only occured if compiled and running;)\n");
    printf(" Please delete $MOZILLA_SRC/dist/bin/components/*tungsten*\n");
    return NS_OK; //It s really ok
  }
  nsCOMPtr<nsILocalFile> libraries;
  libraries = do_QueryInterface (extension );
  
  //libraries -> SetNativeLeafName(NS_LITERAL_CSTRING("deploy"));
  libraries ->AppendNative(NS_LITERAL_CSTRING("deploy"));
  
  libraries ->AppendNative(NS_LITERAL_CSTRING("lib"));
  
  libraries ->AppendNative(NS_LITERAL_CSTRING("lib_dummy"));//dummy replaced to \/

  int axis2_libs_size = sizeof ( axis2_libs ) / sizeof ( char* ) ;
  PRLibrary* lib;
  for (int i = 0 ; i < axis2_libs_size ; i ++ )
  {
    NS_CStringSetData( path, axis2_libs[i] );
    libraries -> SetNativeLeafName ( path  );
    rv = libraries -> Load (&lib );
    if ( NS_SUCCEEDED ( rv ) )
    {
      printf("%s is succesful\n", axis2_libs[i] );
      fprintf(flog, "%s is succesful\n", axis2_libs[i] );
    }
    else
    {
      printf("%s is failed\n", axis2_libs[i] );
      fprintf(flog, "%s is failed\n", axis2_libs[i] );
    }
  }

  /////////////////////////////////////////////////////////// 
  //Following code traverse from extension to
  //deploy/modules/addresing/libtungsten_skel.so
  components-> GetParent(getter_AddRefs ( extension) ); //extension folder
  libraries = do_QueryInterface (extension );

  libraries ->AppendNative(NS_LITERAL_CSTRING("deploy"));
  libraries ->AppendNative(NS_LITERAL_CSTRING("modules"));
  libraries ->AppendNative(NS_LITERAL_CSTRING("addressing"));
  NS_CStringSetData( path, axis2_addr_lib );
  libraries -> AppendNative( path  );

  rv = libraries -> Load (&lib );
  if ( NS_SUCCEEDED ( rv ) )
  {
    printf("%s is succesful\n", axis2_addr_lib );
    fprintf(flog, "%s is succesful\n", axis2_addr_lib );
  }
  else
  {
    printf("%s is failed\n", axis2_addr_lib );
    fprintf(flog, "%s is failed\n", axis2_addr_lib );
  }
  
  /////////////////////////////////////////////////////////// 
  //Following code traverse from extension to
  //skel/libtungsten_skel.so
  components-> GetParent(getter_AddRefs ( extension) ); //extension folder
  libraries = do_QueryInterface (extension );

  libraries ->AppendNative(NS_LITERAL_CSTRING("skel"));
  NS_CStringSetData( path, skel_lib);
  libraries -> AppendNative( path  );

  rv = libraries -> Load (&lib );
  if ( NS_SUCCEEDED ( rv ) )
  {
    printf("%s is succesful\n", skel_lib);
    fprintf(flog, "%s is succesful\n", skel_lib);
  }
  else
  {
    printf("%s is failed\n", skel_lib );
    fprintf(flog,"%s is failed\n", skel_lib );
    fclose(flog);
    return rv; //no way this can continue without this
  }
  
  nsGetModuleProc getmoduleproc = 
    (nsGetModuleProc)PR_FindFunctionSymbol(lib, NS_GET_MODULE_SYMBOL);

  if (!getmoduleproc)
  {
    fclose(flog);
    return NS_ERROR_FAILURE;
  }

  fclose(flog);
  return getmoduleproc(aCompMgr, aLocation, aResult);  
}

