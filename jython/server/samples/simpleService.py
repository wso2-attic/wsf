#@annotate("returns=double", "operationName=f", a="double")
def f(a):
    return a

#@annotate("returns=int", "operationName=add", var1="integer", var2="integer")
def add(var1,var2):
    return var1+var2

#@annotate("returns=double", "operationName=deduct", var1="double", var2="double")
def deduct(var1,var2):
    return var1-var2

#@annotate("returns=int", "operationName=addTwo", var1="integer", var2="integer", var3=(a="string", b="integer"))
def addTwo(var1,var2,var3):
    return var1+var2

#@annotate("returns=int", "operationName=doComplexStuff", var1="integer", var2="(a="integer", b="integer")", var3="(a="string", b="integer")")
def doComplexStuff(var1,var2,var3):
    return var1

class MyClass:
    #@annotate("returns=integer", "operationName=MyClass.multiply", var1="integer", var2="integer")
    def multiply(var1,var2):
        return var1*var2
