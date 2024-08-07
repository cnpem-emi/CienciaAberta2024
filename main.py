from ca2024.gui.graphics_handler import GraphicalViewHandler

WIDTH = 1280
HEIGTH = 720
match_time = 30

main_window = GraphicalViewHandler(WIDTH, HEIGTH, match_time)

if __name__ == "__main__":
    main_window.loop()
