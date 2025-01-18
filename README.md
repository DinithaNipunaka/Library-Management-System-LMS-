# Library-Management-System--LMS-

The Library Management System is a C++ console application designed to help manage library operations such as book registration, user registration, borrowing books, and more. It is a lightweight system that uses file-based storage to track data for books, users, and borrowing records.

---

## Features

1. User Authentication
   - Login system for administrators.
   - Administrator registration functionality.

2. Dashboard
   - Intuitive dashboard for accessing various system features.

3. Book Management
   - Register new books with details like name, author, price, issue date, and quantity.
   - List all registered books.

4. User Management
   - Register new members with personal details.
   - List all registered members.

5. Borrowing System
   - Borrow books by selecting from available ones.
   - Manage borrowed books and set expiration dates.

6. Expired Book Notification
   - Check for overdue books and display expired borrowing records.

7. Logout
   - Logout and return to the main menu.

---

## How to Run the Project

### Prerequisites
- Windows OS (required for the `Sleep` function and `system("cls")` commands).
- C++ Compiler (e.g.Microsoft Visual C++).

### Steps
1. Clone this repository:
 https://github.com/DinithaNipunaka/Library-Management-System-LMS-

2. Compile the program:
   g++ library_management_system.cpp -o library_management_system

3. Run the executable:
   ./library_management_system
---

## File Structure

| File Name               | Purpose                                                                 |
|-------------------------|-------------------------------------------------------------------------|
| `adminRegStaff.txt`     | Stores registered admin credentials.                                    |
| `registeredBooks.txt`   | Stores information about registered books.                              |
| `userRegistation.txt`   | Stores information about registered library members.                    |
| `borrowedBooks.txt`     | Stores records of borrowed books, including expiration dates.           |

---

## Functional Modules

1. Login Module
   - Validates admin credentials from `adminRegStaff.txt`.

2. Register Admin
   - Registers a new administrator and saves credentials in `adminRegStaff.txt`.

3. Book Registration
   - Adds new books to the `registeredBooks.txt` file with unique IDs.

4. User Registration
   - Registers new library members and saves their data in `userRegistation.txt`.

5. Borrow Books
   - Allows users to borrow books by associating a member with a book ID.

6. Expired Books
   - Checks and displays books that have exceeded their borrowing expiration dates.

---

## Example Usage

- Login: 
  Enter your username and password to access the dashboard.
- Register Admin: 
  Create a new administrator account with a secure password.
- Register Book:
  Enter details like book name, author, and issue date.
- List Books: 
  View all the books in the library.
- Register Member:
  Add new members to the library.
- Borrow Book:
  Assign a book to a registered member with an expiration date.

---

## Limitations
1. File-Based Storage: 
   No database support; all data is stored in text files.
2. Single-User Admin: 
   Does not support multiple simultaneous users.
3. Basic Validation: 
   Limited input validation for user entries.

---

## Contribution

Contributions are welcome! If you'd like to improve the system or fix a bug, please fork the repository and submit a pull request.

---

## License

This project is licensed under the MIT License.

---
