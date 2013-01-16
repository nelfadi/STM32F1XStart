#include "stm32f10x_conf.h"


GPIO_InitTypeDef GPIO_InitStructure;


void Delay(vu32 nCount);
void LED_Flash(void);


int main(void)
{

  /* Enable clocks */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

 
  /* Configure PC.06 PC.07 as output push-pull */
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6 | GPIO_Pin_7;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  //==============================================

  //SysTick_Config(SystemCoreClock / 1000);


  while(1)
  {


    GPIO_SetBits(GPIOC, GPIO_Pin_6);
    GPIO_ResetBits(GPIOC, GPIO_Pin_7);

    Delay(0x20000);
    
    GPIO_ResetBits(GPIOC, GPIO_Pin_6);
    GPIO_SetBits(GPIOC, GPIO_Pin_7);

    Delay(0xA0000);


  }
}


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
