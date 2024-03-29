/*******************************************************************************
 *  Name of files:  InitSysTick.c
 *  Description:
 *
 * Linh Vu - vu.t.linh204.work@gmail.com
 * Graduate Student
 * October 2019
 * Built with CCS v.9.2

 ********************************************************************************/

#include <stdint.h>
#include "inc/tm4c123gh6pm.h"
#include <user_init/InitSysCtl.h>
#include "driverlib/systick.h"

/*
usernote1: SysTick là một Timer chính xác.
+ Ta sẽ ghi một giá trị vào thanh ghi 24 bit. Cứ sau một Tick thì thanh ghi sẽ lại
tự trừ giá trị của mình đi một.
+ Thời gian chạy một Tick của SysTick phụ thuộc vào tần số Clock của tm4c
+ Ví dụ với Clock = 80M thì T_1tick = 1/(80*10^6)*10^9 = 12.5 (ns)
+ Hàm SysTick_Wait(delay) với delay là số lần sẽ Tick để hết hàm
+ Như vậy để kết thúc hàm SysTick_Wait sẽ phụ thuộc vào hai yếu tố
       + Tham số truyền delay
       + Tần số Clock của tm4c
+ Công thức tính thời gian đợi như sau:
    T(delay,f_clk) = delay * 1/(f_clk)*10^9 (ns)
    T(delay,f_clk) = delay * 1/(f_clk)*10^6 (us)
    T(delay,f_clk) = delay * 1/(f_clk)*10^3 (ms)
    T(delay,f_clk) = delay * 1/(f_clk)      (s)
    Ví dụ với tần số chạy 80MHz thì f_clk = 80*10^6
    1s = 10^3ms = 10^6us = 10^9ns
    Ta cần tìm tham số delay để thoả mãn thời gian T(delay,f_clk) thì chỉ cần thay vào phương
    trình tương ứng.
usernote2: Các hàm ở dưới chạy mặc định cho f_clk = 80Mhz. Nếu thay đổi f thì hãy chỉnh lại tham số delay
usernote3: Maximize uint32_t = 2^32 = 4294967296 (10 chữ số)
 */

// Initialize SysTick with busy wait running at bus clock.
void Init_SysTick(void)
{
    NVIC_ST_CTRL_R = 0;                   // disable SysTick during setup
    NVIC_ST_RELOAD_R = NVIC_ST_RELOAD_M;  // maximum reload value
    NVIC_ST_CURRENT_R = 0;                // any write to current clears it
                                          // enable SysTick with core clock
    NVIC_ST_CTRL_R = NVIC_ST_CTRL_ENABLE + NVIC_ST_CTRL_CLK_SRC;
}

// Time delay using busy wait.
// The delay parameter is in units of the core clock. (units of 20 nsec for 50 MHz clock, 12.5ns for 80MHz)
// Maximize of delay = 0xFFFFFFFF -> Maximize SysTick_Wait = delay*12.5(ns) = 53.7 (s)
// But with this line : elapsedTime = (startTime - NVIC_ST_CURRENT_R) & 0x00FFFFFF;
// It limited the maximize value of delay. So:
// Just don't use single SysTick_Wait to creat a long time Systick delay
// Using for loop to make it done!
void SysTick_Wait(uint32_t delay)
{
    volatile uint32_t elapsedTime;
    uint32_t startTime = NVIC_ST_CURRENT_R;
    do
    {
        elapsedTime = (startTime - NVIC_ST_CURRENT_R) & 0x00FFFFFF;
    }
    while (elapsedTime <= delay);
}

// Time delay using busy wait.
// This assumes 80 MHz system clock.
// Critical Note: Mọi hàm chỉ hoạt động đúng tại 80Mhz

void SysTick_Wait1us(uint32_t delay)
{
    uint32_t i;
    for (i = 0; i < delay; i++)
    {
        SysTick_Wait(80);
    }
}

void SysTick_Wait1ms(uint32_t delay)
{
    uint32_t i;
    for (i = 0; i < delay; i++)
    {
        SysTick_Wait(80000);
    }
}

void SysTick_Wait1s(uint32_t delay)
{
    uint32_t i;
    for (i = 0; i < delay; i++)
    {
        SysTick_Wait1ms(1000);
    }
}

void SysTick_Wait1m(uint32_t delay)
{
    uint32_t i;
    for (i = 0; i < delay; i++)
    {
        SysTick_Wait1s(60);
    }
}

void SysTick_Wait1h(uint32_t delay)
{
    uint32_t i;
    for (i = 0; i < delay; i++)
    {
        SysTick_Wait1m(60);
    }
}
