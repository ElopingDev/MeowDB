#include "funcs.h"
#include "BankAccount.h"

void meowWrite(const std::string &data, const std::string &dbName, std::ofstream &meowdb)
{
    meowdb.open(dbName);
    meowdb << data;
    meowdb << "\n";
    meowdb.close();
    std::cout << "Done.\n";
}

void meowSerialize(std::ofstream& meowdb, const BankAccount& account) {
    meowdb << account.account_id << "," << account.account_name << ","  << account.balance << std::endl;
}

BankAccount meowDeserialize(std::ifstream &meowdb) {
    BankAccount account;
    meowdb >> account.account_id;
    meowdb.ignore(); // Ignore the comma
    getline(meowdb, account.account_name, ',');
    meowdb >> account.balance;
    return account;
}

void addAccount()
{
    int id;
    std::string name;
    double bal;

    std::cout << "Enter account id: ";
    std::cin >> id;
    std::cout << "Enter account name: ";
    std::cin.ignore(); // Clear any newline character left in the input buffer
    std::getline(std::cin, name); // Use getline to allow spaces in the name
    std::cout << "Enter balance: ";
    std::cin >> bal;

    //Create Struct
    BankAccount account = {id, name, bal};

    //Open File
    std::ofstream meowdb("MeowDB.meow", std::ios::app);

    //Serialize to file
    meowSerialize(meowdb, account);
    meowdb.close();
    
    std::cout << "Added account." << std::endl;
}
void removeAccount()
{
    std::cout << "Removing account." << std::endl;
}
void viewAccount()
{
    int id;
    std::cout << "Enter account ID to view: ";
    std::cin >> id;
    
    std::ifstream meowdb("MeowDB.meow");
    BankAccount account;
    bool found = false;

    while (meowdb.peek() != EOF)
    {
        account = meowDeserialize(meowdb);
        if (account.account_id == id)
        {
            found = true;
            std::cout << "Account ID: " << account.account_id << std::endl;
            std::cout << "Account Name: " << account.account_name << std::endl;
            std::cout << "Balance: " << account.balance << std::endl;
            break;
        }
    }
    if (!found)
    {
        std::cout << "Account with ID " << id << " not found." << std::endl;
    }
    meowdb.close();
    
}
void viewAllAccounts()
{
    std::cout << "Viewing all accounts." << std::endl;
}

void interactiveMenu()
{
    int choice;
    //Interactive Menu.
    do
    {
        std::cout << "Welcome to MeowBank, powered by MeowDB!" << std::endl;
        std::cout << "Select your option: " << std::endl;
        std::cout << "1. Add account" << std::endl;
        std::cout << "2. Remove account" << std::endl;
        std::cout << "3. View accounts" << std::endl;
        std::cout << "4. View all" << std::endl;

        std::cin >> choice;

        switch (choice)
        {
        case 1:
            system("cls");
            addAccount();
            break;
        case 2:
            system("cls");
            removeAccount();
            break;
        case 3:
            system("cls");
            viewAccount();
            break;
        case 4:
            system("cls");
            viewAllAccounts();
            break;
        case 5:
            system("cls");
            std::cout << "Exiting MeowDB :(" << std::endl;
            break;
        default:
            system("cls");
            std::cout << "Invalid choice." << std::endl;
            break;
        }

        std::cout << std::endl; // visiblity
    } while (choice != 5);
    
    }
