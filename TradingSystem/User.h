#pragma once
#include "Stock.h"
#include "Transaction.h"
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>
using namespace std;

class Market;

class User {
protected:
    vector<Holding> portfolio;
    vector<Transaction> history;
    double balance;

public:
    explicit User(double bal);
    virtual ~User() = default;

    virtual void buy(Stock& stock, int qty);
    virtual void sell(Stock& stock, int qty);

    void viewPortfolio(const Market& market) const;
    void viewTransactionHistory() const;
    void viewProfitLoss(const Market& market) const;

protected:
    void validateQuantity(int qty);
    void updateHolding(int stockID, int qty, double price);
    void removeHolding(int stockID);
};
