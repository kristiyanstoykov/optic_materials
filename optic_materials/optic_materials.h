#pragma once
#ifndef OPTICE_MATERIALS_H
#define OPTICE_MATERIALS_H

#include <vector>
#include <fstream>
#include "optic_material.h"
#include "base.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Optic_Materials : public Base
{
private:
    vector<Optic_Material> optic_materials;

public:
    // Constructor
    Optic_Materials() = default;

    int getSize() const;

    void addOpticMaterial(const Optic_Material& optic_material);
    vector<Optic_Material> getOpticMaterials();
    Optic_Material getOpticMaterialByIndex(int index) const;

    ostream& print(ostream& output) const override;
    void print_on_one_line() const;
    istream& input(istream& input) override;
    void to_json(json& j) const override;
    void from_json(json& j) override;
};

#endif