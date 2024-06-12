from ca2024.driver.coil_driver import CoilDriver
from ca2024.driver.inputhandler import InputHandler

coil = CoilDriver(14, 50, 10)
button = InputHandler(7, coil.drive())

if __name__ == "__main__":
    button.read_pin()
    
    
