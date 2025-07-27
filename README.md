#  C++ Login & Signup System (with File Handling)

This is a simple C++ project that implements a **login, signup, and password recovery system** using file handling. It stores user credentials (username, email, password) in a plain text file and allows basic account management through a console-based interface.

---

##  Features

-  Sign Up: Register with a username, email, and password
   Login: Authenticate using stored credentials
-  Forgot Password: Recover password using username and email
-  Data Persistence: User data is stored in a file (`loginData.txt`)
-  Graceful handling of file errors and user input

---

##  File Structure

- `main.cpp` – contains the `main()` function and class logic
- `loginData.txt` – data file created automatically after first signup

---

##  Technologies Used

- Language: C++
- File Handling: `fstream`
- Data Format: Custom delimiter-separated values

---

##  How to Run

### Compile the code:
```bash
g++ main.cpp -o loginApp
