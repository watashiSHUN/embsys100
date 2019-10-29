#define RCC_AHBIENR (*(unsigned int*)0x40023830)
#define GPIOA_MODER (*(unsigned int*)0x40020000)
#define GPIOA_ODR (*(unsigned int*)0x40020014)
volatile int counter = 0;
int unit = 200000;

// first name == SHUN XIAN
void on (int duration){
    GPIOA_ODR |= 0x20;
    counter = 0;
    while(counter < unit*duration){
        counter+=1;
    }
}
void off(int duration){
    // clear the bit (~of 0x20)
    GPIOA_ODR &=0xFFFFFFDF;
    counter = 0;
    while(counter < unit*duration){
        counter+=1;
    }
}

void letter(char* morse, int length){
  for(int i = 0; i < length; i++){
    if(morse[i] == 'i'){
      on(1);
    } else {
      on(3);
    }
    off(1);
  }
  off(2);
}
int main()
{
  // RCC Base address: 0x40023800
  // RCC AHB1 peripheral clock enable register (RCC_HBIENR)
  // Address offset 0x30
  // Write 0x1
  RCC_AHBIENR |= 0x1;
  // GPIOA Base Address 0x4002000
  // Address offset 0x00
  // Write 0x400
  GPIOA_MODER |= 0x400;
  // output data register
  // s=...
  letter("...",3);
  // h=....
  letter("....",4);
  // u=.._
  letter(".._",3);
  // n=_.
  letter("_.",2);
  // space between 2 words 7 gaps
  off(4);
  
  // x=_.._
  letter("_.._",4);
  // i=..
  letter("..",2);
  // a=._
  letter("._",2);
  // n=_.
  letter("_.",2);
  off(4);
  
  return 0;
}
