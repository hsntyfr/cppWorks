#include <iostream>
#include <ctime>
using namespace std;

class Account
{
    public:
    int AccountId;
    bool Private;
    float Balance;
    float Currency;
    time_t DateCreated;

    Account()
    {
        AccountId = 0;
        Private = false;
        Balance = 0;
        Currency = 1;
        DateCreated = time(0);
    }

    Account(int AccountId, bool Private, float Balance)
    {
        AccountId = AccountId;
        Private = Private;
        Balance = Balance;
        DateCreated = time(0);
    }

    void Buy(float money, int account)
    {
        //This if statement for checking account exist or not
        if (AccountId == 0)
        {
            cout << "Account does not exist" << endl;
            return;
        }

        float BTC = money / Currency;
        Balance += BTC;
        cout << "Bought " << BTC << " BTC" << endl;
    }

    void Sell(float BTC, int account)
    {
        //This if statement for checking account exist or not
        if (AccountId == 0)
        {
            cout << "Account does not exist" << endl;
            return;
        }

        //This if statement for checking account has enough BTC or not
        if (Balance >= BTC)
        {
            float TL = BTC * Currency;
            Balance -= BTC;
            cout << "Sold " << BTC << " BTC = " << TL << " TL" << endl;
        }
        else
        {
            cout << "Not enough BTC" << endl;
        }

    }

    void balance()
    {
        cout << "Account ID: " << AccountId;
        cout << " | Balance(BTC): " << Balance;
    }

    void Profit()
    {
        float profit = 0;
        profit = Currency * Balance;

        //This if statement for checking profit is positive or not
        if (profit - Balance < 0)
        {
            cout << " | Profit: " << 0 << endl;
        }
        else
        {
            cout << " | Profit: " << profit - Balance << endl;
        }

    }
};

time_t ChangeDate(int day, int month, int year);
int CalcDay(time_t Date);
float CalcCurrencyPrivate(int day);
float CalcCurrencyPublic(int day);

int main()
{
    srand(time(0));

    int AccountId;
    float Balance;
    Account account;
    Account accounts[100];
    int day;
    int month;
    int year;
    time_t date = {};
    time_t currentTime = time(0);
    int money;

    int choice = 0;

    //This while loop for menu
    while (choice < 7)
    {
        cout << "1. Create public account" << endl;
        cout << "2. Create private account" << endl;
        cout << "3. Buy BTC" << endl;
        cout << "4. Sell BTC" << endl;
        cout << "5. Change system date" << endl;
        cout << "6. Show all" << endl;
        cout << "7. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                AccountId = 0;
                Balance = -1;

                //This while loop for checking account id is between 1 and 100 and account already exist or not
                while (AccountId < 1 || AccountId > 100 || accounts[AccountId - 1].AccountId != 0)
                {
                    cout << "Account ID(Between 1 and 100): ";
                    cin >> AccountId;

                    //This if statement for checking account already exist or not
                    if (accounts[AccountId - 1].AccountId != 0)
                    {
                        cout << "Account already exists" << endl;
                    }
                }
                //This while loop for checking balance is positive
                while (Balance < 0)
                {
                    cout << "Balance BTC: ";
                    cin >> Balance;
                }

                account.AccountId = AccountId;
                account.Private = false;
                account.Balance = Balance;
                account.DateCreated = time(0);
                accounts[AccountId - 1] = account;
                cout << "Account created" << endl;
                break;

            case 2:
                AccountId = 0;
                Balance = -1;

                //This while loop for checking account id is between 1 and 100 and account already exist or not
                while (AccountId < 1 || AccountId > 100 || accounts[AccountId - 1].AccountId != 0)
                {
                    cout << "Account ID(Between 1 and 100): ";
                    cin >> AccountId;

                    //This if statement for checking account already exist or not
                    if (accounts[AccountId - 1].AccountId != 0)
                    {
                        cout << "Account already exists" << endl;
                    }
                }

                //This while loop for checking balance is positive
                while (Balance < 0)
                {
                    cout << "Balance BTC: ";
                    cin >> Balance;
                }
                account.AccountId = AccountId;
                account.Private = true;
                account.Balance = Balance;
                account.DateCreated = time(0);
                accounts[AccountId - 1] = account;
                break;

            case 3:
                cout << "Account ID: ";
                cin >> AccountId;

                //This while loop for checking account id is between 1 and 100
                while (AccountId < 1 || AccountId > 100)
                {
                    cout << "Account ID(Between 1 and 100): ";
                    cin >> AccountId;
                }
                cout << "Money(TL): ";
                cin >> money;

                accounts[AccountId - 1].Buy(money, AccountId);
                break;

            case 4:
                cout << "Account ID: ";
                cin >> AccountId;

                //This while loop for checking account id is between 1 and 100
                while (AccountId < 1 || AccountId > 100)
                {
                    cout << "Account ID(Between 1 and 100): ";
                    cin >> AccountId;
                }
                cout << "BTC: ";
                cin >> money;

                accounts[AccountId - 1].Sell(money, AccountId);
                break;

            case 5:

                cout << "Current date: " << asctime(localtime(&currentTime)) << endl;

                //This do while loop for checking date is in the future
                do
                {
                    cout << "Day: ";
                    cin >> day;
                    cout << "Month: ";
                    cin >> month;
                    cout << "Year: ";
                    cin >> year;
                    date = ChangeDate(day, month, year);

                    //This if statement for checking date is in the future
                    if (date < time(0))
                    {
                        cout << "Date must be in the future" << endl;
                    }
                }
                while (date < time(0));

                //This for loop for calculating currency for all accounts
                for (int i = 0; i < 100; ++i)
                {
                    //This if statement for checking account exist or not
                    if (accounts[i].AccountId != 0)
                    {
                        //This if statement for checking account is private or not
                        if (accounts[i].Private == true)
                        {
                            accounts[i].Currency = CalcCurrencyPrivate(CalcDay(date));
                        }
                        else
                        {
                            accounts[i].Currency = CalcCurrencyPublic(CalcDay(date));
                        }
                    }
                }
                break;

            case 6:
                //This for loop for showing all accounts
                for (int i = 0; i < 100; ++i)
                {
                    //This if statement for checking account exist or not
                    if (accounts[i].AccountId != 0)
                    {
                        accounts[i].balance();

                        //This if statement for checking account is private or not
                        if (accounts[i].Private == true)
                        {
                            cout << " | Private";
                        }
                        else
                        {
                            cout << " | Public";
                        }
                        accounts[i].Profit();
                    }
                }
                break;
        }
    }
    return 0;
}

float CalcCurrencyPublic(int day)
{
    float currency = 1.0;

    //This for loop for calculating currency for public account
    for (int i = 1; i <= day; i++)
    {
        currency += currency * 0.01;

        //This if statement for random decrease currency for public account when day is 15
        if (i % 15 == 0)
        {
            currency -= currency * 0.05;
        }
    }
    return currency;
}
float CalcCurrencyPrivate(int day)
{
    float currency = 1;
    int iter = 1;
    int carry = 0;
    int day1;
    int day2;
    int day3;

    day1 = rand() % 30 + 1;
    day2 = rand() % 30 + 1;
    day3 = rand() % 30 + 1;

    //This while loop for calculating currency for private account
    while (iter != day)
    {
        currency += currency * 0.05;
        //This if statement for random decrease currency for private account when day is 30
        if (iter % 30 == 0)
        {
            day1 = rand() % 30 + 1;
            day2 = rand() % 30 + 1;
            day3 = rand() % 30 + 1;
            carry += 30;
        }
        //This if statement for chech decrease currency for specific days
        if (iter == day1 + carry)
        {
            currency -= currency * 0.1;
        }

        //This if statement for chech decrease currency for specific days
        if (iter == day2 + carry)
        {
            currency -= currency * 0.1;
        }

        //This if statement for chech decrease currency for specific days
        if (iter == day3 + carry)
        {
            currency -= currency * 0.1;
        }
        iter++;
    }
    return currency;
}
time_t ChangeDate(int day, int month, int year)
{
    tm currentTime = {};
    currentTime.tm_year = year - 1900;
    currentTime.tm_mon = month - 1;
    currentTime.tm_mday = day;
    time_t currentTime_t = mktime(&currentTime);
    return currentTime_t;
}
int CalcDay(time_t Date)
{
    time_t currentTime = time(0);
    time_t date = Date;
    time_t diff = date - currentTime;
    int diffDay = diff / (60 * 60 * 24);
    return diffDay;
}