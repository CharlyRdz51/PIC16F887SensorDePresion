//Universidad de Guadalajara
//Centro Universitario de Ciencias Exactas e Ingenierias
//Aguilar Rodriguez Carlos Adolfo 215860049
//Seminario de Solucion de Problemas de Sensores y Acondicionamiento de Señal D-09
//Practica 3 Acondicionamiento Señal Sensor de presion
// ----------------------Configuracion del LCD-------------------------
#define LCD_RS_PIN PIN_D0
#define LCD_RW_PIN PIN_D1
#define LCD_ENABLE_PIN PIN_D2
#define LCD_DATA4 PIN_D3
#define LCD_DATA5 PIN_D4
#define LCD_DATA6 PIN_D5
#define LCD_DATA7 PIN_D6
// ------------------Configuraciones de Microcontrolador---------------
#include <18F4550.h>
#device adc=10
#fuses NOMCLR INTRC_IO MCLR NOWDT NOPROTECT PUT XT NOLVP
#use delay(clock=2000000)
#BYTE TRISA=0x0F
#BYTE PORTA=0x0F
#include <lcd.c>
float medida,Sensor,voltaje;
// ---------------------------Funcion Principal------------------------
void main () {
setup_adc (ADC_CLOCK_INTERNAL);
setup_adc_ports (ALL_ANALOG);
//Inicializacion del LCD
lcd_init ();
medida=0;
Sensor = 0;
lcd_putc('\f');
lcd_gotoxy (1, 1);
lcd_putc("AguilarRodriguez");
lcd_gotoxy (5, 2);
lcd_putc("215860049");
delay_ms (3000);
lcd_putc('\f');
lcd_gotoxy (4, 1);
lcd_putc("Practica 3");
lcd_gotoxy (2, 2);
lcd_putc("Sensor Presion");
delay_ms (3000);
lcd_putc('\f');
while(1){
set_adc_channel (0);
delay_us (100);
//Leer puerto analogico y depositar el valor en medicion
medida=read_adc();
delay_us (100);
voltaje=(5.0*medida/1024.0);
Sensor=((voltaje+0.137)/0.0420001);
delay_us (100);
lcd_gotoxy(1,1);
//Imprimir los gramos en el lcd
printf(lcd_putc,"Presion=%3.0gKpa", Sensor);
delay_us(100);
}
}
