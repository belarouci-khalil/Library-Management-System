#include "database.h"
#include <iostream>

// Implementation for adding a book
void addBook(const std::string &title, int author_id, const std::string &genre) {
    auto& storage = Database::getStorage();
    storage.insert(Book{0, title, author_id, genre, false});
    std::cout << "Book added successfully.\n";
}

// Implementation for listing books
void listBooks() {
    auto& storage = Database::getStorage();
    auto books = storage.get_all<Book>();
    for (const auto &book : books) {
        std::cout << "ID: " << book.id
                  << ", Title: " << book.title
                  << ", Genre: " << book.genre
                  << ", Borrowed: " << (book.is_borrowed ? "Yes" : "No") << std::endl;
    }
}
void updateBook(int bookId, const std::string &newTitle, int newAuthorId, const std::string &newGenre) {
    auto& storage = Database::getStorage();
    auto book = storage.get<Book>(bookId);
    book.title = newTitle;
    book.author_id = newAuthorId;
    book.genre = newGenre;
    storage.update(book);
    std::cout << "Book updated successfully.\n";
}

void deleteBook(int bookId) {
    auto& storage = Database::getStorage();
    auto book = storage.get<Book>(bookId);
    if (book.is_borrowed) {
        std::cout << "Cannot delete a borrowed book.\n";
    } else {
        storage.remove<Book>(bookId);
        std::cout << "Book deleted successfully.\n";
    }
}
