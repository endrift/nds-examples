
#include <nds.h>
#include <stdio.h>
#include <nds\arm9\keyboard.h>

void OnKeyPressed(int key)
{
	if(key > 0)
      iprintf("%c", key);
}

int main(void) 
{
   irqInit();
   irqEnable(IRQ_VBLANK);

	consoleDemoInit();
   
   Keyboard *kbd = keyboardGetDefault();

   kbd->OnKeyPressed = OnKeyPressed;

   keyboardInit(kbd);

   while(1)
   {
      char myName[256];
	
      printf("What is your name?\n");
       
      scanf("%s", myName);
	
	   printf("\nHello %s", myName);

      scanKeys();
      while(!keysDown())scanKeys();
     
      swiWaitForVBlank();
      consoleClear();
   }

	return 0;
}