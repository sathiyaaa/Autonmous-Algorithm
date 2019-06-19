#include <Servo.h>

Servo escl, escr, esct;
bool trigger = false;
int stoop = 5;

void arming() {
  Serial.println("Arming");
  setSpeedforward(30);
  delay(2000);

  setSpeedforward(90);
  delay(2000);

  Serial.println("Armed");
  setSpeedforward(30);
  delay(2000);
}

void setSpeeddepth(int speed) {
  // speed is from 0 to 100 where 0 is off and 100 is max speed
  // the following maps speed values of 0-100 to angles from 0-180

  int angle = map(speed, 0, 100, 0, 180);
  escl.write(0);
  escr.write(0);
  esct.write(angle);
}

void setSpeedforward(int speed) {
  // speed is from 0 to 100 where 0 is off and 100 is max speed
  // the following maps speed values of 0-100 to angles from 0-180

  int angle = map(speed, 0, 100, 0, 180);
  escl.write(angle);
  escr.write(angle);
  esct.write(angle);
}

void setSpeedleft(int speed) {
  // speed is from 0 to 100 where 0 is off and 100 is max speed
  // the following maps speed values of 0-100 to angles from 0-180

  int angle = map(speed, 0, 100, 0, 180);
  escl.write(angle);
  escr.write(angle);
  esct.write(0);
}

void setSpeedoff(int speed) {
  // speed is from 0 to 100 where 0 is off and 100 is max speed
  // the following maps speed values of 0-100 to angles from 0-180

  int angle = map(speed, 0, 100, 0, 180);
  escl.write(0);
  escr.write(0);
  esct.write(0);
  delay(10000000);
}

void setSpeedstop(int speed) {
  // speed is from 0 to 100 where 0 is off and 100 is max speed
  // the following maps speed values of 0-100 to angles from 0-180

  int angle = map(speed, 0, 100, 0, 180);
  escl.write(0);
  escr.write(0);
  esct.write(angle);
}

void setup() {
  Serial.begin(115200);
  escl.attach(6);
  escr.attach(8);
  esct.attach(10);
  arming();
  attachInterrupt(digitalPinToInterrupt(2), onswitch, RISING);
  attachInterrupt(digitalPinToInterrupt(21), offswitch, RISING);
}

void loop() {
  while (trigger == true && stoop < 5)
  {
    delay(5000);
    int speed = 90;
    setSpeeddepth(speed);
    delay(2000);
    for (int i = 0; i < 2; i++)
    {
      if (trigger == true)
      {
        setSpeedforward(speed);
        delay(10000);
      }
      else
      {
        break;
      }
      if (trigger == true)
      {
        setSpeedstop(speed);
        delay(1000);
      }
      else
      {
        break;
      }
      if (trigger == true)
      {
        setSpeedleft(speed);
        delay(5000);;
      }
      else
      {
        break;
      }
      if (trigger == true)
      {
        setSpeedstop(speed);
        delay(1000);
      }
      else
      {
        break;
      }
      if (trigger == true)
      {
        setSpeedforward(speed);
        delay(5000);
      }
      else
      {
        break;
      }
      if (trigger == true)
      {
        setSpeedstop(speed);
        delay(1000);
      }
      else
      {
        break;
      }
      if (trigger == true)
      {
        setSpeedleft(speed);
        delay(5000);
      }
      else
      {
        break;
      }
      if (trigger == true)
      {
        setSpeedstop(speed);
        delay(1000);
      }
      else
      {
        break;
      }
    }
    stoop++;
  }
}

void onswitch()
{
  Serial.println("on triggered");
  trigger = true;
  stoop = 0;
}

void offswitch()
{
  Serial.println("off triggered");
  stoop = 10;
  trigger = false;
  setSpeedoff(0);

}
