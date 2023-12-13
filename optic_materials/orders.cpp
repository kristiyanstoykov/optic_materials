#include "orders.h"

Orders::Orders() {
    this->orders.push_back(Order());
}

void Orders::addOrder(const Order& order) {
    this->orders.push_back(order);
}

vector<Order> Orders::getOrders() {
    return this->orders;
}

void Orders::addIdToLastOrder(int id) {
    if (!this->orders.empty()) {
        this->orders.back().setId(id);
    }
    else {
        throw std::invalid_argument("There are no orders to add a material to.");
    }
}

void Orders::addMaterialToLastOrder(const Optic_Material& material) {
    if (!this->orders.empty()) {
        this->orders.back().addMaterial(material);
    }
    else {
        throw std::invalid_argument("There are no orders to add a material to.");
    }
}

void Orders::addSupplierToLastOrder(const Supplier& supplier) {
    if (!this->orders.empty()) {
        this->orders.back().addSupplier(supplier);
    }
    else {
        throw std::invalid_argument("There are no orders to add a suppler to.");
    }
}

void Orders::printOrderTotal()
{
    for(auto& order : this->orders) {
        cout << "Order " << order.getId() << ": " << order.getTotalRaw() << " +" << " supplier profit: " << order.getSupplier().getProfitMargin() << "% => " << order.getTotal() << "BGN\n";
    }
}

ostream& Orders::print(ostream& output) const {
    output << "Total Orders: " << this->orders.size() << "\n";
    for (const auto& order : this->orders) {
        output << order;
    }
    return output;
}

istream& Orders::input(istream& input) {
    this->orders.clear();
    string line;
    getline(input, line);
    int order_size = stoi(line.substr(line.find(": ") + 2));

    for (int i = 0; i < order_size; ++i)
    {
        Order order;
        input >> order;
        this->orders.push_back(order);
    }

    return input;
}

void Orders::to_json(json& j) const {
    // Start with an empty array
    j = json::array();

    // Serialize each order
    for (const auto& order : this->orders) {
        json orderJson;
        order.to_json(orderJson);
        j.push_back(orderJson);
    }
}

void Orders::from_json(json& j) {
    // Clear existing orders
    this->orders.clear();

    // Deserialize each JSON object into an Order and add to the vector
    for (auto& orderJson : j) {
        Order order;
        order.from_json(orderJson);
        this->orders.push_back(order);
    }
}