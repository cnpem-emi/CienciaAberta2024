import pygame as pg

class ControlScheme:
    def control_selection(self, game_section: int):
        """
            Selects the apropriate control for the game section.
                game_section = 0: selection menu
                game_section = 1: insert team name
                game_section = 2: run game
        """
        
        match game_section:
            case 0:
                return self.selection_menu_control()
            case 1:
                return self.input_text_control()
            case 2:
                return self.game_control()

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
        if key[pg.K_ESCAPE]:
            pg.quit()

    def game_control(self):
        """
            Set the in-game control scheme.
        """
        
        key = pg.key.get_pressed()

        if key[pg.K_ESCAPE]:
            # Go back to selection menu
            pass

    def input_text_control(self) -> str:
        """
            Controls keyboard typing and resturns the string typed.
        """

        key = pg.key.get_pressed()

        if key[pg.event.get().unicode]:
            self.team_name += pg.event.get().unicode
        if key[pg.K_RETURN]:
            print(text)
        if key[k_BACKSPACE]:
            self.team_name = self.team_name[:-1]
        if key[pg.K_ESCAPE]:
            pg.quit()

