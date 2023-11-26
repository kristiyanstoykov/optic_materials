#include "orders.h"


// Method to add an order
void Orders::addOrder(const Order& order) {
    orderList.push_back(order);
}

// Method to get all orders
vector<Order> Orders::getOrders() {
    return orderList;
}

ostream& Orders::print(ostream& output) const {
    output << "Total Orders: " << orderList.size() << "\n";
    for (const auto& order : orderList) {
        output << "---------------------------------\n";
        output << order; // Assuming Order has an overloaded operator<< for printing
        output << "---------------------------------\n";
    }
    return output;
}

istream& Orders::input(istream& input) {
    orderList.clear();
    string line;
    while (getline(input, line)) {
        if (line.empty()) continue; // Skip empty lines or use them as delimiters

        Order order;
        input >> order; // Assuming Order has an overloaded operator>> for input
        orderList.push_back(order);

        // Skip until the next order or end of file
        while (getline(input, line) && !line.empty()) {}
    }
    return input;
}

void Orders::to_json(json& j) const {
    // Start with an empty array
    j = json::array();

    // Serialize each order
    for (const auto& order : orderList) {
        json orderJson;
        order.to_json(orderJson); // Assuming Order has a to_json method
        j.push_back(orderJson);
    }
}

void Orders::from_json(json& j) {
    // Clear existing orders
    orderList.clear();

    // Deserialize each JSON object into an Order and add to the vector
    for (auto& orderJson : j) {
        Order order;
        order.from_json(orderJson);
        orderList.push_back(order);
    }
}