/* SPDX-License-Identifier: GPL-2.0-only */
/* This file is part of the coreboot project. */

#include <arch/acpi.h>
#include <boardid.h>
#include <sar.h>
#include <baseboard/variants.h>
#include <delay.h>
#include <gpio.h>
#include <ec/google/chromeec/ec.h>
#include <soc/intel/apollolake/chip.h>

enum {
	SKU_37_DROID = 37, /* LTE */
	SKU_38_DROID = 38, /* LTE + Touch */
	SKU_39_DROID = 39, /* LTE + KB backlight*/
	SKU_40_DROID = 40, /* LTE + Touch + KB backlight*/
};

struct gpio_with_delay {
	gpio_t gpio;
	unsigned int delay_msecs;
};

static void power_off_lte_module(u8 slp_typ)
{
	const struct gpio_with_delay lte_power_off_gpios[] = {
		{
			GPIO_161, /* AVS_I2S1_MCLK -- PLT_RST_LTE_L */
			30,
		},
		{
			GPIO_117, /* PCIE_WAKE1_B -- FULL_CARD_POWER_OFF */
			100
		},
		{
			GPIO_67, /* UART2-CTS_B -- EN_PP3300_DX_LTE_SOC */
			0
		}
	};

	for (int i = 0; i < ARRAY_SIZE(lte_power_off_gpios); i++) {
		gpio_output(lte_power_off_gpios[i].gpio, 0);
		mdelay(lte_power_off_gpios[i].delay_msecs);
	}
}

const char *get_wifi_sar_cbfs_filename(void)
{
	const char *filename = NULL;
	uint32_t sku_id = google_chromeec_get_board_sku();

	if (sku_id == 33 || sku_id == 34 || sku_id == 35 || sku_id == 36 || sku_id == 41 ||
		sku_id == 42 || sku_id == 43 || sku_id == 44)
		filename = "wifi_sar-droid.hex";

	return filename;
}

void variant_smi_sleep(u8 slp_typ)
{
	/* Currently use cases here all target to S5 therefore we do early return
	 * here for saving one transaction to the EC for getting SKU ID. */
	if (slp_typ != ACPI_S5)
		return;

	switch (google_chromeec_get_board_sku()) {
	case SKU_37_DROID:
	case SKU_38_DROID:
	case SKU_39_DROID:
	case SKU_40_DROID:
		power_off_lte_module(slp_typ);
		return;
	default:
		return;
	}
}


void variant_update_devtree(struct device *dev)
{
	struct soc_intel_apollolake_config *cfg = NULL;

	cfg = (struct soc_intel_apollolake_config *)dev->chip_info;

	if (cfg != NULL && cfg->disable_xhci_lfps_pm) {
		switch (google_chromeec_get_board_sku()) {
		case 37:
		case 38:
		case 39:
		case 40:
			cfg->disable_xhci_lfps_pm = 1;
			return;
		default:
			return;
		}
	}
}
