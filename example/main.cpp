#include <Arduino.h>
// put function declarations here:
#include "MPU6050.h"
#include <Wire.h>
MPU mpu;
AStruct a;
TStruct t;
GStruct g;

void setup() {  

  Wire.begin(21,22);//SDA SCL pins
//setup functions, for int values refer to MPU6050.cpp
  Serial.begin(9600);
  mpu.pwr_setup();
  mpu.gyro_setup(3);
  mpu.acc_setup(1);
  delay(5000);
}
int main(void){}
//print functions --ignore--
void print_acc(){
  Serial.print("ACC X Y Z : \t");
  Serial.print(a.XAxis);Serial.print("\t");
  Serial.print(a.YAxis);Serial.print("\t");
  Serial.println(a.ZAxis);
}

void print_temp(){
  Serial.print("temperature is ");
  Serial.println(t.TempC);
}
  
void print_gyro(){
  Serial.print("GYRO X Y Z : \t");
  Serial.print(g.XAxis);Serial.print("\t");
  Serial.print(g.YAxis);Serial.print("\t");
  Serial.println(g.ZAxis);
}

void loop() {
//refer to MPU6050.h for int values: 131.0,65.5,32.8,16.4 | 16384.0,8192.0,4096.0,2048.0
  mpu.get_acc(1,&a);
  print_acc();
  delay(1000);

  mpu.get_temp(&t);
  print_temp();
  delay(1000);

  mpu.get_gyro(1,&g);
  print_gyro();
  delay(1000);

}
