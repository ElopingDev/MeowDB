#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "BankAccount.h"

void meowWrite(const std::string &data, const std::string &dbName, std::ofstream &meowdb);
void meowSerialize(std::ofstream& meowdb, const BankAccount& account);
BankAccount meowDeserialize(std::ifstream &meowdb);

