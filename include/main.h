#ifndef _MAIN_H
#define _MAIN_H

#include <avr/io.h>
#include <avr/interrupt.h>
#include <Arduino.h>


#define RETURN_NORMAL 0
#define RETURN_ERROR 1

//------------------------------------------------------------------
// Error codes  
//------------------------------------------------------------------

#define ERROR_SCH_TOO_MANY_TASKS (1)
#define ERROR_SCH_CANNOT_DELETE_TASK (2)

#define ERROR_SCH_WAITING_FOR_SLAVE_TO_ACK (3)
#define ERROR_SCH_WAITING_FOR_START_COMMAND_FROM_MASTER (3)

#define ERROR_SCH_ONE_OR_MORE_SLAVES_DID_NOT_START (4)
#define ERROR_SCH_LOST_SLAVE (5)

#define ERROR_SCH_CAN_BUS_ERROR (6)

#define ERROR_I2C_WRITE_BYTE (10)
#define ERROR_I2C_READ_BYTE (11)
#define ERROR_I2C_WRITE_BYTE_AT24C64 (12)
#define ERROR_I2C_READ_BYTE_AT24C64 (13)
#define ERROR_I2C_DS1621 (14)

#define ERROR_USART_TI (21)
#define ERROR_USART_WRITE_CHAR (22)

#define ERROR_SPI_EXCHANGE_BYTES_TIMEOUT (31)
#define ERROR_SPI_X25_TIMEOUT (32)
#define ERROR_SPI_MAX1110_TIMEOUT (33)

#define ERROR_ADC_MAX150_TIMEOUT (44)


#endif

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
