/* -----------------------------------------------------------------------------
*  Author: Sean Collins
*  Class:  CS361 Control Structures
*  Assignment: Week 4, Program 1
*  Date: February 2, 2011
*
*  Program Description: program to determine if three numbers input by the
*  user could represent the sides of a triangle, and if so, what kind of 
*  triangle. 
*
*    Input: The program should first read the lengths of three sides of a triangle.
*
*   Sample Input:	Enter three numbers, separated by spaces
*					3 4 5

*   Processing:  The program should first determine whether the lengths entered
*   could form a triangle, using the following rule:
*   RULE:	Three numbers can represent the sides of a triangle if and only if
*   each number is less than the sum of the other 2 numbers.
*
*   Output:  the program should output the 3 side lengths (right justified to
*   line up with each other) and the triangle type, as shown in the sample
*   outputs below.  
*   Possible types are:
*			Not a triangle
*			Equilateral triangle
*			Isosceles triangle
*			Isosceles right triangle
*			Scalene triangle
*			Scalene right triangle
*   If the triangle is a right triangle, also display the hypotenuse length.
*
*   Additional comments:
*
*     Program Logic
*     The program should first determine whether the lengths entered could
*     form a triangle, using the following rule:
*
*     RULE:	Three numbers can represent the sides of a triangle if and only if
*     each number is less than the sum of the other 2 numbers.
*     Use a boolean variable to store the result.  If the numbers can represent
*     a triangle, set the boolean variable value to true. Otherwise, set the
*     boolean variable value to false.  
*     After the boolean variable value has been set, use it to decide what
*     to do next.
*     If the numbers cannot represent the sides of a triangle (i.e. the boolean
*     variable's value is false), the program should proceed directly to the
*     program output part of the program.
* 
* 	 If the numbers CAN represent the sides of a triangle (i.e. the boolean
*    variable's value is true), then ask the user whether or not s/he wishes
*    to determine the type of triangle the sides represent.  Read the answer as
*    a single character.
* 
*    If the user enters 'n' or 'N', the program should proceed directly to
*    the program output part of the program.
* 
* 	 If the user enters 'y' or 'Y', write a user-defined function to determine
*    the type of triangle the sides represent, as follows:
*
* 		No equal length sides 			?	scalene triangle
*		2 of the 3 sides are equal length 	?	isosceles triangle
*		All 3 sides are equal length 		?	equilateral triangle
*
*    The user-defined function will:
*    Be given a descriptive name. 
*    Take the three side lengths input arguments and will return a string
*    description to the main function that describes the triangle type.
*    The string will be set to the value "SCALENE", "ISOSCELES", or "EQUILATERAL".  
*    After determining the type of triangle via the user-defined function,
*    use the pythagorean theorem:
*
*				Side12 + Side22 = Hypotenuse2
*
*    on the isosceles and scalene triangles to additionally determine whether
*    the triangle is a right triangle (i.e. if the above equation is true,
*    then the triangle is a right triangle).  
*    Note:  the hypotenuse will always be the longest of the 3 sides.
* -----------------------------------------------------------------------------
*/

// pre processing directives

#include <iostream>             // for I/O
#include <iomanip>              // for formatting output
#include <cmath>                // for math functions
#include <cctype>               // classify and transform individual characters


using namespace std;

//Global Constants
const string NOT_A_TRINAGLE = "Not a triangle";
const string EQUILATERAL_TRIANGLE = "Equilateral triangle";
const string ISOSCELES_TRIANGLE = "Isosceles triangle";
const string ISOSCELES_RIGHT_TRIANGLE = "Isosceles right triangle";
const string SCALENE_TRIANGLE = "Scalene triangle";
const string SCALENE_RIGHT_TRIANGLE = "Scalene right triangle";

string itIsATriangle(double, double, double);


int main()
{

// local variables

    double sideOne;
    double sideTwo;
    double sideThree;
    double hypot;
    bool triangle;
    bool right = false;
    char response;
    string typeOfTriangle;
    string test = " ";
    
   // begin program input from user
    cout << "Enter three numbers, separated by spaces: ";
    cin >> sideOne >> sideTwo >> sideThree;
    cout << endl << endl;

   // if else statement to determine if the length of the sides entered are a 
   // triangle

    if (sideOne < sideTwo + sideThree && sideTwo < sideOne + sideThree && sideThree < sideOne + sideTwo)
       triangle = true;
    else
       triangle = false;

       
   // if else statment to output message indicating lengths entered are either 
   // triangle or not
            
    if (triangle == false)
    {
        cout << "Lengths" << endl;
        cout << setw(7) << sideOne << endl;
        cout << setw(7) << sideTwo << endl;
        cout << setw(7) << sideThree << endl;
        cout << "CANNOT form a triangle." << endl;
    }    
    else
    {      
        cout << "The numbers entered do represent the sides";
        cout << " of a Triangle." << endl;
        cout << "Do you wish to determine the type";
        cout << " of triangle (Y for yes, N for no)?: ";
        cin >> response;
        cout << endl << endl;
        response = toupper (response);
 
        if (response == 'Y')
        {
           typeOfTriangle = itIsATriangle(sideOne, sideTwo, sideThree);
           
           if (typeOfTriangle == "ISOSCELES" || typeOfTriangle == "SCALENE")
           {
              if (sideOne > sideTwo && sideOne > sideThree)
              {
                 right = (pow(sideTwo,2.0) + pow(sideThree,2.0) == pow(sideOne,2.0));
                 hypot = sideOne;
                 if (right)
                    test = " right ";
              }
              else 
                if (sideTwo > sideOne && sideTwo > sideThree)
                {
                   right = (pow(sideOne,2) + pow(sideThree,2) == pow(sideTwo,2));
                   hypot = sideTwo;
                   if (right)
                      test = " right ";
                }   
                else
                {
                   right = (pow(sideOne,2) + pow(sideTwo,2) == pow(sideThree,2));
                   hypot = sideThree;
                   if (right)
                      test = " right ";
                }
           }      
                       
           cout << "Lengths" << endl;
           cout << setw(7) << sideOne << endl;
           cout << setw(7) << sideTwo << endl;
           cout << setw(7) << sideThree << endl; 
           cout << "can form a " << typeOfTriangle << test << "triangle." << endl;
           cout << endl << endl;
  
        }     
        else
        {   
              cout << "Lengths" << endl;
              cout << setw(7) << sideOne << endl;
              cout << setw(7) << sideTwo << endl;
              cout << setw(7) << sideThree << endl; 
              cout << "can form a triangle." << endl;
              cout << endl << endl;
        }
    }                  
        
    cout << endl << endl;
    system ("PAUSE");

    return 0;
}


/* -----------------------------------------------------------------------------
 * Creates user defined function that asssigns string value to the type of
 * triangle. It then returns the string value to main.
 * -----------------------------------------------------------------------------
*/
string itIsATriangle(double length_A, double length_B, double length_C)   
{
  string triangleType;

      if (length_A != length_B && length_A != length_C && length_B !=length_C)
         triangleType = "SCALENE";
      else
        if (length_A == length_B && length_A == length_C && length_B == length_C)
           triangleType = "EQUALLATERAL";
        else
          triangleType = "ISOSCELES";
      
  return triangleType;

}
