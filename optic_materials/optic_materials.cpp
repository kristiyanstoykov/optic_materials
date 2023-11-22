#include <iostream>
#include <string>
#include <memory>
#include <fstream>
#include "order.h"
//#include "supplier.h"
//#include "optic_material.h"

using namespace std;

string add(string a)
{
    string b = a;

    return b;
}

int main()
{
    //string bulstat, name, location, phone;
    //cout << "bulstat:\n";
    //getline(cin, bulstat);
    //cout << "name:\n";
    //getline(cin, name);
    //cout << "location:\n";
    //getline(cin, location);
    //cout << "phone:\n";
    //getline(cin, phone);

    Supplier supplier("12121212", "GTS Computers", "Bulgaria, Pazardzhik", "0886626226");

    Optic_Material material("glasses", 2.50f, 5.15f, "Diopter oval glasses");
    Optic_Material material_2("glasses", 0.50f, 1.75f, "Diopter circle glasses");
    //cout << material;

    vector<Optic_Material> materials;

    materials.push_back(material);
    materials.push_back(material_2);

    Order order(1, materials, supplier);

    cout << order;

    cout << "\n\n";
    cout << "Start write to JSON file -----------\n";
    ofstream file_order("order.json");
    if (!file_order) {
        cout << "File could not be created!\n";
    }

    json j_out;
    order.to_json(j_out);
    file_order << j_out.dump(4);
    file_order.close();

    cout << "End write to JSON file   -----------\n";

    cout << "Start read to JSON file -----------\n";
    ifstream in("order.json");
    if (!in) {
        cout << "File can not be openned!\n";
    }
    json j;
    in >> j;

    Order order_in;
    order_in.from_json(j);
    in.close();
    cout << order_in << endl;
    cout << "End read to JSON file   -----------\n";

    return 0;
}
