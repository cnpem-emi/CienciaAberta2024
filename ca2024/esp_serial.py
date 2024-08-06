import serial
import json
from time import sleep

class ComPort:
    def __init__(self):
        self.device = self.get_serial_port()

    def config_serial(self):
        """
            Configures the serial communication with the ESP32.
        """

        data = b'1'
        print("Trying to connect to the ESP32...")
        
        self.device.write(data)
        sleep(0.1)
        while 1:
            if self.device.in_waiting > 0:
                confirmation = self.device.read()
                #response = self.device.readline().decode('utf-8').strip()
                print("Connected!")
                break
            else:
                print("Can't connect to device!")
                sleep(0.1)

    def select_mode(self, mode: int):
        """
            Selects between automatic and manual operation mode.
        """

        self.device.write(mode)
        sleep(0.1)

    def get_serial_port(self):
        """
            Gets the serial port that the device is connected.
        """

        try:
            device = serial.Serial("/dev/ttyUSB0", baudrate=9600)
        except:
            device = serial.Serial("/dev/ttyUSB1", baudrate=9600)
        
        return device
        
    def read_serial(self) -> float:
        """
            Reads the data received from serial port.
        """

        message = self.device.readline() #.decode('utf-8').rstrip()
        return float(message)
        # while 1:
        #     if message == 0:
        #         try:
                    

        #         except:
        #             print("Error decoding data!")

