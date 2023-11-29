#include "note.h"

NOTE::NOTE()
{
    std::cout << "Default constructor called for object" << std::endl;
}

NOTE::NOTE(const std::string& last, const std::string& first, const std::string& phone, int day, int month, int year)
{
    lastName = last;
    firstName = first;
    phoneNumber = phone;
    birthDate[0] = day;
    birthDate[1] = month;
    birthDate[2] = year;
    std::cout << "Parameterized constructor called for object" << std::endl;
}

NOTE::NOTE(const NOTE& other)
{
    lastName = other.lastName;
    firstName = other.firstName;
    phoneNumber = other.phoneNumber;
    birthDate[0] = other.birthDate[0];
    birthDate[1] = other.birthDate[1];
    birthDate[2] = other.birthDate[2];
    std::cout << "Copy constructor called for object" << std::endl;
}

NOTE& NOTE::operator=(const NOTE& other)
{
    if (this != &other) {
        lastName = other.lastName;
        firstName = other.firstName;
        phoneNumber = other.phoneNumber;
        birthDate[0] = other.birthDate[0];
        birthDate[1] = other.birthDate[1];
        birthDate[2] = other.birthDate[2];
        std::cout << "Copy assignment operator called for object" << std::endl;
    }
    return *this;
}

std::string NOTE::getLastName() const
{
    return lastName;
}

std::string NOTE::getFirstName() const
{
    return firstName;
}

std::string NOTE::getPhoneNumber() const
{
    return phoneNumber;
}

int NOTE::getDayOfBirth() const
{
    return birthDate[0];
}

int NOTE::getMonthOfBirth() const
{
    return birthDate[1];
}

int NOTE::getYearOfBirth() const
{
    return birthDate[2];
}

std::ostream& operator<<(std::ostream& os, const NOTE& note)
{
    os << "Last Name: " << note.lastName << std::endl;
    os << "First Name: " << note.firstName << std::endl;
    os << "Phone Number: " << note.phoneNumber << std::endl;
    os << "Birth Date: " << note.birthDate[0] << "/" << note.birthDate[1] << "/" << note.birthDate[2] << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, NOTE& note)
{
    std::cout << "Enter Last Name: ";
    is >> note.lastName;
    std::cout << "Enter First Name: ";
    is >> note.firstName;
    std::cout << "Enter Phone Number: ";
    is >> note.phoneNumber;
    std::cout << "Enter Birth Date (day month year): ";
    int day = 1;
    int mouth = 1;
    int year = 1;

    is >> day >> mouth >> year;

    while (!(day > 0 and day <= 31 and mouth > 0 and mouth <= 12 and year > 0 and year < 3000)) {
        std::cout << "Error date format, enter again: ";
        is >> day >> mouth >> year;
    }

    note.birthDate[0] = day;
    note.birthDate[1] = mouth;
    note.birthDate[2] = year;
    return is;
}
