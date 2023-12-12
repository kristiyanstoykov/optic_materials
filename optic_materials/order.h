#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <vector>
#include "supplier.h"
#include "optic_material.h"

/**
 * @brief Class representing an order which includes optic materials and a supplier.
 *
 * This class encapsulates the details of an order, including a list of optic materials,
 * a supplier, and methods for managing and calculating the total cost of the order.
 * It extends the Base class, providing implementations for serialization and
 * deserialization to/from streams and JSON.
 */
class Order : public Base
{
private:
    int id;
    vector<Optic_Material> materials;
    Supplier supplier;

public:
    /**
     * @brief Default constructor for Order.
     */
    Order();

    /**
     * @brief Constructor for Order with parameters.
     * @param id The unique identifier for the order.
     * @param materials A vector of Optic_Material objects included in the order.
     * @param supplier The Supplier associated with the order.
     */
    Order(int id, vector<Optic_Material> materials, Supplier supplier);

    /**
     * @brief Sets the unique identifier of the order.
     * @param id The unique identifier for the order.
     */
    void setId(int id);

    /**
     * @brief Gets the unique identifier of the order.
     * @return The unique identifier of the order.
     */
    int getId();

    /**
     * @brief Retrieves all optic materials included in the order.
     * @return A vector of Optic_Material objects in the order.
     */
    vector<Optic_Material> getMaterials();

    /**
     * @brief Adds an optic material to the order.
     * @param material The Optic_Material object to be added to the order.
     */
    void addMaterial(const Optic_Material& material);

    /**
     * @brief Sets the supplier for the order.
     * @param supplier The Supplier to be associated with the order.
     */
    void addSupplier(const Supplier& supplier);

    /**
     * @brief Gets the supplier associated with the order.
     * @return The Supplier associated with the order.
     */
    Supplier getSupplier();

    /**
     * @brief Calculates the total cost of the order without profit margin.
     * @return The total raw cost of the order.
     */
    double getTotalRaw();

    /**
     * @brief Calculates the total cost of the order including the supplier's profit margin.
     * @return The total cost of the order.
     */
    double getTotal();

    /**
     * @brief Overridden method for printing the order's details to an output stream.
     * @param output The output stream to which the order's data is to be written.
     * @return Reference to the modified output stream.
     */
    ostream& print(ostream& output) const override;

    /**
     * @brief Overridden method for reading data into the order from an input stream.
     * @param input The input stream from which the order data is to be read.
     * @return Reference to the modified input stream.
     */
    istream& input(istream& input) override;

    /**
     * @brief Overridden method for converting the order's state to JSON format.
     * @param j JSON object to which the order's state is to be written.
     */
    void to_json(json& j) const override;

    /**
     * @brief Overridden method for setting the order's state from JSON format.
     * @param j JSON object from which the order's state is to be read.
     */
    void from_json(json& j) override;
};

#endif
