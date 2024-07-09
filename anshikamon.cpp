#include <iostream>
#include <string>
using namespace std;

int c;

class User {
private:
    string username;
    string password;
public:
    void setusername(const string& username) {
        this->username = username;
    }
    string getusername() const {
        return username;
    }
    void setpassword(const string& password) {
        this->password = password;
    }
    string getpassword() const {
        return password;
    }
};

class UserManager {
private:
    User users[10];
    int userCount = 0;
    int currentUser = -1;
public:
    bool signUp(const string& username, const string& password) {
        for (int i = 0; i < userCount; ++i) {
            if (users[i].getusername() == username) {
                cout << "Username already exists!🥺" << endl;
                return false;
            }
        }
        users[userCount].setusername(username);
        users[userCount].setpassword(password);
        userCount++;
        cout << "Sign up successful!👍" << endl;
        return true;
    }

    bool signIn(const string& username, const string& password) {
        for (int i = 0; i < userCount; ++i) {
            if (users[i].getusername() == username && users[i].getpassword() == password) {
                currentUser = i;
                cout << "Sign in successful!👍" << endl;
                return true;
            }
        }
        cout << "Invalid username or password!🥲" << endl;
        return false;
    }

    bool isSignedIn() const {
        return currentUser != -1;
    }
};

class home {
public:
    int id;
    string name;
    int price;
    friend class cart;
};

class cart {
public:
    home items[10];
    int prices[10];
    int total = 0;
    int count = 0;
    string coupon[1] = {"anshika50"};
    bool couponused[1] = {false};

    void addtocart(home* current) {
        if (count < 10) {
            items[count] = *current;
            prices[count] = current->price;
            count++;
            cout << current->name << " is added to cart" << endl;
            cout << endl;
        } else {
            cout << "Cart is full!🫣" << endl;
        }
    }

    void shoppingcart() {
        cout << "------------------------------------------------------------" << endl;
        for (int i = 0; i < count; i++) {
            cout << i + 1 << ") " << "Id: " << items[i].id << ", " << "Name: " << items[i].name << ", " << "Price: " << items[i].price << endl;
        }
        cout << "------------------------------------------------------------" << endl;
        cout << endl;
    }

    void removeitem(int idtoremove) {
        for (int i = 0; i < count; i++) {
            if (items[i].id == idtoremove) {
                cout << items[i].name << " is removed from your cart.🥺" << endl;
                for (int j = i; j < count - 1; j++) {
                    items[j] = items[j + 1];
                }
                count--;
                return;
            }
        }
        cout << "No such item is found in your cart" << endl;
    }

    void ap() {
        for (int i = 0; i < count; i++) {
            total += prices[i];
        }
        cout << "Total: " << total << " Rs" << endl;
        cout << "Order placed successfully.✔✅" << endl;
        cout << "Thanks for visiting 🥰."<<endl;
        cout << "***** Welcome to the Anshikamon... *****" << endl;
    }

    void disc() {
        string disc;
        cout << endl;
        cout << "Press 1. If you have any coupon." << endl;
        cout << "Press 2. Proceed to Checkout." << endl;
        cout << "Your Operation: ";
        cin >> c;
        if (c == 1) {
            shoppingcart();
            cout << "Enter the Coupon Code: ";
            cin >> disc;
            bool validcoupon = false;
            for (int i = 0; i < 1; i++) {
                if (coupon[i] == disc && !couponused[i]) {
                    total = total - 50000;
                    couponused[i] = true;
                    validcoupon = true;
                    cout << "Coupon applied successfully🎉" << endl;
                    break;
                }
            }
            if (!validcoupon) {
                cout << "Invalid coupon code or already used." << endl;
                cout << endl;
            }
            cout << "Bill:" << endl;
            shoppingcart();
            ap();
        } else if (c == 2) {
            cout << endl;
            cout << "Bill:" << endl;
            ap();
        } else {
            cout << "Invalid Operation.😒" << endl;
        }
    }
};

void menu(home &p1, home &p2, home &p3, home &p4, home &p5, cart &a) {
    home *current = nullptr;
    int rem;
    while (true) {
        cout << "***** MENU *****" << endl << endl;
        cout << "1) " << p1.name << ":" << p1.price << endl;
        cout << "2) " << p2.name << ":" << p2.price << endl;
        cout << "3) " << p3.name << ":" << p3.price << endl;
        cout << "4) " << p4.name << ":" << p4.price << endl;
        cout << "5) " << p5.name << ":" << p5.price << endl;
        cout << "6) Checkout" << endl;
        cout << "7) Exit" << endl;
        cout << "Select Items: ";
        cin >> c;
        if (c == 1) {
            current = &p1;
            a.addtocart(current);
        } else if (c == 2) {
            current = &p2;
            a.addtocart(current);
        } else if (c == 3) {
            current = &p3;
            a.addtocart(current);
        } else if (c == 4) {
            current = &p4;
            a.addtocart(current);
        } else if (c == 5) {
            current = &p5;
            a.addtocart(current);
        } else if (c == 6) {
            cout << endl;
            cout << "Your Cart:" << endl;
            a.shoppingcart();
            cout << "1. To add items" << endl;
            cout << "2. To remove items" << endl;
            cout << "3. To proceed" << endl;
            cout << "Your Operation: ";
            cin >> c;
            if (c == 1) {
                cout << endl;
                continue;
            } else if (c == 2) {
                cout << "Your Cart:" << endl;
                a.shoppingcart();
                cout << "Enter Item Id to Remove: ";
                cin >> rem;
                a.removeitem(rem);
            } else if (c == 3) {
                a.disc();
                break;
            }
        } else if (c == 7) {
            cout << "Bye!" << endl;
            break;
        } else {
            cout << "Invalid Input😒" << endl;
            cout << endl;
            continue;
        }
    }
}

int main() {
    UserManager userManager;
    home p1, p2, p3, p4, p5;
    cart a;

    p1.id = 1;
    p1.name = "PokemonGo Special Edition";
    p1.price = 10000000;

    p2.id = 2;
    p2.name = "Pokedex";
    p2.price = 500000;

    p3.id = 3;
    p3.name = "PokeWatch";
    p3.price = 1000000;

    p4.id = 4;
    p4.name = "Pokeballs";
    p4.price = 500000;

    p5.id = 5;
    p5.name = "Pikachu Special Edition Fluff Toy";
    p5.price = 963852741;

    int choice;
    string username, password;

    cout << "***** Welcome to the Anshikamon... *****" << endl;
    while (true) {
        cout << "1. Sign Up" << endl;
        cout << "2. Sign In" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            userManager.signUp(username, password);
        } else if (choice == 2) {
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            if (userManager.signIn(username, password)) {
                menu(p1, p2, p3, p4, p5, a);
            }
        } else if (choice == 3) {
            cout << "Bye!" << endl;
            break;
        } else {
            cout << "Invalid choice!😒" << endl;
        }
    }

    return 0;
}
