inFile = open("NaturePaper.txt",'r')



wordCount = {}

for i in inFile.read().upper().replace(',','').replace(';','').replace('(','').replace(')','').replace('!','').replace('?','').replace('.','').replace("—",'').replace("\n", '').replace("”", '').replace("“", '').split():
    if i in wordCount:
        wordCount[i] += 1
    else:
        wordCount[i] = 1

for i in wordCount:
    if wordCount[i] == 2 or wordCount[i] == 5 or wordCount[i] == 10:
        print(i + " Appears " + str(wordCount[i]) + " Times")

