# -*- coding: utf-8 -*-
cdef extern from "queue.h":
    ctypedef struct Queue
    Queue *new_queue(int n)
    void put(Queue *q, int n)
    int get(Queue *q)
    int size(Queue *q)

cdef class PyQueue:
    cdef Queue* _impl
    def __cinit__(self, int n):
        self._impl = new_queue(n)

    def getSize(self):
        return size(self._impl)

    def putElement(self, int n):
        put(self._impl, n)

    def getElement(self):
        return get(self._impl)
