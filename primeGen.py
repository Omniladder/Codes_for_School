arr = [1]

def multiplication(arr):
    num = 1
    for i in arr:
        num *= i
    return num


num = 1
sum = 1
for i in range(1, 8):
    sum = sum * num
    num = sum * num  + 1
    print(num)

print(arr[len(arr) - 1])