#include "Broker.h"

Broker::Broker(double bal, double rate) : User(bal), commissionRate(rate) {
    if (rate < 0) throw invalid_argument("Commission rate cannot be negative.");
}

void Broker::buy(Stock& stock, int qty) {
    double commission = stock.getPrice() * qty * commissionRate;
    if (balance < (stock.getPrice() * qty + commission))
        throw runtime_error("Insufficient balance including commission.");
    User::buy(stock, qty);
    balance -= commission;
    cout << "Commission paid: $" << commission << endl;
}

void Broker::sell(Stock& stock, int qty) {
    double commission = stock.getPrice() * qty * commissionRate;
    User::sell(stock, qty);
    balance -= commission;
    cout << "Commission paid: $" << commission << endl;
}
