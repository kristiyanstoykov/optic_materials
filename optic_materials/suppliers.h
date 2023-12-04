#pragma once
#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#include <vector>
#include <fstream>
#include "supplier.h"
#include "base.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Suppliers : public Base
{
private:
    vector<Supplier> suppliers;

public:
    // Constructor
    Suppliers() = default;

    void addSupplier(const Supplier& supplier);
    vector<Supplier> getSuppliers();
    Supplier getSupplierByIndex(int index) const;
    int getSize() const;

    void print_on_one_line() const;

    ostream& print(ostream& output) const override;
    istream& input(istream& input) override;
    void to_json(json& j) const override;
    void from_json(json& j) override;
};

#endif