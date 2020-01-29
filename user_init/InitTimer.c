/*******************************************************************************
 *  Name of files:  InitTimer.c
 *  Description:
 *
 * Linh Vu - vu.t.linh204.work@gmail.com
 * Graduate Student
 * October 2019
 * Built with CCS v.9.2

 ********************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <user_init/InitTimer.h>
#include <user_init/InitInc.h>
#include "driverlib/timer.h"

/*Với f_clk = 80Mhz-> T_clk = 12.5ns; Mỗi bước đếm xuống của Timer sẽ tốn 12.5ns
 Để tạo ra một ngắt với chu kỳ 1s, ta sẽ cần
 ui32PeriodTimer0 = 1/(12.5*10^-9) = 80.000.000;
 Giữa TIMER và WTIMER chỉ khác nhau ở thời gian tối đa có thể quy định cho timer đếm lùi/tiến
 TIMER(5 module) gồm 2 timer nhỏ 16-bit và có thể kết hợp thành 1 timer 32-bit
 WTIMER(5 module) gồm 2 timer nhỏ 32-bit và có thể kết hợp thành 1 timer 64-bit */

#define ui32PeriodTimer0    80000000
#define ui32PeriodTimer1    80000000
#define ui32PeriodTimer2    80000000
#define ui32PeriodTimer3    80000000
#define ui32PeriodTimer4    80000000
#define ui32PeriodTimer5    80000000

// Timer 16/32-bit
// Timer mac dinh se la count down
void Init_Timer0(void)
{
    /*     Khi da set TIMER_CFG_PERIODIC thi TIMER_B khong hoat dong khi ghi vao
     * TimerLoadSet, otherword.
     * Khi da gop hai timer 16bit thanh 32bit thi ta chi la viec tren timerA va xem nhu luc nay
     * timerA la mot timer 32bit va quen hoan toan timerB. Timerboth van duoc tinh vi voi timerboth
     * thi xem nhu dong thoi ghi ca vao A va B (tuc A cung duoc ghi)
     * Tuy nhien khuyen cao chi dung timer A*/
    /*    usernote1: Thong thuong nguoi ta rat it khi dung timer le 16 bit, vi voi 16 bit thì giá trị nạp lớn
     * nhất là 2^16 tương ứng với thời gian đếm tối đa là 0.8ms quá bé. Tuy nhiên nếu muốn dùng thì dùng
     * dòng code sau
     * TimerConfigure(TIMER0_BASE, TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_ONE_SHOT | TIMER_CFG_B_ONE_SHOT);
     * Trong đó dấu | dùng để set chế độ cho từng timer đọc trang 540 Peripheral for details*/
    /*    usernote2: Với chế độ 32bit ghi vào TIMER_A ta có thể ghi được tối đa 0xFFFFFFFF tức tương đương với
     53s ở chế độ chờ.*/
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
    TimerConfigure(TIMER0_BASE, TIMER_CFG_PERIODIC);
    TimerLoadSet(TIMER0_BASE, TIMER_A, ui32PeriodTimer0 - 1);
    IntEnable(INT_TIMER0A);
    TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
    TimerEnable(TIMER0_BASE, TIMER_A);
}

void Init_Timer1(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);
    TimerConfigure(TIMER1_BASE, TIMER_CFG_PERIODIC);
    TimerLoadSet(TIMER1_BASE, TIMER_A, ui32PeriodTimer1 - 1);
    IntEnable(INT_TIMER1A);
    TimerIntEnable(TIMER1_BASE, TIMER_TIMA_TIMEOUT);
    TimerEnable(TIMER1_BASE, TIMER_A);
}

void Init_Timer2(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER2);
    TimerConfigure(TIMER2_BASE, TIMER_CFG_PERIODIC);
    TimerLoadSet(TIMER2_BASE, TIMER_A, ui32PeriodTimer2 - 1);
    IntEnable(INT_TIMER2A);
    TimerIntEnable(TIMER2_BASE, TIMER_TIMA_TIMEOUT);
    TimerEnable(TIMER2_BASE, TIMER_A);
}

void Init_Timer3(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER3);
    TimerConfigure(TIMER3_BASE, TIMER_CFG_PERIODIC);
    TimerLoadSet(TIMER3_BASE, TIMER_A, ui32PeriodTimer3 - 1);
    IntEnable(INT_TIMER3A);
    TimerIntEnable(TIMER3_BASE, TIMER_TIMA_TIMEOUT);
    TimerEnable(TIMER3_BASE, TIMER_A);
}

void Init_Timer4(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER4);
    TimerConfigure(TIMER4_BASE, TIMER_CFG_PERIODIC);
    TimerLoadSet(TIMER4_BASE, TIMER_A, ui32PeriodTimer4 - 1);
    IntEnable(INT_TIMER4A);
    TimerIntEnable(TIMER4_BASE, TIMER_TIMA_TIMEOUT);
    TimerEnable(TIMER4_BASE, TIMER_A);
}

void Init_Timer5(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER5);
    TimerConfigure(TIMER5_BASE, TIMER_CFG_PERIODIC);
    TimerLoadSet(TIMER5_BASE, TIMER_A, ui32PeriodTimer5 - 1);
    IntEnable(INT_TIMER5A);
    TimerIntEnable(TIMER5_BASE, TIMER_TIMA_TIMEOUT);
    TimerEnable(TIMER5_BASE, TIMER_A);
}
