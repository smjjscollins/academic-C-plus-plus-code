/* -----------------------------------------------------------------------------
*  Author: Sean Collins
*  Class:  CS361 Control Structures
*  Assignment: Week 5, Program 2
*  Date: February 7, 2011
*
*  Program Description: Fibonacci series
*
*  Inputs: The Fibonacci series can begin with any two integers
*  (positive or negative), so long as the next term is always the sum of the
*  previous 2 numbers.  
*
*  Outputs: Each number is the sum of the previous two numbers.
*
*           Sample Output:  
*           If the user enters 20 and 30 as the first 2 numbers:
*
*          The first 10 elements of a Fibonacci series 
*	        beginning with 20 and 30 are:
*		    20  30  50  80  130  210  340  550  890  1440
*
*	      The sum of the first 10 elements is:    3740
*	      The seventh element is 340.  11 x 340 = 3740
*
*
*  Additional comments:
*             Tell the user what the program does before prompting for input.
*             Read the first two numbers in the sequence from the user.
*             Only allow the user to enter numbers between –1000 and +1000. 
*             If the either number is not in that range, issue an error message 
*             and then re-prompt the user to enter the numbers again, until both
*             the numbers are in range. 
*             Compute the first 10 elements of the series within a user-defined 
*             function as follows:
*             The function will take the first two terms as an input arguments.
*             The function will display the first two terms, then compute and 
*             display the next 8 terms within a loop, for 10 total elements.
*             The function will also compute and display the sum of the first 
*             10 elements
*             The function will return the seventh term to main. 
*             Display a statement proving the rule above, within a user-defined 
*             function as follows:
*             The function will take the seventh term as an input argument.
*             The function will compute and display 11 times the 7th element.
*
* -----------------------------------------------------------------------------
*/

// pre processing directives

#include <iostream>             // for I/O
#include <iomanip>              // for formatting output
#include <cmath>                // for math functions
#include <cctype>               // classify and transform individual characters


using namespace std;

//Global Constants
const int NEGATIVE_NUMBER = -1000;
const int POSITIVE_NUMBER = 1000;
const int ELEVEN = 11;


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
  cout << "Fibonacci Series" << endl << endl;
  
  return;
  
}
/* -----------------------------------------------------------------------------
 * Creates user defined function that presents string to user and requests
 * the user to input a positive non-zero number. 
 * -----------------------------------------------------------------------------
*/
int getNumbers (string prompt)
{
  int num;            // user input number


 
 
  do {
    cout << endl << prompt;
    cin >> num;
    
    if ((num < NEGATIVE_NUMBER) || (num > POSITIVE_NUMBER))
        cout << "Error -- invalid input" << endl << endl;
  } while ((num < NEGATIVE_NUMBER) || (num > POSITIVE_NUMBER)); 
  

  return num;
}

/* -----------------------------------------------------------------------------
 * Creates user defined function that calcualtes the fibonacci sequence
 * calculates the sum, and returns the seventh term to main by reference. 
 * -----------------------------------------------------------------------------
*/

void fibonacciCalculate(int &num_1, int &num_2, int &seventh)
{
  
  int sum;
  
  cout << "The first 10 elements of a Fibonacci series" << endl;
  cout << "beginning with " << num_1 << " and " << num_2 << " are: " << endl;
  cout << endl;
  cout << num_1 << " " << num_2 << " ";
  
    for (int count = 1; count <= 8; count++){
         int total;
        
         
         total = num_1 + num_2;
         num_1 = num_2;
         num_2 = total;
         sum = seventh * ELEVEN;
         
          if (count == 6)
		    seventh = num_1;
         
         cout << total << " ";
      
           
         }
         
  
  cout << endl << endl;
  cout << "The sum of the first 10 elements is: " << sum << endl;
         
  return;
  
}

/* -----------------------------------------------------------------------------
 * Creates user defined function that displays the seventh term time eleven
 * which is the sum of the fibonacci sequence. 
 * -----------------------------------------------------------------------------
*/


void eleven_times_the_seventh_element(int num)
{
     cout << "The seventh element is " << num << ".  " << ELEVEN << " x " << num;
     cout << " = " << ELEVEN * num << endl;
     
}

int main()
{

// local variables
  int first_number;
  int second_number;
  int seventh_term;
  
// assignment statements 
  first_number = getNumbers ("Enter the first number: ");
  second_number = getNumbers ("Enter the second number: ");
  cout << endl << endl;
  
// call to user defined function to calculate fibonacci sequence
  fibonacciCalculate(first_number, second_number,seventh_term);
  
  cout << endl << endl;
  
// call to user defined funciton to display seventh term times eleven
  eleven_times_the_seventh_element(seventh_term);

  
  
    cout << endl << endl;
    system ("PAUSE");

    return 0;
}
