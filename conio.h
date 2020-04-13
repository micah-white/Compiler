#ifndef  _conio_h
#define _conio_h

#include <stdio.h>

char getch()
{
   int c;
   
   c = getchar();
   
   putchar(c);
   
   return 0;
}

#endif
