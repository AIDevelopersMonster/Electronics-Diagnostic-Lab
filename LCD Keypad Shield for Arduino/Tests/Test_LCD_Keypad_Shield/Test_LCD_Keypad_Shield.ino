/*
  LCD Keypad Shield Testing Project
  =================================

  Author: AlexMalachevsky 
  Youtube: https://www.youtube.com/@KONTAKTS
  Description: This project is designed to test the functionality of the LCD Keypad Shield using an Arduino.
               It includes several tests for the LCD screen, buttons, and custom character generation.

  Libraries Used:
  - LiquidCrystal: A standard Arduino library for controlling LCDs.
  - LCDMenu: A library for creating menus on LCD displays.
    - Install it via Arduino Library Manager or from GitHub: 
      https://github.com/adacho/LCDMenu.git

  Functions:
  - `testScreenAction()`: Test the screen by lighting up all pixels and displaying a chessboard pattern.
  - `testButtonAction()`: Test the buttons by displaying the button name on the screen when pressed.
  - `testASCIIAction()`: Display all ASCII characters (0-255) on the LCD.

  License: MIT License
*/
#include <LiquidCrystal.h>
#include <LCDMenu.h>
#include <LCDMenuItem.h>

// Define button constants
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

// Define LCD and menu objects
LiquidCrystal* LCD;  // Pointer to the LCD object
LCDMenu* menu;       // Pointer to the menu system
int lastButton = btnNONE;  // Variable to track the last button state

// Function to read button states
int read_LCD_buttons() {
  int adc_key_in = analogRead(0);  // Read the value from the button sensor
  if (adc_key_in > 1000) return btnNONE; 
  if (adc_key_in < 50)   return btnRIGHT;
  if (adc_key_in < 195)  return btnUP; 
  if (adc_key_in < 380)  return btnDOWN; 
  if (adc_key_in < 555)  return btnLEFT; 
  if (adc_key_in < 790)  return btnSELECT;
  return btnNONE;
}

// Action for the "Settings" menu item
void settingsAction() {
  menu->getLCD()->clear();
  menu->getLCD()->setCursor(2, 2);
  menu->getLCD()->print("Some settings...");
  delay(2000);  // Wait for 2 seconds
}

// Setup function to initialize the LCD and menu system
void setup() {
  LCD = new LiquidCrystal(8, 9, 4, 5, 6, 7);  // Initialize the LCD with specified pins
  LCD->begin(16, 2);  // Set up the LCD with 16 columns and 2 rows
  LCD->clear();  // Clear the screen

  menu = new LCDMenu("Main Menu", LCD);  // Initialize the menu with title "Main Menu" and LCD object
  LCDMenuItem *newItem;

  // Add menu items
  newItem = new LCDMenuItem("Test Screen");
  newItem->setAction(&testScreenAction);  // Link the "Test Screen" item to its action function
  menu->addMenuItem(newItem);

  newItem = new LCDMenuItem("Test Buttons");
  newItem->setAction(&testButtonAction);  // Link the "Test Buttons" item to its action function
  menu->addMenuItem(newItem);

  newItem = new LCDMenuItem("Test ASCII");
  newItem->setAction(&testASCIIAction);  // Link the "Test ASCII" item to its action function
  menu->addMenuItem(newItem);

  menu->display();  // Display the menu on the LCD
}

// Main loop to handle button presses and menu navigation
void loop() {
  int buttonState = read_LCD_buttons();  // Read the current button state

  // If the button state changes, update the menu
  if (buttonState != lastButton) {  
    menu->getLCD()->setCursor(0, 0); 
    switch (buttonState) {
      case btnDOWN: 
        menu->getLCD()->print(menu->next()->getName());  // Display the next menu item
        break;
      case btnUP: 
        menu->getLCD()->print(menu->prev()->getName());  // Display the previous menu item
        break;
      case btnRIGHT: 
        menu->selectOption();  // Select the current menu option
        break;  
    }
    menu->display();  // Update the display with the current menu state
    lastButton = buttonState;  // Update the last button state
  }
}