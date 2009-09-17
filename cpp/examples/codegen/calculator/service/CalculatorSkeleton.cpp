

    /**
     * CalculatorSkeleton.cpp
     *
     * This file was Auto-Generated from WSDL for "Calculator|http://localhost/axis/Calculator" service
     * by the WSO2 WSF/CPP version:
     * CalculatorSkeleton WSF/CPP Skeleton For the Service
     */

     #include "CalculatorSkeleton.h"

    
     #include <Mul.h>
    
     #include <MulResponse.h>
    
     #include <Div.h>
    
     #include <DivResponse.h>
    
     #include <Sub.h>
    
     #include <SubResponse.h>
    
     #include <Add.h>
    
     #include <AddResponse.h>
    
    using namespace localhost_axis_calculator;
		 
        /**
         * Auto generated function definition signature
         * for "mul|http://localhost/axis/Calculator" operation.
         * 
         * @param _mul of the localhost_axis_calculator::Mul
         *
         * @return localhost_axis_calculator::MulResponse*
         */
        localhost_axis_calculator::MulResponse* CalculatorSkeleton::mul(wso2wsf::MessageContext *outCtx ,localhost_axis_calculator::Mul* _mul)

        {
			int value1 =0, value2 =0, result =0;
			value1 = _mul->getA();
			value2 = _mul->getB();
			result = value1*value2;
			localhost_axis_calculator::MulResponse *mulResponse = new localhost_axis_calculator::MulResponse();
			mulResponse->setMulReturn(result);
			return mulResponse;
		}
     

		 
        /**
         * Auto generated function definition signature
         * for "div|http://localhost/axis/Calculator" operation.
         * 
         * @param _div of the localhost_axis_calculator::Div
         *
         * @return localhost_axis_calculator::DivResponse*
         */
        localhost_axis_calculator::DivResponse* CalculatorSkeleton::div(wso2wsf::MessageContext *outCtx ,localhost_axis_calculator::Div* _div)

        {
			int value1 =0, value2 =0, result =0;
			value1 = _div->getA();
			value2 = _div->getB();
			if(value2 == 0)
			{
				std::cout<<"Cannot divide by Zero"<<std::endl;
				return NULL;
			}
			result = value1/value2;
			localhost_axis_calculator::DivResponse *divResponse = new localhost_axis_calculator::DivResponse();
			divResponse->setDivReturn(result);
	        return divResponse;
        }
     

		 
        /**
         * Auto generated function definition signature
         * for "sub|http://localhost/axis/Calculator" operation.
         * 
         * @param _sub of the localhost_axis_calculator::Sub
         *
         * @return localhost_axis_calculator::SubResponse*
         */
        localhost_axis_calculator::SubResponse* CalculatorSkeleton::sub(wso2wsf::MessageContext *outCtx ,localhost_axis_calculator::Sub* _sub)

        {
			int value1 =0, value2 = 0, result = 0;
			value1 = _sub->getA();
			value2 = _sub->getB();
			result = value1 - value2;
			localhost_axis_calculator::SubResponse *subResponse = new localhost_axis_calculator::SubResponse();
			subResponse->setSubReturn(result);
			return subResponse;
        }
     

		 
        /**
         * Auto generated function definition signature
         * for "add|http://localhost/axis/Calculator" operation.
         * 
         * @param _add of the localhost_axis_calculator::Add
         *
         * @return localhost_axis_calculator::AddResponse*
         */
        localhost_axis_calculator::AddResponse* CalculatorSkeleton::add(wso2wsf::MessageContext *outCtx ,localhost_axis_calculator::Add* _add)

        {
			int value1 = 0, value2=0, result = 0;
			value1 = _add->getA();
			value2 = _add->getB();
			result = value1 + value2;
			localhost_axis_calculator::AddResponse *addResponse = new localhost_axis_calculator::AddResponse();
			addResponse->setAddReturn(result);
			return addResponse;
		}
     

