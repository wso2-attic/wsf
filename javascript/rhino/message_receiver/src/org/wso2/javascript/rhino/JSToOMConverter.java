/*
 * Copyright 2006,2007 WSO2, Inc. http://www.wso2.org
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
package org.wso2.javascript.rhino;

import org.apache.axiom.om.OMElement;
import org.apache.axis2.AxisFault;
import org.apache.axis2.databinding.types.Day;
import org.apache.axis2.databinding.types.Duration;
import org.apache.axis2.databinding.types.Language;
import org.apache.axis2.databinding.types.Month;
import org.apache.axis2.databinding.types.MonthDay;
import org.apache.axis2.databinding.types.NCName;
import org.apache.axis2.databinding.types.Name;
import org.apache.axis2.databinding.types.NegativeInteger;
import org.apache.axis2.databinding.types.NonNegativeInteger;
import org.apache.axis2.databinding.types.NonPositiveInteger;
import org.apache.axis2.databinding.types.NormalizedString;
import org.apache.axis2.databinding.types.Notation;
import org.apache.axis2.databinding.types.PositiveInteger;
import org.apache.axis2.databinding.types.Time;
import org.apache.axis2.databinding.types.Token;
import org.apache.axis2.databinding.types.UnsignedByte;
import org.apache.axis2.databinding.types.UnsignedInt;
import org.apache.axis2.databinding.types.UnsignedLong;
import org.apache.axis2.databinding.types.UnsignedShort;
import org.apache.axis2.databinding.types.Year;
import org.apache.axis2.databinding.types.YearMonth;
import org.apache.axis2.databinding.utils.BeanUtil;
import org.apache.axis2.databinding.utils.ConverterUtil;
import org.mozilla.javascript.Context;
import org.mozilla.javascript.EvaluatorException;
import org.mozilla.javascript.NativeArray;
import org.wso2.javascript.xmlimpl.QName;

import java.math.BigDecimal;
import java.util.Calendar;
import java.util.Date;
import java.util.TimeZone;

public class JSToOMConverter {

    public static String convertToString(Object jsObject) {
        if (jsObject instanceof NativeArray) {
            NativeArray nativeArray = (NativeArray) jsObject;
            Object[] objects = nativeArray.getAllIds();
            String returnString = "";
            // Using a flag here to know weather the iterator is in the first position cause we
            // want to separate the values in the array using a ,
            boolean first = true;
            for (int i = 0; i < objects.length; i++) {
                Object object = objects[i];
                Object value;
                if (object instanceof String) {
                    String property = (String) object;
                    if ("length".equals(property)) {
                        continue;
                    }
                    value = nativeArray.get(property, nativeArray);
                } else {
                    Integer property = (Integer) object;
                    value = nativeArray.get(property.intValue(), nativeArray);
                }
                if (first) {
                    returnString += value;
                    first = false;
                } else {
                    returnString += ", " + value;
                }
            }
            return returnString;
        }
        return jsObject.toString();
    }

    public static String convertToFloat(Object jsObject) throws AxisFault {
        try {
            Float floatObject = (Float) jsObject;
            return ConverterUtil.convertToString(floatObject);
        } catch (Exception e) {
            throw new AxisFault("Unable to convert the return value to float");
        }
    }

    public static String convertToDouble(Object jsObject) throws AxisFault {
        try {
            String str = jsObject.toString();
            if (str.indexOf("Infinity") >= 0) {
                str = str.replace("Infinity", "INF");
            }
            return str;
        } catch (Exception e) {
            throw new AxisFault("Unable to convert the return value to double");
        }
    }

    public static String convertToInteger(Object jsObject) throws AxisFault {
        try {
            Integer integer = (Integer) jsObject;
            return ConverterUtil.convertToString(integer);
        } catch (Exception e) {
            throw new AxisFault("Unable to convert the return value to integer");
        }
    }

    public static String convertToInt(Object jsObject) throws AxisFault {
        try {
            Integer integer = (Integer) jsObject;
            return ConverterUtil.convertToString(integer);
        } catch (Exception e) {
            throw new AxisFault("Unable to convert the return value to int");
        }
    }

    public static String convertToNonPositiveInteger(Object jsObject) throws AxisFault {
        try {
            NonPositiveInteger integer =
                    ConverterUtil.convertToNonPositiveInteger(jsObject.toString());
            return integer.toString();
        } catch (Exception e) {
            throw new AxisFault("Unable to convert the return value to non positive integer");
        }
    }

    public static String convertToNonNegativeInteger(Object jsObject) throws AxisFault {
        try {
            NonNegativeInteger integer =
                    ConverterUtil.convertToNonNegativeInteger(jsObject.toString());
            return integer.toString();
        } catch (Exception e) {
            throw new AxisFault("Unable to convert the return value to non negative integer");
        }
    }

    public static String convertToPositiveInteger(Object jsObject) throws AxisFault {
        try {
            PositiveInteger integer = ConverterUtil.convertToPositiveInteger(jsObject.toString());
            return integer.toString();
        } catch (Exception e) {
            throw new AxisFault("Unable to convert the return value to positive integer");
        }
    }

    public static String convertToNegativeInteger(Object jsObject) throws AxisFault {
        try {
            NegativeInteger integer = ConverterUtil.convertToNegativeInteger(jsObject.toString());
            return integer.toString();
        } catch (Exception e) {
            throw new AxisFault("Unable to convert the return value to negative integer");
        }
    }

    public static String convertToLong(Object jsObject) throws AxisFault {
        try {
            Long longvalue = (Long) jsObject;
            return ConverterUtil.convertToString(longvalue);
        } catch (Exception e) {
            throw new AxisFault("Unable to convert the return value to long");
        }
    }

    public static String convertToShort(Object jsObject) throws AxisFault {
        try {
            Short shortvalue = (Short) jsObject;
            return ConverterUtil.convertToString(shortvalue);
        } catch (Exception e) {
            throw new AxisFault("Unable to convert the return value to short");
        }
    }

    public static String convertToByte(Object jsObject) throws AxisFault {
        try {
            Byte bytevalue = (Byte) jsObject;
            return ConverterUtil.convertToString(bytevalue);
        } catch (Exception e) {
            throw new AxisFault("Unable to convert the return value to byte");
        }
    }

    public static String convertToUnsignedLong(Object jsObject) throws AxisFault {
        try {
            UnsignedLong unsignedLong = (UnsignedLong) jsObject;
            return ConverterUtil.convertToString(unsignedLong);
        } catch (Exception e) {
            throw new AxisFault("Unable to convert the return value to unsigned long");
        }
    }

    public static String convertToUnsignedInt(Object jsObject) throws AxisFault {
        try {
            UnsignedInt unsignedInt = (UnsignedInt) jsObject;
            return ConverterUtil.convertToString(unsignedInt);
        } catch (Exception e) {
            throw new AxisFault("Unable to convert the return value to unsigned int");
        }
    }

    public static String convertToUnsignedShort(Object jsObject) throws AxisFault {
        try {
            UnsignedShort unsignedShort = (UnsignedShort) jsObject;
            return ConverterUtil.convertToString(unsignedShort);
        } catch (Exception e) {
            throw new AxisFault("Unable to convert the return value to unsigned short");
        }
    }

    public static String convertToUnsignedByte(Object jsObject) throws AxisFault {
        try {
            UnsignedByte unsignedByte = (UnsignedByte) jsObject;
            return ConverterUtil.convertToString(unsignedByte);
        } catch (Exception e) {
            throw new AxisFault("Unable to convert the return value to unsigned byte");
        }
    }

    public static String convertToDecimal(Object jsObject) throws AxisFault {
        try {
            BigDecimal bigDecimal = (BigDecimal) jsObject;
            return ConverterUtil.convertToString(bigDecimal);
        } catch (Exception e) {
            throw new AxisFault("Unable to convert the return value to decimal");
        }
    }

    public static String convertToBoolean(Object jsObject) throws AxisFault {
        try {
            Boolean booleanValue = (Boolean) jsObject;
            return ConverterUtil.convertToString(booleanValue);
        } catch (Exception e) {
            throw new AxisFault("Unable to convert the return value to boolean");
        }
    }

    public static String convertToDateTime(Object jsObject) throws AxisFault {
        try {

            // If the user returned a valid date a s a String we use the converterUtil to validate
            // it and return it back.
            if (jsObject instanceof String) {
                Calendar calendar = ConverterUtil.convertToDateTime((String)jsObject);
                return ConverterUtil.convertToString(calendar);
            }
            Date date = (Date) Context.jsToJava(jsObject, Date.class);
            Calendar calendar = Calendar.getInstance();
            calendar.clear();
            calendar.setTime(date);
            return ConverterUtil.convertToString(calendar);
        } catch (EvaluatorException e) {
            throw new AxisFault("Unable to convert the return value to date");
        }
    }

    public static String convertToDate(Object jsObject) throws AxisFault {
        try {
            // If the user returned a date date a s a String we use the converterUtil to validate
            // it and return it back.
            if (jsObject instanceof String) {
                Date date = ConverterUtil.convertToDate((String)jsObject);
                return ConverterUtil.convertToString(date);
            }
            Date date = (Date) Context.jsToJava(jsObject, Date.class);
            return ConverterUtil.convertToString(date);
        } catch (EvaluatorException e) {
            throw new AxisFault("Unable to convert the return value to date");
        }
    }

    public static String convertToTime(Object jsObject) throws AxisFault {
        try {
            // If the user returned a valid time a s a String we use the converterUtil to validate
            // it and return it back.
            if (jsObject instanceof String) {
                Time time = ConverterUtil.convertToTime((String)jsObject);
                return ConverterUtil.convertToString(time);
            }
            Date date = (Date) Context.jsToJava(jsObject, Date.class);
            Calendar calendar = Calendar.getInstance();
            calendar.clear();
            calendar.setTime(date);
            Time time = new Time(calendar);
            return ConverterUtil.convertToString(time);
        } catch (EvaluatorException e) {
            throw new AxisFault("Unable to convert the return value to time");
        }
    }

    public static String convertToGYearMonth(Object jsObject) throws AxisFault {
        try {
            // If the user returned a valid GYearMonth a s a String we use the converterUtil to
            // validate it and return it back.
            if (jsObject instanceof String) {
                YearMonth yearMonth = ConverterUtil.convertToGYearMonth((String)jsObject);
                return ConverterUtil.convertToString(yearMonth);
            }
            Date date = (Date) Context.jsToJava(jsObject, Date.class);
            Calendar calendar = Calendar.getInstance();
            calendar.clear();
            calendar.setTime(date);
            YearMonth yearMonth =
                    new YearMonth(calendar.get(Calendar.YEAR), calendar.get(Calendar.MONTH));
            return ConverterUtil.convertToString(yearMonth);
        } catch (EvaluatorException e) {
            throw new AxisFault("Unable to convert the return value to yearMonth");
        } catch (NumberFormatException e) {
            throw new AxisFault("Unable to convert the return value to yearMonth");
        }
    }

    public static String convertToGMonthDay(Object jsObject) throws AxisFault {
        try {
            // If the user returned a valid GMonthDay a s a String we use the converterUtil to
            // validate it and return it back.
            if (jsObject instanceof String) {
                MonthDay monthDay = ConverterUtil.convertToGMonthDay((String)jsObject);
                return ConverterUtil.convertToString(monthDay);
            }
            Date date = (Date) Context.jsToJava(jsObject, Date.class);
            Calendar calendar = Calendar.getInstance();
            calendar.clear();
            calendar.setTime(date);
            MonthDay monthDay =
                    new MonthDay(calendar.get(Calendar.MONTH), calendar.get(Calendar.DAY_OF_MONTH));
            return ConverterUtil.convertToString(monthDay);
        } catch (EvaluatorException e) {
            throw new AxisFault("Unable to convert the return value to monthDay");
        } catch (NumberFormatException e) {
            throw new AxisFault("Unable to convert the return value to monthDay");
        }
    }

    public static String convertToGYear(Object jsObject) throws AxisFault {
        try {
            // If the user returned a valid GYear a s a String we use the converterUtil to
            // validate it and return it back.
            if (jsObject instanceof String) {
                Year year = ConverterUtil.convertToGYear((String)jsObject);
                return ConverterUtil.convertToString(year);
            }
            Date date = (Date) Context.jsToJava(jsObject, Date.class);
            Calendar calendar = Calendar.getInstance();
            calendar.clear();
            calendar.setTime(date);
            Year year = new Year(calendar.get(Calendar.YEAR));
            return ConverterUtil.convertToString(year);
        } catch (EvaluatorException e) {
            throw new AxisFault("Unable to convert the return value to year");
        } catch (NumberFormatException e) {
            throw new AxisFault("Unable to convert the return value to day");
        }
    }

    public static String convertToGDay(Object jsObject) throws AxisFault {
        try {
            // If the user returned a valid GDay a s a String we use the converterUtil to
            // validate it and return it back.
            if (jsObject instanceof String) {
                Day day = ConverterUtil.convertToGDay((String)jsObject);
                return ConverterUtil.convertToString(day);
            }
            Date date = (Date) Context.jsToJava(jsObject, Date.class);
            Calendar calendar = Calendar.getInstance();
            calendar.clear();
            calendar.setTime(date);
            Day day = new Day(calendar.get(Calendar.DAY_OF_MONTH));
            return ConverterUtil.convertToString(day);
        } catch (EvaluatorException e) {
            throw new AxisFault("Unable to convert the return value to day");
        } catch (NumberFormatException e) {
            throw new AxisFault("Unable to convert the return value to day");
        }
    }

    public static String convertToDuration(Object jsObject) throws AxisFault {
        try {
            String str = (String) jsObject;
            Duration duration = ConverterUtil.convertToDuration(str);
            return ConverterUtil.convertToString(duration);
        } catch (Exception e) {
            throw new AxisFault("Unable to convert the return value to duration");
        }
    }

    public static String convertToGMonth(Object jsObject) throws AxisFault {
        try {
            // If the user returned a valid GMonth a s a String we use the converterUtil to
            // validate it and return it back.
            if (jsObject instanceof String) {
                Month month = ConverterUtil.convertToGMonth((String)jsObject);
                return ConverterUtil.convertToString(month);
            }
            Date date = (Date) Context.jsToJava(jsObject, Date.class);
            Calendar calendar = Calendar.getInstance();
            calendar.clear();
            calendar.setTime(date);
            Month month = new Month(calendar.get(Calendar.MONTH));
            return ConverterUtil.convertToString(month);
        } catch (EvaluatorException e) {
            throw new AxisFault("Unable to convert the return value to month");
        } catch (NumberFormatException e) {
            throw new AxisFault("Unable to convert the return value to month");
        }
    }

    public static String convertToNormalizedString(Object jsObject) throws AxisFault {
        try {
            String str = (String) jsObject;
            return new NormalizedString(str).toString();
        } catch (IllegalArgumentException e) {
            throw new AxisFault("Unable to convert the return value to normalized string");
        }
    }

    public static String convertToToken(Object jsObject) throws AxisFault {
        try {
            String str = (String) jsObject;
            return new Token(str).toString();
        } catch (IllegalArgumentException e) {
            throw new AxisFault("Unable to convert the return value to token");
        }
    }

    public static String convertToLanguage(Object jsObject) throws AxisFault {
        try {
            String str = (String) jsObject;
            return new Language(str).toString();
        } catch (IllegalArgumentException e) {
            throw new AxisFault("Unable to convert the return value to language");
        }
    }

    public static String convertToName(Object jsObject) throws AxisFault {
        try {
            String str = (String) jsObject;
            return new Name(str).toString();
        } catch (IllegalArgumentException e) {
            throw new AxisFault("Unable to convert the return value to name");
        }
    }

    public static String convertToNCName(Object jsObject) throws AxisFault {
        try {
            String str = (String) jsObject;
            return new NCName(str).toString();
        } catch (IllegalArgumentException e) {
            throw new AxisFault("Unable to convert the return value to NCName");
        }
    }

    public static String convertToNOTATION(Object jsObject) throws AxisFault {
        try {
            String str = (String) jsObject;
            Notation notation = new Notation();
            notation.setName(new NCName(str));
            return notation.toString();
        } catch (IllegalArgumentException e) {
            throw new AxisFault("Unable to convert the return value to NOTATION");
        }
    }

    public static String convertToAnyURI(Object jsObject) throws AxisFault {
        try {
            String str = (String) jsObject;
            return ConverterUtil.convertToAnyURI(str).toString();
        } catch (Exception e) {
            throw new AxisFault("Unable to convert the return value to anyURI");
        }
    }

    public static String convertToQName(Object jsObject, OMElement omElement) throws AxisFault {
        try {
            QName qName = (QName)jsObject;
            Object uri = qName.get("uri", qName);
            Object localName = qName.get("localName", qName);
            String prefixString, localNameString;
            if (!JavaScriptEngine.isNull(uri) && !"".equals(uri)) {
                prefixString = BeanUtil.getUniquePrefix();
                omElement.declareNamespace(((String)uri), prefixString);
                localNameString = prefixString + ":" + localName;
            } else {
                localNameString = (String) localName;
            }

            return localNameString;
        } catch (Exception e) {
            throw new AxisFault("Unable to convert the return value to QName");
        }
    }

    public static String convertToHexBinary(Object jsObject) throws AxisFault {
        try {
            String str = (String) jsObject;
            return ConverterUtil.convertToHexBinary(str).toString();
        } catch (Exception e) {
            throw new AxisFault("Unable to convert the return value to hexBinary");
        }
    }

    public static String convertToBase64Binary(Object jsObject) throws AxisFault {
        try {
            return (String) jsObject;
        } catch (Exception e) {
            throw new AxisFault("Unable to convert the return value to base64Binary");
        }
    }
}
