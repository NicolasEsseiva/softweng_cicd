/**
 * \file
 * \brief Configuration header file for SDK_BitIO
 * Copyright (c) 2020, Erich Styger
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * This header file is used to configure settings of the SDK Bit I/O module.
 */

#ifndef __EN2_CONFIG_H
#define __EN2_CONFIG_H

#if McuLib_CONFIG_SDK_VERSION_USED == McuLib_CONFIG_SDK_MCUXPRESSO_2_0
  #include "pin_mux.h" /* include pin muxing header file */

  #if defined(BOARD_INITPINS_EN2_PIN)
    #define EN2_CONFIG_PIN_NUMBER    BOARD_INITPINS_EN2_PIN
  #endif
  #if defined(BOARD_INITPINS_EN2_GPIO)
    #define EN2_CONFIG_GPIO_NAME     BOARD_INITPINS_EN2_GPIO
  #endif
  #if defined(BOARD_INITPINS_EN2_PORT)
    #define EN2_CONFIG_PORT_NAME     BOARD_INITPINS_EN2_PORT
  #endif
#endif

#ifndef EN2_CONFIG_PORT_NAME
  #if McuLib_CONFIG_CPU_IS_IMXRT
    #define EN2_CONFIG_PORT_NAME       GPIO1
  #elif McuLib_CONFIG_CPU_IS_LPC
    #define EN2_CONFIG_PORT_NAME       0
  #else /* name from properties */
    #define EN2_CONFIG_PORT_NAME       PORTA
  #endif
    /*!< name of PORT, is pointer to PORT_Type */
#endif

#ifndef EN2_CONFIG_GPIO_NAME
  #if McuLib_CONFIG_CPU_IS_IMXRT
    #define EN2_CONFIG_GPIO_NAME       GPIO1
  #elif McuLib_CONFIG_CPU_IS_LPC
    #define EN2_CONFIG_GPIO_NAME       GPIO
  #elif McuLib_CONFIG_CPU_IS_KINETIS && McuLib_CONFIG_IS_KINETIS_KE
    #define EN2_CONFIG_GPIO_NAME       0
  #elif McuLib_CONFIG_CPU_IS_MCX
    #define EN2_CONFIG_GPIO_NAME       GPIO0
  #else /* name from properties */
    #define EN2_CONFIG_GPIO_NAME       GPIOA
  #endif
    /*!< name of GPIO, is pointer to GPIO_Type, not used for S32K SDK */
#endif

#ifndef EN2_CONFIG_PIN_NUMBER
  #define EN2_CONFIG_PIN_NUMBER      0u
    /*!< number of pin, type unsigned integer */
#endif

#ifndef EN2_CONFIG_PIN_SYMBOL
  #define EN2_CONFIG_PIN_SYMBOL      LED_RED
    /*!< symbolic name for pin, used for NXP SDK V1.3 */
#endif

#ifndef EN2_CONFIG_INIT_PIN_VALUE
  #define EN2_CONFIG_INIT_PIN_VALUE  0
  /*!< 0: Pin data is initialized with 0 (low); 1: pin value is initialized with 1 (high) */
#endif

/* different types of pin direction settings */
#define EN2_CONFIG_INIT_PIN_DIRECTION_NONE    (0)
#define EN2_CONFIG_INIT_PIN_DIRECTION_INPUT   (1)
#define EN2_CONFIG_INIT_PIN_DIRECTION_OUTPUT  (2)

#ifndef EN2_CONFIG_INIT_PIN_DIRECTION
  #define EN2_CONFIG_INIT_PIN_DIRECTION  EN2_CONFIG_INIT_PIN_DIRECTION_OUTPUT
#endif

#ifndef EN2_CONFIG_DO_PIN_MUXING
  #define EN2_CONFIG_DO_PIN_MUXING  0
  /*!< 1: perform pin muxing in Init(), 0: do not do pin muxing */
#endif

#ifndef EN2_CONFIG_PULL_RESISTOR
  #define EN2_CONFIG_PULL_RESISTOR  0
  /*!< pull resistor setting. 0: no pull resistor, 1: pull-up, 2: pull-down, 3: pull-up or no pull, 4: pull-down or no pull: 4: autoselect-pull */
#endif

#endif /* __EN2_CONFIG_H */
