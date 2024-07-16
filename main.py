from ca2024.gui.window import MainWindow

WIDTH = 800
HEIGTH = 600
match_time = 60

main_window = MainWindow(WIDTH, HEIGTH, match_time)

if __name__ == "__main__":
    main_window.loop()
