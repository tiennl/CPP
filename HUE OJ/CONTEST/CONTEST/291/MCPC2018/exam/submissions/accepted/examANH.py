#!/usr/bin/env python3
import sys

ks, m, f = sys.stdin.read().split()
k = int(ks)
same = len([1 for (a, b) in zip(m, f) if a == b])
n = len(m)
if k <= same:
    print(n - (same - k))
else:
    print(n-k + same)
