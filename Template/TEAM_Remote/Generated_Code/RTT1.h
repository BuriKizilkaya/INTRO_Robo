/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : RTT1.h
**     Project     : TEAM_Remote
**     Processor   : MK20DX128VFT5
**     Component   : SeggerRTT
**     Version     : Component 01.086, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2018-09-17, 23:15, # CodeGen: 0
**     Abstract    :
**
**     Settings    :
**          Component name                                 : RTT1
**          Version                                        : V6.32b
**          Number of Up Channels                          : 3
**          Number of Down Channels                        : 3
**          Max Blocked Interrupt Level                    : 3
**          Syscalls                                       : no
**          Channel 0                                      : Enabled
**            Name                                         : "Terminal"
**            Up Buffer Size (Tx)                          : 512
**            Down Buffer Size (Rx)                        : 64
**            Up Buffer Mode                               : Skip (Default)
**            Down Buffer Mode                             : Skip (Default)
**            Blocking Send                                : Enabled
**              Timeout (ms)                               : 10
**              Wait                                       : WAIT1
**              Wait Time (ms)                             : 1
**            Printf Buffer Size                           : 64
**          SDK                                            : MCUC1
**          Shell                                          : CLS1
**          Source Folders                                 : 
**            Source Folder                                : 
**            Config Folder                                : 
**     Contents    :
**         Read             - int RTT1_Read(unsigned BufferIndex, const char* pBuffer, unsigned NumBytes);
**         Write            - int RTT1_Write(unsigned BufferIndex, char* pBuffer, unsigned BufferSize);
**         WriteString      - unsigned RTT1_WriteString(unsigned BufferIndex, const char* s);
**         printf           - int RTT1_printf(unsigned BufferIndex, const char* sFormat, ...);
**         GetKey           - dword RTT1_GetKey(void);
**         WaitKey          - long RTT1_WaitKey(void);
**         HasKey           - long RTT1_HasKey(void);
**         SetTerminal      - int RTT1_SetTerminal(char TerminalId);
**         TerminalOut      - int RTT1_TerminalOut(char TerminalId, const char* s);
**         ConfigUpBuffer   - int RTT1_ConfigUpBuffer(unsigned BufferIndex, const char* sName, char*...
**         ConfigDownBuffer - int RTT1_ConfigDownBuffer(unsigned BufferIndex, const char* sName, char*...
**         RecvChar         - uint8_t RTT1_RecvChar(uint8_t *c);
**         SendChar         - uint8_t RTT1_SendChar(uint8_t ch);
**         GetCharsInRxBuf  - uint16_t RTT1_GetCharsInRxBuf(void);
**         StdIOKeyPressed  - bool RTT1_StdIOKeyPressed(void);
**         StdIOReadChar    - void RTT1_StdIOReadChar(uint8_t *c);
**         StdIOSendChar    - void RTT1_StdIOSendChar(uint8_t ch);
**         GetStdio         - %@Shell@'ModuleName'%.ConstStdIOTypePtr RTT1_GetStdio(void);
**         Deinit           - void RTT1_Deinit(void);
**         Init             - void RTT1_Init(void);
**
**Copyright : 1997 - 2015 Freescale Semiconductor, Inc. 
**All Rights Reserved.
**
**Redistribution and use in source and binary forms, with or without modification,
**are permitted provided that the following conditions are met:
**
**o Redistributions of source code must retain the above copyright notice, this list
**  of conditions and the following disclaimer.
**
**o Redistributions in binary form must reproduce the above copyright notice, this
**  list of conditions and the following disclaimer in the documentation and/or
**  other materials provided with the distribution.
**
**o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**  contributors may be used to endorse or promote products derived from this
**  software without specific prior written permission.
**
**THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**http: www.freescale.com
**mail: support@freescale.com
** ###################################################################*/
/*!
** @file RTT1.h
** @version 01.00
** @brief
**
*/         
/*!
**  @addtogroup RTT1_module RTT1 module documentation
**  @{
*/         

#ifndef __RTT1_H
#define __RTT1_H

/* MODULE RTT1. */
#include "MCUC1.h" /* SDK and API used */
#include "RTT1config.h" /* configuration */

/* Include inherited components */
#include "WAIT1.h"
#include "MCUC1.h"
#include "CLS1.h"


#include "SEGGER_RTT.h"


#define RTT1_RTT_CHANNEL_0_ENABLED   1  /* 0: channel disabled, 1: channel enabled */

extern uint8_t RTT1_DefaultShellBuffer[CLS1_DEFAULT_SHELL_BUFFER_SIZE]; /* default buffer which can be used by the application */
extern CLS1_ConstStdIOType RTT1_stdio; /* default standard I/O */

#ifdef __cplusplus
extern "C" {
#endif

#define RTT1_Read(BufferIndex, pBuffer, NumBytes) \
  SEGGER_RTT_Read(BufferIndex, pBuffer, NumBytes)

/*
** ===================================================================
**     Method      :  RTT1_Read (component SeggerRTT)
**     Description :
**         Read from buffer
**     Parameters  :
**         NAME            - DESCRIPTION
**         BufferIndex     - Buffer/channel to be used.
**                           0 for terminal.
**       * pBuffer         - Pointer to buffer
**         BufferSize      - Number of bytes to write
**     Returns     :
**         ---             - Number of bytes that have been read
** ===================================================================
*/

#define RTT1_Write(BufferIndex, pBuffer, BufferSize) \
  SEGGER_RTT_Write(BufferIndex, pBuffer, BufferSize)

/*
** ===================================================================
**     Method      :  RTT1_Write (component SeggerRTT)
**     Description :
**         Write to buffer
**     Parameters  :
**         NAME            - DESCRIPTION
**         BufferIndex     - Buffer/channel to be used.
**                           0 for terminal.
**       * pBuffer         - Pointer to buffer
**         BufferSize      - Size of buffer
**     Returns     :
**         ---             - Number of bytes which have been written to
**                           the up buffer
** ===================================================================
*/

#define RTT1_WriteString(BufferIndex, s) \
  SEGGER_RTT_WriteString(BufferIndex, s)

/*
** ===================================================================
**     Method      :  RTT1_WriteString (component SeggerRTT)
**     Description :
**         Write to buffer
**     Parameters  :
**         NAME            - DESCRIPTION
**         BufferIndex     - Buffer/channel to be used.
**                           0 for terminal.
**       * s               - Pointer to 
**     Returns     :
**         ---             - Number of bytes which have been stored in
**                           the "Up"-buffer.
** ===================================================================
*/

#define RTT1_GetKey() \
  SEGGER_RTT_GetKey()

/*
** ===================================================================
**     Method      :  RTT1_GetKey (component SeggerRTT)
**     Description :
**         Returns a character/key
**     Parameters  : None
**     Returns     :
**         ---             - character code
** ===================================================================
*/

#define RTT1_WaitKey() \
  SEGGER_RTT_WaitKey()

/*
** ===================================================================
**     Method      :  RTT1_WaitKey (component SeggerRTT)
**     Description :
**         Waits for a key and returns it.
**     Parameters  : None
**     Returns     :
**         ---             - >=0    Character which has been read.
** ===================================================================
*/

#define RTT1_HasKey() \
  SEGGER_RTT_HasKey()

/*
** ===================================================================
**     Method      :  RTT1_HasKey (component SeggerRTT)
**     Description :
**         Checks if at least one character for reading is available in
**         the SEGGER RTT buffer
**     Parameters  : None
**     Returns     :
**         ---             - 0: No characters are available to read; 1:
**                           At least one character is available.
** ===================================================================
*/

bool RTT1_StdIOKeyPressed(void);
/*
** ===================================================================
**     Method      :  RTT1_StdIOKeyPressed (component SeggerRTT)
**     Description :
**         StdIO handler for Shell
**     Parameters  : None
**     Returns     :
**         ---             - True if there are characters in teh input
**                           buffer
** ===================================================================
*/

void RTT1_StdIOReadChar(uint8_t *c);
/*
** ===================================================================
**     Method      :  RTT1_StdIOReadChar (component SeggerRTT)
**     Description :
**         StdIO Handler for reading a character. It returns a zero
**         byte if there is no character in input buffer.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * c               - Pointer to where to store the received
**                           character
**     Returns     : Nothing
** ===================================================================
*/

void RTT1_StdIOSendChar(uint8_t ch);
/*
** ===================================================================
**     Method      :  RTT1_StdIOSendChar (component SeggerRTT)
**     Description :
**         StdIO handler to sends a character.
**     Parameters  :
**         NAME            - DESCRIPTION
**         ch              - Character to send
**     Returns     : Nothing
** ===================================================================
*/

uint8_t RTT1_RecvChar(uint8_t *c);
/*
** ===================================================================
**     Method      :  RTT1_RecvChar (component SeggerRTT)
**     Description :
**         Receives a character from channel 0. Returns ERR_RXEMPTY if
**         no character available
**     Parameters  :
**         NAME            - DESCRIPTION
**       * c               - Pointer to where to store the received
**                           character
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t RTT1_SendChar(uint8_t ch);
/*
** ===================================================================
**     Method      :  RTT1_SendChar (component SeggerRTT)
**     Description :
**         Sends a character to channel 0.
**     Parameters  :
**         NAME            - DESCRIPTION
**         ch              - Character to send
**     Returns     :
**         ---             - Error code. ERR_OK if character has been
**                           sent, ERR_TXFULL otherwise.
** ===================================================================
*/

#define RTT1_GetCharsInRxBuf() \
  SEGGER_RTT_HasKey()

/*
** ===================================================================
**     Method      :  RTT1_GetCharsInRxBuf (component SeggerRTT)
**     Description :
**         Returns the number of characters in the receive buffer.
**     Parameters  : None
**     Returns     :
**         ---             - Number of characters in the input buffer,
**                           zero for none available.
** ===================================================================
*/

void RTT1_Init(void);

/*
** ===================================================================
**     Method      :  RTT1_Init (component SeggerRTT)
**     Description :
**         Initializes the RTT Control Block.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define RTT1_TerminalOut(TerminalId, s) \
  SEGGER_RTT_TerminalOut(TerminalId, s)

/*
** ===================================================================
**     Method      :  RTT1_TerminalOut (component SeggerRTT)
**     Description :
**         Writes a string to the given terminal without changing the
**         terminal for channel 0.
**     Parameters  :
**         NAME            - DESCRIPTION
**         TerminalId      - TerminalId, 0..15
**       * s               - Pointer to string
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define RTT1_SetTerminal(TerminalId) \
  SEGGER_RTT_SetTerminal(TerminalId)

/*
** ===================================================================
**     Method      :  RTT1_SetTerminal (component SeggerRTT)
**     Description :
**          Sets the terminal to be used for output on channel 0.
**     Parameters  :
**         NAME            - DESCRIPTION
**         TerminalId      - Terminal ID, 0..15
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define RTT1_ConfigUpBuffer(BufferIndex, sName, pBuffer, BufferSize, Flags) \
  SEGGER_RTT_ConfigUpBuffer(BufferIndex, sName, pBuffer, BufferSize, Flags)

/*
** ===================================================================
**     Method      :  RTT1_ConfigUpBuffer (component SeggerRTT)
**     Description :
**         Configures the Up (device to host) buffer
**     Parameters  :
**         NAME            - DESCRIPTION
**         BufferIndex     - Buffer index
**         sName           - Buffer name
**       * pBuffer         - Pointer to buffer
**         intBufferSize   - Size of buffer in bytes
**         Flags           - SEGGER_RTT_MODE_NO_BLOCK_SKIP,
**                           SEGGER_RTT_MODE_NO_BLOCK_TRIM or
**                           SEGGER_RTT_MODE_BLOCK_IF_FIFO_FULL
**     Returns     :
**         ---             - Error code, >=0 OK, <0 Error
** ===================================================================
*/

#define RTT1_ConfigDownBuffer(BufferIndex, sName, pBuffer, BufferSize, Flags) \
  SEGGER_RTT_ConfigDownBuffer(BufferIndex, sName, pBuffer, BufferSize, Flags)

/*
** ===================================================================
**     Method      :  RTT1_ConfigDownBuffer (component SeggerRTT)
**     Description :
**         Configures the Down (host to device) buffer
**     Parameters  :
**         NAME            - DESCRIPTION
**         BufferIndex     - Buffer index
**         sName           - Buffer name
**       * pBuffer         - Pointer to buffer
**         intBufferSize   - Size of buffer in bytes
**         Flags           - SEGGER_RTT_MODE_NO_BLOCK_SKIP,
**                           SEGGER_RTT_MODE_NO_BLOCK_TRIM or
**                           SEGGER_RTT_MODE_BLOCK_IF_FIFO_FULL
**     Returns     :
**         ---             - Error code, >=0 OK, <0 Error
** ===================================================================
*/

#define RTT1_printf \
  SEGGER_RTT_printf

/*
** ===================================================================
**     Method      :  RTT1_printf (component SeggerRTT)
**     Description :
**         Stores a formatted string in SEGGER RTT control block. This
**         data is sent to the host.
**     Parameters  :
**         NAME            - DESCRIPTION
**         BufferIndex     - Index of "Up"-buffer to be
**                           used. (e.g. 0 for "Terminal")
**         sFormat         - Pointer to format string, followed
**                           by the arguments for conversion
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

void RTT1_Deinit(void);
/*
** ===================================================================
**     Method      :  RTT1_Deinit (component SeggerRTT)
**     Description :
**         Driver deinitialization
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

CLS1_ConstStdIOTypePtr RTT1_GetStdio(void);
/*
** ===================================================================
**     Method      :  RTT1_GetStdio (component SeggerRTT)
**     Description :
**         Returns a pointer to the standard I/O
**     Parameters  : None
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

/* END RTT1. */

#ifdef __cplusplus
}  /* extern "C" */
#endif

#endif
/* ifndef __RTT1_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
