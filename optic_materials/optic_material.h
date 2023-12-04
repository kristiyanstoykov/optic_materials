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
    //Optic_Material(const Optic_Material &om);
    std::string getType() const;
    void setType(std::string type);
    double getWidth()const;
    void setWidth(double width);
    double getDiopter()const;
    void setDiopter(double diopter);
    std::string getName()const;
    void setName(std::string name);
    double getPrice()const;
    void setPrice(double price);

    ostream& print(ostream& output) const override;
    istream& input(istream& input) override;
    void to_json(json& j) const override;
    void from_json(json& j) override;
};

#endif
