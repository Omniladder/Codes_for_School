inFile = open("NaturePaper.txt",'r')

wordCount = {}

for i in inFile.read().upper().replace(',','').replace(';','').replace('(','').replace(')','').replace('!','').replace('?','').replace('.','').replace("—",'').replace("\n", '').replace("”", '').replace("“", '').split():
    if i in wordCount:
        wordCount[i] += 1
    else:
        wordCount[i] = 1


inFile.close()
