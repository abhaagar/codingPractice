#!/usr/bin/python
import time

#objects = []
class A:
   def __init__(self,b):
      #self.string = "leak"*1024*8
      self.b  = b

   def __del__(self):
      print "deleting object of class A"

class B:
   def __init__(self):
      #self.string = "leak"*1024*8
      pass

   def setA(self,a):
      self.a = a 

   def __del__(self):
      print "deleting object of class B"

def createLeak():
   objB = B()
   objA = A(objB)
   objB.setA(objA)
   #objects.append(objA)
   #objects.append(objB)
   print "circularly dependent objects were created"
 

while True:
   time.sleep(1)
   createLeak()

