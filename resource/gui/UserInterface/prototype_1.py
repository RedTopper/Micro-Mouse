# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'C:\Users\Tyler\PycharmProjects\Senior_Design\UI\proto_1.ui'
#
# Created by: PyQt5 UI code generator 5.13.2
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MicroMouse(object):
    def setupUi(self, MicroMouse):
        MicroMouse.setObjectName("MicroMouse")
        MicroMouse.resize(700, 600)
        self.centralwidget = QtWidgets.QWidget(MicroMouse)
        self.centralwidget.setObjectName("centralwidget")
        self.imageLabel = QtWidgets.QLabel(self.centralwidget)
        self.imageLabel.setGeometry(QtCore.QRect(20, 100, 271, 271))
        self.imageLabel.setFrameShape(QtWidgets.QFrame.Box)
        self.imageLabel.setLineWidth(2)
        self.imageLabel.setText("")
        self.imageLabel.setObjectName("imageLabel")
        self.label_2 = QtWidgets.QLabel(self.centralwidget)
        self.label_2.setGeometry(QtCore.QRect(320, 90, 181, 71))
        font = QtGui.QFont()
        font.setPointSize(16)
        self.label_2.setFont(font)
        self.label_2.setTextFormat(QtCore.Qt.AutoText)
        self.label_2.setObjectName("label_2")
        self.beginMaze = QtWidgets.QPushButton(self.centralwidget)
        self.beginMaze.setGeometry(QtCore.QRect(340, 230, 151, 51))
        self.beginMaze.setObjectName("beginMaze")
        self.logs = QtWidgets.QPushButton(self.centralwidget)
        self.logs.setGeometry(QtCore.QRect(340, 290, 151, 51))
        self.logs.setObjectName("logs")
        self.label_3 = QtWidgets.QLabel(self.centralwidget)
        self.label_3.setGeometry(QtCore.QRect(360, 140, 201, 71))
        font = QtGui.QFont()
        font.setPointSize(16)
        self.label_3.setFont(font)
        self.label_3.setObjectName("label_3")
        MicroMouse.setCentralWidget(self.centralwidget)
        self.statusbar = QtWidgets.QStatusBar(MicroMouse)
        self.statusbar.setObjectName("statusbar")
        MicroMouse.setStatusBar(self.statusbar)
        self.menubar = QtWidgets.QMenuBar(MicroMouse)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 543, 21))
        self.menubar.setObjectName("menubar")
        self.menuMicro_Mouse = QtWidgets.QMenu(self.menubar)
        self.menuMicro_Mouse.setObjectName("menuMicro_Mouse")
        self.menuMaze = QtWidgets.QMenu(self.menubar)
        self.menuMaze.setObjectName("menuMaze")
        MicroMouse.setMenuBar(self.menubar)
        self.menuMaze.addSeparator()
        self.setImage()
        self.setImage1()
        self.menubar.addAction(self.menuMicro_Mouse.menuAction())
        self.menubar.addAction(self.menuMaze.menuAction())

        self.retranslateUi(MicroMouse)
        QtCore.QMetaObject.connectSlotsByName(MicroMouse)

    def retranslateUi(self, MicroMouse):
        _translate = QtCore.QCoreApplication.translate
        MicroMouse.setWindowTitle(_translate("MicroMouse", "MainWindow"))
        self.label_2.setText(_translate("MicroMouse", "Welcome to"))
        self.beginMaze.setText(_translate("MicroMouse", "Begin Maze"))
        self.logs.setText(_translate("MicroMouse", "Logs"))
        self.label_3.setText(_translate("MicroMouse", "Micro Mouse"))
        self.menuMicro_Mouse.setTitle(_translate("MicroMouse", "Micro Mouse"))
        self.menuMaze.setTitle(_translate("MicroMouse", "Maze"))


    def setImage(self):
        pixmap = QtGui.QPixmap("Maze.png")
        pixmap = pixmap.scaled(self.imageLabel.width(), self.imageLabel.height() , QtCore.Qt.KeepAspectRatio)
        self.imageLabel.setPixmap(pixmap)
        self.imageLabel.setAlignment(QtCore.Qt.AlignCenter)


    def setImage1(self):
        pixmap = QtGui.QPixmap("Arrows.png")
        pixmap = pixmap.scaled(self.imageLabel.width(), self.imageLabel.height(), QtCore.Qt.KeepAspectRatio)
        self.imageLabel.setPixmap(pixmap)
        self.imageLabel.setAlignment(QtCore.Qt.AlignCenter)


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MicroMouse = QtWidgets.QMainWindow()
    ui = Ui_MicroMouse()
    ui.setupUi(MicroMouse)
    MicroMouse.show()
    sys.exit(app.exec_())
