# This Python file uses the following encoding: utf-8
# import sys
# from PySide6.QtWidgets import QApplication

if __name__ == "__main__":
    a = []
    a.append('A')
    a.append('B')
    a.append('150')
    a.append('D')
    a.reverse()
    for i in range(len(a)):
        if i == len(a) - 1:
            print(a[i], end = ' ')
        else:
            print(a[i], end = '-')


