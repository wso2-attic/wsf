package org.wso2.wsf.bpel.ide.utils;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;

import org.eclipse.core.internal.resources.Project;
import org.eclipse.core.resources.IProject;
import org.w3c.dom.Document;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

public class BpelUtils {
	public static boolean isProjectContainsBpel(IProject p){
		String prjPath = p.getLocation().toOSString();
		File prjFolder = new File(prjPath);
		String[] fileList = prjFolder.list();
		for (String filename : fileList) {
			if (filename.toLowerCase().endsWith(".bpel"))
				return true;
		}
		return false;
	}
	
	public static List getBpelValidFileList(String relativePath,String[] fileList){
		List list=new ArrayList();
		List existingWSDL=new ArrayList();
		List requiredWsdl=new ArrayList();
		for (int i = 0; i < fileList.length; i++) {
			String filename = fileList[i];
			File file = new File(filename);
			if (!file.isDirectory()){
				String extension=filename.substring(filename.length()-5).toLowerCase();
				if ((extension.endsWith(".bpel"))&&(isValidBPelFile(filename,requiredWsdl)))
					list.add(filename);
				else if ((extension.endsWith(".wsdl"))&&(isValidWSDLFile(filename)))
					existingWSDL.add(filename);
				else if ((extension.endsWith(".xml"))&&(isValidDeployFile(filename)))
					list.add(filename);
			}
		}
		if (!relativePath.endsWith(File.separator)) relativePath=FileManagementUtil.addAnotherNodeToPath(relativePath, "");
		int relativePathLength = relativePath.length();
		for (Iterator iterator = existingWSDL.iterator(); iterator.hasNext();) {
			String wsdlFileName = (String) iterator.next();
			String relativeFileName=wsdlFileName.substring(relativePathLength);
			if (requiredWsdl.contains(relativeFileName))
				list.add(wsdlFileName);
		}
		return list;
		
	}
	
	public static boolean isValidBPelFile(String filename,List wsdlList){
		Document xmlDocument = getXmlDocument(filename);
		if (xmlDocument==null)
			return false;
		else{
			if (xmlDocument.getDocumentElement().getNodeName().toLowerCase().endsWith(":process")){
				NodeList childNodes = xmlDocument.getDocumentElement().getChildNodes();
				for (int i = 0; i < childNodes.getLength(); i++) {
					Node item = childNodes.item(i);
					if (item.getNodeName().toLowerCase().endsWith(":import")){
						Node namedItem = item.getAttributes().getNamedItem("location");
						String nodeValue = namedItem.getNodeValue();
						wsdlList.add(nodeValue);
					}
					
				}
				return true;
			}else
				return false;
		}
	}
	
	
	
	public static boolean isValidDeployFile(String filename){
		Document xmlDocument = getXmlDocument(filename);
		if (xmlDocument==null)
			return false;
		else
			return xmlDocument.getDocumentElement().getNodeName().equalsIgnoreCase("deploy");

	}
	
	private static Document getXmlDocument(String filename){
		DocumentBuilderFactory docBuilderFactory = DocumentBuilderFactory.newInstance();
		DocumentBuilder docBuilder;
		try {
			docBuilder = docBuilderFactory.newDocumentBuilder();
			Document doc = docBuilder.parse (new File(filename));
			return doc;
		} catch (ParserConfigurationException e) {
			return null;
		} catch (SAXException e) {
			return null;
		} catch (IOException e) {
			return null;
		}
	}
	
	public static boolean isValidWSDLFile(String filename){
		return true;
	}
}
