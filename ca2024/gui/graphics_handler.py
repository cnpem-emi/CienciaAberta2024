import pygame as pg
from .electron import Electron
from .menu import MenuScreen
from ..control_scheme import ControlScheme
from ..esp_serial import ComPort

class GraphicalViewHandler(Electron, MenuScreen, ControlScheme):
    def __init__(self, width: int, heigth: int, time_limit: int):
        super().__init__()

        self.WHITE = (255, 255, 255)
        
        # Size of the screen
        self.width = width
        self.heigth = heigth

        # Main loop attributes
        self.running = True
        self.time_limit = time_limit
        self.initial_velocity = 0
        self.initial_points = 0
        self.game_section = 2

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

        self.start_ticks = pg.time.get_ticks() # Initialize the countdown timer

        # USB conection control
        #usb = ComPort()
        #usb.config_serial()

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

            self.screen.fill("black")

            #######################
            # PUT EVERYTHING HERE #
            #######################
            control = self.control_selection(self.game_section)

            if self.game_section == 0:
                if control == None:
                    control = self.last_control_state
                self.selection_menu(control)
            elif self.game_section == 1:
                self.team_name_menu()
            elif self.game_section == 2:
                points = 0
                speed = 0
                pos_x, pos_y = self.electron_movement()
                #speed, points = usb.read_serial()
                #self.radiation(pos_x, pos_y)
                self.get_points(points)
                self.get_velocity(speed)
                self.draw_electron(pos_x, pos_y)
                self.countdown()

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

        return self.screen.blit(text, text_rect)
    
    def get_velocity(self, velocity):
        """
            Shows the particle velocity on screen.
        """

        position = (self.width/2, 4*self.heigth/5)

        # Calculate the velocity

        #velocity = self.initial_velocity # Dummy variable
        velocity = str(round(velocity, 1)) + " m/s"

        self.font = pg.font.Font("ca2024/gui/fonts/ARCADEPI.TTF", 40)
        text = self.font.render(velocity, True, self.WHITE)
        text_rect = text.get_rect()
        text_rect.center = position

        return self.screen.blit(text, text_rect)

    def get_points(self, points):
        """
            Shows the team points on screen.
        """

        position = (5*self.width/6, self.heigth/5)

        # Calculate the points

        #points = self.initial_points # Dummy variable
        points = str(points) + " PTS"

        self.font = pg.font.Font("ca2024/gui/fonts/ARCADEPI.TTF", 30)
        text = self.font.render(points, True, self.WHITE)
        text_rect = text.get_rect()
        text_rect.center = position

        return self.screen.blit(text, text_rect)
