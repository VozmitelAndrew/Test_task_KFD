#pragma once

#include <string>
#include <unordered_set>
#include <vector>
#include <unordered_map>

struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const std::pair<T1, T2>& p) const {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};


class Exchanger{
public:
    Exchanger();

    Exchanger(std::vector<std::pair<std::string, double>>& initial_absolute_value, std::vector<std::pair<std::string, std::string>>& initial_pairs);

    bool addCurrency(std::string name, double value);
    void deleteCurrency(std::string name);
    bool addTradePair(std::string first, std::string second);
    void deleteTradePair(std::string first, std::string second);
    double viewPrice(std::string name);
private:
    std::unordered_map<std::string, double> cost_table;
    std::unordered_set<std::pair<std::string, std::string>, pair_hash> pair_table;
};