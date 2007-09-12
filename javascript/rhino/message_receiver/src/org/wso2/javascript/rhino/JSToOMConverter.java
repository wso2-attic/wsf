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

import org.apache.axis2.databinding.utils.ConverterUtil;
import org.apache.axis2.databinding.types.NonNegativeInteger;
import org.apache.axis2.databinding.types.NonPositiveInteger;
import org.apache.axis2.databinding.types.PositiveInteger;
import org.apache.axis2.databinding.types.NegativeInteger;
import org.apache.axis2.databinding.types.UnsignedLong;
import org.apache.axis2.databinding.types.UnsignedInt;
import org.apache.axis2.databinding.types.UnsignedShort;
import org.apache.axis2.databinding.types.UnsignedByte;
import org.apache.axis2.databinding.types.Time;
import org.apache.axis2.databinding.types.YearMonth;
import org.apache.axis2.databinding.types.MonthDay;
import org.apache.axis2.databinding.types.Year;
import org.apache.axis2.databinding.types.Day;
import org.apache.axis2.databinding.types.Month;
import org.apache.axis2.databinding.types.NormalizedString;
import org.apache.axis2.databinding.types.Token;
import org.apache.axis2.databinding.types.Language;
import org.apache.axis2.databinding.types.Name;
import org.apache.axis2.databinding.types.NCName;
import org.apache.axis2.databinding.types.Notation;
import org.apache.axis2.databinding.types.Duration;
import org.mozilla.javascript.Context;

import java.math.BigInteger;
import java.math.BigDecimal;
import java.util.Date;
import java.util.Calendar;

public class JSToOMConverter {

    public static String convertToString(Object jsObject) {
        return jsObject.toString();
    }

    public static String convertToFloat(Object jsObject) {
        Float floatObject = (Float) jsObject;
        return ConverterUtil.convertToString(floatObject);
    }

    public static String convertToDouble(Object jsObject) {
        Double doubleObject = (Double) jsObject;
        String str = ConverterUtil.convertToString(doubleObject);
        if (str.indexOf("Infinity") >= 0) {
            str = str.replace("Infinity", "INF");
        }
        return str;
    }

    public static String convertToInteger(Object jsObject) {
        BigInteger bigInteger = (BigInteger) jsObject;
        return ConverterUtil.convertToString(bigInteger);
    }

    public static String convertToInt(Object jsObject) {
        Integer integer = (Integer) jsObject;
        return ConverterUtil.convertToString(integer);
    }

    public static String convertToNonPositiveInteger(Object jsObject) {
        NonPositiveInteger integer = ConverterUtil.convertToNonPositiveInteger(jsObject.toString());
        return integer.toString();
    }

    public static String convertToNonNegativeInteger(Object jsObject) {
        NonNegativeInteger integer = ConverterUtil.convertToNonNegativeInteger(jsObject.toString());
        return integer.toString();
    }

    public static String convertToPositiveInteger(Object jsObject) {
        PositiveInteger integer = ConverterUtil.convertToPositiveInteger(jsObject.toString());
        return integer.toString();
    }

    public static String convertToNegativeInteger(Object jsObject) {
        NegativeInteger integer = ConverterUtil.convertToNegativeInteger(jsObject.toString());
        return integer.toString();
    }

    public static String convertToLong(Object jsObject) {
        Long longvalue = (Long) jsObject;
        return ConverterUtil.convertToString(longvalue);
    }

    public static String convertToShort(Object jsObject) {
        Short shortvalue = (Short) jsObject;
        return ConverterUtil.convertToString(shortvalue);
    }

    public static String convertToByte(Object jsObject) {
        Byte bytevalue = (Byte) jsObject;
        return ConverterUtil.convertToString(bytevalue);
    }

    public static String convertToUnsignedLong(Object jsObject) {
        UnsignedLong unsignedLong = (UnsignedLong) jsObject;
        return ConverterUtil.convertToString(unsignedLong);
    }

    public static String convertToUnsignedInt(Object jsObject) {
        UnsignedInt unsignedInt = (UnsignedInt) jsObject;
        return ConverterUtil.convertToString(unsignedInt);
    }

    public static String convertToUnsignedShort(Object jsObject) {
        UnsignedShort unsignedShort = (UnsignedShort) jsObject;
        return ConverterUtil.convertToString(unsignedShort);
    }

    public static String convertToUnsignedByte(Object jsObject) {
        UnsignedByte unsignedByte = (UnsignedByte) jsObject;
        return ConverterUtil.convertToString(unsignedByte);
    }

    public static String convertToDecimal(Object jsObject) {
        BigDecimal bigDecimal = (BigDecimal) jsObject;
        return ConverterUtil.convertToString(bigDecimal);
    }

    public static String convertToBoolean(Object jsObject) {
        Boolean booleanValue = (Boolean) jsObject;
        return ConverterUtil.convertToString(booleanValue);
    }

    public static String convertToDateTime(Object jsObject) {
        Date date = (Date) Context.jsToJava(jsObject, Date.class);
        Calendar calendar = Calendar.getInstance();
        calendar.clear();
        calendar.setTime(date);
        return ConverterUtil.convertToString(calendar);
    }

    public static String convertToDate(Object jsObject) {
        Date date = (Date) Context.jsToJava(jsObject, Date.class);
        return ConverterUtil.convertToString(date);
    }

    public static String convertToTime(Object jsObject) {
        Date date = (Date) Context.jsToJava(jsObject, Date.class);
        Calendar calendar = Calendar.getInstance();
        calendar.clear();
        calendar.setTime(date);
        Time time = new Time(calendar);
        return ConverterUtil.convertToString(time);
    }

    public static String convertToGYearMonth(Object jsObject) {
        Date date = (Date) Context.jsToJava(jsObject, Date.class);
        Calendar calendar = Calendar.getInstance();
        calendar.clear();
        calendar.setTime(date);
        YearMonth yearMonth = new YearMonth(calendar.get(Calendar.YEAR), calendar.get(Calendar.MONTH));
        return ConverterUtil.convertToString(yearMonth);
    }

    public static String convertToGMonthDay(Object jsObject) {
        Date date = (Date) Context.jsToJava(jsObject, Date.class);
        Calendar calendar = Calendar.getInstance();
        calendar.clear();
        calendar.setTime(date);
        MonthDay monthDay = new MonthDay(calendar.get(Calendar.MONTH), calendar.get(Calendar.DAY_OF_MONTH));
        return ConverterUtil.convertToString(monthDay);
    }

    public static String convertToGYear(Object jsObject) {
        Date date = (Date) Context.jsToJava(jsObject, Date.class);
        Calendar calendar = Calendar.getInstance();
        calendar.clear();
        calendar.setTime(date);
        Year year = new Year(calendar.get(Calendar.YEAR));
        return ConverterUtil.convertToString(year);
    }

    public static String convertToGDay(Object jsObject) {
        Date date = (Date) Context.jsToJava(jsObject, Date.class);
        Calendar calendar = Calendar.getInstance();
        calendar.clear();
        calendar.setTime(date);
        Day day = new Day(calendar.get(Calendar.DAY_OF_MONTH));
        return ConverterUtil.convertToString(day);
    }

    public static String convertToDuration(Object jsObject) {
        Date date = (Date) Context.jsToJava(jsObject, Date.class);
        Calendar calendar = Calendar.getInstance();
        calendar.clear();
        calendar.setTime(date);
        // Need to figure out how to capture the isNegative flag
        Duration duration = new Duration(false, calendar);
        return ConverterUtil.convertToString(duration);
    }

    public static String convertToGMonth(Object jsObject) {
        Date date = (Date) Context.jsToJava(jsObject, Date.class);
        Calendar calendar = Calendar.getInstance();
        calendar.clear();
        calendar.setTime(date);
        Month month = new Month(calendar.get(Calendar.MONTH));
        return ConverterUtil.convertToString(month);
    }

    public static String convertToNormalizedString(Object jsObject) {
        String str = (String) jsObject;
        return new NormalizedString(str).toString();
    }

    public static String convertToToken(Object jsObject) {
        String str = (String) jsObject;
        return new Token(str).toString();
    }

    public static String convertToLanguage(Object jsObject) {
        String str = (String) jsObject;
        return new Language(str).toString();
    }

    public static String convertToName(Object jsObject) {
        String str = (String) jsObject;
        return new Name(str).toString();
    }

    public static String convertToNCName(Object jsObject) {
        String str = (String) jsObject;
        return new NCName(str).toString();
    }

    public static String convertToNOTATION(Object jsObject) {
        String str = (String) jsObject;
        Notation notation = new Notation();
        notation.setName(new NCName(str));
        return notation.toString();
    }

    public static String convertToAnyURI(Object jsObject) {
        String str = (String) jsObject;
        return ConverterUtil.convertToAnyURI(str).toString();
    }

    public static String convertToQName(Object jsObject) {
        return (String) jsObject;
    }

    public static String convertToHexBinary(Object jsObject) {
        String str = (String) jsObject;
        return ConverterUtil.convertToHexBinary(str).toString();
    }

    public static String convertToBase64Binary(Object jsObject) {
        return (String) jsObject;
    }
}
