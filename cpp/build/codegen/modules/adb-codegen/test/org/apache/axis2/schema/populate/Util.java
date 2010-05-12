package org.apache.axis2.schema.populate;

public class Util {
    public static Class getFactory(Class clazz)  {
        Class[] declaredClasse = clazz.getDeclaredClasses();
        for (int i = 0; i < declaredClasse.length; i++) {
            Class aClass = declaredClasse[i];
            if(aClass != null && aClass.getName().endsWith("Factory")){
                return aClass;
            }
        }
        throw new RuntimeException("Factory inner class not found");
    }
}
