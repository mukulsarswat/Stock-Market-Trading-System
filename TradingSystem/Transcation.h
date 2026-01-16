#pragma once
#include <string>
using namespace std;

struct Transaction {
    int stockID;
    string type; // BUY / SELL
    int quantity;
    double price;
};

struct Holding {
    int stockID;
    int quantity;
    double avgBuyPrice;
};
