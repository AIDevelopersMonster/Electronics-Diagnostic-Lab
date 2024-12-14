# LCD Keypad Shield Testing Project

## Description

This project is designed to test the functionality of the **LCD Keypad Shield** using an Arduino. It includes several tests for the LCD screen, buttons, and custom character generation.

The project is structured into several tests, each organized in separate files:
- **Test Screen**: Lights up all pixels on the LCD and runs a "chess pattern" effect.
- **Test Buttons**: Allows you to test each button on the LCD Keypad Shield.
- **Test ASCII**: Displays all ASCII characters (from 0 to 255) on the LCD to check how each character is rendered.

### Authors:
- **Your Name** Alex Malachevsky
       Youtube https://www.youtube.com/@KONTAKTS
   

### Libraries Used:
- **LiquidCrystal**: A standard Arduino library for controlling LCDs.
- **LCDMenu**: A library for creating menus on LCD displays.
    - Install it via Arduino Library Manager or from GitHub:  
      [LCDMenu GitHub Repository](https://github.com/adacho/LCDMenu.git)
  
To install the libraries, go to **Sketch > Include Library > Manage Libraries** in the Arduino IDE and search for the library name.

## Features

- **Test Screen**: Lights up all pixels on the LCD and runs a "chess pattern" effect.
- **Test Buttons**: Allows you to test each button on the LCD Keypad Shield.
- **Test ASCII**: Displays all ASCII characters (from 0 to 255) on the LCD to check the behavior of the characters.

## Requirements

- **Arduino Board**: Arduino Uno, Mega, or any compatible board.
- **LCD Keypad Shield**: A 16x2 LCD with a built-in keypad (5 buttons).
- **Libraries**:
  - `LiquidCrystal` - Standard Arduino library for LCD control.
  - `LCDMenu` - A library to manage menu navigation and interactions.
  
  These libraries can be installed via the Arduino Library Manager.

## Installation

1. **Clone this repository**:
   ```bash
   git clone https://github.com/yourusername/LCD-Keypad-Shield-Testing.git
