#pragma once
#include "Stock.h"
#include <vector>
using namespace std;

class Stock; // forward declaration

class Market {
private:
    vector<Stock> stocks;
public:
    void addStock(const Stock& s);
    Stock* getStockByID(int id);
    void displayStocks() const;
};
