# 📈 Stock Trading System 

A **menu-driven trading simulation system** built in **C++** using **Object-Oriented Programming (OOP)** principles.  
This project models a simplified stock market where users (brokers) can **buy/sell stocks, track portfolio, view transaction history, and analyze profit/loss (P/L)**.

---
## 📊 Trading Workflow

```mermaid
flowchart TD
    A[Start Program] --> B[Initialize Market with Stocks]
    B --> C[Enter Balance & Commission Rate]
    C --> D[Main Menu]

    D -->|1| E[View Portfolio]
    D -->|2| F[Buy Stock]
    D -->|3| G[Sell Stock]
    D -->|4| H[View Market]
    D -->|5| I[Transaction History]
    D -->|6| J[Profit/Loss Report]
    D -->|7| K[Exit Program]

    F --> L[Validate Quantity & Balance]
    L --> M[Update Portfolio & History]
    M --> N[Deduct Commission]

    G --> O[Validate Holdings]
    O --> P[Update Portfolio & History]
    P --> Q[Deduct Commission]

    J --> R[Calculate Profit/Loss]
    R --> S[Show P/L Report]

    K --> T[End Program]
   ```
---

## 🎯 Features

- **Market Simulation**
  - Add and display available stocks
  - Update stock prices and volumes

- **User / Broker**
  - Buy and sell stocks
  - Track portfolio holdings
  - Transaction history
  - Profit/Loss analytics

- **Broker-Specific**
  - Commission applied on each trade
  - Balance management with commission deduction

- **OOP Concepts**
  - Encapsulation (private attributes, getters/setters)
  - Inheritance (`Broker` extends `User`)
  - Polymorphism (virtual methods overridden in `Broker`)
  - Exception handling for invalid operations
  - Smart pointers for memory safety

---

## 🗂️ Project Structure

```
TradingSystem/
│
├── main.cpp             # Entry point, menu-driven interface
├── Stock.h              # Stock class declaration
├── Stock.cpp            # Stock class implementation
├── Market.h             # Market class declaration
├── Market.cpp           # Market class implementation
├── User.h               # User base class
├── User.cpp             # User methods (buy/sell/portfolio/P&L)
├── Broker.h             # Broker class (inherits User)
├── Broker.cpp           # Broker methods (commission logic)
├── Transaction.h        # Transaction & Holding structs
└── Utils.h              # Optional utility functions
```

---

## 👨‍💻 Classes Overview

### `Stock`
- Attributes: `id, name, price, volume`
- Methods:
  - `updatePrice()`, `updateVolume()`
  - `display()`

### `Market`
- Maintains a list of `Stock`
- Methods:
  - `addStock()`
  - `getStockByID()`
  - `displayStocks()`

### `User`
- Attributes: `portfolio, history, balance`
- Methods:
  - `buy()`, `sell()`
  - `viewPortfolio()`
  - `viewTransactionHistory()`
  - `viewProfitLoss()`

### `Broker` (inherits `User`)
- Additional attribute: `commissionRate`
- Overrides:
  - `buy()` → deducts commission
  - `sell()` → deducts commission

### `Transaction`
- Structs:
  - `Transaction` → records each trade
  - `Holding` → tracks portfolio holdings

---

## 🧠 System Logic

### Menu Flow
```
Main Menu
│
├── View Portfolio
├── Buy Stock
├── Sell Stock
├── View Market
├── Transaction History
├── Profit/Loss Report
└── Exit
```

### Profit/Loss Calculation
```
P/L = (Current Price - Avg Buy Price) × Quantity
```

---

## 🚀 Compilation & Execution

### Compile
```bash
g++ main.cpp Stock.cpp Market.cpp User.cpp Broker.cpp -o trading
```

### Run
```bash
./trading
```

---

## 📖 Example Run

```
Initial Balance: $10000
Commission Rate (0.02 for 2%): 0.02

1.View Portfolio
2.Buy
3.Sell
4.Market
5.History
6.P/L
7.Exit
Choice: 2
Stock ID: 1
Qty: 10
Commission paid: $30.00
```

---

## 🧩 Key Concepts Demonstrated

- **Encapsulation** → Stock attributes hidden, accessed via getters
- **Inheritance & Polymorphism** → Broker overrides User methods
- **File Separation** → Clean modular design with `.h` and `.cpp`
- **Exception Handling** → Prevents invalid trades
- **Smart Pointers** → Safe memory management (`unique_ptr<User>`)

---

## ✅ Future Improvements

- Add **real-time price updates** (e.g., random fluctuations)
- Support **multiple users/brokers**
- Save/load portfolio and transactions from files
- Add **graphical P/L visualization**



