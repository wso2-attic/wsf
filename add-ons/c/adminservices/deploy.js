var WshShell = new ActiveXObject("WScript.Shell");
fso = new ActiveXObject("Scripting.FileSystemObject");

var fso, f, s, r;
var ForReading = 1, ForWriting = 2;

var args = WScript.Arguments;

var read_file = args.Item(0);
var deploy_file = args.Item(0);
var axis2c_home = args.Item(1);

// Deploy the client policy file
f = fso.OpenTextFile(read_file, ForReading);
s = f.ReadAll();
f.Close();

f = fso.OpenTextFile(deploy_file, ForWriting, true);
while (s.search(/AXIS2C_HOME/) != -1) {
	r = s.replace(/AXIS2C_HOME/, axis2c_home);
	s = r;
}
while (s.search(/libpwcb\.so/) != -1) {
	r = s.replace(/libpwcb\.so/, "pwcb.dll");
	s = r;
}
while (s.search(/librdflatfile\.so/) != -1) {
	r = s.replace(/librdflatfile\.so/, "rdflatfile.dll");
	s = r;
}
while (s.search(/libsctprovider\.so/) != -1) {
	r = s.replace(/libsctprovider\.so/, "sctprovider.dll");
	s = r;
}
while (s.search(/libsctprovider_hashdb\.so/) != -1) {
	r = s.replace(/libsctprovider_hashdb\.so/, "sctprovider_hashdb.dll");
	s = r;
}
f.write(s);
f.close();
