/* -----------------------------------------------------------------------------
* Author: Sean Collins
* Class:  CS361 Control Structures
* Assignment: Week 4, Program 2
* Date: February 2, 2011
* Program Description: Program to display month entered
*   Input: letters of the month
*   Processing:  Determine month based on letter(s) entered by user
*   Output: Display month
*
*     Additional Comments:
*    Write a program to identify a month entered.
*    First prompt the user for one letter (character) to identify the month. 
*      Then use one large nested switch statement to output one of the 
*      following messages:
*
*       If the letter is 'F' or 'f', output: The month is February
*       If the letter is 'S' or 's', output: The month is September.
*       If the letter is 'O' or 'o', output: The month is October.
*       If the letter is 'N' or 'n', output: The month is November.
*       If the letter is 'D' or 'd', output: The month is December.
*       If the letter is ‘A’ or ‘a’, prompt for the second letter:
*       If the second letter is ‘P’ or ‘p’, output: The month is April.
*       If the second letter is ‘U’ or ‘u’, output: The month is August.
*       If the letter is 'J' or 'j', prompt for the user for a second letter.
*       If the second letter is ‘A’ or ‘a’, output: The month is January
*       If the second letter is ‘U’ or ‘u’, prompt for the third letter:
*       If the third letter is ‘L’ or ‘l’, then output July
*       If the third letter is ‘N’, or ‘n’, then output June
*       If the letter is ‘M’ or ‘m’, prompt for the next two letters at once 
*       (note that you can still read them into two separate character variables).  
*       Be sure to verify the correctness of BOTH the second and third letters 
*      (not just the third letter!)
*       If the third letter is ‘R’ or ‘r’, output: The month is March
*       If the third letter is ‘Y’ or ‘y’, output: The month is May
*       If none of the above situations apply, output: Unknown Month.
*       The program should always produce an output message.  Therefore, you need to
*       insure that ALL possible input combinations produce output of  either a correct
*       month, or the "Unknown Month" message.
*    
* -----------------------------------------------------------------------------
*/

// pre processing directives

#include <iostream>             // for I/O
#include <iomanip>              // for formatting output
#include <cctype>               // classify and transform individual characters


using namespace std;

int main()
{

//local variables

  char month;
  char letterOne;     // variable to determine if month is April or August
  char letterTwo;     // variable to determine if month is January
  char letterThree;   // variable to determine if month is June or July
  char letterFour;    // variable to determine if month is March or May
  char letterFive;    // variable to determine if month is March or may


// begin input from user


  cout << "Please enter the month: ";
  cout << endl;
  cout << endl;
  cout << "J - January, June, July" << endl;
  cout << "F - February" << endl;
  cout << "M - March, May" << endl;
  cout << "A - April, August" << endl;
  cout << "S - September" << endl;
  cout << "O - October" << endl;
  cout << "N - November" << endl;
  cout << "D - December" << endl;
  cout << endl;

  cin >> month;
  cout << endl;
  cout << endl;

    switch (month){ // switch to display month based on conditional data

       case 'F': 
       case 'f':
            cout << "The month is February" << endl;
            break;     
       case 'S':    
       case 's':
            cout << "The month is September" << endl;
            break;
       case 'O':    
       case 'o':
            cout << "The month is October" << endl;
            break;    
       case 'N':
       case 'n':
            cout << "The month is November" << endl;
            break;
       case 'D':     
       case 'd':
            cout << "The month is December" << endl;
            break;   
       case 'A':
       case 'a':
            cout << "Please enter the next letter in the name of the month: ";
            cout << endl;
            cout << "'a' for April 'u' for August: " << endl;
            cin >> letterOne;
            cout << endl;
       // inner switch used to determine if month is August or April
       
            switch (letterOne){            
               case 'P':
               case 'p':
                  cout << "The month is April" << endl;
                  break;
               case 'U':
               case 'u':
                  cout << "The month is August" << endl;
                  break;
            default:
            cout << "Error - no such month!" << endl;
          cout << "Please enter a letter from the choices above" << endl;
            
       }       
       break;
       
       case 'J':
       case 'j':
            cout << "Please enter the next letter in the name of the month: ";
            cout << endl;
            cout << " 'a' for january 'u' for June or July: " << endl;
            cin >> letterTwo;
            cout << endl;
        
        // inner switch used to determine if month is January
        
            switch (letterTwo){
               
               case 'A':
               case 'a':
                     cout << "The month is January" << endl;
                     break;
   
               case 'U':       
               case 'u':
                     cout << "Please enter the next letter" << endl;
                     cout << "'n' for June 'l' for July: " << endl;
                     cin >> letterThree;
                     cout << endl; 
                
                 
                 // inner switch used to determine if month is June or July
                 
                    switch (letterThree){
                       case 'N':
                       case 'n':
                             cout << "The month is June" << endl;
                             break;
                     
                       case 'L':
                       case 'l':
                             cout << "The month is July" << endl;
                             break;
                     
                     default:
            
                          cout << "Error - no such month!" << endl;
	                      cout << "Please enter a letter from the choices above" << endl;
                     }
                     break;
             }
         break;
         
        case 'M':         
        case 'm':
              cout << "Please enter the next two letters in the name of the month: ";
              cout << endl;
              cout << "'ar' for March or 'ay' for May: ";
              cin >> letterFour >> letterFive;
              cout << endl;
 // inner switch used to determine if month is March or May 
        
              switch (letterFour)
              {
                 case 'A':
                 case 'a':
                      switch(letterFive)
                      {   
                         case 'R':
                         case 'r':
                              cout << "The month is March" << endl;
                              break;
         
                         case 'Y':
                         case 'y':
                              cout << "The month is May" << endl;
                              break;
                         default:
                              cout << "Error - no such month!" << endl;
	                          cout << "Please enter a letter from the choices above" << endl;
                      }
                      break;
                                            
                 default:
                      cout << "Error - no such month!" << endl;
	                  cout << "Please enter a letter from the choices above" << endl;
              }
              break;
        default:
             cout << "Error - no such month!" << endl;
             cout << "Please enter a letter from the choices above" << endl;
 
}  // end switch

    cout << endl << endl;
    system ("PAUSE");

    return 0;
}
