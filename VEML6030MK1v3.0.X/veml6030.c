
#include <xc.h>
#include <assert.h>
#include <stdbool.h>
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/examples/i2c_master_example.h"
#include "veml6030.h"

#define VEML6030_ADDR  0x10 //0x48

// VEML6030 registers //
#define REG_ALS_CONF            0x00
#define REG_ALS_WH              0x01
#define REG_ALS_WL              0x02
#define REG_POWER_SAVING        0x03
#define REG_ALS                 0x04
#define REG_WHITE               0x05
#define REG_ALS_INT             0x06

#define REG_ALS_CONF_SHUTDOWN   0x01

uint8_t  writeBuffer[3] = {0x00, 0x00, 0x00};                           // definiert "writeBuffer"
uint8_t  readBuffer[2] = {0x00, 0x00};                                  // definiert "readBuffer"

void VEML6030_Init(void){                                               // "VEML6030_Init"
    uint16_t config;                                                    // definiert "config"
    
    I2C_Write1ByteRegister(VEML6030_ADDR,REG_ALS_CONF,0x00);            // schreibt über I2C "0x00" in "REG_ALS_CONF"               |Sensor Reste
    //config = I2C_Read2ByteRegister(VEML6030_ADDR,REG_ALS_CONF);         // ließt über I2C "REG_ALS_CONF" in "config"                |Power ON
    //config &= ~REG_ALS_CONF_SHUTDOWN;                                   //                                                          |
    //I2C_Write2ByteRegister(VEML6030_ADDR,REG_ALS_CONF,config);          // schreibt über I2C inhalt von"config" in "REG_ALS_CONF"   |
    __delay_ms(10);                                                     // warte 10ms
}                                                                       // 

float VEML6030_GetValue(void){                                          // "VEML6030_GetValue"
    float   lightDataAnz;                                               // definiert "lightDataAnz"
    uint16_t data;                                                      // defineirt "data"

    data = I2C_Read2ByteRegister(VEML6030_ADDR,REG_ALS);                // "data" = inhalt von "REG_ALS"
    lightDataAnz = data;                                                // "lightDataAnz" gleich "data"
    
    return lightDataAnz;                                                // gibt "lightDataAnz" zurück     
}                                                                       // 


