#include "MPU6050.h"
#include <Wire.h>
MPU mpu;
AStruct a;
TStruct t;
GStruct g;

void setup() {  

  Wire.begin(21,22);

  Serial.begin(9600);
  mpu.pwr_setup();
  mpu.gyro_setup(1);
  mpu.acc_setup(1);
  delay(500);
}

void loop() {

  mpu.get_acc(1,&a);
  print_acc();
  delay(1000);

  mpu.get_temp(&t);
  print_temp();
  delay(1000);

  float pp=mpu.get_gyro(1,&g);
  print_gyro();
  Serial.print(pp);
  delay(1000);

}
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