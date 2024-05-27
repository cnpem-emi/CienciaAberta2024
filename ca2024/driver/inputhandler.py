from Adafruit_BBIO import GPIO
from pin_reference import gpio

class InputHandler:
    def __init__(self, input_pin: int) -> None:
        self.input_pin = input_pin
        
        GPIO.setup(gpio.get(self.input_pin), GPIO.IN)

    def read_pin(self) -> None:
        """
            Reads the input pin and waits for a rising edge.
        """

        if GPIO.wait_for_edge(gpio.get(self.input_pin), GPIO.RISING):
            # Do something
            print("HIGH")
        else:
            print("LOW")
