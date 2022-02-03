/* Global Headers */
#include <iostream>         //standard IO header
#include <cstdlib>          //included for rand() and RAND_MAX
#include <iomanip>          //included for output manipulation 
#include <ctime>            //included to access the computer's clock
using namespace std;

/*===========================================================================*/
/* Global function prototypes */
void PrintHeading();
int numGen(int);
void StrategyOne(int&);
void StrategyTwo(int&);
void StrategyThree(int&);
/*===========================================================================*/
/* Main function */
int main()
{  
   int winNum1,             //the number of wins for each respective strategy
       winNum2,             
       winNum3;             

   double percent1,         //the percentage of wins from each strategy
          percent2,
          percent3;

   unsigned int seed;       //the seed that initializes rand();

   /* Initialize rand() using the current time */
   seed = static_cast<unsigned>(time(NULL));
   srand(seed);

   StrategyOne(winNum1);    //call the functions of the three strategies 
   
   StrategyTwo(winNum2);

   StrategyThree(winNum3);

   /* calculate the win percentage based on the number of wins */
   percent1 = ((double)winNum1 / 1000) * 100;
   
   percent2 = ((double)winNum2 / 1000) * 100;

   percent3 = ((double)winNum3 / 1000) * 100;

   /* print the percentages to two decimal places */
   cout << fixed << showpoint << setprecision(2); 
  
   /* print the main output heading */
   PrintHeading();

   /* pring out the descriptions of the strategies and the results */
   cout << "The first strategy is staying with the door initially picked."
        << endl;
   cout << "Results:" << endl;
   cout << "Number of games played: 1000" << endl;
   cout << "Number of games won: " << winNum1 << endl;
   cout << "Percentage of games won: " << percent1 << "%" << endl << endl;
  
   cout << "The second strategy is randomly deciding to stay with the door"
        << endl << "initally picked or switch to the unpicked, unopened door."
        << endl;
   cout << "Results:" << endl;
   cout << "Number of games played: 1000" << endl;
   cout << "Number of games won: " << winNum2 << endl;
   cout << "Percentage of games won: " << percent2 << "%" << endl << endl;

   cout << "The third strategy is switching to the unpicked, unopened door."
        << endl;
   cout << "Results:" << endl;
   cout << "Number of games played: 1000" << endl;
   cout << "Number of games won: " << winNum3 << endl;
   cout << "Percentage of games won: " << percent3 << "%" << endl << endl;

   /* determine and print the rankings of the three strategies */
   cout << "The rankings of the strategies are as follows: " << endl;
   if(percent1 > percent2 && percent2 > percent3)
      {   
         cout << "1) Strategy One" << endl;
         cout << "2) Strategy Two" << endl;
         cout << "3) Strategy Three" << endl << endl;;
      }
   else if(percent1 > percent3 && percent3 > percent2)
      {   
         cout << "1) Strategy One" << endl;   
         cout << "2) Strategy Three" << endl;   
         cout << "3) Strategy Two" << endl << endl;
      }
   else if(percent2 > percent3 && percent3 > percent1)
      {
         cout << "1) Strategy Two" << endl;
         cout << "2) Strategy Three" << endl;                                                  
         cout << "3) Strategy One" << endl << endl;
      }
   else if (percent2 > percent1 && percent1 > percent3)
      {
         cout << "1) Strategy Two" << endl;
         cout << "2) Strategy One" << endl;
         cout << "3) Strategy Three" << endl << endl;
      }
   else if (percent3 > percent1 && percent1 > percent2)
      {
         cout << "1) Strategy Three" << endl;
         cout << "2) Strategy One" << endl;
         cout << "3) Strategy Two" << endl << endl;
      }

   else if (percent3 > percent2 && percent2 > percent1)
      {
         cout << "1) Strategy Three" << endl;                                              
         cout << "2) Strategy Two" << endl;          
         cout << "3) Strategy One" << endl << endl;
      }

   /* Print a message to signify normal termination */
   cout << "Program run terminated." << endl << endl;

return(0);
} /* main */

/*=========================Function Definitions============================*/
void PrintHeading()

/* This function prints an output heading */

/* Called by: main */

{ /* PrintHeading */
   cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
   cout << "Welcome to the Monty Hall Puzzle Simulation Program!" << endl;
   cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl
        << endl;
} /* PrintHeading */

/*=========================================================================*/
void StrategyOne(int &winNum1)

/* This function determines the number of wins out of 1000 when using */
/* strategy one, always staying with initial choice of door. */

/* Called by: main */ 

{ /* StrategyOne */

   /* Define local variables */
   const int DOORS = 3;  // number of doors to choose from

   int winDoor,          // represents a winning door in the simulation
       initialDoor,      // the first door chosen
       goatDoor,         // the door with a goat 
       otherDoor;        // the door not chosen or opened

   /* Initialize the number of wins for strategy one to zero */
   winNum1 = 0;

   /* Run the simulation, repeating 1000 times */
   for(int i = 1; i <= 1000; i++)
   {
      /* Randomize winning and inital door */
      winDoor = numGen(DOORS);
      initialDoor = numGen(DOORS);

      /* Randomize otherDoor and goatDoor */
      do
      {
         goatDoor = numGen(DOORS);
      } while (goatDoor == winDoor || goatDoor == initialDoor);

      do
      {
         otherDoor = numGen(DOORS);
      } while (otherDoor == initialDoor);
      
      /* Add one win to the total for strategy one */
      /* if the initial door is the winning door */
      if (initialDoor == winDoor)
      {
         winNum1 = winNum1 + 1;
      }
   } /* end of loop that executes the 1000 simulations */

} /* StrategyOne */
/*=========================================================================*/

void StrategyTwo(int &winNum2)

/* ----------------------------------------------------------------------- */
/* This function behaves similar to StrategyOne, however instead of always */
/* staying with the initial choice, the "contestant" randomly decides to   */
/* stay with their inital choice of door or switch to the door that is not */
/* chosen nor opened by the host.                                          */
/* ----------------------------------------------------------------------- */

/* Called by: main */

{ /* StrategyTwo */
   
   /* Define local variables */
   const int DOORS = 3;  // number of doors to choose from
   const int FLIP = 2;   // the coin flip, 'heads' and 'tails'

   int winDoor,          // represents a wining door in the simulation
       initialDoor,      // the first door chosen
       goatDoor,         // the door with a goat
       otherDoor,        // the door not chosen or opened
       choice;           // the choice of staying or switching, 'coin flip'

   /* Initialize number of wins for this strategy to zero */
   winNum2 = 0;

   /* Run the simulations for strategy two */
   for(int i = 1; i <= 1000; i++)
   {
      /* Randomize the winning and initial doors, as well as the coin flip */
      winDoor = numGen(DOORS);
      initialDoor = numGen(DOORS);

      /* Perform the coin flip using the numGen function */
      choice = numGen(FLIP);
     
      /* Randomize otherDoor and goatDoor */      
      do
      {
         goatDoor = numGen(DOORS);
      } while (goatDoor == winDoor || goatDoor == initialDoor);

      do
      {
         otherDoor = numGen(DOORS);
      } while (otherDoor == initialDoor || otherDoor == goatDoor);

      /* Determine if the random choice is a win or not */
      /* If the choice is a win, add one win to the total for strategy 2 */
      switch (choice) 
      {
         case 1:
             if (initialDoor == winDoor)
             {
                winNum2 = winNum2 + 1;
             }
             break;
         case 2:
            if (otherDoor == winDoor) 
            {
               winNum2 = winNum2 + 1;
            }
            break;
      } /* end of switch choice */

   } /* end of loop that executes the 1000 simulations */

} /* StrategyTwo */
/*========================================================================*/

void StrategyThree(int &winNum3)

/* The final strategy determines the number of wins out of 1000 using */
/* strategy three, always switching to the unpicked, unopened door. */

/* Called by: main */

{ /* StrategyThree */

   /* Define local variables */
   const int DOORS = 3;  // number of doors to choose from

   int winDoor,          // winning door
       initialDoor,      // the first door chosen
       goatDoor,         // the door with a goat    
       otherDoor;        // the door Monty Hall does not open
   
   /* Initialize the number of wins for this strategy to zero */
   winNum3 = 0;

   /* Perform the 1000 simulations */
   for(int i = 1; i <= 1000; i++)
   {
      /* Randomize winning door and initial choice */
      winDoor = numGen(DOORS);
      initialDoor = numGen(DOORS);
 
      /* Randomize otherDoor and goatDoor*/           
      do
      {
         goatDoor = numGen(DOORS);
      } while (goatDoor == winDoor || goatDoor == initialDoor);

      do
      {
         otherDoor = numGen(DOORS);
      } while (otherDoor == initialDoor || otherDoor == goatDoor);

      /* Add one win to the counter for this strategy if the unopened, */
      /* unchosen door is the winning door */
      if (otherDoor == winDoor)
      {
               winNum3 = winNum3 + 1;
      }

   } /* end of loop that executes the 1000 simulations */

} /* StrategyThree */
/*========================================================================*/

int numGen(int max)

/* This is the function that randomizes the three doors, as well as the */
/* coin flip used in strategyTwo */

/* Called by: strategyOne, strategyTwo, and strategyThree */

{ /* numGen */

   /* Define auxiliary variables used for calculations */
   double x = RAND_MAX + 1.0;        
   int y;                            

   /* y contains the result and is passed to the three strategies */
   y = static_cast<int> (1 + rand() * (max / x));

return (y);                      
} /* numGen */
/*========================================================================*/
/*                END  OF  PROGRAM  MONTY  HALL  PUZZLE                   */
/*========================================================================*/
