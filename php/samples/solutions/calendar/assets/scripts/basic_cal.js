function goLastMonth(month, year)
{
// If the month is Januaru, decrement the year
if(month == 1)
{
--year;
month = 13;
}

document.location.href = 'calendar_client.php?month='+(month-1)+'&year='+year;
} 

function goNextMonth(month, year)
{
// If the month is December, increment the year
if(month == 12)
{
++year;
month = 0;
}

document.location.href = 'calendar_client.php?month='+(month+1)+'&year='+year;
}


function display(month,year,week)
{

document.location.href='calendar_client.php?month='+month+'&year='+year+'&week='+week;
}

