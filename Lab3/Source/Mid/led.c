/*******************************************************************************
 *
 * Description: Lab3
 * Project name: led.c
 *
 *
 * Last Changed By:  $Author: TrungNT $
 * Revision:         $Revision: 1.0 $
 * Last Changed:     $Date: 5/3/2021 $
 *
 ******************************************************************************/

#include "app/framework/include/af.h"
#include "led.h"
#include "em_timer.h"


typedef struct {
  GPIO_Port_TypeDef   port;
  unsigned int        pin;
  bool 				  ledBlinkMode;
  ledColor_e		  color;
  uint32_t 			  onTime;
  uint32_t			  offTime;
  uint8_t			  blinkTime;
} ledArray_t;

ledArray_t led_Array[LED_RGB_COUNT][LED_RGB_ELEMENT] = {LED_RGB_1, LED_RGB_2};

ledArray_t ledAction[LED_RGB_COUNT];

/**
 * @func    ledInit
 * @brief   Initialize LED
 * @param   None
 * @retval  None
 */
void ledInit(void)
{
	TIMER_Init_TypeDef timerInit = TIMER_DIM_INIT;
	CMU_ClockEnable(cmuClock_GPIO, true);
	CMU_ClockEnable(cmuClock_TIMER3, true);
	timerInit.prescale = (TIMER_Prescale_TypeDef)_TIMER_CFG_PRESC_DIV1;


	for(int i = 0;i <LED_RGB_COUNT;i++)
	{
		for(int j = 0; j< LED_RGB_ELEMENT;j++)
		{
			GPIO_PinModeSet(led_Array[i][j].port, led_Array[i][j].pin,
							gpioModePushPull,0);
		}
	}
	turnOffRBGLed(LED1);
	turnOffRBGLed(LED2);
}

/**
 * @func    turnOffRBGLed
 * @brief   turn Off LED
 * @param   None
 * @retval  None
 */
void turnOffRBGLed(ledNumber index)
{
	for(int j=0;j<LED_RGB_ELEMENT;j++)
	{
		GPIO_PinOutSet(led_Array[index][j].port, led_Array[index][j].pin);
	}
}
