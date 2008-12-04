@echo off

@call clean_dist.bat

@call init.bat
@call .\wsf_c\build\init.bat

@copy configure.in wsf_c\configure.in
@copy configure.in.dist wsdlc\build\win32\configure.in
@copy wsf_c_build.bat wsf_c\build.bat

@cd wsf_c

@call build.bat

@cd ..

@mkdir wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32

@xcopy /E /Q /Y /I wsf_c\wso2-wsf-c-bin-%WSFC_VERSION% wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\wsf_c

@if exist wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\wsf_c\services rmdir /S /Q wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\wsf_c\services

@if exist wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\wsf_c\modules\savan rmdir /S /Q wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\wsf_c\modules\savan

@if exist wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\wsf_c\samples rmdir /S /Q wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\wsf_c\samples

@if exist wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\wsf_c\ides rmdir /S /Q wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\wsf_c\ides

@if exist wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\wsf_c\bin\samples rmdir /S /Q wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\wsf_c\bin\samples

@if exist wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\wsf_c\bin\tools rmdir /S /Q wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\wsf_c\bin\tools

@if exist wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\wsf_c\bin\docs rmdir /S /Q wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\wsf_c\bin\docs

@if exist wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\wsf_c\modules\logging rmdir /S /Q wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\wsf_c\modules\logging

rem @if exist wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\wsdlc\xslt rmdir /S /Q wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\wsdlc\xslt

rem @if exist wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\wsdlc\conf rmdir /S /Q wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\wsdlc\conf

@if exist wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\wsdlc rmdir /S /Q wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\wsdlc

@if exist lib xcopy /Y /I /Q /E lib wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\lib

@if exist samples xcopy /Y /I /Q /E samples wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\samples

@if exist docs xcopy /Y /I /Q /E docs wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\docs

@if exist AUTHORS copy /Y AUTHORS wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32

@if exist ChangeLog copy /Y ChangeLog wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32

@if exist COPYING copy /Y COPYING wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32

@if exist NOTICE copy /Y NOTICE wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32

@if exist INSTALL copy /Y INSTALL wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32

@if exist README.SAMPLES copy /Y README.SAMPLES wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32

@if exist README copy /Y README wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32

@if exist LICENSE copy /Y LICENSE wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32

@if exist NEWS copy /Y NEWS wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32

@if exist README.INSTALL_WIN32 copy /Y README.INSTALL_WIN32 wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32

@if exist install.rb copy /Y install.rb wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32

@if exist find_rbconfig.rb copy /Y find_rbconfig.rb wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32

@if exist get_wsfc_home.rb copy /Y get_wsfc_home.rb wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32

@mkdir wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\wsdlc

@mkdir wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\wsdlc\conf

@mkdir wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\wsdlc\xslt

@if exist conf\wsdlc_type_map.xml copy /Y conf\wsdlc_type_map.xml wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\wsdlc\conf\type_map.xml

@if exist wsdlc\xslt\wsdl2sig.xslt copy /Y wsdlc\xslt\wsdl2sig.xslt wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\wsdlc\xslt\wsdl2sig.xslt

@if exist wsdlc\xslt\wsdl11to20.xsl10.xsl copy /Y wsdlc\xslt\wsdl11to20.xsl10.xsl wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\wsdlc\xslt\wsdl11to20.xsl10.xsl

@cd wsdlc

@call build.bat

@copy lib\wsdlc.lib ..\wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\wsf_c\lib\wsdlc.lib

@copy lib\wsdlc.dll ..\wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\wsf_c\lib\wsdlc.dll

@cd ..

@echo.

@echo Building WSF Client...

@echo.

@ruby extconf.rb

@nmake 

@mt.exe -manifest WSFC.so.manifest -outputresource:WSFC.so;2

@nmake install

@echo. 

@echo Building WSF Service...

@echo.

@cd wsservice

@ruby extconf.rb

@nmake

@mt.exe -manifest wsservice.so.manifest -outputresource:wsservice.so;2

@nmake install

@cd .. 

@if exist WSFC.so copy /Y WSFC.so wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\lib

@cd wsservice

@if exist wsservice.so copy /Y wsservice.so ..\wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\lib

@cd ..

@del /f /q /s wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\wsf_c\*.pdb
@del /f /q /s wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\wsf_c\*.ilk
@del /f /q /s wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\wsf_c\*.exp
@del /f /q /s wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32\wsf_c\*.manifest

