#include <stdio.h>
#include "conio.h"
#include <iostream>
#include <windows.h>


using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoXY(int x, int y); 

void WaitKey();


int main()
{
   int x = 1;
   int y = 5;
   gotoXY(24,2); 
   cout <<   "Hac co detected";

   for (x=1;x<27;x++) 
   {
      gotoXY(x,y);
      cout << "dark dark bruh bruh lmao";

      Sleep(200);
      gotoXY(x,y); 
	  cout << " "; 
   }
   x--; 

   for (y=5;y<23;y++) 
   {
      Sleep(200);
      gotoXY(x,y);
	  cout << " "; 
      Sleep(200);
      gotoXY(x,y+1);
      cout << "flag_f1301_detected_alo_alo"; 
   }
   Sleep(800);
   for (y=23;y>8;y--)
   {
      Sleep(200);
      gotoXY(x,y);
	  cout << "\t";
      Sleep(200);
      gotoXY(x,y-1);
      cout << "chu chay quanh man hinh ne";
   }

   Sleep(1000); 
   gotoXY(23,24);
   cout << "Press F . . ."; 
   gotoXY(23,24); 
   WaitKey();  
   return 0;
}

void gotoXY(int x, int y) 
{ 
CursorPosition.X = x; 
CursorPosition.Y = y; 
SetConsoleCursorPosition(console,CursorPosition); 
}

void WaitKey()
{
   while (_kbhit()) _getch(); 
   _getch(); 
   while (_kbhit()) _getch(); 
}