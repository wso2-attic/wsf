

    /**
     * CalculatorSkeleton.cpp
     *
     * This file was Auto-Generated from WSDL for "Calculator|http://localhost/axis/Calculator" service
     * by the WSO2 WSF/CPP version:
     * CalculatorSkeleton WSF/CPP Skeleton For the Service
     */

     #include "CalculatorSkeleton.h"

    
     #include <Div.h>
    
     #include <DivResponse.h>
    
     #include <Add.h>
    
     #include <AddResponse.h>
    
     #include <Sub.h>
    
     #include <SubResponse.h>
    
     #include <Mul.h>
    
     #include <MulResponse.h>
    
    using namespace localhost_axis_calculator;


		 
        /**
         * Auto generated function definition signature
         * for "div|http://localhost/axis/Calculator" operation.
         * 
         * @param _div of the localhost_axis_calculator::Div
         *
         * @return localhost_axis_calculator::DivResponse*
         */
        localhost_axis_calculator::DivResponse* CalculatorSkeleton::div(localhost_axis_calculator::Div* _div)

        {
			localhost_axis_calculator::DivResponse *divRes = NULL;
			int val1 =0, val2 =0, retval =0;
			val1 = _div->getArg_0_3();
			val2 = _div->getArg_1_3();
			retval = val1/val2;
			divRes = new localhost_axis_calculator::DivResponse();
			divRes->setDivReturn(retval);
			return divRes;
        }
     

		 
        /**
         * Auto generated function definition signature
         * for "add|http://localhost/axis/Calculator" operation.
         * 
         * @param _add of the localhost_axis_calculator::Add
         *
         * @return localhost_axis_calculator::AddResponse*
         */
        localhost_axis_calculator::AddResponse* CalculatorSkeleton::add(localhost_axis_calculator::Add* _add)

        {
			localhost_axis_calculator::AddResponse *addRes = NULL;
			int val1 = 0, val2=0, retval = 0;
			val1 = _add->getArg_0_0();
			val2 = _add->getArg_1_0();
			retval = val1 + val2;
			addRes = new localhost_axis_calculator::AddResponse();
			addRes->setAddReturn(retval);
			return addRes;
        }
     

		 
        /**
         * Auto generated function definition signature
         * for "sub|http://localhost/axis/Calculator" operation.
         * 
         * @param _sub of the localhost_axis_calculator::Sub
         *
         * @return localhost_axis_calculator::SubResponse*
         */
        localhost_axis_calculator::SubResponse* CalculatorSkeleton::sub(localhost_axis_calculator::Sub* _sub)

        {
			localhost_axis_calculator::SubResponse *subRes = NULL;
			int val1 =0, val2 = 0, retval = 0;
			val1 = _sub->getArg_0_1();
			val2 = _sub->getArg_1_1();
			retval = val1 - val2;
			subRes = new localhost_axis_calculator::SubResponse();
			subRes->setSubReturn(retval);
			return subRes;
        }
     

		 
        /**
         * Auto generated function definition signature
         * for "mul|http://localhost/axis/Calculator" operation.
         * 
         * @param _mul of the localhost_axis_calculator::Mul
         *
         * @return localhost_axis_calculator::MulResponse*
         */
        localhost_axis_calculator::MulResponse* CalculatorSkeleton::mul(localhost_axis_calculator::Mul* _mul)

        {
			localhost_axis_calculator::MulResponse *mulRes = NULL;
			int val1 =0, val2 =0, retval =0;
			val1 = _mul->getArg_0_2();
			val2 = _mul->getArg_1_2();
			retval = val1+val2;
			mulRes = new localhost_axis_calculator::MulResponse();
			mulRes->setMulReturn(retval);
			return mulRes;
		}
     

