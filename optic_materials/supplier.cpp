#include "supplier.h"

Supplier::Supplier() {}

Supplier::Supplier(std::string bulstat, std::string name, std::string location, std::string phone, double profit_margin)
{
    if (bulstat.empty())
    {
        throw std::invalid_argument("The bulstat can't be empty!");
    }

    if (name.empty())
    {
        throw std::invalid_argument("The name can't be empty!");
    }

    if (location.empty())
    {
        throw std::invalid_argument("The location can't be empty!");
    }

    if (phone.length() != 10)
    {
        throw std::invalid_argument("The phone must be 10 symbols!");
    }

    this->bulstat = bulstat;
    this->name = name;
    this->location = location;
    this->phone = phone;
    this->profit_margin = profit_margin;
}

// Copy constructor
Supplier::Supplier(const Supplier& sup):
    bulstat(sup.bulstat),
    name(sup.name),
    location(sup.location),
    phone(sup.phone),
    profit_margin(sup.profit_margin)
{}

std::string Supplier::getBulstat()
{
    return this->bulstat;
}

void Supplier::setBulstat(std::string bulstat)
{
    this->bulstat = bulstat;
}

std::string Supplier::getName()
{
    return this->name;
}

void Supplier::setName(std::string name)
{
    this->name = name;
}

std::string Supplier::getLocation()
{
    return this->location;
}

void Supplier::setLocation(std::string location)
{
    this->location = location;
}

std::string Supplier::getPhone()
{
    return this->phone;
}

void Supplier::setPhone(std::string phone)
{
    this->phone = phone;
}

double Supplier::getProfitMargin()
{
    return this->profit_margin;
}

void Supplier::setProfitMargin(double profit_margin)
{
    this->profit_margin = profit_margin;
}


ostream &Supplier::print(ostream &output) const
{
    output << "Suplier: " << this->name << endl;
    output << "Bulstat: " << this->bulstat << endl;
    output << "Phone: " << this->phone << endl;
    output << "Location: " << this->location << endl;
    output << "Profit margin: " << this->profit_margin << endl;

    return output;
}

istream &Supplier::input(istream &input)
{
    string line;

    getline(input, line);
    this->name = line.substr(line.find(": ") + 2);

    getline(input, line);
    this->bulstat = line.substr(line.find(": ") + 2);

    getline(input, line);
    this->phone = line.substr(line.find(": ") + 2);

    getline(input, line);
    this->location = line.substr(line.find(": ") + 2);

    getline(input, line);
    this->profit_margin = stod(line.substr(line.find(": ") + 2));

    return input;
}

void Supplier::to_json(json& j) const
{
    j = json{
        {"name", this->name},
        {"bulstat", this->bulstat},
        {"phone", this->phone},
        {"location", this->location},
        {"profit_margin", this->profit_margin}
    };
}

void Supplier::from_json(json& j)
{
    this->name = j.at("name").get<string>();
    this->bulstat = j.at("bulstat").get<string>();
    this->phone = j.at("phone").get<string>();
    this->location = j.at("location").get<string>();
    this->profit_margin = j.at("profit_margin").get<double>();
}