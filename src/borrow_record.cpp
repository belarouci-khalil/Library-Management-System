#include <string>
#include <iostream>
#include "database.h"

void recordBorrowing(int bookId, int borrowerId, const std::string &borrowDate) {
    auto& storage = Database::getStorage();
    auto book = storage.get<Book>(bookId);
    if (book.is_borrowed) {
        std::cout << "Book is already borrowed.\n";
    } else {
        book.is_borrowed = true;
        storage.update(book);
        storage.insert(BorrowRecord{0, bookId, borrowerId, borrowDate, ""});
        std::cout << "Borrowing recorded successfully.\n";
    }
}

void returnBook(int bookId) {
    auto& storage = Database::getStorage();
    auto book = storage.get<Book>(bookId);
    if (!book.is_borrowed) {
        std::cout << "Book is not currently borrowed.\n";
    } else {
        book.is_borrowed = false;
        storage.update(book);
        auto record = storage.get_all<BorrowRecord>(
            sqlite_orm::where(sqlite_orm::c(&BorrowRecord::book_id) == bookId && sqlite_orm::c(&BorrowRecord::return_date) == ""));
        record[0].return_date = "Today"; // Replace with actual return date logic
        storage.update(record[0]);
        std::cout << "Book returned successfully.\n";
    }
}
