#ifndef ORDERS_H
#define ORDERS_H

#include <vector>
#include <fstream>
#include "order.h"
#include "base.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

/**
 * @brief Class representing a collection of Order objects.
 *
 * This class manages a collection of Order objects and provides methods
 * for adding orders and managing their contents. It extends the Base class,
 * implementing serialization and deserialization to/from streams and JSON.
 */
class Orders : public Base {
private:
    vector<Order> orders;

public:
    /**
     * @brief Default constructor for Orders.
     */
    Orders();

    /**
     * @brief Adds an Order object to the collection.
     * @param order The Order object to be added.
     */
    void addOrder(const Order& order);

    /**
     * @brief Retrieves all orders in the collection.
     * @return A vector containing all Order objects in the collection.
     */
    vector<Order> getOrders();

    /**
     * @brief Adds an optic material to the last order in the collection.
     * @param material The Optic_Material object to be added to the last order.
     */
    void addMaterialToLastOrder(const Optic_Material& material);

    /**
     * @brief Adds a supplier to the last order in the collection.
     * @param supplier The Supplier to be associated with the last order.
     */
    void addSupplierToLastOrder(const Supplier& supplier);

    /**
     * @brief Sets the ID for the last order in the collection.
     * @param id The unique identifier for the last order.
     */
    void addIdToLastOrder(int id);

    /**
     * @brief Prints the total cost of each order in the collection.
     */
    void printOrderTotal();

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
