#include <iostream>
#include <string>
#include <memory>
#include <fstream>
#include "order.h"
//#include "supplier.h"
//#include "optic_material.h"

using namespace std;

void load_order(Order &order) {
    ifstream in("order.txt");
    if (!in) {
        cout << "File could not be opened!\n";
        in.close();
        return;
    }

    in >> order;
    in.close();
}

void load_order_json(Order& order) {
    cout << "Start read to JSON file -----------\n";
    ifstream in("order.json");
    if (!in) {
        cout << "File could not be opened!\n";
        return;
    }

    json j;
    in >> j;
    order.from_json(j);

    in.close();
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

void save_order_json(Order order) {
    ofstream out("order.json");
    if (!out) {
        cout << "File could not be opened or created!\n";
        return;
    }

    json j;
    order.to_json(j);
    out << j.dump(4);
    out.close();
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

void display_menu(Order &order) {

    cout << "Optic materials\n";
    cout << "1. Load order from file.\n";
    cout << "2. Enter new order\n";
    cout << "3. Edit order\n";
    cout << "4. Save order to file\n";
    cout << "5. View current order\n";
    cout << "0. Exit\n";

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        load_order(order);
        //load_order_json(order);
        // TODO Load orders to file
        break;
    case 2:
        enter_order(order);
        break;
    case 3:
        // TODO Edit order
        break;
    case 4:
        save_order(order);
        save_order_json(order);
        break;
    case 5:
        // TODO View current orders to file
        break;
    case 0:
        // TODO Exit
        break;
    default:
        break;
    }
}


int main() {
    
    Order order;
    display_menu(order);

    cout << "Test --------------";
    cout << order;
    cout << "End test ----------";

    return 0;
}
