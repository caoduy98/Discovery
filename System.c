#include <main.h>
#include <Lcd4bit.c>

#define Add_SW1   PIN_A3
#define Add_SW2   PIN_A4
#define Add_SW3   PIN_A5
#define Add_SW4   PIN_A6
#define Dat_SW    PIN_A7
#define Crt_SW    PIN_F8

#define Add_Led1  PIN_A10
#define Add_Led2  PIN_A9
#define Add_Led3  PIN_A14
#define Add_Led4  PIN_A15

#define Dat_Led   PIN_B1

#define Seg7_A1   PIN_G2
#define Seg7_A2   PIN_G3
#define Seg7_A3   PIN_G6
#define Seg7_A4   PIN_G7

#define Seg7_B1   PIN_F12
#define Seg7_B2   PIN_F13
#define Seg7_B3   PIN_G0
#define Seg7_B4   PIN_G1

#define PX        PIN_D0
#define PY        PIN_D1
#define PULSEA    PIN_G9
#define PULSEA_   PIN_G8
#define PULSEB    PIN_C13
#define PULSEB_   PIN_C14

#define ON_5V     PIN_E6
#define ON_12V    PIN_E7
#define ON_5V_    PIN_E8
#define ON_12V_   PIN_E9

#define LED1      PIN_D2
#define LED2      PIN_D3
#define LED3      PIN_D4
#define LED4      PIN_D5
#define LED5      PIN_D6
#define LED6      PIN_D7
#define LED7      PIN_D8
#define LED8      PIN_D9

#define MD  PIN_G14
#define UP  PIN_G15
#define DW  PIN_G12
#define EX  PIN_G13

unsigned char data_switch = 0;
unsigned char data_singled = 0;
unsigned char data_seg7_led1 = 0;
unsigned char data_seg7_led2 = 0;
unsigned char dat1 = 0,dat2 = 0,dat3 = 0;
unsigned char data = 0;

unsigned char power_on_5V = 1;
unsigned char power_on_12V = 1;
unsigned char power_on_5V_ = 1;
unsigned char power_on_12V_ = 1;
unsigned char power_on = 1;

unsigned char re_local = 0;
unsigned char setup_mode = 0;
unsigned int16 val_adc1 = 0,val_adc2 = 0;
unsigned int16 curren_displayA = 0,curren_displayB = 0;
unsigned char flag_currA = 0,flag_currB = 0;

unsigned int32 M[25];

void Switch_control (unsigned char flag);
void Single_Seg7_led_read (void);
void Main_init (void);
void Pulse_switch (unsigned char flag);
void Control_supply (unsigned char flag);
unsigned char Check_connect_computer (void);
void control_button (void);
unsigned int16 multi_read_adc (unsigned int8 channel,unsigned int16 samling);
Void Read_current (void);

void Main_init (void)
{
   set_tris_A(0xFFFF);
   set_tris_B(0x000C);
   set_tris_C(0x901F);
   set_tris_E(0x003F);
   set_tris_F(0xFF00);
   set_tris_D(0xFFFF);
   set_tris_G(0xFCFF);
   output_A(0x0000);
   delay_ms(50);
   lcd_init();
   delay_ms(50);
   setup_adc(ADC_CLOCK_DIV_8|ADC_TAD_MUL_8);
   setup_adc_ports(sAN18|sAN19|VSS_VDD);
}
