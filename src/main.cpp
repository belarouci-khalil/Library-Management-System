#include "database.h"
#include <iostream>
#include <string>

void menu() {
    std::cout << "Library Management System\n";
    std::cout << "1. Add Book\n";
    std::cout << "2. List Books\n";
    std::cout << "3. Update Book\n";
    std::cout << "4. Delete Book\n";
    std::cout << "5. Add Author\n";
    std::cout << "6. List Authors and Their Books\n";
    std::cout << "7. Register Borrower\n";
    std::cout << "8. List Borrowers and Their Borrowed Books\n";
    std::cout << "9. Record Borrowing\n";
    std::cout << "10. Return Book\n";
    std::cout << "0. Exit\n";
}

int main() {
    int choice;
    do {
        menu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string title, genre;
                int author_id;
                std::cout << "Enter book title: ";
                std::cin.ignore(); // Clear the newline character from input buffer
                std::getline(std::cin, title);
                std::cout << "Enter author ID: ";
                std::cin >> author_id;
                std::cout << "Enter genre: ";
                std::cin.ignore();
                std::getline(std::cin, genre);
                addBook(title, author_id, genre);
                break;
            }
            case 2:
                listBooks();
                break;
            case 3: {
                int book_id;
                std::string new_title, new_genre;
                int new_author_id;
                std::cout << "Enter book ID to update: ";
                std::cin >> book_id;
                std::cout << "Enter new title: ";
                std::cin.ignore();
                std::getline(std::cin, new_title);
                std::cout << "Enter new author ID: ";
                std::cin >> new_author_id;
                std::cout << "Enter new genre: ";
                std::cin.ignore();
                std::getline(std::cin, new_genre);
                updateBook(book_id, new_title, new_author_id, new_genre);
                break;
            }
            case 4: {
                int book_id;
                std::cout << "Enter book ID to delete: ";
                std::cin >> book_id;
                deleteBook(book_id);
                break;
            }
            case 5: {
                std::string author_name;
                std::cout << "Enter author name: ";
                std::cin.ignore();
                std::getline(std::cin, author_name);
                addAuthor(author_name);
                break;
            }
            case 6:
                listAuthorsAndBooks();
                break;
            case 7: {
                std::string borrower_name;
                std::cout << "Enter borrower name: ";
                std::cin.ignore();
                std::getline(std::cin, borrower_name);
                registerBorrower(borrower_name);
                break;
            }
            case 8:
                listBorrowersAndBooks();
                break;
            case 9: {
                int book_id, borrower_id;
                std::string borrow_date;
                std::cout << "Enter book ID to borrow: ";
                std::cin >> book_id;
                std::cout << "Enter borrower ID: ";
                std::cin >> borrower_id;
                std::cout << "Enter borrow date (YYYY-MM-DD): ";
                std::cin.ignore();
                std::getline(std::cin, borrow_date);
                recordBorrowing(book_id, borrower_id, borrow_date);
                break;
            }
            case 10: {
                int book_id;
                std::cout << "Enter book ID to return: ";
                std::cin >> book_id;
                returnBook(book_id);
                break;
            }
            case 0:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }

    } while (choice != 0);

    return 0;
}
