import pygame as pg
from numpy import linspace, pi, sin
#from .photon import Photon

class Electron():
    def __init__(self):
        super().__init__()
        # Electron movement variables
        self.index_e = 0
        self.electron_position = linspace(-pi/2, pi/2, 80)
        self.beginning_e = True
        self.end_e = False

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

    def electron_movement(self, speed: float=0) -> int:
        """
            Makes the electron move for a few pixels.
        """

        pos_x = self.width/2
        pos_y = self.heigth/2

        if speed > 5:
            speed = 5
        amplitude = (1+2*speed)*10 # Verify the optimal amplitude
        pos_y += amplitude*self.electron_position[self.index_e]

        if self.beginning_e == True:
            self.index_e += 1
        if self.index_e >= self.electron_position.size:
            self.beginning_e = False
            self.end_e = True
        if self.end_e == True:
            self.index_e -= 1
        if self.index_e == 0:
            self.beginning_e = True
            self.end_e = False

        return pos_x, pos_y

    def max_speed(self, speed: float) -> float:
        """
            Gets the maximum speed achieved on the match.
        """

        if speed >= self.max_speed:
            self.max_speed = speed

        return self.max_speed

    def radiation(self, pos_x: float, pos_y: float):
        """
            Makes a cloud of light appear around the electron.
        """
        
        pg.draw.circle(self.screen, (255, 40, 40), (pos_x, pos_y), 50)
