#!/usr/bin/env python3
import sys, math
x,y, x1,y1, x2,y2 = map(int, sys.stdin.read().split())
xp = abs(x - (x1 + x2)/2) - (x2 - x1)/2
yp = abs(y - (y1 + y2)/2) - (y2 - y1)/2

if xp < 0 : # above/below
    print(yp)
elif yp < 0: # beside
    print(xp)
else:      # diag from corner
    print(math.hypot(xp, yp))
