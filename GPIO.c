#include "GPIO.h"
#include "RCC_STM32.h" 
void GPIO_SetMode (GPIO_TYPE *GPIOx, uint8_t pin, uint8_t mode)
{
	GPIOx->MODER &= ~(0x3  << (pin * 2));
	GPIOx->MODER |=  (mode << (pin * 2));
}
void GPIO_SetOutput (GPIO_TYPE *GPIOx, uint8_t pin, uint8_t type)
{
	GPIOx->OTYPER &= ~(1    << pin);
	GPIOx->OTYPER |=  (type << pin);
}
void GPIO_SPEED 		(GPIO_TYPE *GPIOx, uint8_t pin, uint8_t speed)
{
	GPIOx->OSPEEDR &= ~(0x3   << (pin * 2));
	GPIOx->OSPEEDR |=  (speed << (pin * 2));
}
void GPIO_SetPull 	(GPIO_TYPE *GPIOx, uint8_t pin, uint8_t pull)
{
	GPIOx->PUPDR  &= ~(0x3   << (pin * 2));
	GPIOx->PUPDR  |=  (pull  << (pin * 2));
}
void GPIO_Set_AFRH 		(GPIO_TYPE *GPIOx, uint8_t pin, uint8_t afrh)
{
	GPIOx->AFRH  &= ~(0x7   << pin);
	GPIOx->AFRH  |=  (afrh  << pin);
}
void GPIO_Set_AFRL 		(GPIO_TYPE *GPIOx, uint8_t pin, uint8_t afrl)
{
	GPIOx->AFRL  &= ~(0x7   << pin);
	GPIOx->AFRL  |=  (afrl  << pin);
}

void GPIO_Config_Analog(void)
{
	CLK_CONTROL->AHB1ENR |= (1 << 0);
	GPIO_SetMode (GPIO_A_CONTROL, 0, GPIO_MODE_ANALOG); 
	GPIO_SetMode (GPIO_A_CONTROL, 1, GPIO_MODE_ANALOG);
	GPIO_SetMode (GPIO_A_CONTROL, 2, GPIO_MODE_ANALOG);
	GPIO_SetMode (GPIO_A_CONTROL, 3, GPIO_MODE_ANALOG);
}
void GPIO_Config_SPI1(void)
{
	
}
void GPIO_Config_Buzzer_Output(void)
{
	
}
void GPIO_Config_Motor_Output(void)
{
	
}



