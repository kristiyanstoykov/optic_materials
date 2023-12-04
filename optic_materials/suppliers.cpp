#include "suppliers.h"

// Method to add an supplier
void Suppliers::addSupplier(const Supplier& supplier) {
    this->suppliers.push_back(supplier);
}

// Method to get all suppliers
vector<Supplier> Suppliers::getSuppliers() {
    return this->suppliers;
}

void Suppliers::print_on_one_line() const {
    cout << "Optic materials:\n";
    int i = 0;
    for (auto& supplier : this->suppliers) {
        cout << i + 1 << ": " << supplier.getBulstat() << " "
            << i + 1 << ": " << supplier.getName() << " "
            << " " << supplier.getLocation()
            << " " << supplier.getPhone() << " "
            << supplier.getProfitMargin() << '\n';
        i++;
    }
}

Supplier Suppliers::getSupplierByIndex(int index) const {
    if (index >= 0 && index < suppliers.size()) {
        return suppliers[index];
    }
    else {
        throw std::out_of_range("Index is out of range for suppliers vector.");
    }
}

int Suppliers::getSize() const
{
    return (int) this->suppliers.size();
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
    int suppliers_size = stoi(line.substr(line.find(": ") + 2));

    for (int i = 0; i < suppliers_size; ++i)
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
        json suppliersJson;
        supplier.to_json(suppliersJson);
        j.push_back(suppliersJson);
    }
}

void Suppliers::from_json(json& j) {
    // Clear existing suppliers
    this->suppliers.clear();

    // Deserialize each JSON object into an Supplier and add to the vector
    for (auto& suppliersJson : j) {
        Supplier supplier;
        supplier.from_json(suppliersJson);
        this->suppliers.push_back(supplier);
    }
}