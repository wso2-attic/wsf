echo Setting Visual Studio environment variables...
vcvars32.bat
echo Building WSF Client...
ruby extconf-win32.rb
nmake 
nmake install
echo Building WSF Service...
cd wsservice
ruby extconf-win32.rb
nmake
nmake install
