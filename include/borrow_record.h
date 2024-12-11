#ifndef BORROW_RECORD_H
#define BORROW_RECORD_H

#include <string>

struct BorrowRecord {
    int id;
    int book_id;
    int borrower_id;
    std::string borrow_date;
    std::string return_date;
};

#endif // BORROW_RECORD_H
