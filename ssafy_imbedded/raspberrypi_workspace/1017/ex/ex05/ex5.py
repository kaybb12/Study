from gpiozero import Button
from gpiozero import LED
from signal import pause
from time import sleep

led1 = LED(14)
led2 = LED(15)
led3 = LED(18)
led4 = LED(2)
btn1 = Button(23)
btn2 = Button(24)

num = 1

def press1():
    print("Btn1 Pressed!")
    global num
    if (num == 1):
        led1.off()
        print("led1 off")
        sleep(0.5)
        led2.on()
        print("led2 on")
        sleep(0.5)
        num += 1
        print(num)
    elif (num == 2):
        led2.off()
        print("led2 off")
        sleep(0.5)
        led3.on()
        print("led3 on")
        sleep(0.5)
        num += 1
        print(num)
    elif (num == 3):
        led3.off()
        print("led3 off")
        sleep(0.5)
        led4.on()
        print("led4 on")
        sleep(0.5)
        num += 1
        print(num)
    elif (num == 4):
        led4.off()
        print("led4 off")
        sleep(0.5)
        led1.on()
        print("led1 on")
        sleep(0.5)
        num = 1
        print(num)

def release1():
    print("Btn1 Released!")

def press2():
    global num
    print("Btn2 Pressed!")
    led2.off()
    led3.off()
    led4.off()
    led1.on()
    num = 1
    print("init")
    sleep(0.5)


def release2():
    print("Btn2 Released!")
#while True:
btn1.when_pressed = press1
btn2.when_pressed = press2
btn1.when_released = release1
btn2.when_released = release2

pause()

