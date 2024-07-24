import pygame as pg

class MenuScreen:
    def selection_menu(self, position: int):
        self.menu_screen()
        self.menu_rect(position)

    def menu_screen(self):
        """
            Create the selection menu screen.
        """

        self.screen.fill("black")

        position_title = (self.width/2, self.heigth/5)
        position_auto = (self.width/2, self.heigth/2)
        position_manual = (self.width/2, self.heigth/2 + self.heigth/6)

        self.font = pg.font.Font("ca2024/gui/fonts/ARCADEPI.TTF", 50)

        title_text = self.font.render(self.title_text, True, self.WHITE)
        auto_text = self.font.render(self.auto_mode_t, True, self.WHITE)
        manual_text = self.font.render(self.manual_mode_t, True, self.WHITE)

        auto_text_rect = auto_text.get_rect()
        auto_text_rect.center = position_auto
        
        manual_text_rect = manual_text.get_rect()
        manual_text_rect.center = position_manual
        
        title_text_rect = title_text.get_rect()
        title_text_rect.center = position_title

        return self.screen.blit(title_text, title_text_rect), self.screen.blit(auto_text, auto_text_rect), self.screen.blit(manual_text, manual_text_rect)

    def menu_rect(self, position: int):
        """
            Creates a rectangle to hover the mode selected.
        """

        rect_auto = (self.width/9, 3*self.heigth/7)
        rect_manual = (self.width/5, 3*self.heigth/5)

        position_auto = (7*self.width/9, self.heigth/7)
        position_manual = (9*self.width/15, self.heigth/8)

        match position:
           case 1:
            # Move the rectangle to position 1
            pg.draw.rect(
                self.screen, 
                self.WHITE, 
                pg.Rect(rect_auto, (position_auto)), width=5, border_radius=10)
            
           case 2:
            # Move the rectangle to position 2
            pg.draw.rect(
                self.screen, 
                self.WHITE, 
                pg.Rect(rect_manual, (position_manual)), width=5, border_radius=10)

    def team_name_menu(self):
        """
            Calls a menu with text input to write the team name.
        """
        
        self.game_section = 1

        self.font = pg.font.Font("ca2024/gui/fonts/ARCADEPI.TTF", 50)
        position_section_text = (self.width/2, self.heigth/3)
        position_team_name = (self.width/8, self.heigth/2)

        section_text = self.font.render(self.section_text, True, self.WHITE)

        section_text_rect = section_text.get_rect()
        section_text_rect.center = position_section_text

        if len(self.team_name) <= 19:
            txt_surface = self.font.render(self.team_name.upper(), True, self.WHITE)

            return self.screen.blit(section_text, section_text_rect), self.screen.blit(txt_surface, position_team_name)
        else:
            self.team_name = self.team_name[:-1]
            txt_surface = self.font.render(self.team_name.upper(), True, self.WHITE)

            return self.screen.blit(section_text, section_text_rect), self.screen.blit(txt_surface, position_team_name)
