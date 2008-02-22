function goLastMonth(month, year)
{
// If the month is Januaru, decrement the year
if(month == 1)
{
--year;
month = 13;
}

document.location.href = 'get_event_client.php?month='+(month-1)+'&year='+year;
} 

function goNextMonth(month, year)
{
// If the month is December, increment the year
if(month == 12)
{
++year;
month = 0;
}

document.location.href = 'get_event_client.php?month='+(month+1)+'&year='+year;
}


function display(month,year,week)
{

document.location.href='get_event_client.php?month='+month+'&year='+year+'&week='+week;
}

function greating()
{
var d = new Date()
var time = d.getHours()
if (time<10)
{
document.write("<b>Good morning</b>");
}
else (time>10 && time<16)
{
document.write("<b>Good day</b>");
}

}

function greating_day(){
//You will receive a different greeting based
//on what day it is. Note that Sunday=0,
//Monday=1, Tuesday=2, etc.
var d=new Date();
theDay=d.getDay();
switch (theDay)
{
case 5:
  document.write("Finally Friday");
  break;
case 6:
  document.write("Super Saturday");
  break;
case 4:
  document.write("Good Thursday");
  break;
case 3:
 document.write("Happy Wednesday");
 break;
case 2:
 document.write("Super Thursday");
 break;
case 1:
 document.write("Begin Monday");
 break;
case 0:
 document.write("Sleepy Sunday");
 break;
default:
  document.write("I'm looking forward to this weekend!");
}
}

function function1(day,time)
{

var answer = prompt ("Add a event for"+day);

}

