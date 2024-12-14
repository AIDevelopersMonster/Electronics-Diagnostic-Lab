/*
  Test for LCD Keypad Shield Buttons
  ==================================

  This file contains the action for testing the buttons on the LCD Keypad Shield.
  It will display the name of the button pressed on the screen.
*/


// Action for the "Test Buttons" menu item
void testButtonAction() {
  menu->getLCD()->clear();
  menu->getLCD()->setCursor(0, 0);
  menu->getLCD()->print("Test Buttons...");
  delay(1000);  // Wait before the button test starts
  
  const char* buttonNames[] = {"RIGHT", "UP", "DOWN", "LEFT", "SELECT"};
  int buttonCodes[] = {btnRIGHT, btnUP, btnDOWN, btnLEFT, btnSELECT};  // Button codes
  
  // Loop through each button and wait for the press
  for (int i = 0; i < 5; i++) {
    menu->getLCD()->clear();
    menu->getLCD()->setCursor(0, 0);
    menu->getLCD()->print("Press ");
    menu->getLCD()->print(buttonNames[i]);  // Display button name

    int buttonState = btnNONE;
    while (buttonState != buttonCodes[i]) {  // Wait until the correct button is pressed
      buttonState = read_LCD_buttons();  // Read button state
      delay(50);  // Small delay to reduce the frequency of checks
    }

    // Once the correct button is pressed, show feedback
    menu->getLCD()->clear();
    menu->getLCD()->setCursor(0, 0);
    menu->getLCD()->print(buttonNames[i]);
    menu->getLCD()->print(" pressed");
    delay(1000);  // Show for a second before moving to the next button
  }

  // After testing all buttons, go back to the main menu
  delay(1000);
  menu->display();  // Return to the main menu
}