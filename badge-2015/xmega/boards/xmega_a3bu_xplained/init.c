/**
 * \file
 *
 * \brief XMEGA-A3BU Xplained board init.
 *
 * This file contains board initialization function.
 *
 * Copyright (c) 2010-2015 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include <conf_board.h>
#include <board.h>
#include <ioport.h>

/**
 * \addtogroup xmega_a3bu_xplained_group
 * @{
 */

void board_init(void)
{
	ioport_configure_pin(LED0_GPIO, IOPORT_DIR_OUTPUT | IOPORT_INIT_HIGH | IOPORT_INV_ENABLED);
	
	
	// ioport_configure_pin(LED1_GPIO, IOPORT_DIR_OUTPUT | IOPORT_INIT_HIGH);
	// ioport_configure_pin(LED2_GPIO, IOPORT_DIR_OUTPUT | IOPORT_INIT_HIGH);
	// ioport_configure_pin(LED3_GPIO, IOPORT_DIR_OUTPUT | IOPORT_INIT_LOW
	// 		| IOPORT_INV_ENABLED);

	//ioport_configure_pin(IOPORT_CREATE_PIN(PORTB, 1), IOPORT_DIR_INPUT);

	ioport_configure_pin(GPIO_PUSH_BUTTON_UP, IOPORT_DIR_INPUT
			| IOPORT_LEVEL | IOPORT_PULL_UP);
	ioport_configure_pin(GPIO_PUSH_BUTTON_DOWN, IOPORT_DIR_INPUT
			| IOPORT_LEVEL | IOPORT_PULL_UP);
	ioport_configure_pin(GPIO_PUSH_BUTTON_LEFT, IOPORT_DIR_INPUT
			| IOPORT_LEVEL | IOPORT_PULL_UP);
	ioport_configure_pin(GPIO_PUSH_BUTTON_RIGHT, IOPORT_DIR_INPUT
			| IOPORT_LEVEL | IOPORT_PULL_UP);
	
	ioport_configure_pin(GPIO_PUSH_BUTTON_START, IOPORT_DIR_INPUT
			| IOPORT_LEVEL | IOPORT_PULL_UP);
	ioport_configure_pin(GPIO_PUSH_BUTTON_SELECT, IOPORT_DIR_INPUT
			| IOPORT_LEVEL | IOPORT_PULL_UP);

	ioport_configure_pin(GPIO_PUSH_BUTTON_A, IOPORT_DIR_INPUT
			| IOPORT_LEVEL | IOPORT_PULL_UP);
	ioport_configure_pin(GPIO_PUSH_BUTTON_B, IOPORT_DIR_INPUT
			| IOPORT_LEVEL | IOPORT_PULL_UP);

	ioport_configure_pin(ESP_CH_PD,   IOPORT_DIR_OUTPUT | IOPORT_INIT_HIGH);
	ioport_configure_pin(ESP_RST_FET, IOPORT_DIR_OUTPUT | IOPORT_INIT_LOW);
	ioport_configure_pin(ESP_GP0_FET, IOPORT_DIR_OUTPUT | IOPORT_INIT_LOW);

	ioport_configure_pin(BUZZER_PWM,   IOPORT_DIR_OUTPUT);
	ioport_configure_pin(BUZZER_GND,   IOPORT_DIR_OUTPUT | IOPORT_INIT_LOW);


	ioport_configure_pin(MMA8451INT1, IOPORT_DIR_INPUT | IOPORT_MODE_PULLUP);
	PORTF.INTCTRL |= PORT_INT0LVL_LO_gc;
	PORTF.INT0MASK |= PIN2_bm;

	
	ioport_configure_pin(MMA8451INT2, IOPORT_DIR_INPUT | IOPORT_MODE_PULLUP);
	PORTF.INTCTRL |= PORT_INT1LVL_LO_gc;
	PORTF.INT1MASK |= PIN1_bm;



	//Motion Detector


#ifdef CONF_BOARD_C12832A1Z
	ioport_configure_pin(NHD_C12832A1Z_SPI_SCK, IOPORT_DIR_OUTPUT
			| IOPORT_INIT_HIGH);
	ioport_configure_pin(NHD_C12832A1Z_SPI_MOSI, IOPORT_DIR_OUTPUT
			| IOPORT_INIT_HIGH);
	ioport_configure_pin(NHD_C12832A1Z_CSN, IOPORT_DIR_OUTPUT
			| IOPORT_INIT_HIGH);
	ioport_configure_pin(NHD_C12832A1Z_REGISTER_SELECT, IOPORT_DIR_OUTPUT
			| IOPORT_INIT_HIGH);
	ioport_configure_pin(NHD_C12832A1Z_RESETN, IOPORT_DIR_OUTPUT
			| IOPORT_INIT_HIGH);
	ioport_configure_pin(NHD_C12832A1Z_BACKLIGHT, IOPORT_DIR_OUTPUT
			| IOPORT_INIT_LOW);
#endif

#ifdef CONF_BOARD_AT45DBX
	ioport_configure_pin(AT45DBX_MASTER_SCK, IOPORT_DIR_OUTPUT
			| IOPORT_INIT_HIGH);
	ioport_configure_pin(AT45DBX_MASTER_MOSI, IOPORT_DIR_OUTPUT
			| IOPORT_INIT_HIGH);
	ioport_configure_pin(AT45DBX_MASTER_MISO, IOPORT_DIR_INPUT);
	ioport_configure_pin(AT45DBX_CS, IOPORT_DIR_OUTPUT | IOPORT_INIT_HIGH);
#endif

#ifdef CONF_BOARD_ENABLE_MXT143E_XPLAINED
	ioport_configure_pin(MXT143E_XPLAINED_SCK, IOPORT_DIR_OUTPUT
			| IOPORT_INIT_HIGH);
	ioport_configure_pin(MXT143E_XPLAINED_MOSI, IOPORT_DIR_OUTPUT
			| IOPORT_INIT_HIGH);
	ioport_configure_pin(MXT143E_XPLAINED_MISO, IOPORT_DIR_INPUT);
	ioport_configure_pin(MXT143E_XPLAINED_CS, IOPORT_DIR_OUTPUT
			| IOPORT_INIT_HIGH);
	ioport_configure_pin(MXT143E_XPLAINED_CHG, IOPORT_DIR_INPUT);
	ioport_configure_pin(MXT143E_XPLAINED_DC, IOPORT_DIR_OUTPUT
			| IOPORT_INIT_LOW);
	#ifndef MXT143E_XPLAINED_BACKLIGHT_DISABLE
	ioport_configure_pin(MXT143E_XPLAINED_BACKLIGHT, IOPORT_DIR_OUTPUT
			| IOPORT_INIT_LOW);
	#endif
	ioport_configure_pin(MXT143E_XPLAINED_LCD_RESET, IOPORT_DIR_OUTPUT
			| IOPORT_INIT_LOW);
#endif

#ifdef CONF_BOARD_ENABLE_AC_PINS
	// ioport_configure_pin(IOPORT_CREATE_PIN(PORTA, 0), IOPORT_DIR_INPUT);
	// ioport_configure_pin(IOPORT_CREATE_PIN(PORTA, 2), IOPORT_DIR_INPUT);
	//ADCB.EVCTRL=ADC_SWEEP_01_gc | ADC_EVSEL_2345_gc | ADC_EVACT_SYNCHSWEEP_gc;
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTB, 1), IOPORT_DIR_INPUT);
#endif


#ifdef CONF_BOARD_ENABLE_USARTC0
	ioport_configure_pin(IRRX, IOPORT_DIR_INPUT | IOPORT_MODE_PULLUP);

	
	//PORTC.INTCTRL |= PORT_INT0LVL_LO_gc;
	//PORTC.INT0MASK |= PIN2_bm;

	//ioport_configure_pin(IRTX, IOPORT_DIR_OUTPUT | IOPORT_INIT_HIGH);
	//ioport_configure_pin(IRTX, IOPORT_DIR_OUTPUT | IOPORT_INIT_LOW);

#endif

#ifdef CONF_BOARD_ENABLE_USARTD0
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD, 3), IOPORT_DIR_OUTPUT | IOPORT_INIT_HIGH );
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTD, 2), IOPORT_DIR_INPUT);
#endif

#ifdef CONF_BOARD_ENABLE_USARTE0
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTE, 3), IOPORT_DIR_OUTPUT
			| IOPORT_INIT_HIGH);
	ioport_configure_pin(IOPORT_CREATE_PIN(PORTE, 2), IOPORT_DIR_INPUT);
#endif

#if defined (SENSORS_XPLAINED_BOARD)
	/* Configure the Xplained Sensor extension board, if any, after
	 * the platform Xplained board has configured basic clock settings,
	 * GPIO pin mapping, interrupt controller options, etc.
	 */
	sensor_board_init ();
#endif

#ifdef CONF_BOARD_AT86RFX
	ioport_configure_pin(AT86RFX_SPI_SCK, IOPORT_DIR_OUTPUT
			| IOPORT_INIT_HIGH);
	ioport_configure_pin(AT86RFX_SPI_MOSI, IOPORT_DIR_OUTPUT
			| IOPORT_INIT_HIGH);
	ioport_configure_pin(AT86RFX_SPI_MISO, IOPORT_DIR_INPUT);
	ioport_configure_pin(AT86RFX_SPI_CS, IOPORT_DIR_OUTPUT | IOPORT_INIT_HIGH);

	/* Initialize TRX_RST and SLP_TR as GPIO. */
	ioport_configure_pin(AT86RFX_RST_PIN, IOPORT_DIR_OUTPUT | IOPORT_INIT_HIGH);
	ioport_configure_pin(AT86RFX_SLP_PIN, IOPORT_DIR_OUTPUT | IOPORT_INIT_HIGH);
#endif
}

/**
 * @}
 */