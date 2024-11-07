import time
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
    'A' : {'B': 9, 'C': 6, 'D' : 8},
    'B' : {'F': 4},
    'C' : {'E': 6, 'G': 7},
    'D' : {'E' : 6},
    'E' : {'H': 7},
    'F' : {'G' : 10},
    'G' : {'H' : 5},
    'H' : {}
}




start = time.perf_counter()
shortestPath = BFS(graph, 'A', 'H')
distance = 0
for i in range(len(shortestPath) - 1):
    distance += graph[shortestPath[i]][shortestPath[i+1]]

print(f"Shortest Path Distance : {distance} \nShortest Path: ", shortestPath)

end = time.perf_counter()

print("BFS Search Time is", -1 * (start - end))

print('\n')

start = time.perf_counter()

DFSPATH = DFS(graph, 'A', 'H')
distance = 0
for i in range(len(DFSPATH) - 1):
    distance += graph[DFSPATH[i]][DFSPATH[i+1]]

print(f"Depth First Search Distance : {distance} \nDFS Path: ", DFSPATH)

end = time.perf_counter()
print("BFS Search Time is", -1 * (start - end))
print('\n')

start = time.perf_counter()

UFSPATH = UFS(graph, 'A', 'H')
distance = 0
for i in range(len(UFSPATH) - 1):
    distance += graph[UFSPATH[i]][UFSPATH[i+1]]

print(f"Uniform Cost Search Distance : {distance} \nUFS Path: ", UFSPATH)

end = time.perf_counter()
print("BFS Search Time is", -1 * (start - end))
#'''