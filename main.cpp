/*
    main.cpp 
    Author: Dristi Bhugun <db1178@live.mdx.ac.uk>
    Created: 22/12/23
    Updated: 08/01/24
*/

#include "books.h"
#include "member.h"
#include "person.h"
#include "librarian.h"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>


int main() {
    // csv file name to load books
    std::string filename = "library_books.csv"; 
    std::vector<Book> books = CSVReader::readCSV(filename);
    if (books.empty()) {
        std::cout << "No books found or failed to read the file." << std::endl;
        return 1;
    }
    // adding filter to view only selected type of generes
    std::unordered_set<std::string> filterBooks = {
    "Science fiction", "Satire", "Drama", "Action and Adventure", 
        "Romance", "Mystery", "Horror", "Health", "Guide", "Diaries", 
        "Comics", "Journals", "Biographies", "Fantasy", "History", 
        "Science", "Art"
    };

    // creating sample members
    std::vector<Member> members;
    members.emplace_back(1001, "Shika Db", "Port Louis, Maurituis", "shika.db@gmail.com");
    members.emplace_back(1002, "Sushmeeta Poudel", "New Orleans, USA", "sush390@gmail.com");
    members.emplace_back(1003, "Harley Quinn", "Pine St, New York, USA", "quinn911@gmail.com");

    // creating a librarian
    Librarian librarian(299281, "Dristi Bhugun", "Port Louis, Mauritius", "dristi.bs@gmail.com", 45000);

    int choice;
    // menu for library management system
    do {
        std::cout << "\nLibrary Management System\n";
        std::cout << "1. Member Details\n";
        std::cout << "2. Books Details\n";
        std::cout << "3. Issue Books\n";
        std::cout << "4. My Profile\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int memberChoice;
                do {
                    std::cout << "\nMember\n";
                    std::cout << "1. Create Member\n";
                    std::cout << "2. View All Members\n";
                    std::cout << "3. Back\n";
                    std::cout << "Enter your choice: ";
                    std::cin >> memberChoice;

                    switch (memberChoice) {
                        case 1:
                           librarian.addMember(members);
                            break;
                        case 2:
                            librarian.displayMemberInfo(members);
                            break;
                        case 3:
                            std::cout << "Returning to Main Menu.\n";
                            break;
                        default:
                            std::cout << "Invalid choice. Please try again.\n";
                    }
                } while (memberChoice != 3);
                break;
            }
            case 2: {
                    int bookChoice;
                    do {
                        std::cout << "\nBooks Menu\n";
                        std::cout << "1. Display All Books\n";
                        std::cout << "2. Display Available Books\n";
                        std::cout << "3. Book availability checker\n";
                        std::cout << "4. Back\n";
                        std::cout << "Enter your choice: ";
                        std::cin >> bookChoice;

                        switch (bookChoice) {
                            case 1:
                                displayBooks(books);
                                break;
                            case 2:
                                displayBooks(books, filterBooks);
                                break;
                            case 3:
                                int bookId;
                                std::cout << "Enter the Book ID to check availability: ";
                                std::cin >> bookId;

                                if (isBookAvailable(books, bookId, filterBooks)) {
                                    std::cout << "\nBook with ID " << bookId << " is available." << std::endl;
                                } else {
                                    std::cout << "\nBook with ID " << bookId << " is not available." << std::endl;
                                }
                                break;
                            case 4:
                                std::cout << "Returning to Main Menu.\n";
                                break;
                            default:
                                std::cout << "Invalid choice. Please try again.\n";
                        }
                    } while (bookChoice != 4);
                    break;
                }

            case 3:
                int issueChoice;
                do {
                    std::cout << "\nIssue Menu\n";
                    std::cout << "1. Issue Book\n";
                    std::cout << "2. Display Borrowed Books\n";
                    std::cout << "3. Return Book\n";
                    std::cout << "4. Check fine\n";
                    std::cout << "5. Back\n";
                    std::cout << "Enter your choice: ";
                    std::cin >> issueChoice;

                    switch (issueChoice) {
                        case 1:
                            {
                                int memberID;
                                std::string bookID;
                                std::cout << "Enter the Member ID: ";
                                std::cin >> memberID;
                                std::cout << "Enter the Book ID: ";
                                std::cin >> bookID;
                                librarian.issueBook(books, members, memberID, bookID);
                            }
                            break;
                        case 2:
                            {
                                int borrowedID;
                                std::cout << "Enter the Member ID: ";
                                std::cin >> borrowedID;
                                librarian.displayBorrowedBooks(members, borrowedID);
                            }
                            break;
                        case 3:
                            {
                                int memberID;
                                std::string bookID;
                                std::cout << "Enter the Member ID: ";
                                std::cin >> memberID;
                                std::cout << "Enter the Book ID: ";
                                std::cin >> bookID;
                                librarian.returnBook(books, members, memberID, bookID);
                            }
                            break;
                        case 4:
                            {
                                int memberID;
                                std::cout << "Enter Member ID to calculate fine: ";
                                std::cin >> memberID;
                                librarian.calcFine(members, memberID);
                            }
                            break;
                        case 5:
                            std::cout << "Returning to Main Menu.\n";
                            break;
                        default:
                            std::cout << "Invalid choice. Please try again.\n";
                    }
                } while (issueChoice != 5);
                break;
            case 4:
                int profileChoice;
                do{
                    std::cout << "\n------Profile Menu----\n";
                    std::cout << "1. Display Profile\n";
                    std::cout << "2. Edit Profile\n";
                    std::cout << "3. View Salary\n";
                    std::cout << "4. Back\n";
                    std::cout << "Enter your choice: ";
                    std::cin >> profileChoice;

                    switch (profileChoice) {
                        case 1:
                            std::cout << "\n---------Librarian Profile----------" << std::endl;
                            std::cout << "ID: " << librarian.getStaffID() << std::endl;
                            std::cout << "Name: " << librarian.getName() << std::endl;
                            std::cout << "Address: " << librarian.getAddress() << std::endl;
                            std::cout << "E-mail: " << librarian.getEmail() << std::endl;
                            std::cout << "Salary: " << librarian.getSalary() << std::endl;
                            std::cout << "----------XXX---------" << std::endl;
                            break;
                        case 2:
                            int profileChoice;
                            do{
                                std::cout << "\n------Edit Profile----\n";
                                std::cout << "1. Edit Staff ID\n";
                                std::cout << "2. Edit Name\n";
                                std::cout << "3. Edit Address\n";
                                std::cout << "4. Edit Email\n";
                                std::cout << "5. Edit Salary\n";
                                std::cout << "6. Back\n";
                                std::cout << "Enter your choice: ";
                                std::cin >> profileChoice;
                            switch(profileChoice){
                            case 1:
                                int newStaffID;
                                std::cout << "Enter new Staff ID: ";
                                std::cin >> newStaffID;
                                librarian.setStaffID(newStaffID);
                                std::cout << "\nStaff ID updated successfully.\n";
                                break;
                            case 2:
                                {
                                    std::string newStaffName;
                                    std::cout << "Enter new Name: ";
                                    std::cin.ignore(); 
                                    std::getline(std::cin, newStaffName); 
                                    librarian.setName(newStaffName);
                                    std::cout << "\nName updated successfully.\n";
                                }
                                break;
                            case 3:
                                {
                                    std::string newStaffAddress;
                                    std::cout << "Enter new Address: ";
                                    std::cin.ignore(); 
                                    std::getline(std::cin, newStaffAddress); 
                                    librarian.setAddress(newStaffAddress);
                                    std::cout << "\nAddress updated successfully.\n";
                                }
                                break;
                            case 4:
                                {
                                    std::string newStaffEmail;
                                    std::cout << "Enter new Email: ";
                                    std::cin.ignore(); 
                                    std::getline(std::cin, newStaffEmail); 
                                    librarian.setEmail(newStaffEmail);
                                    std::cout << "\nEmail updated successfully.\n";
                                }
                                break;
                            case 5:
                                int newStaffSalary;
                                std::cout << "Enter new Salary: ";
                                std::cin >> newStaffSalary;
                                librarian.setSalary(newStaffSalary);
                                std::cout << "\nSalary updated successfully.\n";
                                break;
                            case 6:
                                std::cout << "Returning to Main Menu.\n";
                                break;
                            }
                            }while(profileChoice != 6);
                            break;
                        case 3:
                            std::cout << "\nSalary: " << librarian.getSalary() << std::endl;
                            break;
                        case 4:
                            std::cout << "Returning to Main Menu.\n";
                            break;
                        default:
                            std::cout << "Invalid choice. Please try again.\n";
                    }
                }while (profileChoice != 4);
                break;
            case 5:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}



