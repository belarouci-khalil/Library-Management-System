﻿# Library-Management-System
# Library-Management-System
# Library Management System

## Overview
The **Library Management System** is a console-based application designed to manage library resources efficiently. It allows users to perform various operations, such as managing books, authors, borrowers, and book borrowing/return records. The application is written in C++ and provides an intuitive user interface for library staff and administrators.

---

## Features
### Core Functionalities:
1. **Add Book**: Add a new book with a title, author, and genre.
2. **List Books**: Display a list of all books in the library.
3. **Update Book**: Update the details of an existing book.
4. **Delete Book**: Remove a book from the library.
5. **Add Author**: Register a new author.
6. **List Authors and Their Books**: Display a list of all authors and their associated books.
7. **Register Borrower**: Add a new borrower to the system.
8. **List Borrowers and Their Borrowed Books**: Display all borrowers and the books they have borrowed.
9. **Record Borrowing**: Record the borrowing of a book by a borrower.
10. **Return Book**: Mark a book as returned by a borrower.

---

## Installation
1. Clone this repository or download the source code.
2. Ensure you have a C++ compiler (e.g., GCC) installed.
3. Compile the code using the following command:
   ```bash
   g++ main.cpp database.cpp -o library_management
   ```
4. Run the application:
   ```bash
   ./library_management
   ```

---

## How to Use
### Navigation:
- The application provides a menu with numbered options.
- Enter the number corresponding to the desired operation.

### Input Details:
- Follow the prompts to enter information such as book title, author ID, borrower name, etc.
- Invalid inputs will result in an error message, and you will be prompted to try again.

### Exiting:
- Select option `0` from the menu to exit the application.

---

## Dependencies
This project relies on a `database.h` and `database.cpp` file for database operations. Ensure these files are included in the same directory as `main.cpp` and are correctly implemented with functions such as:
- `addBook()`
- `listBooks()`
- `updateBook()`
- `deleteBook()`
- `addAuthor()`
- `listAuthorsAndBooks()`
- `registerBorrower()`
- `listBorrowersAndBooks()`
- `recordBorrowing()`
- `returnBook()`

---

## Code Highlights
### Modular Design:
- **Header File**: Includes the function declarations for database operations.
- **Main File**: Manages the user interface and interactions.

### User Interface:
- Centered and colored text output for better readability.
- Clear prompts and error handling for a user-friendly experience.

### Portability:
- Compatible with both Windows and Unix-based systems using `system("cls")` and `system("clear")` commands.

---

## Future Improvements
1. Implement a graphical user interface (GUI).
2. Add database persistence using files or an actual database like SQLite.
3. Extend functionality to manage overdue books and generate reports.

---

## Contributing
1. Fork the repository.
2. Create a new branch for your feature or bugfix.
3. Commit your changes and push the branch.
4. Create a pull request to merge your branch into the main repository.

