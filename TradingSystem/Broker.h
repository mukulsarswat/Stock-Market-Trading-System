#pragma once
#include "User.h"

class Broker : public User {
private:
    double commissionRate;
public:
    Broker(double bal, double rate);
    void buy(Stock& stock, int qty) override;
    void sell(Stock& stock, int qty) override;
};
