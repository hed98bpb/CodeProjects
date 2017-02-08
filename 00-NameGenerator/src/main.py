from random import *
from tkinter import *
from tkinter import messagebox

boysNameArray = []
girlsNameArray = []
surnameArray = []


def main():
    generateNames()

    top = Tk(screenName="Name generator")
    top.minsize(width=200, height=100)

    var = IntVar()
    var.set(0)

    boys = Radiobutton(top, text="boys", variable=var, value=0)
    boys.pack()

    girls = Radiobutton(top, text="girls", variable=var, value=1)
    girls.pack()

    nameButton = Button(top, text="generate name", command=lambda: printNameInDialog(var))
    nameButton.pack()

    top.mainloop()


def printNameInDialog(category):

    if category.get() == 0:
        messagebox.showinfo("Generated Name", boysNameArray[randrange(0, len(boysNameArray))] +
                            " " + surnameArray[randrange(0, len(surnameArray))])
    elif category.get() == 1:
        messagebox.showinfo("Generated Name", girlsNameArray[randrange(0, len(girlsNameArray))] +
                            " " + surnameArray[randrange(0, len(surnameArray))])


def generateNames():
    array = boysNameArray

    with open('NameList', 'r') as nameList:
        for name in nameList:
            if name != "=\n":
                array.append(name[:-1])
            elif array == boysNameArray:
                array = girlsNameArray
            elif array == girlsNameArray:
                array = surnameArray


if __name__ == "__main__":
    main()
