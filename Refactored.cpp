#include <iostream>

using namespace std;

class Product {
public:
    int price;
    string name;
    string brand;
    int quantity;
    int total;

    Product(int _price, const string& _name, const string& _brand)
        : price(_price), name(_name), brand(_brand), quantity(0), total(0) {}

    void display() {
        cout << name << "\t\t" << brand << "\t\t" << price << "\t\t" << quantity << "\t\t" << total << endl;
    }

    void buyProduct() {
        cout << "\nDo you want to buy " << name << "?(y/n): ";
        char choice;
        cin >> choice;
        if (choice == 'y') {
            cout << "\nPrice of 1 " << name << ": " << price << endl;
            cout << "Enter quantity: ";
            cin >> quantity;
            total = quantity * price;
        }
    }
};

class ElectronicStore {
private:
    Product* menu[5];
    int grandTotal;

public:
    ElectronicStore() : grandTotal(0) {
        // Adding products to the menu
        menu[0] = new Product(30000, "Laptop", "Samsung");
        menu[1] = new Product(10000, "Mobile", "Apple");
        menu[2] = new Product(8000, "TV", "Sony");
        menu[3] = new Product(25000, "Watch", "Apple");
        menu[4] = new Product(20000, "PC", "Dell");
    }

    ~ElectronicStore() {
        // Deleting allocated memory for products
        for (int i = 0; i < 5; ++i) {
            delete menu[i];
        }
    }

    void displayMenu() {
        cout << "===================WELCOME TO ELECTRONIC STORE=================" << endl;
        cout << "\t\t\tMENU" << endl;
        cout << "Product name\t Brand\t\tPrice" << endl;

        for (int i = 0; i < 5; ++i) {
            cout << menu[i]->name << "\t\t" << menu[i]->brand << "\t\t" << menu[i]->price << endl;
        }

        cout << "==============================================================" << endl;
    }

    void buyProducts() {
        for (int i = 0; i < 5; ++i) {
            menu[i]->buyProduct();
            grandTotal += menu[i]->total;
        }
    }

    void displayBill() {
        cout << "-------------------------------------------------------------------" << endl;
        cout << "                             BILL                                      " << endl;
        cout << "-------------------------------------------------------------------" << endl;
        cout << "Product name\tBrand     \tprice\t\tquantity\ttotal" << endl;

        for (int i = 0; i < 5; ++i) {
            if (menu[i]->quantity > 0) {
                menu[i]->display();
            }
        }

        cout << "                                          \t\tgtotal = " << grandTotal << endl;
        cout << "-----------------------------------------------------------------" << endl;
        cout << "\n\nTHANK YOU for coming here!" << endl;
    }
};

int main() {
    ElectronicStore store;
    store.displayMenu();
    store.buyProducts();
    
    store.displayBill();

    system("pause");
    return 0;
}

