#!/usr/bin/env python3
import sys
hand = sys.stdin.read()
print(max((hand.count(r) for r in "A23456789TJQK")))
