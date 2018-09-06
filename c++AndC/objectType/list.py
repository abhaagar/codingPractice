import ctypes

class ListStruct(ctypes.Structure):
    _fields_ = [("ob_refcnt",ctypes.c_long),
                ("ob_type",ctypes.c_void_p),
                ("ob_size",ctypes.c_ulong),
                ("ob_item",ctypes.c_long),
                ("allocated",ctypes.c_ulong)]

    def __repr__(self):
        return ("ListStruct(len={self.ob_size}, "
                "refcount={self.ob_refcnt},items={self.ob_item}, "
                "allocated={self.allocated})").format(self=self)
