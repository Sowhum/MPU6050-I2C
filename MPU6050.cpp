#include <Wire.h>
#include <stdint.h>
#include "MPU6050.h"

uint8_t mpuaddr=0x68;
void MPU::pwr_setup(){//power management registers setup
    Wire.beginTransmission(ADDR);
    Wire.write(PWR_MGMT_1);
    Wire.write(0x01);
    Wire.endTransmission(true);
}

void MPU::gyro_setup(int range){//gyroscope registers setup
    Wire.beginTransmission(ADDR);
    Wire.write(GYRO_CONFIG);
    //RANGE values (0 to 3) corresponds to scale of +- 250, 500, 1000, 2000 °/s
   if(range==0){
         Wire.write(0x00);
    }
    else if(range==1){
         Wire.write(0x08);
    }
    else if(range==2){
         Wire.write(0x10);
    }
    else if(range==3){
         Wire.write(0x18);
    }
    Wire.endTransmission(true);
}

void MPU::acc_setup(int range){//accelerometer registers setup
    Wire.beginTransmission(ADDR);
    Wire.write(ACC_CONFIG);
    //RANGE values (0 to 3) corresponds to scale of +- 2, 4, 8, 16 g
    if(range==0){
         Wire.write(0x00);
    }
    else if(range==1){
         Wire.write(0x8);
    }
    else if(range==2){
         Wire.write(0x10);
    }
    else if(range==3){
         Wire.write(0x18);
    }

    Wire.endTransmission(true);
}

void MPU::get_acc(int Anum, struct AStruct *acc){//reading from 6 registers starting from XOUT_H
    Wire.beginTransmission(ADDR);
    Wire.write(ACCEL_XOUT_H);
    Wire.endTransmission(false);
    Wire.requestFrom(mpuaddr,(size_t)6,true);  
    
    int16_t xdata=Wire.read()<<8|Wire.read();
    int16_t ydata=Wire.read()<<8|Wire.read();
    int16_t zdata=Wire.read()<<8|Wire.read();

    acc->XAxis=(float)xdata/AccelRange[Anum];
    acc->YAxis=(float)ydata/AccelRange[Anum];
    acc->ZAxis=(float)zdata/AccelRange[Anum];

    Wire.endTransmission(true);
}

void MPU::get_temp(struct TStruct *temp){//reading from 2 registers starting from TEMP_OUT_H
    Wire.beginTransmission(ADDR);
    Wire.write(TEMP_OUT_H);
    Wire.endTransmission(false);
    Wire.requestFrom(mpuaddr,(size_t)2,true);  
    
    int16_t tdata=Wire.read()<<8|Wire.read();

    temp->TempC=float(tdata)/340 +36.53;

    Wire.endTransmission(true);
}

float MPU::get_gyro(int Gnum,struct GStruct *gyro){//reading from 6 registers starting from XOUT_H
    Wire.beginTransmission(ADDR);
    Wire.write(GYRO_XOUT_H);
    Wire.endTransmission(true);
    Wire.requestFrom(mpuaddr,(size_t)6,true);  
    
    int16_t xdata=Wire.read()<<8|Wire.read();
    int16_t ydata=Wire.read()<<8|Wire.read();
    int16_t zdata=Wire.read()<<8|Wire.read();
    
    gyro->XAxis=(float)xdata/GyroRange[Gnum];
    gyro->YAxis=(float)ydata/GyroRange[Gnum];
    gyro->ZAxis=(float)zdata/GyroRange[Gnum];

    Wire.endTransmission(true);
    return(ydata);
}
