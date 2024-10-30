from gpiozero import LED
from time import sleep

red = LED(14)
green = LED(15)
blue = LED(18)


while True:
    red.on()
    green.on()
    blue.on()
    sleep(0.5)
    red.off()
    green.off()
    blue.off()
    sleep(0.5)
