function string_replace(haystack, find, sub) {
    return haystack.split(find).join(sub);
}

var WshShell = new ActiveXObject("WScript.Shell");
fso = new ActiveXObject("Scripting.FileSystemObject");

var fso, f, s, r;
var ForReading = 1, ForWriting = 2;

var axis2c_home = WshShell.ExpandEnvironmentStrings("%WSFCPP_HOME%");
var axis2c_home_samples = axis2c_home + "/samples/src/c/rampartc"
var axis2c_home_lib = axis2c_home+"/samples/lib/";

var args = WScript.Arguments;

var read_file = args.Item(0);
var deploy_file = args.Item(1);

// Deploy the client policy file
f = fso.OpenTextFile(read_file, ForReading);
s = f.ReadAll();
f.Close();

f = fso.OpenTextFile(deploy_file, ForWriting, true);
s = string_replace(s, "AXIS2C_HOME/samples/src/rampartc", axis2c_home_samples);
s = string_replace(s, "AXIS2C_HOME/samples/lib/rampartc", axis2c_home_lib);
s = string_replace(s, "libpwcb.so", "pwcb.dll");
s = string_replace(s, "librdflatfile.so", "rdflatfile.dll");
s = string_replace(s, "libsctprovider.so", "sctprovider.dll");
s = string_replace(s, "libsctprovider_hashdb.so", "sctprovider_hashdb.dll");

f.write(s);
f.close();
