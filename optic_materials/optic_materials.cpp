#include "optic_materials.h"

// Method to add an supplier
void Optic_Materials::addOpticMaterial(const Optic_Material& optic_material) {
    this->optic_materials.push_back(optic_material);
}

// Method to get all suppliers
vector<Optic_Material> Optic_Materials::getOpticMaterial() {
    return this->optic_materials;
}

ostream& Optic_Materials::print(ostream& output) const {
    output << "Total optic materials: " << this->optic_materials.size() << "\n";
    for (const auto& optic_material : this->optic_materials) {
        output << optic_material;
    }
    return output;
}

istream& Optic_Materials::input(istream& input) {
    this->optic_materials.clear();
    string line;
    getline(input, line);
    int order_size = stoi(line.substr(line.find(": ") + 2));

    for (int i = 0; i < order_size; ++i)
    {
        Optic_Material optic_material;
        input >> optic_material;
        this->optic_materials.push_back(optic_material);
    }

    return input;
}

void Optic_Materials::to_json(json& j) const {
    // Start with an empty array
    j = json::array();

    // Serialize each supplier
    for (const auto& optic_material : this->optic_materials) {
        json materialJson;
        optic_material.to_json(materialJson);
        j.push_back(materialJson);
    }
}

void Optic_Materials::from_json(json& j) {
    // Clear existing suppliers
    this->optic_materials.clear();

    // Deserialize each JSON object into an Supplier and add to the vector
    for (auto& materialJson : j) {
        Optic_Material optic_material;
        optic_material.from_json(materialJson);
        this->optic_materials.push_back(optic_material);
    }
}