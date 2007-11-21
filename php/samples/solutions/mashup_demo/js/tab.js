var Widget = {};


Widget.TabPanel = function(parent, thisString, width, tabWidth, keepBody)
{
	this.init(parent, thisString, width, tabWidth, keepBody);
}

Widget.TabPanel.tabs = {}

Widget.TabPanel.prototype =
{
	parent: null, //some container element
	thisString: "", // how this should be taken
	
	tabs: Array(),
	count: 0,
	
	selectedTab: -1,
	
	tabWidth: 120,
	width: 0,
	
	onSelectFn: null,
	onSelectPreFn: null,
	
	tabHeader: null,
	tabBodyInner: null,
	tabBodyOuter: null,
	tabRemaining: null,
	
	
	init: function( parent, thisString, width, tabWidth, keepBody)
	{
		this.parent = parent;
		if( thisString == null )
		{
			alert( "wrong_use of tab. thisString cannot be null");
		}
		this.thisString = thisString;
		
		if( width == null )
		{
			alert( "wrong_use of tab. width cannont be null");
		} this.width = width;
		
		this.tabs = [];
		
		if(tabWidth)
		{
			this.tabWidth = tabWidth;
		}
		this.keepBody = keepBody;
		
	},
	
	// copied from yui
	browser : function() {
		var ua = navigator.userAgent.toLowerCase();
		if (ua.indexOf('opera')!=-1) { // Opera (check first in case of spoof)
		 return 'opera';
		} else if (ua.indexOf('msie 7')!=-1) { // IE7
		 return 'ie7';
		} else if (ua.indexOf('msie') !=-1) { // IE
		 return 'ie';
		} else if (ua.indexOf('safari')!=-1) { // Safari (check before Gecko because it includes "like Gecko")
		 return 'safari';
		} else if (ua.indexOf('gecko') != -1) { // Gecko
		 return 'gecko';
		} else {
		 return false;
		}
	},
	
	show: function()
	{
		var totalWidth = this.count * this.tabWidth;
		
		if( this.width < totalWidth +15 )
		{
			this.width = totalWidth +15 ;
		}
		innerHTML = "<div id=\"tabHeader" + this.thisString + "\" style=\"width:" + this.width+ "px; position:relative\" >";;
		
		for( i = 0; i < this.count; i ++ )
		{
			innerHTML += "<div style=\"float:left; width:" + this.tabWidth+ "px\" ";
			
			innerHTML += "onClick=\"eval('"+ this.thisString + ".selectTab("+i+")');\">";
			
			if( this.selectedTab == i )
			{
				innerHTML += "<div class=\"bottom_selected\"><div class=\"rright\">" +
				               "<div class=\"left_selected\"><div class=\"top_selected\">"; 
				innerHTML += "<div class=\"tl_selected\"><div class=\"tr_selected\">";
			}
			else
			{
				innerHTML += "<div class=\"bbottom\"><div class=\"left\"><div class=\"rright\"><div class=\"top\">";
				innerHTML += "<div class=\"tl\"><div class=\"ttr\">";
			}
			
			innerHTML += this.tabs[i].title;
			
			innerHTML += "</div></div></div></div>";
			innerHTML += "</div></div>"; 
			innerHTML += "</div>"; 
		}
					
		// to fill the empty parts
		var remaining = this.getRemainingWidth();
		
		innerHTML += "<div id=\"tabRemaining" + this.thisString + "\" style=\"float:left; width:" + remaining+ "px\" ";
		innerHTML += "<div class=\"bottomremaining\">";
		innerHTML += "&nbsp;";
		innerHTML += "</div>";
		innerHTML += "</div>";
				
		innerHTML += "</div>";
		
		// fill the body
		innerHTML += "<div style=\"float:left; width:" + this.width+ "px\" id=\"tabBodyOuter" + this.thisString + "\">";
		
		innerHTML += "<div class=\"bottombody\"><div class=\"leftbody\"><div class=\"rright\">";
		innerHTML += "<div class=\"br\"><div class=\"bl\"><div class=\"ttr\">";
		innerHTML += "<div style=\"overflow:auto; height:500px;\" id=\"tabBodyInner" + this.thisString + "\" >";

		if(this.selectedTab == -1)
		{
			this.selectedTab = 0;
		}

		innerHTML += "</div>";
		innerHTML += this.tabs[this.selectedTab].innerHTML;
		
		innerHTML += "</div></div></div>";
		innerHTML += "</div></div></div>"; 
		innerHTML += "</div>";
		
		this.parent.innerHTML = innerHTML;
		
		this.tabHeader = document.getElementById( 'tabHeader'+ this.thisString );
		this.tabRemaining = document.getElementById( 'tabRemaining'+ this.thisString );
		this.tabBodyInner = document.getElementById( 'tabBodyInner'+ this.thisString );
		this.tabBodyOuter = document.getElementById( 'tabBodyOuter'+ this.thisString );
		
	},
	
	getRemainingWidth: function()
	{
		var totalWidth = this.count * this.tabWidth;
		
		var remaining = this.width - totalWidth;
		if( this.browser() == 'ie' || this.browser() == 'ie7'|| this.browser() == 'opera' )
		{
			remaining -= 10;
		}
		else
		{
			// this should be adjust according to the number of inital tabs
			remaining -= 5;
		}
		return remaining;
	},
	
	setWidth: function( width )
	{
		
		var totalWidth = this.count * this.tabWidth;
		if( width < totalWidth + 15)
		{
			return;
		}
		this.width = width;
		
		if( this.tabRemaining != null )
		{
			this.tabRemaining.style.width = this.getRemainingWidth() + "px";
		}
		if( this.tabHeader != null )
		{
			this.tabHeader.style.width = width + "px";
		}
		if( this.tabBodyOuter != null )
		{
			this.tabBodyOuter.style.width = width +"px";
		}
	},
	
	getTabBody: function()
	{
		return this.tabBodyInner;
	},
    getTabBodyId: function()
    {
        return "tabBodyInner" + this.thisString;
    },
	
	selectTab: function( t)
	{
		var found = 0;
		if( typeof t == "number" )
		{
			if(this.selectedTab == t)
			{
				return;
			}
			this.selectedTab = t;
			t = this.tabs[t];
			found = 1;
		}
		else
		{
			for( i = 0; i < this.count; i ++ )
			{
				if( this.tabs[i] == t || 
					this.tabs[i].title == t.title ) //tabs need not to be the same..
				{
					if(this.selectedTab == i)
					{
						return;
					}
					this.selectedTab = i;
					found = 1;
				}
			}
		}
		if( !found)
		{
			return -1;
		}
		if(this.onSelectPre != null)
		{
			this.onSelectPre(t);
		}
		
		this.show();
		if( this.onSelect != null )
		{
			this.onSelect(t);
		}
		
		if( this.tabBodyInner != null )
		{
			//this.tabBodyInner.innerHTML = t.innerHTML;
		}
		return 0;
	},
	
	addTab: function( t)
	{
		this.tabs[this.count] = t;
		this.count ++;
	},
	
	removeTab: function( t)
	{
		found = false;
		for( i = 0; i < this.count; i ++ )
		{
			if( found )
			{
				this.tabs[i-1] = this.tabs[i]; //shift everything
			}
			if( (typeof t == "number" && t == i )
			    ||(this.tabs[i] == t || 
			       this.tabs[i].title == t.title)  ) //tabs need not to be the same..
			{
				found = true;
			}
		}
		if( found )
		{
			this.count --;
		}
	},
	getSelected: function()
	{
		return this.tabs[this.selectedTab];
	},
	
	setOnSelect: function(onSelect)
	{
		this.onSelect = onSelect;
	},
	
	reset: function()
	{
		this.count = 0;
	},
	
	toString: function()
	{
		str = "";
		for( i = 0; i < this.count; i ++ )
		{
			str += this.tabs[i].title;
			if( i != this.count -1 )
			{
				str += ",";
			}
		}
	},
	
	getCount: function()
	{
		return this.count;
	},
	
	final: null
}

/** 
 * class: Tab
 * args: title - Title of the tab
 */
Widget.Tab = function( title, innerHTML, id)
{
	this.init( title, innerHTML, id);
}

Widget.Tab.prototype = 
{
	title: "",
	id: null,
	
	innerHTML: "", 
	
	init: function(title, innerHTML,id)
	{
		this.title = title;
		this.id = id;
		if( innerHTML != null )
		{
			this.innerHTML = innerHTML;
		}
	},
	
	setInnerHTML: function( innerHTML )
	{
		this.innerHTML = innerHTML;
	},
	
	final: null
}
