#include <iostream>
using namespace std;

class IntegerSet {
private:
    int elements[50] = {0};
    int count;

public:
    IntegerSet() {
        count = 0;
    }

    void add(int num) {
        // check for duplicate
        for (int i = 0; i < count; i++) {
            if (elements[i] == num) {
                cout << "A set can only contain unique values\n";
                return;
            }
        }

        // check capacity
        if (count >= 50) {
            cout << "Set is full\n";
            return;
        }

        // add element
        elements[count] = num;
        count++;
        cout << "Number added successfully\n";
    }

    void display() {
        cout << "Set elements: ";
        for (int i = 0; i < count; i++) {
            cout << elements[i] << " ";
        }
        cout << "\nTotal elements: " << count << endl;
    }
    
};

int main() {
    IntegerSet iset;
    int num;

    cout << "Enter integers (enter -1 to stop):\n";

    while (true) {
        cin >> num;
        if (num == -1) break;
        iset.add(num);
    }

    iset.display();
    return 0;
}
