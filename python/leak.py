#!/usr/bin/python
import time
import gc
import weakref
#objects = []
class A:
   def __init__(self,b):
      self.string = "leak"*1024
      self.b  = weakref.ref(b)

   def __del__(self):
      print "deleting object of class A"

class B:
   def __init__(self):
      self.string = "leak"*1024
   
   def setA(self,a):
      self.a = weakref.ref(a) 

   #def __del__(self):
   #   print "deleting object of class B"

def createLeak():
   objB = B()
   objA = A(objB)
   objB.setA(objA)
   #objects.append(objA)
   #objects.append(objB)
 
#print gc.get_threshold()
#gc.set_debug(gc.DEBUG_STATS|gc.DEBUG_COLLECTABLE|gc.DEBUG_UNCOLLECTABLE|gc.DEBUG_INSTANCES|gc.DEBUG_OBJECTS|gc.DEBUG_LEAK)
while True:
   time.sleep(1)
   createLeak()
   print "circularly dependent objects were created"
   #import pdb; pdb.set_trace()
   print "Count:",gc.get_count()
   print "Garbage Count:",len(gc.garbage)


