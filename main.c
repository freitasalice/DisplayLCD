/*
 * File:   newmain.c
 * Author: 21192692
 *
 * Created on 22 de Abril de 2021, 13:13
 */


#include <xc.h>
#include "config.h"

#define DADOS   PORTB
#define EN      PORTDbits.RD7
#define RS      PORTDbits.RD6


void LCD_init (void) 
{
    TRISDbits.TRISD6 = 0;
    TRISDbits.TRISD7 = 0;
    ANSELH = 0;
    TRISB = 0x00;
    
    DADOS = 0x00;
    EN = 1;
    RS = 0;          
}

void LCD_on ( void)
{
    // Ligar o Display LCD
    RS = 0;
    EN = 1;
    DADOS = 0x0F;
    EN = 0;
    __delay_us(40);
    EN = 1;
}

void LCD_printChar (char c)
{
    RS = 1;
    DADOS = c;
    EN = 0;
    __delay_us(40);
    EN = 1;
}

void LCD_print ( char * str )
{
    char i = 0;
    
    while ( *(str+i) !=0 )
    {
        LCD_printChar( *(str+i) );
        ++i;
    }
}

void main (void)
{
    LCD_init();
    LCD_on();
    LCD_print ( "" );
    
    
    while(1)
    {
    }    
}