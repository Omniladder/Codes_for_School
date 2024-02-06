from random import randint


numOfRolls = int(input("How many rolls do you plan on doing "))

arr = [0] * 13


for i in range(numOfRolls):
   arr[randint(1, 6) + randint(1, 6)] += 1


for i in range(2, 12 + 1):
    print("Number of  " + str(i) + " Rolls: " + str(arr[i] / numOfRolls))




