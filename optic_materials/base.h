#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

class Base
{
private:
    virtual ostream& print(ostream& output) const = 0;
    virtual istream& input(istream& input) = 0;
    virtual void to_json(json& j) const = 0;
    virtual void from_json(json& j) = 0;

public:
    virtual ~Base() {} // Virtual destructor
    friend ostream& operator<<(ostream& output, const Base& base);
    friend istream& operator>>(istream& input, Base& base);
};

#endif
    