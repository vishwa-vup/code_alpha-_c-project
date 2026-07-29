# 🔐 Login & Registration System

A professional C++ console application that allows users to register and log in using file handling. The system stores user credentials in a text file, prevents duplicate usernames, and verifies user login.

---

# 📌 Project Information

- **Project Name:** Login & Registration System
- **Language:** C++
- **Internship:** CodeAlpha C++ Programming Internship
- **Task:** Task 2 – Login & Registration System

---

# 🚀 Features

- User Registration
- User Login
- Duplicate Username Detection
- Password Confirmation
- File Handling using `fstream`
- Simple and Interactive Menu
- Success and Error Messages
- Object-Oriented Programming (OOP)

---

# 🛠 Technologies Used

- C++
- Object-Oriented Programming
- File Handling (`fstream`)
- Classes & Objects
- Functions
- Conditional Statements
- Loops
- String Library

---

# 📂 Project Structure

```
Login_Registration_System/
│
├── login_registration.cpp
├── users.txt
└── README.md
```

---

# ⚙️ How It Works

### Registration

1. Enter a username.
2. The system checks whether the username already exists.
3. Enter and confirm the password.
4. If successful, the username and password are saved in `users.txt`.

### Login

1. Enter username.
2. Enter password.
3. The system verifies the credentials stored in the file.
4. Displays either a success or an error message.

---

# 💻 How to Compile

Using **g++**

```bash
g++ login_registration.cpp -o login_registration
```

---

# ▶️ How to Run

### Windows

```bash
login_registration.exe
```

### Linux / macOS

```bash
./login_registration
```

---

# 📸 Sample Menu

```
=====================================
 LOGIN & REGISTRATION SYSTEM
 CodeAlpha Internship Project
=====================================

1. Register
2. Login
3. Exit

Enter Choice:
```

---

# 📸 Sample Registration

```
Enter Username: vishwa

Enter Password: 12345

Confirm Password: 12345

Registration Successful.
```

---

# 📸 Sample Login

```
Username: vishwa

Password: 12345

Login Successful.

Welcome, vishwa!
```

---

# 📸 Sample users.txt

```
vishwa 12345
john password
alex qwerty
```

---

# 🎯 Learning Outcomes

This project demonstrates:

- Object-Oriented Programming
- Encapsulation
- Classes and Objects
- File Handling
- User Authentication
- Input Validation
- Basic Database Simulation
- Menu-Driven Programming

---

# 🔮 Future Improvements

- Encrypt passwords before storing them.
- Hide password input while typing.
- Password strength validation.
- Forgot password feature.
- Delete user account.
- Update password.
- Admin login.
- Store user data in a database (SQLite/MySQL).

---

# 📜 Conclusion

The Login & Registration System provides a simple and effective authentication mechanism using C++ and file handling. It demonstrates important programming concepts such as object-oriented design, file operations, and user validation, making it an excellent beginner-to-intermediate project for learning secure data management principles.

---

# 👨‍💻 Author

**Name:** Vishwa

**Internship:** CodeAlpha C++ Programming Internship

**Language:** C++

---