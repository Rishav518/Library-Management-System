/*
    librarian.cpp 
    Author: Dristi Bhugun <db1178@live.mdx.ac.uk>
    Created: 30/12/23
    Updated: 08/01/24
*/
#include "librarian.h"
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <string>
#include <chrono>

// Constructor
Librarian::Librarian(int staffId, std::string name, std::string address, std::string email, int salary)
    : staffId(staffId), name(name), address(address), email(email), salary(salary) {}

int Librarian::getStaffID() const {
    return staffId;
}

std::string Librarian::getName() const {
    return name;
}

std::string Librarian::getAddress() const {
    return address;
}

std::string Librarian::getEmail() const {
    return email;
}

int Librarian::getSalary() const {
    return salary;
}

void Librarian::setStaffID(int staffId) {
    this->staffId = staffId;
}

void Librarian::setName(const std::string& name) {
    this->name = name;
}

void Librarian::setAddress(const std::string& address) {
    this->address = address;
}

void Librarian::setEmail(const std::string& email) {
    this->email = email;
}

void Librarian::setSalary(int salary) {
    this->salary = salary;
}

//function to add members
void Librarian::addMember(std::vector<Member>& members) {
    int count;
    std::cout << "Number of members you want to add: ";
    std::cin >> count;
    std::cin.ignore(); 

    for (int i = 0; i < count; ++i) {
        int memberID;
        std::string name, address, email;

        std::cout << "Enter details for new member " << (i + 1) << ":\n";
        std::cout << "Member ID (Integer): ";
        std::cin >> memberID;
        std::cin.ignore(); // To consume the newline character

        std::cout << "Name: ";
        std::getline(std::cin, name);

        std::cout << "Address: ";
        std::getline(std::cin, address);


        std::cout << "Email: ";
        std::getline(std::cin, email);

        members.emplace_back(memberID, name, address, email);

        std::cout << "Member added successfully!\n";
    }
}

// function to display members
void Librarian::displayMemberInfo(const std::vector<Member>& members) {
    std::cout << "\n-----Member Information-----" << std::endl;
    for (const auto& member : members) {
        std::cout << "\n Member ID: " << member.getMemberID()
                  << "\n Name: " << member.getName() 
                  << "\n Address: " << member.getAddress()
                  << "\n Email: " << member.getEmail()
                  << "\n---------------" << std::endl;
    }
}

// function to issue a book to member
void Librarian::issueBook(std::vector<Book>& books, std::vector<Member>& members, int memberID, const std::string& bookID) {
    auto memberIt = std::find_if(members.begin(), members.end(), [memberID](const Member& member) {
        return member.getMemberID() == memberID;
    });

    auto bookIt = std::find_if(books.begin(), books.end(), [bookID](const Book& book) {
        return book.getID() == bookID;
    });

    if (memberIt != members.end() && bookIt != books.end()) {
        memberIt->borrowBook(*bookIt);
        std::cout << "\nBook with ID " << bookID << " issued to member with ID " << memberID << std::endl;
    } else {
        //If member or book is not found
        std::cout << "Member or book not found." << std::endl;
    }
}

// function to display borrowed books 
void Librarian::displayBorrowedBooks(const std::vector<Member>& members, int memberID) {
    auto it = std::find_if(members.begin(), members.end(), [memberID](const Member& member) {
        return member.getMemberID() == memberID;
    });

    if (it != members.end()) {
        it->displayBorrowedBooks();
    } else {
        std::cout << "Member not found." << std::endl;
    }
}

// function to calculate fine 
void Librarian::calcFine(const std::vector<Member>& members, int memberID) {
    auto memberIt = std::find_if(members.begin(), members.end(), [memberID](const Member& member) {
        return member.getMemberID() == memberID;
    });

    if (memberIt != members.end()) {
        int totalFine = 0;
        std::cout << "\nTotal fine for member " << memberID << ": $" << totalFine << std::endl;
    } else {
        std::cout << "Member not found." << std::endl;
    }
}

// function to return book
void Librarian::returnBook(std::vector<Book>& books, std::vector<Member>& members, int memberID, const std::string& bookID) {
    auto memberIt = std::find_if(members.begin(), members.end(), [memberID](const Member& member) {
        return member.getMemberID() == memberID;
    });

    if (memberIt != members.end() && memberIt->returnBook(bookID)) {
        auto bookIt = std::find_if(books.begin(), books.end(), [bookID](const Book& book) {
            return book.getID() == bookID;
        });

        if (bookIt != books.end()) {
            std::cout << "\nBook " << bookID << " returned successfully." << std::endl;
        } else {
            std::cout << "\nBook not found in the library." << std::endl;
        }
    } else {
        std::cout << "\nMember not found or book not borrowed by member." << std::endl;
    }
}


