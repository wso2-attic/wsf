
<html>
<head>
<link href="./assets/style/style3.css" rel="stylesheet" type="text/css" />
</head>
<body>
	
<table>
<tr>

<td><b><u>Details</u></b></td>

<td><b><u>Description</u></b><td>

</tr>
<br>
<br>

<tr>
<td><b>userID</td>
<?php
echo"<td><b>$userID</b></td>";
?>
</tr>

<tr>
<td>Name</td>
<?php
echo"<td>$firstName.$lastName</td>";
?>
</tr>

<tr>
<td>Address</td>
<?php
echo"<td>$address</td>";
?>
</tr>

<tr>
<td>Email</td>
<?php
echo"<td>$email</td>";
?>
</tr>

<tr>
<td>Country</td>
<?php
echo"<td>$country</td>";
?>
</tr>

<tr>
<td>Postel code</td>
<?php
echo"<td>$code</td>";
?>
</tr>


</table>

<a href="login_client.php"><img src="./assets/images/arrow.jpg">Back to the login page</a>

</body>
</html>


