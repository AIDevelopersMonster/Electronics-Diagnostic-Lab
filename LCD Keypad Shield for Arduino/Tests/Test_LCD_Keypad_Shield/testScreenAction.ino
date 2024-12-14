/*
  Test for LCD Screen
  ===================

  This file contains the action for testing the LCD screen by lighting up all the pixels and displaying a chessboard pattern.
*/

// Action for the "Test Screen" menu item
void testScreenAction() {
  menu->getLCD()->clear();
  menu->getLCD()->setCursor(0, 0);
  menu->getLCD()->print("Testing Screen...");
  delay(1000);

  // Light up all pixels on the screen
  menu->getLCD()->clear();
  for (int row = 0; row < 2; row++) {
    for (int col = 0; col < 16; col++) {
      menu->getLCD()->setCursor(col, row);
      menu->getLCD()->write(255);  // Turn on each pixel
      delay(50);  // Wait for a short time to make the pixels visible
    }
  }
  delay(1000);  // Wait for 1 second before proceeding

  // Test: Chess pattern (left to right)
  menu->getLCD()->clear();
  menu->getLCD()->setCursor(0, 0);
  menu->getLCD()->print("Chess Pattern...");
  delay(1000);

  // Clear screen to avoid artifacts
  menu->getLCD()->clear();

  for (int row = 0; row < 2; row++) {
    for (int col = 0; col < 16; col++) {
      if ((row + col) % 2 == 0) {
        menu->getLCD()->setCursor(col, row);
        menu->getLCD()->write(255);  // Turn on the pixel in a chess pattern
      }
      delay(50);  // Delay for the chess effect
    }
  }
  delay(1000);  // Wait before switching the direction

  // Test: Chess pattern (right to left)
  menu->getLCD()->clear();
  menu->getLCD()->setCursor(0, 0);
  menu->getLCD()->print("Chess Pattern...");
  delay(1000);

  // Clear screen to avoid artifacts
  menu->getLCD()->clear();

  for (int row = 0; row < 2; row++) {
    for (int col = 15; col >= 0; col--) {
      if ((row + col) % 2 == 0) {
        menu->getLCD()->setCursor(col, row);
        menu->getLCD()->write(255);  // Turn on the pixel in a chess pattern (right to left)
      }
      delay(50);  // Delay for the chess effect
    }
  }

  delay(1000);  // Wait for 1 second before returning to the menu
  menu->display();  // Return to the menu
}