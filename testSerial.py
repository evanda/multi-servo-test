import serial

arduino = serial.Serial('/dev/ttyACM0')


# e.g. 1 , 180 (for servo 1 to 180 degrees) or 2 , 90 (for servo 2 to 90 degrees)
# for the continuous rotation servo, 128 is stop.
def writeAngle(servo, angle):
    whichServo = chr(servo)
    angleByte = chr(angle)
    
    arduino.write(whichServo+angleByte);

# writeAngle(1,0)
