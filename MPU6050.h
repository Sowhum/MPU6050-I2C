#ifndef MPU6050_H

#define MPU6050_H

#define ADDR 0x68
    
//IMU Configurations registers
#define PWR_MGMT_1 0x6B
#define GYRO_CONFIG 0x1B
#define ACC_CONFIG 0x1C

//IMU Data measurements registers 

#define ACCEL_XOUT_H 0X3B
#define ACCEL_XOUT_L 0X3C
#define ACCEL_YOUT_H 0X3D
#define ACCEL_YOUT_L 0X3E
#define ACCEL_ZOUT_H 0X3F
#define ACCEL_ZOUT_L 0X40

#define TEMP_OUT_H 0X41
#define TEMP_OUT_L 0X42

#define GYRO_XOUT_H 0X43
#define GYRO_XOUT_L 0X44
#define GYRO_YOUT_H 0X45
#define GYRO_YOUT_L 0X46
#define GYRO_ZOUT_H 0X47
#define GYRO_ZOUT_L 0X48

//Data Structs

struct AStruct//acceleration
{
    float XAxis,YAxis,Zaxis;
};

struct GStruct//gyroscope
{
    float XAxis,YAxis,Zaxis;
};

struct TStruct//temperature
{
    float TempC;
};

class MPU{
public:
    //config functions
    void pwr_setup();
    void gyro_setup();
    void acc_setup();

    //data read functions
    void get_acc(float Anum,struct Astruct acc);

};

#endif