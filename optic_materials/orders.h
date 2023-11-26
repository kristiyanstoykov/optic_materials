#ifndef ORDERS_H
#define ORDERS_H

#include <vector>
#include <fstream>
#include "order.h"
#include "base.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Orders : public Base{
private:
    vector<Order> orderList;

public:
    // Constructor
    Orders() = default;

    void addOrder(const Order& order);
    vector<Order> getOrders();

    ostream& print(ostream& output) const override;
    istream& input(istream& input) override;
    void to_json(json& j) const override;
    void from_json(json& j) override;

};

#endif
