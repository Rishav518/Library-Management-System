#ifndef _BOOKS_H_
#define _BOOKS_H_

/*
    books.h 
    Author: Dristi Bhugun <db1178@live.mdx.ac.uk>
    Created: 22/12/23
    Updated: 08/01/24
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

struct Book {
    // Member variables
    std::string id;
    std::string name;
    int pageCount;
    std::string authorFirstName;
    std::string authorLastName;
    std::string bookType;
    std::string dueDate;

    // Constructors
    Book() : pageCount(0) {}
    Book(const std::string& id, const std::string& name, int pageCount,
         const std::string& authorFirstName, const std::string& authorLastName,
         const std::string& bookType);

    std::string getID() const;
    std::string getName() const;
    int getPageCount() const;
    std::string getAuthorFirstName() const;
    std::string getAuthorLastName() const;
    std::string getBookType() const;
    std::string getDueDate() const;
    std::string setDueDate() const;
};

class CSVReader {
public:
    static std::vector<Book> readCSV(const std::string& filename);
};

void displayBooks(const std::vector<Book>& books, const std::unordered_set<std::string>& filterTypes = {});
bool isBookAvailable(const std::vector<Book>& books, int bookId, const std::unordered_set<std::string>& filterBooks);

#endif

