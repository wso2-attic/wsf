/*
 * Copyright 2008 WSO2, Inc. http://www.wso2.org
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

package org.wso2.wsf.jython.messagereceiver;

import org.apache.axis2.AxisFault;
import org.apache.axis2.databinding.utils.ConverterUtil;
import org.apache.axis2.databinding.types.NonPositiveInteger;
import org.apache.axis2.databinding.types.NonNegativeInteger;
import org.apache.axis2.databinding.types.PositiveInteger;
import org.apache.axis2.databinding.types.NegativeInteger;
import org.python.core.PyInteger;

/**
 * Converts Python Objects to java Objects.
 */
public class PyToOMConverter {
    /**
     * Converts a given python Object to String. 
     * 
     * @param pyObject python Object.
     * @return returns a String. 
     */
    public static String convertToString(Object pyObject) {
        return pyObject.toString();
    }

    /**
     * Converts a given python Object to Float.
     * 
     * @param pyObject python Object.
     * @return returns a String. 
     * @throws org.apache.axis2.AxisFault AxisFault
     */
    public static String convertToFloat(Object pyObject) throws AxisFault {
        try {
            Float floatObject = (Float) pyObject;
            return ConverterUtil.convertToString(floatObject);
        } catch (Exception e) {
            throw new AxisFault("Unable to convert the return value to float");
        }
    }

    /**
     * Converts a given python Object to Integer.
     *
     * @param pyObject python Object.
     * @return returns a String. 
     * @throws org.apache.axis2.AxisFault AxisFault
     */
    public static String convertToInteger(Object pyObject) throws AxisFault {
        try {
            Integer integer = (Integer) pyObject;
            return ConverterUtil.convertToString(integer);
        } catch (Exception e) {
            throw new AxisFault("Unable to convert the return value to integer");
        }
    }

    /**
     * Converts a given python Object to Int.
     *
     * @param pyObject python Object.
     * @return returns a String. 
     * @throws org.apache.axis2.AxisFault AxisFault
     */
    public static String convertToInt(Object pyObject) throws AxisFault {
        try {
            Integer integer;
            if (pyObject instanceof PyInteger) {
                integer = (Integer) ((PyInteger)pyObject).__tojava__(Integer.class);
            } else {
                integer = (Integer) pyObject;
            }
            return ConverterUtil.convertToString(integer);
        } catch (Exception e) {
            throw new AxisFault("Unable to convert the return value to int");
        }
    }

    /**
     * Converts a given python Object to NonPositiveInteger.
     *
     * @param pyObject python Object.
     * @return returns a String. 
     * @throws org.apache.axis2.AxisFault AxisFault
     */
    public static String convertToNonPositiveInteger(Object pyObject) throws AxisFault {
        try {
            NonPositiveInteger integer =
                    ConverterUtil.convertToNonPositiveInteger(pyObject.toString());
            return integer.toString();
        } catch (Exception e) {
            throw new AxisFault("Unable to convert the return value to non positive integer");
        }
    }

    /**
     * Converts a given python Object to NonNegativeInteger.
     *
     * @param pyObject python Object.
     * @return returns a String. 
     * @throws org.apache.axis2.AxisFault AxisFault
     */
    public static String convertToNonNegativeInteger(Object pyObject) throws AxisFault {
        try {
            NonNegativeInteger integer =
                    ConverterUtil.convertToNonNegativeInteger(pyObject.toString());
            return integer.toString();
        } catch (Exception e) {
            throw new AxisFault("Unable to convert the return value to non negative integer");
        }
    }

    /**
     * Converts a given python Object to PositiveInteger.
     *
     * @param pyObject python Object.
     * @return returns a String. 
     * @throws org.apache.axis2.AxisFault AxisFault
     */
    public static String convertToPositiveInteger(Object pyObject) throws AxisFault {
        try {
            PositiveInteger integer = ConverterUtil.convertToPositiveInteger(pyObject.toString());
            return integer.toString();
        } catch (Exception e) {
            throw new AxisFault("Unable to convert the return value to positive integer");
        }
    }

    /**
     * Converts a given python Object to NegativeInteger.
     *
     * @param pyObject python Object.
     * @return returns a String. 
     * @throws org.apache.axis2.AxisFault AxisFault
     */
    public static String convertToNegativeInteger(Object pyObject) throws AxisFault {
        try {
            NegativeInteger integer = ConverterUtil.convertToNegativeInteger(pyObject.toString());
            return integer.toString();
        } catch (Exception e) {
            throw new AxisFault("Unable to convert the return value to negative integer");
        }
    }

    /**
     * Converts a given python Object to Long.
     *
     * @param pyObject python Object.
     * @return returns a String. 
     * @throws org.apache.axis2.AxisFault AxisFault
     */
    public static String convertToLong(Object pyObject) throws AxisFault {
        try {
            Long longvalue = (Long) pyObject;
            return ConverterUtil.convertToString(longvalue);
        } catch (Exception e) {
            throw new AxisFault("Unable to convert the return value to long");
        }
    }

}
