#ifndef BOOK_H
#define BOOK_H

#include <string>

struct Book {
    int id;
    std::string title;
    int author_id;
    std::string genre;
    bool is_borrowed;
};

#endif // BOOK_H
