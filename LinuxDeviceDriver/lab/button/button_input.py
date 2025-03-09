import gpiod
BUTTON_PIN = 4

chip = gpiod.Chip("gpiochip0");
button_line = chip.get_line(BUTTON_PIN);
button_line.request(consumer="Button", type=gpiod.LINE_REQ_DIR_IN);

try:
    while True:
        button_state = button_line.get_value()
        if button_state == 1:
            print("Button released")
        else:
            print("Button pressed")

finally:
    button_line.release()

