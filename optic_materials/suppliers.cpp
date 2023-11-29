#include "suppliers.h"

// Method to add an supplier
void Suppliers::addSupplier(const Supplier& supplier) {
    this->suppliers.push_back(supplier);
}

// Method to get all suppliers
vector<Supplier> Suppliers::getSuppliers() {
    return this->suppliers;
}

ostream& Suppliers::print(ostream& output) const {
    output << "Total Suppliers: " << this->suppliers.size() << "\n";
    for (const auto& supplier : this->suppliers) {
        output << supplier;
    }
    return output;
}

istream& Suppliers::input(istream& input) {
    this->suppliers.clear();
    string line;
    getline(input, line);
    int order_size = stoi(line.substr(line.find(": ") + 2));

    for (int i = 0; i < order_size; ++i)
    {
        Supplier supplier;
        input >> supplier;
        this->suppliers.push_back(supplier);
    }

    return input;
}

void Suppliers::to_json(json& j) const {
    // Start with an empty array
    j = json::array();

    // Serialize each supplier
    for (const auto& supplier : this->suppliers) {
        json orderJson;
        supplier.to_json(orderJson);
        j.push_back(orderJson);
    }
}

void Suppliers::from_json(json& j) {
    // Clear existing suppliers
    this->suppliers.clear();

    // Deserialize each JSON object into an Supplier and add to the vector
    for (auto& orderJson : j) {
        Supplier supplier;
        supplier.from_json(orderJson);
        this->suppliers.push_back(supplier);
    }
}