#include <Wire.h>
#include <stdint.h>
#include "MPU6050.h"

Wire.begin();

void MPU::pwr_setup(){//power management registers setup
    Wire.beginTransmission(ADDR);
    Wire.write(PWR_MGMT_1);
    Wire.write(0x00);
    Wire.endTransmission(true);
}

void MPU::gyro_setup(int range){//gyroscope registers setup
    Wire.write(GYRO_CONFIG);
    if(range==0){
         Wire.write(0x00);
    }
    else if(range==1){
         Wire.write(0x01);
    }
    else if(range==2){
         Wire.write(0x10);
    }
    else if(range==3){
         Wire.write(0x11);
    }
   
    Wire.endTransmission(true);
}

void MPU::acc_setup(int range){//accelerometer registers setuo
    Wire.write(ACC_CONFIG);
     if(range==0){
         Wire.write(0x00);
    }
    else if(range==1){
         Wire.write(0x01);
    }
    else if(range==2){
         Wire.write(0x10);
    }
    else if(range==3){
         Wire.write(0x11);
    }

    Wire.endTransmission(true);
}

void MPU::get_acc(int Anum, AStruct acc){
    Wire.beginTransmission(ADDR);
    Wire.write(ACCEL_XOUT_H);
    Wire.endTransmission(false);
    Wire.requestFrom(ADDR,6,true);  
    
    int16_t xdata=Wire.read()<<8|Wire.read();
    int16_t ydata=Wire.read()<<8|Wire.read();
    int16_t zdata=Wire.read()<<8|Wire.read();

    acc.XAxis=(float)xdata/AccelRange[Anum];
    acc.YAxis=(float)ydata/AccelRange[Anum];
    acc.ZAxis=(float)zdata/AccelRange[Anum];

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

void MPU::get_gyro(int Gnum, GStruct gyro){
    Wire.beginTransmission(ADDR);
    Wire.write(GYRO_XOUT_H);
    Wire.endTransmission(false);
    Wire.requestFrom(ADDR,6,true);  
    
    int16_t xdata=Wire.read()<<8|Wire.read();
    int16_t ydata=Wire.read()<<8|Wire.read();
    int16_t zdata=Wire.read()<<8|Wire.read();
    
    gyro.XAxis=(float)xdata/GyroRange[Gnum];
    gyro.YAxis=(float)ydata/GyroRange[Gnum];
    gyro.ZAxis=(float)zdata/GyroRange[Gnum];

    Wire.endTransmission(true);
}

