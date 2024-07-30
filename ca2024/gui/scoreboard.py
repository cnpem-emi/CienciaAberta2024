import pygame as pg
from ..data_io import DataIO
                                                                                                                       
class ScoreBoard(DataIO):
    def show_score(self):
        """
            Shows the scoreboard screen.
        """
        
        self.font = pg.font.Font("ca2024/gui/fonts/ARCADEPI.TTF", 50)
        position_scoreboard_text = (self.width/2, self.heigth/8)

        scoreboard_text = self.font.render(self.scoreboard_text, True, self.WHITE)

        scoreboard_text_rect = scoreboard_text.get_rect()
        scoreboard_text_rect.center = position_scoreboard_text

        return self.screen.blit(scoreboard_text, scoreboard_text_rect), self.load_score()

    def write_score(self, team_name: str, max_speed: float, points: int):
        """
            Write the match score in the CSV file.
            @TODO Create a team name with a random number if no name is inserted.
        """
        
        if not team_name.strip():
            data = self.read_file()
            team_number = str(len(data))

            team_name = f"Equipe {team_number}\n"

        row = [team_name.upper(), round(float(max_speed), 2), int(points)]
        
        return self.write_file(row)

    def load_score(self):
        """
            Reads the score points from the CSV file.
        """

        score = self.read_file()
        score = list(filter(None, score))
        ordered_score = self._order_score(score[1:])

        heigth = self.heigth/3
        for row in ordered_score:
            if heigth > self.heigth/1.1:
                break

            self.speed_text = row[1] + " m/s"

            self.name_text = row[0]
            self.points_text = row[2]

            position_t_name_text = (self.width/7, heigth)
            position_t_speed_text = (self.width/2, heigth)
            position_t_points_text = (self.width/1.2, heigth)

            name_text = self.font.render(self.name_text[:-1].upper(), True, self.WHITE)
            speed_text = self.font.render(self.speed_text, True, self.WHITE)
            points_text = self.font.render(self.points_text, True, self.WHITE)

            name_text_rect = name_text.get_rect()
            name_text_rect.center = position_t_name_text
            speed_text_rect = speed_text.get_rect()
            speed_text_rect.center = position_t_speed_text
            points_text_rect = points_text.get_rect()
            points_text_rect.center = position_t_points_text

            heigth += self.heigth/9

            self.screen.blit(name_text, name_text_rect), self.screen.blit(speed_text, speed_text_rect), self.screen.blit(points_text, points_text_rect)

    def _order_score(self, score: list) -> list:
        """
            Orders the score list by points.
        """
        
        return sorted(score, key=lambda x: int(x[-1]), reverse=True)

