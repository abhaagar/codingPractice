#!/usr/bin/python
import time, sys
class CycleNodeA:
    def __init__(self,nodeB):
       self.nodeB = nodeB
    def __del__(self):
       print "Freed nodeB"
class CycleNodeB:
    def __init__(self):
       self.nodeA = None
    def setNodeA(self,nodeA):
       self.nodeA = nodeA
    def __del__(self):
       print "Freed nodeA"
CycleList = []
for i in range(100):
    b = CycleNodeB()
    a = CycleNodeA(b)
    b.setNodeA(a)
    # created circular dependency
    CycleList.append(a)
    time.sleep(0.5)
CycleList = []
sys.exit(0)
#time.sleep(10000)
