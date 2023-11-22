#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <iostream>
#include <string>
#include "base.h"

class Supplier : public Base
{
private:
    std::string bulstat;
    std::string name;
    std::string location;
    std::string phone;

public:
    Supplier();
    Supplier(std::string bulstat, std::string name, std::string location, std::string phone);
    std::string getBulstat();
    void setBulstat(std::string bulstat);
    std::string getName();
    void setName(std::string name);
    std::string getLocation();
    void setLocation(std::string location);
    std::string getPhone();
    void setPhone(std::string phone);

    ostream& print(ostream& output) const override;
    istream& input(istream& input) override;
    void to_json(nlohmann::json& j) const override;
    void from_json(json& j) override;
};

#endif
