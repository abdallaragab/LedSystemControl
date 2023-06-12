def SET_BIT(BYTE,BIT_no):
    return BYTE|(1<<BIT_no)

def CLEAR_BIT(BYTE,BIT_no):
    return BYTE&~(1<<BIT_no)

def TOGGLE_BIT(BYTE,BIT_no):
    return BYTE^(1<<BIT_no)

