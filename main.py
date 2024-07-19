from ca2024.gui.graphics_handler import GraphicalViewHandler

WIDTH = 1024
HEIGTH = 768
match_time = 60

main_window = GraphicalViewHandler(WIDTH, HEIGTH, match_time)

if __name__ == "__main__":
    main_window.loop()
