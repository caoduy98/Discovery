#define LCD_RS   PIN_B5
#define LCD_RW   PIN_B6
#define LCD_E    PIN_B7 

#define LCD_D4   PIN_B8 
#define LCD_D5   PIN_B9  
#define LCD_D6   PIN_B10
#define LCD_D7   PIN_B11  

void lcd_enable(void);
void lcd_send_4bit_data ( unsigned char cX );
void lcd_send_command (unsigned char cX );
void lcd_init (void );
void lcd_gotoxy(unsigned char x, unsigned char y);
void lcd_clear(void);
void lcd_putchar ( unsigned int16 cX );
void lcd_puts (char *s);
void lcd_putcharInt(unsigned int16 val);

