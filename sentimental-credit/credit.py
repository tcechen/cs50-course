# TODO
from cs50 import get_int
import math

cnt = 1
sum1 = 0
sum2 = 0
num = get_int("Number: ")

temp = num

while num > 0:
    digit = num % 10
    if cnt % 2 == 1:
        sum1 += digit
    else:
        digit2 = digit * 2
        if digit2 >= 10:
            sum2 = sum2 + int(digit2 / 10) + digit2 % 10
        else:
            sum2 = sum2 + digit2
    cnt += 1
    num = int(num / 10)

N = cnt - 1

temp = int(temp / math.pow(10, N - 2))


if (sum1 + sum2) % 10 == 0:
    if digit == 4 and (N == 13 or N == 16):
        print("VISA")
    elif digit == 3 and N == 15 and (temp == 34 or temp == 37):
        print("AMEX")
    elif digit == 5 and N == 16 and (temp >= 51 and temp <= 55):
        print("MASTERCARD")
    else:
        print("INVALID")
else:
    print("INVALID")
