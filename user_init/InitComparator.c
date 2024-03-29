/*******************************************************************************
 *  Name of files:  InitComparator.c
 *  Description:
 *
 * Linh Vu - vu.t.linh204.work@gmail.com
 * Graduate Student
 * October 2019
 * Built with CCS v.9.3

 ********************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <user_init/InitInc.h>

void Init_Comparator0(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_COMP0);
    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_COMP0))
    {
    }
    // Set ref&configure comparator
    ComparatorRefSet(COMP_BASE, COMP_REF_0_275V);
    ComparatorConfigure(
            COMP_BASE,
            0,
            COMP_TRIG_NONE | COMP_INT_BOTH | COMP_ASRCP_REF | COMP_OUTPUT_NORMAL);
    ComparatorIntRegister(COMP_BASE, 0, &IntComparator0Handler);
    ComparatorIntEnable(COMP_BASE, 0);
    ComparatorIntClear(COMP_BASE, 0);
}

