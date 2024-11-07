size = 0

while size < 2:
    size = int(input("Input in a size greater than or equal to 2 "))

for row in range(size):
    for i in range(size - row ):
        print(" ", end="")
    
    for j in range(size + row * 2):
        print("*", end="")

    print("")


for row in range(size - 2):
    for i in range(size * 3): 
        print("*", end="")
    print("")

for row in range(size + 1):
    for i in range(row):
        print(" ", end="")
    for j in range(size * 3 - row * 2):
        print("*", end="")

    print("")


