import pygame as pg
from numpy import linspace, pi, sin, deg2rad

class Photon:
    def __init__(self, screen, width: int, heigth: int, y_offset: int=0):
        super().__init__()
        self.beginning = True
        self.end = False

        self.screen = screen
        self.width = width
        self.heigth = heigth
        
        self.index_p = 0
        self.photon_x = self.width/2
        self.photon_y = 0
        self.photon_position_y = linspace(-pi/2, pi/2, 10)
        self.random_y = y_offset
    
    def draw_photon(self, inverse: bool=False):
        """
            Draws photons emmited by the electron when the speed is increased.
                inverse = True: photon_x < 1
                inverse = False: photon_x > 1
        """
        

        self.photon_x, pos_y = self.photon_movement(inverse)
        PHOTON_COLOR = (245, 184, 71)
        photon_position = (self.photon_x, pos_y)
        gamma_img = pg.image.load('ca2024/gui/img/gamma.png').convert()
        
        scale = 0.12
        img_size = gamma_img.get_size()
        img_size = (img_size[0]*scale, img_size[1]*scale)
        gamma_img = pg.transform.scale(gamma_img, img_size)

        gamma_rect = gamma_img.get_rect()
        gamma_rect.center = photon_position

        return pg.draw.circle(self.screen, PHOTON_COLOR, photon_position, 20), self.screen.blit(gamma_img, gamma_rect)

    def photon_movement(self, inverse: bool=False):
        """
            Defines the way that the photons move.
        """

        pos_y = self.heigth/2

        pos_y += 10*self.photon_position_y[self.index_p] + self.photon_y

        if self.beginning == True:
            self.index_p += 1
        if self.index_p >= self.photon_position_y.size:
            self.beginning = False
            self.end = True
        if self.end == True:
            self.index_p -= 1
        if self.index_p == 0:
            self.beginning = True
            self.end = False

        if inverse == False:
            self.photon_x += 4
        else:
            self.photon_x -= 4
        
        self.photon_y += self.random_y

        return self.photon_x, float(pos_y)
