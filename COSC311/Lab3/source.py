import stats as st
import pandas as pd
from matplotlib import pyplot as plt

sidiBelFrame = pd.read_csv("Sidi-Bel_Abbes_Region.csv")
bejaiaFrame = pd.read_csv("Bejaia_Region.csv")

#columnTitles = bejaia.columns


bejaia = bejaiaFrame.values.tolist()
sidiBel = sidiBelFrame.values.tolist()

for i in bejaia[:][:]:
    i[13] = i[13].strip()

#print(bejaia)

#for i in range(len(bejaia)):
#    print(bejaia[i][3])

bejFireTemps = [bejaia[i][3] for i in range(len(bejaia)) if bejaia[i][len(bejaia[i]) - 1] == 'fire']
bejFireHumid = [bejaia[i][4] for i in range(len(bejaia)) if bejaia[i][len(bejaia[i]) - 1] == 'fire']
bejFireWind = [bejaia[i][5] for i in range(len(bejaia)) if bejaia[i][len(bejaia[i]) - 1] == 'fire']
bejFireRain = [bejaia[i][6] for i in range(len(bejaia)) if bejaia[i][len(bejaia[i]) - 1] == 'fire']


bejNoFireTemps = [bejaia[i][3] for i in range(len(bejaia)) if bejaia[i][len(bejaia[i]) - 1] != 'fire']
bejNoFireHumid = [bejaia[i][4] for i in range(len(bejaia)) if bejaia[i][len(bejaia[i]) - 1] != 'fire']
bejNoFireWind = [bejaia[i][5] for i in range(len(bejaia)) if bejaia[i][len(bejaia[i]) - 1] != 'fire']
bejNoFireRain = [bejaia[i][6] for i in range(len(bejaia)) if bejaia[i][len(bejaia[i]) - 1] != 'fire']

#fireBejTemprs = [i for i in bejTemps if ]

width = .4
bejMeanCate = ["Temperature", "Humidity", "Wind Speed", "Rain"]
xArrangement = [i for i in range(len(bejMeanCate))]

plt.bar(xArrangement, [st.mean(bejFireTemps), st.mean(bejFireHumid), st.mean(bejFireWind), st.mean(bejFireRain)], width, label='Fire')
plt.bar([i + width for i in xArrangement], [st.mean(bejNoFireTemps), st.mean(bejNoFireHumid), st.mean(bejNoFireWind), st.mean(bejNoFireRain)], width, label='No Fire')






plt.xticks([i + width / 2 for i in xArrangement], bejMeanCate)

plt.title("Mean Data based on fire")

plt.legend()

plt.show()


'''

Observations:

    Temperatures increase During Fires
    Humidity Decreases During Fires
    Wind Speed might decrease during fires however its hard to tell given the small change
    Its hard to know the coorelation between rain and fires given the low amount of rain that has found

'''


for i in sidiBel[:][:]:
    i[13] = i[13].strip()



sidiMedCate = ["FFMC Median", "DMC Median", "DC Median", "ISI Median"]

FFMCMed = st.median([sidiBel[i][7] for i in range(len(sidiBel))])
DMCMed = st.median([sidiBel[i][8] for i in range(len(sidiBel))])
DCMed = st.median([sidiBel[i][9] for i in range(len(sidiBel))])
ISIMed = st.median([sidiBel[i][10] for i in range(len(sidiBel))])

plt.bar(xArrangement, [FFMCMed, DMCMed, DCMed, ISIMed], width + .2, label = 'Sidi Medians')

plt.xticks(xArrangement, sidiMedCate)


plt.show()


bejNoFireTemps = [bejaia[i][3] for i in range(len(bejaia)) if bejaia[i][len(bejaia[i]) - 1] != 'fire']

tempQuantiles = [
        st.quantile([bejaia[i][3] for i in range(len(bejaia))], .25), 
        st.quantile([bejaia[i][3] for i in range(len(bejaia))], .6), 
        st.quantile([bejaia[i][3] for i in range(len(bejaia))] , .75)
]

humidQuantiles = [
        st.quantile([bejaia[i][4] for i in range(len(bejaia))], .25), 
        st.quantile([bejaia[i][4] for i in range(len(bejaia))], .6), 
        st.quantile([bejaia[i][4] for i in range(len(bejaia))] , .75)
        ]

windQuantiles = [
        st.quantile([bejaia[i][5] for i in range(len(bejaia))], .25), 
        st.quantile([bejaia[i][5] for i in range(len(bejaia))], .6), 
        st.quantile([bejaia[i][5] for i in range(len(bejaia))] , .75)
        ]

rainQuantiles = [
        st.quantile([bejaia[i][6] for i in range(len(bejaia))], .25), 
        st.quantile([bejaia[i][6] for i in range(len(bejaia))], .6), 
        st.quantile([bejaia[i][6] for i in range(len(bejaia))] , .75)
        ]

print("Temperature Quantiles .25, .6, .75: ", tempQuantiles)
print("Relative Humidity Quantiles .25, .6, .75: ", humidQuantiles)
print("Wind Speed Quantiles .25, .6, .75: ", windQuantiles)
print("Rain Quantiles .25, .6, .75: ", rainQuantiles)

