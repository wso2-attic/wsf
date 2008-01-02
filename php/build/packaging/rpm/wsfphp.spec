Summary: WSO2 WSF/PHP
Name: wso2-wsf-php
Vendor: WSO2 Inc.
Version:1.2.0
Release: 1
Source: wso2-wsf-php-1.2.0.tar.gz
License: Apache License V2.0
Group: Development/Tools
%description
WSO2 Web Services Framework for PHP (WSO2 WSF/PHP), a binding of WSO2 WSF/C into PHP is a PHP extension for providing and consuming Web Services in PHP. WSO2 WSF/PHP supports SOAP 1.1, SOAP 1.2, WSDL 1.1, WSDL 2.0, REST style invocation as well as some of the key WS-* stack specifications such as: SOAP MTOM, WS-Addressing, WS-Security, WS-SecurityPolicy and WS-ReliableMessaging.
%prep
%setup -q
%build
export CFLAGS="-O2"
./configure --with-axis2=`pwd`/wsf_c/axis2c/include --prefix='/usr/lib/php/modules/wsf_c'
make
%install
make install
strip -g /usr/lib/php/modules/wsf_c/lib/*.so
#cp -f `php-config --extension-dir`/wsf.so /usr/lib/php/modules/
mkdir -p /usr/lib/php/modules/wsf_php
cp -rf scripts /usr/lib/php/modules/wsf_php
cp -rf samples /usr/lib/php/modules/wsf_php
cp -rf docs /usr/lib/php/modules/wsf_php
mkdir /usr/lib/php/modules/wsf_php/sandesha2
cp -rf wsf_c/sandesha2c/config /usr/lib/php/modules/wsf_php/sandesha2
%post
echo "[wsf]" >> /etc/php.ini
echo "extension=wsf.so" >> /etc/php.ini
echo "wsf.home=\"/usr/lib/php/modules/wsf_c\"" >> /etc/php.ini
echo "wsf.log_path=\"/tmp\"" >> /etc/php.ini
echo "wsf.rm_db_dir=\"/tmp\"" >> /etc/php.ini

echo "Copy samples folders in /usr/lib/php/modules/wsf_php to your Web Root"
echo "Edit php.ini file located in /etc/php.ini and set your php.ini entry include_path to point to /usr/lib/php/modules/wsf_php/scripts directory"
echo "eg. include_path = \".:/usr/lib/php/modules/wsf_php/scripts\" "

%files
%defattr(-,root,root)
/usr/lib/php/modules/wsf.so
/usr/lib/php/modules/wsf_php
/usr/lib/php/modules/wsf_c
%doc COPYING AUTHORS README NEWS
