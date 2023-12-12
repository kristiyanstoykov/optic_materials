#pragma once
#ifndef OPTIC_MATERIALS_H
#define OPTIC_MATERIALS_H

#include <vector>
#include <fstream>
#include "optic_material.h"
#include "base.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

/**
 * @brief Class representing a collection of Optic_Material objects.
 *
 * This class encapsulates a collection of Optic_Material objects and provides methods
 * for managing this collection, including adding and retrieving optic materials,
 * and implementing serialization and deserialization to/from streams and JSON.
 */
class Optic_Materials : public Base
{
private:
    vector<Optic_Material> optic_materials;

public:
    /**
     * @brief Default constructor for Optic_Materials.
     */
    Optic_Materials() = default;

    /**
     * @brief Gets the number of optic materials in the collection.
     * @return The size of the optic materials collection.
     */
    int getSize() const;

    /**
     * @brief Adds an Optic_Material object to the collection.
     * @param optic_material The Optic_Material object to be added.
     */
    void addOpticMaterial(const Optic_Material& optic_material);

    /**
     * @brief Retrieves all optic materials in the collection.
     * @return A vector containing all Optic_Material objects in the collection.
     */
    vector<Optic_Material> getOpticMaterials();

    /**
     * @brief Retrieves an Optic_Material object at a specified index in the collection.
     * @param index The index of the Optic_Material object to retrieve.
     * @return The Optic_Material object at the specified index.
     */
    Optic_Material getOpticMaterialByIndex(int index) const;

    /**
     * @brief Overridden method for printing the collection's details to an output stream.
     * @param output The output stream to which the collection's data is to be written.
     * @return Reference to the modified output stream.
     */
    ostream& print(ostream& output) const override;

    /**
     * @brief Prints a concise one-line description of each optic material in the collection.
     */
    void print_on_one_line() const;

    /**
     * @brief Overridden method for reading data into the collection from an input stream.
     * @param input The input stream from which the data is to be read.
     * @return Reference to the modified input stream.
     */
    istream& input(istream& input) override;

    /**
     * @brief Overridden method for converting the collection's state to JSON format.
     * @param j JSON object to which the collection's state is to be written.
     */
    void to_json(json& j) const override;

    /**
     * @brief Overridden method for setting the collection's state from JSON format.
     * @param j JSON object from which the collection's state is to be read.
     */
    void from_json(json& j) override;
};

#endif
