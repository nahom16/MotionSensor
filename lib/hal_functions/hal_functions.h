/* * * * * * * hal_ functions.h * * * * * * * 
 *                                           *
 * Declares all of the HAL functions         *
 *                                           *
 * Created by Nahom Tsegaye                  *
 *                                           *
 * Adapted from HAL_Lib that was created     *
 * by Steven Bell at Tufts University        *
 *                                           *
 * May 16th, 2025                            *
 *                                           *
 * * * * * * * * * * * * * * * * * * * * * * */

#ifndef HAL_FUNC_H
#define HAL_FUNC_H

#include <stm32l432xx.h>
#include <stdbool.h>

/* Pin names on the Nucleo silkscreen, copied from the Arduino Nano form factor */
typedef enum {A0,A1,A2,A3,A4,A5,A6,A7,
	  D0,D1,D2,D3,D4,D5,D6,D7,D8,D9,D10,D11,D12,D13 } HAL_Lib_Pin;

typedef int HAL_Lib_Err;

#define HAL_Lib_Err_OK 0
#define HAL_Lib_Err_INEXPLICABLE_FAILURE -1
#define HAL_Lib_Err_NOT_IMPLEMENTED -2
#define HAL_Lib_ERR_INVALID_CONFIG -3

/* Header file for all EE14lib functions. */

/* GPIO modes */
#define INPUT 0b00
#define OUTPUT 0b01
// Normally shouldn't need to use ALTERNATE_FUNCTION directly; the peripheral modes will set this up
#define ALTERNATE_FUNCTION 0b10
#define ANALOG 0b11

/* GPIO pullup modes */
#define PULL_OFF 0b00
#define PULL_UP 0b01
#define PULL_DOWN 0b10
/* GPIO pullup 0b11 is reserved */


/*
 * GPIO functions
 */

HAL_Lib_Err gpio_config_mode(HAL_Lib_Pin pin, unsigned int mode);
HAL_Lib_Err gpio_config_pullup(HAL_Lib_Pin pin, unsigned int mode);
HAL_Lib_Err gpio_config_alternate_function(HAL_Lib_Pin pin, unsigned int function);
void gpio_write(HAL_Lib_Pin pin, bool value);
bool gpio_read(HAL_Lib_Pin pin);
HAL_Lib_Err gpio_config_alternate_function(HAL_Lib_Pin pin, unsigned int function);

/*
 * Timer functions
 */
/* TODO: implement timer functions */

/*
 * ADC functions
 */
HAL_Lib_Err adc_config_single(const HAL_Lib_Pin pin);
unsigned int adc_read_single(void);

/*
 * Print Initialization
 */

void host_serial_init();
void serial_write(USART_TypeDef *USARTx, const char *buffer, int len);
char serial_read(USART_TypeDef *USARTx);

#endif
