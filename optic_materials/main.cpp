#include <iostream>
#include <string>
#include <memory>
#include <fstream>
#include "orders.h"
#include "suppliers.h"
#include "optic_materials.h"

using namespace std;

void load_orders(Orders &orders) {
    ifstream in("order.txt");
    if (!in) {
        cout << "File could not be opened!\n";
        in.close();
        return;
    }

    in >> orders;
    in.close();
}

void load_orders_json(Orders& orders) {
    cout << "Start read to JSON file -----------\n";
    ifstream in("orders.json");
    if (!in) {
        cout << "File could not be opened!\n";
        return;
    }

    json j;
    in >> j;
    in.close();

    orders.from_json(j);

}

void save_order(Order order) {
    ofstream out("order.txt");
    if (!out) {
        cout << "File could not be opened or created!\n";
        return;
    }

    out << order;
    out.close();
}

void save_orders_json(Orders orders) {
    ofstream out("order.json");
    if (!out) {
        cout << "File could not be opened or created!\n";
        return;
    }

    json j;
    orders.to_json(j);
    out << j.dump(4);
    out.close();
}

void enter_supplier(Supplier &supplier) {
    string bulstat, name, location, phone;
    cout << "Enter Supplier\n";
    cout << "Enter bulstat:\n";
    getline(cin, bulstat);
    cout << "Enter name:\n";
    getline(cin, name);
    cout << "Enter location:\n";
    getline(cin, location);
    cout << "Enter phone:\n";
    getline(cin, phone);

    supplier = Supplier("12121212", "GTS Computers", "Bulgaria, Pazardzhik", "0886626226", 9.99f);
}

void enter_material(Optic_Material& material) {

    string type, name;
    double width, diopter, price;
    cout << "Material " << i + 1 << ": \n";
    cout << "Enter type\n";
    getline(cin, type);
    while (type.empty()) {
        cout << "Material type cannot be empty!\nEnter type:\n";
        getline(cin, type);
    }
    cout << "Enter name:\n";
    getline(cin, name);
    while (name.empty()) {
        cout << "Material name cannot be empty!\nEnter name:\n";
        getline(cin, type);
    }
    cout << "Enter width:\n";
    cin >> width;
    while (width <= 0) {
        cout << "Material width cannot be 0 or less than 0!\nEnter width:\n";
        cin >> width;
    }
    cout << "Enter diopter:\n";
    cin >> diopter;
    while (diopter == 0) {
        cout << "Material diopter cannot be 0!\nEnter width:\n";
        cin >> diopter;
    }
    cout << "Enter price:\n";
    cin >> price;
    while (price < 0) {
        cout << "Material price cannot be less than 0!\nEnter width:\n";
        cin >> price;
    }

    material = Optic_Material(type, width, diopter, name, price);
}

void enter_order(Order& order) {

    int order_id;
    cout << "Enter order id number: ";
    cin >> order_id;

    int num_mat;
    vector<Optic_Material> materials;
    cout << "Enter number of materials to add: ";
    cin >> num_mat;

    for (int i = 0; i < num_mat; i++)
    {
        string type, name;
        double width, diopter, price;
        cout << "Material " << i + 1 << ": \n";
        cout << "Enter type\n";
        getline(cin, type);
        cout << "Enter name:\n";
        getline(cin, name);
        cout << "Enter width:\n";
        cin >> width;
        cout << "Enter diopter:\n";
        cin >> diopter;
        cout << "Enter price:\n";
        cin >> price;

        Optic_Material material(type, width, diopter, name, price);

        materials.push_back(material);
    }

    // TODO move this to another function for entering suppliers and saving to files
    string bulstat, name, location, phone;
    cout << "Enter Supplier\n";
    cout << "Enter bulstat:\n";
    getline(cin, bulstat);
    cout << "Enter name:\n";
    getline(cin, name);
    cout << "Enter location:\n";
    getline(cin, location);
    cout << "Enter phone:\n";
    getline(cin, phone);

    Supplier supplier("12121212", "GTS Computers", "Bulgaria, Pazardzhik", "0886626226", 9.99f);

    cout << "Order successfully added";

    order = Order(order_id, materials, supplier);
}

void display_menu(Orders &orders, Suppliers& supplier, Optic_Materials& materials) {

    cout << "Optic materials\n";
    cout << "1. Load orders, suppliers and materials from file.\n";
    cout << "2. Enter new order\n";
    cout << "3. Enter new supplier\n";
    cout << "4. Enter new optic material\n";
    cout << "5. View orders\n";
    cout << "6. View suppliers\n";
    cout << "7. View optic materials\n";
    cout << "8. Save orders, suppliers and materials to file\n";
    cout << "0. Exit\n";

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        // TODO Load orders, suppliers and materials from file
        load_orders(orders);
        //load_order_json(order);
        break;
    case 2:
        enter_orders(orders);
        break;
    case 3:
        // TODO Enter new supplier
        break;
    case 4:
        // TODO Enter new optic material
        break;
    case 5:
        // TODO View orders ( to screen )
        break;
    case 6:
        // TODO View suppliers ( to screen )
        break;
    case 7:
        // TODO View optic materials ( to screen )
        break;
    case 8:
        // TODO Save orders, suppliers and materials to file
        save_order(order);
        //save_order_json(order);
        break;
    case 0:
        // TODO Exit. Add prompt that says if orders ... not saved are lost forever
        break;
    default:
        break;
    }
}

void test(Suppliers& suppliers) {

    Supplier supplier1("2222222", "GTS Computers", "Bulgaria, Pazardzhik", "0886626226", 9.99f);
    Supplier supplier2("3333333", "GTS Computers", "Bulgaria, Pazardzhik", "0886626226", 9.99f);
    Supplier supplier3("4444444", "GTS Computers", "Bulgaria, Pazardzhik", "0886626226", 9.99f);

    suppliers.addSupplier(supplier1);
    suppliers.addSupplier(supplier2);
    suppliers.addSupplier(supplier3);
}

int main() {
    
    Orders orders;
    Suppliers suppliers;
    Optic_Materials materials;
    //display_menu(orders, suppliers, materials);

    cout << "Test supplers --------------\n";
    test(suppliers);
    cout << suppliers;

    return 0;
}
