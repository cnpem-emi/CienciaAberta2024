import csv

class DataIO:
    def read_file(self) -> list:
        """
            Reads the CSV file and returns the obtained data.
        """
        
        data = []

        with open('ca2024/data/score.csv', 'r') as csvfile:
            csvreader = csv.reader(csvfile)
            #fields = next(csvreader)

            for row in csvreader:
                data.append(row)

            csvfile.close()

            return data

    def write_file(self, row: list):
        """
            Writes data on the csv file.
        """
        
        with open('ca2024/data/score.csv', 'a+') as csvfile:
            csvwriter = csv.writer(csvfile)
            csvwriter.writerow(row)

