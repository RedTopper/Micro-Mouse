"""
ZetCode PyQt5 tutorial
"""

import sys
from PyQt5.QtWidgets import *;

if __name__ == '__main__':
    app = QApplication(sys.argv)

    w = QWidget()
    layout = QVBoxLayout()
    layout.addWidget(QPushButton('Turn Left'))
    layout.addWidget(QPushButton('Turn Right'))
    w.setLayout(layout)
    w.resize(250, 150)
    w.move(300, 300)
    w.setWindowTitle('Micro Mouse')
    w.show()

    sys.exit(app.exec_())


def turn_left():
    alert = QMessageBox()
    alert.setText('You Turned left')
    alert.exec()


def turn_right():
    alert = QMessageBox()
    alert.setText('You Turned Right')
    alert.exec()
