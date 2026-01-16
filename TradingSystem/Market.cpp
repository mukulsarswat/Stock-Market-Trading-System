#include "Market.h"
#include <iostream>

void Market::addStock(const Stock& s) { stocks.push_back(s); }

Stock* Market::getStockByID(int id) {
    for (auto& s : stocks)
        if (s.getID() == id) return &s;
    return nullptr;
}

void Market::displayStocks() const {
    std::cout << "\n--- MARKET STOCKS ---\n";
    for (const auto& s : stocks) s.display();
}
