#include <iostream>
#include "ATM.h"

#define adder 100

struct User{
    std::unordered_map<std::string, double> cash;
};

int main() {
    std::cout << "Hello, User!" << std::endl;

    std::vector<std::pair<std::string, double>> initial_currency_values = {
            {"BTC", adder}, {"USD", 56678*adder}, {"RUB", 5178290*adder}, {"EUR", 51425*adder}, {"USDT", 57042*adder}
    };

    std::vector<std::pair<std::string, std::string>> initial_pairs = {
            {"RUB", "USD"}, {"USD", "EUR"}, {"EUR", "RUB"}, {"USDT", "USD"}, {"BTC", "USD"}
    };

    std::vector<std::pair<std::string, double>> initial_machine_money = {
            {"RUB", 10000}, {"USD", 1000}, {"EUR", 1000}, {"USDT", 1000}, {"BTC", 2}
    };

    Exchanger exchanger(initial_currency_values, initial_pairs);
    ATM atm(initial_machine_money, exchanger);

}
