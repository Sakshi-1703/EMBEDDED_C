#include<AT89C5131.h>
sbit led = P1^6;
sbit led1 = P1^7;
void ISR_interrupt_delay_0( ) interrupt 1  // timer0
{
			TR0=0;
			TF0=0;
			TL0=0X60;
			TH0=0XF0;
			TR0=1;
			led=~led;
}

void ISR_interrupt_delay_1( ) interrupt 3 //timer1
{
			TR1=0;
			TF1=0;
	    TL1=0X90;
			TH1=0XE8;
			TR1=1;
			led1=~led1;
			
}

void main()
{
	TMOD = 0X11;
	TL0=0X60;
	TH0=0XF0;
	TL1=0X90;
	TH1=0XE8;
	ET0 = 1;
	ET1 = 1;
	EA = 1;
	TR0 = 1;
	TR1 = 1;
	while(1);
}
