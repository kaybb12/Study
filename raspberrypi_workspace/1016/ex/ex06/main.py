# This Python file uses the following encoding: utf-8
# import sys
# from PySide6.QtWidgets import QApplication

if __name__ == "__main__":
    list = ["MC", "BTS", "BTS", "MC", "BTS"]
    dt = dict()
    for i in list:
        dt[str(i)]=0
    for i in list:
        dt[i] += 1
    for key, value in dt.items():
        print(key,":",value,"개")

    while(True):
        pass

