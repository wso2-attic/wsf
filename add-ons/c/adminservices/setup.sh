#!/bin/bash
set -e

function banner {
echo "/***********************************************************/"
echo "/* WSO2 WSF/{C,CPP} Admin Console Installer                */"
echo "/***********************************************************/"
}
function prod_select { 
echo "Step 1"
echo "------"
echo " 1. WSO2 WSF/C"
echo " 2. WSO2 WSF/C++"
echo "."
echo "Select a target product : "
read product
} 
function prod_c { 
echo "Step 2"
echo "------"
echo "Specify your WSO2 WSF/C home : "
read home
}
function prod_cpp { 
echo "Step2"
echo "Specify your WSO2 WSF/C++ home : "
read home
}
function carbon { 
echo "Step 3"
echo "------"
echo "Specify where you want to install WSO2 Carbon Console : "
read carbon_home
}
function prod_error { 
echo " [Error] Target product has to either '1' or '2' "
exit
}
function home_error { 
echo " [Error] The path does not exist "
exit
}
function carbon_error {
echo " [Error] The path does not exist "
exit
}
function install_prod {
cp -rf ./carbon/wso2carbon-2.0.2 $carbon_home/wso2carbon-2.0.2
echo "Installing Carbon Console .... [OK]"
./deploy.sh $home $home/services/SecurityAdminService/policies/scenario1-policy.xml
echo "Customizing services ... [OK]"
if [ "$product"=="1" ]; then
cp ./carbon/conf/carbon.c.xml $carbon_home/wso2carbon-2.0.2/conf/carbon.xml
cp ./carbon/styles/org.wso2.wsas.styles-3.1.2.c.jar $carbon_home/wso2carbon-2.0.2/repository/components/plugins/org.wso2.wsas.styles-3.1.2.jar
fi
if [ "$product"=="2" ]; then
cp ./carbon/conf/carbon.cpp.xml $carbon_home/wso2carbon-2.0.2/conf/carbon.xml
cp ./carbon/styles/org.wso2.wsas.styles-3.1.2.cpp.jar $carbon_home/wso2carbon-2.0.2/repository/components/plugins/org.wso2.wsas.styles-3.1.2.jar
fi
echo "Customizing Carbon ...[OK]"
echo "."
echo "Admin installed successfully...."
}
banner
prod_select
if [ "$product" == "1" ]; then
prod_c
else
	if [ "$product" == "2" ]; then
	prod_cpp
	fi
fi
if  test -d $home;then
carbon
else
home_error
fi
if test -d $carbon_home; then
install_prod
else
carbon_error
fi

