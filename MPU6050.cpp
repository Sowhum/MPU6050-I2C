#include <Wire.h>
#include <stdint.h>
#include "MPU6050.h"

Wire.begin();

void MPU::pwr_setup(){
    Wire.beginTransmission(ADDR);
    Wire.write(PWR_MGMT_1);
    Wire.write(0x00);
    Wire.endTransmission(true);
}

void MPU::gyro_setup(){
    Wire.beginTransmission(ADDR);
    Wire.write(GYRO_CONFIG);
    Wire.write(0x10);
    Wire.endTransmission(true);
}

void MPU::acc_setup(){
    Wire.beginTransmission(ADDR);
    Wire.write(ACC_CONFIG);
    Wire.write(0x00);
    Wire.endTransmission(true);
}

void MPU::get_acc(float Anum, AStruct acc){
    Wire.beginTransmission(ADDR);
    Wire.write(ACCEL_XOUT_H);
    Wire.endTransmission(false);
    Wire.requestFrom(ADDR,6,true);  
    
    int16_t xdata=Wire.read()<<8|Wire.read();
    int16_t ydata=Wire.read()<<8|Wire.read();
    int16_t zdata=Wire.read()<<8|Wire.read();

    acc.XAxis=(float)xdata/Anum;
    acc.YAxis=(float)xdata/Anum;
    acc.ZAxis=(float)xdata/Anum;

    Wire.endTransmission(true);
}

void MPU::get_temp(TStruct temp){
    Wire.beginTransmission(ADDR);
    Wire.write(TEMP_OUT_H);
    Wire.endTransmission(false);
    Wire.requestFrom(ADDR,2,true);  
    
    int16_t tdata=Wire.read()<<8|Wire.read();

    temp.TempC=float(tdata)/340 +36.53;

    Wire.endTransmission(true);
}

void MPU::get_gyro(float Gnum, GStruct gyro){
    Wire.beginTransmission(ADDR);
    Wire.write(GYRO_XOUT_H);
    Wire.endTransmission(false);
    Wire.requestFrom(ADDR,6,true);  
    
    int16_t xdata=Wire.read()<<8|Wire.read();
    int16_t ydata=Wire.read()<<8|Wire.read();
    int16_t zdata=Wire.read()<<8|Wire.read();
    
    gyro.XAxis=(float)xdata/Gnum;
    gyro.YAxis=(float)xdata/Gnum;
    gyro.ZAxis=(float)xdata/Gnum;

    Wire.endTransmission(true);
}

