#include <iostream>
#include <string>
using namespace std;


class PaymentMethod {
protected:
    string ownerName;

public:
    PaymentMethod(string name) : ownerName(name) {}

    // Pure virtual function
    virtual void pay(float amount) = 0;

    // Virtual destructor is crucial here so the derived destructor gets called on delete
    virtual ~PaymentMethod() {
        cout << "  (System: Cleaning up payment resource for " << ownerName << ")\n";
    }
};

class CreditCard : public PaymentMethod {
private:
    string cardNumber;

public:
    CreditCard(string name, string cardNum)
        : PaymentMethod(name), cardNumber(cardNum) {}

    void pay(float amount) override {
        cout << "Processing Credit Card Payment...\n";
        cout << "Paid " << amount << " via Card ending in " << cardNumber 
             << " (Owner: " << ownerName << ")\n";
    }
};

class Bitcoin : public PaymentMethod {
private:
    string walletAddr;

public:
    Bitcoin(string name, string wallet)
        : PaymentMethod(name), walletAddr(wallet) {}

    void pay(float amount) override {
        cout << "Processing Crypto Transaction...\n";
        cout << "Paid " << amount << " via Bitcoin Wallet " << walletAddr 
             << " (Owner: " << ownerName << ")\n";
    }
};

int main() {
    int pin, choice;
    int password = 1234;
    float amount;
    string ownerName, cardNum, walletNum;

    cout << "Welcome to the Polymorphic Payment Gateway\n";
    
  
    cout << "Enter owner name: ";
    getline(cin, ownerName); 

    cout << "Enter pin: ";
    cin >> pin;

    if (pin == password) {
        cout << "Select payment method:\n1. Credit Card\n2. Bitcoin\n";
        cin >> choice;

        PaymentMethod* ptr = nullptr;

        cout << "Enter amount: ";
        cin >> amount;

        if (choice == 1) {
            cout << "Enter last 4 digits of card: ";
            cin >> cardNum;
           
            ptr = new CreditCard(ownerName, cardNum);
        } else {
            cout << "Enter wallet address: ";
            cin >> walletNum;
            
            ptr = new Bitcoin(ownerName, walletNum);
        }

        // Polymorphic call
        if (ptr != nullptr) {
            ptr->pay(amount);
            
            // CLEAN UP YOUR MEMORY
            delete ptr; 
            ptr = nullptr;
        }
    } else {
        cout << "Access Denied.\n";
    }

    return 0;
}
