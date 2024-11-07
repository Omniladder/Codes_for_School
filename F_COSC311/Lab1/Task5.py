import matplotlib.pyplot as plt 

wordCount = {}

words = inFile.read().upper().replace(',','').replace(';','').replace('(','').replace(')','').replace('!','').replace('?','').replace('.','').replace("—",'').replace("\n", '').replace("”", '').replace("“", '').split()



plt.bar(appearances, avg_len)
