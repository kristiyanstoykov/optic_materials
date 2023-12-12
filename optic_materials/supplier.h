#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <iostream>
#include <string>
#include "base.h"

/**
 * @brief Class representing a supplier in the optics materials system.
 *
 * This class stores details about a supplier, including identification, contact information,
 * and profit margin. It extends the Base class, providing implementations for serialization
 * and deserialization to/from streams and JSON.
 */
class Supplier : public Base
{
private:
    std::string bulstat;
    std::string name;
    std::string location;
    std::string phone;
    double profit_margin;

public:
    /**
     * @brief Default constructor for Supplier.
     */
    Supplier();

    /**
     * @brief Constructor for Supplier with parameters.
     * @param bulstat The unique identifier for the supplier.
     * @param name The name of the supplier.
     * @param location The location of the supplier.
     * @param phone The contact phone number of the supplier.
     * @param profit_margin The profit margin of the supplier.
     */
    Supplier(std::string bulstat, std::string name, std::string location, std::string phone, double profit_margin);

    /**
     * @brief Gets the unique identifier of the supplier.
     * @return The bulstat of the supplier.
     */
    std::string getBulstat() const;

    /**
     * @brief Sets the unique identifier of the supplier.
     * @param bulstat The bulstat to set for the supplier.
     */
    void setBulstat(std::string bulstat);

    /**
     * @brief Gets the name of the supplier.
     * @return The name of the supplier.
     */
    std::string getName() const;

    /**
     * @brief Sets the name of the supplier.
     * @param name The name to set for the supplier.
     */
    void setName(std::string name);

    /**
     * @brief Gets the location of the supplier.
     * @return The location of the supplier.
     */
    std::string getLocation() const;

    /**
     * @brief Sets the location of the supplier.
     * @param location The location to set for the supplier.
     */
    void setLocation(std::string location);

    /**
     * @brief Gets the contact phone number of the supplier.
     * @return The phone number of the supplier.
     */
    std::string getPhone() const;

    /**
     * @brief Sets the contact phone number of the supplier.
     * @param phone The phone number to set for the supplier.
     */
    void setPhone(std::string phone);

    /**
     * @brief Gets the profit margin of the supplier.
     * @return The profit margin of the supplier.
     */
    double getProfitMargin() const;

    /**
     * @brief Sets the profit margin for the supplier.
     * @param profit_margin The profit margin to set for the supplier.
     */
    void setProfitMargin(double profit_margin);

    /**
     * @brief Overridden method for printing the supplier's details to an output stream.
     * @param output The output stream to which the supplier's data is to be written.
     * @return Reference to the modified output stream.
     */
    ostream& print(ostream& output) const override;

    /**
     * @brief Overridden method for reading data into the supplier from an input stream.
     * @param input The input stream from which the supplier data is to be read.
     * @return Reference to the modified input stream.
     */
    istream& input(istream& input) override;

    /**
     * @brief Overridden method for converting the supplier's state to JSON format.
     * @param j JSON object to which the supplier's state is to be written.
     */
    void to_json(nlohmann::json& j) const override;

    /**
     * @brief Overridden method for setting the supplier's state from JSON format.
     * @param j JSON object from which the supplier's state is to be read.
     */
    void from_json(json& j) override;
};

#endif
