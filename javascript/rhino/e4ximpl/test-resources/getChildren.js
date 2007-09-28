/*
 * Copyright 2007 WSO2, Inc. http://www.wso2.org
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

var xml = <connector xmlns="http://geronimo.apache.org/xml/ns/j2ee/connector-1.1">
    <dep:environment xmlns:dep="http://geronimo.apache.org/xml/ns/deployment-1.1">
        <dep:moduleId>
            <dep:groupId>tungsten</dep:groupId>
            <dep:artifactId>tungsten_db</dep:artifactId>
            <dep:version>1.0</dep:version>
            <dep:type>rar</dep:type>
        </dep:moduleId>
        <dep:dependencies>
            <dep:dependency>
                <dep:groupId>org.apache.derby</dep:groupId>
                <dep:artifactId>derby</dep:artifactId>
                <dep:version>10.1.1.0</dep:version>
                <dep:type>jar</dep:type>
            </dep:dependency>
        </dep:dependencies>
    </dep:environment>
    <resourceadapter>
        <outbound-resourceadapter>
            <connection-definition>
                <connectionfactory-interface>javax.sql.DataSource</connectionfactory-interface>
                <connectiondefinition-instance>
                    <name>tungsten_db</name>
                    <config-property-setting name="Password">tungsten</config-property-setting>
                    <config-property-setting name="Driver">org.apache.derby.jdbc.EmbeddedDriver</config-property-setting>
                    <config-property-setting name="UserName">tungsten</config-property-setting>
                    <config-property-setting name="ConnectionURL">jdbc:derby:@tungsten_home@/database/TUNGSTEN_DB</config-property-setting>
                    <connectionmanager>
                        <local-transaction/>
                        <single-pool>
                            <max-size>50</max-size>
                            <min-size>1</min-size>
                            <match-one/>
                        </single-pool>
                    </connectionmanager>
                </connectiondefinition-instance>
            </connection-definition>
        </outbound-resourceadapter>
    </resourceadapter>
</connector>;