# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'Senior_Design\UI\MicroMouseGui_1_1.ui'
#
# Created by: PyQt5 UI code generator 5.13.2
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MicroMouse_GUI(object):
    def setupUi(self, MicroMouse_GUI):
        MicroMouse_GUI.setObjectName("MicroMouse_GUI")
        MicroMouse_GUI.resize(790, 670)
        self.central = QtWidgets.QWidget(MicroMouse_GUI)
        self.central.setObjectName("central")
        self.connect = QtWidgets.QPushButton(self.central)
        self.connect.setGeometry(QtCore.QRect(530, 230, 93, 28))
        self.connect.setObjectName("connect")
        self.webAddress = QtWidgets.QTextEdit(self.central)
        self.webAddress.setGeometry(QtCore.QRect(510, 120, 221, 31))
        self.webAddress.setObjectName("webAddress")
        self.label = QtWidgets.QLabel(self.central)
        self.label.setGeometry(QtCore.QRect(570, 90, 101, 21))
        self.label.setObjectName("label")
        self.label_2 = QtWidgets.QLabel(self.central)
        self.label_2.setGeometry(QtCore.QRect(590, 150, 41, 21))
        self.label_2.setObjectName("label_2")
        self.port = QtWidgets.QTextEdit(self.central)
        self.port.setGeometry(QtCore.QRect(510, 180, 221, 31))
        self.port.setObjectName("port")
        self.console = QtWidgets.QTextEdit(self.central)
        self.console.setGeometry(QtCore.QRect(110, 390, 561, 191))
        self.console.setObjectName("console")
        self.manual = QtWidgets.QPushButton(self.central)
        self.manual.setGeometry(QtCore.QRect(530, 270, 93, 28))
        self.manual.setObjectName("manual")
        self.autonomous = QtWidgets.QPushButton(self.central)
        self.autonomous.setGeometry(QtCore.QRect(530, 310, 121, 31))
        self.autonomous.setObjectName("autonomous")
        self.maze = QtWidgets.QGraphicsView(self.central)
        self.maze.setGeometry(QtCore.QRect(40, 30, 451, 321))
        self.maze.setObjectName("maze")
        MicroMouse_GUI.setCentralWidget(self.central)
        self.menubar = QtWidgets.QMenuBar(MicroMouse_GUI)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 790, 26))
        self.menubar.setObjectName("menubar")
        MicroMouse_GUI.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MicroMouse_GUI)
        self.statusbar.setObjectName("statusbar")
        MicroMouse_GUI.setStatusBar(self.statusbar)

        self.retranslateUi(MicroMouse_GUI)
        QtCore.QMetaObject.connectSlotsByName(MicroMouse_GUI)

    def retranslateUi(self, MicroMouse_GUI):
        _translate = QtCore.QCoreApplication.translate
        MicroMouse_GUI.setWindowTitle(_translate("MicroMouse_GUI", "MainWindow"))
        self.connect.setText(_translate("MicroMouse_GUI", "Connect"))
        self.label.setText(_translate("MicroMouse_GUI", "Web Address"))
        self.label_2.setText(_translate("MicroMouse_GUI", "Port"))
        self.manual.setText(_translate("MicroMouse_GUI", "Run Manual"))
        self.autonomous.setText(_translate("MicroMouse_GUI", "Run Autonomous"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MicroMouse_GUI = QtWidgets.QMainWindow()
    ui = Ui_MicroMouse_GUI()
    ui.setupUi(MicroMouse_GUI)
    MicroMouse_GUI.show()
    sys.exit(app.exec_())
