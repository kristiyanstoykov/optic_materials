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
    double profit_margin;

public:
    Supplier();
    Supplier(std::string bulstat, std::string name, std::string location, std::string phone, double profit_margin);
    Supplier(const Supplier &sup);
    std::string getBulstat();
    void setBulstat(std::string bulstat);
    std::string getName();
    void setName(std::string name);
    std::string getLocation();
    void setLocation(std::string location);
    std::string getPhone();
    void setPhone(std::string phone);
    double getProfitMargin();
    void setProfitMargin(double getProfitMargin);


    ostream& print(ostream& output) const override;
    istream& input(istream& input) override;
    void to_json(nlohmann::json& j) const override;
    void from_json(json& j) override;
};

#endif
