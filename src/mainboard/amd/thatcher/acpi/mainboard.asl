/* SPDX-License-Identifier: GPL-2.0-only */
/* This file is part of the coreboot project. */

	/* Data to be patched by the BIOS during POST */
	/* FIXME the patching is not done yet! */
	/* Memory related values */
	Name(LOMH, 0x0)	/* Start of unused memory in C0000-E0000 range */
	Name(PBAD, 0x0)	/* Address of BIOS area (If TOM2 != 0, Addr >> 16) */
	Name(PBLN, 0x0)	/* Length of BIOS area */

	Name(PCBA, CONFIG_MMCONF_BASE_ADDRESS)	/* Base address of PCIe config space */
	Name(PCLN, Multiply(0x100000, CONFIG_MMCONF_BUS_NUMBER)) /* Length of PCIe config space, 1MB each bus */
	Name(HPBA, 0xFED00000)	/* Base address of HPET table */

	/* Some global data */
	Name(OSVR, 3)   /* Assume nothing. WinXp = 1, Vista = 2, Linux = 3, WinCE = 4 */
	Name(OSV, Ones) /* Assume nothing */
	Name(PMOD, One) /* Assume APIC */

	/* AcpiGpe0Blk */
	OperationRegion(GP0B, SystemMemory, 0xfed80814, 0x04)
		Field(GP0B, ByteAcc, NoLock, Preserve) {
		, 11,
		USBS, 1,
	}
