/*******************************************************************************
 *  Name of files:  InitUART.c
 *  Description:
 *
 * Linh Vu - vu.t.linh204.work@gmail.com
 * Graduate Student
 * October 2019
 * Built with CCS v.9.2

 ********************************************************************************/

#ifndef _INITUART_H
#define _INITUART_H

#ifdef __cplusplus
extern "C" {
#endif

void Init_UART0(int32_t baudrate);
void Init_UART1(int32_t baudrate);
void Init_UART2(int32_t baudrate);
void Init_UART3(int32_t baudrate);
void Init_UART4(int32_t baudrate);
void Init_UART5(int32_t baudrate);
void Init_UART6(int32_t baudrate);
void Init_UART7(int32_t baudrate);
void Float2UART(float number);

#ifdef __cplusplus
}
#endif

#endif /* _INITUART_H */
