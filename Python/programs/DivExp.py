def DivExp(a,b):
    try:
        assert a>0,"Number is negative." 
        if b==0:
            raise ZeroDivisionError("division error")
        c=a/b
        return c
    
    except AssertionError as x:
        print("Assertion failure: "+str(x))


    except ZeroDivisionError as x:
        print(x)


x,y = map(int,input("Enter two integers: ").split())
DivExp(x,y)
