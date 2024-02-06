arr = [(int(i / 2) * (i + 1) + int((i + 1) / 2) * (i % 2 != 0)) for i in range(1, 20 + 1)]
print( "Even: " + str(sum(i * (i % 2 == 0) for i in arr)) + " Odd: " + str(sum(i * (i % 2 != 0) for i in arr)) + " Array: " + str(arr))
# HUGE FLEX RIGHT HERE
