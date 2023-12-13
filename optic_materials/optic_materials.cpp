#include "optic_materials.h"

Optic_Materials::Optic_Materials() {}


bool Optic_Materials::isEmpty() {
    return this->optic_materials.empty();
}

// Method to add an supplier
void Optic_Materials::addOpticMaterial(const Optic_Material& optic_material) {
    this->optic_materials.push_back(optic_material);
}

int Optic_Materials::getSize() const
{
    return (int) this->optic_materials.size();
}

// Method to get all suppliers
vector<Optic_Material> Optic_Materials::getOpticMaterials() {
    return this->optic_materials;
}

Optic_Material Optic_Materials::getOpticMaterialByIndex(int index) const {
    if (index >= 0 && index < optic_materials.size()) {
        return optic_materials[index];
    }
    else {
        throw std::out_of_range("Index is out of range for optic materials vector.");
    }
}

ostream& Optic_Materials::print(ostream& output) const {
    output << "Total optic materials: " << this->optic_materials.size() << "\n";
    for (const auto& optic_material : this->optic_materials) {
        output << optic_material;
    }
    return output;
}


void Optic_Materials::print_on_one_line() const {
    cout << "Optic materials:\n";
    int i = 0;
    for (auto& optic_material : this->optic_materials) {
        cout << i + 1 << ": " << optic_material.getName() << " "
            << optic_material.getType() << " w:" << optic_material.getWidth()
            << " d: " << optic_material.getDiopter()
            << " p: " << optic_material.getPrice() << '\n';
        i++;
    }
}

istream& Optic_Materials::input(istream& input) {
    this->optic_materials.clear();
    string line;
    getline(input, line);
    int materials_size = stoi(line.substr(line.find(": ") + 2));

    for (int i = 0; i < materials_size; ++i)
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