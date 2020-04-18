#!/bin/bash
cython queuecpy.pyx
gcc -g -O2 -fpic -c queue.c -o queue.o
gcc -g -O2 -fpic -c queuecpy.c -o queuecpy `python-config --cflags`
gcc -shared -o queuecpy.so queue.o queuecpy `python-config --libs`
