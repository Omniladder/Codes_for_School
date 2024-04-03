import stats as st
import pandas as pd
from matplotlib import pyplot as plt

sidiBel = pd.read_csv("Sidi-Bel_Abbes_Region.csv")
bejaia = pd.read_csv("Bejaia_Region.csv")

#columnTitles = bejaia.columns

print(type(bejaia))

for i in bejaia.rows:
    print(i)

bejTemps = bejaia.iloc[:,3]
bejHumid = bejaia.iloc[:,5]
bejWind = bejaia.iloc[:,6]
bejRain = bejaia.iloc[:,7]

#fireBejTemprs = [i for i in bejTemps if ]









