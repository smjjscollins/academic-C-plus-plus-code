/* -----------------------------------------------------------------------------
* Author: Sean Collins
* Class:  CS361 Control Structures
* Assignment: Week 8, Program 1
* Date: February 28, 2011
* Program Description: The program will read the current date (month and year)
* from the user. Then in a loop, it will read a subscriber's name, a 
* subscription start month and year, and the number of years subscribed.
* Using this information, it will output a subscription status for each
* subscriber. The program will loop, processing subscribers, until the user 
* chooses to exit.
*
* Processing:  Determine month based on letter(s) entered by user and then 
* determine the subcription start month based on date, number of years subscribed
* 
* Output: Display the subscription status, start date and end date
* -----------------------------------------------------------------------------
*/

// pre processing directives

#include <iostream>             // for I/O
#include <iomanip>              // for formatting output
#include <cctype>               // classify and transform individual characters
#include <cmath> 
#include <cstring>


using namespace std;

/* -----------------------------------------------------------------------------
* global constants
*-------------------------------------------------------------------------------
*/

  const int JAN = 1;
  const int FEB = 2;
  const int MAR = 3;
  const int APR = 4;
  const int MAY = 5;
  const int JUN = 6;
  const int JUL = 7;
  const int AUG = 8;
  const int SEP = 9;
  const int OCT = 10;
  const int NOV = 11;
  const int DEC = 12;
  const int LOW_YEAR_LIMIT = 2011;
  const int HIGH_YEAR_LIMIT = 2016;
  const int START_YEAR_LIMIT = 2005;
  const int SUBSCRIPTION_START_LIMIT = 1;
  const int SUBSCRIPTION_START_BOUNDARY = 5;
  const int ONE_YEAR = 12;
  
/*------------------------------------------------------------------------------
* function prototypes
*-------------------------------------------------------------------------------
*/
  void programHeader();
  int getMonth();          
  int getYear(string prompt);
  string getName(string prompt);
  int subscriptionLength(int& start_year, int& subscribe_years);
  void subscriberInput(int& month, int& low_year, string& first_name, string& last_name, int& length);
  string monthName(int month);
  void subscriptionInfo (string name, int year, string lname, string fname, 
  int start_year, int subscribe_years, int length, int month);
  
  
int main()
{

/*------------------------------------------------------------------------------
* local variables
*-------------------------------------------------------------------------------
*/
  int low_year;
  int high_year;
  int month;
  string first_name;
  string last_name;
  int subscribe;
  string name_of_month;
  int length;
  int start_year;
  int subscribe_years;
/*------------------------------------------------------------------------------
* begin call to functions
*-------------------------------------------------------------------------------
*/  
  
  subscriberInput(month, low_year, first_name, last_name, length);
  name_of_month = monthName(month);
  length = subscriptionLength(start_year, subscribe_years);
  subscriptionInfo(name_of_month, low_year, last_name, first_name, start_year,
  subscribe_years, length, month);
  
  
    cout << endl << endl;
    system ("PAUSE");

    return 0;
}

/*------------------------------------------------------------------------------
* Function Description: 
* Function GetMonth, will read and error check the month. GetMonth will have one
* input parameter – the year. The GetMonth function will prompt for the month 
* and error check that the month entered is between 1 and 12.  If the year is 
* 1900, it will also error check that the month is not Jan or Feb, since only 
* months from March and beyond will work.  
* The function will loop until a valid month is entered.  Once a valid month is 
* entered, it will be returned to main.
*-------------------------------------------------------------------------------
*/


void programHeader(){
  
  cout << "Subscription Evaluation Program" << endl;
  cout << endl << endl;
}

int getMonth(){
  
  char month;
  char letterOne;     // variable to determine if month is April or August
  char letterTwo;     // variable to determine if month is January
  char letterThree;   // variable to determine if month is June or July
  char letterFour;    // variable to determine if month is March or May
  char letterFive;    // variable to determine if month is March or may
  int num1;

// begin input from user


  cout << "Please enter the first letter of the subscription start month: ";
  cin >> month;
  cout << endl;
  cout << endl;
  
  
    switch (month){ // switch to display month based on conditional data

       case 'F': 
       case 'f':
            num1 = FEB;
            break;     
       case 'S':    
       case 's':
            num1 = SEP;
            break;
       case 'O':    
       case 'o':
            num1 = OCT;
            break;    
       case 'N':
       case 'n':
            num1 = NOV;
            break;
       case 'D':     
       case 'd':
            num1 = DEC;
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
                  num1 = APR;
                  break;
               case 'U':
               case 'u':
                  num1 = AUG;
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
                     num1 = JAN;
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
                             num1 = JUN;
                             break;
                     
                       case 'L':
                       case 'l':
                             num1 = JUL;
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
        
              switch (letterFour, letterFive){
                 case 'A':
                 case 'a':
                 case 'R':
                 case 'r':
                       num1 = MAR;
                       break;
         
                 case 'Y':
                 case 'y':
                      num1 = MAY;
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

  return num1;
}


/*------------------------------------------------------------------------------
* Function Description: 
* Function GetYear will be passed a string prompt from function subscriptionLength()
* and request the user input the start year and number of years subscribed. The
* vlalues will then be passed back to the calling function. 
*-------------------------------------------------------------------------------
*/
int getYear(string prompt)
{
  int num;            // user input number
  
  do {
      cout << endl << prompt;
      cin >> num;
    
  } while (num < LOW_YEAR_LIMIT || num > HIGH_YEAR_LIMIT); 

  return num;
}

/*------------------------------------------------------------------------------
* Function Description: 
* Function GetName will be passed a string prompt from function subscriberInput()
* and read the users first and last name and then pass the strings back to the 
* calling funtion.
*-------------------------------------------------------------------------------
*/

string getName(string prompt)
{
  string name;            // user input name

      cout << endl << prompt;
      //cin >> name;
      cin.ignore();
      getline (cin, name);
      
  

  return name;
}

/*------------------------------------------------------------------------------
* Function Description: 
* Function subscriptionLength will determine the length of time the subscriber is
* subscribed to the magazine based on the start year and number of years subscribed.
*-------------------------------------------------------------------------------
*/

int subscriptionLength(int& start_year, int& subscribe_years){
  
 
  int length;
   
  cout << endl;
  cout << "Enter subscription start year: ";
  cin >> start_year;
  cout << endl;
  
       if (start_year <= START_YEAR_LIMIT || start_year > LOW_YEAR_LIMIT){
          cout << "The start year can not be before 2006. " << endl;
          cout << endl;
          cout << "Please enter a valid start year: ";
          cin >> start_year;
          cout << endl;
          }
   
  cout << "Enter number of years subscribed: "; 
  cin >> subscribe_years;
  cout << endl;
  cout << endl << endl;
  
       if (subscribe_years < SUBSCRIPTION_START_LIMIT || subscribe_years > SUBSCRIPTION_START_BOUNDARY){
          cout << "The number of year subscribed must be between ";
          cout << SUBSCRIPTION_START_LIMIT << endl;
          cout << " and " << SUBSCRIPTION_START_BOUNDARY << " years. ";
          cout << "Please enter a valid length: ";
          cin >> subscribe_years;
          cout << endl;
          cout << endl << endl;
          }
  
  length = start_year + subscribe_years;
  
  return length;  
}   

/*------------------------------------------------------------------------------
* Function Description: 
* Function subscriberInput will used call functions programHeader, getMonth,
* getYear, getName, and subscriptionLength to gather information from the user 
* and then return values via reference back to main().
*-------------------------------------------------------------------------------
*/

void subscriberInput(int& month, int& low_year, string& first_name, string& last_name,
int& length){
  
  int start_year;
  int subscribe_years;
  
  programHeader();
  month = getMonth();
  low_year = getYear("Enter current year (4 digits): ");
  first_name = getName("Please enter your first name: ");
  last_name = getName("Please enter your last name: ");
  

}

/*------------------------------------------------------------------------------
* Function Description: 
* Function monthName will have the integer of the month slected passed in via 
* value parameter and then an if..else statemnt will be used to determine that 
* string name of the month which is passed back to main()
*-------------------------------------------------------------------------------
*/

string monthName(int month){
  
  string name;
  
  if (month == JAN)
     name = "January";
  else if (month == FEB)
     name = "February";
  else if (month == MAR)
     name = "March";
  else if (month == APR)
     name = "April";
  else if (month == MAY)
     name = "May";
  else if (month == JUN)
     name = "June";
  else if (month == JUL)
     name = "July";
  else if (month == AUG)
     name = "August";
  else if (month == SEP)
     name = "September";
  else if (month == OCT)
     name = "October";
  else if (month == NOV)
     name = "November";
  else if (month == DEC)
     name = "December";
  
  return name;     
}

/*------------------------------------------------------------------------------
* Function Description: 
* Function subscriptionInfo will use values passed from main() to display the 
* values and calucualted results for current date, last name , first name, 
* subscription start date, status, and experiration date. Then the program will 
* as the user if they would like to process additional subscriptions.
*-------------------------------------------------------------------------------
*/

void subscriptionInfo (string name, int year, string lname, string fname,
int start_year, int subscribe_years, int length, int month){
  
  char answer;
  int monthsLeft;
  string accountStatus;
  string current = "Current";
  int expires;
  string expirationDate;
  
  expires = month - 1;
  expirationDate = monthName(expires);
  cout << "Current Date: " << setw(15)<< name << "  " << year << endl;
  cout << "Subscriber: " << setw(16) << lname << " , " << fname << endl;
  cout << endl << endl;
  cout << "Start Date: " << setw(17) << name <<  "  " << start_year << endl;
  cout << "Expiration Date: " << setw(12) <<  expirationDate <<  "  " << length;
  cout << endl;
  cout << endl << endl;
  
  monthsLeft = ((ONE_YEAR - (expires)) + ((length - start_year) * ONE_YEAR));
  
         if (month == expires || month - 1 == expires && length == year){
            cout << "Account Status:      Subscription expires within a month" << endl;
            cout << setw(54) << "Please call to RENEW subscription" << endl;
            cout << endl << endl;
            }
         else if (month > expires && length == year){
            cout << " Account Status:     Expiration date has passed" << endl;
            cout << setw(54) << "Your subscription has been CANCELLED" << endl;
            cout << endl << endl;
            }
         else{ 
            cout << "Account Status: " << setw(12) << current << endl; 
            cout << setw(23) << monthsLeft << " months remaining on subscription" << endl;
            cout << endl << endl;
            }
         
  cout << "Process another subscription (y/n)?: ";
  cin >> answer;
  cout << endl;
  
  answer = toupper(answer);
  
         if (answer == 'Y'){
            programHeader();
            fname = getName("Please enter your first name: ");
            lname = getName("Please enter your last name: ");
            length = subscriptionLength(start_year, subscribe_years);
            subscriptionInfo (name, year, lname, fname,
            start_year, subscribe_years, length, month);
            }
         else 
  
  return;
  
}
