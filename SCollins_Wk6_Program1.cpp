/*------------------------------------------------------------------------------
* Author: Sean Collins
* Class:  CS361
* Assignment: Week 6, Program 1
* Date: February 15, 2011
* Program Description: Monthly Credit Card Bill
*   Input: payment amount, balance and credit card interest rate
*   Processing:  Calculate Monthly credit card bill
*   Output: Displays credit card payment schedule
* Additional Comments:
*  
*  The interest rates and minumum payments will vary depending on the credit 
*  rating of the customer: 
*  Code E:	Excellent credit
*	Code A:	Above average credit
*	Code B:	Below average credit
*	Code S:	Sub-standard credit
*
* The rates are as follows:
* Code E:   Interest rate:  14% annually		
* Minimum balance due:  $10
* Code A:   Interest rate:  16% annually	
* Minimum balance due:  6% of balance for the first $1000, 5% of balance over $1000
* Code B:   Interest rate:  18% annually	
* Minimum balance due:  7% of balance for the first $1000, 6% of balance over $1000
* Code S:   Interest rate:  20% annually		
* Minimum balance due:  8% of balance
*
* No other codes should be accepted.  Remember to define constants for all
* fixed values. 
* Use double precision floating point variables, where floating
* point variables are used.
*
* The program should first explain the program to the user.  
* Then display a menu of credit rating codes, along with descriptions of each,
* to the user.  Prompt for the customer's credit rating code and error check
* that the user entered a valid credit rating code 
* (accepted in upper or lowercase). Re-prompt until a valid value is entered.  
* Also prompt for the charge balance on the card, and error check that the
* number entered is not negative (i.e. must be at least 0).  
* Re-prompt until a valid value is entered.
* The program should compute the current balance.  
* 1/12th  of 1/100th  of the annual interest rate (i.e. one month's interest) 
* should be applied to the charge balance to get the current balance.  
*
* The output should display: the customer's credit rating in words, the current
* balance (after interest was added to the charge balance), and finally,
* (unless the credit rating was E), and the minimum balance due.  
* Display neatly with descriptive text.
*
* After displaying the results, ask the user whether to execute the program
* again, and do so, as long as the user wishes to continue. 
*
* At a minimum, the program should implement three separate functions
* (in addition to main), as described on the next page: 
*
* One function to read all necessary inputs (credit rating, and if necessary,
* the charge balance).  First the function  should display the credit rating
* menu, and read and validate the customer's credit rating.  
* Then, read and validate the charge balance.  Both validated inputs shall then
* be passed back to main via reference parameters.   
* One function to calculate the current balance and return it to main. 
* Pass all necessary information into this function via input parameters.
* One function to display the bill output. Pass all necessary information
* into this function via input parameters.
* Use of global variables is NOT allowed. The functions must use parameters to
* pass required data to each function.   
* Remember to pass all input parameters by VALUE, and pass all output parameters
* by REFERENCE.
*-------------------------------------------------------------------------------
*/


#include <iostream>             // for I/O
#include <iomanip>              // for formatting output
#include <cmath>                // for math functions
#include <cctype>               // classify and transform individual characters


using namespace std;

// global constants
const char CODE_E = 'E';
const char CODE_A = 'A';
const char CODE_B = 'B';
const char CODE_S = 'S';
const int ONE_HUNDRETH = 100;
const int ONE_TWELFTH = 12;
const int ONE_THOUSAND = 1000;
// interest rates
const double CODE_E_INTEREST = 0.14; // excellant credit
const double CODE_A_INTEREST = 0.16; // above average credit
const double CODE_B_INTEREST = 0.18; // below average credit
const double CODE_S_INTEREST = 0.20; // sub-standard credit
// minimum balances due
const double CODE_E_MINIMUM_BALANCE_DUE = 10.00; 
const double CODE_A_MINIMUM_BALANCE_DUE_UNDER_1000 = 0.06; 
const double CODE_A_MINIMUM_BALANCE_DUE_OVER_1000 = 0.05; 
const double CODE_B_MINIMUM_BALANCE_DUE_UNDER_1000 = 0.07; 
const double CODE_B_MINIMUM_BALANCE_DUE_OVER_1000 = 0.06; 
const double CODE_S_MINIMUM_BALANCE_DUE = 0.08; 


// begin user-defined functions

/*------------------------------------------------------------------------------
* Task:  Display program header and determine time to pay off existing credit 
*        card balance based on monthly payment and information input by user
* Input parameters: payment amount, balance and credit card interest rate
* Output parameters: amortization schedule to payoff credit card balance
*-------------------------------------------------------------------------------
*/

void creditCardMenuDisplay(char& creditRatingCode, double& begginingBalance){

   bool validCode;

   cout << "This program calculates your monthly credit card payment " << endl;
   cout << endl;

   cout << "Please enter your credit rating from the choices below: ";
   cout << endl << endl;
   
   cout << "E - Excellent credit" << endl;
   cout << "A - Above average credit" << endl;
   cout << "B - Below average credit" << endl;
   cout << "S - Sub-standard credit" << endl;
   cout << endl << endl;   

   do
   { 
        
   validCode = true;	

   cout << "Please enter an option from menu above:  ";
   cin >> creditRatingCode;
   cout << endl;

   creditRatingCode = toupper(creditRatingCode);
   
   switch (creditRatingCode) // switch to verify correct choice
   {
	
		case 'E': 
            cout << "You have selected option E excellent credit";
            cout << endl;
            break;
        
		case 'A':    
            cout << "You have selected option A above average credit";
            cout << endl;
            break;
		
		case 'B':    
		    cout << "You have selected option B below average credit";
            cout << endl;
            break;
       
		case 'S':
	        cout << "You have selected option S sub-standard credit" << endl;
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
      cout << "You must enter a balance greater than or equal to $0.00" << endl;
      cout << endl << endl;
      cout << "Enter your charge balance: $";
      cin >> begginingBalance;
      cout << endl << endl;
      }   
  while (begginingBalance < 0);
  
  
  return;
}

/*------------------------------------------------------------------------------
* Task:  Calculate the current credit card balance based on credit rating and 
*        charge balance.
* Input parameters: credit rating, charge balance
* Output parameters: current credit card balance
*-------------------------------------------------------------------------------
*/
double calculateBalance(char creditRating, double beginBal)
{
       
  double currentBal;
  double monthlyInterestCharge;

  if (creditRating == CODE_E)
  {
     monthlyInterestCharge = CODE_E_INTEREST / ONE_TWELFTH;
     currentBal = ((beginBal * monthlyInterestCharge) + beginBal) ;
  }
  else
    if (creditRating == CODE_A)
    {
       monthlyInterestCharge = CODE_A_INTEREST / ONE_TWELFTH;
       currentBal = ((beginBal * monthlyInterestCharge) + beginBal) ;
    }
    else
      if (creditRating == CODE_B)
      {
         monthlyInterestCharge = CODE_B_INTEREST / ONE_TWELFTH;
         currentBal = ((beginBal * monthlyInterestCharge) + beginBal) ;
      }
      else 
        if (creditRating == CODE_S)
        {
           monthlyInterestCharge = CODE_S_INTEREST / ONE_TWELFTH;
           currentBal = ((beginBal * monthlyInterestCharge) + beginBal) ;
        }
              
   return currentBal;
     
}


double minimu_payment(char creditRating, double currentBalance)
{
       
     double min_due;
     
     if (creditRating == 'E')
       min_due = CODE_E_MINIMUM_BALANCE_DUE;
     else
       if (creditRating == 'A')
         if (currentBalance > ONE_THOUSAND)
           min_due = (ONE_THOUSAND * CODE_A_MINIMUM_BALANCE_DUE_UNDER_1000) + ((currentBalance - ONE_THOUSAND) *  CODE_A_MINIMUM_BALANCE_DUE_OVER_1000);
         else
           min_due = currentBalance * CODE_A_MINIMUM_BALANCE_DUE_UNDER_1000;
       else
         if (creditRating == 'B')
           if (currentBalance > ONE_THOUSAND)
             min_due = (ONE_THOUSAND * CODE_B_MINIMUM_BALANCE_DUE_UNDER_1000) + ((currentBalance - ONE_THOUSAND) *  CODE_B_MINIMUM_BALANCE_DUE_OVER_1000);
           else
             min_due = currentBalance * CODE_B_MINIMUM_BALANCE_DUE_UNDER_1000;
         else
           if (creditRating == 'S')
             min_due = currentBalance * CODE_S_MINIMUM_BALANCE_DUE;
             
     return min_due;                     
       
}


void creditRating(char creditRating, string& rating, double& interest)
{
       
    if (creditRating == 'E')
    {
      rating = "Credit rating: Excellent.";
      interest = CODE_E_INTEREST * ONE_HUNDRETH;
    }  
    else
      if (creditRating == 'A')
      {
        rating = "Credit rating: Above Average.";
        interest = CODE_A_INTEREST * ONE_HUNDRETH;
      }  
      else
        if (creditRating == 'B')
        {
          rating = "Credit rating: Below Average.";
          interest = CODE_B_INTEREST * ONE_HUNDRETH;
        }  
        else
          if (creditRating == 'S')
          {
            rating = "Credit rating: Sub-Standard.";
            interest = CODE_S_INTEREST * ONE_HUNDRETH;
          }   
   
}         
       
      
/*------------------------------------------------------------------------------
* Task:  Display current credit card balance based on credit rating and 
*        charge balance.
* Input parameters: credit rating and current balance
* Output parameters: credit rating and current credit card balance
*-------------------------------------------------------------------------------
*/

void creditCardBalanceDisplay(char creditRating, double currentBal, double minBal, string rating, double interest)
{
  
  cout << fixed << showpoint << setprecision(2);   
  cout << "Credit Card Monthly Payment" << endl;
  cout << endl;
  cout << rating << endl;
  cout << endl;
  cout << "Your current Balance is:    " << setw(8) << currentBal << endl;
  cout << "Your current Interest rate: " << setw(8) << interest << "%" << endl;
  cout << "Your Minimum balance due:   " << setw(8) << minBal << endl;
  
}


int main()
{
// local variables
double charge_balance;
char credit_rating;
double current_balance;
double minimum;
double interest;
string rating;
int makeAChoice;


  do
  {
      creditCardMenuDisplay(credit_rating, charge_balance);
      current_balance = calculateBalance(credit_rating, charge_balance);
      minimum =  minimu_payment(credit_rating, current_balance);
      creditRating(credit_rating, rating, interest);
      creditCardBalanceDisplay(credit_rating, current_balance, minimum, rating, interest);
  
      do
      {
           cout << endl << endl;
           cout << "Would you like to re-calculate your monthly bill?";
           cout << endl;
           cout << endl;
           cout << "If yes enter 1 if no enter 2:  ";
           cin >> makeAChoice;
           cout << endl;
           
           if (makeAChoice != 1 && makeAChoice != 2)
             cout << "You entered an invalid value, please try again!" << endl;
             
      }
      while (makeAChoice != 1 && makeAChoice != 2);
      
  }
  while (makeAChoice == 1);
      
  return 0;
    
}

