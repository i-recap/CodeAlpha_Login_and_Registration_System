# Login and Registration System

A simple console-based Login and Registration System developed in C++. The application allows users to register with a username and password, securely stores credentials using hashing, and authenticates users during login.

---

## Features

- User Registration
- User Login
- Username validation
- Password validation
- Duplicate username detection
- Password hashing
- Credentials stored in separate user files
- Login authentication
- Error and success messages

---

## Technologies Used

- C++
- File Handling
- Hashing
- Functions
- Input Validation

---

## Project Structure

```
Login-System/
│
├── users/
│   ├── user1.txt
│   ├── user2.txt
│   └── ...
│
└── main.cpp
```

---

## How It Works

### Registration

1. Enter username.
2. Enter password.
3. Username is validated.
4. Password is validated.
5. Duplicate usernames are checked.
6. Password hash is stored inside a user file.

### Login

1. Enter username.
2. Enter password.
3. Stored hash is read.
4. Password hash is generated.
5. Both hashes are compared.
6. User is authenticated.

---

## Concepts Used

- File Handling
- Hashing
- Functions
- String Manipulation
- Input Validation
- Conditional Statements
- Loops

---

## Requirements

- Create a folder named **users** in the project directory before running the application.
- Each registered user will have a separate file inside this folder.

---
