/* DDR USB Dance Pad Code - Super Make Something Episode 9) - https://youtu.be/-qeD2__yK4c
 * by: Alex - Super Make Something
 * date: June 1st, 2016
 * license: Creative Commons - Attribution - Non-Commercial.  More information available at: http://creativecommons.org/licenses/by-nc/3.0/
 */

/*
 * This code contains the follow functions:
 * - void setup(): Sets pins 4, 5, 6, 7 to input with pull-up resistors enabled and begins Keyboard functionality
 * - void loop(): Main loop - reads pin voltages and sends out corresponding keystrokes via USB
 */

/* 
 * Pinout:
 * - "HIGH" voltage button contacts - pins 4, 5, 6, 7
 * - "GND" voltage button contacts - GND pin
 */

#include <Keyboard.h>

int upStatus=1;
int upStatusPrev=1;
int leftStatus=1;
int leftStatusPrev=1;
int downStatus=1;
int downStatusPrev=1;
int rightStatus=1;
int rightStatusPrev=1;

void setup()
{
  pinMode(4,INPUT_PULLUP);
  pinMode(5,INPUT_PULLUP);
  pinMode(6,INPUT_PULLUP);
  pinMode(7,INPUT_PULLUP);
  Keyboard.begin();
}

void loop()
{
 
 upStatus=digitalRead(4);
 leftStatus=digitalRead(5);
 downStatus=digitalRead(6);
 rightStatus=digitalRead(7);
 
 //UP ARROW PRESSED
 if (upStatus!=upStatusPrev && upStatus==LOW)
 {
    Keyboard.press('w');
    upStatusPrev=upStatus;
 }
 //UP ARROW RELEASED
 if (upStatus!=upStatusPrev && upStatus==HIGH)
 {
    Keyboard.release('w');
    upStatusPrev=upStatus;
 }
 
  //LEFT ARROW PRESSED
 if (leftStatus!=leftStatusPrev && leftStatus==LOW)
 {
    Keyboard.press('a');
    leftStatusPrev=leftStatus;
 }
 //LEFT ARROW RELEASED
 if (leftStatus!=leftStatusPrev && leftStatus==HIGH)
 {
    Keyboard.release('a');
    leftStatusPrev=leftStatus;
 }
 
  //DOWN ARROW PRESSED
 if (downStatus!=downStatusPrev && downStatus==LOW)
 {
    Keyboard.press('s');
    downStatusPrev=downStatus;
 }
 //DOWN ARROW RELEASED
 if (downStatus!=downStatusPrev && downStatus==HIGH)
 {
    Keyboard.release('s');
    downStatusPrev=downStatus;
 }
 
 //RIGHT ARROW PRESSED
 if (rightStatus!=rightStatusPrev && rightStatus==LOW)
 {
    Keyboard.press('j');
    rightStatusPrev=rightStatus;
 }
 //RIGHT ARROW RELEASED
 if (rightStatus!=rightStatusPrev && rightStatus==HIGH)
 {
    Keyboard.release('j');
    rightStatusPrev=rightStatus;
 }
}
