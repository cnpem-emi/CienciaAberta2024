from .ca2024.driver.coil_driver import CoilDriver

if __name__ == "__main__":
    coil = CoilDriver(14, 50, 100)
    coil.drive()