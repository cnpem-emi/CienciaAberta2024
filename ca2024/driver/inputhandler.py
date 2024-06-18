from Adafruit_BBIO import GPIO
from .pin_reference import gpio

class InputHandler:
    def __init__(self, input_pin: int) -> None:
        self.input_pin = input_pin

        GPIO.setup(gpio.get(self.input_pin), GPIO.IN, GPIO.PUD_DOWN)

    def read_pin(self) -> None:
        """
            Reads the input pin and waits for a rising or falling edge.
            Returns 1 if edge detected.
        """
        if GPIO.wait_for_edge(gpio.get(self.input_pin), GPIO.BOTH) == None:
            print(GPIO.input(gpio.get(self.input_pin)))
            return 1
