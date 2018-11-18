/*
 * stm32_spi.h
 *
 *  Created on: 1 апр. 2017 г.
 *      Author: RomaJam
 */

#ifndef STM32_SPI_H
#define STM32_SPI_H

#include "stm32_exo.h"
#include "../../userspace/io.h"
#include "../../userspace/i2c.h"
#include "../../userspace/process.h"
#include <stdbool.h>

typedef struct  {
    IO* io;
    HANDLE process;
    int tx_length;
    unsigned int rx_length;
} SPI;

typedef struct  {
    SPI* spis[SPI_COUNT];
} SPI_DRV;

void stm32_spi_init(EXO* exo);
void stm32_spi_request(EXO* exo, IPC* ipc);


#endif /* STM32_SPI_H */
