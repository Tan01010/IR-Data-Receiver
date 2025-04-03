# IR Signal Receiver with U8glib Display

This project allows you to detect and display infrared (IR) signals using an IR receiver and an OLED display (SSD1306 128x64). The Arduino Uno receives and decodes the IR signals and displays the command, protocol, and address of the received data on a monochrome screen. This project supports multiple IR protocols for decoding signals.

## Components Required

- **Arduino Uno** or compatible board
- **IR Receiver** (compatible with IRremote library)
- **OLED Display** (128x64 SSD1306 display)
- **Jumper Wires**

## Libraries Used

- **IRremote**: For receiving and decoding the IR signals.
- **U8glib**: For interfacing with the OLED display and rendering text.

## Pin Configuration

- **IR Receiver Pin**: Digital Pin 2 (defined as `IR_RECEIVE_PIN` in the code)

## Circuit Diagram

Connect the IR receiver to the Arduino Uno as follows:

- **VCC** to 5V
- **GND** to GND
- **Signal** to Pin 2 (configured in the code)

Connect the OLED display using I2C:

- **VCC** to 5V
- **GND** to GND
- **SCL** to A5
- **SDA** to A4

## How It Works

1. The Arduino Uno reads incoming IR signals from the IR receiver.
2. When a signal is detected, the `IRremote` library decodes the command, protocol, and address from the signal.
3. The decoded information is displayed on the OLED screen.
4. If no IR signal is detected, the display will show "No Data...".
5. The data will refresh every 5 seconds.

## Code Breakdown

### Setup

- **Serial communication** is started for debugging.
- The **IR receiver** is initialized to begin receiving data on pin 2.
- The **OLED display** is initialized, and a font is set for text display.

### Loop

- In the `loop()`, the `checkForData()` function checks for incoming IR data.
- If IR data is detected, it clears the display and shows:
  - The **command** in hexadecimal
  - The **protocol** in hexadecimal
  - The **address** in hexadecimal
- If no IR signal is received, it displays "No Data...".

### Display Settings

The font used is `u8g_font_6x10`. You can change the font by adjusting the `setFont()` method.

## Installation Instructions

1. Install the **IRremote** library from the Arduino Library Manager.
2. Install the **U8glib** library from the Arduino Library Manager.
3. Connect the IR receiver and OLED display as per the wiring instructions above.
4. Upload the code to your Arduino.
5. Open the Serial Monitor to observe incoming data.

## Example Output

- When an IR signal is detected:

```
*****START*****
Cmd: 10
Protocol: 5
Addr: 5A
******END******
```
- When no signal is detected:

```
No Data...
```


## Troubleshooting

- **No output on display**: Check the connections of the OLED display and ensure the correct I2C pins are used.
- **IR receiver not detecting signals**: Ensure the IR receiver is connected to the correct pin and aligned with the remote.

## License

This project is open-source and available under the MIT License.
