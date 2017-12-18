#!/usr/bin/python

import singleLinkedList as sll
import sys

num1 = sll.LinkedList()
num2 = sll.LinkedList()
ans = sll.LinkedList()

numDigits1 = int(input("Enter number of digits of number 1: "))
digitCount = 0

while digitCount < numDigits1:
    num1.append ( int(input()) )
    digitCount += 1

numDigits2 = int(input("Enter number of digits of number 2: "))

digitCount = 0

while digitCount < numDigits2:
    num2.append (int (input() ))
    digitCount += 1

print("Numbers Entered are: ")
num1.printNodes()
num2.printNodes()

carryOver = digitCount = 0
num1digit = num1.head
num2digit = num2.head

while digitCount < numDigits1 and digitCount < numDigits2:

    ansDigit = num1digit.data + num2digit.data + carryOver

    if ansDigit >= 10:
        carryOver = 1
        ansDigit = ansDigit%10

    else:
        carryOver = 0

    num1digit = num1digit.next
    num2digit = num2digit.next
    ans.append(ansDigit)
    digitCount += 1

while digitCount < numDigits1:
    
    ans.append(num1digit.data)
    num1digit = num1digit.next
    digitCount+=1

while digitCount < numDigits2:

    ans.append(num2digit.data)
    num2digit = num2digit.next
    digitCount+=1

ans.printNodes()
