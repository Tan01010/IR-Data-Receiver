#include <IRremote.hpp>
#include <U8glib.h>  // Include U8glib library

#define IR_RECEIVE_PIN 2

// Initialize U8glib for a 128x64 OLED display (adjust for your display model)
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);  // Adjust constructor based on your display

void setup() {
  // Start Serial, Receiver, and Display
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  Serial.println("Serial, IR Receiver, and Display Started...");
  
  u8g.setFont(u8g_font_6x10);  // Set the font for the display (you can change this as needed)
}

void loop() {
  checkForData();
}

void checkForData() {
  // Check for incoming data
  if (IrReceiver.decode()) {
    u8g.firstPage();  // Start a new page for drawing
    do {
      // Clear previous content and start writing new text on the display
      u8g.setPrintPos(5, 10);  // Set position for first line
      u8g.print("*****START*****");

      u8g.setPrintPos(5, 20);  // Set position for second line
      u8g.print("Cmd: ");
      u8g.print(IrReceiver.decodedIRData.command, HEX);  // Display Command in Hex

      u8g.setPrintPos(5, 30);  // Set position for third line
      u8g.print("Protocol: ");
      u8g.print(IrReceiver.decodedIRData.protocol, HEX);  // Display Protocol in Hex

      u8g.setPrintPos(5, 40);  // Set position for fourth line
      u8g.print("Addr: ");
      u8g.print(IrReceiver.decodedIRData.address, HEX);  // Display Address in Hex

      u8g.setPrintPos(5, 50);
      u8g.print("******END******");

    } while (u8g.nextPage());  // Continue drawing to the next page if needed
    
    IrReceiver.resume();  // Receive the next value
    delay(5000);  // Wait for 10 seconds before checking again
  } else {
    u8g.firstPage();  // Start a new page for drawing
    do {
      u8g.setPrintPos(5, 10);  // Set position for first line
      u8g.print("No Data...");
    } while (u8g.nextPage());  // Continue drawing to the next page if needed
  }
}
