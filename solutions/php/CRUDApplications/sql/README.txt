echo "create database RESTfulSchool;" | mysql -u dimuthu -p

mysql -u user -p -D RESTfulSchool < create_tables.sql 
mysql -u user -p -D RESTfulSchool < initial_data.sql 

