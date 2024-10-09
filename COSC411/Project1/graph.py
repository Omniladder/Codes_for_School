
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
    nodesChecked = 0

    while(cityQueue):
        currentCity = cityQueue.pop(0)

        for city in list(graph[currentCity].keys()):
            nodesChecked += 1
            if city not in visitedSet:
                cityQueue.append(city)
                visitedSet.add(city)
                parents[city] = currentCity
            
            if city is targetCity:
                print("BFS Number of Nodes Checked: ", nodesChecked)
                return trackBack(parents, startCity, targetCity)


    
def DFS(graph, startCity, targetCity):
   
    cityStack = []
    cityStack.append(startCity)

    visitedSet = set()
    visitedSet.add(startCity)

    parents = {}
    nodesChecked = 0

    while(cityStack):
        currentCity = cityStack.pop()

        for city in list(graph[currentCity].keys()):
            nodesChecked += 1
            if city not in visitedSet:
                cityStack.append(city)
                visitedSet.add(city)
                parents[city] = currentCity
            
            if city is targetCity:
                print("DFS Number of Nodes Checked: ", nodesChecked)
                return trackBack(parents, startCity, targetCity)
    
from queue import PriorityQueue
def UFS(graph, startCity, targetCity):
   
    cityPQ = PriorityQueue()
    cityPQ.put((0,startCity))

    visitedSet = set()
    visitedSet.add(startCity)

    parents = {}
    nodesChecked = 0

    while(cityPQ):
        cost, currentCity = cityPQ.get()

        for city in list(graph[currentCity].keys()):
            nodesChecked += 1
            if city not in visitedSet:
                cityPQ.put((graph[currentCity][city] ,city))
                visitedSet.add(city)
                parents[city] = currentCity
            
            if city is targetCity:
                print("UFS Number of Nodes Checked: ", nodesChecked)
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


cities = {'Buffalo':'Buffalo', 'Boston':'Boston', 'Pittsburgh':'Pittsburgh', 'New York':'New York', 'Philadelphia':'Philadelphia', 'Baltimore': 'Baltimore', 'Salisbury' : 'Salisbury', 'Washington DC' : 'Washington DC', 'Richmond' : 'Richmond', 'Norfolk' : 'Norfolk'}

inputStartCity = str(input("Please Input Starting City Name:\n"))

while(inputStartCity not in graph):
    inputStartCity = str(input("Invalid City Please Retype Starting City:\n"))

inputTargetCity = str(input("Please Input Target City Name:\n"))

while(inputTargetCity not in graph):
    inputTargetCity = str(input("Invalid City Please Retype Target City\n"))

inputStartCity = inputStartCity.strip()
inputTargetCity = inputTargetCity.strip()


#'''

#IDK WHY THIS WORKS BUT IF I REMOVE IT IT BREAKS AND IM TOO SCARED TO TOUCH IT
startCity = cities[inputStartCity]
targetCity = cities[inputTargetCity]

'''
startCity = 'New York'
targetCity = 'Richmond'

print(startCity == inputStartCity)
print(targetCity == inputTargetCity)
'''
print('\n')


shortestPath = BFS(graph, startCity, targetCity)
distance = 0
for i in range(len(shortestPath) - 1):
    distance += graph[shortestPath[i]][shortestPath[i+1]]

print(f"Shortest Path Distance : {distance} \nShortest Path: ", shortestPath)

print('\n')

DFSPATH = DFS(graph, startCity, targetCity)
distance = 0
for i in range(len(DFSPATH) - 1):
    distance += graph[DFSPATH[i]][DFSPATH[i+1]]

print(f"Depth First Search Distance : {distance} \nDFS Path: ", DFSPATH)

print('\n')

UFSPATH = UFS(graph, startCity, targetCity)
distance = 0
for i in range(len(UFSPATH) - 1):
    distance += graph[UFSPATH[i]][UFSPATH[i+1]]

print(f"Uniform Cost Search Distance : {distance} \nUFS Path: ", UFSPATH)
#'''