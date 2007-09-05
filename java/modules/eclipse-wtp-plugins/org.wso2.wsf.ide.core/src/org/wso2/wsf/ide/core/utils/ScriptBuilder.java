/*
 * Copyright 2005,2006 WSO2, Inc. http://www.wso2.org
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
package org.wso2.wsf.ide.core.utils;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;

import javax.xml.transform.Result;
import javax.xml.transform.Source;
import javax.xml.transform.SourceLocator;
import javax.xml.transform.Templates;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerConfigurationException;
import javax.xml.transform.TransformerException;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.stream.StreamResult;
import javax.xml.transform.stream.StreamSource;

public class ScriptBuilder {
	
	/**
	 * This method applies the xslFilename to inFilename and writes
	 * the output to outFilename.
	 * @param inFilename
	 * @param outFilename
	 * @param xslFilename
	 */
    public void parseXMLFile(String inFilename, String outFilename, String xslFilename) {
        try {
        	parseXMLFile(new FileInputStream(inFilename),
                         new FileOutputStream(outFilename), new FileInputStream(xslFilename));
        } catch (FileNotFoundException e) {
        	e.printStackTrace();
        } 
    }
   
    /**
     * This method applies the xslFileStream to inFileStream and writes
     * the output to outFilename.
     * @param inStream
     * @param outStream
     * @param xslStream
     */
    public void parseXMLFile(InputStream inStream, OutputStream outStream, 
    		InputStream xslStream) {
        try {
            // Create transformer factory
            TransformerFactory factory = TransformerFactory.newInstance();
            // Use the factory to create a template containing the xsl file
            Templates template = factory.newTemplates(new StreamSource(xslStream));
            // Use the template to create a transformer
            Transformer xformer = template.newTransformer();
            // Prepare the input and output files
            Source source = new StreamSource(inStream);
            Result result = new StreamResult(outStream);
            // Apply the xsl file to the source file and write the result to the output file
            xformer.transform(source, result);
        } catch (TransformerConfigurationException e) {
            e.printStackTrace();
        } catch (TransformerException e) {
            SourceLocator locator = e.getLocator();
            System.out.println("An error occurred while applying the XSL file : \n" +
            		"location column : "+locator.getColumnNumber()+"\n"+
            		"line : "+locator.getLineNumber()+"\n"+
            		"publicId : "+locator.getPublicId()+"\n"+
            		"systemId: "+locator.getSystemId()+"\n");
            e.printStackTrace();
        }
    }
}