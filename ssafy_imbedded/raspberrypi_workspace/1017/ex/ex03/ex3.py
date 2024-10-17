from gpiozero import LED
from time import sleep

LED1 = LED(14)
LED2 = LED(15)
LED3 = LED(18)
led1 = 0    
led2 = 0
led3 = 0

while True:
    num = int(input("INPUT>>"))


    if (num == 1) :
        if (led1 == 0):
            LED1.on()
            led1 = 1
            print("LED1 on")
        else:
            LED1.off()
            led1 = 0
            print("LED1 off")
    elif (num == 2) :
        if (led2 == 0):
            LED2.on()
            led2 = 1
            print("LED2 on")
        else:
            LED2.off()
            led2 = 0
            print("LED2 off")
    elif (num == 3) :
        if (led3 == 0):
            LED3.on()
            led3 = 1
            print("LED3 on")
        else:
            LED3.off()
            led3 = 0
            print("LED3 off")


