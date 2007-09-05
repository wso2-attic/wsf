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
package org.wso2.wsf.ide.wtp.ext.dumpaar.script;

import java.io.File;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.Result;
import javax.xml.transform.Source;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerException;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;

import org.eclipse.core.runtime.IPath;
import org.eclipse.core.runtime.Path;
import org.w3c.dom.DOMException;
import org.w3c.dom.Document;
import org.w3c.dom.Element;

public class AntMapBuilder {
	
	private IPath buildFileLocation;
	
	public boolean buildAntBuildMap(AntBuildDTO dto) {
		try {
			Document document = createDomDocument();
			// Insert the root element Map
			Element mapElement = document.createElement("Map");
			document.appendChild(mapElement);
			// Insert the entry elements
			mapElement.appendChild(getEntryElement(document, "serviceName", dto.getServiceName()));
			mapElement.appendChild(getEntryElement(document, "buildTarget", dto.getTargetPath()));
			//The output filename
			IPath outputLocation = new Path(dto.getTargetPath());
			outputLocation = outputLocation.removeLastSegments(1);
			outputLocation = outputLocation.append(dto.getServiceName());
			outputLocation = outputLocation.append(dto.getServiceName()+"DumpAARMap.xml");
			writeXmlFile(document, outputLocation.toOSString());
			setBuildFileLocation(outputLocation);
		} catch (DOMException e) {
			e.printStackTrace();
			return false;
		} catch (ParserConfigurationException e) {
			e.printStackTrace();
			return false;
		} catch (TransformerException e) {
			e.printStackTrace();
			return false;
		}
		return true ;
	}
	
    private Document createDomDocument() throws ParserConfigurationException {
            DocumentBuilder builder = DocumentBuilderFactory.newInstance().newDocumentBuilder();
            Document doc = builder.newDocument();
            return doc;
    }
    
    private Element getEntryElement(Document document, String key, String value){
        Element entryElement = document.createElement("Entry");
        entryElement.setAttribute("key", key);
        entryElement.setAttribute("value", value);
        return entryElement;
    }

    private static void writeXmlFile(Document doc, String filename) throws TransformerException {
            // Prepare the DOM document for writing
            Source source = new DOMSource(doc);
            // Prepare the output file
            File file = new File(filename);
            Result result = new StreamResult(file);
            // Write the DOM document to the file
            Transformer xformer = TransformerFactory.newInstance().newTransformer();
            xformer.transform(source, result);
    }

	public IPath getBuildFileLocation() {
		return buildFileLocation;
	}

	private void setBuildFileLocation(IPath buildFileLocation) {
		this.buildFileLocation = buildFileLocation;
	}
}
