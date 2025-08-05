#include <Lcd4bit.h>

// Ham Khoi Tao LCD
 void lcd_enable(void)
{
   output_high(LCD_E);   
   delay_us(20);       
   output_low(LCD_E);
   delay_us(20);    
}
// --------------------------------------------------
// Ham Gui 4 Bit Du Lieu Ra LCD
 void lcd_send_4bit_data ( unsigned char cX )
{
   output_bit(LCD_D4,cX & 0x01); 
   output_bit(LCD_D5,(cX>>1)&1);
   output_bit(LCD_D6,(cX>>2)&1);
   output_bit(LCD_D7,(cX>>3)&1);
}

// --------------------------------------------------
// Ham Gui 1 Lenh Cho LCD
 void lcd_send_command (unsigned char cX )
{
   lcd_send_4bit_data ( cX >>4 );       // send 4 bit high  
   lcd_enable() ;
   lcd_send_4bit_data ( cX  );                // send 4 bit low  
   lcd_enable() ;
}

// --------------------------------------------------
// Ham Khoi Tao LCD
 void lcd_init ( void )
{
   //lcd_send_4bit_data ( 0x00 );
   //delay_ms(200);
   
   output_low(LCD_RS);   
   output_low(LCD_RW);
   output_low(LCD_E);                                                   // che do gui lenh
   
   lcd_send_4bit_data ( 0x03 );          // ket noi 8 bit
   lcd_enable() ;
   lcd_enable() ;
   lcd_enable() ;
   lcd_send_4bit_data ( 0x02 );               // ket noi 4 bit
   lcd_enable() ;
   
   lcd_send_command( 0x28 );                 
   lcd_send_command( 0x06 );
   lcd_send_command( 0x0c );                   
   lcd_send_command( 0x01 );                  
   lcd_send_command( 0x08 );         
}

// --------------------------------------------------
// Ham Thiet Lap Vi Tri Con Tro
void lcd_gotoxy(unsigned char x, unsigned char y)
{
  unsigned char address;
  if(y == 0)address = (0x80+x);
  if(y == 1)address = (0xc0+x);
  if(y == 2)address = (0x94+x);
  if(y == 3)address = (0xd4+x);
  delay_ms(3);
  lcd_send_command(address);
  delay_ms(1);
}
// --------------------------------------------------
// Ham Xoa Man Hinh LCD
void lcd_clear(void)
{
   lcd_send_command(0x01);  
  //delay_us(300);
}

// --------------------------------------------------
// Ham Gui 1 Ky Tu Len LCD
 void lcd_putchar ( unsigned int16 cX )
{
     output_high(LCD_RS);   
     lcd_send_command( cX );
     output_low(LCD_RS);
}

// --------------------------------------------------
void lcd_putcharInt(unsigned int16 val)
{
   unsigned char i, j, num[5];
   i = 0;
   while(val > 9)
   {
      num[i] = val%10 + 0x30;
      val = val/10;
      i++;
   }
   num[i] = val + 0x30;
   for(j = 0; j <= i; j++)
   {

      lcd_putchar(num[i - j]);
   }
}
// Ham Gui 1 Chuoi Ky Tu Len LCD
void lcd_puts(char *s)
{
   while (*s)
   {
         lcd_putchar(*s);
      s++;
   }
}
