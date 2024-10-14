#include <iostream>
#include <fstream>
#include "funcs.h"
#include "BankAccount.h"

int main() {

    interactiveMenu();
    
    //Deserialize from file
    std::ifstream inFile("MeowDB.meow");
    BankAccount loadedAccount = meowDeserialize(inFile);
    inFile.close();

    std::cout << "Loaded MeowDB.meow" << std::endl;
    std::cout << "Account ID: " << loadedAccount.account_id << std::endl;
    std::cout << "Account Name: " << loadedAccount.account_name << std::endl;
    std::cout << "Balance: " << loadedAccount.balance << std::endl;
    return 0;
}
