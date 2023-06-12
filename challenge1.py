import serial
from BIT_MATH import *
from tkinter import  *
from tkinter import  ttk

def print_line():
    global text_value
    global text_box
    #text_value=text_box.get()
    print("Hello ",text_value.get())


    



def change_ledValue(bit_num, value):
    global PortValue
    global myserial
    global myLabel
    send_value = (bit_num << 4) | value
    
    if value == 1:
        newcolor="green"
        PortValue = PortValue | (1 << bit_num)
    elif value == 0:
        newcolor="red"
        PortValue = PortValue & ~(1 << bit_num)
    
    try:
        myserial.write(bytes([send_value]))
    except:
        print("Serial error")
    else:
        print("Value sent:", bytes([send_value]))
        print("Port value:", bytes([PortValue]))
        ledLabel[bit_num].configure(bg=newcolor)


    

    
mainWindow=Tk()
mainWindow.geometry("550x700")
myLabel=Label(mainWindow,text="Welcome To Leds Control System",bg="yellow",height=1,width=30,bd=20)
myLabel.grid(row=10,column=50,rowspan=4,columnspan=3)



ButList=[]
ButListOff=[]
ledLabel=[ ]
PortValue=0b00000000

for counter in range(0, 8):
    ledLabel.append(Label(mainWindow, text="LED " + str(counter), bg="white", height=1, width=10, bd=5))
    ledLabel[counter].grid(row=100 + counter * 10, column=15, rowspan=3, columnspan=3, padx=25, pady=5)

    ButList.append(Button(mainWindow, text="Turn On", bg="Green", height=1, width=10,command=lambda counter=counter: change_ledValue(counter, 1)))
    ButList[counter].grid(row=100 + counter * 10, column=50, rowspan=3, columnspan=3, padx=25, pady=15)

    ButListOff.append(Button(mainWindow, text="Turn Off", bg="red", height=1, width=10,command=lambda counter=counter: change_ledValue(counter, 0)))
    ButListOff[counter].grid(row=100 + counter * 10, column=80, rowspan=3, columnspan=3, padx=25, pady=15)

nameLabel=Label(mainWindow,text="Made By \n Abdalla Ragab",bg="pink",height=1,width=10,bd=20)
nameLabel.grid(row=250,column=50,rowspan=4,columnspan=3)

OSLabel=Label(mainWindow,text="Embedded Linux App",bg="LightSalmon",height=1,width=20,bd=20)
OSLabel.grid(row=500,column=50,rowspan=4,columnspan=6,pady=20)

try:
    myserial=serial.Serial(port="COM2",baudrate=9600,bytesize=8,timeout=3,parity="N",stopbits=2)

except:
        print("Serial error")
else:
        print("serial Opend")

mainWindow.title("Abdullah")
mainWindow.mainloop()
