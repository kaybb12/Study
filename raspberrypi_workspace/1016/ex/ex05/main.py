# This Python file uses the following encoding: utf-8
# import sys
# from PySide6.QtWidgets import QApplication

if __name__ == "__main__":
    while(True):

        dt = {'KFC':10, 'MC':20, 'MOMS':30}
        key = input()
        if (key in dt): print(dt[key])
        else: print(1000)
