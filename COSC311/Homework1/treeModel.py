def decTree(outIn, humIn, windIn):

    if outIn == "Overcast":
        return True
    elif outIn == "Sunny":
        if humIn == "Normal":
            return True
        else:
            return False
    else:
            if windIn == "Weak":
                return True
            else:
                return False

outIn = input("What is the outlook ")
humIn = input("What is the humidity ")
windIn = input("How is the wind ")

print(decTree(outIn, humIn, windIn))
