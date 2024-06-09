def Div(a,b):

    try:
        assert a>0,"Number is negative."

        if b==0:
            raise ZeroDivisionError("Zero!!")
        c=a/b
        return c 
    
    except AssertionError as x:
        print("Assertion failure: ",x)

    except ZeroDivisionError as x:
        print(x)

x,y = map(int,input("Enter them").split())
Div(x,y)