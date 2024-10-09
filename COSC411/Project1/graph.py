
def trackBack(parents, startCity, targetCity):
    currentCity = targetCity
    path = []
    while currentCity is not startCity:
        path.insert(0,currentCity)
        currentCity = parents[currentCity]
    path.insert(0,currentCity)
    return path

def BFS(graph, startCity, targetCity):
   
    cityQueue = []
    cityQueue.append(startCity)

    visitedSet = set()
    visitedSet.add(startCity)

    parents = {}

    while(cityQueue):
        currentCity = cityQueue.pop()

        for city in list(graph[currentCity].keys()):
            if city not in visitedSet:
                cityQueue.append(city)
                visitedSet.add(city)
                parents[city] = currentCity
            
            if city is targetCity:
                return trackBack(parents, startCity, targetCity)


    

    
    

    



graph = {
    'Buffalo' : {'Boston': 450, 'Pittsburgh': 219},
    'Boston' : {'Buffalo': 450 , 'New York': 216},
    'Pittsburgh' : {'New York': 370, 'Buffalo': 219, 'Philadelphia' : 304, 'Baltimore' : 248},
    'New York' : {'Boston': 216, 'Pittsburgh': 370, 'Philadelphia' :94},
    'Philadelphia' : {'New York': 94, 'Pittsburgh' : 304, 'Baltimore': 101, 'Salisbury': 138},
    'Baltimore' : {'Philadelphia': 101, 'Pittsburgh' : 248, 'Washington DC': 45, 'Salisbury': 117},
    'Salisbury' : {'Philadelphia': 138, 'Baltimore': 117, 'Washington DC': 116, 'Norfolk': 132},
    'Washington DC' : {'Baltimore': 45, 'Salisbury': 116, 'Richmond': 110},
    'Richmond' : {'Washington DC': 110, 'Norfolk': 93},
    'Norfolk' : {'Richmond': 93, 'Salisbury': 132}
}

'''
startCity = input("Please Input Starting City Name:\n")

while(startCity not in graph):
    startCity = input("Invalid City Please Retype Starting City:\n")

targetCity = input("Please Input Target City Name:\n")

while(targetCity not in graph):
    targetCity = input("Invalid City Please Retype Target City\n")
'''

print(BFS(graph, 'New York', 'Richmond'))
