/*******************************************************************************
FILE NAME   : main.c
DESCRIPTION : Where all the magic begins.
	      

Copyright   : David Allegre
            : 2015
	    : All Rights Reserved
*******************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "nucleoboard.h"
#include "hw_init.h"
#include "print.h"
#include <assert.h>

extern int sqrAsm(int val); // defined somewhere else
extern int div2Asm(int val);
extern int swapCharsAsm(char* charPtr1, char* charPtr2);

char clr_scrn[] = { 27, 91, 50, 74, 0 };              // esc[2J
/* Public variables ----------------------------------------------------------*/
__IO uint32_t timer;
PRINT_DEFINEBUFFER();           /* required for lightweight sprintf */
/* Private prototype ---------------------------------------------------------*/
void delay(uint32_t time);
char* myCstr = "What's up yo!";
char a = 'a';
char z = 'z';
char a2 = 'a';

/*******************************************************************************
Function Name   : main
Description     : 
Parameters      :
Return value    :               */
void main() {
uint8_t foo;

  foo = 10;
  Hw_init();

  PrintString(clr_scrn); /* Clear entire screen */
  PrintString("Shun's Nucleo STM32F401 is ... alive!!!\n");
  RETAILMSG(1, ("Programming Assignment #1: Built %s %s.\r\n\r\n",
              __DATE__,
              __TIME__));  

  assert(sqrAsm(123)==15129);
  assert(div2Asm(foo)==5);
  
  assert(swapCharsAsm(&a,&z)==1);
  a = 'a'; // swap back
  z = 'z';
  assert(swapCharsAsm(&a,&a2)==0);
  
  while (foo) {
    GPIO_ToggleBits(GPIO_PORT_LD2, GPIO_PIN_LD2);
    PrintString("EMBSYS CP100A: University of Washington - UART Test Application \n");
    
    delay(1000);
    GPIO_ToggleBits(GPIO_PORT_LD2, GPIO_PIN_LD2);
    
    delay(1000);
    foo--;
  }
  while (1) {
    // loop forever
    asm("nop");
  }
}


void delay(uint32_t time) {
  
  timer = time;
  while(timer) {}
}
void SystemInit(void) {
  // System init is called from the assembly .s file
  // We will configure the clocks in hw_init
  asm("nop");
}
  