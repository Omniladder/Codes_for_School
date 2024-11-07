import pandas as pd


dataYears = [2002, 2008, 2013]
mergedData = []

for year in dataYears:
    currentCSV = pd.read_csv(f"NA{dataYears[0]}.csv")
    currentCSV['Year'] = [year for i in range(len(currentCSV))]
    mergedData.append(currentCSV)

mergedCSV = pd.concat(mergedData)
mergedCSV.to_csv("NAmerged.csv")
