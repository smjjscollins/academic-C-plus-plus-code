// -----------------------------------------------------------------------------
// Author: Sean Collins
// Class:  CS361 Control Stuctures
// Assignment: Week 3, Program 2
// Date: January 25, 2011
// Program Description: IRA Deduction Worksheet
//
//  Input:
//       
//       - Whether covered by a retirement plan 
//       - Filing status (one of the following)
//         1. Single
//         2. Married, Filing Jointly
//         3. Head of Household
//         4. Qualifying Widow, Married
//         5. Filing Separately
//         - Total Income 
//         - Qualified Expenses
//         - Total Wage Income
//         - IRA Contributions 
//  
//  Processing:
//           
//           Read inputs for lines 1 and 2 (whether covered by a retirement plan
//           and filing status).
//
//           Perform necessary calculations to determine if the exit condition
//           for line 2 has been met. If yes, issue the STOP message, and return
//           from main with exit code 2. 
//           return 2;
//
//           Determine amount for line 2.
//           If user chose "Married, Filing Separately", ask if lived apart all 
//           year to determine the correct amount.
//
//           Read the input for lines 3 and 4 (total income and qualified expenses).
//           Perform the necessary calculations for line 5.
//
//           Perform necessary calculations to determine if the exit condition 
//           for line 6 has been met. If yes, issue the STOP message, and return
//           from main with exit code 6. 
//           return 6;
//           If no, calculate the amount for line 6.
//
//           Perform necessary calculations for line 7 (see further instructions
//           in the Processing Logic Notes below)
//           Read the remaining inputs (total wage income and IRA contributions)
//           Perform necessary calculations for remaining lines.
//
//  Output: displays IRA deduction on worksheet
//
//  Additional Comments:
//  (Processing Logic Notes)
//  Lines 2 and 6 have possible exit conditions. Therefore, you will need to start
//  processing after only some of your inputs have been read. Do NOT read more
//  inputs than are necessary.If the program exits on either line 2 or line 6,
//  NO lines from the Worksheet will be displayed.  
//  If neither exit condition (from line 2 and line 6) is met, then the program
//  will display the entire worksheet and return from the main function with an
//  exit code of 0.
//
//  For line 7, write a user-defined function that will round a value up to the
//  nearest multiple of 10, and use it in the line 7 calculations when necessary.
//  The function should take the original value as an input argument
//  The function should return the nearest multiple of $10.
//  No other computations should be performed within this function.
//  Examples:    Input argument of 150.01 would return 160.00
//  Input argument of 1036.56 would return 1040.00
// -----------------------------------------------------------------------------

// pre processing directives

#include <iostream>             // for I/O
#include <iomanip>              // for formatting output
#include <cmath>                // for math functions
#include <cctype>               // classify and transform individual characters

// global constants
const double QUALIFYING_WIDOWER = 85000;
const double MARRIED_FILE_SEPERATE = 10000;
const double SINGLE_HOH_OR_MFS = 60000;
const double LINE_7_CREDIT = 4000;
const double LINE_7_MULTIPLIER = .40;
const double LINE_7_LIMIT = 10000;
const double LINE_7_BENIFIT = 200;

//user defined function

double lineSevenFunction(double line_6_Formula, double LINE_7_MULTIPLIER)
{
  double roundNumber;
  
  roundNumber = line_6_Formula * LINE_7_MULTIPLIER;  
  
   if(static_cast<int>(roundNumber)% 10 == 0){
     floor(roundNumber + 10);
   }
   else {
     static_cast<int> (roundNumber);
     ceil(roundNumber + 10);
   }
  
  return roundNumber;
}

using namespace std;


int main()
{

// local variables

char retirementPlan;
char livedApart;
string retirementYes = "Yes";
string retirementNo = "No";
int filingStatus;
double totalIncome;
double qualifiedExpenses;
double wageIncome;
double iraContrabutions;
double line_2_Deduction;
double line_5_Subtract;
double lineFiveFormula;
double lineSixFormula;
double lineSevenFormula;
// user input

  cout << "Are you covered by a retirement plan (Y/N)?  ";
  cin >> retirementPlan;
  cout << endl;
  cout << endl;
  
  retirementPlan = toupper(retirementPlan);
  
  cout << "1 - Single" << endl;
  cout << "2 - Married, Filing Jointly" << endl;
  cout << "3 - Head of Household" << endl;
  cout << "4 - Qualifying Widow(er)" << endl;
  cout << "5 - Married, Filing Seperately" << endl;
  cout << endl;
  cout << "Enter your filing status from above (1 - 5):  ";
  cin >> filingStatus;
  cout << endl;
  cout << endl;

     if (filingStatus == 2){
        cout << "STOP!!! You must use a different worksheet" << endl;
        cout << endl << endl;
        system ("PAUSE");
        return 2;
        }
     else
     if (filingStatus == 5){
     cout << "You chose Married filing Seperately. Did you live with" << endl;
     cout << "your spouse during any part of the year (Y/N): ";
     cin >> livedApart;
     cout << endl << endl;
     }
     
  livedApart = toupper(livedApart);
  
     if (livedApart == 'Y'){
        line_2_Deduction = MARRIED_FILE_SEPERATE;
        }
     else {
        line_2_Deduction = SINGLE_HOH_OR_MFS;
        }
  
  cout << "Enter your total Income (1040, line 22):  ";
  cin >> totalIncome;
  cout << endl;
  cout << endl;

  cout << "Enter qualified expenses (1040, line 23-31a): ";
  cin >> qualifiedExpenses;
  cout << endl;
  cout << endl;

  cout << "Enter wage income (1040, line 7): ";
  cin >> wageIncome;
  cout << endl;
  cout << endl;

  cout << "Enter IRA contributions made (or plan to be made by deadline): ";
  cin >> iraContrabutions;
  cout << endl;
  cout << endl;

// program output

  system ("cls");
  
  cout << fixed << showpoint << setprecision (2);
  cout << setw(10) << " Deduction for Exemptions Worksheet" << endl;
  cout << endl;
  cout << endl;

// if-else statment to determine retirement plan
  
      if (retirementPlan == 'Y'){
         cout << "1. Covered by a retirement plan?  " << setw(20);
         cout << retirementYes << endl;
         cout << endl;
         }
      else 
      if (retirementPlan == 'N'){
         cout << "1. Covered by a retirement plan?  " << setw(20);
         cout << retirementNo << endl;
         cout << endl;
         }
      
// if-else statment to determine fileing status

      if (filingStatus == 1){
      
         line_2_Deduction = SINGLE_HOH_OR_MFS;
         
         cout << "2. Filing status amount (Single): " << setw(30);
         cout << line_2_Deduction << endl;
         cout << endl;
         }
      else
      if (filingStatus == 3){
         
          line_2_Deduction = SINGLE_HOH_OR_MFS;
          
         cout << "2. Filing status amount (Head of House): " << setw(30);
         cout << line_2_Deduction << endl;
         cout << endl;
         }
      else
      if (filingStatus == 4){
         
         line_2_Deduction = QUALIFYING_WIDOWER;
         
         cout << "2. Filing status amount (Widow(er)): " << setw(30);
         cout <<  line_2_Deduction << endl;
         cout << endl;
         }
       else
      if (filingStatus == 5){
         cout << "2. Filing status amount (Married Seperate): ";
         cout << setw(30) << line_2_Deduction << endl;
         cout << endl;
         }
         
  cout << "3. Total income (1040, line 22)" << setw(23) << totalIncome;
  cout << endl << endl;
  cout << "4. Qualified expenses (1040, lines 23-31a):" << setw(24);
  cout << qualifiedExpenses << endl << endl;
  cout << "-------------------------------------------------------------------";
  cout << endl << endl;
  
  lineFiveFormula = totalIncome - qualifiedExpenses;
  
  cout << "5. Subtotal (line 3-line 4):" << setw(26) << lineFiveFormula;
  cout << endl << endl;
 
 
 // if-else statemnet line 6      
       if (lineFiveFormula > line_2_Deduction){
          cout << "STOP None of your IRA contributions are deductible" << endl;
          cout << endl; 
          cout << endl << endl;     
          system ("PAUSE");

          return 6;               
          }
        else
      if (lineFiveFormula < line_2_Deduction){
                          
         lineSixFormula = line_2_Deduction - lineFiveFormula;
         
         cout << "6. Subtotal (line 2-line 5):" << setw(39) << lineSixFormula;
         cout << endl << endl;
         }
     
// if-else statement line 7
  lineSevenFormula = lineSevenFunction(lineSixFormula, LINE_7_MULTIPLIER);
  
      if (lineSixFormula >= LINE_7_LIMIT || retirementPlan == 'N'){
         cout << cout << "7. Multiply line 6 by 4%:" << setw(34) << LINE_7_CREDIT;
         cout << endl << endl;
         }
         
                             
// assignment statement and call to function passing values lineSixFormula and
// LINE_7_MULTIPLIER    
        // lineSevenFormula = lineSevenFunction(lineSixFormula, LINE_7_MULTIPLIER);
     
         if (lineSixFormula < LINE_7_LIMIT && lineSevenFormula >= LINE_7_BENIFIT){ 
            cout << "7. Multiply line 6 by 4%:" << setw(34) << lineSevenFormula;
            cout << endl << endl;
            }
         else
         if (lineSixFormula < LINE_7_LIMIT && lineSevenFormula < LINE_7_BENIFIT ){                           
            cout << "7. Multiply line 6 by 4%:" << setw(34) << LINE_7_BENIFIT;
            cout << endl << endl;
            }
         
  cout << "8. Wage income (1040, line 7):" << setw(24) << wageIncome << endl;
  cout << endl;
  cout << "9. IRA contributions:" << setw(33) << iraContrabutions << endl;
  cout << endl;
  cout << "-------------------------------------------------------------------";
  cout << endl;

// if-else statement to determine deductible amount
   
      if (LINE_7_BENIFIT <= LINE_7_CREDIT || lineSevenFormula || wageIncome || iraContrabutions){
         cout << "10. Deductible amount:" << setw(32) << LINE_7_BENIFIT << endl;
         }
      else
      if (lineSevenFormula > LINE_7_BENIFIT){
         cout << "10. Deductible amount:" << setw(32) << lineSevenFormula << endl;
         }  
  cout << endl << endl;         
  cout << "***Enter amount from worksheet line 10 on form 1040 line 32" << endl;
  
  
    cout << endl << endl;     
    system ("PAUSE");

    return 0;
}
