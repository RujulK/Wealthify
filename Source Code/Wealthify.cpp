 /*
 Wealthify: The Smart Budget Tracker
    By,
    Rujul Krishna (23070122511)
    Mahesh Kharote (23070122517)
*/
// ok
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

typedef struct category // STRUCT USED // Categories of types of payment
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
            } while (user_n[0] != user_n[1]);
            
            cout << "Entered" << endl;
        }

        
};

int main()
{
    Wealthify x(60, 2); // Object created and variables invoked using parameterized constructor; 
    x.show();
    x.start_app();
    return 0;
}