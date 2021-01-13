# Project Description
This was purely for learning how bluetooth connections and communication worked with ESP32 based microcontrollers and communicating with a C# .net application. As a further experiment I also played around with a way for the C# program to automatically identify the COM port that the program is intended to interface with.

This will work fine with any ESP32 based device, however you will need to remove the heltec specific code in the `ESP32/BluetoothConnect` code. 

# Prerequisites
- HelTec Automation(TM) WIFI Kit 32 (ESP32 based microcontroller with OLED display) (this requires particular arduino libraries which you can find here: https://heltec.org/wifi_kit_install/)
- Bluetooth capable computer

# Setup
- Verify & Upload the Arduino .ino sketch to your ESP32 based device (you will need to edit this if not using the model named above)
- Compile the C# console client
- Add the ESP32 based device as a bluetooth device to your computer

# Usage
- Run the ESP32 based device 
- Run the C# compiled console client (you can do this in Visual Studio debug mode or a compiled release)
- The ESP32 device will read "Connecting..." until it establishes a bluetooth connection & the C# app finds the correct port to communicate with
- If a connection can be established, the console app will prompt you to "Enter Text". Enter anything you want and press the "enter" key and it should then display on the ESP32 based device's OLED display