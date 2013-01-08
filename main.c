/*===========================================================================
 * DESCRIPTION:
 *
 * This example exhibits basic functionality of the STM32-Primer. It toggles
 * the onboard LEDs.
 *
 *---------------------------------------------------------------------------
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *---------------------------------------------------------------------------
 * Copyright (c) Raisonance S.A.S., 2007-2009
 *==========================================================================*/

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_conf.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
GPIO_InitTypeDef GPIO_InitStructure;



/* Private function prototypes -----------------------------------------------*/
void RCC_Configuration(void);
void NVIC_Configuration(void);
void Delay(vu32 nCount);

void LED_Flash(void);

/* Private functions ---------------------------------------------------------*/
/*******************************************************************************
* Function Name  : main
* Description    : Main program.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
int main(void)
{

  /* NVIC Configuration */
  NVIC_Configuration();

  /* Enable clocks */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

 
  /* Configure PC.06 PC.07 as output push-pull */
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6 | GPIO_Pin_7;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  //==============================================

  SysTick_Config(SystemCoreClock / 1000);


  while(1)
  {

/* 
    GPIO_SetBits(GPIOC, GPIO_Pin_6);
    GPIO_ResetBits(GPIOC, GPIO_Pin_7);

    Delay(0xDFFFF);
    
    GPIO_ResetBits(GPIOC, GPIO_Pin_6);
    GPIO_SetBits(GPIOC, GPIO_Pin_7);

    Delay(0xDFFFF);

*/

  }
}


/*******************************************************************************
* Function Name  : NVIC_Configuration
* Description    : Configures Vector Table base location.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void NVIC_Configuration(void)
{
  /* Set the Vector Table base location at 0x08000000 */ 
  NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);
}



/*******************************************************************************
* Function Name  : Delay
* Description    : Inserts a delay time.
* Input          : nCount: specifies the delay time length.
* Output         : None
* Return         : None
*******************************************************************************/
void Delay(vu32 nCount)
{
  for(; nCount!= 0;nCount--);
}





void LED_Flash(void)
{

  static int f=0;
   
   if(f==0)
   {
      f=1;
      GPIO_SetBits(GPIOC, GPIO_Pin_6);//
   }
   else
   {
      f=0;
      GPIO_ResetBits(GPIOC, GPIO_Pin_6);//
   }
  
}


void SysTick_Handler(void) {

   LED_Flash();

}
