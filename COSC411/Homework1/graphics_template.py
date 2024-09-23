import sys
from PyQt5.QtGui import QPainter, QPen, QBrush
from PyQt5.QtWidgets import QWidget, QApplication
from PyQt5.QtCore import Qt, QRect, QPoint


class Face(QWidget):

  def __init__(self):
    super().__init__()
    self.setGeometry(50, 50, 500, 500)
    self.setWindowTitle('Face')
    self.show()
    self.__x = -1
    self.__y = -1
    self.show()

  def paintEvent(self, event):
    qp = QPainter()
    qp.begin(self)
    
    #eye sockets
    qp.drawEllipse(100,100,100,100)
    qp.drawEllipse(300,100,100,100)
    
    #Mouth
    qp.setPen(QPen(Qt.red, 8))
    qp.drawLine(150,300,250,400)
    qp.drawLine(350,300,250,400)
    
    #Nose
    qp.setPen(QPen(Qt.blue, 1))
    qp.setBrush(Qt.blue)
    qp.drawPolygon(QPoint(250,175),QPoint(200,275),QPoint(300,275))
    
    #Draw Eye balls
    qp.setPen(QPen(Qt.black, 5))
    qp.setBrush(Qt.black)
    
    #Show coordinates of the the click
    clicktext = 'No Click Yet'
    
    
    
    qp.end()

  def mousePressEvent(self, event):
    pass

if __name__ == '__main__':
  app = QApplication(sys.argv)
  ex = Face()
  sys.exit(app.exec_())
