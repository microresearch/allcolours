/*
 * adc.c - adc setup

- ADC 0-11

PA0->PA3 4

PA5->PA7 3

PC0->PC2 3

PB0(ADC4), PB1(ADC8) 2

TOTAL 12 ADC

+1 - ADC12, PC3 is ADCIN

TOTAL 13

*/
 
#include "adc.h"

void ADC1_Init(void)
{
	DMA_InitTypeDef DMA_InitStructure;
	ADC_CommonInitTypeDef ADC_CommonInitStructure;
	ADC_InitTypeDef ADC_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;

	/* enable clocks for DMA2, ADC1, GPIOA ----------------------------------*/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2 | RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOC, ENABLE);
	//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);

	/* ADC Common Init ------------------------------------------------------*/
	ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div2; // was 2
 	ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;
	ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles; // was 5?
	ADC_CommonInit(&ADC_CommonInitStructure);

	/* ADC1 Init ------------------------------------------------------------*/
	ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE; // was enable
	ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
	ADC_InitStructure.ADC_ExternalTrigConv = DISABLE;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right; // was right - in CLOUDS is left? so is 12 bits
	ADC_InitStructure.ADC_NbrOfConversion = 1;
	//	ADC_InitStructure.ADC_NbrOfChannel = 10; not existing
	ADC_Init(ADC1, &ADC_InitStructure);
	ADC_Cmd(ADC1, ENABLE);
	/*
	  PA0->PA3 4
	  PA5->PA7 3
	  PC0->PC2 3
	  PB0(ADC4), PB1(ADC8) 2
	*/

	
	// adc0,1,2,3,5,6,7
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 |GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;// as pin 4 is DAC
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL ;
	GPIO_Init(GPIOA, &GPIO_InitStructure);


	// adc9,10,11,12
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3; // +PC3 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL ;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	// adc4, adc8
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;// 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL ;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	

	/* Enable ADC1 */
	ADC_Cmd(ADC1, ENABLE);
	
	/* Start ADC1 Software Conversion */ 
	//	ADC_SoftwareStartConv(ADC1);

}



//#define FLAG_TX (1 << 6) /* port B, pin 6 */
/*
void DMA2_Stream0_IRQHandler(void)
{
	if (DMA_GetFlagStatus(DMA2_Stream0, DMA_FLAG_TCIF0) != RESET)
	{
		DMA_ClearFlag(DMA2_Stream0, DMA_FLAG_TCIF0);

		ADC_SoftwareStartConv(ADC1);
	}
	
}
*/
