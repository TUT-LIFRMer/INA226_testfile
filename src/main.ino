//
//    FILE: INA226_demo.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: demo
//     URL: https://github.com/RobTillaart/INA226

#include <Arduino.h>
#include "INA226.h"


INA226 INA(0x40);


void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.print("INA226_LIB_VERSION: ");
  Serial.println(INA226_LIB_VERSION);

  Wire.begin();
  if (!INA.begin() )
  {
    Serial.println("could not connect. Fix and Reboot");
  }
  INA.setMaxCurrentShunt(1, 0.002);
}


void loop()
{
  Serial.println("\nBUS\tSHUNT\tCURRENT\tPOWER");
  for (int i = 0; i < 20; i++)
  {
    Serial.print(INA.getBusVoltage(), 3);
    Serial.print("\t");
    Serial.print(INA.getShuntVoltage_mV(), 3);
    Serial.print("\t");
    Serial.print(INA.getCurrent_mA(), 3);
    Serial.print("\t");
    Serial.print(INA.getPower_mW(), 3);
    Serial.println();
    delay(1000);
  }
}


//  -- END OF FILE --

