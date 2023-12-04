#include "order.h"

Order::Order() {}

Order::Order(int id, vector<Optic_Material> materials, Supplier supplier)
{
    if (id < 0)
    {
        throw std::invalid_argument("id can't be less than zero!");
    }

    this->id = id;
    this->materials = materials;
    this->supplier = supplier;
}

void Order::setId(int id)
{
    this->id = id;
}

int Order::getId()
{
    return this->id;
}

vector<Optic_Material> Order::getMaterials()
{
    return this->materials;
}

void Order::addMaterial(const Optic_Material& material) {
    this->materials.push_back(material);
}

Supplier Order::getSupplier()
{
    return this->supplier;
}

void Order::addSupplier(const Supplier& supplier) {
    this->supplier = supplier;
}

double Order::getTotal() {
    double total = 0;

    for (auto& material : this->materials) {
        total += material.getPrice();
    }

    total *= 100 / this->supplier.getProfitMargin();

    return total;
}

ostream& Order::print(ostream& output) const
{
    output << "ID: " << id << "\n";
    output << "Number of materials: " << materials.size() << "\n";
    for (const auto& material : materials)
    {
        output << material; // Assuming Optic_Material has a print method
    }
    output << supplier;
    return output;
}

istream& Order::input(istream& input)
{
    string line;

    getline(input, line);
    this->id = stoi(line.substr(line.find(": ") + 2));

    int num_of_materials;
    getline(input, line);
    num_of_materials = stoi(line.substr(line.find(": ") + 2));
    this->materials.clear();
    for (int i = 0; i < num_of_materials; ++i)
    {
        Optic_Material material;
        input >> material;
        this->materials.push_back(material);
    }

    input >> this->supplier;

    return input;
}

void Order::to_json(json& j) const
{
    j = json{
        {"id", id},
        {"numberOfMaterials", materials.size()},
        {"materials", json::array()}
    };

    // Serialize each material
    for (const auto& material : materials) {
        json materialJson;
        material.to_json(materialJson);
        j["materials"].push_back(materialJson);
    }

    // Serialize supplier
    json supplierJson;
    supplier.to_json(supplierJson);
    j["supplier"] = supplierJson;
}

void Order::from_json(json& j) {
    // Deserialize ID
    this->id = j.at("id").get<int>();

    // Clear existing materials
    this->materials.clear();

    // Deserialize materials
    auto& materials_json = j.at("materials");
    for (auto& mat: materials_json) {
        Optic_Material material;
        material.from_json(mat);
        materials.push_back(material);
    }

    // Deserialize supplier
    supplier.from_json(j.at("supplier"));
}