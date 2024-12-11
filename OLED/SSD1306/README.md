# OLED/SSD1306 Diagnostics

## Overview
This folder contains scripts and instructions for testing OLED displays based on the SSD1306 controller. These scripts help verify the functionality of the display, including pixel rendering, contrast, and responsiveness.

---

## Features of the Test Script
1. **Full Pixel Test**:
   - Lights up all pixels on the display to check for dead pixels or uneven brightness.
   
2. **Chessboard Pattern**:
   - Alternates pixels in a checkerboard pattern to evaluate pixel clarity and alignment.

3. **Row-by-Row Activation**:
   - Lights up rows sequentially to ensure even activation and detect any vertical alignment issues.

---

## Requirements
1. **Hardware**:
   - OLED display (SSD1306, I2C interface).
   - Microcontroller (e.g., Arduino Nano, Uno, ESP32).
   - Breadboard and jumper wires.

2. **Libraries**:
   - `Adafruit_GFX`
   - `Adafruit_SSD1306`

---

## Wiring Diagram
| OLED Pin | Microcontroller Pin |
|----------|----------------------|
| VCC      | 5V                  |
| GND      | GND                 |
| SDA      | A4 (I2C Data)       |
| SCL      | A5 (I2C Clock)      |

---

## How to Run the Test
1. **Setup**:
   - Connect the OLED display to the microcontroller as per the wiring diagram.
   - Install the required libraries in Arduino IDE.
     1. Open `Sketch -> Include Library -> Manage Libraries...`.
     2. Search for `Adafruit_GFX` and `Adafruit_SSD1306`, then click `Install`.

2. **Upload the Script**:
   - Open the `OLED_Test_SSD1306.ino` file in Arduino IDE.
   - Compile and upload it to the microcontroller.

3. **Observe Output**:
   - The display will sequentially perform the following:
     - Light up all pixels for 5 seconds.
     - Show a checkerboard pattern for 5 seconds.
     - Activate rows one by one with a brief delay between each.

---

## Example Output
- **Full Pixel Test**: Screen fully illuminated.
- **Checkerboard Pattern**: Alternating pixel grid clearly visible.
- **Row Test**: Rows light up sequentially, moving from top to bottom.

---

## Troubleshooting
1. **Display does not light up**:
   - Check wiring connections and ensure SDA/SCL pins are correctly mapped.
   - Verify that the I2C address in the script matches your display (default: `0x3C`).

2. **Unstable display output**:
   - Ensure sufficient power supply (use 5V for consistent operation).
   - Confirm proper installation of the required libraries.

3. **Partial or broken patterns**:
   - Inspect the OLED for physical damage or loose connections.

---

## Contribution
Feel free to improve the test scripts or suggest additional patterns for testing OLED displays.

---

## License
This project is licensed under the MIT License. See `LICENSE` for more details.


