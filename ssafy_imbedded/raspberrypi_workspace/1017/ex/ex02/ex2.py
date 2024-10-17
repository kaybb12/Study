from gpiozero import LED
from time import sleep

LED1 = LED(14)
LED2 = LED(15)

while True:
    t = 1;
    LED2.on()
    sleep(2)
    for _ in range (6):
        LED1.on()
        sleep(t)
        LED1.off()
        sleep(t)
        t -= 0.2
    LED2.off()