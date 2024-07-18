import pygame as pg

class ControlScheme:
    def control_selection(self):
        """
            Selects the apropriate control for the game section.
        """
        
        pass

    def selection_menu_control(self) -> int:
        """
            Set the control scheme for the selection menu screen.
        """

        key = pg.key.get_pressed()

        if key[pg.K_UP]:
            return 1
        if key[pg.K_DOWN]:
            return 2
        if key[pg.K_RETURN]:
            # Call game window
            print("Init game!")

    def game_control(self):
        key = pg.key.get_pressed()

        if key[pg.key.K_ESCAPE]:
            # Go back to selection menu
            pass


    def end_game_control(self):
        """
            Set the control scheme for the game screen.
        """
        
        pass
