import random


def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


def func(x, c, n):
    return (x ** 2) % n + c


n = int(input())
f_n = n
a = [-1, 1, 2]
f = []
ans = -1
while ans * ans < f_n:
    x0 = random.randint(0, n - 1)
    c = a[random.randint(0, 2)]
    x1 = func(x0, c, n) % n
    while gcd(abs(x1 - x0), n) == 1:
        x1 = func(func(x1, c, n) % n, c, n) % n
        x0 = func(x0, c, n) % n
    g = gcd(x1 - x0, n)
    if g != n:
        f.append(g)
        n //= g
        ans *= g
i = 2
while i * i <= n:
    while n % i == 0:
        f.append(i)
        n /= i
    i += 1
if (n > 1):
    f.append(n)
f.sort()
for i in range(len(f)):
    print(f[i])