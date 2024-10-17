from gpiozero import Button
from gpiozero import LED
from signal import pause
from time import sleep
from threading import Timer

leds = [LED(14), LED(15), LED(18), LED(16), LED(20), LED(21)]
btn1 = Button(23)


mode = 1

def led_mode_update():
    global mode

    if mode == 1:
        for i in range(0, len(leds), 2):
            leds[i].on()
        for i in range(1, len(leds), 2):
            leds[i].off()
        sleep(0.5)
        for i in range(0, len(leds), 2):
            leds[i].off()
        for i in range(1, len(leds), 2):
            leds[i].on()
        sleep(0.5)

    elif mode == 2:
        for led in leds:
            led.on()
        sleep(0.5)
        for led in leds:
            led.off()
        sleep(0.5)

    Timer(1, led_mode_update).start()

def press1():
    global mode
    mode = 2 if mode == 1 else 1
    print(f"Mode changed to {mode}")

btn1.when_pressed = press1

led_mode_update()

pause()
