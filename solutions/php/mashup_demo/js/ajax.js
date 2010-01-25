var xmlhttp=false;
var Ajax = {};

Ajax.XMLHttp = function()
{
    var xmlhttp;
    try {
     xmlhttp = new ActiveXObject("Msxml2.XMLHTTP");
    } catch (e) {
     try {
      xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
     } catch (E) {
      xmlhttp = false;
     }
    }
    if (!xmlhttp && typeof XMLHttpRequest!='undefined') {
        try {
            xmlhttp = new XMLHttpRequest();
        } catch (e) {
            xmlhttp=false;
        }
    }
    if (!xmlhttp && window.createRequest) {
        try {
            xmlhttp = window.createRequest();
        } catch (e) {
            xmlhttp=false;
        }
    }
    return xmlhttp;
}

var LOADING_DIV_ID = "loading_div";

var pending = 0;

Ajax.request = function(uri, args)
{
    var loading_div = document.getElementById(LOADING_DIV_ID);
    var xmlhttp = new Ajax.XMLHttp();
    if (args["params"] != null &&  args["params"].length > 0)
    {
        uri += '?';
    }
    for (var i = 0; args["params"] != null && i < args["params"].length/2; i ++)
    {
        uri += encodeURIComponent(args["params"][2*i] );
        uri += '=';
        uri += encodeURIComponent(args["params"][2*i + 1] );
        uri += '&';
    }
    xmlhttp.open("GET", uri , true);
    loading_div.style.visibility = "visible";
    pending ++;
    xmlhttp.onreadystatechange = function() 
    {
	    if(xmlhttp.readyState == 4) 
	    {
            pending --;
            if(pending == 0)
            {
                loading_div.style.visibility = "hidden";
            }
            if(args["set_to"])
            {
                document.getElementById(args["set_to"]).innerHTML = xmlhttp.responseText;
            }           
	    }
    }
    xmlhttp.send(null);
}
