from Adafruit_BBIO import GPIO
from .pin_reference import gpio

class InputHandler:
    def __init__(self, input_pin: int, callback_func: None) -> None:
        self.input_pin = input_pin
        #self.callback_func = callback_func

        GPIO.setup(gpio.get(self.input_pin), GPIO.IN, GPIO.PUD_DOWN)

    def read_pin(self) -> None:
        """
            Reads the input pin and waits for a rising edge.
        """
        #if GPIO.wait_for_edge(gpio.get(self.input_pin), GPIO.BOTH) == None:
        print(GPIO.input(gpio.get(self.input_pin)))
        #self.callback_func()
        #print("hello")
