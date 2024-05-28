/*
    books.cpp 
    Author: Dristi Bhugun <db1178@live.mdx.ac.uk>
    Created: 30/12/23
    Updated: 08/01/24
*/

#include "books.h"
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <fstream>
#include <sstream>

// Constructor
Book::Book(const std::string& id, const std::string& name, int pageCount,
           const std::string& authorFirstName, const std::string& authorLastName,
           const std::string& bookType)
    : id(id), name(name), pageCount(pageCount), authorFirstName(authorFirstName),
      authorLastName(authorLastName), bookType(bookType) {

}

std::string Book::getID() const {
    return id;
}

std::string Book::getName() const {
    return name;
}

int Book::getPageCount() const {
    return pageCount;
}

std::string Book::getAuthorFirstName() const {
    return authorFirstName;
}

std::string Book::getAuthorLastName() const {
    return authorLastName;
}

std::string Book::getBookType() const {
    return bookType;
}

std::string Book::getDueDate() const {
    return dueDate; 
}

std::vector<Book> CSVReader::readCSV(const std::string& filename) {
    std::vector<Book> books;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return books;
    }

    std::string line;
    std::getline(file, line); 

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string token;
        Book book;

        // Read the line and store the values in the book object
        std::getline(ss, book.id, ',');
        std::getline(ss, book.name, ',');
        ss >> book.pageCount;
        ss.ignore();
        std::getline(ss, book.authorFirstName, ',');
        std::getline(ss, book.authorLastName, ',');
        std::getline(ss, book.bookType, ',');

        books.push_back(book);
    }

    file.close();
    return books;
}


//function to display books
void displayBooks(const std::vector<Book>& books, const std::unordered_set<std::string>& filterTypes) {
    // Check if books were successfully read
    if (books.empty()) {
        std::cout << "No books found or failed to read the file." << std::endl;
        return;
    }

    std::cout << "Book Details:" << std::endl;
    for (const auto& book : books) {
        // If filterTypes is empty or the book type is in the filterTypes, display the book
        if (filterTypes.empty() || filterTypes.find(book.bookType) != filterTypes.end()) {
            std::cout << " Book ID: " << book.id 
                      << "\n Book Name: " << book.name
                      << "\n Page Count: " << book.pageCount 
                      << "\n Author: " << book.authorFirstName << " " << book.authorLastName 
                      << "\n Book Type: " << book.bookType 
                      << "\n -----------------" << std::endl;
        }
    }
}

//function to check if book is available or not
bool isBookAvailable(const std::vector<Book>& books, int bookId, const std::unordered_set<std::string>& filterBooks) {
    auto it = std::find_if(books.begin(), books.end(), [bookId, &filterBooks](const Book& book) {
        return book.id == std::to_string(bookId) && filterBooks.find(book.bookType) != filterBooks.end();
    });

    return it != books.end();
}
