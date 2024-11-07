inFile = open("NaturePaper.txt",'r')
print(len(set(inFile.read().upper().replace(',','').replace(';','').replace('(','').replace(')','').replace('!','').replace('?','').replace('.','').replace("—",'').replace("\n", '').replace("”", '').replace("“", '').split())))
inFile.close()
