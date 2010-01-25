:: REM Please pay attention to the following delimiters
:: :	Command line parameter key:value pair separator.
:: #	In the opargs list each list item is separated by this delimiter.
:: @	For each opargs list item key:value pair is separated by this delimiter.
:: $	In the Items oparg list item, each item is separated by this delimiter.
:: !	For Items opargs list item, each item field is separated by this delimeter.
:: ?	For Items opargs list item, each items field key:value pairs are separated by this delimiter.
::
amazoneclient.bat /subscriptionid:0EADDHWF3PPVRSMBB2R2 /op:CartAdd /soap:false /opargs:Items@ASIN?0131488740!Quantity?5$ASIN?B000OIKRPG!Quantity?2
