#include "Exchanger.h"

Exchanger::Exchanger(std::vector<std::pair<std::string, double>>& initial_absolute_value,
          std::vector<std::pair<std::string, std::string>>& initial_pairs){
    for (auto& [name, cost] : initial_absolute_value) {
        cost_table[name] = cost;
    }

    pair_table.insert(initial_pairs.begin(), initial_pairs.end());
}

bool Exchanger::addCurrency(std::string name, double value) {
    if (cost_table.find(name) != cost_table.end()) {
        return false;
    }
    cost_table[name] = value;
    return true;
}

bool Exchanger::addTradePair(std::string first, std::string second) {
    auto trade_pair = std::make_pair(first, second);
    if (pair_table.find(trade_pair) != pair_table.end()) {
        return false;
    }
    pair_table.insert(trade_pair);
    return true;
}

double Exchanger::viewPrice(std::string name) {
    if (cost_table.find(name) != cost_table.end()) {
        return cost_table[name];
    }
    throw std::string{"No such currency!"};
}

void Exchanger::deleteCurrency(std::string name){
    cost_table.erase(name);
}

void Exchanger::deleteTradePair(std::string first, std::string second){
    pair_table.erase(std::make_pair(first, second));
}