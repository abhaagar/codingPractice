#!/usr/bin/python
# program to see the effect of heuristic used for
# garbage collection based on generation of object
import time
import gc
gc.set_debug(gc.DEBUG_LEAK)

def allocateObj():
   str = "Allocating a string, destructed later"*1024
   return

while True:
   start = time.time()
   allocateObj()
   end =  time.time()
   print "Time in allocation",(end-start)
   print "Garbage Collector Stats",(gc.get_count())
   print gc.garbage
   time.sleep(1)

