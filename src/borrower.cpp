#include <string>
#include <iostream>
#include "database.h"

void registerBorrower(const std::string &name) {
    auto& storage = Database::getStorage();
    storage.insert(Borrower{0, name});
    std::cout << "Borrower registered successfully.\n";
}

void listBorrowersAndBooks() {
    auto& storage = Database::getStorage();

    try {
        auto borrowers = storage.get_all<Borrower>();

        for (const auto &borrower : borrowers) {
            std::cout << "Borrower ID: " << borrower.id << ", Name: " << borrower.name << "\nBooks:\n";
            auto records = storage.get_all<BorrowRecord>(sqlite_orm::where(sqlite_orm::c(&BorrowRecord::borrower_id) == borrower.id));

            if (!records.empty()) {
                for (const auto &record : records) {
                    auto book = storage.get<Book>(record.book_id);
                    std::cout << "  - " << book.title << " (Borrowed: " << record.borrow_date << ")\n";
                }
            } else {
                std::cout << "  - No borrowed books.\n";
            }
        }
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

