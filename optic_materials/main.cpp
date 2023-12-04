#include <iostream>
#include <string>
#include <memory>
#include <fstream>
#include "orders.h"
#include "suppliers.h"
#include "optic_materials.h"

using namespace std;

void load_orders(Orders &orders) {
    ifstream in("orders.txt");
    if (!in) {
        cout << "File could not be opened!\n";
        in.close();
        return;
    }

    in >> orders;
    in.close();
}

void load_orders_json(Orders& orders) {
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

void save_orders(Orders orders) {
    ofstream out("orders.txt");
    if (!out) {
        cout << "File could not be opened or created!\n";
        return;
    }

    out << orders;
    out.close();
}

void save_orders_json(Orders orders) {
    ofstream out("orders.json");
    if (!out) {
        cout << "File could not be opened or created!\n";
        return;
    }

    json j;
    orders.to_json(j);
    out << j.dump(4);
    out.close();
}

void load_suppliers(Suppliers& suppliers) {
    ifstream in("suppliers.txt");
    if (!in) {
        cout << "File could not be opened!\n";
        in.close();
        return;
    }

    in >> suppliers;
    in.close();
}

void load_suppliers_json(Suppliers& suppliers) {
    ifstream in("suppliers.json");
    if (!in) {
        cout << "File could not be opened!\n";
        return;
    }

    json j;
    in >> j;
    in.close();

    suppliers.from_json(j);

}

void save_suppliers(Suppliers suppliers) {
    ofstream out("suppliers.txt");
    if (!out) {
        cout << "File could not be opened or created!\n";
        return;
    }

    out << suppliers;
    out.close();
}

void save_suppliers_json(Suppliers suppliers) {
    ofstream out("suppliers.json");
    if (!out) {
        cout << "File could not be opened or created!\n";
        return;
    }

    json j;
    suppliers.to_json(j);
    out << j.dump(4);
    out.close();
}

void load_materials(Optic_Materials& materials) {
    ifstream in("materials.txt");
    if (!in) {
        cout << "File could not be opened!\n";
        in.close();
        return;
    }

    in >> materials;
    in.close();
}

void load_materials_json(Optic_Materials& materials) {
    cout << "Start read to JSON file -----------\n";
    ifstream in("materials.json");
    if (!in) {
        cout << "File could not be opened!\n";
        return;
    }

    json j;
    in >> j;
    in.close();

    materials.from_json(j);

}

void save_materials(Optic_Materials materials) {
    ofstream out("materials.txt");
    if (!out) {
        cout << "File could not be opened or created!\n";
        return;
    }

    out << materials;
    out.close();
}

void save_materials_json(Optic_Materials materials) {
    ofstream out("materials.json");
    if (!out) {
        cout << "File could not be opened or created!\n";
        return;
    }

    json j;
    materials.to_json(j);
    out << j.dump(4);
    out.close();
}

Supplier enter_supplier() {
    string bulstat, name, location, phone;
    double profit_margin;
    cin.clear();
    cin.ignore();
    cout << "Enter Supplier\n";
    cout << "Enter bulstat:\n";
    getline(cin, bulstat);
    while (bulstat.empty()) {
        cout << "Supplier bullstat cannot be empty!\nEnter bulstat:\n";
        getline(cin, bulstat);
    }
    cout << "Enter name:\n";
    getline(cin, name);
    while (name.empty()) {
        cout << "Supplier name cannot be empty!\nEnter name:\n";
        getline(cin, name);
    }
    cout << "Enter location:\n";
    getline(cin, location);
    while (location.empty()) {
        cout << "Supplier location cannot be empty!\nEnter location:\n";
        getline(cin, location);
    }
    cout << "Enter phone:\n";
    getline(cin, phone);
    while (phone.empty()) {
        cout << "Supplier phone cannot be empty!\nEnter phone:\n";
        getline(cin, phone);
    }
    cout << "Enter profit margin (%):\n";
    cin >> profit_margin;
    while (profit_margin < 0) {
        cout << "Supplier profit margin cannot be less than 0!\nEnter profit margin:\n";
        getline(cin, phone);
    }

    Supplier supplier(bulstat, name, location, phone, profit_margin);
    return supplier;
}

Optic_Material enter_material() {

    string type, name;
    double width, diopter, price;
    cin.clear();
    cin.ignore();
    cout << "Enter type:\n";
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

    Optic_Material material(type, width, diopter, name, price);

    return material;
}

void enter_order(Orders& orders, Optic_Materials materials, Suppliers suppliers) {

    orders.addOrder(Order());

    int order_id;
    cout << "Enter order id number: ";
    cin >> order_id;
    orders.addIdToLastOrder(order_id);

    int materials_to_add;
    cout << "Enter number of materials to add: ";
    cin >> materials_to_add;

    materials.print_on_one_line();

    for (int i = 0; i < materials_to_add; i++)
    {
        int num;
        cout << "Choose material number to add to order:\n";
        cin >> num;

        while (num <= 0 || num > materials.getSize())
        {
            cout << "Incorrect number!\nChoose material number to add to order:\n";
            cin >> num;
        }

        orders.addMaterialToLastOrder(materials.getOpticMaterialByIndex(num - 1));

    }

    suppliers.print_on_one_line();
    int num;
    cout << "Choose supplier number to add to order:\n";
    cin >> num;

    while (num <= 0 || num > suppliers.getSize())
    {
        cout << "Incorrect number!\nChoose material number to add to order:\n";
        cin >> num;
    }

    orders.addSupplierToLastOrder(suppliers.getSupplierByIndex(num - 1));

    cout << "Order successfully added";
}

void display_menu(Orders &orders, Suppliers& suppliers, Optic_Materials& materials) {

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
        //load_orders(orders);
        load_orders_json(orders);
        load_suppliers(suppliers);
        //load_orders_json(suppliers);
        load_materials(materials);
        //load_orders_json(materials);
        break;
    case 2:
        enter_order(orders, materials, suppliers);
        break;
    case 3:
        // Enter new supplier
        suppliers.addSupplier(enter_supplier());
        break;
    case 4:
        // Enter new optic material
        materials.addOpticMaterial(enter_material());
        cout << "Material added successfully\n";
        break;
    case 5:
        // View orders ( to screen )
        cout << orders;
        break;
    case 6:
        // View suppliers ( to screen )
        cout << suppliers;
        break;
    case 7:
        // View optic materials ( to screen )
        cout << materials;
        break;
    case 8:
        // Save orders, suppliers and materials to file
        save_orders(orders);
        save_orders_json(orders);
        save_suppliers(suppliers);
        save_suppliers_json(suppliers);
        save_materials(materials);
        save_materials_json(materials);
        break;
    case 0:
        // TODO Exit. Add prompt that says if orders ... not saved are lost forever
        cout << "Goodbye!";
        return;
        break;
    default:
        break;
    }

    display_menu(orders, suppliers, materials);

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
    display_menu(orders, suppliers, materials);

    return 0;
}
