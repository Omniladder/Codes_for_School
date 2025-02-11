#Imports
import sys
import math as m
import random as r
from PyQt5.QtGui import QPainter, QPen, QBrush, QColor, QFont
from PyQt5.QtWidgets import QWidget, QApplication, QDesktopWidget, QLabel
from PyQt5.QtCore import Qt, QRect, QPoint


#Class Object Declaration
class gameBoard(QWidget):
    #Generates Game Board
    def __init__(self, gridWidth) -> None:
        super().__init__()

        #Generates GameBoard
        self.gameGrid = [i+1 for i in range(gridWidth**2 - 1)] #We want to do a square because thats the shape of the game
        self.gameGrid.append(-1)

        #Gets Screen size for object size purposes
        self.windowSize = self.size()
        self.width = self.windowSize.width()
        self.height = self.windowSize.height()

        #Sets Geometry Window
        self.setGeometry(0, 0, self.height, self.height)

        #Sets Title of Game
        self.setWindowTitle('Fifteen Puzzle Game')

        #Sets Various needed variables for game such as the games move count and the amount of cells wide the board is
        self.gridWidth = gridWidth
        self.moves = 0

        #Shuffles Board to Random Solveable State
        self.shuffle()
        while(not self.isSolveable() and not self.isSolved()):
            self.shuffle()


        #Draws Grid
        self.show()


    def mousePressEvent(self, event):
    
        if(self.isSolved()):
            return

        #gets X and Y positions of click
        x = event.x()
        y = event.y()


        #Gets Cell Index
        index = int((x - self.gridStartX) / self.cellSize) + self.cellWidth * int((y - self.gridStartY) / self.cellSize )
        
        self.swapCell(index)


        self.update()
        return

    def isSolved(self):
        if self.gameGrid[len(self.gameGrid) - 1] == -1 and sorted(self.gameGrid[:-1]) == self.gameGrid[:-1]:
            return True
        else:
            return False

    #Swaps Index Wanted with Cell clicked on
    def swapCell(self, cellIndex):

        #Gets Index of empty cell to swap with
        emptyIndex = self.gameGrid.index(-1)
        
        if (int(emptyIndex / self.gridWidth) == int(cellIndex / self.gridWidth) ):
            self.gameGrid.pop(emptyIndex)
            self.gameGrid.insert(cellIndex, -1)
            self.moves += abs(cellIndex - emptyIndex)
        elif (int(emptyIndex % self.gridWidth) == int(cellIndex % self.gridWidth)):
            for i in range(emptyIndex, cellIndex + 2 * (emptyIndex < cellIndex) - 1, self.gridWidth *( 2 * (emptyIndex < cellIndex) - 1)):
                self.gameGrid[emptyIndex] = self.gameGrid[i]
                self.gameGrid[i] = -1
                emptyIndex = i
                self.moves += 1
            self.moves -= 1 #Because we dont count moving empty cell
    
    
    def isSolveable(self):
        
        #Keeps track of number of inversions
        inversions = 0

        #Gets Empty index to determine row
        emptyIndex = self.gameGrid.index(-1)

        #Gets row that is empty counting from the bottom
        emptyRow = self.gridWidth - int(emptyIndex / self.gridWidth) - 1

        #Counts Number of Inversion
        for index in range(len(self.gameGrid)):
            for testIndex in range(index + 1, len(self.gameGrid)):
                if(self.gameGrid[testIndex] > self.gameGrid[index] and index != emptyIndex and testIndex + index != emptyIndex):
                    inversions += 1


        if (inversions % 2 == 0 and self.gridWidth % 2 == 1):
            return True
        elif (inversions % 2 == 1 and emptyRow % 2 == 0 and self.gridWidth % 2 == 0):
            return True
        elif (inversions % 2 == 0 and emptyRow % 2 == 1 and self.gridWidth % 2 == 0):
            return True

        return False

        



        

    def shuffle(self):
        unusedIndexes = [i+1 for i in range(self.gridWidth**2 - 1)] #We want to do a square because thats the shape of the game
        unusedIndexes.append(-1)

        for i in range(len(self.gameGrid)):
            randomNum = r.randint(0,len(unusedIndexes) - 1)
            self.gameGrid[i] = unusedIndexes[randomNum]
            unusedIndexes.pop(randomNum)


    #puts the game grid onto the screen
    def paintEvent(self, event):
        
        #Gets Window size for sizing purposes
        self.windowSize = self.size()
        self.width = self.windowSize.width()
        self.height = self.windowSize.height()
        
        #Intializes Starts the Painter
        painter = QPainter()
        painter.begin(self)

        #Sets starting indexes for game board
        self.gridStartX = int(self.width / 2 - (self.height - 100) / 2)
        self.gridStartY = 75

        #Sets Proper size for gameboard and Cells
        self.boardSize = self.height - 100
        self.cellSize = int(self.boardSize // self.gridWidth)

        #Number of cells in  one row of board
        self.cellWidth = int(self.boardSize // self.cellSize)

        #Draws Dynaimcally Changing sized Board
        painter.fillRect(self.gridStartX, self.gridStartY, self.boardSize, self.boardSize, QColor(100, 100, 110))

        #Draws each of square
        for index, indexNumber in enumerate(self.gameGrid):
            if(indexNumber != -1):
                #Draws Square
                painter.fillRect(self.gridStartX + self.cellSize * (index % self.cellWidth), self.gridStartY + self.cellSize * int(index / self.cellWidth) , self.cellSize - 3, self.cellSize - 3, QColor(100, 100, 210))
                

                fontSize = 65
                #Adds Number to square
                painter.setFont(QFont('Arial', fontSize, QFont.Bold))
                #painter.setBold(True)
                painter.drawText(self.gridStartX + self.cellSize * (index % self.cellWidth) + int(self.cellSize / 2 - fontSize / 2) , self.gridStartY + self.cellSize * int(index / self.cellWidth) + int(self.cellSize / 2 + fontSize / 2),str(indexNumber))


        if(self.isSolved()):
            painter.setPen(QColor(0,150,0))
            painter.drawText(int(self.width / 2) - int(fontSize / 2) * len("YOU WIN!!!"),fontSize + 8,"YOU WIN!!!")
            print(self.moves)

        painter.setPen(QColor(0,0,0))
        painter.setFont(QFont('Arial', 25, QFont.Bold))
        painter.drawText(int(self.width / 2 * 1.5),fontSize + 8,f"Moves: {self.moves}")

        #Closes things up
        painter.end()

    #New Generate Function that resizes screen to what I want
    def show(self) -> None:
        
        super().show()
        self.resize(800,800)
        self.__x = -135
        self.__y = -1
        super().show()
        



if __name__ == '__main__':
    #Generates Application Object
    app = QApplication(sys.argv)

    #Initializes Game board and Displays
    game = gameBoard(gridWidth=4)
    game.show()

    
    #closes Application
    sys.exit(app.exec_())
