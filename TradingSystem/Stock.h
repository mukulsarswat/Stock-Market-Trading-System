#pragma once
#include <string>
#include <stdexcept>
#include <iostream>
using namespace std;

class Stock {
private:
    int id;
    string name;
    double price;
    int volume;

public:
    Stock(int i, string n, double p, int v);

    int getID() const;
    string getName() const;
    double getPrice() const;
    int getVolume() const;

    void updatePrice(double newPrice);
    void updateVolume(int change);
    void display() const;
};
