class A:
    __obj = None
    __init_flag = True
    def __new__(cls,*args,**kwargs):
        if cls.__obj == None:
            cls.__obj = object.__new__(cls)

        return cls.__obj
    def __init__(self):
        if A.__init_flag:
            A.__init_flag = False
     
            

        