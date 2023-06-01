#include<Wire.h>

// AD5675 I2C address
#define Addr 0x0C

void setup()
{
  // Initialise I2C communication as Master
  Wire.begin();
  // Initialise serial communication, set baud rate = 9600
  Serial.begin(9600);
  delay(300);
}

void loop()
{
  unsigned int data[3] = {0x10, 0xFF,0xFF};
  unsigned int data_2[3] = {0x71,0x00, 0x04};
  
    // Start I2C transmission
  Wire.beginTransmission(Addr);
  // Select DAC and input register
  // Wire.write(0x2F); Write to Input Register n; update all (software LDAC) and All ADCs.
  Wire.write(data_2[0]);
  // Write data = 0x8000(32768)
  // data msb = 0x80
  Wire.write(data_2[1]);
  // data lsb = 0x00
  Wire.write(data_2[2]);

  // Stop I2C transmission
  Wire.endTransmission();
  
  Serial.println("Done Setting Gain and Vref");
  
  // Start I2C transmission
  Wire.beginTransmission(Addr);
  // Select DAC and input register
  // Wire.write(0x2F); Write to Input Register n; update all (software LDAC) and All ADCs.
  Wire.write(data[0]);
  // Write data = 0x8000(32768)
  // data msb = 0x80
  Wire.write(data[1]);
  // data lsb = 0x00
  Wire.write(data[2]);

  // Stop I2C transmission
  Wire.endTransmission();

  // // Convert the data, Vref = 5 V
  // float voltage = (((data[0] * 256) + (data[1])) / 65536.0) * 3.3;

  // // Output data to serial monitor
  // Serial.print("Voltage : ");
  // Serial.print(voltage);
  // Serial.println(" V");
  delay(500);
}