import pygame as pg
from numpy import linspace, pi, sin

class Electron:
    def __init__(self):
        # Electron movement variables
        self.index = 0
        self.electron_position = linspace(-pi/2, pi/2, 60)
        self.beginning = True
        self.end = False

        self.speed = 0
        self.points = 0
        self.max_speed = 0

    def draw_electron(self, pos_x: int=0, pos_y: int=0):
        """
            Draws an electron on screen.
        """
        
        self.font = pg.font.Font("ca2024/gui/fonts/ARCADEPI.TTF", 30)
        ELECTRON_COLOR = (100, 100, 255)
        #position = (self.width/2, self.heigth/2)
        position = (pos_x, pos_y)
        
        text = self.font.render("e-", True, self.WHITE)
        text_rect = text.get_rect()
        text_rect.center = position
    
        return pg.draw.circle(self.screen, ELECTRON_COLOR, position, 30), self.screen.blit(text, text_rect)

    def electron_movement(self) -> int:
        """
            Makes the electron move for a few pixels.
        """

        pos_x = self.width/2
        pos_y = self.heigth/2

        pos_y += 10*self.electron_position[self.index]

        if self.beginning == True:
            self.index += 1
        if self.index >= self.electron_position.size:
            self.beginning = False
            self.end = True
        if self.end == True:
            self.index -= 1
        if self.index == 0:
            self.beginning = True
            self.end = False

        return pos_x, pos_y

    def radiation(self, pos_x, pos_y):
        """
            Makes a cloud of light appear around the electron.
        """
        
        pg.draw.circle(self.screen, (255, 40, 40), (pos_x, pos_y), 50)

    def max_speed(self, speed):
        """
            Gets the maximum speed achieved on the match.
        """

        if speed >= self.max_speed:
            self.max_speed = speed

