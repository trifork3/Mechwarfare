
from threading import Thread, Lock, Event

from botnet.logging import *

import time, sys
import traceback as tb

from server.gaits.walking import *
import server.gaits.settings as s

if not s.isAnimation:
    import RPi.GPIO as GPIO
    GPIO.setmode(GPIO.BCM)  
    GPIO.setup(s.GUN_PIN, GPIO.OUT, initial=GPIO.LOW)



class GunController(Thread):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.firing = False

    def changeSprayTime(self, isOn):
        if isOn:
            if s.spray_time == s.SPRAY_TIME_3:
                s.spray_time = s.SPRAY_TIME_1
            else:
                s.spray_time = s.SPRAY_TIME_3 

    ### THIS IS THE FUNCTION
    def fire(self, isOn):
        if isOn:
            debug("Started Firing")
            self.firing = True
        else:
            debug("Stopped firing")
            self.firing = False
                

    def run(self):
        self.stop = Event()
        while not self.stop.is_set():
            if not s.isAnimation:
                # fire for spray time and then wait 1 second so user doesn't spray too much
                if self.firing:
                    GPIO.output(18,True)
                    time.sleep(s.spray_time)
                    GPIO.output(18,False)
                    time.sleep(s.SPRAY_DELAY)
                else:
                    time.sleep(.05)
            else:
                if self.firing:
                    s.isFiring = True
                    time.sleep(s.spray_time)
                    print (s.spray_time)
                    s.isFiring = False
                    time.sleep(s.SPRAY_DELAY)
                else:
                    time.sleep(.05)

    def pan(self, speed):
        """This function should turn on the pan motor at the specified speed,
           positive values are to the right, negative to the left. Zero is off.
           The input will range from -1 to +1. `pan` should return instantly."""

        debug("rotate pan at speed: ",  speed)
        if speed == 0.0:
            stopTurretServo(0)
        elif speed < 0.0:
            changeServoSpeeds(-speed, ["pan"])
            moveTurretServo(0, getTurretBound(0,1))
        elif speed > 0.0:
            changeServoSpeeds(speed, ["pan"])
            moveTurretServo(0, getTurretBound(0,0))

    def tilt(self, speed):
        """This function should behave like the `pan` function, but for the
        tilt motor. It should return instantly."""

        debug("rotate tilt at speed: ", speed)
        if speed == 0.0:
            stopTurretServo(1)
        elif speed < 0.0:
            changeServoSpeeds(-speed, ["tilt"])
            moveTurretServo(1,getTurretBound(1,1))
        elif speed > 0.0:
            changeServoSpeeds(speed, ["tilt"])
            moveTurretServo(1, getTurretBound(1,0))

    # is on deals with the fact that when you release the button, the value changes. 
    # This should probably be handled on the client side though

    def panHome(self, isOn):
        if isOn:
            print ("go to pan home")
            changeServoSpeeds(s.MAX_SERVO_SPEED, ['pan'])
            moveTurretServo(0,0.0)

    def tiltHome(self, isOn):
        if isOn:
            print ("go to tilt home")
            changeServoSpeeds(s.MAX_SERVO_SPEED, ['tilt'])
            moveTurretServo(1,0.0)


