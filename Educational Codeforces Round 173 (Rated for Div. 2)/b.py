import sys
import functools

sys.set_int_max_str_digits(6000)

@functools.cache
def fac(x):
    r = 1
    for i in range(1, x+1):
        r *= i
    return r


def solve():
    n, k = map(int, input().split())

    print('1', end=' ')
    sum = k * fac(n)

    if n >= 3 or sum % 3 == 0:
        print('3', end=' ')
    if k == 5:
        print('5', end=' ')
    if k == 7 or n >= 3:
        print('7', end=' ')
    if sum % 9 == 0:
        print('9', end=' ')
    print()


_t = int(input())
for i in range(0, _t):
    solve()

