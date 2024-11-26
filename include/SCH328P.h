#ifndef _SCH328P_H
#define _SCH328P_H

#include "main.h"
#include "PORT.h"

// ------ Public data type declarations ----------------------------

// Store in DATA area, if possible, for rapid access
// Total memory per task is 7 bytes
typedef struct
{
    // Pointer to the task (must be a 'void (void)' function)
    void (*pTask)(void);

    // Delay (ticks) until the function will (next) be run
    // - see SCH_Add_Task() for further details
    int Delay;

    // Interval (ticks) between subsequent runs.
    // - see SCH_Add_Task() for further details
    int Period;

    // Incremented (by scheduler) when task is due to execute
    char RunMe;
} sTask;

// ------ Public function prototypes -------------------------------

// Core scheduler functions
void SCH_Dispatch_Tasks(void);
char SCH_Add_Task(void(*pFunction)(void), const int DELAY, const int PERIOD);
char SCH_Delete_Task(const char TASK_INDEX);
void SCH_Report_Status(void);

// ------ Public constants -----------------------------------------

// The maximum number of tasks required at any one time
// during the execution of the program
//
// MUST BE ADJUSTED FOR EACH NEW PROJECT
#define SCH_MAX_TASKS (3)

#endif

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
