#  Banking Management System (C++)
 
A console-based **Banking Management System** built in C++ that simulates core banking operations — customer registration, account management, deposits, withdrawals, and fund transfers — complete with input validation and transaction history tracking.
 
> 🎓 Developed as **Task 3** of the **CodeAlpha C++ Programming Internship**.
 
---
 
## ✨ Features
 
- 👤 Customer registration & login (Name + Customer ID based authentication)
- 💳 Create up to **2 accounts per customer** — Savings or Business
- 💰 Deposit & Withdraw money with real-time balance validation
- 🔁 Fund transfer between accounts, with minimum-balance protection
- 🧾 Auto-generated unique Transaction IDs (`TXN-1001`, `TXN-1002`, ...)
- 📜 Transaction history — view all transactions or search by Transaction ID
- 🔒 Strict input validation for names, customer IDs, account numbers, MPIN, and phone numbers
---
 
## 🛠️ Tech Stack
 
| | |
|---|---|
| **Language** | C++ |
| **Concepts Used** | Object-Oriented Programming (Classes & Objects), Arrays of Objects, Control Flow, Input Validation |
| **Platform** | Windows (uses `<windows.h>`, `system("cls")`, `system("pause")`) |
 
---
 
## 📂 Project Structure
 
The system is built around 4 core classes:
 
| Class | Responsibility |
|---|---|
| `Transaction` | Stores transaction details — ID, sender/receiver account, amount, date, resulting balance |
| `Account` | Stores account details — number, type, MPIN, phone, balance |
| `Customer` | Holds a customer's profile, up to 2 accounts, and up to 10 transactions |
| `Bank` | Manages all customers and drives registration, login, and every banking operation |
 
---
 
## ✅ Validation Rules
 
| Field | Rule |
|---|---|
| Name | 6–15 characters, letters & spaces only, at least 1 uppercase letter, max 2 spaces |
| Customer ID | Format `CUSxxxx` (e.g. `CUS1001`) |
| Account Number | Format `ACxxxx` (e.g. `AC1001`) |
| MPIN | Exactly 4 digits, cannot be `0000` |
| Phone Number | 11 digits, must start with `03` |
| Savings Account | Minimum balance of **Rs. 1,000** |
| Business Account | Minimum balance of **Rs. 10,000** |
| Transfer Amount | Between **Rs. 500 – Rs. 50,000**, must be a multiple of 500 |
 
---
 
## 🚀 Getting Started
 
### Prerequisites
- A C++ compiler (e.g. **g++ / MinGW**) on Windows, or any IDE such as Code::Blocks, Dev-C++, or Visual Studio
### Compile & Run
```bash
g++ BankingSystem.cpp -o BankingSystem
./BankingSystem
```
 
---
 
## 🖥️ How to Use
 
1. Run the program.
2. **Register** as a new customer with your Name and a Customer ID.
3. **Login** using your registered Name and ID.
4. From the Customer Menu, choose an action:
   - Create Account
   - View Account
   - Deposit
   - Withdraw
   - Transfer
   - Transaction History
   - Logout
---
 
## 🔮 Future Improvements
 
- Persist customer/account data using file handling or a database (currently in-memory only)
- Encrypt MPIN storage instead of storing as plain text
- Add an admin panel for bank-level reports and analytics
- Remove Windows-specific calls for cross-platform support
---
 
## 👤 Author
 
**Danish**
Built as part of the **CodeAlpha C++ Programming Internship**.
 
---
 
## 📄 License
 
This project is open-source and available for educational purposes.
