@echo off

@call init.bat
@call .\wsf_c\build\init.bat

@cd wsf_c

@call clean.bat

@cd ..

@if exist wsf_c\wso2-wsf-c-bin-%WSFC_VERSION% rmdir /S /Q wsf_c\wso2-wsf-c-bin-%WSFC_VERSION%

@if exist wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32 rmdir /S /Q wso2-wsf-ruby-bin-%WSFRUBY_VERSION%-win32

@if exist wsf_c\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32 rmdir /s /q wsf_c\axis2c\build\axis2c-bin-%AXIS2C_VERSION%-win32

@if exist wsf_c\axis2c\build\deploy rmdir /s /q wsf_c\axis2c\build\deploy

@if exist wsf_c\axis2c\build\win32\int.msvc rmdir /s /q wsf_c\axis2c\build\win32\int.msvc

@if exist wsf_c\rampartc\build\rampartc-%RAMPARTC_VERSION% rmdir /s /q wsf_c\rampartc\build\rampartc-%RAMPARTC_VERSION%

@if exist wsf_c\rampartc\build\win32\int.msvc rmdir /s /q wsf_c\rampartc\build\win32\int.msvc

@if exist wsf_c\sandesha2c\build\sandesha2 rmdir /s /q wsf_c\sandesha2c\build\sandesha2

@if exist wsf_c\sandesha2c\build\win32\int.msvc rmdir /s /q wsf_c\sandesha2c\build\win32\int.msvc

@if exist src\intdir rmdir /s /q src\intdir

@if exist WSFC_wrapper.obj del /Q WSFC_wrapper.obj
@if exist vc80.pdb del /Q /F vc80.pdb
@if exist WSFC-i386-mswin32.pdb del /Q /F WSFC-i386-mswin32.pdb
@if exist WSFC-i386-mswin32.lib del /Q /F WSFC-i386-mswin32.lib
@if exist mkmf.log del /Q /F mkmf.log
@if exist WSFC.so.manifest del /Q /F WSFC.so.manifest
@if exist makefile del /Q /F makefile
@if exist wsfc.dll del /Q /F wsfc.dll
@if exist wsfc.so del /Q /F wsfc.so
@if exist WSFC-i386-mswin32.exp del /Q /F WSFC-i386-mswin32.exp

@if exist wsservice\wsf.obj del /Q /F wsservice\wsf.obj
@if exist wsservice\wsf_out_transport_info.obj del /Q /F wsservice\wsf_out_transport_info.obj
@if exist wsservice\wsf_policy.obj del /Q /F wsservice\wsf_policy.obj
@if exist wsservice\wsf_stream.obj del /Q /F wsservice\wsf_stream.obj
@if exist wsservice\wsf_util.obj del /Q /F wsservice\wsf_util.obj
@if exist wsservice\wsf_worker.obj del /Q /F wsservice\wsf_worker.obj
@if exist wsservice\wsf_xml_msg_recv.obj del /Q /F wsservice\wsf_xml_msg_recv.obj
@if exist wsservice\Makefile del /Q /F wsservice\Makefile
@if exist wsservice\wsservice.so.manifest del /Q /F wsservice\wsservice.so.manifest
@if exist wsservice\wsservice-i386-mswin32.lib del /Q /F wsservice\wsservice-i386-mswin32.lib
@if exist wsservice\vc80.pdb del /Q /F wsservice\vc80.pdb
@if exist wsservice\wsservice-i386-mswin32.pdb del /Q /F wsservice\wsservice-i386-mswin32.pdb
@if exist wsservice\wsservice.so del /Q /F wsservice\wsservice.so
@if exist wsservice\mkmf.log del /Q /F wsservice\mkmf.log
@if exist wsservice\wsservice-i386-mswin32.exp del /Q /F wsservice\wsservice-i386-mswin32.exp

