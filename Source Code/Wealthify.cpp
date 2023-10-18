 /*
 Wealthify: The Smart Budget Tracker
    By,
    Rujul Krishna (23070122511)
    Mahesh Kharote (23070122517)
    Vanisha Agrawal (22070122245)
*/

#include <iostream>
#include <cstring>
using namespace std;

class Wealthify // CLASS USED // Main class of the app
{
    private:
        int balance;
        long long int d_val[500]; // Verification variable for storing specific date info
        float day_val[500] = {0}; // Storing per day value
        int d_i = 0;  // Day counter
        int user_type; // User type: 0 for Normal Tier user, 1 for Pro Tier user, 2 for Exclusive Tier user
        //int menu_temp;
        string user_n[2]; // User name, 0 to store the actual one and 1 to store the user input trying to login
        string user_p[2]; // User pass, 0 to store the actual one and 1 to store the user input trying to login
        int y, m, d;
        int today_spent = 0;
        int kitty = 0;

        class category // NESTED CLASS USED // Categories of types of payment
        {
            public:
                int food[500] = {0};
                int gadgets[500] = {0};
                int wardrobe[500] = {0};
                int appliances[500] = {0};
                int other[500] = {0};
                int g, w, a, o;
                int f = g = w = a = o = 0; // Counter
        };

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
            
            balance = 10000;
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
            d_i++; // Incrementing the unique value counter
            today_spent = 0; // Resets today's money spents
            kitty = 0;

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

        string lower(string lwr) // Turns a string, uppercase into lowercase and if lower case then ignores
        {
            for(int i=0;lwr[i]!='\0';i++)
            {
                if ((lwr[i] >= 'A') && (lwr[i] <= 'Z'))
                {  
                    lwr[i] += 32;    
                }
            }

            return lwr;
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

            d_val[d_i] = (d + m + y) + (d * m * y); // To get a unique value for each dates

            /*date_up();

            cout << "You may start entering details for the date " << d << "-" << m << "-" << y << endl << endl;*/

            string op;

            do
            {
                cout << "You may start entering details for the date " << d << "-" << m << "-" << y << endl << endl;
                cout << "MAIN MENU" << endl << endl;
                cout << "Type \"info\" to get information on how to use the app" << endl;
                cout << "Type here: ";
                cin >> op;
                op = lower(op); // Can accept any input doesn't care about case
                cout << endl;

                if (op == "info")
                {
                    cout << "Type \"Balance\" to to show your balance" << endl;
                    cout << "Type \"Today\" to know today's amount of money spent" << endl;
                    cout << "Type \"Add\" to add money spent on something" << endl;
                    cout << "Type \"Next\" to change the current date to tomorrow" << endl;
                    cout << "Type \"Exit\" to exit the app" << endl << endl;
                }
                else if (op == "add")
                {
                    add_bal();
                }    
                else if (op == "balance")
                {
                    cout << "BALANCE FEATURE SELECTED. PERFORMING ACTION BELOW" << endl << endl;
                    show();
                }
                else if (op == "today")
                {
                    today();
                }
                else if (op == "next")
                {
                    date_up();
                }
            } while (op != "exit"); // Forcing to lower case so it ain't case sensitive
            

        
        }

        // Testing FUCNTION OVERLOADING
        int sum(int a, int b) // FUNCTION OVERLOADING with 2 parameters // Function for sum
        {
            return a - b;
        }        
        int sum(int a, int b, int c) // FUNCTION OVERLOADING with 3 parameters // Function for sum
        {
            return a - b - c;
        }
        int sum(int a, int b, int c, int d) // FUNCTION OVERLOADING with 4 parameters // Function for sum
        {
            return a - b - c - d;
        }
        int sum(int a, int b, int c, int d, int e) // FUNCTION OVERLOADING with 5 parameters // Function for sum
        {
            return a - b - c - d - e;
        }
        int sum(int a, int b, int c, int d, int e, int f) // FUNCTION OVERLOADING with 6 parameters // Function for sum
        {
            return a - b - c - d - e - f;
        }

        void today()
        {
            cout << "The current amount of money you have is " << kitty << " Rupees" << endl << endl;
        }

        void add_bal() // Function to add to balance
        {
            kitty = 0;
            int tmp; // Temporarily store the value
            string s_tmp; // Option string
            int d_tmp; // Digit temporary variable
            int v_sum[5]; // Temp Variable for sum
            int cat; // To add to category

            cout << "What did you spend the money on?" << endl; // Bal menu 1
            cout << "Type from the following categories" << endl;
            cout << "Food" << endl;
            cout << "Gadgets" << endl;
            cout << "Wardrobe" << endl;
            cout << "Appliances" << endl;
            cout << "Other" << endl;
            cout << "Enter here: ";
            cin >> s_tmp;
            s_tmp = lower(s_tmp);
            cout << endl;

            cout << "How many different kinds of " << s_tmp << " did you buy?" << endl; // Bal menu 2
            cout << "Enter a number (maximum of 5): ";
            cin >> d_tmp;
            cout << endl;

            for (int i = 0; i < d_tmp; i++) // Storing all the item values within the variable
            {
                cout << "Enter the price of " << s_tmp << " number " << i + 1 << ": ";
                cin >> v_sum[i]; 
            }
            cout << endl;

            switch(d_tmp) // Selecting which function overload to pick
            {
                case 1:
                    kitty = v_sum[0];
                    tmp = sum(balance, v_sum[0]);
                    break;
                case 2:
                    kitty = v_sum[0] + v_sum[1];
                    tmp = sum(balance, v_sum[0], v_sum[1]);
                    break;
                case 3:
                    kitty = v_sum[0] + v_sum[1] + v_sum[2];
                    tmp = sum(balance, v_sum[0], v_sum[1], v_sum[2]);
                    break;
                case 4:
                    kitty = v_sum[0] + v_sum[1] + v_sum[2] + v_sum[3];
                    tmp = sum(balance, v_sum[0], v_sum[1], v_sum[2], v_sum[3]);
                    break;
                case 5:
                    kitty =  v_sum[0] + v_sum[1] + v_sum[2] + v_sum[3] + v_sum[4];
                    tmp = sum(balance, v_sum[0], v_sum[1], v_sum[2], v_sum[3], v_sum[4]);
                    break;
            }

            //cat = tmp + balance;
            balance = tmp; // Updates balance
            today_spent = cat;
            category A; // Object for nested class created

            day_val[d_i]++; // Updating the value of today's spent money

            if (s_tmp == "food") // Assigning value within the nested class array
            {
                A.food[A.f] += cat;
                A.f++;
            }
            else if (s_tmp == "gadgets")
            {
                A.gadgets[A.g] += cat;
                A.g++;
            }
            else if (s_tmp == "wardrobe")
            {
                A.wardrobe[A.w] += cat;
                A.w++;
            }
            else if (s_tmp == "appliances")
            {
                A.appliances[A.a] += cat;
                A.a++;
            }
            else
            {
                A.other[A.o] += cat;
                A.o++;
            }
        }

        void dis_bal()
        {
            cout << "Here is your balance in your account: " << balance << endl << endl;
        }
};

int main()
{
    int op;
    
    cout << "Welcome to the Main ADMIN Menu of WEALTHIFY" << endl << endl;
    cout << "A Project By: Rujul Krishna - 23070122511, Mahesh Kharote - 23070122517, Vanisha Agrawal - 22070122245" << endl;
    cout << "Project led by the AMAZING Leader, Rujul" << endl << endl;
    cout << "Options:" << endl;
    cout << "1. Normal User Account Creation" << endl;
    cout << "2. Pro User Account Creation" << endl;
    cout << "3. Exclusive User Account Creation" << endl;
    cout << "Pick the account you wish to give to the user (Enter the option number): ";
    cin >> op;
    cout << endl << endl;

    do
    {
        if (op == 1)
        {
            Wealthify x; // Default balance of 10000
            x.start_app();
            break;
            }
        else if (op == 2)
        {
            Wealthify x(50000);
            x.start_app();
            break;
        }
        else if (op == 3)
        {
            Wealthify x(100000, 2); // Object created and variables invoked using parameterized constructor; 
            x.start_app();
            break;
        }
    }   while (op !=  0);

    /*Wealthify x(6000, 2);

    x.start_app();*/

    return 0;
}