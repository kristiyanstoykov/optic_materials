#ifndef OPTIC_MATERIAL_H
#define OPTIC_MATERIAL_H

#include <iostream>
#include <string>
#include "base.h"

using namespace std;

class Optic_Material : public Base
{
private:
    string type;
    double width;
    double diopter;
    string name;
    double price;

public:
    Optic_Material();
    Optic_Material(std::string type, double width, double diopter, std::string name, double price);
    std::string getType();
    void setType(std::string type);
    double getWidth();
    void setWidth(double width);
    double getDiopter();
    void setDiopter(double diopter);
    std::string getName();
    void setName(std::string name);
    double getPrice();
    void setPrice(double price);

    ostream& print(ostream& output) const override;
    istream& input(istream& input) override;
    void to_json(json& j) const override;
    void from_json(json& j) override;
};

#endif
