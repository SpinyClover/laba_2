#include <iostream>
#include <string>

class NOTE {
private:
    std::string lastName;
    std::string firstName;
    std::string phoneNumber = "";
    int birthDate[3];

public:
    NOTE();

    NOTE(const std::string& last, const std::string& first, const std::string& phone, int day, int month, int year);

    NOTE(const NOTE& other);

    ~NOTE() {
        std::cout << "Destructor called for object" << std::endl;
    }

    NOTE& operator=(const NOTE& other);

    std::string getLastName() const;

    std::string getFirstName() const;

    std::string getPhoneNumber() const;

    int getDayOfBirth() const;

    int getMonthOfBirth() const;

    int getYearOfBirth() const;

    friend std::ostream& operator<<(std::ostream& os, const NOTE& note);

    friend std::istream& operator>>(std::istream& is, NOTE& note);
};
