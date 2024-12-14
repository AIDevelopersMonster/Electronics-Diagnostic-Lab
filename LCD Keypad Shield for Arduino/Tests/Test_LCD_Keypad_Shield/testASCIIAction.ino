/*
  Test for ASCII Characters
  ==========================

  This file contains the action for testing all ASCII characters (0-255) on the LCD screen.
  It will display each character sequentially to ensure that the LCD can render all ASCII characters properly.

  The program will display the characters one by one on the LCD screen, from ASCII code 0 to 255.
  The characters will be displayed in a 2-line format, with 16 characters per line.

  This test helps verify the behavior of the LCD for both standard and extended ASCII characters.
*/

// Action for the "Test ASCII" menu item
void testASCIIAction() {
  menu->getLCD()->clear();
  menu->getLCD()->setCursor(0, 0);
  menu->getLCD()->print("Testing ASCII...");
  delay(1000);

  int x = 0, y = 0;

  // Loop through all ASCII characters from 0 to 255
  for (int i = 0; i < 256; i++) {
    menu->getLCD()->setCursor(x, y);  // Set cursor position on the screen
    menu->getLCD()->write(i);  // Print the current ASCII character

    // Update the cursor position
    x++;
    if (x >= 16) {
      x = 0;  // Reset cursor to the beginning of the row
      y = (y + 1) % 2;  // Switch to the next line (0 or 1)
    }

    delay(100);  // Short delay to view each symbol
  }

  delay(1000);  // Pause before returning to the menu
  menu->display();  // Return to the main menu
}
