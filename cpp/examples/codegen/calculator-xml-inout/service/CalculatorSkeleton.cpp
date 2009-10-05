

    /**
     * CalculatorSkeleton.cpp
     *
     * This file was Auto-Generated from WSDL for "Calculator|http://localhost/axis/Calculator" service
     * by the WSO2 WSF/CPP version:
     * CalculatorSkeleton WSF/CPP Skeleton For the Service
     */

     #include "CalculatorSkeleton.h"
	 #include <typeinfo>

    
    using namespace localhost_axis_calculator;


		 
        /**
         * Auto generated function definition signature
         * for "mul|http://localhost/axis/Calculator" operation.
         * 
         * @param _mul of the wso2wsf::OMElement*
         *
         * @return wso2wsf::OMElement*
         */
        wso2wsf::OMElement* CalculatorSkeleton::mul(wso2wsf::MessageContext *outCtx ,wso2wsf::OMElement* _mul)

        {
          /* TODO fill this with the necessary business logic */
          return (wso2wsf::OMElement*)NULL;
        }
     

		 
        /**
         * Auto generated function definition signature
         * for "div|http://localhost/axis/Calculator" operation.
         * 
         * @param _div of the wso2wsf::OMElement*
         *
         * @return wso2wsf::OMElement*
         */
        wso2wsf::OMElement* CalculatorSkeleton::div(wso2wsf::MessageContext *outCtx ,wso2wsf::OMElement* _div)

        {
          /* TODO fill this with the necessary business logic */
          return (wso2wsf::OMElement*)NULL;
        }
     

		 
        /**
         * Auto generated function definition signature
         * for "sub|http://localhost/axis/Calculator" operation.
         * 
         * @param _sub of the wso2wsf::OMElement*
         *
         * @return wso2wsf::OMElement*
         */
        wso2wsf::OMElement* CalculatorSkeleton::sub(wso2wsf::MessageContext *outCtx ,wso2wsf::OMElement* _sub)

        {
          /* TODO fill this with the necessary business logic */
          return (wso2wsf::OMElement*)NULL;
        }
     

		 
        /**
         * Auto generated function definition signature
         * for "add|http://localhost/axis/Calculator" operation.
         * 
         * @param _add of the wso2wsf::OMElement*
         *
         * @return wso2wsf::OMElement*
         */
        wso2wsf::OMElement* CalculatorSkeleton::add(wso2wsf::MessageContext *outCtx ,wso2wsf::OMElement* _add)

        {

			wso2wsf::OMElement *value1 = NULL;
			wso2wsf::OMElement *value2 = NULL;
			try{
				 value1 = dynamic_cast<wso2wsf::OMElement*>(_add->getFirstChild());
			
				 value2 =  dynamic_cast<wso2wsf::OMElement*>(value1->getNextSibling());
			}catch(std::bad_cast){
				std::cout<<"Caught Bad Cast"<<std::endl;
			}
			std::string param1 = value1->getText();
			int add_param1 = atoi(param1.c_str());
			std::string param2 = value2->getText();
			int add_param2 = atoi(param2.c_str());
			int result = add_param1 + add_param2;
			char result_str[50];
			sprintf(result_str, "%d", result);
			wso2wsf::OMElement *response = new wso2wsf::OMElement("addResponse");
			wso2wsf::OMElement *returnVal = new wso2wsf::OMElement(response, "addReturn");
			returnVal->setText(result_str);
			return response;
        }
     

