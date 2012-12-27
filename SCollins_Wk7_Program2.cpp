/* -----------------------------------------------------------------------------
* Author: Sean Collins
* Class:  CS361
* Assignment: Week 7, Program 2
* Date: February 25, 2011
* Program Description: program that determines what day of the week a 
*                      specific date falls on
*   Input: numeric year, month, and day
*   Processing:  The program will first read a numeric year, month, and day as 
*                described below. After a valid date has been entered, it will
*                be used to calculate two values, value1 and value2.  
*                These values will then be plugged into the following formula
*                to find a number:
*
*   number  =  ( 1461  x  value1  / 4  ) +  (153  x  value2)  /  5)  +  Day
*
*                Finally, the number computed above, will be used to find the
*                day.  First subtract 621,049 from the number to get a result, 
*                and then take that result modulo 7 to get a remainder.
*                This will give you a remainder from 0 to 6 that represents 
*                the day of the week (0 = Sun, 1 = Mon,..., 6 = Sat) that
*                the date falls on.
*
*   Output: day of week based on year and month entered
* -----------------------------------------------------------------------------
*/

#include <iostream>             // for I/O
#include <iomanip>              // for formatting output
#include <cmath>                // for math functions
#include <cctype>               // classify and transform individual characters


using namespace std;

/* -----------------------------------------------------------------------------
* global constants
*-------------------------------------------------------------------------------
*/

  const int YEAR_MIN = 1900;
  const int YEAR_MAX = 1999;
  const int JAN = 1;
  const int FEB = 2;
  const int CALC_NUM_1 = 1461;
  const int CALC_NUM_2 = 153;
  const int CALC_NUM_3 = 5;
  const int CALC_NUM_4 = 4;
  const int CALC_REMAINDER_SUB = 621049;
  const int CALC_REMAINDER_MODULO = 7;
  const int CALC_VAL_MONTH = 13;
  const int LEAP_YEAR = 29;
  const int NOT_A_LEAP_YEAR = 28;
/*------------------------------------------------------------------------------
* function prototypes
*-------------------------------------------------------------------------------
*/

int getMonth(int year);
int getDay(int month, int year);
int calcValues (int year, int month, int& value1, int& value2);
string calcRemainder(int year, int month, int day);
void displayResults(int day, int month, int year, string dayOfWeek);

/*------------------------------------------------------------------------------
* end function prototypes
*-------------------------------------------------------------------------------
*/

int main()
{
    
/*------------------------------------------------------------------------------
* local variables
*-------------------------------------------------------------------------------
*/

  int year;
  int month;
  int day;
  string dayOfWeek;
  char ans;
  
  
  do
  {
     do
     {      
        cout << "Enter year (1900-1999): ";
        cin >> year;
        cout << endl;
     }
     while (year < YEAR_MIN || year > YEAR_MAX);
  
     month = getMonth(year);
     day = getDay(month, year);
     dayOfWeek = calcRemainder(year, month, day);
     displayResults(day, month, year, dayOfWeek);
     
     do
     {
        cout << "Do you wnat to determine another day? Y/N"  << endl;
        cin >> ans;
        ans = toupper(ans);
        if (ans != 'Y' && ans != 'N')
          cout << "You did not enter a valid input, please try again!" << endl;
     }
     while (ans != 'Y' && ans != 'N');
     
  }
  while (ans == 'Y');
  
  cout << endl << endl;
  return 0;
}

/*------------------------------------------------------------------------------
* input functions: getMonth, getDay
*-------------------------------------------------------------------------------
*/


/*------------------------------------------------------------------------------
* Function Description: 
* Function GetMonth, will read and error check the month. GetMonth will have one
* input parameter – the year. The GetMonth function will prompt for the month 
* and error check that the month entered is between 1 and 12.  If the year is 
* 1900, it will also error check that the month is not Jan or Feb, since only 
* months from March and beyond will work.  
* The function will loop until a valid month is entered.  Once a valid month is 
* entered, it will be returned to main.
*-------------------------------------------------------------------------------
*/

int getMonth(int year){
  
  int month;
  do
  {
        
     cout << "Enter month (1-12): ";
     cin >> month;
     cout << endl;
  
     if (year == YEAR_MIN && (month == JAN || month == FEB))
     {
         do
         {
            cout << "Please enter a month OTHER than January or February." << endl;
            cout << "Enter a valid month (3 - 12): ";
            cin >> month;
            cout << endl;
         }
         while (month < 3);   
     }
  }
  while (month < 1 || month > 12);

  return month;
}

/*------------------------------------------------------------------------------
* Function Description:
* Function GetDay will read and error check the day.  GetDay will have two input
* parameters -- the month and year. The GetDay function will error check that 
* the day is valid for the month and year previously entered (Days can be 28-31, 
* depending on the month). February will have 28 days, unless it is a leap year.
* A year in this range is a leap year if it is evenly divisible by 4, except for
* 1900, which is not a leap year. February has 29 days in a leap year.  
* The GetDay function will loop until a valid day is entered. Once a valid day 
* is entered, it will be returned to the main.
* ------------------------------------------------------------------------------
*/

int getDay(int month, int year){
  
  int day;
  
  if (month == 4 || month == 6 || month == 9 || month == 11)
    do
    {
       cout << "Enter day (1 - 30): ";
       cin >> day;
       cout << endl;
    }
    while (day < 1 || day > 30);
  else
    if (month == 2 && year % 4 == 0)
      do
      {
         cout << " You have chosen a Leap year, enter day (1 - 29): ";
         cin >> day;
         cout << endl;
      }
      while (day < 1 || day > 29);
    else
      if (month == 2)
        do
        {
           cout << "Enter day (1 - 28): ";
           cin >> day;
           cout << endl;
        }
        while (day < 1 || day > 28);
      else
        do
        {
           cout << "Enter day (1-31): ";
           cin >> day;
           cout << endl;
        }
        while (day < 1 || day > 31);
 
  return day;
}

/*------------------------------------------------------------------------------
* formula functions: calcValues, calcRemainder
*-------------------------------------------------------------------------------
*/


/*------------------------------------------------------------------------------
* Function Description:
* Function CalcValues will determine values for value1 and value2 to be used in
* the number formula (from above).
* CalcValues will have two input parameters -- the year and month.
* If the month is January or February,  value1 will be (year –1) and value2 will
* be (month +13) Otherwise, value1 will be year and value2 will be (month + 1)
* The values for value1 and value2 will both be passed back to the calling 
* function via reference parameters. This function must be called by a function
* other than main (i.e. it cannot be called by main).
* ------------------------------------------------------------------------------
*/
int calcValues(int year, int month, int& value1, int& value2){
 
    if (month == JAN || month == FEB)
    {
       value1 = year - 1;
       value2 = month + CALC_VAL_MONTH;
       }
    else{
       value1 = year;
       value2 = month + 1;
       }
}

/*------------------------------------------------------------------------------
* Function Description:
* Function CalcRemainder will perform several calculations
* You determine what input parameter(s) are needed for this function
* Calculate the value for number
* Calculate the subtraction result
* Calculate the modulo of 7
* After all calculations are complete, the modulo remainder will be returned.
* ------------------------------------------------------------------------------
*/

string calcRemainder(int year, int month, int day){
    
  int number;
  int subtract;
  int modulo;
  string dayOfWeek;
  int value1, value2;
  
  calcValues(year, month, value1, value2);
  
  number = (((CALC_NUM_1 * value1) / CALC_NUM_4) + ((CALC_NUM_2 * value2) / CALC_NUM_3) + day);
  subtract = number - CALC_REMAINDER_SUB;
  modulo = subtract % CALC_REMAINDER_MODULO;
  
         if (modulo == 0){
            dayOfWeek = "Sunday";
            }
         else if (modulo == 1){
            dayOfWeek = "Monday";
            }
         else if (modulo == 2){
            dayOfWeek = "Tuesday";
            }
         else if (modulo == 3){
            dayOfWeek = "Wednesday";
            }
         else if (modulo == 4){
            dayOfWeek = "Thursday";
            }
         else if (modulo == 5){
            dayOfWeek = "Friday";
            }
         else if (modulo == 6){
            dayOfWeek = "Saturday";
            }

  return dayOfWeek;
  
}

/*------------------------------------------------------------------------------
* Function Description:
* Function DisplayResults will determine and display the correct day of the 
* week, along with the original date entered. You determine what input 
* parameter(s) are needed for this function
* ------------------------------------------------------------------------------
*/

void displayResults(int day, int month, int year, string dayOfWeek){
     
 cout << month << "-" << day << "-" << year << " fell on a " << dayOfWeek;
 cout << endl;
 
}
