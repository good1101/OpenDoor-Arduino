#include "MoveState.h"
#include "Buttons.h"
#include "GateLeaf.h"
////пины для левой створки
#define PIN_VOLTAGE_LEFT 2
#define PIN_RELE_LEFT_1 3
#define PIN_RELE_LEFT_2 4
//пины для правой створки
#define PIN_VOLTAGE_RIGHT 5
#define PIN_RELE_RIGHT_1 6
#define PIN_RELE_RIGHT_2 7

#define PIN_BUTTON_OPEN_ALL 12 //пин для кнопки открытия всех створок
#define PIN_BUTTON_CLOSE_ALL 11 //пин для кнопки закрытия всех створок

#define PIN_BUTTON_OPEN_ALL_ALT 8
#define PIN_BUTTON_CLOSE_ALL_ALT 9

int moveTimeSecond = 60;
Button btOpen(PIN_BUTTON_OPEN_ALL, true);
Button btClose(PIN_BUTTON_CLOSE_ALL, true);
Button btOpenAlt(PIN_BUTTON_OPEN_ALL_ALT, false);
Button btCloseAlt(PIN_BUTTON_CLOSE_ALL_ALT, false);

MoveState moveOpen;
MoveState moveClose;
bool statusD = false;

GateLeaf gateLeafLeft(PIN_RELE_LEFT_1, PIN_RELE_LEFT_2, PIN_VOLTAGE_LEFT);
GateLeaf gateLeafRight(PIN_RELE_RIGHT_1, PIN_RELE_RIGHT_2, PIN_VOLTAGE_RIGHT);

void setup() 
{
  Serial.begin(9600);
  moveOpen.init(open, stop, moveTimeSecond);
  moveClose.init(close, stop, moveTimeSecond);
  btOpen.setCallbackPress(buttonPressOpen);
  btClose.setCallbackPress(buttonPressClose);
  btOpenAlt.setCallbackPress(buttonPressOpen);
  btCloseAlt.setCallbackPress(buttonPressClose);

}

void test()
{
  Serial.println("test");
}

void loop() {

  btOpen.check();
  btClose.check();
  btOpenAlt.check();
  btCloseAlt.check();
  moveOpen.check();
  moveClose.check();

}

void buttonPressOpen()
{
  Serial.println("pressOpen");
  moveClose.clear();
  moveOpen.move();
}

void buttonPressClose()
{
   Serial.println("pressClose");
   moveOpen.clear();
   moveClose.move();
}

void close()
{
   gateLeafLeft.close();
   gateLeafRight.close();
}
void open()
{
   gateLeafLeft.open();
   gateLeafRight.open();
}

void stop()
{
   gateLeafLeft.stop();
   gateLeafRight.stop();
}
