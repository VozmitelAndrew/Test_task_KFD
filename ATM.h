#pragma once

#include "Exchanger.h"

#include <string>
#include <vector>
#include <unordered_map>

class ATM{
public:
    ATM(std::vector<std::pair<std::string, double>>& initial_money, Exchanger& _exchanger);

    std::string exchange(double amount, std::string first, std::string second);

    void addMoney(std::string name, double amount);
    void withdrawMoney(std::string name, double amount);

private:
    std::unordered_map<std::string, double> amount_in_machine;
    Exchanger& exchanger;
};