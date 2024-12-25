import tkinter as tk
from tkinter import filedialog

def ouvrir_fichier():
    root = tk.Tk()
    root.withdraw()
    fichier = filedialog.askopenfilename()
    print("Fichier sélectionné:", fichier)

if __name__ == "__main__":
    ouvrir_fichier()
