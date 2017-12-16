#!/bin/python3

import sys

def minimumTime(x):

    x.sort()
    result = 0

    print(x)    

    prev = x[0]

    for i in x:
        result += (i - prev)
        prev = i

    return result

if __name__ == "__main__":

    t = int(input().strip())

    for a0 in range(t):

        n = int(input().strip())
        x = list(map(int, input().strip().split(' ')))
        result = minimumTime(x)
        print(result)
