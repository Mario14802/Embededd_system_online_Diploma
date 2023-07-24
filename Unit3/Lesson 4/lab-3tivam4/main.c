//prepared by Mario Atef
//Tivac M4-cotex


#include <stdint.h>
#include <stdio.h>

#define SYSCTL_RCGC2_R      (*((volatile unsigned long*)0x400fe108))
#define GPIO_PORTF_DIR_R    (*((volatile unsigned long*)0x40025400))
#define GPIO_PORTF_DEN_R    (*((volatile unsigned long*)0x4002551C))
#define GPIO_PORTF_DATA_R   (*((volatile unsigned long*)0x400253FC))

int main ()
{

SYSCTL_RCGC2_R =0x20;

volatile unsigned long delay_count;
for ( delay_count=0 ; delay_count <200 ; delay_count++);
  GPIO_PORTF_DIR_R |= 1<<3;
  GPIO_PORTF_DEN_R |= 1<<3;
  while(1)
  {


      GPIO_PORTF_DATA_R |= 1<<3 ;
      for ( delay_count=0 ; delay_count < 200000;  delay_count++);
      GPIO_PORTF_DATA_R &= ~(1<<3);
      for ( delay_count=0 ; delay_count < 200000;  delay_count++);


  }

return (0);

}