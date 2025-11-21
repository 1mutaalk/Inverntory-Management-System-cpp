#include <iostream>
#include <string>
using namespace std;

string ProductName[100];
int ProductID[100];
int ProductPrice[100];
int ProductQuantity[100];
int Productcount = 0;

char Login() {
    char login;
    cout << "Please Log in to use our services.\nC for Customer, A for Admin: ";
    cin >> login;
    while (login != 'A' && login != 'a' && login != 'C' && login != 'c') {
        cout << "Enter a valid input (A/C): ";
        cin >> login;
    }
    return login;
}

int Passwordcheck() {
    int password;
    char Status;
    cout << "Enter the Password: ";
    cin >> password;
    while (password != 2468) {
        cout << "Invalid Password! Do you want to continue? (Y/N): ";
        cin >> Status;
        if (Status == 'Y' || Status == 'y') {
            cout << "Enter the Password: ";
            cin >> password;
        }
        else if (Status == 'N' || Status == 'n') {
            return 0;
        }
    }
    return 1;
}

void addProduct() {
    int n;
    string Name;
    cout << "How many Products do you want to add: ";
    cin >> n;
    if (n <= 0) {
        cout << "Invalid number of products.\n";
        return;
    }
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cout << "Enter Product Name: ";
        getline(cin, Name);
        for (int j = 0; j < Name.length(); j++) {
            if (Name[j] >= 'a' && Name[j] <= 'z') {
                Name[j] = Name[j] - 32;
            }
        }
        ProductName[Productcount] = Name;
        ProductID[Productcount] = Productcount;
        cout << "Enter Product Price: ";
        cin >> ProductPrice[Productcount];
        cout << "Enter Product Quantity: ";
        cin >> ProductQuantity[Productcount];
        if (ProductPrice[Productcount] < 0 || ProductQuantity[Productcount] < 0) {
            cout << "Invalid price or quantity.\n";
            return;
        }
        cout << "Product added Successfully! Product ID is " << Productcount << endl;
        Productcount++;
        cin.ignore();
    }
}

void editQuantity() {
    if (Productcount == 0) {
        cout << "No products available to edit.\n";
        return;
    }
    int ID, NewQuantity;
    char Status;
    do {
        cout << "Enter ID of Product: ";
        cin >> ID;
        if (ID >= 0 && ID < Productcount) {
            cout << "Current Quantity of " << ProductName[ID] << ": " << ProductQuantity[ID] << endl;
            cout << "Enter new Quantity: ";
            cin >> NewQuantity;
            if (NewQuantity >= 0) {
                ProductQuantity[ID] = NewQuantity;
                cout << "Quantity updated successfully!" << endl;
            }
            else {
                cout << "Invalid quantity.\n";
            }
        }
        else {
            cout << "Invalid Product ID!\n";
        }
        cout << "Do you want to edit another product? (Y/N): ";
        cin >> Status;
    } while (Status == 'Y' || Status == 'y');
}

void editPrice() {
    if (Productcount == 0) {
        cout << "No products available to edit.\n";
        return;
    }
    int ID, NewPrice;
    char Status;
    do {
        cout << "Enter Product ID: ";
        cin >> ID;
        if (ID >= 0 && ID < Productcount) {
            cout << "Previous Price of " << ProductName[ID] << ": " << ProductPrice[ID] << endl;
            cout << "Enter new Price: ";
            cin >> NewPrice;
            if (NewPrice >= 0) {
                ProductPrice[ID] = NewPrice;
                cout << "Price updated successfully!" << endl;
            }
            else {
                cout << "Invalid price." << endl;
            }
        }
        else {
            cout << "Invalid Product ID!" << endl;
        }
        cout << "Do you want to edit another product? (Y/N): ";
        cin >> Status;
        while (Status != 'Y' && Status != 'y' && Status != 'N' && Status != 'n') {
            cout << "Enter a valid input (Y/N): ";
            cin >> Status;
        }
    } while (Status == 'Y' || Status == 'y');
}

int Discount(int Cost) {
    if (Cost > 10000) return Cost - (Cost * 10) / 100;
    else if (Cost > 5000) return Cost - (Cost * 5) / 100;
    else return Cost;
}

int SalesTax(int Cost) {
    return Cost + (Cost * 16) / 100;
}

void Customer() {
    if (Productcount == 0) {
        cout << "No products available for purchase.\n";
        return;
    }
    string Product, CustomerName, Address;
    int ID = -1, Quantity, Cost,  DiscountedCost, TaxCost;
	double number;
    cin.ignore();
    cout << "Enter Product Name: ";
    getline(cin, Product);
    for (int j = 0; j < Product.length(); j++) {
        if (Product[j] >= 'a' && Product[j] <= 'z') {
            Product[j] = Product[j] - 32;
        }
    }
    for (int i = 0; i < Productcount; i++) {
        if (ProductName[i] == Product) {
            ID = i;
            break;
        }
    }
    if (ID == -1) {
        cout << "Product not found!" << endl;
        return;
    }
    cout << "Product Price: " << ProductPrice[ID] << endl;
    cout << "Available Quantity: " << ProductQuantity[ID] << endl;
    cout << "Enter Quantity: ";
    cin >> Quantity;
    while (Quantity <= 0 || Quantity > ProductQuantity[ID]) {
        cout << "Invalid or not enough stock. Available Quantity: " << ProductQuantity[ID] << endl;
        cout << "Enter Quantity: ";
        cin >> Quantity;
    }
    Cost = ProductPrice[ID] * Quantity;
    ProductQuantity[ID] -= Quantity;
    cin.ignore();
    cout << "Please provide your details.\nName: ";
    getline(cin, CustomerName);
    cout << "Address: ";
    getline(cin, Address);
    cout << "Mobile Number: ";
    cin >> number;
    DiscountedCost = Discount(Cost);
    TaxCost = SalesTax(DiscountedCost);
    cout << "\n------- Bill -------" << endl;
    cout << "Customer: " << CustomerName << endl;
    cout << "Product: " << ProductName[ID] << endl;
    cout << "Quantity: " << Quantity << endl;
    cout << "Price: " << Cost << endl;
    cout << "Discounted Price: " << DiscountedCost << endl;
    cout << "Total (after discount + tax): Rs. " << TaxCost << endl;
    cout << "Thank you for shopping!" << endl;
    cout << "----------------------";
}

void admin() {
    int n;
    do {
        cout << "\n1. Add Product\n2. Edit Product Quantity\n3. Edit Product Price\n4. Quit\nEnter choice: ";
        cin >> n;
        while (n != 1 && n != 2 && n != 3 && n != 4) {
            cout << "Enter a valid input (1-4): ";
            cin >> n;
        }
        if (n == 1) addProduct();
        else if (n == 2) editQuantity();
        else if (n == 3) editPrice();
    } while (n != 4);
}

int main() {
    char login, Status;
    do {
        login = Login();
        if (login == 'A' || login == 'a') {
            if (Passwordcheck()) admin();
            else return 0;
        }
        else if (login == 'C' || login == 'c') Customer();
        cout << "\nDo you want to return to main menu? (Y/N): ";
        cin >> Status;
        while (Status != 'Y' && Status != 'y' && Status != 'N' && Status != 'n') {
            cout << "Enter a valid input (Y/N): ";
            cin >> Status;
        }
    } while (Status == 'Y' || Status == 'y');
    cout << "Thanks for visiting!" << endl;
    return 0;
}
