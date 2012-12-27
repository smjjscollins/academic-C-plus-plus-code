//------------------------------------------------------------------------------
// Author: Sean Collins
// Class:  CS361
// Assignment: Week 2, Program 1
// Date: January 18, 2011
// Program Description: Calculates Bill for InsureU Insurance Premium
//   Input: Original Vehicle Cost and Year of Manufacture
//   Processing:  Calculates Yearly Collision, Comprehensive and Liability 
//   Output: Displays the Annual Cost of Insurance
//   Other comments:
//                   - Uses double precision for all floating point variables
//
//                   - Uses a separate, user-defined function to output a 
//                   program description header to the user before prompting for
//                   input.  This header should contain your name. 
//
//                   - Reads inputs from the user for the the original cost of
//                   the automobile and the model year.
//
//                   - Calculates and displays the cost of collision, 
//                   comprehensive, and liability insurance, along with the
//                   total insurance premium for the year.
//
//                   - Displays all calculations(include both dollars and cents)
//                   Labels all output and make sure that the decimals all line
//                   up.
// -----------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
using namespace std;

// global constants

const double COLLISION_DISCOUNT_1 = 0.02;      // collision discount %
const double COLLISION_DISCOUNT_2 = 0.0015;      // depreciation per year %        I CORRECTED THIS
const double COMPREHENSIVE_DISCOUNT_1 = 0.0035;  // comprehensive discount %       I CORRECTED THIS
const double COMPREHENSIVE_DISCOUNT_2 = 150.00;// comprehensive cash discount 
const double LIABILITY = 190.00;               // cost for liability insurance
const int CURRENT_YEAR = 2009;

//----------------------------------------------------------------------
// Creates user defined function programHeader which displays the header
// information and author of the program.
// ---------------------------------------------------------------------
 
void programHeader()   
{
  cout << setw(20) << "InsureU Insurance Premium Calculations";
  cout << endl;
  cout << setw(20) << "by" << endl;
  cout << setw(30) << "Mr. Sean Collins" << endl;
  cout << endl;

  return;
}

int main()
{
  //local variables
  double originalCostVehicle;
  double collision;
  double comprehensive;
  double liability;
  double total;
  double depreciationValue;
  double collisionAdjustment;
  double comprehensiveAdjustment;
  int vehicleYear;
  
  
  // call to user defined function
  programHeader(); 
  
  // begin user input
  cout << "Enter original cost of vehicle: ";
  cin >> originalCostVehicle;
  cout << endl;
  
  cout << "Enter vehicle model year: ";
  cin >> vehicleYear;
  cout << endl;
  cout << endl << endl;
  // end user input
  
  // assignment statments
  collisionAdjustment = COLLISION_DISCOUNT_1 * originalCostVehicle;
  depreciationValue = (CURRENT_YEAR - vehicleYear) * (originalCostVehicle * COLLISION_DISCOUNT_2); // CORRECTED THIS
  collision = collisionAdjustment - depreciationValue;
  comprehensiveAdjustment = COMPREHENSIVE_DISCOUNT_1 * originalCostVehicle;
  comprehensive = comprehensiveAdjustment + COMPREHENSIVE_DISCOUNT_2;
  total = collision + comprehensive + LIABILITY;
  
  // begin output
  cout << "RESULTS: " << endl << endl;
  cout << fixed << showpoint << setprecision(2) << endl;
  
  cout << "Collision:         $  " << setw(8) << collision << endl;
  cout << "Comprehensive:     $  " << setw(8) << comprehensive << endl;
  cout << "Liability:         $  " << setw(8) << LIABILITY << endl;
  cout << setw(30) << "----------" << endl;
  
  cout << "TOTAL              $  " << setw(8) << total << " annually" << endl;
  
    cout << endl << endl;
    system ("PAUSE");

    return 0;
}
