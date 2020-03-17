/*
 * This file is part of the coreboot project.
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
 * GNU General Public License for more details.
 */

#ifndef _GPIORVP7_H
#define _GPIORVP7_H

#include <soc/gpe.h>
#include <soc/gpio.h>

/* TCA6424A  I/O Expander */
#define IO_EXPANDER_BUS		4
#define IO_EXPANDER_0_ADDR	0x22
#define IO_EXPANDER_P0CONF	0x0C	/* Port 0 conf offset */
#define IO_EXPANDER_P0DOUT	0x04	/* Port 0 data offset */
#define IO_EXPANDER_P1CONF	0x0D
#define IO_EXPANDER_P1DOUT	0x05
#define IO_EXPANDER_P2CONF	0x0E
#define IO_EXPANDER_P2DOUT	0x06
#define IO_EXPANDER_1_ADDR	0x23


/* GPE_EC_WAKE */
#define GPE_EC_WAKE		GPE0_LAN_WAK

/* CHROMEEC in RVP */
#define EC_SCI_GPI		GPP_E16
#define EC_SMI_GPI		GPP_E15
/*
 * Gpio based irq for touchpad, 18th index in North Bank
 * MAX_DIRECT_IRQ + GPSW_SIZE + 19
 */
#define KBLRVP_TOUCHPAD_IRQ	33

#define KBLRVP_TOUCH_IRQ	31

#define BOARD_TOUCHPAD_NAME		"touchpad"
#define BOARD_TOUCHPAD_IRQ		KBLRVP_TOUCHPAD_IRQ
#define BOARD_TOUCHPAD_I2C_BUS		0
#define BOARD_TOUCHPAD_I2C_ADDR		0x20

#define BOARD_TOUCHSCREEN_NAME		"touchscreen"
#define BOARD_TOUCHSCREEN_IRQ		KBLRVP_TOUCH_IRQ
#define BOARD_TOUCHSCREEN_I2C_BUS	0
#define BOARD_TOUCHSCREEN_I2C_ADDR	0x4c

#ifndef __ACPI__

/* Pad configuration in ramstage. */
static const struct pad_config gpio_table[] = {
/* PM_SLP_S0ix_R_N*/	PAD_CFG_GPO(GPP_A7, 1, DEEP),
/* LPC_CLKRUN */	PAD_CFG_NF(GPP_A8, NONE, DEEP, NF1),
/* PCH_CLK_PCI_TPM */	PAD_CFG_NF(GPP_A10, NONE, DEEP, NF1),
/* PCH_LPC_CLK */	PAD_CFG_GPI_APIC(GPP_A11, NONE, DEEP),
/* ISH_KB_PROX_INT */	PAD_CFG_GPO(GPP_A12, 1, RSMRST),
/* PCH_SUSPWRACB */	PAD_CFG_NF(GPP_A13, NONE, DEEP, NF1),
/* PCH_SUSACK */	PAD_CFG_NF(GPP_A15, 20K_PD, DEEP, NF1),
/* SD_1P8_SEL */	PAD_CFG_NF(GPP_A16, NONE, DEEP, NF1),
/* SD_PWR_EN */		PAD_CFG_NF(GPP_A17, NONE, DEEP, NF1),
/* ACCEL INTERRUPT */	PAD_CFG_NF(GPP_A18, NONE, DEEP, NF1),
/* ISH_GP1 */		PAD_CFG_NF(GPP_A19, NONE, DEEP, NF1),
/* GYRO_DRDY */		PAD_CFG_NF(GPP_A20, NONE, DEEP, NF1),
/* FLIP_ACCEL_INT */	PAD_CFG_NF(GPP_A21, NONE, DEEP, NF1),
/* GYRO_INT */		PAD_CFG_GPO(GPP_A22, 1, DEEP),
/* ISH_GP5 */		PAD_CFG_GPI_APIC(GPP_A23, NONE, DEEP),
/* CORE_VID0 */		PAD_CFG_NF(GPP_B0, NONE, DEEP, NF1),
/* CORE_VID1 */		PAD_CFG_NF(GPP_B1, NONE, DEEP, NF1),
/* HSJ_MIC_DET */	PAD_CFG_NF(GPP_B2, NONE, DEEP, NF1),
/* TRACKPAD_INT */	PAD_CFG_GPI_APIC(GPP_B3, NONE, PLTRST),
/* BT_RF_KILL */	PAD_CFG_GPO(GPP_B4, 1, DEEP),
/* SRCCLKREQ0# */	PAD_CFG_GPI_APIC(GPP_B5, NONE, DEEP),
/* MPHY_EXT_PWR_GATE */	PAD_CFG_NF(GPP_B11, NONE, DEEP, NF1),
/* PM_SLP_S0 */		PAD_CFG_NF(GPP_B12, NONE, DEEP, NF1),
/* PCH_PLT_RST */	PAD_CFG_NF(GPP_B13, NONE, DEEP, NF1),
/* GPP_B_14_SPKR */	PAD_CFG_TERM_GPO(GPP_B14, 1, 20K_PD, DEEP),
/* WLAN_PCIE_WAKE */	PAD_CFG_GPI_ACPI_SCI(GPP_B16, NONE, PLTRST, YES),
/* TBT_CIO_PLUG_EVT */	PAD_CFG_GPI_ACPI_SCI(GPP_B17, 20K_PU, PLTRST, YES),
/* PCH_SLOT1_WAKE_N */	PAD_CFG_GPI_ACPI_SCI(GPP_B18, 20K_PU, PLTRST, YES),
/* CCODEC_SPI_CS */	PAD_CFG_NF(GPP_B19, NONE, DEEP, NF1),
/* CODEC_SPI_CLK */	PAD_CFG_NF(GPP_B20, 20K_PD, DEEP, NF1),
/* CODEC_SPI_MISO */	PAD_CFG_NF(GPP_B21, 20K_PD, DEEP, NF1),
/* CODEC_SPI_MOSI */	PAD_CFG_NF(GPP_B22, 20K_PD, DEEP, NF1),
/* SM1ALERT# */		PAD_CFG_TERM_GPO(GPP_B23, 1, 20K_PD, DEEP),
/* SMB_CLK */		PAD_CFG_NF(GPP_C0, NONE, DEEP, NF1),
/* SMB_DATA */		PAD_CFG_NF(GPP_C1, 20K_PD, DEEP, NF1),
/* SMBALERT# */		PAD_CFG_TERM_GPO(GPP_C2, 1, 20K_PD, DEEP),
/* M2_WWAN_PWREN */	PAD_CFG_NF(GPP_C3, NONE, DEEP, NF1),
/* SML0DATA */		PAD_CFG_NF(GPP_C4, NONE, DEEP, NF1),
/* SML0ALERT# */	PAD_CFG_GPI_APIC(GPP_C5, 20K_PD, DEEP),
/* EC_IN_RW */		PAD_CFG_NF(GPP_C6, NONE, DEEP, NF1),
/* USB_CTL */		PAD_CFG_NF(GPP_C7, 20K_PD, DEEP, NF1),
/* UART0_RXD */		PAD_CFG_NF(GPP_C8, NONE, DEEP, NF1),
/* UART0_TXD */		PAD_CFG_NF(GPP_C9, NONE, DEEP, NF1),
/* NFC_RST* */		PAD_CFG_NF(GPP_C10, NONE, DEEP, NF1),
/* EN_PP3300_KEPLER */	PAD_CFG_NF(GPP_C11, NONE, DEEP, NF1),
/* PCH_MEM_CFG0 */	PAD_CFG_NF(GPP_C12, NONE, DEEP, NF1),
/* PCH_MEM_CFG1 */	PAD_CFG_NF(GPP_C13, NONE, DEEP, NF1),
/* PCH_MEM_CFG2 */	PAD_CFG_NF(GPP_C14, NONE, DEEP, NF1),
/* PCH_MEM_CFG3 */	PAD_CFG_NF(GPP_C15, NONE, DEEP, NF1),
/* I2C0_SDA */		PAD_CFG_NF(GPP_C16, NONE, DEEP, NF1),
/* I2C0_SCL */		PAD_CFG_NF(GPP_C17, NONE, DEEP, NF1),
/* I2C1_SDA */		PAD_CFG_NF(GPP_C18, NONE, DEEP, NF1),
/* I2C1_SCL */		PAD_CFG_NF(GPP_C19, NONE, DEEP, NF1),
/* GD_UART2_RXD */	PAD_CFG_NF(GPP_C20, NONE, DEEP, NF1),
/* GD_UART2_TXD */	PAD_CFG_NF(GPP_C21, NONE, DEEP, NF1),
/* TCH_PNL_PWREN */	PAD_CFG_NF(GPP_C22, NONE, DEEP, NF1),
/* SPI_WP_STATUS */	PAD_CFG_NF(GPP_C23, NONE, DEEP, NF1),
/* ITCH_SPI_CS */	PAD_CFG_NF(GPP_D0, NONE, DEEP, NF1),
/* ITCH_SPI_CLK */	PAD_CFG_NF(GPP_D1, NONE, DEEP, NF1),
/* ITCH_SPI_MISO_1 */	PAD_CFG_NF(GPP_D2, NONE, DEEP, NF1),
/* ITCH_SPI_MISO_0 */	PAD_CFG_NF(GPP_D3, NONE, DEEP, NF1),
/* CAM_FLASH_STROBE */	PAD_CFG_NF(GPP_D4, NONE, DEEP, NF1),
/* EN_PP3300_DX_EMMC */	PAD_CFG_NF(GPP_D5, NONE, DEEP, NF1),
/* EN_PP1800_DX_EMMC */	PAD_CFG_NF(GPP_D6, NONE, DEEP, NF1),
/* SH_I2C1_SDA */	PAD_CFG_NF(GPP_D7, NONE, DEEP, NF1),
/* SH_I2C1_SCL */	PAD_CFG_NF(GPP_D8, NONE, DEEP, NF1),
			PAD_CFG_GPI_GPIO_DRIVER(GPP_D9, NONE, DEEP),
/* SD_D3_WAKE */	PAD_CFG_GPI_GPIO_DRIVER(GPP_D10, NONE, DEEP),
/* USB_A1_ILIM_SEL */	PAD_CFG_GPI_GPIO_DRIVER(GPP_D11, NONE, DEEP),
/* EN_PP3300_DX_CAM */	PAD_CFG_GPI_GPIO_DRIVER(GPP_D12, NONE, DEEP),
/* EN_PP1800_DX_AUDIO */PAD_CFG_NF(GPP_D13, NONE, DEEP, NF1),
/* ISH_UART0_TXD */	PAD_CFG_NF(GPP_D14, NONE, DEEP, NF1),
/* ISH_UART0_RTS */	PAD_CFG_NF(GPP_D15, NONE, DEEP, NF1),
/* ISH_UART0_CTS */	PAD_CFG_NF(GPP_D16, NONE, DEEP, NF1),
/* DMIC_CLK_1 */	PAD_CFG_NF(GPP_D17, NONE, DEEP, NF1),
/* DMIC_DATA_1 */	PAD_CFG_NF(GPP_D18, 20K_PD, DEEP, NF1),
/* DMIC_CLK_0 */	PAD_CFG_NF(GPP_D19, NONE, DEEP, NF1),
/* DMIC_DATA_0 */	PAD_CFG_NF(GPP_D20, 20K_PD, DEEP, NF1),
/* ITCH_SPI_D2 */	PAD_CFG_NF(GPP_D21, NONE, DEEP, NF1),
/* ITCH_SPI_D3 */	PAD_CFG_NF(GPP_D22, NONE, DEEP, NF1),
/* I2S_MCLK */		PAD_CFG_NF(GPP_D23, NONE, DEEP, NF1),
/* SPI_TPM_IRQ */	PAD_CFG_GPI_APIC(GPP_E0, 20K_PD, DEEP),
/* SATAXPCIE1 */	PAD_CFG_NF(GPP_E1, NONE, DEEP, NF1),
/* SSD_PEDET */		PAD_CFG_GPI_GPIO_DRIVER(GPP_E2, NONE, DEEP),
/* CPU_GP0 */		PAD_CFG_GPO(GPP_E3, 1, RSMRST),
/* SATA_DEVSLP1 */	PAD_CFG_NF(GPP_E5, NONE, DEEP, NF1),
/* SATA_DEVSLP2 */	PAD_CFG_NF(GPP_E6, NONE, DEEP, NF1),
			PAD_CFG_NF(GPP_E8, NONE, DEEP, NF1),
/* USB2_OC_0 */		PAD_CFG_NF(GPP_E9, NONE, DEEP, NF1),
/* USB2_OC_1 */		PAD_CFG_NF(GPP_E10, NONE, DEEP, NF1),
/* USB2_OC_2 */		PAD_CFG_NF(GPP_E11, NONE, DEEP, NF1),
/* DDI1_HPD */		PAD_CFG_NF(GPP_E13, NONE, DEEP, NF1),
/* DDI2_HPD */		PAD_CFG_NF(GPP_E14, NONE, DEEP, NF1),
/* EC_SMI */		PAD_CFG_GPI_ACPI_SMI(GPP_E15, NONE, DEEP, YES),
/* EC_SCI */		PAD_CFG_GPI_ACPI_SCI(GPP_E16, NONE, PLTRST, YES),
/* EDP_HPD */		PAD_CFG_NF(GPP_E17, NONE, DEEP, NF1),
/* DDPB_CTRLCLK */	PAD_CFG_NF(GPP_E18, NONE, DEEP, NF1),
/* DDPB_CTRLDATA */	PAD_CFG_NF(GPP_E19, 20K_PD, DEEP, NF1),
/* DDPC_CTRLCLK */	PAD_CFG_NF(GPP_E20, NONE, DEEP, NF1),
/* DDPC_CTRLDATA */	PAD_CFG_NF(GPP_E21, NONE, DEEP, NF1),
/* PCH_CODEC_IRQ */	PAD_CFG_GPI_APIC(GPP_E22, NONE, DEEP),
/* TCH_PNL_RST */	PAD_CFG_TERM_GPO(GPP_E23, 1, 20K_PD, DEEP),
/* I2S2_SCLK */		PAD_CFG_NF(GPP_F0, NONE, DEEP, NF1),
/* I2S2_SFRM */		PAD_CFG_NF(GPP_F1, NONE, DEEP, NF1),
/* I2S2_TXD */		PAD_CFG_NF(GPP_F2, NONE, DEEP, NF1),
/* I2S2_RXD */		PAD_CFG_NF(GPP_F3, NONE, DEEP, NF1),
/* I2C2_SDA */		PAD_CFG_NF(GPP_F4, NONE, DEEP, NF1),
/* I2C2_SCL */		PAD_CFG_NF(GPP_F5, NONE, DEEP, NF1),
/* I2C3_SDA */		PAD_CFG_NF(GPP_F6, NONE, DEEP, NF1),
/* I2C3_SCL */		PAD_CFG_NF(GPP_F7, NONE, DEEP, NF1),
/* I2C4_SDA */		PAD_CFG_NF(GPP_F8, NONE, DEEP, NF1),
/* I2C4_SDA */		PAD_CFG_NF(GPP_F9, NONE, DEEP, NF1),
/* AUDIO_IRQ */		PAD_CFG_NF(GPP_F10, NONE, DEEP, NF2),
/* I2C5_SCL */		PAD_CFG_NF(GPP_F11, NONE, DEEP, NF2),
/* EMMC_CMD */		PAD_CFG_NF(GPP_F12, NONE, DEEP, NF1),
/* EMMC_DATA0 */	PAD_CFG_NF(GPP_F13, NONE, DEEP, NF1),
/* EMMC_DATA1 */	PAD_CFG_NF(GPP_F14, NONE, DEEP, NF1),
/* EMMC_DATA2 */	PAD_CFG_NF(GPP_F15, NONE, DEEP, NF1),
/* EMMC_DATA3 */	PAD_CFG_NF(GPP_F16, NONE, DEEP, NF1),
/* EMMC_DATA4 */	PAD_CFG_NF(GPP_F17, NONE, DEEP, NF1),
/* EMMC_DATA5 */	PAD_CFG_NF(GPP_F18, NONE, DEEP, NF1),
/* EMMC_DATA6 */	PAD_CFG_NF(GPP_F19, NONE, DEEP, NF1),
/* EMMC_DATA7 */	PAD_CFG_NF(GPP_F20, NONE, DEEP, NF1),
/* EMMC_RCLK */		PAD_CFG_NF(GPP_F21, NONE, DEEP, NF1),
/* EMMC_CLK */		PAD_CFG_NF(GPP_F22, NONE, DEEP, NF1),
/* WWAN_UIM_SIM_DET */	PAD_CFG_GPI_APIC(GPP_F23, NONE, DEEP),
/* SD_CMD */		PAD_CFG_NF(GPP_G0, NONE, DEEP, NF1),
/* SD_DATA0 */		PAD_CFG_NF(GPP_G1, NONE, DEEP, NF1),
/* SD_DATA1 */		PAD_CFG_NF(GPP_G2, NONE, DEEP, NF1),
/* SD_DATA2 */		PAD_CFG_NF(GPP_G3, NONE, DEEP, NF1),
/* SD_DATA3 */		PAD_CFG_NF(GPP_G4, NONE, DEEP, NF1),
/* SD_CD# */		PAD_CFG_NF(GPP_G5, NONE, DEEP, NF1),
/* SD_CLK */		PAD_CFG_NF(GPP_G6, NONE, DEEP, NF1),
/* SD_WP */		PAD_CFG_NF(GPP_G7, NONE, DEEP, NF1),
/* PCH_BATLOW */	PAD_CFG_NF(GPD0, NONE, DEEP, NF1),
/* EC_PCH_ACPRESENT */	PAD_CFG_NF(GPD1, NONE, DEEP, NF1),
/* EC_PCH_WAKE */	PAD_CFG_NF(GPD2, NONE, DEEP, NF1),
/* EC_PCH_PWRBTN */	PAD_CFG_NF(GPD3, 20K_PU, DEEP, NF1),
/* PM_SLP_S3# */	PAD_CFG_NF(GPD4, NONE, DEEP, NF1),
/* PM_SLP_S4# */	PAD_CFG_NF(GPD5, NONE, DEEP, NF1),
/* PM_SLP_SA# */	PAD_CFG_NF(GPD6, NONE, DEEP, NF1),
			PAD_CFG_NF(GPD7, NONE, DEEP, NF1),
/* PM_SUSCLK */		PAD_CFG_NF(GPD8, NONE, DEEP, NF1),
/* PCH_SLP_WLAN# */	PAD_CFG_NF(GPD9, NONE, DEEP, NF1),
/* PM_SLP_S5# */	PAD_CFG_NF(GPD10, NONE, DEEP, NF1),
/* LANPHYC */		PAD_CFG_NF(GPD11, NONE, DEEP, NF1),
};

/* Early pad configuration in romstage. */
static const struct pad_config early_gpio_table[] = {
/* UART0_RXD */		PAD_CFG_NF(GPP_C8, NONE, DEEP, NF1),
/* UART0_TXD */		PAD_CFG_NF(GPP_C9, NONE, DEEP, NF1),
};


#endif

#endif
