#ifndef _MEMBER_H_
#define _MEMBER_H_

/*
    member.h 
    Author: Dristi Bhugun <db1178@live.mdx.ac.uk>
    Created: 22/12/23
    Updated: 08/01/23
*/

#include <vector>
#include <string>
#include "books.h"
#include <iostream>

class Member {
private:
    int memberID;
    std::string name;
    std::string address;
    std::string email;
    std::vector<Book> booksLoaned;

public:
    Member(int memberID, const std::string& name, const std::string& address, const std::string& email);

    int getMemberID() const;
    std::string getName() const;
    std::string getAddress() const;
    std::string getEmail() const;
    std::vector<Book> getBooksBorrowed() const;
    void setBooksBorrowed(const Book& book);
    void borrowBook(const Book& book);
    void displayBorrowedBooks() const;
    bool returnBook(const std::string& bookID);

};

#endif