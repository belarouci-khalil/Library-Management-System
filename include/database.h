#ifndef DATABASE_H
#define DATABASE_H

#include <../lib/sqlite_orm/include/sqlite_orm/sqlite_orm.h>
#include "book.h"
#include "author.h"
#include "borrower.h"
#include "borrow_record.h"
// Declarations for book-related functions
void addBook(const std::string &title, int author_id, const std::string &genre);
void listBooks();
void addAuthor(const std::string &name) ;
void listAuthors();
void listBorrowers();
void recordBorrowing(int bookId, int borrowerId, const std::string &borrowDate);
void returnBook(int bookId);
void listBorrowersAndBooks();
void borrowBook(int bookId);
void borrowBorrower(int borrowerId);
void registerBorrower(const std::string &name);
void updateBook(int bookId, const std::string &newTitle, int newAuthorId, const std::string &newGenre);
void deleteBook(int bookId);
void listAuthorsAndBooks();
class Database {
public:
    static auto& getStorage() {
        using namespace sqlite_orm;
        static auto storage = make_storage("library.db",
            make_table("books",
                make_column("id", &Book::id, primary_key()),
                make_column("title", &Book::title),
                make_column("author_id", &Book::author_id),
                make_column("genre", &Book::genre),
                make_column("is_borrowed", &Book::is_borrowed)),
            make_table("authors",
                make_column("id", &Author::id, primary_key()),
                make_column("name", &Author::name)),
            make_table("borrowers",
                make_column("id", &Borrower::id, primary_key()),
                make_column("name", &Borrower::name),
                make_column("email", &Borrower::email)),
            make_table("borrow_records",
                make_column("id", &BorrowRecord::id, primary_key()),
                make_column("book_id", &BorrowRecord::book_id),
                make_column("borrower_id", &BorrowRecord::borrower_id),
                make_column("borrow_date", &BorrowRecord::borrow_date),
                make_column("return_date", &BorrowRecord::return_date))
        );

        storage.sync_schema();
        return storage;
    }
};

#endif // DATABASE_H
