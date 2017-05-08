#ifndef I2C_H
#define I2C_H

#include <inttypes.h>
#ifdef __cplusplus
extern "C"{
#endif
void i2cInit();
uint8_t i2cSendRegister(uint8_t reg, uint8_t data);
uint8_t i2cReadRegister(uint8_t reg, uint8_t *data);
#ifdef __cplusplus
} // extern "C"
#endif
#endif //I2C_H
