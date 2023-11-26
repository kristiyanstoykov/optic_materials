#include "optic_material.h"

Optic_Material::Optic_Material() {}

Optic_Material::Optic_Material(std::string type, double width, double diopter, std::string name, double price)
{
    if (type.empty())
    {
        throw std::invalid_argument("The type can't be empty!");
    }

    if (width <= 0)
    {
        throw std::invalid_argument("The width can not be 0 or less than 0!");
    }

    if (diopter == 0)
    {
        throw std::invalid_argument("The diopter cannot be 0!");
    }

    if (name.empty())
    {
        throw std::invalid_argument("The name must be 10 symbols!");
    }

    if (price < 0)
    {
        throw std::invalid_argument("The price cant be less than 0!");
    }

    this->type = type;
    this->width = width;
    this->diopter = diopter;
    this->name = name;
    this->price = price;
}

std::string Optic_Material::getType()
{
    return this->type;
}

void Optic_Material::setType(std::string type)
{
    this->type = type;
}

std::string Optic_Material::getName()
{
    return this->name;
}

void Optic_Material::setName(std::string name)
{
    this->name = name;
}

double Optic_Material::getDiopter()
{
    return this->diopter;
}

void Optic_Material::setDiopter(double diopter)
{
    this->diopter = diopter;
}

double Optic_Material::getWidth()
{
    return this->width;
}

void Optic_Material::setWidth(double width)
{
    this->width = width;
}

double Optic_Material::getPrice()
{
    return this->price;
}

void Optic_Material::setPrice(double price)
{
    this->price = price;
}


ostream& Optic_Material::print(ostream& output) const
{
    output << "Optic material: " << this->name << endl;
    output << "Type: " << this->type << endl;
    output << "Width: " << this->width << endl;
    output << "Diopter: " << this->diopter << endl;
    output << "Price: " << this->price << endl;

    return output;
}

istream& Optic_Material::input(istream& input)
{
    string line;

    getline(input, line);
    this->name = line.substr(line.find(": ") + 2);

    getline(input, line);
    this->type = line.substr(line.find(": ") + 2);

    getline(input, line);
    this->width = stod(line.substr(line.find(": ") + 2));

    getline(input, line);
    this->diopter = stod(line.substr(line.find(": ") + 2));

    getline(input, line);
    this->price = stod(line.substr(line.find(": ") + 2));

    return input;
}

void Optic_Material::to_json(json& j) const
{
    j = json{
        {"name", this->name},
        {"type", this->type},
        {"width", this->width},
        {"diopter", this->diopter},
        {"price", this->price}
    };
}

void Optic_Material::from_json(json& j)
{
    this->name = j.at("name").get<std::string>();
    this->type = j.at("type").get<std::string>();
    this->width= j.at("width").get<double>();
    this->diopter = j.at("diopter").get<double>();
    this->price = j.at("price").get<double>();
}