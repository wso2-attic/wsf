<?php
    if(array_key_exists("example", $_GET)) {
        if($_GET["example"] == "Example1") {
            $default_text = <<<TEXT1
<data name="DataServiceSample2">                                
    <config>                                                                
        <property name="org.wso2.ws.dataservice.driver">org.apache.derby.jdbc.EmbeddedDriver</property>                                                                
        <property name="org.wso2.ws.dataservice.protocol">jdbc:derby:../samples/DataService/database/DATA_SERV_SAMP</property>                                                                
        <property name="org.wso2.ws.dataservice.user">wso2wsas</property>                                                                
        <property name="org.wso2.ws.dataservice.password">wso2wsas</property>                                
    </config>

    <operation name="topCustomersInCalifornia">                                
        <call-query href="topCustomersInCaliforniaSQL" />                
    </operation>                
    <query id="topCustomersInCaliforniaSQL">
        <sql>select c.CUSTOMERNUMBER, c.CONTACTLASTNAME, c.CONTACTFIRSTNAME, c.PHONE
from WSO2WSAS.ORDERS o, WSO2WSAS.ORDERDETAILS od, WSO2WSAS.PRODUCTS p, WSO2WSAS.CUSTOMERS c 
where o.ORDERNUMBER = od.ORDERNUMBER and od.PRODUCTCODE = p.PRODUCTCODE 
  and c.CUSTOMERNUMBER = o.CUSTOMERNUMBER 
and c.STATE = 'CA' and c.COUNTRY = 'USA'
and o.ORDERDATE > '2000-12-31' 
group by c.CUSTOMERNUMBER, c.CONTACTLASTNAME, c.CONTACTFIRSTNAME, c.PHONE 
having integer(sum(od.QUANTITYORDERED * od.PRICEEACH)) > 50000 
order by c.CUSTOMERNUMBER</sql>                                
        <result element="top-customers" rowName="customer-info">                                                
            <element name="customer-number" column="CUSTOMERNUMBER" />                                                
            <element name="last-name" column="CONTACTLASTNAME" />                                                
            <element name="first-name" column="CONTACTFIRSTNAME" />                                                
            <element name="telephone" column="PHONE" />                                                
        </result>                
    </query>

    <operation name="topEmployeesInMA">
        <call-query href="topEmployeesInMASQL" />
    </operation>    
    <query id="topEmployeesInMASQL">        
        <sql>select e.EMPLOYEENUMBER, e.LASTNAME, e.FIRSTNAME, e.JOBTITLE 
from WSO2WSAS.EMPLOYEES e, WSO2WSAS.CUSTOMERS c, WSO2WSAS.ORDERS o, WSO2WSAS.ORDERDETAILS od 
where e.EMPLOYEENUMBER = c.SALESREPEMPLOYEENUMBER and c.CUSTOMERNUMBER = o.CUSTOMERNUMBER  and o.ORDERNUMBER = od.ORDERNUMBER  
and c.STATE = 'MA' and c.COUNTRY = 'USA'  and o.ORDERDATE >= '2004-01-01' 
group by e.EMPLOYEENUMBER, e.LASTNAME, e.FIRSTNAME, e.JOBTITLE 
having integer(sum(od.QUANTITYORDERED * od.PRICEEACH)) > 10000</sql>        
        <result element="top-employees" rowName="employee">            
            <element name="emp-no" column="EMPLOYEENUMBER" />            
            <element name="last-name" column="LASTNAME" />            
            <element name="first-name" column="FIRSTNAME" />            
            <element name="job-title" column="JOBTITLE" />            
        </result>    
    </query>
</data>

TEXT1;
        }
        if($_GET["example"] == "Example2") {
            $default_text = <<<TEXT1
<data name="DeptUpdateService">
    <config>
        <property name="org.wso2.ws.dataservice.driver">org.apache.derby.jdbc.EmbeddedDriver</property>
        <property name="org.wso2.ws.dataservice.protocol">jdbc:derby:../samples/DataService/database/DATA_SERV_SAMP</property>
        <property name="org.wso2.ws.dataservice.user">wsas</property>
        <property name="org.wso2.ws.dataservice.password">wsas</property>
    </config>    

    <operation name="addNewDepartment">
        <call-query href="addDept">
            <with-param name="deptId" query-param="deptId" />
            <with-param name="deptName" query-param="deptName" />
        </call-query>
    </operation>
    <query id="addDept">
        <sql>insert into department (id,name) values (?,?)</sql>
        <result element="Results" rowName="Result" />
        <param name="deptId" sqlType="INTEGER" />
        <param name="deptName" sqlType="STRING" />
    </query>

    <operation name="updateDepartment">
        <call-query href="updateDept">
            <with-param name="deptId" query-param="deptId" />
            <with-param name="deptName" query-param="deptName" />
        </call-query>
    </operation>
    <query id="updateDept">
        <sql>update department set name = ?  where id = ?</sql>
        <result element="Results" rowName="Result" />
        <param name="deptName" sqlType="STRING" />
        <param name="deptId" sqlType="INTEGER" />
    </query>

</data>
TEXT1;
        }
        if($_GET["example"] == "Example3") {
            $default_text = <<<TEXT1
<data name="DataServiceSample1">            
    <config>                        
        <property name="org.wso2.ws.dataservice.driver">org.apache.derby.jdbc.EmbeddedDriver</property>                        
        <property name="org.wso2.ws.dataservice.protocol">jdbc:derby:../samples/DataService/database/DATA_SERV_SAMP</property>                        
        <property name="org.wso2.ws.dataservice.user">wso2wsas</property>                        
        <property name="org.wso2.ws.dataservice.password">wso2wsas</property>            
    </config>

    <operation name="customersInBoston">                        
        <call-query href="customersInBostonSQL" />
    </operation>
    <query id="customersInBostonSQL">
        <sql>select  * from Customers where city = 'Boston' and country = 'USA'</sql>
        <result element="customers" rowName="customer">
            <element name="customer-name" column="customerName" />
            <element name="contact-last-name" column="contactLastName" />
            <element name="contact-first-name" column="contactFirstName" />
            <element name="phone" column="phone" />
            <element name="city" column="city" />
            <element name="country" column="country" />
        </result>
    </query>

    <operation name="employeesByNumber">
        <call-query href="employeesByNumberSQL">
            <with-param name="employeeNumber" query-param="employeeNumber" />
        </call-query>
    </operation>
    <query id="employeesByNumberSQL">
        <sql>select * from Employees where employeeNumber = ?</sql>
        <result element="employees" rowName="employee">
            <element name="last-name" column="lastName" />
            <element name="first-name" column="firstName" />
            <element name="email" column="email" />
        </result>
        <param name="employeeNumber" sqlType="INTEGER" />
    </query>

    <operation name="customerAddress">
        <call-query href="customerAddressSQL">
            <with-param name="lastName" query-param="lastName" />
            <with-param name="firstName" query-param="firstName" />
        </call-query>
    </operation>
    <query id="customerAddressSQL">
        <sql>select * from Customers where contactLastName = ? and contactFirstName = ?</sql>
        <result element="customer-addresses" rowName="customer-address">
            <element name="customer-number" column="customerNumber" />
            <element name="contact-last-name" column="contactLastName" />
            <element name="contact-first-name" column="contactFirstName" />
            <element name="address-line1" column="addressLine1" />
            <element name="address-line2" column="addressLine2" />
            <element name="city" column="city" />
            <element name="state" column="state" />
            <element name="postal-code" column="postalCode" />
            <element name="country" column="country" />
        </result>
        <param name="lastName" sqlType="STRING" />
        <param name="firstName" sqlType="STRING" />
    </query>
</data> 
TEXT1;
        }
        if($_GET["example"] == "Example4") {
            $default_text = <<<TEXT1
<data name="NextedQuerySample">
   <config>
      <property name="org.wso2.ws.dataservice.driver">org.apache.derby.jdbc.EmbeddedDriver</property>
      <property name="org.wso2.ws.dataservice.protocol">jdbc:derby:../samples/DataService/database/DATA_SERV_SAMP</property>
      <property name="org.wso2.ws.dataservice.user">wso2wsas</property>
      <property name="org.wso2.ws.dataservice.password">wso2wsas</property>
   </config>

   <operation name="customerOrders">
      <call-query href="customerOrdersSQL" />
   </operation>

   <query id="customerOrdersSQL">
      <sql>select o.ORDERNUMBER,o.ORDERDATE, o.STATUS,o.CUSTOMERNUMBER from WSO2WSAS.ORDERS o</sql>

      <result element="Orders" rowName="Order">
         <element name="Order-number" column="ORDERNUMBER" />
         <element name="Last-name" column="ORDERDATE" />
         <element name="First-name" column="STATUS" />
         <call-query href="customerNameSQL">
            <with-param name="customerNumber" query-param="customerNumber" />
         </call-query>
      </result>
   </query>

   <operation name="customerName">
      <call-query href="customerNameSQL">
         <with-param name="customerNumber" query-param="customerNumber" />
      </call-query>
   </operation>

   <query id="customerNameSQL">
      <sql>select c.CUSTOMERNAME from WSO2WSAS.CUSTOMERS c where c.CUSTOMERNUMBER = ?</sql>
      <result element="Customers" rowName="Customer">
         <element name="Name" column="CUSTOMERNAME" />
      </result>
      <param name="customerNumber" sqlType="INTEGER" />
   </query>
</data>


TEXT1;
        }
  }
?>
