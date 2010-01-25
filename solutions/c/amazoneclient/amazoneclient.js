WScript.StdOut.WriteLine("Running Amazoneclient");
var FSO = WScript.CreateObject("Scripting.FileSystemObject");
var subscription_id="";
var op="";
var op_args="";
var op_xml = "";
var soap = "false";

function amazoneclient_get_file_content(filename)
{
	var F = FSO.OpenTextFile(filename, 1);
	var t = F.ReadAll();
	F.Close();
	return t;
}

function amazoneclient_item_search(op_args, subscription_id, soap)
{
	var FSO = WScript.CreateObject("Scripting.FileSystemObject");
	var filename = "ItemSearch.xml";
	/*var file_content = amazoneclient_get_file_content(filename, true);*/
	var file_desc = FSO.CreateTextFile(filename, true);
	op_args = op_args.split("#"); 
	file_desc.WriteLine("<n:ItemSearch xmlns:n=\"http://webservices.amazon.com/AWSECommerceService/2007-10-29\">");
	file_desc.WriteLine("<n:SubscriptionId>"+subscription_id+"</n:SubscriptionId>");
    if (soap == "true")
	{
		file_desc.WriteLine("<n:Request>");
	}
    else
	{
        file_desc.WriteLine("<n:Service>AWSECommerceService</n:Service>");
        file_desc.WriteLine("<n:Operation>ItemSearch</n:Operation>");
	}
	for(arg in op_args)
	{
		var segment = op_args[arg];
		var key;
		var value;
		segment = segment.split("@", 2);
		key = segment[0];
		if(segment.length > 1)
		{
			value = segment[1];
		}
		else
		{
			value = null;
		}
		WScript.StdOut.WriteLine("key:"+key+";value:"+value);
		if(key == "Actor")
		{
			file_desc.WriteLine("<n:Actor>"+value+"</n:Actor>");
		}
		if(key == "Artist")
		{
			file_desc.WriteLine("<n:Artist>"+value+"</n:Artist>");
		}
		if(key == "Availability")
		{
			file_desc.WriteLine("<n:Availability>"+value+"</n:Availability>");
		}
		if(key == "Author")
		{
			file_desc.WriteLine("<n:Author>"+value+"</n:Author>");
		}
		if(key == "Brand")
		{
			file_desc.WriteLine("<n:Brand>"+value+"</n:Brand>");
		}
		if(key == "BrowseNode")
		{
			file_desc.WriteLine("<n:BrowseNode>"+value+"</n:BrowseNode>");
		}
		if(key == "City")
		{
			file_desc.WriteLine("<n:City>"+value+"</n:City>");
		}
		if(key == "Composer")
		{
			file_desc.WriteLine("<n:Composer>"+value+"</n:Composer>");
		}
		if(key == "Conductor")
		{
			file_desc.WriteLine("<n:Conductor>"+value+"</n:Conductor>");
		}
		if(key == "Count")
		{
			file_desc.WriteLine("<n:Count>"+value+"</n:Count>");
		}
		if(key == "Cuisine")
		{
			file_desc.WriteLine("<n:Cuisine>"+value+"</n:Cuisine>");
		}
		if(key == "Director")
		{
			file_desc.WriteLine("<n:Director>"+value+"</n:Director>");
		}
		if(key == "FutureLaunchDate")
		{
			file_desc.WriteLine("<n:FutureLaunchDate>"+value+"</n:FutureLaunchDate>");
		}
		if(key == "ISPUPostalCode")
		{
			file_desc.WriteLine("<n:ISPUPostalCode>"+value+"</n:ISPUPostalCode>");
		}
		if(key == "ItemPage")
		{
			file_desc.WriteLine("<n:ItemPage>"+value+"</n:ItemPage>");
		}
		else if(key == "Keywords")
		{
			file_desc.WriteLine("<n:Keywords>"+value+"</n:Keywords>");
		}
		if(key == "Manufacturer")
		{
			file_desc.WriteLine("<n:Manufacturer>"+value+"</n:Manufacturer>");
		}
		if(key == "MaximumPrice")
		{
			file_desc.WriteLine("<n:MaximumPrice>"+value+"</n:MaximumPrice>");
		}
		if(key == "MerchantId")
		{
			file_desc.WriteLine("<n:MerchantId>"+value+"</n:MerchantId>");
		}
		if(key == "MinimumPrice")
		{
			file_desc.WriteLine("<n:MinimumPrice>"+value+"</n:MinimumPrice>");
		}
		if(key == "MusicLabel")
		{
			file_desc.WriteLine("<n:MusicLabel>"+value+"</n:MusicLabel>");
		}
		if(key == "Neighborhood")
		{
			file_desc.WriteLine("<n:Neighborhood>"+value+"</n:Neighborhood>");
		}
		if(key == "Orchestra")
		{
			file_desc.WriteLine("<n:Orchestra>"+value+"</n:Orchestra>");
		}
		if(key == "PostalCode")
		{
			file_desc.WriteLine("<n:PostalCode>"+value+"</n:PostalCode>");
		}
		if(key == "Power")
		{
			file_desc.WriteLine("<n:Power>"+value+"</n:Power>");
		}
		if(key == "Publisher")
		{
			file_desc.WriteLine("<n:Publisher>"+value+"</n:Publisher>");
		}
		if(key == "ResponseGroup")
		{
			file_desc.WriteLine("<n:ResponseGroup>"+value+"</n:ResponseGroup>");
		}
		if(key == "ReviewSort")
		{
			file_desc.WriteLine("<n:ReviewSort>"+value+"</n:ReviewSort>");
		}
		if(key == "SearchIndex")
		{
			file_desc.WriteLine("<n:SearchIndex>"+value+"</n:SearchIndex>");
		}
		if(key == "Sort")
		{
			file_desc.WriteLine("<n:Sort>"+value+"</n:Sort>");
		}
		if(key == "State")
		{
			file_desc.WriteLine("<n:State>"+value+"</n:State>");
		}
		if(key == "TagPage")
		{
			file_desc.WriteLine("<n:TagPage>"+value+"</n:TagPage>");
		}
		if(key == "TagsPerPage")
		{
			file_desc.WriteLine("<n:TagsPerPage>"+value+"</n:TagsPerPage>");
		}
		if(key == "TagSort")
		{
			file_desc.WriteLine("<n:TagSort>"+value+"</n:TagSort>");
		}
		if(key == "TextStream")
		{
			file_desc.WriteLine("<n:TextStream>"+value+"</n:TextStream>");
		}
		if(key == "Title")
		{
			file_desc.WriteLine("<n:Title>"+value+"</n:Title>");
		}
		else if(key == "ReleaseDate")
		{
			file_desc.WriteLine("<n:ReleaseDate>"+value+"</n:ReleaseDate>");
			
		}
	}
    if (soap == "true")
	{
		file_desc.WriteLine("</n:Request>");
	}
	file_desc.WriteLine("</n:ItemSearch>");
}

function amazoneclient_item_lookup(op_args, subscription_id, soap)
{
	var FSO = WScript.CreateObject("Scripting.FileSystemObject");
	var filename = "ItemLookup.xml";
	var file_desc = FSO.CreateTextFile(filename, true);
	op_args = op_args.split("#"); 
	file_desc.WriteLine("<n:ItemLookup xmlns:n=\"http://webservices.amazon.com/AWSECommerceService/2007-10-29\">");
	file_desc.WriteLine("<n:SubscriptionId>"+subscription_id+"</n:SubscriptionId>");
    if (soap == "true")
	{
		file_desc.WriteLine("<n:Request>");
	}
    else
	{
        file_desc.WriteLine("<n:Service>AWSECommerceService</n:Service>");
        file_desc.WriteLine("<n:Operation>ItemLookup</n:Operation>");
	}
	for(arg in op_args)
	{
		var segment = op_args[arg];
		var key;
		var value;
		segment = segment.split("@", 2);
		key = segment[0];
		if(segment.length > 1)
		{
			value = segment[1];
		}
		else
		{
			value = null;
		}
		WScript.StdOut.WriteLine("key:"+key+";value:"+value);
		if(key == "ISPUPostalCode")
		{
			file_desc.WriteLine("<n:ISPUPostalCode>"+value+"</n:ISPUPostalCode>");
		}
		if(key == "MerchantId")
		{
			file_desc.WriteLine("<n:MerchantId>"+value+"</n:MerchantId>");
		}
		else if(key == "OfferPage")
		{
			file_desc.WriteLine("<n:OfferPage>"+value+"</n:OfferPage>");
		}
		if(key == "ItemId")
		{
			file_desc.WriteLine("<n:ItemId>"+value+"</n:ItemId>");
		}
		if(key == "ResponseGroup")
		{
			file_desc.WriteLine("<n:ResponseGroup>"+value+"</n:ResponseGroup>");
		}
		if(key == "ReviewPage")
		{
			file_desc.WriteLine("<n:ReviewPage>"+value+"</n:ReviewPage>");
		}
		if(key == "ReviewSort")
		{
			file_desc.WriteLine("<n:ReviewSort>"+value+"</n:ReviewSort>");
		}
		if(key == "SearchIndex")
		{
			file_desc.WriteLine("<n:SearchIndex>"+value+"</n:SearchIndex>");
		}
		if(key == "SearchInsideKeywords")
		{
			file_desc.WriteLine("<n:SearchInsideKeywords>"+value+"</n:SearchInsideKeywords>");
		}
		if(key == "TagPage")
		{
			file_desc.WriteLine("<n:TagPage>"+value+"</n:TagPage>");
		}
		if(key == "TagsPerPage")
		{
			file_desc.WriteLine("<n:TagsPerPage>"+value+"</n:TagsPerPage>");
		}
		if(key == "TagSort")
		{
			file_desc.WriteLine("<n:TagSort>"+value+"</n:TagSort>");
		}
		if(key == "VariationPage")
		{
			file_desc.WriteLine("<n:VariationPage>"+value+"</n:VariationPage>");
		}
	}
    if (soap == "true")
	{
		file_desc.WriteLine("</n:Request>");
	}
	file_desc.WriteLine("</n:ItemLookup>");
}

function amazoneclient_cart_create(op_args, subscription_id)
{
	var FSO = WScript.CreateObject("Scripting.FileSystemObject");
	var filename = "CartCreate.xml";
	var file_desc = FSO.CreateTextFile(filename, true);
	op_args = op_args.split("#"); 
	file_desc.WriteLine("<n:CartCreate xmlns:n=\"http://webservices.amazon.com/AWSECommerceService/2007-10-29\">");
	file_desc.WriteLine("<n:SubscriptionId>"+subscription_id+"</n:SubscriptionId>");
	file_desc.WriteLine("<n:Service>AWSECommerceService</n:Service>");
	file_desc.WriteLine("<n:Operation>CartCreate</n:Operation>");
	for(arg in op_args)
	{
		var segment = op_args[arg];
		var key;
		var value;
		segment = segment.split("@", 2);
		key = segment[0];
		if(segment.length > 1)
		{
			value = segment[1];
		}
		else
		{
			value = null;
		}
		WScript.StdOut.WriteLine("key:"+key+"#value:"+value);
		if(key == "MergeCart")
		{
			file_desc.WriteLine("<n:MergeCart>"+value+"</n:MergeCart>");
		}
		if(key == "ResponseGroup")
		{
			file_desc.WriteLine("<n:ResponseGroup>"+value+"</n:ResponseGroup>");
		}
		if(key == "Items")
		{
			WScript.StdOut.WriteLine("value:"+value);
			value = value.split("$");
			for(i in value)
			{
				var xitem = value[i];
				if(!xitem)
					break;
				WScript.StdOut.WriteLine("item:"+xitem);
				xitem = xitem.split("!");
				for(j in xitem)
				{
					var itemfield = xitem[j];
					var key;
					var value;
					if(!itemfield)
						break;
					itemfield = itemfield.split("?", 2);
					key = itemfield[0];
					if(itemfield.length > 1)
					{
						value = itemfield[1];
					}
					else
						value = null;
					WScript.StdOut.WriteLine("key:"+key+"$value:"+value);
					if(key == "ASIN")
					{
						file_desc.WriteLine("<n:Item."+i+".ASIN>"+value+"</n:Item."+i+".ASIN>");
					}
					if(key == "OfferListingId")
					{
						file_desc.WriteLine("<n:Item."+i+".OfferListingId>"+value+"</n:Item."+i+".OfferListingId>");
					}
					if(key == "Quantity")
					{
						file_desc.WriteLine("<n:Item."+i+".Quantity>"+value+"</n:Item."+i+".Quantity>");
					}
					if(key == "AssociateTag")
					{
						file_desc.WriteLine("<n:Item."+i+".AssociateTag>"+value+"</n:Item."+i+".AssociateTag>");
					}
					if(key == "ListItemId")
					{
						file_desc.WriteLine("<n:Item."+i+".ListItemId>"+value+"</n:Item."+i+".ListItemId>");
					}

				}
			}
		}
	}
	file_desc.WriteLine("</n:CartCreate>");
}

function amazoneclient_cart_create_soap(op_args, subscription_id)
{
	var FSO = WScript.CreateObject("Scripting.FileSystemObject");
	var filename = "CartCreate.xml";
	var file_desc = FSO.CreateTextFile(filename, true);
	op_args = op_args.split("#"); 
	file_desc.WriteLine("<n:CartCreate xmlns:n=\"http://webservices.amazon.com/AWSECommerceService/2007-10-29\">");
	file_desc.WriteLine("<n:SubscriptionId>"+subscription_id+"</n:SubscriptionId>");
	file_desc.WriteLine("<n:Request>");
	for(arg in op_args)
	{
		var segment = op_args[arg];
		var key;
		var value;
		segment = segment.split("@", 2);
		key = segment[0];
		if(segment.length > 1)
		{
			value = segment[1];
		}
		else
		{
			value = null;
		}
		WScript.StdOut.WriteLine("key:"+key+"#value:"+value);
		if(key == "MergeCart")
		{
			file_desc.WriteLine("<n:MergeCart>"+value+"</n:MergeCart>");
		}
		if(key == "ResponseGroup")
		{
			file_desc.WriteLine("<n:ResponseGroup>"+value+"</n:ResponseGroup>");
		}
		if(key == "Items")
		{
			WScript.StdOut.WriteLine("value:"+value);
			file_desc.WriteLine("<n:Items>");
			value = value.split("$");
			for(i in value)
			{
				var xitem = value[i];
				if(!xitem)
					break;
				WScript.StdOut.WriteLine("item:"+xitem);
				file_desc.WriteLine("<n:Item>");
				xitem = xitem.split("!");
				for(j in xitem)
				{
					var itemfield = xitem[j];
					var key;
					var value;
					if(!itemfield)
						break;
					itemfield = itemfield.split("?", 2);
					key = itemfield[0];
					if(itemfield.length > 1)
					{
						value = itemfield[1];
					}
					else
						value = null;
					WScript.StdOut.WriteLine("key:"+key+"$value:"+value);
					if(key == "ASIN")
					{
						file_desc.WriteLine("<n:ASIN>"+value+"</n:ASIN>");
					}
					if(key == "OfferListingId")
					{
						file_desc.WriteLine("<n:OfferListingId>"+value+"</n:OfferListingId>");
					}
					if(key == "Quantity")
					{
						file_desc.WriteLine("<n:Quantity>"+value+"</n:Quantity>");
					}
					if(key == "AssociateTag")
					{
						file_desc.WriteLine("<n:AssociateTag>"+value+"</n:AssociateTag>");
					}
					if(key == "ListItemId")
					{
						file_desc.WriteLine("<n:ListItemId>"+value+"</n:ListItemId>");
					}

				}
				file_desc.WriteLine("</n:Item>");
			}

			file_desc.WriteLine("</n:Items>");
		}
	}
	file_desc.WriteLine("</n:Request>");
	file_desc.WriteLine("</n:CartCreate>");
}

function amazoneclient_cart_add(op_args, subscription_id)
{
	var FSO = WScript.CreateObject("Scripting.FileSystemObject");
	var filename = "CartAdd.xml";
	var file_desc = FSO.CreateTextFile(filename, true);
	var cart_id = null;
	var hmac = null;
	var contents = null;
	re = new RegExp("[^*]*<CartId>\([^*]*\)<\/CartId>[^*]*", "g");
	contents = amazoneclient_get_file_content("CartCreateResponse.xml");
	re.exec(contents);
	cart_id = RegExp.$1;
	re = new RegExp("[^*]*<HMAC>\([^*]*\)<\/HMAC>[^*]*", "g");
	re.exec(contents);
	hmac = RegExp.$1;
	WScript.StdOut.WriteLine("cart_id:"+cart_id);
	WScript.StdOut.WriteLine("hmac:"+hmac);
	op_args = op_args.split("#"); 
	file_desc.WriteLine("<n:CartAdd xmlns:n=\"http://webservices.amazon.com/AWSECommerceService/2007-10-29\">");
	file_desc.WriteLine("<n:SubscriptionId>"+subscription_id+"</n:SubscriptionId>");
	file_desc.WriteLine("<n:Service>AWSECommerceService</n:Service>");
	file_desc.WriteLine("<n:Operation>CartAdd</n:Operation>");
	file_desc.WriteLine("<n:CartId>"+cart_id+"</n:CartId>");
	file_desc.WriteLine("<n:HMAC>"+hmac+"</n:HMAC>");
	for(arg in op_args)
	{
		var segment = op_args[arg];
		var key;
		var value;
		segment = segment.split("@", 2);
		key = segment[0];
		if(segment.length > 1)
		{
			value = segment[1];
		}
		else
		{
			value = null;
		}
		WScript.StdOut.WriteLine("key:"+key+"#value:"+value);
		if(key == "MergeCart")
		{
			file_desc.WriteLine("<n:MergeCart>"+value+"</n:MergeCart>");
		}
		if(key == "ResponseGroup")
		{
			file_desc.WriteLine("<n:ResponseGroup>"+value+"</n:ResponseGroup>");
		}
		if(key == "Items")
		{
			WScript.StdOut.WriteLine("value:"+value);
			value = value.split("$");
			for(i in value)
			{
				var xitem = value[i];
				if(!xitem)
					break;
				WScript.StdOut.WriteLine("item:"+xitem);
				xitem = xitem.split("!");
				for(j in xitem)
				{
					var itemfield = xitem[j];
					var key;
					var value;
					if(!itemfield)
						break;
					itemfield = itemfield.split("?", 2);
					key = itemfield[0];
					if(itemfield.length > 1)
					{
						value = itemfield[1];
					}
					else
						value = null;
					WScript.StdOut.WriteLine("key:"+key+"$value:"+value);
					if(key == "ASIN")
					{
						file_desc.WriteLine("<n:Item."+i+".ASIN>"+value+"</n:Item."+i+".ASIN>");
					}
					if(key == "OfferListingId")
					{
						file_desc.WriteLine("<n:Item."+i+".OfferListingId>"+value+"</n:Item."+i+".OfferListingId>");
					}
					if(key == "Quantity")
					{
						file_desc.WriteLine("<n:Item."+i+".Quantity>"+value+"</n:Item."+i+".Quantity>");
					}
					if(key == "AssociateTag")
					{
						file_desc.WriteLine("<n:Item."+i+".AssociateTag>"+value+"</n:Item."+i+".AssociateTag>");
					}
					if(key == "ListItemId")
					{
						file_desc.WriteLine("<n:Item."+i+".ListItemId>"+value+"</n:Item."+i+".ListItemId>");
					}
				}
			}
		}
	}
	file_desc.WriteLine("</n:CartAdd>");
}

function amazoneclient_cart_add_soap(op_args, subscription_id)
{
	var FSO = WScript.CreateObject("Scripting.FileSystemObject");
	var filename = "CartAdd.xml";
	var file_desc = FSO.CreateTextFile(filename, true);
	var cart_id = null;
	var hmac = null;
	var contents = null;
	re = new RegExp("[^*]*<CartId>\([^*]*\)<\/CartId>[^*]*", "g");
	contents = amazoneclient_get_file_content("CartCreateResponse.xml");
	re.exec(contents);
	cart_id = RegExp.$1;
	re = new RegExp("[^*]*<HMAC>\([^*]*\)<\/HMAC>[^*]*", "g");
	re.exec(contents);
	hmac = RegExp.$1;
	WScript.StdOut.WriteLine("cart_id:"+cart_id);
	WScript.StdOut.WriteLine("hmac:"+hmac);
	op_args = op_args.split("#"); 
	file_desc.WriteLine("<n:CartAdd xmlns:n=\"http://webservices.amazon.com/AWSECommerceService/2007-10-29\">");
	file_desc.WriteLine("<n:SubscriptionId>"+subscription_id+"</n:SubscriptionId>");
	file_desc.WriteLine("<n:Request>");
	file_desc.WriteLine("<n:CartId>"+cart_id+"</n:CartId>");
	file_desc.WriteLine("<n:HMAC>"+hmac+"</n:HMAC>");
	for(arg in op_args)
	{
		var segment = op_args[arg];
		var key;
		var value;
		segment = segment.split("@", 2);
		key = segment[0];
		if(segment.length > 1)
		{
			value = segment[1];
		}
		else
		{
			value = null;
		}
		WScript.StdOut.WriteLine("key:"+key+"#value:"+value);
		if(key == "MergeCart")
		{
			file_desc.WriteLine("<n:MergeCart>"+value+"</n:MergeCart>");
		}
		if(key == "ResponseGroup")
		{
			file_desc.WriteLine("<n:ResponseGroup>"+value+"</n:ResponseGroup>");
		}
		if(key == "Items")
		{
			WScript.StdOut.WriteLine("value:"+value);
			file_desc.WriteLine("<n:Items>");
			value = value.split("$");
			for(i in value)
			{
				var xitem = value[i];
				if(!xitem)
					break;
				WScript.StdOut.WriteLine("item:"+xitem);
				file_desc.WriteLine("<n:Item>");
				xitem = xitem.split("!");
				for(j in xitem)
				{
					var itemfield = xitem[j];
					var key;
					var value;
					if(!itemfield)
						break;
					itemfield = itemfield.split("?", 2);
					key = itemfield[0];
					if(itemfield.length > 1)
					{
						value = itemfield[1];
					}
					else
						value = null;
					WScript.StdOut.WriteLine("key:"+key+"$value:"+value);
					if(key == "ASIN")
					{
						file_desc.WriteLine("<n:ASIN>"+value+"</n:ASIN>");
					}
					if(key == "OfferListingId")
					{
						file_desc.WriteLine("<n:OfferListingId>"+value+"</n:OfferListingId>");
					}
					if(key == "Quantity")
					{
						file_desc.WriteLine("<n:Quantity>"+value+"</n:Quantity>");
					}
					if(key == "AssociateTag")
					{
						file_desc.WriteLine("<n:AssociateTag>"+value+"</n:AssociateTag>");
					}
					if(key == "ListItemId")
					{
						file_desc.WriteLine("<n:ListItemId>"+value+"</n:ListItemId>");
					}

				}
				file_desc.WriteLine("</n:Item>");
			}

			file_desc.WriteLine("</n:Items>");
		}
	}
	file_desc.WriteLine("</n:Request>");
	file_desc.WriteLine("</n:CartAdd>");
}

function amazoneclient_cart_modify(op_args, subscription_id)
{
	var FSO = WScript.CreateObject("Scripting.FileSystemObject");
	var filename = "CartModify.xml";
	var file_desc = FSO.CreateTextFile(filename, true);
	var cart_id = null;
	var hmac = null;
	var contents = null;
	re = new RegExp("[^*]*<CartId>\([^*]*\)<\/CartId>[^*]*", "g");
	contents = amazoneclient_get_file_content("CartCreateResponse.xml");
	re.exec(contents);
	cart_id = RegExp.$1;
	re = new RegExp("[^*]*<HMAC>\([^*]*\)<\/HMAC>[^*]*", "g");
	re.exec(contents);
	hmac = RegExp.$1;
	WScript.StdOut.WriteLine("cart_id:"+cart_id);
	WScript.StdOut.WriteLine("hmac:"+hmac);
	op_args = op_args.split("#"); 
	file_desc.WriteLine("<n:CartModify xmlns:n=\"http://webservices.amazon.com/AWSECommerceService/2007-10-29\">");
	file_desc.WriteLine("<n:SubscriptionId>"+subscription_id+"</n:SubscriptionId>");
	file_desc.WriteLine("<n:Service>AWSECommerceService</n:Service>");
	file_desc.WriteLine("<n:Operation>CartModify</n:Operation>");
	file_desc.WriteLine("<n:CartId>"+cart_id+"</n:CartId>");
	file_desc.WriteLine("<n:HMAC>"+hmac+"</n:HMAC>");
	for(arg in op_args)
	{
		var segment = op_args[arg];
		var key;
		var value;
		segment = segment.split("@", 2);
		key = segment[0];
		if(segment.length > 1)
		{
			value = segment[1];
		}
		else
		{
			value = null;
		}
		WScript.StdOut.WriteLine("key:"+key+"#value:"+value);
		if(key == "MergeCart")
		{
			file_desc.WriteLine("<n:MergeCart>"+value+"</n:MergeCart>");
		}
		if(key == "ResponseGroup")
		{
			file_desc.WriteLine("<n:ResponseGroup>"+value+"</n:ResponseGroup>");
		}
		if(key == "Items")
		{
			WScript.StdOut.WriteLine("value:"+value);
			value = value.split("$");
			for(i in value)
			{
				var xitem = value[i];
				if(!xitem)
					break;
				WScript.StdOut.WriteLine("item:"+xitem);
				xitem = xitem.split("!");
				for(j in xitem)
				{
					var itemfield = xitem[j];
					var key;
					var value;
					if(!itemfield)
						break;
					itemfield = itemfield.split("?", 2);
					key = itemfield[0];
					if(itemfield.length > 1)
					{
						value = itemfield[1];
					}
					else
						value = null;
					WScript.StdOut.WriteLine("key:"+key+"$value:"+value);
					if(key == "CartItemId")
					{
						file_desc.WriteLine("<n:Item."+i+".CartItemId>"+value+"</n:Item."+i+".CartItemId>");
					}
					if(key == "Quantity")
					{
						file_desc.WriteLine("<n:Item."+i+".Quantity>"+value+"</n:Item."+i+".Quantity>");
					}
				}
			}
		}
	}
	file_desc.WriteLine("</n:CartModify>");
}

function amazoneclient_cart_modify_soap(op_args, subscription_id)
{
	var FSO = WScript.CreateObject("Scripting.FileSystemObject");
	var filename = "CartModify.xml";
	var file_desc = FSO.CreateTextFile(filename, true);
	var cart_id = null;
	var hmac = null;
	var contents = null;
	re = new RegExp("[^*]*<CartId>\([^*]*\)<\/CartId>[^*]*", "g");
	contents = amazoneclient_get_file_content("CartCreateResponse.xml");
	re.exec(contents);
	cart_id = RegExp.$1;
	re = new RegExp("[^*]*<HMAC>\([^*]*\)<\/HMAC>[^*]*", "g");
	re.exec(contents);
	hmac = RegExp.$1;
	WScript.StdOut.WriteLine("cart_id:"+cart_id);
	WScript.StdOut.WriteLine("hmac:"+hmac);
	op_args = op_args.split("#"); 
	file_desc.WriteLine("<n:CartModify xmlns:n=\"http://webservices.amazon.com/AWSECommerceService/2007-10-29\">");
	file_desc.WriteLine("<n:SubscriptionId>"+subscription_id+"</n:SubscriptionId>");
	file_desc.WriteLine("<n:Request>");
	file_desc.WriteLine("<n:CartId>"+cart_id+"</n:CartId>");
	file_desc.WriteLine("<n:HMAC>"+hmac+"</n:HMAC>");
	for(arg in op_args)
	{
		var segment = op_args[arg];
		var key;
		var value;
		segment = segment.split("@", 2);
		key = segment[0];
		if(segment.length > 1)
		{
			value = segment[1];
		}
		else
		{
			value = null;
		}
		WScript.StdOut.WriteLine("key:"+key+"#value:"+value);
		if(key == "MergeCart")
		{
			file_desc.WriteLine("<n:MergeCart>"+value+"</n:MergeCart>");
		}
		if(key == "ResponseGroup")
		{
			file_desc.WriteLine("<n:ResponseGroup>"+value+"</n:ResponseGroup>");
		}
		if(key == "Items")
		{
			WScript.StdOut.WriteLine("value:"+value);
			file_desc.WriteLine("<n:Items>");
			value = value.split("$");
			for(i in value)
			{
				var xitem = value[i];
				if(!xitem)
					break;
				WScript.StdOut.WriteLine("item:"+xitem);
				file_desc.WriteLine("<n:Item>");
				xitem = xitem.split("!");
				for(j in xitem)
				{
					var itemfield = xitem[j];
					var key;
					var value;
					if(!itemfield)
						break;
					itemfield = itemfield.split("?", 2);
					key = itemfield[0];
					if(itemfield.length > 1)
					{
						value = itemfield[1];
					}
					else
						value = null;
					WScript.StdOut.WriteLine("key:"+key+"$value:"+value);
					if(key == "CartItemId")
					{
						file_desc.WriteLine("<n:CartItemId>"+value+"</n:CartItemId>");
					}
					if(key == "Quantity")
					{
						file_desc.WriteLine("<n:Quantity>"+value+"</n:Quantity>");
					}
				}
				file_desc.WriteLine("</n:Item>");
			}

			file_desc.WriteLine("</n:Items>");
		}
	}
	file_desc.WriteLine("</n:Request>");
	file_desc.WriteLine("</n:CartModify>");
}

function amazoneclient_cart_clear(op_args, subscription_id, soap)
{
	var FSO = WScript.CreateObject("Scripting.FileSystemObject");
	var filename = "CartClear.xml";
	var file_desc = FSO.CreateTextFile(filename, true);
	var cart_id = null;
	var hmac = null;
	var contents = null;
	re = new RegExp("[^*]*<CartId>\([^*]*\)<\/CartId>[^*]*", "g");
	contents = amazoneclient_get_file_content("CartCreateResponse.xml");
	re.exec(contents);
	cart_id = RegExp.$1;
	re = new RegExp("[^*]*<HMAC>\([^*]*\)<\/HMAC>[^*]*", "g");
	re.exec(contents);
	hmac = RegExp.$1;
	WScript.StdOut.WriteLine("cart_id:"+cart_id);
	WScript.StdOut.WriteLine("hmac:"+hmac);
	op_args = op_args.split("#"); 
	file_desc.WriteLine("<n:CartClear xmlns:n=\"http://webservices.amazon.com/AWSECommerceService/2007-10-29\">");
	file_desc.WriteLine("<n:SubscriptionId>"+subscription_id+"</n:SubscriptionId>");
    if (soap == "true")
	{
		file_desc.WriteLine("<n:Request>");
	}
    else
	{
        file_desc.WriteLine("<n:Service>AWSECommerceService</n:Service>");
        file_desc.WriteLine("<n:Operation>CartClear</n:Operation>");
	}
	file_desc.WriteLine("<n:CartId>"+cart_id+"</n:CartId>");
	file_desc.WriteLine("<n:HMAC>"+hmac+"</n:HMAC>");
	for(arg in op_args)
	{
		var segment = op_args[arg];
		var key;
		var value;
		segment = segment.split("@", 2);
		key = segment[0];
		if(segment.length > 1)
		{
			value = segment[1];
		}
		else
		{
			value = null;
		}
		WScript.StdOut.WriteLine("key:"+key+"#value:"+value);
		if(key == "MergeCart")
		{
			file_desc.WriteLine("<n:MergeCart>"+value+"</n:MergeCart>");
		}
		if(key == "ResponseGroup")
		{
			file_desc.WriteLine("<n:ResponseGroup>"+value+"</n:ResponseGroup>");
		}
	}
    if(soap == "true")
    {
	    file_desc.WriteLine("</n:Request>");
    }
	file_desc.WriteLine("</n:CartClear>");
}

function amazoneclient_process_op(op_name, op_args, subscription_id, soap)
{
	if(op_name == "ItemSearch")
	{
		amazoneclient_item_search(op_args, subscription_id, soap);
	}
	if(op_name == "ItemLookup")
	{
		amazoneclient_item_lookup(op_args, subscription_id, soap);
	}
	if(op_name == "CartCreate")
	{
		if(soap == "true")
		{
			amazoneclient_cart_create_soap(op_args, subscription_id);
		}
		else
		{
			amazoneclient_cart_create(op_args, subscription_id);
		}
	}
	if(op_name == "CartAdd")
	{
		if(soap == "true")
		{
			amazoneclient_cart_add_soap(op_args, subscription_id);
		}
		else
		{
			amazoneclient_cart_add(op_args, subscription_id);
		}
	}
	if(op_name == "CartModify")
	{
		if(soap == "true")
		{
			amazoneclient_cart_modify_soap(op_args, subscription_id);
		}
		else
		{
			amazoneclient_cart_modify(op_args, subscription_id);
		}
	}
	if(op_name == "CartClear")
	{
		amazoneclient_cart_clear(op_args, subscription_id, soap);
	}
}

// Process amazoneclient arguments
function amazoneclient_process_args()
{
	args = WScript.Arguments;
	for (i = 0; i < args.length; i++) 
	{
		arg = args(i);
		// If it is --foo=bar, split on the equals sign
		arg = arg.split("=", 2);
		argname = arg[0];
		if (arg.length > 1) 
		{
			argval = arg[1];
			/*WScript.StdOut.WriteLine("argval:" + argval);*/
		} else 
		{
			argval = null;
		}

		if (argname == '--subscription_id' && argval != null) 
		{
			subscription_id = argval
			WScript.StdOut.WriteLine("subscription_id:" + subscription_id);
		}
		if (argname == '--op' && argval != null) 
		{
			op = argval
			WScript.StdOut.WriteLine("op:" + op);
		}
		if (argname == '--op_args' && argval != null) 
		{
			op_args = argval
			WScript.StdOut.WriteLine("op_args:" + op_args);
		}
		if (argname == '--soap') 
		{
			soap = "true";
			WScript.StdOut.WriteLine("soap:" + soap);
		}
	}
}


amazoneclient_process_args();
amazoneclient_process_op(op, op_args, subscription_id, soap);
if(!subscription_id)
{
	WScript.StdOut.WriteLine("Visit http://aws.amazon.com to aget a Amazon key");
}

