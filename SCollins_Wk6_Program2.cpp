/*------------------------------------------------------------------------------
* Author: Sean Collins
* Class:  CS361
* Assignment: Week 6, Program 
* Date: February 16, 2011
* Program Description: determine time to pay off existing credit 
* card balance based on monthly payment and information input by user
*   
* Input: payment amount, balance and credit card interest rate
*   
* Processing:  calculate the balance, interest charge,
* balance with interest, payment, and ending balance each month.
*
* Output: display the balance, interest charge, balance with interest,
* payment, and ending balance each month.
*-------------------------------------------------------------------------------
*/


#include <iostream>             // for I/O
#include <iomanip>              // for formatting output
#include <cmath>                // for math functions
#include <cctype>               // classify and transform individual characters


using namespace std;

// global constants
  const double OPTION_1 = 0.10;
  const double OPTION_2 = 0.20;
  const double OPTION_3 = 0.30;
  const double MINIMUM_BAL = 100.00;
  const double MINIMUM_INTEREST = 5;
  const double MAXIMUM_INTEREST = 30;
  const double MINIMUM_PAYMENT = 50;
  const double PERCENT = 100;
  const int YEAR = 12;



// begin user-defined functions

/*------------------------------------------------------------------------------
* Task:  Display program header and determine time to pay off existing credit 
*        card balance based on monthly payment and information input by user
* Input parameters: payment amount, balance and credit card interest rate
* Output parameters: amortization schedule to payoff credit card balance
*-------------------------------------------------------------------------------
*/

void creditCardMenuDisplay(int& creditRatingCode, double& beginingBalance, double& creditRatingInterestRate)
{

   bool validCode;

   cout << "This program calculates how long it will take to pay off your ";
   cout << endl;
   cout << "credit card balance." << endl;
   cout << endl;

   cout << "What will your monthly payment be? ";
   cout << endl << endl;
   
   cout << "1 - 10% of balance with interest" << endl;
   cout << "2 - 20% of balance with interest" << endl;
   cout << "3 - 30% of balance with interest" << endl;
   cout << "4 - Exit Program" << endl;
   cout << endl;   
   

   do 
   { 
        
        validCode = true;  

        cout << "Please enter a option from menu above:  ";
        cin >> creditRatingCode;
        cout << endl;
        cout << endl;

        switch (creditRatingCode) // switch to verify correct choice
        {
	
		       case 1: 
                    cout << "You have selected option 1 - 10% of balance with interest";
                    cout << endl;
                    break;
        
        	   case 2:    
                    cout << "You have selected option 2 - 20% of balance with interest";
                    cout << endl;
                    break;
		
               case 3:    
		            cout << "You have selected option 3 - 30% of balance with interest";
                    cout << endl;
                    break;
       
               case 4:
	                cout << "You have selected option 4 - Exit Program" << endl;
                    cout << endl;
                    break;
            
               default:
                    cout << "Error - no such option!" << endl;
                    validCode = false;
                    break;
        } // end switch
        
   } while (!validCode);
   
   do
   {
      cout << fixed << showpoint << setprecision(2) << endl;
      cout << "Enter your beginning balance: ";
      cin >> beginingBalance;
      cout << endl;   
      
      if (beginingBalance < MINIMUM_BAL)
      {
           cout << "A minimum balance of $" << MINIMUM_BAL << " is required." << endl;
           cout << "Please try again." << endl;
      }
   }
   while (beginingBalance < MINIMUM_BAL);   
   
   do
   {
         
      cout << "Enter the credit card's annual interest rate: ";
      cin >> creditRatingInterestRate;
      cout << endl;

      if (creditRatingInterestRate < MINIMUM_INTEREST || MAXIMUM_INTEREST < creditRatingInterestRate)
      {
            cout << "You must enter an interest rate between " << MINIMUM_INTEREST;
            cout << "% and " << MAXIMUM_INTEREST << "%." << endl;
            cout << "Please try again." << endl;
      }
   }
   while (creditRatingInterestRate < MINIMUM_INTEREST || MAXIMUM_INTEREST < creditRatingInterestRate);
   
   creditRatingInterestRate = creditRatingInterestRate / PERCENT;   
            
  return;
}


/*------------------------------------------------------------------------------
* Task:  calculate monthly interest payment
* Input parameters: credit option and balance
* Output parameters: monthly interest
*-------------------------------------------------------------------------------
*/
double monthlyPayment(int creditOpt, double balance)
{
    
  double payment;
  
  if (creditOpt == 1)
    payment = balance * OPTION_1;
  else
    if (creditOpt == 2)
      payment = balance * OPTION_2;
    else
      if (creditOpt == 3)
        payment = balance * OPTION_3;
         
  return payment;
  
}


/*------------------------------------------------------------------------------
* Task:  display amortization payment info
* Input parameters: balance, interst charge, payment
* Output parameters: months, beginning balance, balance + interest, payment,
*                    ending balance
*-------------------------------------------------------------------------------
*/
void displayHeader(int creditOpt)
{

    cout << "RESULTS:" << endl;
    cout << "----------------------------------------------------------------";
    cout << endl;
    cout << "         Initial    Month's     Balance ";
    
    if (creditOpt == 1)
      cout << "       10%        End" << endl;
    else
      if (creditOpt == 2)
        cout << "       20%        End" << endl;
      else
        if (creditOpt == 3)
          cout << "       30%        End" << endl;   
    
    cout << "Month    Balance    Interest    w/Interest    Payment    Balance";
    cout << endl;
    cout << "----------------------------------------------------------------";
    cout << endl;
}    
  



int main()
{
    
// local variables
  int credit_option;
  double balance;
  double first_bal;
  double second_bal;
  double monthly_interest;
  double payment;
  double interest_rate;
  double monthly_rate;
  
  int month = 1;

  // call to 1st funtion that gathers user input
  creditCardMenuDisplay(credit_option, balance, interest_rate);
  
  displayHeader(credit_option);
  
  monthly_rate = interest_rate / YEAR;
 
  // call to 2nd function that calculates initial balance using loops
  while (balance > 0)
  {
      first_bal = balance;
      
      monthly_interest = first_bal * monthly_rate;
      
      second_bal = first_bal + monthly_interest;
      
      payment = monthlyPayment(credit_option, second_bal);
      
      if (payment < MINIMUM_PAYMENT)
        if (second_bal < MINIMUM_PAYMENT)
          payment = second_bal;
        else  
          payment = MINIMUM_PAYMENT;
        
      balance = second_bal - payment;
        
      cout << month << "  " << first_bal << "  " <<  monthly_interest << "  " << second_bal << "  " << payment << " " << balance << endl;
       
      month++;
  } 
   
  cout << endl << endl;
  system ("PAUSE");

  return 0;
}

