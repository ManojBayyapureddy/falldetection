#include <Wire.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
const int MPU_addr = 0x68;
int16_t Accx, Accy, Accz, Tmp, Grx, Gry, Grz;
float ax = 0, ay = 0, az = 0, gx = 0, gy = 0, gz = 0;
boolean fall = false;
boolean tg1 = false;
boolean tg2 = false;
boolean tg3 = false;
byte tg1count = 0;
byte tg2count = 0;
byte tg3count = 0;
int anChange = 0;

#define BLYNK_TEMPLATE_ID "TMPL340sYM9p6"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "Z_oYkHUa3qkjEtK_kncg38HIzkf6-laP"
const char *ssid = "iPhone";
const char *pass = "123454321";
void setup()
{
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.println("Wrote to IMU");
  Serial.println("Connecting to ");
  Serial.println(ssid);

  Serial.println("");
  Serial.println("WiFi connected");
}
void loop()
{
  Blynk.run();
  mpu_read();
  ax = (Accx - 2050) / 16384.00;
  ay = (Accy - 77) / 16384.00;
  az = (Accz - 1947) / 16384.00;
  gx = (Grx + 270) / 131.07;
  gy = (Gry - 351) / 131.07;
  gz = (Grz + 136) / 131.07;

  float ra_amp = pow(pow(ax, 2) + pow(ay, 2) + pow(az, 2), 0.5);
  int hei = ra_amp * 10;
  Serial.println(hei);
  Blynk.virtualWrite(V5, hei);
  if (hei <= 2 && tg2 == false)
  {
    tg1 = true;
    Serial.println("TRIGGER 1 ACTIVATED");
  }
  if (tg1 == true)
  {
    tg1count++;
    if (hei >= 12)
    {
      tg2 = true;
      Serial.println("TRIGGER 2 ACTIVATED");
      tg1 = false;
      tg1count = 0;
    }
  }
  if (tg2 == true)
  {
    tg2count++;
    anChange = pow(pow(gx, 2) + pow(gy, 2) + pow(gz, 2), 0.5);
    Serial.println(anChange);
    if (anChange >= 30 && anChange <= 400)
    {
      tg3 = true;
      tg2 = false;
      tg2count = 0;
      Serial.println(anChange);
      Serial.println("TRIGGER 3 ACTIVATED");
    }
  }
  if (tg3 == true)
  {
    tg3count++;
    if (tg3count >= 10)
    {
      anChange = pow(pow(gx, 2) + pow(gy, 2) + pow(gz, 2), 0.5);

      Serial.println(anChange);
      if ((anChange >= 0) && (anChange <= 10))
      {
        fall = true;
        tg3 = false;
        tg3count = 0;
        Serial.println(anChange);
      }
      else
      {
        tg3 = false;
        tg3count = 0;
        Serial.println("TRIGGER 3 DEACTIVATED");
      }
    }
  }
  if (hei > 15)
  {
    Serial.println("FALL DETECTED");
    fall = false;
  }
  if (tg2count >= 6)
  {
    tg2 = false;
    tg2count = 0;
    Serial.println("TRIGGER 2 DECACTIVATED");
  }
  if (tg1count >= 6)
  {
    tg1 = false;
    tg1count = 0;
    Serial.println("TRIGGER 1 DECACTIVATED");
  }
  delay(100);
}
void mpu_read()
{
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr, 14, true);
  Accx = Wire.read() << 8 | Wire.read();
  Accy = Wire.read() << 8 | Wire.read();
  Accz = Wire.read() << 8 | Wire.read();
  Tmp = Wire.read() << 8 | Wire.read();
  Grx = Wire.read() << 8 | Wire.read();
  Gry = Wire.read() << 8 | Wire.read();
  Grz = Wire.read() << 8 | Wire.read();
}
