/*!
 * Copyright (c) 2020-2024, Erich Styger
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * \file
 * \brief \brief Interface for the McuShellUart module.
 */

#ifndef MCUSHELLUART_H_
#define MCUSHELLUART_H_

#include "McuShellUartconfig.h"
#include "McuShell.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! Default McuShell buffer */
extern uint8_t McuShellUart_DefaultShellBuffer[McuShell_DEFAULT_SHELL_BUFFER_SIZE]; /* default buffer which can be used by the application */

/*! Standard I/O for input/output */
extern McuShell_ConstStdIOType McuShellUart_stdio;

McuShell_ConstStdIOTypePtr McuShellUart_GetStdio(void);

/*!
 * \brief Polls for an UART character, might be blocking
 * \return The character or EOF
 */
int McuShellUart_PollChar(void);

/*!
 * \brief perform muxing of the UART pins
 * \param uart One of the preconfigured and supported UART types, e.g. McuShellUart_CONFIG_UART_K22FN512_LPUART0_C3_C4
 */
void McuShellUart_MuxUartPins(int uart);

/*!
 * \brief Module de-initialization
 */
void McuShellUart_Deinit(void);

/*!
 * \brief Module initialization
 */
void McuShellUart_Init(void);

#ifdef __cplusplus
}  /* extern "C" */
#endif

#endif /* MCUSHELLUART_H_ */
