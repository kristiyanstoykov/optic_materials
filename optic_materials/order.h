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
    void setId(int id);
    int getId();
    vector<Optic_Material> getMaterials();
    void addMaterial(const Optic_Material& material);
    void addSupplier(const Supplier& supplier);
    Supplier getSupplier();
    double getTotal();

    ostream& print(ostream& output) const override;
    istream& input(istream& input) override;
    void to_json(json& j) const override;
    void from_json(json& j) override;
};

#endif
