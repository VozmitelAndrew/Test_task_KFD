#include "ATM.h"

ATM::ATM(std::vector<std::pair<std::string, double>>& initial_money, Exchanger& _exchanger): exchanger(_exchanger){
    for (const auto& [name, cost] : initial_money) {
        amount_in_machine[name] = cost;
    }
}

std::string ATM::exchange(double amount, std::string first, std::string second) {
    double first_currency_value;
    double second_currency_value;
    try{
        first_currency_value = exchanger.viewPrice(first);
        second_currency_value = exchanger.viewPrice(second);

        if(!exchanger.addTradePair(first,second)){
            throw std::string{"Pair not supported"};
        }
    }catch(std::string error){
        throw error;
    }

    double amount_second_currency = (amount * first_currency_value) / second_currency_value;


    if (amount_in_machine[second] < amount_second_currency) {
        throw std::string{"Not enough money in the machine for exchange"};
    }


    amount_in_machine[first] += amount;
    amount_in_machine[second] -= amount_second_currency;

    return "Exchange successful: " + first + ": " + std::to_string(amount) + " exchanged for " + second + ": " + std::to_string(amount_second_currency);
}


void ATM::addMoney(std::string name, double amount) {
    amount_in_machine[name] += amount;
}

void ATM::withdrawMoney(std::string name, double amount){
    if(amount_in_machine[name] >= amount){
        amount_in_machine[name] -= amount;
    }else{
        throw std::string{"Not enough money in the machine to withdraw"};
    }
}