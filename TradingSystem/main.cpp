#include "Market.h"
#include "User.h"
#include "Broker.h"
#include <memory>
#include <iostream>
using namespace std;

int main() {
    try {
        Market market;
        market.addStock({1, "AAPL", 150, 1000});
        market.addStock({2, "GOOGL", 2800, 500});
        market.addStock({3, "AMZN", 3500, 300});

        double balance, commission;
        cout << "Initial Balance: $"; cin >> balance;
        cout << "Commission Rate (0.02 for 2%): "; cin >> commission;

        unique_ptr<User> user = make_unique<Broker>(balance, commission);

        int choice;
        do {
            cout << "\n1.View Portfolio\n2.Buy\n3.Sell\n4.Market\n5.History\n6.P/L\n7.Exit\nChoice: ";
            cin >> choice;

            try {
                if (choice == 1) user->viewPortfolio(market);
                else if (choice == 2) {
                    int id, qty; cout << "Stock ID: "; cin >> id;
                    cout << "Qty: "; cin >> qty;
                    Stock* s = market.getStockByID(id); if (!s) throw runtime_error("Stock not found.");
                    user->buy(*s, qty);
                }
                else if (choice == 3) {
                    int id, qty; cout << "Stock ID: "; cin >> id;
                    cout << "Qty: "; cin >> qty;
                    Stock* s = market.getStockByID(id); if (!s) throw runtime_error("Stock not found.");
                    user->sell(*s, qty);
                }
                else if (choice == 4) market.displayStocks();
                else if (choice == 5) user->viewTransactionHistory();
                else if (choice == 6) user->viewProfitLoss(market);
            } catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }

        } while (choice != 7);
    }
    catch (const exception& e) {
        cout << "Fatal Error: " << e.what() << endl;
    }
    return 0;
}
