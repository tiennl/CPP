score = int(raw_input())
m = raw_input()
n = len(m)
same = sum(a==b for a,b in zip(m, raw_input()))
print min(same,score) + min(n-same,n-score)

