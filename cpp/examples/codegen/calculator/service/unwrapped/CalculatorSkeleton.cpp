

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
         * @param _a of the int
         * @param _b of the int
         *
         * @return int
         */
        int CalculatorSkeleton::mul(wso2wsf::MessageContext *outCtx ,int _a,int _b)

        {
			return _a*_b;
		}
     

		 
        /**
         * Auto generated function definition signature
         * for "div|http://localhost/axis/Calculator" operation.
         * 
         * @param _a0 of the int
         * @param _b1 of the int
         *
         * @return int
         */
        int CalculatorSkeleton::div(wso2wsf::MessageContext *outCtx ,int _a0,int _b1)

        {
			if(_a0 != 0)
			{
				return _a0/_b1;
			}
			else
			{
				std::cout<<"Cannot divide by zero";
				return 0;
			}
		}
     

		 
        /**
         * Auto generated function definition signature
         * for "sub|http://localhost/axis/Calculator" operation.
         * 
         * @param _a2 of the int
         * @param _b3 of the int
         *
         * @return int
         */
        int CalculatorSkeleton::sub(wso2wsf::MessageContext *outCtx ,int _a2,int _b3)

        {
			return _a2 - _b3;
		}
     

		 
        /**
         * Auto generated function definition signature
         * for "add|http://localhost/axis/Calculator" operation.
         * 
         * @param _a4 of the int
         * @param _b5 of the int
         *
         * @return int
         */
        int CalculatorSkeleton::add(wso2wsf::MessageContext *outCtx ,int _a4,int _b5)

        {
			return _a4 + _b5;
        }
     

