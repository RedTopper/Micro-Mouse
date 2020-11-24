# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'C:\Users\Tyler\PycharmProjects\Senior_Design\UI\proto_2.ui'
#
# Created by: PyQt5 UI code generator 5.13.2
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets
from UserInterface import MouseRequests
import requests
import asyncio


class Ui_MicroMouse(object):
    Mouse = MouseRequests.MouseRequest()


    def setupUi(self, MicroMouse):
        MicroMouse.setObjectName("MicroMouse")
        MicroMouse.resize(558, 593)
        self.centralwidget = QtWidgets.QWidget(MicroMouse)
        self.centralwidget.setObjectName("centralwidget")
        self.imageLabel = QtWidgets.QLabel(self.centralwidget)
        self.imageLabel.setGeometry(QtCore.QRect(30, 100, 271, 271))
        self.imageLabel.setFrameShape(QtWidgets.QFrame.Box)
        self.imageLabel.setLineWidth(2)
        self.imageLabel.setText("")
        self.imageLabel.setObjectName("imageLabel")
        self.label_2 = QtWidgets.QLabel(self.centralwidget)
        self.label_2.setGeometry(QtCore.QRect(150, 20, 181, 71))
        font = QtGui.QFont()
        font.setPointSize(14)
        self.label_2.setFont(font)
        self.label_2.setTextFormat(QtCore.Qt.AutoText)
        self.label_2.setObjectName("label_2")
        self.connectButton = QtWidgets.QPushButton(self.centralwidget)
        self.connectButton.setGeometry(QtCore.QRect(380, 160, 81, 21))
        self.connectButton.setObjectName("connectButton")
        self.label_3 = QtWidgets.QLabel(self.centralwidget)
        self.label_3.setGeometry(QtCore.QRect(300, 20, 201, 71))
        fontSmall = QtGui.QFont()
        fontSmall.setPointSize(10)
        self.label_3.setFont(font)
        self.connectButton.setFont(fontSmall)
        self.label_3.setObjectName("label_3")
        self.ArrowLabel = QtWidgets.QLabel(self.centralwidget)
        self.ArrowLabel.setGeometry(QtCore.QRect(360, 220, 121, 101))
        self.ArrowLabel.setFrameShape(QtWidgets.QFrame.Box)
        self.ArrowLabel.setLineWidth(2)
        self.ArrowLabel.setText("")
        self.ArrowLabel.setObjectName("ArrowLabel")
        self.textEdit = QtWidgets.QTextEdit(self.centralwidget)
        self.textEdit.setGeometry(QtCore.QRect(310, 120, 221, 21))
        self.textEdit.setObjectName("textEdit")
        self.textEdit_2 = QtWidgets.QTextEdit(self.centralwidget)
        self.textEdit.setFont(fontSmall)
        self.textEdit_2.setFont(fontSmall)
        self.textEdit_2.setGeometry(QtCore.QRect(30, 390, 501, 141))
        self.textEdit_2.setObjectName("textEdit_2")
        MicroMouse.setCentralWidget(self.centralwidget)
        self.statusbar = QtWidgets.QStatusBar(MicroMouse)
        self.statusbar.setObjectName("statusbar")
        MicroMouse.setStatusBar(self.statusbar)
        self.menubar = QtWidgets.QMenuBar(MicroMouse)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 558, 21))
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
        self.connectButton.clicked.connect(self.connect)

    def retranslateUi(self, MicroMouse):
        _translate = QtCore.QCoreApplication.translate
        MicroMouse.setWindowTitle(_translate("MicroMouse", "MainWindow"))
        self.label_2.setText(_translate("MicroMouse", "Welcome to"))
        self.connectButton.setText(_translate("MicroMouse", "Connect"))
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
        pixmap = pixmap.scaled(self.ArrowLabel.width(), self.ArrowLabel.height(), QtCore.Qt.KeepAspectRatio)
        self.ArrowLabel.setPixmap(pixmap)
        self.ArrowLabel.setAlignment(QtCore.Qt.AlignCenter)


    def connect(self):
        string = self.textEdit.toPlainText()
        print(string)
        self.Mouse.setUrl(string)
        self.Mouse.MoveRight()
        print('Done')
        # self.textEdit_2.setText("Connecting to " + string)
        # self.textEdit_2.append("Connected to 127.0.0.1")
# http://127.0.0.1:5000/connect


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MicroMouse = QtWidgets.QMainWindow()
    ui = Ui_MicroMouse()
    ui.setupUi(MicroMouse)
    MicroMouse.show()
    sys.exit(app.exec_())
