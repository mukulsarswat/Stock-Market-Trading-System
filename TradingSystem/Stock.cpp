#include "Stock.h"

Stock::Stock(int i, string n, double p, int v) : id(i), name(n), price(p), volume(v) {}

int Stock::getID() const { return id; }
string Stock::getName() const { return name; }
double Stock::getPrice() const { return price; }
int Stock::getVolume() const { return volume; }

void Stock::updatePrice(double newPrice) {
    if (newPrice <= 0) throw invalid_argument("Price must be positive.");
    price = newPrice;
}

void Stock::updateVolume(int change) {
    if (volume + change < 0) throw runtime_error("Insufficient market volume.");
    volume += change;
}

void Stock::display() const {
    cout << "ID: " << id << " | " << name << " | Price: $" << price << " | Volume: " << volume << endl;
}
