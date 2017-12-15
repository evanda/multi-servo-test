from testSerial import writeAngle
import time

delay = 0

#def goAngle(servo, currentAngle, destinationAngle):
  #if ( currentAngle > destinationAngle ): step = -1
  #else: step = 1

  #for a in range(currentAngle, destinationAngle, step):
    #print "Angle %d" % (a)
    #writeAngle(servo,a)
    #time.sleep(delay)

def armTo(firstAngle,secondAngle):
  writeAngle(2,firstAngle)
  writeAngle(3,secondAngle)

