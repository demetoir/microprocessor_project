///*----------------------------------------------------------------------------
// *      doorLock_LCD.h
// *----------------------------------------------------------------------------
// *      Name:    doorLock_LCD.h
// *---------------------------------------------------------------------------*/
//

#include "GLCD.h"



void setLCDTime(int time_10h, int time_1h, int time_10m, int time_1m,  int time_10s, int time_1s);
void setLCDkey(char val);


void setLCD_refresh(void);

void init_lcd(void);
void LCD_refresh(void);



