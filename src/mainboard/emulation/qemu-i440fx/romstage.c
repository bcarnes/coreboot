/* SPDX-License-Identifier: GPL-2.0-only */
/* This file is part of the coreboot project. */

#include <arch/romstage.h>
#include <cbmem.h>

void mainboard_romstage_entry(void)
{
	cbmem_recovery(0);
}
