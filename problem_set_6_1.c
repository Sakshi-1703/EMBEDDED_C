#include<AT89C5131.h>
sbit rs = P0^0;
sbit rw = P0^1;
sbit en = P0^2;

void ms_delay(unsigned int time)
{
	unsigned int i,j;
	for(i=0;i<time;i++)
		{
			for(j=0;j<382;j++);
		}
}
	
void lcd_cmd(unsigned int i)
{
		rs= 0;
    rw=0;
    en=1;
	 P2=i;
    ms_delay(10);
    en=0;
	 
}

void lcd_data(unsigned char *s)
{ 
	while(*s!='\0')
	{
		rs= 1;
    rw=0;
    en=1;
		P2=*s++;
    ms_delay(10);
    en=0;
	  
	}
}

 void lcd_init()
 {
	P2=0x00;
	  rs=0;
	  rw=0;
	  en=0;
    lcd_cmd(0x38);  
    ms_delay(4);
	  lcd_cmd(0x06);  
    ms_delay(4);
    lcd_cmd(0x0C);  
    ms_delay(4);
    lcd_cmd(0x01);  
    ms_delay(4);
 }
 void main() 
 {
	lcd_init;
	while(1)
	{
    lcd_cmd(0x85);  
    ms_delay(4);
    lcd_data("pt-51");  
    ms_delay(2000);
		lcd_cmd(0xC4);  
    ms_delay(4);
    lcd_data("IIT-BOMBAY"); 
    ms_delay(3000);
		
		lcd_cmd(0x01);  // Clear LCD
  	ms_delay(2000);

    lcd_cmd(0x81);  
    ms_delay(4);
    lcd_data("SAKSHI-SHREYA");  
    ms_delay(4);
		lcd_cmd(0xC4);  
    ms_delay(4);
    lcd_data("WORKSHOP"); 
    ms_delay(5000);
	  lcd_cmd(0x01);  
    ms_delay(4);
	}
}