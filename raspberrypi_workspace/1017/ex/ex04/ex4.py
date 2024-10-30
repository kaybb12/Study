from gpiozero import Button
from gpiozero import LED
from signal import pause
from time import sleep

LED1 = LED(14) 
LED2 = LED(15)
LED3 = LED(18)
btn1 = Button(23)
btn2 = Button(24)

def press1():
    print("Btn1 Pressed!")
    LED1.on()
    print("LED1 on")
    sleep(0.5)
    LED1.off()
    print("LED1 off")
    sleep(0.5)
    LED2.on()
    print("LED2 on")
    sleep(0.5)
    LED2.off()
    print("LED2 off")
    sleep(0.5)
    LED3.on()
    print("LED3 on")
    sleep(0.5)
    LED3.off()
    print("LED3 off")
    sleep(0.5)
    
def release1():
    print("Btn1 Released!")
    
def press2():
    print("Btn2 Pressed!")
    LED1.on()
    print("LED1 on")
    LED2.on()
    print("LED2 on")
    LED3.on()
    print("LED3 on")
    sleep(1)
    LED1.off()
    print("LED1 off")
    LED2.off()
    print("LED2 off")
    LED3.off()
    print("LED3 off")
    sleep(1)
    
def release2():
    print("Btn2 Released!")



btn1.when_pressed = press1
btn1.when_released = release1
btn2.when_pressed = press2
btn2.when_released = release2

pause()