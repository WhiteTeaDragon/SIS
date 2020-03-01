def gcd(a, b):
    if b == 0:
        return (a, 1, 0)
    else:
        d, x1, y1 = gcd(b, a % b)
        return (d, y1, x1 - y1 * (a // b))
    
a, b = list(map(int, input().split()))
a %= b
d, x, y = gcd(a, b)
if d != 1:
    print(-1)
else:
    print(x % b)