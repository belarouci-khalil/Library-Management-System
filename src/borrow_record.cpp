#include <string>
#include <iostream>
#include "database.h"

void recordBorrowing(int bookId, int borrowerId, const std::string &borrowDate) {
    auto& storage = Database::getStorage();

    try {
        auto book = storage.get<Book>(bookId);
        auto borrower = storage.get<Borrower>(borrowerId);

        if (book.is_borrowed) {
            std::cout << "Book is already borrowed.\n";
        } else {
            book.is_borrowed = true;
            storage.update(book);
            storage.insert(BorrowRecord{0, bookId, borrowerId, borrowDate, ""});
            std::cout << "Borrowing recorded successfully.\n";
        }
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}


void returnBook(int bookId) {
    auto& storage = Database::getStorage();

    try {
        auto book = storage.get<Book>(bookId);

        if (!book.is_borrowed) {
            std::cout << "Book is not currently borrowed.\n";
        } else {
            book.is_borrowed = false;
            storage.update(book);
            auto records = storage.get_all<BorrowRecord>(sqlite_orm::where(sqlite_orm::c(&BorrowRecord::book_id) == bookId && sqlite_orm::c(&BorrowRecord::return_date) == ""));

            if (!records.empty()) {
                records[0].return_date = "Today"; // Assuming today's date is used
                storage.update(records[0]);
                std::cout << "Book returned successfully. Record updated.\n";
            } else {
                std::cout << "No borrow record found for this book.\n";
            }
        }
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}
