import random


def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


def f(x, c, n):
    return (x ** 2) % n + c


n = int(input())
a = [-1, 1, 2]
ans = -1
while ans == -1:
    x0 = random.randint(0, n - 1)
    c = a[random.randint(0, 2)]
    x1 = f(x0, c, n) % n
    while gcd(abs(x1 - x0), n) == 1:
        x1 = f(f(x1, c, n) % n, c, n) % n
        x0 = f(x0, c, n) % n
    g = gcd(x1 - x0, n)
    if g != n:
        ans = g
if (ans < n // ans):
    print(ans, n // ans)
else:
    print(n // ans, ans)