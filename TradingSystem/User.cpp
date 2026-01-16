#include "User.h"
#include "Market.h"
#include <iostream>
#include <iomanip>

User::User(double bal) : balance(bal) {
    if (bal < 0) throw invalid_argument("Initial balance cannot be negative.");
}

void User::validateQuantity(int qty) {
    if (qty <= 0) throw invalid_argument("Quantity must be positive.");
}

void User::updateHolding(int stockID, int qty, double price) {
    for (auto& h : portfolio) {
        if (h.stockID == stockID) {
            double totalCost = h.avgBuyPrice * h.quantity + price * qty;
            h.quantity += qty;
            h.avgBuyPrice = totalCost / h.quantity;
            return;
        }
    }
    portfolio.push_back({stockID, qty, price});
}

void User::removeHolding(int stockID) {
    portfolio.erase(remove_if(portfolio.begin(), portfolio.end(),
                              [&](const Holding& h) { return h.stockID == stockID; }),
                    portfolio.end());
}

void User::buy(Stock& stock, int qty) {
    validateQuantity(qty);
    double cost = stock.getPrice() * qty;
    if (balance < cost) throw runtime_error("Insufficient balance.");
    stock.updateVolume(-qty);
    balance -= cost;
    updateHolding(stock.getID(), qty, stock.getPrice());
    history.push_back({stock.getID(), "BUY", qty, stock.getPrice()});
}

void User::sell(Stock& stock, int qty) {
    validateQuantity(qty);
    for (auto& h : portfolio) {
        if (h.stockID == stock.getID()) {
            if (h.quantity < qty) throw runtime_error("Not enough shares to sell.");
            double revenue = stock.getPrice() * qty;
            stock.updateVolume(qty);
            balance += revenue;
            h.quantity -= qty;
            history.push_back({stock.getID(), "SELL", qty, stock.getPrice()});
            if (h.quantity == 0) removeHolding(stock.getID());
            return;
        }
    }
    throw runtime_error("Stock not found in portfolio.");
}

void User::viewPortfolio(const Market&) const {
    cout << "\n--- PORTFOLIO ---\n";
    if (portfolio.empty()) {
        cout << "Portfolio empty.\n";
        return;
    }
    for (const auto& h : portfolio)
        cout << "Stock ID: " << h.stockID << " | Qty: " << h.quantity
             << " | Avg Buy: $" << fixed << setprecision(2) << h.avgBuyPrice << endl;
    cout << "Balance: $" << balance << endl;
}

void User::viewTransactionHistory() const {
    cout << "\n--- TRANSACTION HISTORY ---\n";
    for (const auto& t : history)
        cout << t.type << " | Stock ID: " << t.stockID
             << " | Qty: " << t.quantity
             << " | Price: $" << t.price << endl;
}

void User::viewProfitLoss(const Market& market) const {
    cout << "\n--- PORTFOLIO P/L ---\n";
    if (portfolio.empty()) {
        cout << "Portfolio empty.\n";
        return;
    }
    for (const auto& h : portfolio) {
        const Stock* s = market.getStockByID(h.stockID);
        if (!s) continue;
        double pl = (s->getPrice() - h.avgBuyPrice) * h.quantity;
        cout << "Stock ID: " << h.stockID
             << " | Qty: " << h.quantity
             << " | Avg Buy: $" << h.avgBuyPrice
             << " | Current: $" << s->getPrice()
             << " | P/L: $" << fixed << setprecision(2) << pl << endl;
    }
}
