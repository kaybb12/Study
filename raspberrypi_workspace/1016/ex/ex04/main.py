# This Python file uses the following encoding: utf-8
# import sys
# from PySide6.QtWidgets import QApplication

if __name__ == "__main__":
    arr = [3, 3, 2, 6, 2]
    bucket = [0] * 7
    for a in arr:
        bucket[a] += 1

    for i in range(len(bucket)):
        print(i,":",bucket[i],"개")

    while(True):
        pass;


