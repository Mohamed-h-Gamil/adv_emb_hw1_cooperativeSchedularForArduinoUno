/*------------------------------------------------------------------*-

   0_01_16g.C (v1.00)

  ------------------------------------------------------------------

   *** THIS IS A SCHEDULER FOR THE ARDUINO UNO (ATMEGA328P) ***

   *** Uses T0 for timing, 8-bit, CTC mode (AUTO RELOAD) ***

   *** With 16MHz crystal -> 1ms tick interval ***


   ---

   This code is copyright (c) 2014-2015 SafeTTy Systems Ltd.

   This code forms part of a Time-Triggered Reference Design
   that is documented in the following book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont
   [Originally published Addison-Wesley, 2001; ISBN: 0-201-33138-1]

   This code is intended (only) to demonstrate the use of some simple
   Time-Triggered system architectures.

   THIS CODE IS PROVIDED "AS IS" WITHOUT ANY WARRANTY AS TO ITS
   SUITABILITY FOR ANY PURPOSE.

   THIS CODE IS NOT SUITABLE FOR USE IN ANY FORM OF PRODUCT.

   This code may be used without charge: [i] by universities and
   colleges in courses for which a degree up to and including MSc
   level (or equivalent) is awarded; [ii] for non-commercial projects
   carried out by individuals and hobbyists.

   Please see the SafeTTy Systems WWW site for alternative code
   libraries and products that are suitable for use in a range of
   production systems:

   http://www.safetty.net/

-*------------------------------------------------------------------*/

#include "0_01_16g.h"

// ------ Public variable declarations -----------------------------

// The array of tasks (see Sch51.C)
extern sTask SCH_tasks_G[SCH_MAX_TASKS];

// Used to display the error code
// See Main.H for details of error codes
// See Port.H for details of the error port
extern char Error_code_G;

/*------------------------------------------------------------------*-

  SCH_Init_T0()

  Scheduler initialisation function.  Prepares scheduler
  data structures and sets up timer interrupts at required rate.
  Must call this function before using the scheduler.

-*------------------------------------------------------------------*/
void SCH_Init_T0(void)
{
    char i;

    for (i = 0; i < SCH_MAX_TASKS; i++)
    {
        SCH_Delete_Task(i);
    }

    // Reset the global error variable
    // - SCH_Delete_Task() will generate an error code,
    //   (because the task array is empty)
    Error_code_G = 0;

    // Using Timer 0, 8-bit, clk/64 prescale, CTC mode
    TCCR0A |= (1 << WGM01);              // configure CTC mode
    OCR0A = 249;                         // setting up compare register for 1ms tick period

    //  Interrupt Timer 0 enabled
    TIMSK0 |= (1 << OCIE0A); // enable interrupt for OCR0A compare register
}

/*------------------------------------------------------------------*-

  SCH_Start()

  Starts the scheduler, by enabling interrupts.

  NOTE: Usually called after all regular tasks are added,
  to keep the tasks synchronised.

  NOTE: ONLY THE SCHEDULER INTERRUPT SHOULD BE ENABLED!!!

-*------------------------------------------------------------------*/
void SCH_Start(void)
{
    // start timer with clk/64 prescale
    TCCR0B |= (1 << CS00) | (1 << CS01);
    sei(); 
}

/*------------------------------------------------------------------*-

  SCH_Update

  This is the scheduler ISR.  It is called at a rate
  determined by the timer settings in SCH_Init_T0().
  This version is triggered by Timer 0 interrupts.

-*------------------------------------------------------------------*/
ISR(TIMER0_COMPA_vect)
{
    char Index;

    // NOTE: calculations are in *TICKS* (not milliseconds)
    for (Index = 0; Index < SCH_MAX_TASKS; Index++)
    {
        // Check if there is a task at this location
        if (SCH_tasks_G[Index].pTask)
        {
            if (SCH_tasks_G[Index].Delay == 0)
            {
                // The task is due to run
                SCH_tasks_G[Index].RunMe += 1; // Inc. the 'Run Me' flag

                if (SCH_tasks_G[Index].Period)
                {
                    // Schedule periodic tasks to run again
                    SCH_tasks_G[Index].Delay = SCH_tasks_G[Index].Period;
                }
            }
            else
            {
                // Not yet ready to run: just decrement the delay
                SCH_tasks_G[Index].Delay -= 1;
            }
        }
    }
}

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
