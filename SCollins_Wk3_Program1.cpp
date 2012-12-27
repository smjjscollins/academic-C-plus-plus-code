//------------------------------------------------------------------------------
// Author: Sean Collins
// Class:  CS361
// Assignment: Week 3, Program 1
// Date: January 24, 2011
// Program Description: Calculates Bill for Rent2U Car Rental
//   Input: Vehicle size, milelage terms, length of rental
//   Processing:  Calculates final charges
//   Output: Displays final charges to user
//
//                     Additional Comments:
//
// - Customers can rent compact, midsize, or fullsize cars at the 
//   following rates:
//
//  		Mileage Charged
//	Car		Daily Rate		
//	Size     		(1-5 days) 	         
//	Compact	     $ 18.99	
//	Midsize	     $ 23.99			
//	Fullsize	 $ 28.99	
//
// - Customers can choose to pay extra for unlimited mileage, or 
//   be charged for mileage 
//
//	Charge per Mile	= 5 cents per mile
//	or
//	Unlimited Mileage Daily Rate = Additional $4 per day
//		(NOTE: $4 is the daily rate INCREASE, not a mileage charge)
//
// - Customers can take out insurance on the car or waive the insurance.
//	Insurance charge = additional $5 per day
//
// - Cars rented for over 7 days are charged a lower weekly rate for whole weeks.
//	Weekly Rate (for 7 days):  6.5 x Daily Rate
//
//	Rate Examples:	
// 12 days = 	1 x weekly rate + 5 x daily rate
//				14 days = 		2 x weekly rate
//				15 days = 		2 x weekly rate + 1 x daily rate
//
// - All car rentals are subject to a 6% state tax on the full charge, 
//   including mileage.  
// - Cars rented for over 30 days receive a 5% monthly discount 
//   (in addition to any weekly rate already given) before tax is added.
// - If a customer rents a car less than 7 days or for more than 30 days, 
// a message should also be displayed at the bottom of the bill, after the total
// Create separate a user-defined function, which takes the number of days
// rented as an input argument and outputs the correct message, if necessary
// (i.e. the function should do nothing if the days rented are are between
// 6 and 30).  
// Example messages:	
// Warning: Too few days to earn weekly rate.
// Congratulations, you have earned an additional monthly discount.
// - The program should output a car rental bill, formatted as shown on the
//   next page.
// - The program must use constants for ALL fixed values and descriptive
//   variable names.
// - The program shall use descriptive names for all constants and variables.
// - The program shall use double type constants and variables for all dollar
//   values.
// -----------------------------------------------------------------------------

#include <iostream>             // for I/O
#include <iomanip>              // for formatting output
#include <cmath>                // for math functions
#include <cctype>               // classify and transform individual characters

using namespace std;

// Global Constants
const double COMPACT_AUTO = 18.99;          // daily rate for compact car
const double MIDSIZE_AUTO = 23.99;          // daily rate for midsize car
const double FULLSIZE_AUTO = 28.99;         // daily rate for fullsize car
const double CHARGE_PER_MILE = .05;         // charge per mile of usage
const double UNLIMITED_MILEAGE_CHARGE = 4.00; // charge for unlimited mileage
const double INSURANCE_CHARGE = 5.00;       // optional insurance charge
const double SALES_TAX = .06;               // sales tax applied to full charge
const double MONTHLY_DISCOUNT_CALC = .05; // discount rental 30 days or longer 
const double WEEKLY_RATE_CALC = 6.5; //  multiplier for cars rented 7+ days
const int BOUNDARY_SEVEN_DAYS = 7;
const int BOUNDARY_THIRTY_DAYS = 31;


// User defined function to display bill header information
 void billCalculationHeader()   
{
	cout << setw(20) << "Rent2U Car Rental: Car Selection Tool";
    cout << endl;
    cout << endl;
    cout << endl;

	return;

}

// User defined function to display days rented message to user
void rentalDaysMessage(int daysRented)
{
     if (daysRented < BOUNDARY_SEVEN_DAYS){
        cout << "Warning: Too few days to earn weekly rate." << endl;
        }
     else
     if (daysRented > BOUNDARY_THIRTY_DAYS){
        cout << "Congratulations, you have earned an additional";
        cout << " monthly discount." << endl;
        }
  return;
}

int main()
{

// local variables
  char carSizeOption;
  char unlimitedMileageOption;
  int rentalDays;
  int totalMilesDriven;
  string optionalInsurance;
  string carSizeOutput;
  double carCharge;
  double mileageCharge;
  double subTotal;
  double total;
  double tax;
  double weeklyRate;
  double dailyRate;
  double monthlyDiscount;
  double finalCharge;
  
  
// call to user defined function
  billCalculationHeader();
  
// begin user input

  cout << "Enter car size (C,M,F): ";
  cin >> carSizeOption;
  cout << endl;
  
  
  carSizeOption = toupper (carSizeOption);

  cout << "Enter days rented: ";
  cin >> rentalDays;
  cout << endl;
  

  cout << "Charge for each mile driven (Y/N) ?: ";
  cin >> unlimitedMileageOption;
  cout << endl;
  
  
  unlimitedMileageOption = toupper (unlimitedMileageOption);
  
//------------------------------------------------------------------------------
// if statment to determine if user should be prompted to enter miles driven
// based on previous choice to be charged for miles driven
//------------------------------------------------------------------------------

     if (unlimitedMileageOption == 'Y'){
         cout << "Enter miles driven: ";
         cin >> totalMilesDriven;
         cout << endl;
         }
    
  cout << "Insurance requested (yes or no): ";
  cin >> optionalInsurance;
  cout << endl;


// begin output

  system ("CLS");
  
  cout << "RENTAL BILL:" << endl;
  cout << endl;
  
//------------------------------------------------------------------------------
// if-else statement inidicating type of car chosen as a string
//------------------------------------------------------------------------------

       if (carSizeOption == 'C'){
          carSizeOutput = "Compact";
          }
       else 
       if (carSizeOption == 'M'){
          carSizeOutput = "Midsize";
          }
       else 
       if (carSizeOption == 'F'){
          carSizeOutput = "Fullsize";
          }
          
  cout << "Car Size " << setw(20) << carSizeOutput << endl;
  cout << endl;

//------------------------------------------------------------------------------
// if statement to determine if total miles driven should be displayed
//------------------------------------------------------------------------------

       if (unlimitedMileageOption == 'Y'){
          cout << "Mileage" << setw(19) << totalMilesDriven << " miles" << endl;
          cout << endl;
          cout << "Days Rented" << setw(15) << rentalDays << " days" << endl;
          cout << endl;
          }
       else 
       if (unlimitedMileageOption = 'N'){
            cout << "Days Rented" << setw(15) << rentalDays << " days" << endl;
            cout << endl;
            }
 
//------------------------------------------------------------------------------ 
// if-else statement to calculate charge for car chosen 
//------------------------------------------------------------------------------

        if (carSizeOption == 'C'){
           carCharge = COMPACT_AUTO;
           }
        else
        if (carSizeOption == 'C' && unlimitedMileageOption == 'N'){
           carCharge = COMPACT_AUTO + UNLIMITED_MILEAGE_CHARGE;
           }
        else
        if (carSizeOption == 'C' && optionalInsurance == "yes"){
           carCharge = COMPACT_AUTO + INSURANCE_CHARGE;
           }  
        else
        if (carSizeOption == 'C' && unlimitedMileageOption == 'N'  && optionalInsurance == "yes" ){
           carCharge = COMPACT_AUTO + INSURANCE_CHARGE + UNLIMITED_MILEAGE_CHARGE;
           }                 
        else 
        if (carSizeOption == 'M'){
           carCharge = MIDSIZE_AUTO ;
           }
        else
        if (carSizeOption == 'M' && unlimitedMileageOption == 'N'){
           carCharge = MIDSIZE_AUTO + UNLIMITED_MILEAGE_CHARGE;
           }
        else
        if (carSizeOption == 'M' && optionalInsurance == "yes"){
           carCharge = MIDSIZE_AUTO + INSURANCE_CHARGE;
           }  
        else
        if (carSizeOption == 'M' && unlimitedMileageOption == 'N'  && optionalInsurance == "yes" ){
           carCharge = MIDSIZE_AUTO + INSURANCE_CHARGE + UNLIMITED_MILEAGE_CHARGE;
           }  
        else 
        if (carSizeOption == 'F'){
           carCharge = FULLSIZE_AUTO;
           }
        else
        if (carSizeOption == 'F' && unlimitedMileageOption == 'N'){
           carCharge = FULLSIZE_AUTO + UNLIMITED_MILEAGE_CHARGE;
           }
        else
        if (carSizeOption == 'F' && optionalInsurance == "yes"){
           carCharge = FULLSIZE_AUTO + INSURANCE_CHARGE;
           }  
        else
        if (carSizeOption == 'F' && unlimitedMileageOption == 'N'  && optionalInsurance == "yes" ){
           carCharge = FULLSIZE_AUTO + INSURANCE_CHARGE + UNLIMITED_MILEAGE_CHARGE;
           } 
            
         
//------------------------------------------------------------------------------
 // if-else to determine daily and weekly rate based on rental days
//------------------------------------------------------------------------------

        if (rentalDays >= BOUNDARY_SEVEN_DAYS){
                       
           dailyRate = carCharge * (rentalDays / BOUNDARY_SEVEN_DAYS);
           weeklyRate = WEEKLY_RATE_CALC * dailyRate;
           finalCharge = dailyRate + weeklyRate;
           
           cout << fixed << showpoint << setprecision(2) << endl;
           cout << "Car Charge" << setw(15) << "$"  << finalCharge << endl;
           cout << endl;           
           }
        
        else
        if (rentalDays < BOUNDARY_SEVEN_DAYS){
                       
           finalCharge = carCharge * rentalDays;
           
           cout << fixed << showpoint << setprecision(2) << endl;
           cout << "Car Charge" << setw(15) << "$"  << finalCharge << endl;
           cout << endl;
           }
       
           
        if (rentalDays >= BOUNDARY_THIRTY_DAYS){
                       
           finalCharge = (dailyRate + weeklyRate) * MONTHLY_DISCOUNT_CALC + dailyRate + weeklyRate;
        
           cout << fixed << showpoint << setprecision(2) << endl;
           cout << "Car Charge" << setw(15) << "$"  << finalCharge << endl;
           cout << endl;
           }
  
  
 
//------------------------------------------------------------------------------ 
// if statement to calculate charge for mileage
//------------------------------------------------------------------------------

       if (unlimitedMileageOption == 'Y'){
                                  
          mileageCharge = totalMilesDriven * CHARGE_PER_MILE;
          
          cout << "Mileage Charge" << setw(12) << "$" << mileageCharge << endl;
          cout << endl;
          cout << setw(31) << "----------" << endl;
          cout << endl;
  
          subTotal = finalCharge + mileageCharge;
  
          cout << "Subtotal" << setw(17) << "$" << subTotal << endl;
          cout << endl;
          cout << setw(31) << "----------" << endl;
          cout << endl;
          
          tax = subTotal * SALES_TAX;
          cout << "Tax" << setw(23) << "$" << tax << endl;
          cout << endl;
          }
  
      else
      if (unlimitedMileageOption == 'N'){
                                  
           tax = finalCharge * SALES_TAX;
           
           cout << "Tax" << setw(23) << "$" << tax << endl;
           cout << endl;
           }
  
      if (rentalDays >= BOUNDARY_THIRTY_DAYS){
                     
         monthlyDiscount = (dailyRate + weeklyRate) * MONTHLY_DISCOUNT_CALC;
         
         cout << "Monthly Discount" << setw(10) << "$" << monthlyDiscount;
         cout << endl << endl;
         }
  
  cout << setw(31) << "----------" << endl;
  cout << endl;
  
  total = subTotal + tax;
  
  cout << "Total" << setw(20) << "$" << total << endl;
  cout << endl << endl;
  
  rentalDaysMessage(rentalDays);
   
    cout << endl << endl;
    system ("PAUSE");

    return 0;
}
