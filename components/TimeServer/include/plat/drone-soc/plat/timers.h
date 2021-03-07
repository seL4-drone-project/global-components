/*
 * Copyright 2019, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#define HARDWARE_TIMER_COMPONENT   \
    component HWTimer {            \
        hardware;                  \
        dataport Buf(0x10000) mem; \
        emits TimerIRQ irq;        \
    }

#define HARDWARE_TIMER_INTERFACES      \
    dataport Buf(0x10000) hwtimer_mem; \
    consumes TimerIRQ hwtimer_irq;

#define HARDWARE_TIMER_ATTRIBUTES

#define HARDWARE_TIMER_COMPOSITION                                             \
    component HWTimer hwtimer;                                                 \
    connection seL4HardwareMMIO hwtimer_mem(from hwtimer_mem, to hwtimer.mem); \
    connection seL4HardwareInterrupt hwtimer_irq(from hwtimer.irq,             \
                                                 to hwtimer_irq);

#define HARDWARE_TIMER_CONFIG       \
    hwtimer.mem_paddr = 0x10050000; \
    hwtimer.mem_size = 0x10000;     \
    hwtimer.irq_irq_number = 7;

#define HARDWARE_TIMER_PLAT_INTERFACES
