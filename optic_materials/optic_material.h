#ifndef OPTIC_MATERIAL_H
#define OPTIC_MATERIAL_H

#include <iostream>
#include <string>
#include "base.h"

using namespace std;

/**
 * @brief Class representing an optical material.
 *
 * This class stores details of an optical material and provides methods
 * for setting and getting its properties. It extends the Base class,
 * providing implementations for serialization and deserialization
 * to/from streams and JSON.
 */
class Optic_Material : public Base
{
private:
    string type;
    double width;
    double diopter;
    string name;
    double price;

public:
    /**
     * @brief Default constructor for Optic_Material.
     */
    Optic_Material();

    /**
     * @brief Constructor for Optic_Material with parameters.
     * @param type The type of the optical material.
     * @param width The width of the optical material.
     * @param diopter The diopter value of the optical material.
     * @param name The name of the optical material.
     * @param price The price of the optical material.
     */
    Optic_Material(string type, double width, double diopter, string name, double price);

    /**
     * @brief Gets the type of the optical material.
     * @return The type of the optical material.
     */
    string getType() const;

    /**
     * @brief Sets the type of the optical material.
     * @param type The type of the optical material.
     */
    void setType(string type);

    /**
     * @brief Gets the width of the optical material.
     * @return The width of the optical material.
     */
    double getWidth()const;

    /**
     * @brief Sets the width of the optical material.
     * @param width The width of the optical material.
     */
    void setWidth(double width);

    /**
     * @brief Gets the diopter value of the optical material.
     * @return The diopter value of the optical material.
     */
    double getDiopter()const;

    /**
     * @brief Sets the diopter value of the optical material.
     * @param diopter The diopter value of the optical material.
     */
    void setDiopter(double diopter);

    /**
     * @brief Gets the name of the optical material.
     * @return The name of the optical material.
     */
    string getName()const;

    /**
     * @brief Sets the name of the optical material.
     * @param name The name of the optical material.
     */
    void setName(string name);

    /**
     * @brief Gets the price of the optical material.
     * @return The price of the optical material.
     */
    double getPrice()const;

    /**
     * @brief Sets the price of the optical material.
     * @param price The price of the optical material.
     */
    void setPrice(double price);

    /**
     * @brief Overridden method for printing the optical material's details to an output stream.
     * @param output The output stream to which the data is to be written.
     * @return Reference to the modified output stream.
     */
    ostream& print(ostream& output) const override;

    /**
     * @brief Overridden method for reading data into the optical material from an input stream.
     * @param input The input stream from which the data is to be read.
     * @return Reference to the modified input stream.
     */
    istream& input(istream& input) override;

    /**
     * @brief Overridden method for converting the optical material's state to JSON format.
     * @param j JSON object to which the object's state is to be written.
     */
    void to_json(json& j) const override;

    /**
     * @brief Overridden method for setting the optical material's state from JSON format.
     * @param j JSON object from which the object's state is to be read.
     */
    void from_json(json& j) override;
};

#endif
