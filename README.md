# Optic Materials

## Description

Optic Materials is a course project for the Programming Languages subject.

## Installation

To get started with "Optic Materials", you'll need to have either Visual Studio 2022 or VS Code installed on your system. Additionally, the `nlohmann/json` library is required for this project. You can install this library via your preferred package manager or by following the instructions on its [GitHub repository](https://github.com/nlohmann/json).

## Usage

After installing the required software and libraries, you can clone this repository using the following command:

Once cloned, open the project in Visual Studio 2022 or VS Code and run the application.

```bash
git clone https://github.com/kristiyanstoykov/optic_materials.git
```

## Features

### Base (`base.h`)

* **Classes** : None
* **Functions** :
* `print`, `to_json`, `from_json`: Basic display and JSON functionalities

### Optic Material (`optic_material.h`)

* **Classes** : None
* **Functions** :
* `Optic_Material`: Constructor for optic material
* `setType`, `getWidth`, `setWidth`, `getDiopter`, `setDiopter`, `setName`, `getPrice`, `setPrice`: Getters and setters for optic material properties
* `print`, `to_json`, `from_json`: Functions for printing, converting to JSON, and loading from JSON

### Optic Materials (`optic_materials.h`)

* **Classes** : None
* **Functions** :
* `getSize`, `addOpticMaterial`, `getOpticMaterialByIndex`: Manage a collection of optic materials
* `print`, `print_on_one_line`, `to_json`, `from_json`: Display, JSON conversion

### Order (`order.h`)

* **Classes** : None
* **Functions** :
* `Order`: Constructor for order
* `setId`, `getId`, `addMaterial`, `addSupplier`: Order management functions
* `getTotalRaw`, `getTotal`: Calculate total cost
* `print`, `to_json`, `from_json`: Display and JSON functionalities

### Orders (`orders.h`)

* **Classes** : `Orders : public Base`
* **Functions** :
* `addOrder`, `addMaterialToLastOrder`, `addSupplierToLastOrder`, `addIdToLastOrder`: Order creation and management
* `printOrderTotal`, `print`, `to_json`, `from_json`: Display and JSON functionalities

### Supplier (`supplier.h`)

* **Classes** : None
* **Functions** :
* `Supplier`: Constructor for supplier
* `setBulstat`, `setName`, `setLocation`, `setPhone`, `getProfitMargin`, `setProfitMargin`: Supplier management
* `print`, `to_json`, `from_json`: Display and JSON functionalities

### Suppliers (`suppliers.h`)

* **Classes** : None
* **Functions** :
* `addSupplier`, `getSupplierByIndex`, `getSize`: Manage a collection of suppliers
* `print_on_one_line`, `print`, `to_json`, `from_json`: Display and JSON functionalities

### Main (`main.cpp`)

* **Classes** : None
* **Functions** :
* Various loading, saving, and menu display functions (`load_orders`, `save_orders`, `display_menu`, etc.)
* `enter_order`, `test`: Order entry and testing functionalities

## Contributing

Contributions to "Optic Materials" are welcome! If you have suggestions or improvements, feel free to fork this repository and submit a pull request.

## License

This project is licensed under the [MIT License](https://chat.openai.com/c/LICENSE.md) - see the LICENSE.md file for details.

## Contact

For any queries or support, please open an issue on the GitHub repository.
