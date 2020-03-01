def gcd(a, b):
    if b == 0:
        return (a, 1, 0)
    else:
        d, x1, y1 = gcd(b, a % b)
        return (d, y1, x1 - y1 * (a // b))

a, b, c = list(map(int, input().split()))
d1, x, y = gcd(a, b)
if c % d1 != 0:
    print("Impossible")
else:
    c //= d1
    a //= d1
    b //= d1
    x *= c
    y *= c
    if (x != 0):
        k = (x // abs(x)) * ((abs(x) // b) + (x < 0) * (x % b != 0))
    else:
        k = 0
    x -= k * b
    y += k * a
    print(x, y)