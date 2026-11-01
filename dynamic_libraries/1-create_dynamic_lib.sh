#!/bin/bash
gcc -fPIC -c *.c
gcc -shared *.o -o liball.so
