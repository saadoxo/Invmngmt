#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

struct Item {
    int id;
    string name;
    int quantity;
    double price;
    Item* next;
};
class Inventory {
private:
    Item* head;
public:
    Inventory() {
        head = NULL;
    }
//adding item in inventory
    void addItem(int id, const string& name, int quantity, double price) {
        Item* newItem = new Item;
        newItem->id = id;
        newItem->name = name;
        newItem->quantity = quantity;
        newItem->price = price;
        newItem->next = NULL;

        if (head == NULL) {
            head = newItem;
        } else {
            Item* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newItem;
        }
        cout<<"Item added to inventory."<<endl;
    }
//displaying items
    void displayItems() {
        if (head == NULL) {
            cout<<"Inventory is empty."<<endl;
            return;
        }

        Item* current = head;
        cout<<"Inventory:"<<endl;
        cout<<"----------------------------------" <<endl;
        while (current != NULL) {
            cout<<"ID: " << current->id <<endl;
            cout<<"Name: " << current->name <<endl;
            cout<<"Quantity: " << current->quantity <<endl;
            cout<<"Price: $" << current->price <<endl;
            cout<<"----------------------------------" <<endl;
            current = current->next;
        }
    }

//item searching
    void searchItem(const string& name) {
        Item* current = head;
        while (current != NULL) {
            if (current->name == name) {
                cout<<"Item found:" << endl;
                cout<<"ID: "<< current->id <<endl;
                cout<<"Name: "<< current->name <<endl;
                cout<<"Quantity: "<< current->quantity <<endl;
                cout<<"Price: $"<< current->price <<endl;
                return;
            }
            current = current->next;
        }
        cout<<"Item not found."<<endl;
    }

//user buying item(decrease its quantity)
    void buyItem(const string& name, int quantity) {
        Item* current = head;
        while (current != NULL) {
            if (current->name == name) {
                if (current->quantity >= quantity) {
                    current->quantity -= quantity;
                    cout<<"Item purchased successfully."<<endl;
                    return;
                } else {
                    cout<<"Insufficient quantity available."<<endl;
                    return;
                }
            }
            current = current->next;
        }
        cout<<"Item not found."<<endl;
    }

//deleting an item
    void deleteItem(int id) {
        if (head == NULL) {
            cout<<"Inventory is empty."<< endl;
            return;
        }

        if (head->id == id) {
            Item* temp = head;
            head = head->next;
            delete temp;
            cout<<"Item deleted from inventory."<<endl;
            return;
        }

        Item* current = head;
        while (current->next != NULL) {
            if (current->next->id == id) {
                Item* temp = current->next;
                current->next = current->next->next;
                delete temp;
                cout<<"Item deleted from inventory."<<endl;
                return;
            }
            current = current->next;
        }
        cout << "Item not found." << endl;
    }

//updating an item
    void updateItem(int id, const string& name, int quantity, double price) {
        Item* current = head;
        while (current != NULL) {
            if (current->id == id) {
                current->name = name;
                current->quantity = quantity;
                current->price = price;
                cout<<"Item updated successfully."<<endl;
                return;
            }
            current = current->next;
        }
        cout<<"Item not found." << endl;
    }
};
void adminMenu(Inventory& inventory) {
    int option, id, quantity;
    string name;
    double price;

    while (true) {
        cout<<"\n------- ADMIN MENU -------"<<endl;
        cout<<"1. Add Item"<<endl;
        cout<<"2. Delete Item"<<endl;
        cout<<"3. Update Item"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Choose an option: ";
        cin>>option;

        switch (option) {
            case 1:
				system("CLS");
				cout<<"---------ADDING ITEM----------"<<endl;
                cout<<"Enter the Item ID: ";
                cin>>id;
                cout<<"Enter the Item name: ";
                cin.ignore();
                getline(cin, name);
                cout<<"Enter the quantity: ";
                cin>>quantity;
                cout<<"Enter the price: $";
                cin>>price;
                inventory.addItem(id, name, quantity, price);
                break;
            case 2:
            	cout<<"--------DELETING ITEM----------"<<endl;
                cout<< "Enter the Item ID: ";
                cin>>id;
                inventory.deleteItem(id);
                break;
            case 3:
            	cout<<"--------UPDATING ITEM----------"<<endl;
                cout<<"Enter the Item ID: ";
                cin>>id;
                cout<<"Enter the Item name: ";
                cin.ignore();
                getline(cin, name);
                cout<<"Enter the quantity: ";
                cin>>quantity;
                cout<<"Enter the price: $";
                cin>>price;
                inventory.updateItem(id, name, quantity, price);
                break;
            case 4:
                cout<<"Exiting admin menu." << endl;
                return;
            default:
                cout<<"Invalid option. Try again." << endl;
                break;
        }
    }
}

int main() {
    Inventory inventory;
    int option, quantity;
    string name;
    string pass,passcode;

    while (true) {
    	cout<<"\n==============================="<<endl;
    	cout<<  "=====- Inventory system -======"<<endl;
        cout<<  "=====------- MENU -------======"<<endl;
        cout<<  "=====--1. Display Items -======"<<endl;
        cout<<  "=====--2. Search Item ---======"<<endl;
        cout<<  "=====--3. Buy Item ------======"<<endl;
        cout<<  "=====--4. Admin Menu ----======"<<endl;
        cout<<  "=====--5. Exit ----------======"<<endl;
        cout<<  "==============================="<<endl;
        cout<<"Choose an option: ";
        cin>> option;

        switch (option) {
            case 1:
            	system("CLS");
                inventory.displayItems();
                break;
            case 2:
                cout<<"Enter the Item name: ";
                cin.ignore();
                getline(cin, name);
                inventory.searchItem(name);
                break;
            case 3:
                cout<<"Enter the Item name: ";
                cin.ignore();
                getline(cin, name);
                cout<<"Enter the quantity: ";
                cin>>quantity;
                inventory.buyItem(name, quantity);
                break;
            case 4:
            	//admin password is here
   	  			passcode="admin";
     			cout<<"Enter the password: "<<endl;
     			cin>>pass;
     			if(pass==passcode)
     			{
         		system("CLS");
         		adminMenu(inventory);            
     			}
     			else
     			{
        		cout<<"wrong Password"<<endl;
     			}
                break;
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid option. Try again." << endl;
                break;
        }
    }
    return 0;
}
