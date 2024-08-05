import pygame as pg
from time import sleep

class ControlScheme:
    def __init__(self):
        self.mode = 0

    def control_selection(self, game_section: int):
        """
            Selects the apropriate control settings for the game section.
                game_section = 0: selection menu
                game_section = 1: insert team name
                game_section = 2: game running
                game_section = 3: scoreboard
        """
        
        match game_section:
            case 0:
                return self.selection_menu_control()
            case 1:
                return self.input_text_control()
            case 2 | 3:
                return self.game_control()

    def selection_menu_control(self) -> int:
        """
            Set the control scheme for the selection menu screen.
        """

        key = pg.key.get_pressed()

        if key[pg.K_UP]:
            self.mode = 1
            return 1
        if key[pg.K_DOWN]:
            self.mode = 2
            return 2
        if key[pg.K_RETURN]:
            # Send bit to microcontroller to select operation mode based on the position of the cursor
            if self.mode == 1:
                # Send bit to ESP32
                #self.select_mode(1)
                self.team_name = "AUTO\n"
                self.game_section = 2
            elif self.mode == 2:
                # Send bit to ESP32
                #self.select_mode(2)
                self.game_section = 1
            sleep(0.1)
        if key[pg.K_ESCAPE]:
            pg.quit()

    def game_control(self):
        """
            Set the in-game control scheme.
        """
        
        key = pg.key.get_pressed()

        if key[pg.K_ESCAPE]:
            # Go back to selection menu
            self.mode = 0
            self.game_section = 0 # Return to main menu
            self.team_name = ''
            sleep(0.5)

    def input_text_control(self) -> str:
        """
            Controls keyboard typing and resturns the string typed.
        """

        self.enalbe_keyboard = True        
        key = pg.key.get_pressed()

        if key[pg.K_RETURN]:
            self.enalbe_keyboard = False
            print(self.team_name)
            self.game_section = 2 # Run game
            self.start_ticks = pg.time.get_ticks()
        if key[pg.K_BACKSPACE]:
            self.team_name = self.team_name[:-1] # Delete last character
            sleep(0.05)
        if key[pg.K_ESCAPE]:
            self.mode = 0
            self.game_section = 0 # Return to main menu
            sleep(0.5)
