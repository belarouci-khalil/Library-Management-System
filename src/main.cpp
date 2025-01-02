#include "database.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <set>
#include <random>

const int SCREEN_WIDTH = 80;
std::set<int> used_ids; 

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void printCentered(const std::string& text) {
    int padding = (SCREEN_WIDTH - text.size()) / 2;
    if (padding > 0) {
        std::cout << std::string(padding, ' ');
    }
    std::cout << text << "\n";
}

void showHeader() {
    std::cout << "\033[1;36m";
    printCentered("=========================================");
    printCentered("        LIBRARY MANAGEMENT SYSTEM        ");
    printCentered("=========================================");
    std::cout << "\033[0m";
}

int generateUniqueID() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dis(1000, 9999);

    int new_id;
    do {
        new_id = dis(gen);
    } while (used_ids.find(new_id) != used_ids.end());

    used_ids.insert(new_id);
    return new_id;
}

void testFunctions() {
    try {
        clearScreen();
        std::cout << "\033[1;35mRunning test suite...\033[0m\n";

        std::string test_author = "Test Author " + std::to_string(rand() % 10000);
        addAuthor(test_author);
        std::cout << "Added author: " << test_author << "\n";

        std::string test_book = "Test Book " + std::to_string(rand() % 10000);
        std::string test_genre = "Test Genre";
        int author_id = 1; 
        addBook(test_book, author_id, test_genre);
        std::cout << "Added book: " << test_book << " (Genre: " << test_genre << ")\n";
        std::string test_borrower = "Test Borrower " + std::to_string(rand() % 10000);
        registerBorrower(test_borrower);
        std::cout << "Registered borrower: " << test_borrower << "\n";

        int book_id = 1;   
        int borrower_id = 1;
        std::string borrow_date = "2025-01-01";
        recordBorrowing(book_id, borrower_id, borrow_date);
        std::cout << "Recorded borrowing: Book ID " << book_id << " by Borrower ID " << borrower_id << "\n";

        returnBook(book_id);
        std::cout << "Returned book: ID " << book_id << "\n";

        std::cout << "\033[1;32mAll tests completed successfully!\033[0m\n";
    } catch (const std::exception& e) {
        std::cerr << "\033[1;31mError during test execution: " << e.what() << "\033[0m\n";
    }
}

void menu() {
    showHeader();
    std::cout << "\033[1;33m";
    printCentered("1. Add Book");
    printCentered("2. List Books");
    printCentered("3. Update Book");
    printCentered("4. Delete Book");
    printCentered("5. Add Author");
    printCentered("6. List Authors and Their Books");
    printCentered("7. Register Borrower");
    printCentered("8. List Borrowers and Their Borrowed Books");
    printCentered("9. Record Borrowing");
    printCentered("10. Return Book");
    printCentered("11. Run Tests");
    printCentered("12. Logout");
    printCentered("0. Exit");
    std::cout << "\033[0m";
}

bool authenticate() {
    std::string username, password;
    std::cout << "username:admin/password:admin\n";
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    if (username == "admin" && password == "admin") {
        std::cout << "Authentication successful!\n";
        return true;
    } else {
        std::cout << "Invalid credentials. Access denied\n";
        return false;
    }
}

int main() {
    if (!authenticate()) {
        return 1; 
    }

    int choice;
    do {
        clearScreen();
        menu();
        std::cout << "\033[1;32m";
        printCentered("Enter your choice: ");
        std::cout << "\033[0m";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\033[1;31mInvalid input. Please enter a number.\033[0m\n";
            continue;
        }

        clearScreen();
        switch (choice) {
            case 1: {
                std::string title, genre;
                int author_id;
                std::cout << "\033[1;34mEnter book title: \033[0m";
                std::cin.ignore();
                std::getline(std::cin, title);
                std::cout << "\033[1;34mEnter author ID: \033[0m";
                std::cin >> author_id;
                std::cout << "\033[1;34mEnter genre: \033[0m";
                std::cin.ignore();
                std::getline(std::cin, genre);
                addBook(title, author_id, genre);
                std::cout << "\033[1;32mBook added successfully!\033[0m\n";
                break;
            }
            case 2:
                listBooks();
                break;
            case 3: {
                int book_id;
                std::string new_title, new_genre;
                int new_author_id;
                std::cout << "\033[1;34mEnter book ID to update: \033[0m";
                std::cin >> book_id;
                std::cout << "\033[1;34mEnter new title: \033[0m";
                std::cin.ignore();
                std::getline(std::cin, new_title);
                std::cout << "\033[1;34mEnter new author ID: \033[0m";
                std::cin >> new_author_id;
                std::cout << "\033[1;34mEnter new genre: \033[0m";
                std::cin.ignore();
                std::getline(std::cin, new_genre);
                updateBook(book_id, new_title, new_author_id, new_genre);
                std::cout << "\033[1;32mBook updated successfully!\033[0m\n";
                break;
            }
            case 4: {
                int book_id;
                std::cout << "\033[1;34mEnter book ID to delete: \033[0m";
                std::cin >> book_id;
                deleteBook(book_id);
                std::cout << "\033[1;32mBook deleted successfully!\033[0m\n";
                break;
            }
            case 5: {
                std::string author_name;
                std::cout << "\033[1;34mEnter author name: \033[0m";
                std::cin.ignore();
                std::getline(std::cin, author_name);
                addAuthor(author_name);
                std::cout << "\033[1;32mAuthor added successfully!\033[0m\n";
                break;
            }
            case 6:
                listAuthorsAndBooks();
                break;
            case 7: {
                std::string borrower_name;
                std::cout << "\033[1;34mEnter borrower name: \033[0m";
                std::cin.ignore();
                std::getline(std::cin, borrower_name);
                registerBorrower(borrower_name);
                std::cout << "\033[1;32mBorrower registered successfully!\033[0m\n";
                break;
            }
            case 8:
                listBorrowersAndBooks();
                break;
            case 9: {
                int book_id, borrower_id;
                std::string borrow_date;
                std::cout << "\033[1;34mEnter book ID to borrow: \033[0m";
                std::cin >> book_id;
                std::cout << "\033[1;34mEnter borrower ID: \033[0m";
                std::cin >> borrower_id;
                std::cout << "\033[1;34mEnter borrow date (YYYY-MM-DD): \033[0m";
                std::cin.ignore();
                std::getline(std::cin, borrow_date);
                recordBorrowing(book_id, borrower_id, borrow_date);
                std::cout << "\033[1;32mBorrowing recorded successfully!\033[0m\n";
                break;
            }
            case 10: {
                int book_id;
                std::cout << "\033[1;34mEnter book ID to return: \033[0m";
                std::cin >> book_id;
                returnBook(book_id);
                std::cout << "\033[1;32mBook returned successfully!\033[0m\n";
                break;
            }
            case 11:
                testFunctions();
                break;
            case 12:
                std::cout << "\033[1;32mLogging out...\033[0m\n";
                if (!authenticate()) {
                    return 1; // Exit if authentication fails after logout
                }
                break;
            case 0:
                std::cout << "\033[1;32mThank you for using the Library Management System. Goodbye!\033[0m\n";
                break;
            default:
                std::cout << "\033[1;31mInvalid choice. Please try again.\033[0m\n";
                break;
        }
        std::cout << "\nPress Enter to continue...";
        std::cin.ignore();
        std::cin.get();
    } while (choice != 0);

    return 0;
}
