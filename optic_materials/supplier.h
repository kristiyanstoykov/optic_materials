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
    //Supplier(const Supplier &sup);
    std::string getBulstat() const;
    void setBulstat(std::string bulstat);
    std::string getName() const;
    void setName(std::string name);
    std::string getLocation() const;
    void setLocation(std::string location);
    std::string getPhone() const;
    void setPhone(std::string phone);
    double getProfitMargin() const;
    void setProfitMargin(double getProfitMargin);


    ostream& print(ostream& output) const override;
    istream& input(istream& input) override;
    void to_json(nlohmann::json& j) const override;
    void from_json(json& j) override;
};

#endif
