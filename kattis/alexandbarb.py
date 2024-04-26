A,B,C = map(int,input().split())
print((A % (B+C) >= B) and "Alex" or "Barb")