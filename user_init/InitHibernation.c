/*******************************************************************************
 *  Name of files:  InitHibernation.c
 *  Description:
 *
 * Linh Vu - vu.t.linh204.work@gmail.com
 * Graduate Student
 * January 2020
 * Built with CCS v.9.3

 ********************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <user_init/InitInc.h>

void Init_Hibernation(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_HIBERNATE);
    HibernateEnableExpClk(SysCtlClockGet());
    HibernateGPIORetentionEnable();
    // Set delay time for Hibernation
    SysCtlDelay(64000000);  //approx 1.6s
    HibernateRTCSet(0);
    HibernateRTCEnable();
    HibernateRTCMatchSet(0,5);
    HibernateWakeSet(HIBERNATE_WAKE_PIN | HIBERNATE_WAKE_RTC);
}
