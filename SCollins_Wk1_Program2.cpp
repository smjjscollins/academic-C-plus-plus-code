//------------------------------------------------------------------------------
// Author: Sean Collins
// Class:  CS361
// Assignment: Week 1, Program 2
// Date: January 11, 2011
// Program Description: Calculates Bill for Cost of Graduation Announcements
//   Input: Student Name, Cost of Announcements, Number of Announcements Ordered
//   Processing:  Aligns Text and Calculates Total Bill
//   Output: Displays the Total for Cost of Graduation Announcements
// -----------------------------------------------------------------------------

#include <iostream>                                       
#include <iomanip>                                        
using namespace std;

// Global Constants Defined
const int MINIMUM_ANNOUNCEMENTS = 25;
const float COST_ANNOUNCEMENTS = 1.04;
const float DISCOUNT_COST = 0.94;
const float COST_STUDENT_NAMECARDS = 0.42;
const string STUDENT_NAME = "Sean Collins";
const char FIRSTNAME_INITIAL = 'S';
const char LASTNAME_INITIAL = 'C';

int main()
{
  // Local Variables Defined
  int totalOrdered;
  float totalRegularPrice;
  float totalDiscountPrice;
  float totalNameCards;
  float billTotal;
  
  // Program Header and Input from user
  
  cout << "Graduation Announcement Billing Program" << endl;
  cout << endl;
  cout << "Enter number of announcements ordered: ";
  cin >> totalOrdered;
  cout << endl << endl;
  
  // Assignment Statements to Calcualate Costs
  totalRegularPrice = MINIMUM_ANNOUNCEMENTS * COST_ANNOUNCEMENTS;
  totalDiscountPrice = (totalOrdered - MINIMUM_ANNOUNCEMENTS) * DISCOUNT_COST;
  totalNameCards = totalOrdered * COST_STUDENT_NAMECARDS;
  
  
  // Begin Output
  cout << fixed << showpoint << setprecision(2) << endl;
  cout << "Graduating Student: " << setw(15) << STUDENT_NAME;
  cout << "(" << FIRSTNAME_INITIAL << LASTNAME_INITIAL << ")" << endl;
  cout << "Announcements Ordered: " << totalOrdered << endl;
  cout << endl << endl;
  cout << "Full Price Announcement Cost: $" << totalRegularPrice << endl;
  cout << "Discounted Announcement Cost: $" << setw(5) << totalDiscountPrice;
  cout << endl;
  cout << "Student Name Card Cost: " << setw(7) << "$" << totalNameCards << endl;
  cout << endl;
  cout << setw(36) << "---------" << endl;
  
  // Assignment Statement to calculate total
  billTotal = totalRegularPrice + totalDiscountPrice + totalNameCards;
  
  cout << "Total Bill for Announcements: $" << billTotal;
  
    cout << endl << endl;
    system ("PAUSE");

    return 0;
}
