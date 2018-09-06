import ctypes

MAX=10000000
def seq(num):
   i = 0
   while i<num:
      yield i
      i+=1

def sum():
  count = 0
  for i in seq(MAX):
     count += 1
  return count


def csum():
   count = 0
   ob_ival_offset = \
     ctypes.sizeof(ctypes.c_long)+\
     ctypes.sizeof(ctypes.c_voidp)
   ob_ival = ctypes.c_int.from_address(id(count)+ob_ival_offset)
   for i in seq(MAX):
      ob_ival.value = ob_ival.value + 1
   return count
