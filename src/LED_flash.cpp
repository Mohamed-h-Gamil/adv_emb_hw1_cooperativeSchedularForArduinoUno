#include "LED_flash.h"

/*------------------------------------------------------------------*-

  LED_Flash_Init()

  - See below.

-*------------------------------------------------------------------*/
void LED1_Flash_Init(void)
{
    pinMode(LED1_PIN, OUTPUT);
    digitalWrite(LED1_PIN, LOW);
}

void LED2_Flash_Init(void)
{
    pinMode(LED2_PIN, OUTPUT);
    digitalWrite(LED2_PIN, LOW);
}

/*------------------------------------------------------------------*-

  LED_Flash_Update()

  Flashes an LED (or pulses a buzzer, etc) on a specified port pin.

  Must schedule at twice the required flash rate: thus, for 1 Hz
  flash (on for 0.5 seconds, off for 0.5 seconds) must schedule
  at 2 Hz.

-*------------------------------------------------------------------*/
void LED1_Flash_Update(void)
{
    // Change the LED from OFF to ON (or vice versa)
    digitalWrite(LED1_PIN, !digitalRead(LED1_PIN));
}


void LED2_Flash_Update(void)
{
    // Change the LED from OFF to ON (or vice versa)
    digitalWrite(LED2_PIN, !digitalRead(LED2_PIN));
}

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
