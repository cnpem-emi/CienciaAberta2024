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

    def draw_photon(self, speed: float, pos_x: float, pos_y:float):
        """
            Draws photons emmited by the electron when the speed is increased.
        """
        
        PHOTON_COLOR = (245, 184, 71)
        photon_position = (pos_x+100, pos_y+100)
        gamma_img = pg.image.load('ca2024/gui/img/gamma.png').convert()
        
        scale = 0.12
        img_size = gamma_img.get_size()
        img_size = (img_size[0]*scale, img_size[1]*scale)
        gamma_img = pg.transform.scale(gamma_img, img_size)

        gamma_rect = gamma_img.get_rect()
        gamma_rect.center = photon_position

        return pg.draw.circle(self.screen, PHOTON_COLOR, photon_position, 20), self.screen.blit(gamma_img, gamma_rect)

    def photon_movement(self):
        """
            Defines the way that the photons move.
        """

        pass