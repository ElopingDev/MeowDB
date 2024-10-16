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


