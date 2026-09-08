# 🔐 Login & Registration System (C++)

A console-based **Login & Registration System** built in C++ that validates user names and passwords, stores user credentials in a local text file, verifies login credentials, and provides an option to reset all registered data.

> 🎓 Developed as part of the **CodeAlpha C++ Programming Internship**.

---

## ✨ Features

- 📝 **User Registration** with name and password validation
- 🔑 **Login Verification** using stored credentials
- ♻️ **Reset Option** to clear all registered users
- 💾 **File Handling** using a local `users.txt` file
- ✅ **Input Validation** for names and passwords

---

## 🛠️ Tech Stack

| Category | Details |
|---|---|
| **Language** | C++ |
| **File Handling** | `fstream` |
| **Concepts** | Object-Oriented Programming, String Manipulation, Input Validation |
| **Storage** | Local Text File |
| **Platform** | Windows |

---

## 📂 Project Structure

The main functionality of the project is implemented using the `userdata` class.

| Method | Responsibility |
|---|---|
| `registration()` | Validates user information and stores the credentials in `users.txt` |
| `login()` | Reads stored credentials and verifies the entered name and password |
| `reset()` | Clears all registered user data from `users.txt` |

---

## ✅ Validation Rules

### 👤 Name Validation

The name must:

- Contain **6–15 characters**
- Contain only **letters and spaces**
- Have at least **1 uppercase letter**
- Have at least **1 space**
- Have a maximum of **2 spaces**
- Not contain digits or special characters

### 🔐 Password Validation

The password must:

- Contain at least **1 uppercase letter**
- Contain at least **1 digit**
- Contain at least **1 special character**
- Not contain spaces

---

## 🖥️ How to Use

1. Run the program.
2. Choose an option from the main menu:
   - **1** — Register a new user (name + password following the rules above)
   - **2** — Login with an existing name + password
   - **3** — Reset file (clears all registered users)
   - **4** — Exit

---

## ⚠️ Notes & Limitations

- Passwords are stored as **plain text** in `users.txt` — not suitable for production/real-world use.
- No duplicate-username check is performed during registration.

---

## 👤 Author

**Danish Noor**
Built as part of the **CodeAlpha C++ Programming Internship**.
