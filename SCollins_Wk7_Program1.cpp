/* -----------------------------------------------------------------------------
* Author: Sean Collins
* Class:  CS361
* Assignment: Week 7, Program 1
* Date: February 22, 2011
* Program Description: example recursive and iterative functions
*   Input: number and integer
*   Processing:  calcuale the factorial of a number based on integer entered
*   Output: displays the factorial produced by the recursive and iterative
*           funtions
*-------------------------------------------------------------------------------
*  Additional Comments:
* Given the following recursive function, answer the two sub-problems below. 
*
* float wk7recur (int num) 
* {
*  if (num == 0)
*      return 1;
*  else
*      return ( 2 * wk7recur (num - 1) );
*}
*  
*Sub-Problem 1: 
*
* What would the value of answer be for each of the following?  Calculate your 
* answers by hand. You will need to report ALL intermediate answers for each 
* level of recursion (NOT just the final result).
*
* a)float answer = wk7recur (1); 
* b)float answer = wk7recur (3); 
* c)float answer = wk7recur (5); 
*
*answers to sub-problems 1a-c & 2
*
* 1a. 1
*
* The value of inum: 1 is passed into wk7recur function. The automatic variable,
* num, does not meet the base condition if (num == 0) return 1, num is passed to
* the else condition which calculates the value in the return statment.
* The first pass through the recurssion results in 2 * wk7recur (num(1)-1) 
* and the value 2.00 is passed back to main and inum has the value of 2. 
*
* 1st pass: 2.0 * 1.0 = 2.0
* On the second pass inum equals 0 and the function terminates and returns, with 
* a value of 1, back to main()
* 2nd pass: num = 0, return 1
* inum = 2.00
*
* 1b. 3
*
* The  value of inum: 3 is passed into wk7recur function. The automatic variable,
* num, does not meet the base condition if (num == 0) return 1, num is
* passed to the else condition which calculates the value in the return
* statment. The first pass through the recurssion results in
* 2 * wk7recur (num(3) -1) and the integer 2 is passed back to main and inum now 
* has the value of 2.
*
* 1st pass: 2.0 * 2.0 * 2.0 = 8.0
* 2nd pass: 2.0 * 2.0 = 4.0
* 3rd pass: 2.0 * 2.0 = 2.0
* 4th pass: num = 0, return 1,
*
* inum = 8.00
*
* 1c. 5
*
* The  value of inum: 5 is passed into wk7recur function. The automatic variable,
* num, does not meet the base condition if (num == 0) return 1, num is
* passed to the else condition which calculates the value in the
* return statment. The first pass through the recurssion results in
* 2 * wk7recur (num(5) -1) 
*
* 1st pass: 2.0 * 2.0 * 2.0 * 2.0 * 2.0 = 32.0
* 2nd pass: 2.0 * 2.0 * 2.0 * 2.0 = 16.0
* 3rd pass: 2.0 * 2.0 * 2.0 = 8.0
* 4th pass: 2.0 * 2.0 = 4.0
* 5th pass: 2.0 * 1.0 = 2.0
* 6th pass: num = 0, return 1,
*
* inum = 32.00
*
* Sub-Problem 2: 
*
* Figure out what computation is being performed by the wk7recur function. 
* What is the name of the math computation performed by this function?
* Exponentiation Math
*-------------------------------------------------------------------------------
*/

#include <iostream>             // for I/O
#include <iomanip>              // for formatting output
#include <cmath>                // for math functions
#include <cctype>
//------------------------------------------------------------------------------
// function prototypes
//------------------------------------------------------------------------------

float wk7recur (int num);
float wk7loop (int num1);



using namespace std;

int main()
{
// local variables

  float answerRecur;
  float answerLoop;
  int inum;

// start input from user

  cout << fixed << showpoint << setprecision (2);
  cout << "This program will take two numbers and use a recursive function and";
  cout << endl;
  cout << "an iterative loop to calculate the factorial of a given number.";
  cout << endl;
  cout << endl;
  do
  {
     do
     {
          cout << "Please enter a positive integer or -1 to exit: ";
          cin >> inum;
          cout << endl;
     
          if (inum < -1)
            cout << "The input is invalid, please try again!"  << endl;
     
     }
     while (inum < -1);

     if (inum != -1)
     {

       // call to functions
       answerRecur = wk7recur (inum);
       answerLoop = wk7loop (inum);

       // start output 
       cout << "Recursive result = " << answerRecur << endl;
       cout << "Iterative result = " << answerLoop  << endl;

     }// end if
     
  }
  while (inum != -1);
       
  cout << endl << endl;
  
  return 0;
}


// user defined funtions

//------------------------------------------------------------------------------
// Discription:  recursive function
// Input parameters: value parametes value and num
// Output parameters: returns calculation to main 
//------------------------------------------------------------------------------
float wk7recur (int num)
{
    if (num == 0)
       return 1;
    else
       return ( 2 * wk7recur (num - 1) );
}

//------------------------------------------------------------------------------
// Discription:  iterative function
// Input parameters: value parametes value and num
// Output parameters: returns calculation to main value * count
//------------------------------------------------------------------------------

float wk7loop (int num1)
{
  int loop;
  int count = 1;
    
     for (loop = 1; loop <= num1; loop++){
         count = (2 * count);
     } 
    
 return count;
 
}


