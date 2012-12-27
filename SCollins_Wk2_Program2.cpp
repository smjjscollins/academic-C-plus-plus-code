// -------------------------------------------------------
// Author: Sean Collins
// Class:  CS361
// Assignment: Week 2, Program 2
// Date: January 18, 2011
// Program Description: Calculate the Area of a Triangle
//   Input: Lenght of 3 Sides
//   Processing:  Calculate Area given Formula to Compute Area
//   Output: Area of Triangle
//   Other comments:  
//                    - Reads the lengths of three sides of a triangle as inputs
//                    from the user.
//
//                    - Calculates the area of a triangle 
//                    * Uses the pre-defined sqrt function from the cmath
//                    * library in the area calculation
//
//                    - Use a separate, user-defined function to output the 
//                    results 
//                    * The function should have four parameters:  the three 
//                    * side lengths and the area
//                    * From within the user-defined function, display the three
//                    * side lengths and the area  formatted as shown below, 
//                    * each rounded to 2 decimal place, with the decimals 
//                    * lining up.
// -------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <cmath>


using namespace std;

// global constants

  const int DIVISOR = 2; // divisor for sides calculation
  
//----------------------------------------------------------------------
// Creates user defined function programHeader which displays the header
// information and author of the program.
// ---------------------------------------------------------------------
 
void programHeader()   
{
  cout << "Triangle Area Calculation";
  cout << endl;
  cout << endl;

  return;
}

//----------------------------------------------------------------------
// Creates user defined function which calculates sides and area of a triangle
// and outputs the results to the user. Value prameters are used to pass the 
// values from main into the calculateArea function
// ---------------------------------------------------------------------

void display (float sideA, float sideB, float sideC, float area)
{
  
  // output 
  cout << fixed << showpoint << setprecision(2) << endl;
  cout << "RESULTS:" << endl;
  cout << "Side 1:    " << setw(5) << sideA << " meters" << endl;
  cout << "Side 2:    " << setw(5) << sideB << " meters" << endl;
  cout << "Side 3:    " << setw(5) << sideC << " meters" << endl;
  cout << "  Area:    " << setw(5) << area  << " square meters" << endl;
 
} 


int main()
{
  // local variables
  
  float sideOne;
  float sideTwo;
  float sideThree;
  float area;
  float sides;
  float multiplier;
  
  
  // call to user defined function to display program header 
  programHeader();
  
  // user input 
  cout << "Enter the lengths of three sides of a triangle (in meters)." << endl;
  cout << "Enter the first side: ";
  cin >> sideOne;
  cout << "Enter the second side: ";
  cin >> sideTwo;
  cout << "Enter the thrid side: ";
  cin >> sideThree;
  cout << endl << endl;
  
  sides = (sideOne + sideTwo + sideThree) / DIVISOR;
  multiplier = sides * (sides - sideOne) * (sides - sideTwo) * (sides - sideThree);
  area = sqrt (multiplier);
  
  
    // call to user defined function to calculate and display output
  display (sideOne, sideTwo, sideThree, area);
  

    cout << endl << endl;
    system ("PAUSE");

    return 0;
}
