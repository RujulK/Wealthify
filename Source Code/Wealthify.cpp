 /*
 Wealthify: The Smart Budget Tracker
    By,
    Rujul Krishna (23070122511)
    Mahesh Kharote (23070122517)
*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct category // STRUCT USED // Categories of types of payment
{
    string food;
    string gadgets;
    string wardrobe;
    string appliances;
};

class Wealthify // CLASS USED // Main class of the app
{
    private:
        int balance;
        int value[50][12][31]; // Array with 50 Years worth of data thaat can be stored, and then 12 months and 31 days
        int user_type; // User type: 0 for Normal Tier user, 1 for Pro Tier user, 2 for Exclusive Tier user
        int menu_temp;
        string user_n[2]; // User name, 0 to store the actual one and 1 to store the user input trying to login
        string user_p[2]; // User pass, 0 to store the actual one and 1 to store the user input trying to login
        int y, m, d;

    public:
        void acc_create() // Account creation function added
        {
            cout << "Enter the User Name you would like to have: "; // Take user name from the user
            cin >> user_n[0];
            cout << endl;
            cout << "Enter the Password you would like to have: "; // Take password from the user
            cin >> user_p[0];
            cout << endl;
        }

        Wealthify(void) // DEFAULT CONSTRUCTOR USED // for 0 balance user account creation, and default Normal tier account
        {
            cout << "Normal Tier User Account has been created" << endl << endl;
            
            acc_create();
            
            balance = 0;
            user_type = 0;
        }

        Wealthify(int a) // SINGLE VARIABLE PARAMETERIZED CONSTRUCTOR // for custom balance account creation and default Normal tier account
        {
            cout << "Normal Tier User Account has been created" << endl << endl;

            acc_create();
            
            balance = a;
            user_type = 0;
        }

        Wealthify(int a, int b) // TWO VARIABLE PARAMETERIZED CONSTRUCTOR // a variable for user Balance, b variable for user tier
        {
            switch(b)
            {
                case 0:
                    cout << "Normal Tier User Account has been created" << endl << endl;
                    break;
                case 1:
                    cout << "Pro Tier User Account has been created" << endl << endl;
                    break;
                case 2:
                    cout << "Exclusive Tier User Account has been created" << endl << endl;
                    break;
                default:
                    cout << "Invalid user creation option" << endl << endl;
            }

            acc_create();

            balance = a;
            user_type = b;
        }

        void show()
        {
            cout << "The current amount of money you have is " << balance << " Rupees" << endl << endl;
        }

        void date_up() // INNOVATIVE FEATURE?? HEHE PLS GIVE MARKS :D // Function to update the months and year and reset the day
        {
            d++; // Incrementing the day by one

            int m_max = 31;  // Max days in a month

            if (m == 4 || m == 6 || m == 9 || m == 11) // For Months that only has 30 days
            {
                m_max = 30;
            } 
            else if (m == 2) // For February month 
            {
                if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))  // 29 Days if a Leap year
                {
                    m_max = 29;
                } 
                else // 28 Days in Feb for a non Leap year
                {
                    m_max = 28;
                }
            }

            if (d > m_max) // When the days get past newly defined max month value, increment the month
            {
                d = 1;
                m++;
                
                if (m > 12) // When the month crosses 12, reset and increment the year
                {
                    m = 1;
                    y++;
                }
            }
        }

        void start_app()
        {
            do
            {
                cout << "Enter the User Name: "; // Take user name from the user
                cin >> user_n[1];
                cout << endl;
                cout << "Enter the Password: "; // Take password from the user
                cin >> user_p[1];
                cout << endl;
                if (((user_n[0] == user_n[1]) && (user_p[0] == user_p[1])) == 0) // Give error output message
                {
                    cout << "Incorrect username or password" << endl;
                    cout << "Please try again" << endl << endl;
                }

            } while (((user_n[0] == user_n[1]) && (user_p[0] == user_p[1])) == 0); // Keeps looping until the correct credentials are entered
            
            cout << "Username and Password CORRECT" << endl << endl;

            cout << "Welcome to WEALTHIFY: The Smart Budget Tracker" << endl << endl;

            cout << "App initialization started.. Enter the following details: " << endl << endl; // Getting date info
            cout << "Enter the Year: ";
            cin >> y;
            cout << endl;
            cout << "Enter the Month: ";
            cin >> m;
            cout << endl;
            cout << "Enter the Day: ";
            cin >> d;
            cout << endl;

            cout << "You may start entering details for the date " << d << "-" << m << "-" << y << endl << endl;

            /*date_up();

            cout << "You may start entering details for the date " << d << "-" << m << "-" << y << endl << endl;*/

        
        }

        void get_amt()
        {

        }
};

int main()
{
    Wealthify x(60, 2); // Object created and variables invoked using parameterized constructor; 
    x.show();
    x.start_app();
    return 0;
}