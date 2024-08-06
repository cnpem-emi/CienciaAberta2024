import pygame as pg
from time import sleep
from random import randint
from .electron import Electron
from .photon import Photon
from .menu import MenuScreen
from .scoreboard import ScoreBoard
from ..control_scheme import ControlScheme
from ..esp_serial import ComPort

class GraphicalViewHandler(Electron, MenuScreen, ScoreBoard, ControlScheme):
    def __init__(self, width: int, heigth: int, time_limit: int):
        super().__init__()

        self.WHITE = (255, 255, 255)
        
        # Size of the screen
        self.width = width
        self.heigth = heigth

        # Main loop attributes
        self.running = True
        self.time_limit = time_limit
        self.speed = 0
        self.points = 0
        self.game_section = 0
        self.game_mode = 0

        pg.init()
        pg.display.set_caption("Ciência Aberta 2024") # Window Name

        # Add pg.FULLSCREEN later
        self.screen = pg.display.set_mode((self.width, self.heigth))
        self.clock = pg.time.Clock()
        self.font = pg.font.Font("ca2024/gui/fonts/ARCADEPI.TTF", 30)

        # Selection Menu parameters
        self.title_text = "ACELERADOR MAGNETICO"
        self.auto_mode_t = "MODO AUTOMATICO"
        self.manual_mode_t = "MODO MANUAL"
        self.last_control_state = 1 # Menu position (1 or 2)

        self.section_text = "DIGITE O NOME DO TIME:"
        self.enalbe_keyboard = False
        self.team_name = ''

        self.scoreboard_text = "PONTUACAO"
        self.score_text = ''

        # Photons
        self.photon_list = []

        self.start_ticks = pg.time.get_ticks() # Initialize the countdown timer

        # USB conection control
        self.usb = ComPort()
        self.usb.config_serial()

    def loop(self):
        """
            Main window loop.
        """

        while self.running:
            for event in pg.event.get():
                if event.type == pg.QUIT:
                    self.running = False
                elif event.type == pg.KEYDOWN and self.enalbe_keyboard == True:
                    self.team_name += event.unicode
                    sleep(0.01)

            self.screen.fill("black")

            #######################
            # PUT EVERYTHING HERE #
            #######################
            control = self.control_selection(self.game_section)

            # Main menu
            if self.game_section == 0:
                self.photon_list = []
                if control == None:
                    control = self.last_control_state
                self.selection_menu(control)

            # Team name input menu
            elif self.game_section == 1:
                self.team_name_menu()

            # Game running
            elif self.game_section == 2:
                self.speed = self.usb.read_serial()
                self.get_points(self.speed)
                self.get_velocity(self.speed)
                electron_x, electron_y = self.electron_movement(self.speed)
                self.draw_electron(electron_x, electron_y)

                # Draw photons as the electron's speed increase
                self.show_photons(self.speed)

                for p_index in range(len(self.photon_list)):
                    self.photon_list[p_index].draw_photon()

                self.photon_list = [photon for photon in self.photon_list if 
                    not (photon.photon_x >= self.width or 
                         photon.photon_x <= -self.width or 
                         photon.photon_y >= self.heigth or 
                         photon.photon_y <= -self.heigth)]

                self.countdown()

                # if self.speed < 4:
                #     self.speed += 0.01

            # Scoreboard
            elif self.game_section == 3:
                self.show_score()

            self.last_control_state = control
            #######################

            pg.display.update()
            self.clock.tick(60)
        
        pg.quit()

    def countdown(self):
        """
            Time countdown for the match.
        """

        position = (self.width/2, self.heigth/5)

        seconds = self.time_limit - (pg.time.get_ticks() - self.start_ticks)/1000
        seconds = str(round(seconds, 1))
        
        self.font = pg.font.Font("ca2024/gui/fonts/ARCADEPI.TTF", 50)
        text = self.font.render(seconds, True, self.WHITE)
        text_rect = text.get_rect()
        text_rect.center = position

        if float(seconds) <= 0:
            self.write_score(self.team_name, self.speed, self.points)
            self.game_section = 3
            return self.game_section
        else:
            return self.screen.blit(text, text_rect)
    
    def get_velocity(self, velocity: float):
        """
            Shows the particle velocity on screen.
        """

        position = (self.width/2, 4*self.heigth/5)

        if velocity == None:
            velocity = 0
            
        velocity = str(round(velocity, 1)) + " m/s"

        self.font = pg.font.Font("ca2024/gui/fonts/ARCADEPI.TTF", 40)
        text = self.font.render(velocity, True, self.WHITE)
        text_rect = text.get_rect()
        text_rect.center = position

        return self.screen.blit(text, text_rect)

    def get_points(self, speed: float):
        """
            Shows the team points on screen.
        """

        position = (5*self.width/6, self.heigth/5)

        if speed == None:
            speed = 0

        # Calculate the points
        points = 100*speed
        points = int(points)
        self.points = points

        #points = self.initial_points # Dummy variable
        points = str(points) + " PTS"

        self.font = pg.font.Font("ca2024/gui/fonts/ARCADEPI.TTF", 30)
        text = self.font.render(points, True, self.WHITE)
        text_rect = text.get_rect()
        text_rect.center = position

        return self.points, self.screen.blit(text, text_rect)

    def show_photons(self, speed: float) -> list:
        """
            Instatiate a random number of photons depending on the speed of the electron.
        """
        
        chance_of_showing = randint(1, 50)
        chance_of_showing += round(3*speed)

        if chance_of_showing > 50 and len(self.photon_list) < 30:
            p = Photon(self.screen, self.width, self.heigth)
            self.photon_list.append(p)
            
        return self.photon_list

