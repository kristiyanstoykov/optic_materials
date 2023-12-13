#pragma once
#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#include <vector>
#include <fstream>
#include "supplier.h"
#include "base.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

/**
 * @brief Class representing a collection of Supplier objects.
 *
 * This class manages a collection of Supplier objects and provides methods
 * for adding suppliers and accessing them. It extends the Base class,
 * implementing serialization and deserialization to/from streams and JSON.
 */
class Suppliers : public Base
{
private:
    vector<Supplier> suppliers;

public:
    /**
     * @brief Default constructor for Suppliers.
     */
    Suppliers() = default;

    /**
     * @brief Adds a Supplier object to the collection.
     * @param supplier The Supplier object to be added.
     */
    void addSupplier(const Supplier& supplier);

    /**
     * @brief Retrieves all suppliers in the collection.
     * @return A vector containing all Supplier objects in the collection.
     */
    vector<Supplier> getSuppliers();

    /**
     * @brief Retrieves a Supplier object at a specified index in the collection.
     * @param index The index of the Supplier object to retrieve.
     * @return The Supplier object at the specified index.
     */
    Supplier getSupplierByIndex(int index) const;

    /**
     * @brief Gets the number of suppliers in the collection.
     * @return The size of the suppliers collection.
     */
    int getSize() const;

    /**
     * @brief Checks if collection is empty
     * @return True if collection is empty, false otherwise
     */
    bool isEmpty();

    /**
     * @brief Prints a concise one-line description of each supplier in the collection.
     */
    void print_on_one_line() const;

    /**
     * @brief Overridden method for printing the collection's details to an output stream.
     * @param output The output stream to which the collection's data is to be written.
     * @return Reference to the modified output stream.
     */
    ostream& print(ostream& output) const override;

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
