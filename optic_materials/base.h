#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

/**
 * @brief A base class providing an interface for serialization and deserialization
 *        as well as stream insertion and extraction.
 *
 * This class defines a common interface for derived classes to implement custom
 * behavior for printing to and reading from streams, and for converting to and
 * from JSON format.
 */
class Base
{
private:
    /**
     * @brief Virtual method for printing the object's details to an output stream.
     * @param output The output stream to which the object's data is to be written.
     * @return Reference to the modified output stream.
     */
    virtual ostream& print(ostream& output) const = 0;

    /**
     * @brief Virtual method for reading data into the object from an input stream.
     * @param input The input stream from which the data is to be read.
     * @return Reference to the modified input stream.
     */
    virtual istream& input(istream& input) = 0;

    /**
     * @brief Virtual method for converting the object's state to JSON format.
     * @param j JSON object to which the object's state is to be written.
     */
    virtual void to_json(json& j) const = 0;

    /**
     * @brief Virtual method for setting the object's state from JSON format.
     * @param j JSON object from which the object's state is to be read.
     */
    virtual void from_json(json& j) = 0;

public:
    /**
     * @brief Overloads the << operator for outputting the Base object's details to an output stream.
     * @param output The output stream to which the data is to be written.
     * @param base The Base object whose data is to be outputted.
     * @return Returns the modified output stream for chaining.
     */
    friend ostream& operator<<(ostream& output, const Base& base);

    /**
     * @brief Overloads the >> operator for reading data into a Base object from an input stream.
     * @param input The input stream from which the data is to be read.
     * @param base The Base object where the read data is to be stored.
     * @return Returns the modified input stream for chaining.
     */
    friend istream& operator>>(istream& input, Base& base);
};

#endif
    