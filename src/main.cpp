#include "main.h"

#include "0_01_16g.h"
#include "LED_flash.h"

void setup()
{
  // Set up the scheduler
  SCH_Init_T0();

  // Prepare for the 'Flash_LED' task
  LED1_Flash_Init();
  LED2_Flash_Init();

  // Add the 'Flash LED' task (on for ~1000 ms, off for ~1000 ms)
  // - timings are in ticks (1 ms tick interval)
  SCH_Add_Task(LED1_Flash_Update, 0, 1000);
  SCH_Add_Task(LED2_Flash_Update, 0, 500);

  // Start the scheduler
  SCH_Start();
}

void loop()
{
  SCH_Dispatch_Tasks();
}
