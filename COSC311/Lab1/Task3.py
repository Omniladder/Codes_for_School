inFile = open("NaturePaper.txt",'r')

def count(seachTerm, wordCount):
    if seachTerm.upper() in wordCount:
        print(seachTerm, " Appears ", wordCount[seachTerm.upper()], "times")
    else:
        print(seachTerm, "Is not in Paper")

wordCount = {}

for i in inFile.read().upper().replace(',','').replace(';','').replace('(','').replace(')','').replace('!','').replace('?','').replace('.','').replace("—",'').replace("\n", '').replace("”", '').replace("“", '').split():
    if i in wordCount:
        wordCount[i] += 1
    else:
        wordCount[i] = 1

count("AI", wordCount)
count("robotics", wordCount)
count("climate", wordCount)
count("materials", wordCount)
count("algorithms", wordCount)

