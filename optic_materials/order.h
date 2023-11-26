#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <vector>
#include "supplier.h"
#include "optic_material.h"

class Order : public Base
{
private:
    int id;
    vector<Optic_Material> materials;
    Supplier supplier;

public:
    Order();
    Order(int id, vector<Optic_Material> materials, Supplier supplier);
    int getId();
    vector<Optic_Material> getMaterials();
    Supplier getSupplier();
    double getTotal();

    ostream& print(ostream& output) const override;
    istream& input(istream& input) override;
    void to_json(json& j) const override;
    void from_json(json& j) override;
};

#endif
