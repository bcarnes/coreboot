/* SPDX-License-Identifier: GPL-2.0-only */
/* This file is part of the coreboot project. */

#include <console/uart.h>

uintptr_t uart_platform_base(int idx)
{
	return (uintptr_t)(0xFEDC6000 + 0x2000 * (idx & 1));
}

unsigned int uart_platform_refclk(void)
{
	return 48000000;
}
