#include <iostream>
#include <random>

using namespace std;

int randomInt(mt19937 &gen, int a, int b); //Function that returns a random integer in the inclusive range [a, b], using a Mersenne Twister 
void genOemKey(mt19937 &gen); //Function that returns a OEM key
void genRetailKey(mt19937 &gen); //Function that returns a retail key
void clearConsole(); //function to clear the console on Linux/Windows

int main()
{
    random_device seed; //seed for random numbers
    mt19937 gen(seed());

    do 
    {
        int choose; 
        cout << "0-Exit" << endl;
        cout << "1-gen OEM key" << endl;
        cout << "2-gen retail key" << endl;

        cout << ">";
        try //input validation
        {
            cin >> choose; 
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    throw invalid_argument("not valid input!");
                }
        }
        catch (const exception& e)
        {
            cerr << "Error: not valid input! " << endl;
            continue;
        }

        switch(choose)
        {
            case 0:
            {
                clearConsole();
                cout << "Thank you for using win95 Key Gen (^-^)";
                return 0;
            }

            case 1:
            {
                clearConsole();
                cout << endl;
                cout << "This is the OEM key: ";
                genOemKey(gen);
                break;
            }

            case 2:
            {
                clearConsole();
                cout << endl;
                cout << "This is the retail key (A key):";
                genRetailKey(gen);
                break;
            }

            default: // Handles any invalid character entered by the user
            {
                cerr << "Invalid character! (╥﹏╥)"; 
                break;
            }
        }

    }while(true);
}

int randomInt(mt19937 &gen, int a, int b)
{
    return uniform_int_distribution<int>(a, b)(gen);
}

void genOemKey(mt19937 &gen)
{
    int numericalProductKey[16] = {}; //array that contains the numeric part of the OEM key
    const string OEM = "-OEM-";

    numericalProductKey[0] = randomInt(gen, 0, 3); //from line 87 to 93 it prints the part of the OEM key that indicates the days (from 001 to 366)
    cout << numericalProductKey[0];

    numericalProductKey[1] = randomInt(gen, 0, 6);
    cout << numericalProductKey[1];

    numericalProductKey[2] = randomInt(gen, 1, 6);
    cout << numericalProductKey[2];

    numericalProductKey[3] = randomInt(gen, 95, 99);  //prints the part of the OEM key that indicates the years (from 001 to 366)
    cout << numericalProductKey[3];
    cout << OEM;

    numericalProductKey[4] = 0; //from line 100 to 102 it prints the constant part of the OEM key imposted to 0
    numericalProductKey[5] = 0;
    cout << numericalProductKey[4] << numericalProductKey[5];

    int partialSum = 0; //the partial sum to calculate this part of the OEM key, the sum of the numbers must be divisible by 7
    for(int i = 6; i <= 9; i++)
    {
        numericalProductKey[i] = randomInt(gen, 0, 9);
        partialSum += numericalProductKey[i];
        cout << numericalProductKey[i];
    }

    int remainder = partialSum % 7; //corrects the number by adding 0 as the last digit if the carry of the partial sum is equal to 0
    if (remainder == 0) 
    {
        numericalProductKey[10] = 0;
    } 
    else 
    {
        numericalProductKey[10] = 7 - remainder; //corrects the number by adding as the last digit the difference between 7 and remainder  
    }
    cout << numericalProductKey[10];

    cout << "-";

    for(int i = 11; i <= 15; i++)
    {
        numericalProductKey[i] = randomInt(gen, 0, 9);
        cout << numericalProductKey[i];
    }

    cout << endl << endl;
}

void genRetailKey(mt19937 &gen)
{
    int retailKey[10] = {}; //array that contains the numeric part of the retail key

    for(int i = 0; i <= 2; i++) //generate 3 random numbers ensuring that all 3 are never the same
    {
        if(i == 2)
        {
            do
            {
                retailKey[i] = randomInt(gen, 0, 9);
            } while(retailKey[i] == retailKey[0]);

            cout << retailKey[i];
        }
        else
        {
            retailKey[i] = randomInt(gen, 0, 9);
            cout << retailKey[i];
        }
    }

    cout << "-";

    int partialSum_2 = 0;
    for(int i = 3; i <= 8; i++) //generate 7 random numbers so that their sum is divisible by 7
    {
        retailKey[i] = randomInt(gen, 0, 9);
        partialSum_2 += retailKey[i];
        cout << retailKey[i];
    }

    int remainder_2 = partialSum_2 % 7;
    if (remainder_2 == 0)
    {
        retailKey[9] = 0;
    }
    else
    {
        retailKey[9] = 7 - remainder_2;
    }

    cout << retailKey[9];

    cout << endl << endl;
}


void clearConsole() //If the operating system is Windows, it executes the CLS command to clear the terminal; otherwise, it executes the clear command
{
    #ifdef _WIN32 
        system("CLS");
    #else
        system("clear");
    #endif
}