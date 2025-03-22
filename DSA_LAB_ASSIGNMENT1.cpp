#include <iostream>
#include <string>
using namespace std;

#define TAX_RATE_PREPROCESSOR 0.15 


int main() {
    cout << "   Welcome to the Product Sales and Inventory Analysis  " << endl;
    cout << "This program helps you analyze product sales and inventory for a store." << endl;
    cout << "Remember, C++ is a compiled language.so, You must compile this program before running it." << endl << endl;


    string productName;
    int productCategory;
    int initialInventoryQuantity;
    float productPrice;
    int numberOfItemsSold;

    int newInventory;
    float totalSales;
    string inventoryStatus;


    string productDescription = "Sample Product";
    int sampleCategory;
    sampleCategory = 15;
    float samplePrice{ 12.3 };


    auto totalSalesCopy = totalSales;
    decltype(initialInventoryQuantity) inventoryCopy = 50;


    const float TAX_RATE_CONST = 0.15;


    cout << "Enter the product name with a single word : ";
    cin >> productName;

    cout << "Enter the product category between 1 and 5: ";
    cin >> productCategory;

    cout << "Enter the initial inventory quantity: ";
    cin >> initialInventoryQuantity;

    cout << "Enter the product price per unit: $";
    cin >> productPrice;

    cout << "Enter the number of items sold: ";
    cin >> numberOfItemsSold;


    newInventory = initialInventoryQuantity;
    newInventory -= numberOfItemsSold;
    totalSales = numberOfItemsSold * productPrice;


    inventoryStatus = (newInventory < 10) ? "Low Inventory" : "Sufficient Inventory";


    if (productCategory < 1 || productCategory > 5) {
        cout << "Invalid product category! Please enter a number between 1 and 5." << endl;
        return 1;
    }


    cout << endl << "Product Category Details:" << endl;
    switch (productCategory) {
    case 1:
        cout << "Category 1: Electronics" << endl;
        break;
    case 2:
        cout << "Category 2: Groceries" << endl;
        break;
    case 3:
        cout << "Category 3: Clothing" << endl;
        break;
    case 4:
        cout << "Category 4: Stationery" << endl;
        break;
    case 5:
        cout << "Category 5: Miscellaneous" << endl;
        break;
    }


    cout << endl << "Receipt for " << productName << ":" << endl;
    for (int i = 1; i <= numberOfItemsSold; i++) {
        cout << "Item " << i << ": $" << productPrice << endl;
    }


    cout << endl << "Tax Rate (Preprocessor): " << TAX_RATE_PREPROCESSOR * 100 << "%" << endl;
    cout << "Tax Rate (const): " << TAX_RATE_CONST * 100 << "%" << endl;


    cout << endl << "Detailed Summary:" << endl;
    cout << "Product Name: " << productName << endl;
    cout << "Product Category: " << productCategory << endl;
    cout << "Initial Inventory: " << initialInventoryQuantity << endl;
    cout << "Price per Unit: $" << productPrice << endl;
    cout << "Items Sold: " << numberOfItemsSold << endl;
    cout << "New Inventory: " << newInventory << endl;
    cout << "Total Sales: $" << totalSales << endl;
    cout << "Inventory Status: " << inventoryStatus << endl;
    cout << "Helper Variable (auto): " << totalSalesCopy << endl;
    cout << "Helper Variable (decltype): " << inventoryCopy << endl;
    cout << "Sample Product Description: " << productDescription << endl;
    cout << "Sample Category: " << sampleCategory << endl;
    cout << "Sample Price: $" << samplePrice;


    return 0;
}