from Adafruit_BBIO import PWM
from .pin_reference import pwm
import time

class CoilDriver:
    def __init__(self, output_pin: int, duty_cycle: int, freq: int) -> None:
        self.output_pin = output_pin
        self.duty_cycle = duty_cycle
        self.freq = freq

    def drive(self) -> None:
        """
            Send a square wave pulse to the output pin
        """
        # @todo control pulse width size
        PWM.start(pwm.get(self.output_pin), self.duty_cycle, self.freq)
        time.sleep(2*(1/self.freq))
        self.clear()

    def clear(self) -> None:
        """
            Change the state of the output pin to LOW
        """
        PWM.stop(pwm.get(self.output_pin))

    def __milli(self):
        # Private method to calculate the pulse width from frequency and duty cycle
        # Call at drive method and pass the result as parameter
        pass
