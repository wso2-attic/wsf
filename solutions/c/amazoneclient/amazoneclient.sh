soap="false"
dump="false"

if test -z $WSFC_HOME; then
    WSFC_HOME=$PWD/../../..
fi

function getoptex()
{
  let $# || return 1
  local optlist="${1#;}"
  let OPTIND || OPTIND=1
  [ $OPTIND -lt $# ] || return 1
  shift $OPTIND
  if [ "$1" != "-" -a "$1" != "${1#-}" ]
  then OPTIND=$[OPTIND+1]; if [ "$1" != "--" ]
  then
    local o
    o="-${1#-$OPTOFS}"
    for opt in ${optlist#;}
    do
      OPTOPT="${opt%[;.:]}"
      unset OPTARG
      local opttype="${opt##*[^;:.]}"
      [ -z "$opttype" ] && opttype=";"
      if [ ${#OPTOPT} -gt 1 ]
      then # long-named option
        case $o in
          "--$OPTOPT")
            if [ "$opttype" != ":" ]; then return 0; fi
            OPTARG="$2"
            if [ -z "$OPTARG" ];
            then # error: must have an agrument
              let OPTERR && echo "$0: error: $OPTOPT must have an argument" >&2
              OPTARG="$OPTOPT";
              OPTOPT="?"
              return 1;
            fi
            OPTIND=$[OPTIND+1] # skip option's argument
            return 0
          ;;
          "--$OPTOPT="*)
            if [ "$opttype" = ";" ];
            then  # error: must not have arguments
              let OPTERR && echo "$0: error: $OPTOPT must not have arguments" >&2
              OPTARG="$OPTOPT"
              OPTOPT="?"
              return 1
            fi
            OPTARG=${o#"--$OPTOPT="}
            return 0
          ;;
        esac
      else # short-named option
        case "$o" in
          "-$OPTOPT")
            unset OPTOFS
            [ "$opttype" != ":" ] && return 0
            OPTARG="$2"
            if [ -z "$OPTARG" ]
            then
              echo "$0: error: -$OPTOPT must have an argument" >&2
              OPTARG="$OPTOPT"
              OPTOPT="?"
              return 1
            fi
            OPTIND=$[OPTIND+1] # skip option's argument
            return 0
          ;;
          "-$OPTOPT"*)
            if [ $opttype = ";" ]
            then # an option with no argument is in a chain of options
              OPTOFS="$OPTOFS?" # move to the next option in the chain
              OPTIND=$[OPTIND-1] # the chain still has other options
              return 0
            else
              unset OPTOFS
              OPTARG="${o#-$OPTOPT}"
              return 0
            fi
          ;;
        esac
      fi
    done
    echo "$0: error: invalid option: $o"
  fi; fi
  OPTOPT="?"
  unset OPTARG
  return 1
}
function optlistex
{
  local l="$1"
  local m # mask
  local r # to store result
  while [ ${#m} -lt $[${#l}-1] ]; do m="$m?"; done # create a "???..." mask
  while [ -n "$l" ]
  do
    r="${r:+"$r "}${l%$m}" # append the first character of $l to $r
    l="${l#?}" # cut the first charecter from $l
    m="${m#?}"  # cut one "?" sign from m
    if [ -n "${l%%[^:.;]*}" ]
    then # a special character (";", ".", or ":") was found
      r="$r${l%$m}" # append it to $r
      l="${l#?}" # cut the special character from l
      m="${m#?}"  # cut one more "?" sign
    fi
  done
  echo $r
}
function getopt()
{
  local optlist=`optlistex "$1"`
  shift
  getoptex "$optlist" "$@"
  return $?
}

function item_search()
{
    echo "<n:ItemSearch xmlns:n=\"http://webservices.amazon.com/AWSECommerceService/2007-10-29\">" > ItemSearch.xml
    echo "<n:SubscriptionId>$1</n:SubscriptionId>" >> ItemSearch.xml
    if [ "$soap" == "true" ]; then
        echo "<n:Request>" >> ItemSearch.xml
    else
        echo "<n:Service>AWSECommerceService</n:Service>" >> ItemSearch.xml
        echo "<n:Operation>ItemSearch</n:Operation>" >> ItemSearch.xml
    fi
    for arg in "$@"
    do
        i=`expr index $arg :`
        if [ $i -gt 0 ]; then
            key=${arg:0:$i-1}
            len=${#arg}
            value=${arg:$i:$len}
        else
            continue
        fi
        if [ "$key" == "Actor" ]; then
            echo "<n:Actor>$value</n:Actor>" >> ItemSearch.xml
        elif [ "$key" == "Artist" ]; then
            echo "<n:Artist>$value</n:Artist>" >> ItemSearch.xml
        elif [ "$key" == "Availability" ]; then
            echo "<n:Availability>$value</n:Availability>" >> ItemSearch.xml
        elif [ "$key" == "Author" ]; then
            echo "<n:Author>$value</n:Author>" >> ItemSearch.xml
        elif [ "$key" == "Brand" ]; then
            echo "<n:Brand>$value</n:Brand>" >> ItemSearch.xml
        elif [ "$key" == "BrowseNode" ]; then
            echo "<n:BrowseNode>$value</n:BrowseNode>" >> ItemSearch.xml
        elif [ "$key" == "City" ]; then
            echo "<n:City>$value</n:City>" >> ItemSearch.xml
        elif [ "$key" == "Composer" ]; then
            echo "<n:Composer>$value</n:Composer>" >> ItemSearch.xml
        elif [ "$key" == "Conductor" ]; then
            echo "<n:Conductor>$value</n:Conductor>" >> ItemSearch.xml
        elif [ "$key" == "Count" ]; then
            echo "<n:Count>$value</n:Count>" >> ItemSearch.xml
        elif [ "$key" == "Cuisine" ]; then
            echo "<n:Cuisine>$value</n:Cuisine>" >> ItemSearch.xml
        elif [ "$key" == "Director" ]; then
            echo "<n:Director>$value</n:Director>" >> ItemSearch.xml
        elif [ "$key" == "FutureLaunchDate" ]; then
            echo "<n:FutureLaunchDate>$value</n:FutureLaunchDate>" >> ItemSearch.xml
        elif [ "$key" == "ISPUPostalCode" ]; then
            echo "<n:ISPUPostalCode>$value</n:ISPUPostalCode>" >> ItemSearch.xml
        elif [ "$key" == "ItemPage" ]; then
            echo "<n:ItemPage>$value</n:ItemPage>" >> ItemSearch.xml
        elif [ "$key" == "Keywords" ]; then
            echo "<n:Keywords>$value</n:Keywords>" >> ItemSearch.xml
        elif [ "$key" == "Manufacturer" ]; then
            echo "<n:Manufacturer>$value</n:Manufacturer>" >> ItemSearch.xml
        elif [ "$key" == "MaximumPrice" ]; then
            echo "<n:MaximumPrice>$value</n:MaximumPrice>" >> ItemSearch.xml
        elif [ "$key" == "MerchantId" ]; then
            echo "<n:MerchantId>$value</n:MerchantId>" >> ItemSearch.xml
        elif [ "$key" == "MinimumPrice" ]; then
            echo "<n:MinimumPrice>$value</n:MinimumPrice>" >> ItemSearch.xml
        elif [ "$key" == "MusicLabel" ]; then
            echo "<n:MusicLabel>$value</n:MusicLabel>" >> ItemSearch.xml
        elif [ "$key" == "Neighborhood" ]; then
            echo "<n:Neighborhood>$value</n:Neighborhood>" >> ItemSearch.xml
        elif [ "$key" == "Orchestra" ]; then
            echo "<n:Orchestra>$value</n:Orchestra>" >> ItemSearch.xml
        elif [ "$key" == "PostalCode" ]; then
            echo "<n:PostalCode>$value</n:PostalCode>" >> ItemSearch.xml
        elif [ "$key" == "Power" ]; then
            echo "<n:Power>$value</n:Power>" >> ItemSearch.xml
        elif [ "$key" == "Publisher" ]; then
            echo "<n:Publisher>$value</n:Publisher>" >> ItemSearch.xml
        elif [ "$key" == "ResponseGroup" ]; then
            echo "<n:ResponseGroup>$value</n:ResponseGroup>" >> ItemSearch.xml
        elif [ "$key" == "ReviewSort" ]; then
            echo "<n:ReviewSort>$value</n:ReviewSort>" >> ItemSearch.xml
        elif [ "$key" == "SearchIndex" ]; then
            echo "<n:SearchIndex>$value</n:SearchIndex>" >> ItemSearch.xml
        elif [ "$key" == "Sort" ]; then
            echo "<n:Sort>$value</n:Sort>" >> ItemSearch.xml
        elif [ "$key" == "State" ]; then
            echo "<n:State>$value</n:State>" >> ItemSearch.xml
        elif [ "$key" == "TagPage" ]; then
            echo "<n:TagPage>$value</n:TagPage>" >> ItemSearch.xml
        elif [ "$key" == "TagsPerPage" ]; then
            echo "<n:TagsPerPage>$value</n:TagsPerPage>" >> ItemSearch.xml
        elif [ "$key" == "TagSort" ]; then
            echo "<n:TagSort>$value</n:TagSort>" >> ItemSearch.xml
        elif [ "$key" == "TextStream" ]; then
            echo "<n:TextStream>$value</n:TextStream>" >> ItemSearch.xml
        elif [ "$key" == "Title" ]; then
            echo "<n:Title>$value</n:Title>" >> ItemSearch.xml
        elif [ "$key" == "ReleaseDate" ]; then
            echo "<n:ReleaseDate>$value</n:ReleaseDate>" >> ItemSearch.xml
        else
            echo "error"
        fi
    done
    if [ "$soap" == "true" ]; then
        echo "</n:Request>" >> ItemSearch.xml
    fi
    echo "</n:ItemSearch>" >> ItemSearch.xml

}

function item_lookup()
{
    echo "<n:ItemLookup xmlns:n=\"http://webservices.amazon.com/AWSECommerceService/2007-10-29\">" > ItemLookup.xml
    echo "<n:SubscriptionId>$1</n:SubscriptionId>" >> ItemLookup.xml
    if [ "$soap" == "true" ]; then
        echo "<n:Request>" >> ItemLookup.xml
    else
        echo "<n:Service>AWSECommerceService</n:Service>" >> ItemLookup.xml
        echo "<n:Operation>ItemLookup</n:Operation>" >> ItemLookup.xml
    fi
    for arg in "$@"
    do
        i=`expr index $arg :`
        if [ $i -gt 0 ]; then
            key=${arg:0:$i-1}
            len=${#arg}
            value=${arg:$i:$len}
        else
            continue
        fi
        if [ "$key" == "ISPUPostalCode" ]; then
            echo "<n:ISPUPostalCode>$value</n:ISPUPostalCode>" >> ItemLookup.xml
        elif [ "$key" == "MerchantId" ]; then
            echo "<n:MerchantId>$value</n:MerchantId>" >> ItemLookup.xml
        elif [ "$key" == "OfferPage" ]; then
            echo "<n:OfferPage>$value</n:OfferPage>" >> ItemLookup.xml
        elif [ "$key" == "ItemId" ]; then
            echo "<n:ItemId>$value</n:ItemId>" >> ItemLookup.xml
        elif [ "$key" == "ResponseGroup" ]; then
            echo "<n:ResponseGroup>$value</n:ResponseGroup>" >> ItemLookup.xml
        elif [ "$key" == "ReviewPage" ]; then
            echo "<n:ReviewPage>$value</n:ReviewPage>" >> ItemLookup.xml
        elif [ "$key" == "ReviewSort" ]; then
            echo "<n:ReviewSort>$value</n:ReviewSort>" >> ItemLookup.xml
        elif [ "$key" == "SearchIndex" ]; then
            echo "<n:SearchIndex>$value</n:SearchIndex>" >> ItemLookup.xml
        elif [ "$key" == "SearchInsideKeywords" ]; then
            echo "<n:SearchInsideKeywords>$value</n:SearchInsideKeywords>" >> ItemLookup.xml
        elif [ "$key" == "TagPage" ]; then
            echo "<n:TagPage>$value</n:TagPage>" >> ItemLookup.xml
        elif [ "$key" == "TagsPerPage" ]; then
            echo "<n:TagsPerPage>$value</n:TagsPerPage>" >> ItemLookup.xml
        elif [ "$key" == "TagSort" ]; then
            echo "<n:TagSort>$value</n:TagSort>" >> ItemLookup.xml
        elif [ "$key" == "VariationPage" ]; then
            echo "<n:VariationPage>$value</n:VariationPage>" >> ItemLookup.xml
        else
            echo "error"
        fi
    done
    if [ "$soap" == "true" ]; then
        echo "</n:Request>" >> ItemLookup.xml
    fi
    echo "</n:ItemLookup>" >> ItemLookup.xml
}

function parse_item_list_for_cart_create()
{
    arg_list=$@
    echo $arg_list > temp_item_list1
    sed -e 's/;/ /' temp_item_list1 > temp_item_list2
    arg_list1=`cat temp_item_list2`
    k=0
    for arg1 in $arg_list1
    do
        let "k=$k+1"
        if [ -n $arg1 ]; then
            echo $arg1 > temp_item_list3
            sed -e 's/:/ /' temp_item_list3 > temp_item_list4
            arg_list2=`cat temp_item_list4`
        fi
        for arg2 in $arg_list2
        do
            i=`expr index $arg2 =`
            if [ $i -gt 0 ]; then
                key=${arg2:0:$i-1}
                len=${#arg2}
                value=${arg2:$i:$len}
            else
                continue
            fi
            if [ "$key" == "ASIN" ]; then
                echo "<n:Item.$k.ASIN>$value</n:Item.$k.ASIN>" >> CartCreate.xml
            elif [ "$key" == "OfferListingId" ]; then
                echo "<n:Item.$k.OfferListingId>$value</n:Item.$k.OfferListingId>" >> CartCreate.xml
            elif [ "$key" == "Quantity" ]; then
                echo "<n:Item.$k.Quantity>$value</n:Item.$k.Quantity>" >> CartCreate.xml
            elif [ "$key" == "AssociateTag" ]; then
                echo "<n:Item.$k.AssociateTag>$value</n:Item.$k.AssociateTag>" >> CartCreate.xml
            elif [ "$key" == "ListItemId" ]; then
                echo "<n:Item.$k.ListItemId>$value</n:Item.$k.ListItemId>" >> CartCreate.xml
            else
                echo "error2"
            fi
        done
    done
}

function parse_item_list_for_cart_create_soap()
{
    arg_list=$@
    echo $arg_list > temp_item_list1
    sed -e 's/;/ /' temp_item_list1 > temp_item_list2
    arg_list1=`cat temp_item_list2`
    for arg1 in $arg_list1
    do
        if [ -n $arg1 ]; then
            echo $arg1 > temp_item_list3
            sed -e 's/:/ /' temp_item_list3 > temp_item_list4
            arg_list2=`cat temp_item_list4`
        fi
        echo "<n:Item>" >> CartCreate.xml
        for arg2 in $arg_list2
        do
            i=`expr index $arg2 =`
            if [ $i -gt 0 ]; then
                key=${arg2:0:$i-1}
                len=${#arg2}
                value=${arg2:$i:$len}
            else
                continue
            fi
            if [ "$key" == "ASIN" ]; then
                echo "<n:ASIN>$value</n:ASIN>" >> CartCreate.xml
            elif [ "$key" == "OfferListingId" ]; then
                echo "<n:OfferListingId>$value</n:OfferListingId>" >> CartCreate.xml
            elif [ "$key" == "Quantity" ]; then
                echo "<n:Quantity>$value</n:Quantity>" >> CartCreate.xml
            elif [ "$key" == "AssociateTag" ]; then
                echo "<n:AssociateTag>$value</n:AssociateTag>" >> CartCreate.xml
            elif [ "$key" == "ListItemId" ]; then
                echo "<n:ListItemId>$value</n:ListItemId>" >> CartCreate.xml
            else
                echo "error2"
            fi
        done
        echo "</n:Item>" >> CartCreate.xml
    done
}
function parse_item_list_for_cart_add()
{
    arg_list=$@
    echo $arg_list > temp_item_list1
    sed -e 's/;/ /' temp_item_list1 > temp_item_list2
    arg_list1=`cat temp_item_list2`
    k=0
    for arg1 in $arg_list1
    do
        let "k=$k+1"
        if [ -n $arg1 ]; then
            echo $arg1 > temp_item_list3
            sed -e 's/:/ /' temp_item_list3 > temp_item_list4
            arg_list2=`cat temp_item_list4`
        fi
        for arg2 in $arg_list2
        do
            i=`expr index $arg2 =`
            if [ $i -gt 0 ]; then
                key=${arg2:0:$i-1}
                len=${#arg2}
                value=${arg2:$i:$len}
            else
                continue
            fi
            if [ "$key" == "ASIN" ]; then
                echo "<n:Item.$k.ASIN>$value</n:Item.$k.ASIN>" >> CartAdd.xml
            elif [ "$key" == "OfferListingId" ]; then
                echo "<n:Item.$k.OfferListingId>$value</n:Item.$k.OfferListingId>" >> CartAdd.xml
            elif [ "$key" == "Quantity" ]; then
                echo "<n:Item.$k.Quantity>$value</n:Item.$k.Quantity>" >> CartAdd.xml
            elif [ "$key" == "AssociateTag" ]; then
                echo "<n:Item.$k.AssociateTag>$value</n:Item.$k.AssociateTag>" >> CartAdd.xml
            elif [ "$key" == "ListItemId" ]; then
                echo "<n:Item.$k.ListItemId>$value</n:Item.$k.ListItemId>" >> CartAdd.xml
            else
                echo "error2"
            fi
        done
    done
}

function parse_item_list_for_cart_add_soap()
{
    arg_list=$@
    echo $arg_list > temp_item_list1
    sed -e 's/;/ /' temp_item_list1 > temp_item_list2
    arg_list1=`cat temp_item_list2`
    for arg1 in $arg_list1
    do
        if [ -n $arg1 ]; then
            echo $arg1 > temp_item_list3
            sed -e 's/:/ /' temp_item_list3 > temp_item_list4
            arg_list2=`cat temp_item_list4`
        fi
        echo "<n:Item>" >> CartAdd.xml
        for arg2 in $arg_list2
        do
            i=`expr index $arg2 =`
            if [ $i -gt 0 ]; then
                key=${arg2:0:$i-1}
                len=${#arg2}
                value=${arg2:$i:$len}
            else
                continue
            fi
            if [ "$key" == "ASIN" ]; then
                echo "<n:ASIN>$value</n:ASIN>" >> CartAdd.xml
            elif [ "$key" == "OfferListingId" ]; then
                echo "<n:OfferListingId>$value</n:OfferListingId>" >> CartAdd.xml
            elif [ "$key" == "Quantity" ]; then
                echo "<n:Quantity>$value</n:Quantity>" >> CartAdd.xml
            elif [ "$key" == "AssociateTag" ]; then
                echo "<n:AssociateTag>$value</n:AssociateTag>" >> CartAdd.xml
            elif [ "$key" == "ListItemId" ]; then
                echo "<n:ListItemId>$value</n:ListItemId>" >> CartAdd.xml
            else
                echo "error2"
            fi
        done
        echo "</n:Item>" >> CartAdd.xml
    done
}

function parse_modify_item_list()
{
    arg_list=$@
    echo $arg_list > temp_item_list1
    sed -e 's/;/ /' temp_item_list1 > temp_item_list2
    arg_list1=`cat temp_item_list2`
    k=0
    for arg1 in $arg_list1
    do
        let "k=$k+1"
        if [ -n $arg1 ]; then
            echo $arg1 > temp_item_list3
            sed -e 's/:/ /' temp_item_list3 > temp_item_list4
            arg_list2=`cat temp_item_list4`
        else
            continue;
        fi
        for arg2 in $arg_list2
        do
            i=`expr index $arg2 =`
            if [ $i -gt 0 ]; then
                key=${arg2:0:$i-1}
                len=${#arg2}
                value=${arg2:$i:$len}
            else
                continue
            fi
            if [ "$key" == "CartItemId" ]; then
                echo "<n:Item.$k.CartItemId>$value</n:Item.$k.CartItemId>" >> CartModify.xml
            elif [ "$key" == "Quantity" ]; then
                echo "<n:Item.$k.Quantity>$value</n:Item.$k.Quantity>" >> CartModify.xml
            else
                echo "error"
            fi
        done
    done
}

function parse_modify_item_list_soap()
{
    arg_list=$@
    echo $arg_list > temp_item_list1
    sed -e 's/;/ /' temp_item_list1 > temp_item_list2
    arg_list1=`cat temp_item_list2`
    for arg1 in $arg_list1
    do
        if [ -n $arg1 ]; then
            echo $arg1 > temp_item_list3
            sed -e 's/:/ /' temp_item_list3 > temp_item_list4
            arg_list2=`cat temp_item_list4`
        else
            continue;
        fi
        echo "<n:Item>" >> CartModify.xml
        for arg2 in $arg_list2
        do
            i=`expr index $arg2 =`
            if [ $i -gt 0 ]; then
                key=${arg2:0:$i-1}
                len=${#arg2}
                value=${arg2:$i:$len}
            else
                continue
            fi
            if [ "$key" == "CartItemId" ]; then
                echo "<n:CartItemId>$value</n:CartItemId>" >> CartModify.xml
            elif [ "$key" == "Quantity" ]; then
                echo "<n:Quantity>$value</n:Quantity>" >> CartModify.xml
            else
                echo "error"
            fi
        done
        echo "</n:Item>" >> CartModify.xml
    done
}

function cart_create()
{
    echo "<n:CartCreate xmlns:n=\"http://webservices.amazon.com/AWSECommerceService/2007-10-29\">" > CartCreate.xml
    echo "<n:SubscriptionId>$1</n:SubscriptionId>" >> CartCreate.xml
    if [ "$soap" == "true" ]; then
        echo "<n:Request>" >> CartCreate.xml
    else
        echo "<n:Service>AWSECommerceService</n:Service>" >> CartCreate.xml
        echo "<n:Operation>CartCreate</n:Operation>" >> CartCreate.xml
    fi
    for arg in "$@"
    do
        i=`expr index $arg =`
        if [ $i -gt 0 ]; then
            key=${arg:0:$i-1}
            len=${#arg}
            value=${arg:$i:$len}
        else
            continue
        fi
        if [ "$key" == "MergeCart" ]; then
            echo "<n:MergeCart>$value</n:MergeCart>" >> CartCreate.xml
        elif [ "$key" == "Items" ]; then
            if [ "$soap" == "true" ]; then
                echo "<n:Items>" >> CartCreate.xml
                parse_item_list_for_cart_create_soap $value
                echo "</n:Items>" >> CartCreate.xml
            else
                parse_item_list_for_cart_create $value
            fi
        elif [ "$key" == "ResponseGroup" ]; then
            echo "<n:ResponseGroup>$value</n:ResponseGroup>" >> CartCreate.xml
        else
            echo "error"
        fi
    done
    if [ "$soap" == "true" ]; then
        echo "</n:Request>" >> CartCreate.xml
    fi
    echo "</n:CartCreate>" >> CartCreate.xml
}
function cart_add()
{
    echo "<n:CartAdd xmlns:n=\"http://webservices.amazon.com/AWSECommerceService/2007-10-29\">" > CartAdd.xml
    echo "<n:SubscriptionId>$1</n:SubscriptionId>" >> CartAdd.xml
    if [ "$soap" == "true" ]; then
        echo "<n:Request>" >> CartAdd.xml
    else
        echo "<n:Service>AWSECommerceService</n:Service>" >> CartAdd.xml
        echo "<n:Operation>CartAdd</n:Operation>" >> CartAdd.xml
    fi
    #Default values for CartId and HMAC are taken from corresponding values stored
    #by CartCreate operation.
    sed -e 's/[^*]*<CartId>\([^*]*\)<\/CartId>[^*]*/\1/' CartCreateResponse.xml > CartId
    sed -e 's/[^*]*<HMAC>\([^*]*\)<\/HMAC>[^*]*/\1/' CartCreateResponse.xml > HMAC
    #sed -e 's/\//\\\//' HMAC_temp > HMAC
    cart_id=`cat CartId`
    hmac=`cat HMAC`
    echo "<n:CartId>$cart_id</n:CartId>" >> CartAdd.xml
    echo "<n:HMAC>$hmac</n:HMAC>" >> CartAdd.xml
    for arg in "$@"
    do
        i=`expr index $arg =`
        if [ $i -gt 0 ]; then
            key=${arg:0:$i-1}
            len=${#arg}
            value=${arg:$i:$len}
        else
            continue
        fi
        if [ "$key" == "MergeCart" ]; then
            echo "<n:MergeCart>$value</n:MergeCart>" >> CartAdd.xml
        elif [ "$key" == "Items" ]; then
            if [ "$soap" == "true" ]; then
                echo "<n:Items>" >> CartAdd.xml
                parse_item_list_for_cart_add_soap $value
                echo "</n:Items>" >> CartAdd.xml
            else
                parse_item_list_for_cart_add $value
            fi
        elif [ "$key" == "ResponseGroup" ]; then
            echo "<n:ResponseGroup>$value</n:ResponseGroup>" >> CartAdd.xml
        else
            echo "error"
        fi
    done
    if [ "$soap" == "true" ]; then
        echo "</n:Request>" >> CartAdd.xml
    fi
    echo "</n:CartAdd>" >> CartAdd.xml
}
function cart_modify()
{
    echo "<n:CartModify xmlns:n=\"http://webservices.amazon.com/AWSECommerceService/2007-10-29\">" > CartModify.xml
    echo "<n:SubscriptionId>$1</n:SubscriptionId>" >> CartModify.xml
    if [ "$soap" == "true" ]; then
        echo "<n:Request>" >> CartModify.xml
    else
        echo "<n:Service>AWSECommerceService</n:Service>" >> CartModify.xml
        echo "<n:Operation>CartModify</n:Operation>" >> CartModify.xml
    fi
    #Default values for CartId and HMAC are taken from corresponding values stored
    #by CartCreate operation.
    sed -e 's/[^*]*<CartId>\([^*]*\)<\/CartId>[^*]*/\1/' CartCreateResponse.xml > CartId
    sed -e 's/[^*]*<HMAC>\([^*]*\)<\/HMAC>[^*]*/\1/' CartCreateResponse.xml > HMAC
    #sed -e 's/[\/\.\*\\]/\\&/g' HMAC_temp > HMAC
    #sed -e 's/\//\\\//' HMAC_temp > HMAC
    cart_id=`cat CartId`
    hmac=`cat HMAC`
    echo "hmac:"$hmac
    echo "<n:CartId>$cart_id</n:CartId>" >> CartModify.xml
    echo "<n:HMAC>$hmac</n:HMAC>" >> CartModify.xml
    for arg in "$@"
    do
        i=`expr index $arg =`
        if [ $i -gt 0 ]; then
            key=${arg:0:$i-1}
            len=${#arg}
            value=${arg:$i:$len}
        else
            continue
        fi
        if [ "$key" == "MergeCart" ]; then
            echo "<n:MergeCart>$value</n:MergeCart>" >> CartModify.xml
        elif [ "$key" == "Items" ]; then
            if [ "$soap" == "true" ]; then
                echo "<n:Items>" >> CartModify.xml
                parse_modify_item_list_soap $value
                echo "</n:Items>" >> CartModify.xml
            else
                parse_modify_item_list $value
            fi
        elif [ "$key" == "ResponseGroup" ]; then
            echo "<n:ResponseGroup>$value</n:ResponseGroup>" >> CartModify.xml
        else
            echo "error"
        fi
    done
    if [ "$soap" == "true" ]; then
        echo "</n:Request>" >> CartModify.xml
    fi
    echo "</n:CartModify>" >> CartModify.xml
}
function cart_clear()
{
    echo "<n:CartClear xmlns:n=\"http://webservices.amazon.com/AWSECommerceService/2007-10-29\">" > CartClear.xml
    echo "<n:SubscriptionId>$1</n:SubscriptionId>" >> CartClear.xml
    if [ "$soap" == "true" ]; then
        echo "<n:Request>" >> CartClear.xml
    else
        echo "<n:Service>AWSECommerceService</n:Service>" >> CartClear.xml
        echo "<n:Operation>CartClear</n:Operation>" >> CartClear.xml
    fi
    #Default values for CartId and HMAC are taken from corresponding values stored
    #by CartCreate operation.
    sed -e 's/[^*]*<CartId>\([^*]*\)<\/CartId>[^*]*/\1/' CartCreateResponse.xml > CartId
    sed -e 's/[^*]*<HMAC>\([^*]*\)<\/HMAC>[^*]*/\1/' CartCreateResponse.xml > HMAC
    #sed -e 's/\//\\\//' HMAC_temp > HMAC
    cart_id=`cat CartId`
    hmac=`cat HMAC`
    echo "<n:CartId>$cart_id</n:CartId>" >> CartClear.xml
    echo "<n:HMAC>$hmac</n:HMAC>" >> CartClear.xml
    for arg in "$@"
    do
        i=`expr index $arg =`
        if [ $i -gt 0 ]; then
            key=${arg:0:$i-1}
            len=${#arg}
            value=${arg:$i:$len}
        else
            continue
        fi
        if [ "$key" == "MergeCart" ]; then
            echo "<n:MergeCart>$value</n:MergeCart>" >> CartClear.xml
        elif [ "$key" == "ResponseGroup" ]; then
            echo "<n:ResponseGroup>$value</n:ResponseGroup>" >> CartClear.xml
        else
            echo "error"
        fi
    done
    if [ "$soap" == "true" ]; then
        echo "</n:Request>" >> CartClear.xml
    fi
    echo "</n:CartClear>" >> CartClear.xml
}

function parse_op()
{
    op_args=""
    if [ $1 == "ItemSearch" ]; then
        op_args=("$2 $3")
        item_search $op_args
    fi
    if [ $1 == "ItemLookup" ]; then
        op_args=("$2 $3")
        item_lookup $op_args
    fi
    if [ $1 == "CartCreate" ]; then
        op_args=("$2 $3")
        cart_create $op_args
    fi
    if [ $1 == "CartAdd" ]; then
        op_args=("$2 $3")
        cart_add $op_args
    fi
    if [ $1 == "CartModify" ]; then
        op_args=("$2 $3")
        cart_modify $op_args
    fi
    if [ $1 == "CartClear" ]; then
        op_args=("$2 $3")
        cart_clear $op_args
    fi
}

function amazoneclient_clean()
{
    rm -f ItemSearch.xml
    rm -f ItemSearchResponse.xml
    rm -f ItemLookup.xml
    rm -f ItemLookupResponse.xml
    rm -f CartCreate.xml
    rm -f CartCreateResponse.xml
    rm -f CartAdd.xml
    rm -f CartAddResponse.xml
    rm -f CartModify.xml
    rm -f CartModifyResponse.xml
    rm -f Item_temp.xml
    rm -f ModifyItem_temp.xml
    rm -f temp*
    rm -f CartId
    rm -f HMAC
    rm -f HMAC_temp
}

function print_help()
{
help=(
"amazoneclient 1.0, command line tool to consume Amazon E-Commerce Web Services. This can be used to search, lookup
 and then add selected items to the amazon shopping cart for purchase. Then you will given a purchase url to continue
 with your transaction with Amazon."
"Usage: amazoneclient [-s|--subscription-id subscription id] [-o|--op operation] [-a|--op-args op arguments]"
"Mandatory arguments to long options are mandatory for short options too."
"General:
  -v,  --version                    display the version of amazoneclient and exit.
  -h,  --help                       print this help.
  -s,  --subscription-id            Your Amazon Application key. You can retrieve this from http://aws.amazon.com" 
"Operation Specific:
  -o,  --op OP_NAME                 Possible values for OP_NAME are
                                    Item Search
                                    Item Lookup
                                    CartCreate
                                    CartAdd
                                    CartModify
                                    CartClear.
                                    After each operation invoke you will have a OP_NAMEResponse.xml file in your
                                    current directory which will contain the result of the operation you invoked 
                                    from Amazon. You should refer to this Response.xml file to extract information.
                                    For Cart releated operations you may need to send a list of items as value to the
                                    'Items' key. In that case each item is separated by ';' and elements in each item
                                    is separated by ':' as in
                                    Items=ASIN=0131488740:Quantity=5;ASIN=B000OIKRPG:Quantity=2
  -a,  --op-args ARGS_LIST          Specify the operation specific arguement list. Following is a description of
                                    the arguement list corresponding to each operation. Argument list should be
                                    enclosed by pair of double quotes.
                                    Each argument is a key, value pair. Key and value are separated by '='. 
                                    Each key, value pair is separated by a space. A value should contain no spaces, use
                                    underscore instead."
"eg 1:
sh amazoneclient.sh -sTEAUYHWF3PPPR3MB7IOR7 --opItemSearch --op-args\"Keywords=Web_Services_Sanjiva SearchIndex:Books\"
eg 2:
sh amazoneclient.sh -sTEAUYHWF3PPPR3MB7IOR7 --opItemLookup --op-args\"ItemId:0131488740 ResponseGroup:OfferFull\"
eg 3:
sh amazoneclient.sh -sTEAUYHWF3PPPR3MB7IOR7 -oCartCreate -a\"Items=ASIN:0131488740 Quantity=5;ASIN:B000OIKRPG Quantity=2\""
)
for i in "${help[@]}"
do
    echo "$i"
done
exit 0
}

subscription_id=""
op=""
op_args=""
item_lookup_xml=""
usage="Usage: $0 [-s subscription id] [-o operation] [-a op arguments]"
if [ $# -gt 0 ]; then
    :
else
    echo $usage
    exit 1
fi

while getoptex "s: o: w d a: h u. subscription-id: op: soap dump op-args: help usage." "$@"
do case $OPTOPT in
    s | subscription-id) subscription_id="$OPTARG";;
    o | op) op="$OPTARG";;
    a | op-args) op_args="$OPTARG";;
    w | soap) soap="true";;
    d | dump) dump="true";;
    h | help) print_help;exit 1;;
    u | usage) echo $usage;;
    *) echo $usage
        exit 1
        ;;
    esac
done
if test -z "$subscription_id"; then
    echo "Visit http://aws.amazon.com to aget a Amazon key"
    exit 1
fi
op_xml=("$op.xml")
op_response_xml=("$op""Response.xml")
parse_op $op $subscription_id "$op_args"
if [ "$soap" == "true" ]; then
    if [ "$dump" == "true" ]; then
$WSFC_HOME/bin/wsclient --soap1.1 --no-mtom --soap-dump --action http://soap.amazon.com http://soap.amazon.com:80/onca/soap?Service=AWSECommerceService < $op_xml > $op_response_xml
    else
$WSFC_HOME/bin/wsclient --soap1.1 --no-mtom --action http://soap.amazon.com http://soap.amazon.com:80/onca/soap?Service=AWSECommerceService < $op_xml > $op_response_xml
    fi
else
    if [ "$dump" == "true" ]; then
$WSFC_HOME/bin/wsclient --get --soap-dump --to http://webservices.amazon.com:80/onca/xml < $op_xml > $op_response_xml
    else
$WSFC_HOME/bin/wsclient --get --to http://webservices.amazon.com:80/onca/xml < $op_xml > $op_response_xml
    fi
fi
if [ $op == "CartClear" ]; then
    amazoneclient_clean
fi
