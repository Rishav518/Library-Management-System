#ifndef _LIBRARIAN_H_
#define _LIBRARIAN_H_

/*
    librarian.h 
    Author: Dristi Bhugun <db1178@live.mdx.ac.uk>
    Created: 22/12/23
    Updated: 08/01/24
*/

#include <string>
#include <vector>
#include <chrono>
#include <algorithm>
#include "member.h"
#include "books.h"

class Librarian {
public:
    // Constructor
    Librarian(int staffId, std::string name, std::string address, std::string email, int salary);

    int getStaffID() const;
    std::string getName() const;
    std::string getAddress() const;
    std::string getEmail() const;
    int getSalary() const;
    void addMember(std::vector<Member>&);
    void issueBook(std::vector<Book>& books, std::vector<Member>& members, int memberID, const std::string& bookID);        
    void displayBorrowedBooks(const std::vector<Member>& members, int memberID);
    void returnBook(std::vector<Book>& books, std::vector<Member>& members, int memberID, const std::string& bookID);
    void calcFine(const std::vector<Member>& members, int memberID);
    
   
    void setStaffID(int staffId);
    void displayMemberInfo(const std::vector<Member>& members);
    void setName(const std::string& name);
    void setAddress(const std::string& address);
    void setEmail(const std::string& email);
    void setSalary(int salary);
    

private:
    int staffId;
    std::string name;
    std::string address;
    std::string email;
    int salary;
};



#endif
