#!/usr/bin/env python3
import sys

def ok(c):
    p = c
    s = set()
    for i in range(6):
        d = p % 10
        if d == 0 or c % d or d in s:
            return 0
        p //= 10
        s.add(d)
    return 1
        
L,H  = map(int, sys.stdin.read().split())
A =[c for c in range(L,H+1) if ok(c)]
# print(A)
print(len(A))
