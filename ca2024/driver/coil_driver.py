from Adafruit_BBIO import PWM
from .pin_reference import pwm
import time

class CoilDriver:
    def __init__(self, output_pin: int, pulse_width: int) -> None:
        self.output_pin = output_pin
        self.pulse_width = pulse_width
        self.duty_cycle = 100

    def drive(self) -> None:
        """
            Send a square wave pulse to the output pin
        """
        
        self.freq = __frequency()
        PWM.start(pwm.get(self.output_pin), self.duty_cycle, self.freq)
        time.sleep(2*(1/self.freq))
        self.clear()

    def clear(self) -> None:
        """
            Change the state of the output pin to LOW
        """
        
        PWM.stop(pwm.get(self.output_pin))

    def __frequency(self) -> int:
        # Private method to calculate the frequency from pulse width
        # Call at drive method and pass the result as parameter
        self.pulse_width = self.pulse_width/1000
        freq = 1/self.pulse_width

        return freq
