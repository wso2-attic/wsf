md %AXIS2C_HOME%\modules\rampart\
copy modules\rampart\mod_rampart.dll %AXIS2C_HOME%\modules\rampart\
copy modules\rampart\module.xml %AXIS2C_HOME%\modules\rampart\

md %AXIS2C_HOME%\services\sec_echo\
copy bin\samples\services\sec_echo\sec_echo.dll %AXIS2C_HOME%\services\sec_echo\
copy bin\samples\services\sec_echo\services.xml %AXIS2C_HOME%\services\sec_echo\

md %AXIS2C_HOME%\bin\samples\rampart\
md %AXIS2C_HOME%\bin\samples\rampart\authn_provider\
copy bin\samples\authn_provider\authn.dll %AXIS2C_HOME%\bin\samples\rampart\authn_provider\

md %AXIS2C_HOME%\bin\samples\rampart\client\
md %AXIS2C_HOME%\bin\samples\rampart\client\sec_echo\
copy bin\samples\client\sec_echo\echo.exe %AXIS2C_HOME%\bin\samples\rampart\client\sec_echo\

md %AXIS2C_HOME%\bin\samples\rampart\callback
copy bin\samples\callback\pwcb.dll %AXIS2C_HOME%\bin\samples\rampart\callback\

md %AXIS2C_HOME%\bin\samples\rampart\credential_provider
copy bin\samples\credential_provider\cred_provider.dll %AXIS2C_HOME%\bin\samples\rampart\credential_provider\

xcopy bin\samples\keys %AXIS2C_HOME%\bin\samples\rampart\keys\ /E /I /Y /S
