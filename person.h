#ifndef _PERSON_H_
#define _PERSON_H_

/*
    person.h 
    Author: Dristi Bhugun <db1178@live.mdx.ac.uk>
    Created: 22/12/23
    Updated: 08/01/23
*/

#include <string>
#include <iostream>
class Person {
private:
    std::string name;
    std::string address;
    std::string email;

public:
    std::string getName() const;
    void setName(std::string name);
    std::string getAddress() const;
    void setAddress(std::string address);
    std::string getEmail() const;
    void setEmail(std::string email);
};

#endif
