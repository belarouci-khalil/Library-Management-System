#include <string>
#include <iostream>
#include "database.h"

void addAuthor(const std::string &name) {
    auto& storage = Database::getStorage();
    storage.insert(Author{0, name});
    std::cout << "Author added successfully.\n";
}

void listAuthorsAndBooks() {
    auto& storage = Database::getStorage();
    auto authors = storage.get_all<Author>();
    for (const auto &author : authors) {
        std::cout << "Author ID: " << author.id << ", Name: " << author.name << "\nBooks:\n";
        auto books = storage.get_all<Book>(sqlite_orm::where(sqlite_orm::c(&Book::author_id) == author.id));
        for (const auto &book : books) {
            std::cout << "  - " << book.title << " (Genre: " << book.genre << ")\n";
        }
    }
}
