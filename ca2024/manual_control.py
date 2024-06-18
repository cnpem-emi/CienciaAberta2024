import threading
from driver.inputhandler import InputHandler
from driver.coil_driver import CoilDriver

class ManualControl(InputHandler, CoilDriver):
    def __init__(self, pulse_width: int):
        # Input pins
        self.button_0 = InputHandler(7)
        self.button_1 = InputHandler(8)
        self.button_2 = InputHandler(9)
        self.button_3 = InputHandler(10)
        self.button_4 = InputHandler(11)
        self.button_5 = InputHandler(12)

        self.pulse_width = pulse_width
        # Output pins
        self.output_0 = CoilDriver(14, self.pulse_width)
        self.output_1 = CoilDriver(16, self.pulse_width)
        self.output_2 = CoilDriver(21, self.pulse_width)
        self.output_3 = CoilDriver(22, self.pulse_width)
        self.output_4 = CoilDriver(42, self.pulse_width)
        self.output_5 = CoilDriver(19, self.pulse_width)

        # Threads
        self.thread_0 = threading.Thread(
            target=self.manual_loop, args=(button_0, output_0)
            )
        self.thread_1 = threading.Thread(
            target=self.manual_loop, args=(button_1, output_1)
            )
        self.thread_2 = threading.Thread(
            target=self.manual_loop, args=(button_2, output_2)
            )
        self.thread_3 = threading.Thread(
            target=self.manual_loop, args=(button_3, output_3)
            )
        self.thread_4 = threading.Thread(
            target=self.manual_loop, args=(button_4, output_4)
            )
        self.thread_5 = threading.Thread(
            target=self.manual_loop, args=(button_5, output_5)
            )

    def manual_loop(
            self, btn_input: InputHandler, btn_output: CoilDriver
            ) -> None:
        """
            Waits for user input forever
        """

        while 1:
            if btn_input.read_pin() == 1:
                btn_output.drive()
    
    def run(self) -> None:
        """
            Start all threads and runs the manual mode
        """

        self.thread_0.start()
        self.thread_1.start()
        self.thread_2.start()
        self.thread_3.start()
        self.thread_4.start()
        self.thread_5.start()
