/*
    member.cpp 
    Author: Dristi Bhugun <db1178@live.mdx.ac.uk>
    Created: 30/12/23
    Updated: 08/01/24
*/

#include "member.h"

// Constructor
Member::Member(int memberID, const std::string& name, const std::string& address, const std::string& email)
    : memberID(memberID), name(name), address(address), email(email) {}

int Member::getMemberID() const {
    return memberID;
}

std::string Member::getName() const {
    return name;
}

std::string Member::getAddress() const {
    return address;
}

std::string Member::getEmail() const {
    return email;
}

std::vector<Book> Member::getBooksBorrowed() const {
    return booksLoaned;
}

void Member::setBooksBorrowed(const Book& book) {
    booksLoaned.push_back(book);
}
void Member::borrowBook(const Book& book) {
    booksLoaned.push_back(book);
}

// function to display borrowed books
void Member::displayBorrowedBooks() const {
    for (const auto& book : booksLoaned) {
        std::cout << " Book ID: " << book.getID() 
        << "\n Title: " << book.getName()
        << "\n Author: " << book.getAuthorFirstName() 
        << " " << book.getAuthorLastName()
        << "\n Page count: " << book.getPageCount() << std::endl;
    }
}
// function to return book
bool Member::returnBook(const std::string& bookID) {
    auto it = std::find_if(booksLoaned.begin(), booksLoaned.end(), [bookID](const Book& book) {
        return book.getID() == bookID;
    });

    if (it != booksLoaned.end()) {
        booksLoaned.erase(it);
        // Book returned successfully
        return true; 
    } else {
        // Book not found in the member's borrowed books
        return false; 
    }
}