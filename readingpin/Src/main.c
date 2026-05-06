/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Joshva Jonathan Joseph
 * @brief          : Main program body
 ******************************************************************************
**/

#include <stdint.h>


int main(void)
{
	// address's of Required registers
		    uint32_t *RCC_AHB1ENR = (uint32_t*) 0x40023830;
			uint32_t *GPIOA_MODER = (uint32_t*) 0x40020000;
			uint32_t *GPIOA_IDR = (uint32_t*) 0x40020010;
			uint32_t *GPIOA_ODR = (uint32_t*) 0x40020014;


		// programming register according to requirements
			// setting RCC enable for gpioA
		*RCC_AHB1ENR |= (1<<0);
          // Making PinA6 as an output pin
		 *GPIOA_MODER &= ~(3<<12);
		*GPIOA_MODER |= (1<<12);
          // making PinA0 as an input pin
		*GPIOA_MODER &= ~(3<<0);


			while(1)
			{
			  uint32_t pinstatus = (uint32_t)(*GPIOA_IDR & 0x1);


			if (pinstatus)
			{
				*GPIOA_ODR |= (1<<6);
			}
			else
			{
				*GPIOA_ODR &= ~(1<<6);

			}

			}
}

