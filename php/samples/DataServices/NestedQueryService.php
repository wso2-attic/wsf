<?php

        // import the DataService Library

        require_once("wso2/DataServices/DataService.php");
        require_once("constants.php");
        
        // building the config array

        $config = array("db" => "mysql", // change this to your db engine name 
                    "username" => DB_USERNAME, 
                    "password" => DB_PASSWORD, 
                    "dbname" => "ds", // change this to your db name
                    "dbhost" => "localhost"); // change this to your db host

        // ----------building the queries for customerOrders ------------
            
        // building the input format for the customerOrdersSQL
        
        $customerOrdersSQL_input_format =  NULL;
        
        // building the output elements for the customerOrdersSQL
                
        $customerOrdersSQL_elements = array("Order_number" => "ORDERNUMBER", 
                            "Order_date" => "ORDERDATE", 
                            "Status" => "STATUS");
                
        // ------- building the query customerNameSQL called from query customerOrdersSQL ------
        
        // building the input format for the customerNameSQL
        
        $customerNameSQL_1_1_input_format = array("customerNumber" => "INTEGER");
        
        // building the output elements for the customerNameSQL
                
        $customerNameSQL_1_1_elements = array("Name" => "CUSTOMERNAME");
                
        // building the output elements order for the customerNameSQL
        
        $customerNameSQL_1_1_elements_order = array("Name");
        
        // building the output format for the customerNameSQL
        
        $customerNameSQL_1_1_output_format =  array(
            "resultElement" => "Customers",
            "rowElement" => "Customer",
            "elements" => $customerNameSQL_1_1_elements,
            "elementsOrder" => $customerNameSQL_1_1_elements_order);
        
        
        // building the sql for the customerNameSQL
        
        $customerNameSQL_1_1_sql = "select c.CUSTOMERNAME from ds.Customers c where c.CUSTOMERNUMBER = ?";
        
        // building the input mapping for the customerNameSQL
        
        $customerNameSQL_1_1_input_mapping = array("CUSTOMERNUMBER" => "customerNumber");
        
        $customerNameSQL_1_1_query = array(
                    "inputFormat" => $customerNameSQL_1_1_input_format,
                    "outputFormat" => $customerNameSQL_1_1_output_format,
                    "sql" => $customerNameSQL_1_1_sql,
                    "inputMapping" => $customerNameSQL_1_1_input_mapping);

            
        // ------- finished the query customerNameSQL called from query customerOrdersSQL -------
        
        // building the output queries for the customerOrdersSQL
                
        $customerOrdersSQL_queries = array("query1" => $customerNameSQL_1_1_query);
                
        // building the output elements order for the customerOrdersSQL
        
        $customerOrdersSQL_elements_order = array("Order_number",
                    "Order_date",
                    "Status",
                    "OrderId",
                    "query1");
        
        // building the output format for the customerOrdersSQL
        
        $customerOrdersSQL_output_format =  array(
            "resultElement" => "Orders",
            "rowElement" => "Order",
            "elements" => $customerOrdersSQL_elements,
            "attributes" => array("OrderId" => "ORDERNUMBER"),
            "queries" => $customerOrdersSQL_queries,
            "elementsOrder" => $customerOrdersSQL_elements_order);
        
        
        // building the sql for the customerOrdersSQL
        
        $customerOrdersSQL_sql = "select o.ORDERNUMBER,o.ORDERDATE, o.STATUS,o.CUSTOMERNUMBER from ds.Orders o";
        
        // building the input mapping for the customerOrdersSQL
        
        $customerOrdersSQL_input_mapping =  NULL;
        
        $customerOrders = array(
                    "inputFormat" => $customerOrdersSQL_input_format,
                    "outputFormat" => $customerOrdersSQL_output_format,
                    "sql" => $customerOrdersSQL_sql,
                    "inputMapping" => $customerOrdersSQL_input_mapping);
            
        // ------------finished queries for customerOrders--------------
        

        // ----------building the queries for customerName ------------
            
        // building the input format for the customerNameSQL
        
        $customerNameSQL_input_format = array("customerNumber" => "INTEGER");
        
        // building the output elements for the customerNameSQL
                
        $customerNameSQL_elements = array("Name" => "CUSTOMERNAME");
                
        // building the output elements order for the customerNameSQL
        
        $customerNameSQL_elements_order = array("Name");
        
        // building the output format for the customerNameSQL
        
        $customerNameSQL_output_format =  array(
            "resultElement" => "Customers",
            "rowElement" => "Customer",
            "elements" => $customerNameSQL_elements,
            "elementsOrder" => $customerNameSQL_elements_order);
        
        
        // building the sql for the customerNameSQL
        
        $customerNameSQL_sql = "select c.CUSTOMERNAME from ds.Customers c where c.CUSTOMERNUMBER = ?";
        
        // building the input mapping for the customerNameSQL
        
        $customerNameSQL_input_mapping = array("customerNumber" => "CUSTOMERNUMBER");
        
        $customerName = array(
                    "inputFormat" => $customerNameSQL_input_format,
                    "outputFormat" => $customerNameSQL_output_format,
                    "sql" => $customerNameSQL_sql,
                    "inputMapping" => $customerNameSQL_input_mapping);
            
        // ------------finished queries for customerName--------------
        

        // building the operations array

        $operations = array("customerOrders" => $customerOrders, 
                    "customerName" => $customerName);

        // create the DataService object and reply
        $ds = new DataService(array("operations" => $operations,
                              "config" => $config,
                              "serviceName" => "NextedQuerySample"));
        $ds->reply();
        
?>
