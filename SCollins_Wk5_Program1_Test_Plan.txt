/* -----------------------------------------------------------------------------
*  Author: Sean Collins
*  Class:  CS361 Control Structures
*  Assignment: Week 5, Program 1
*  Date: February 7, 2011
*
*  Program Description: Pretend you have a computer that can do addition, 
*  subtraction, and division, but not multiplication.
*
*  Input: Read in two numbers and determine which is larger and which is smaller.  
*  Start halving the larger number (disregard any remainders) and doubling
*  the smaller. Keep a running sum of the second number's value, whenever
*  the first number (originally the larger) is odd. Continue until the first
*  number (originally the larger) has been reduced to 1.  
*
*  Output: The product of the two numbers will be equivalent to the running sum.  
*
*  Example:  Multiply 26 and 53
*
*			Larger		Smaller
*			53 (odd)	 26
*			26		     52
*			13 (odd)	104
*			 6		    208
*			 3 (odd)	416
*			 1 (odd)	832
*
*		Running sum of odds (bolded above) = 26 + 104 + 416 + 832 = 1378
*						so:  26 x 53 = 1378
*
*  Additional comments:
*    Tell the user what the program does before prompting for input.
*    Write a user-defined function to read a number from the user.  
*    The user-defined function requirements are:
*    The prompt for user input will be stored in a string type variable and 
*    passed as an input argument to the function (example: "Enter the first 
*    number to multiply").
*    The function will prompt the user for the input and then use a loop to 
*    verify that the user input is positive and non-zero.  If it is not, the 
*    function will issue an error message and then re-prompt the user to enter 
*    the number again, until a positive, non-zero value is entered.  
*    Once valid input has been entered, the value that the user entered will be
*    returned to the main function.
*    The user-defined function will be called twice – once to read and error 
*    check the first number, and once to read and error check the second number.  
*    As you work through the algorithm, output the values of both numbers each 
*    time you loop, along with a message about whether the second number was 
*    added to the running sum. 
*    Output the final result of the multiplication (show both numbers with an 
*    'x' between them, along with the final value of your running sum).
* ------------------------------------------------------------------------------
*/

// pre processing directives

#include <iostream>             // for I/O
#include <iomanip>              // for formatting output
#include <cmath>                // for math functions
#include <cctype>               // classify and transform individual characters


using namespace std;

//Global Constants
const int DIVISOR = 2;
/*
*-------------------------------------------------------------------------------
* User defined functions
*-------------------------------------------------------------------------------
*/

/*
*-------------------------------------------------------------------------------
* Function to Display program header to user
*-------------------------------------------------------------------------------
*/

void programHeader ()
{
  cout << "Program will multiply two numbers." << endl << endl;
  
  return;
  
}
/* -----------------------------------------------------------------------------
 * Creates user defined function that presents string to user and requests
 * the user to input a positive non-zero number. 
 * -----------------------------------------------------------------------------
*/
int getNumbers (string prompt)
{
  int num;            

  do {
      cout << endl << prompt;
      cin >> num;
      cout << endl << endl;
      if (num <= 0)
          cout << "Invalid input.  Must be positive and non-zero Please try";
          cout << " again." << endl;
  } while (num <= 0); 

  return num;
  
}

int main()
{

// local variables

  int first_number;
  int second_number;
  int larger;
  int smaller;
  string result = "add";
  int sum;
  int total;
  
// Call to user defined function
  programHeader();
  
/*------------------------------------------------------------------------------
* assignment statments and call to user defined function prompting for user
* input
*-----------------------------------------------------------------------------*/

  first_number = getNumbers ("Enter the first number to multiply: ");
  cout << endl;
  second_number = getNumbers ("Enter the second number to multiply: ");
  cout << endl << endl;
  
// if-else statment to determine largest and smallest number entered by user 
       if (first_number > second_number){
          larger = first_number;
          smaller = second_number;
          }
       else{
          smaller = first_number;
          larger = second_number;
          }

// begin output   

      for (int count = 1; count <= 1; count++){      
          cout << "RESULTS:" << endl << endl;
          cout << "Larger" << setw(15) << "Smaller" << setw(15) << "Result" << endl;
          cout << "------" << setw(15) << "-------" << setw(15) << "------" << endl;
          
          if (first_number > second_number){
              cout << setw(5) << first_number << setw(15) << second_number;
              cout << setw(15) << endl;
              }
          else{
              cout << setw(5) << second_number << setw(15) << first_number;
              cout << setw(15) << endl;
              }
          }
/*------------------------------------------------------------------------------
* do-while loop with embedded if-else statement
------------------------------------------------------------------------------*/  
      do { 
          
          larger = larger / DIVISOR;
          smaller = smaller + smaller;
          
            if (larger % DIVISOR == 1){
                sum = smaller + smaller; 
                cout << setw(5) << larger << " odd" << setw(11) << smaller;
                cout << setw(15) << result << endl;
            }
            else{
            cout << setw(5) << larger << setw(15) << smaller << setw(15) << endl;
            }
            
      } while (larger >= 1);
       
// assignment statement  
  total = first_number * second_number;
  
  cout << "Final Result:" << endl << endl;
  cout << first_number << " X " << second_number << " = " << total << endl;
  
    cout << endl << endl;
    system ("PAUSE");

    return 0;
}
