/*
 * HelTec Automation(TM) WIFI_Kit_32 factory test code, witch includ
 * follow functions:
 *
 * - Basic OLED function test;
 *
 * - Basic serial port test(in baud rate 115200);
 *
 * - LED blink test;
 *
 * - WIFI join and scan test;
 *
 * - Timer test and some other Arduino basic functions.
 *
 * by Aaron.Lee from HelTec AutoMation, ChengDu, China
 * 成都惠利特自动化科技有限公司
 * www.heltec.cn
 *
 * this project also realess in GitHub:
 * https://github.com/HelTecAutomation/Heltec_ESP32
*/

#include "heltec.h"
#include "WiFi.h"
#include "BluetoothSerial.h"

bool connected = false;
bool comConnected = false;
BluetoothSerial SerialBT;

void BluetoothSetup(void)
{
  Heltec.display -> drawString(0, 0, "Connecting...");
  Heltec.display -> display();

  delay(1000);
  SerialBT.begin("ESP32test");
  delay(100);
}


void setup()
{
  pinMode(LED,OUTPUT);
  digitalWrite(LED,HIGH);

  Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRa Enable*/, true /*Serial Enable*/);

  Heltec.display->clear();
  BluetoothSetup();
  
}

void loop()
{
  String inputFromOtherSide;
  if (SerialBT.available()) {
    while(!comConnected)
    {
      SerialBT.println("<connected>");
      inputFromOtherSide = SerialBT.readString();
      Heltec.display -> clear();
      Heltec.display -> drawString(0, 0, inputFromOtherSide);
      Heltec.display -> display();
      if(inputFromOtherSide == "<connect>")
      {
        comConnected = true;
      }
    }
    inputFromOtherSide = SerialBT.readString();
    Heltec.display -> clear();
    Heltec.display -> drawString(0, 0, "You entered: " + inputFromOtherSide);
    Heltec.display -> display();
    
  }
  delay(2000);
}
