27th August 2008

WSO2 Web Services Framework for Spring 1.5
-------------------------------------------

Building with the binary distribution
-------------------------------------

Please follow instructions in the INSTALL file.


Building the source distribution
--------------------------------

NOTE: JDK 1.5 and Maven 2 is required to build the source.

1.type “mvn clean install” in the base directory (where the source was downloaded to)
2.If, the build fails due to a missing artifact build again by typing “mvn clean install -up”
3.A WAR will be created at BASEDIR/modules/webapp/target/ (An exploded version of the WAR will be located at the same location)
4.Drop the WAR into a servlet container (ex:- Apache-Tomcat 5.5)

Support
-------

Issues can be reported using the public JIRA available at http://wso2.org/jira/browse/WSFSpring

Contact us
----------

WSO2 WSAS developers can be contacted via mailing lists: 

For Users: wsf-spring-dev@wso2.org 
For Developers:wsf-spring-user@wso2.org

For details on subscriptions see wsf-spring-dev-request@wso2.org

Alternatively, questions can also be raised in the forums: http://wso2.org/forum/194
Thank you for your interest in WSO2 WSF/Spring
- The WSO2 WSF/Spring Development Team
