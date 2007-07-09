Connect to mysql as root user
mysql -u root -p
Then execute
grant all privileges on *.* TO 'g'@'localhost' identified by 'g' with grant option;
grant all privileges on *.* TO 'g'@'%' identified by 'g' with grant option;
