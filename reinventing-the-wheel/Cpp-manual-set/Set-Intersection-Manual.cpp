#include <iostream>
using namespace std;

class IntegerSet {
private:
    int* elements;
    int size;

public:
    
    IntegerSet(int input[], int s) {
        size = s;
        elements = new int[size];
        for (int i = 0; i < size; i++) {
            elements[i] = input[i];
        }
    }

    
    ~IntegerSet() {
        delete[] elements;
    }

    // The Intersection Logic
    
    int* intersection(IntegerSet& otherSet, int& resultSize) {
       
        int* tempResult = new int[size]; 
        int count = 0;

        
        for (int i = 0; i < size; i++) {
            
            
            for (int j = 0; j < otherSet.size; j++) {
                
                if (this->elements[i] == otherSet.elements[j]) {
                    
                    tempResult[count] = this->elements[i];
                    count++;
                    break; 
                }
            }
        }

        resultSize = count;
        return tempResult;
    }

    t
    void printSet() {
        cout << "{ ";
        for (int i = 0; i < size; i++) {
            cout << elements[i] << (i < size - 1 ? ", " : " ");
        }
        cout << "}" << endl;
    }
};

int main() {
   
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {3, 4, 5, 6, 7};

  
    IntegerSet setA(arr1, 5);
    IntegerSet setB(arr2, 5);

    cout << "Set A: ";
    setA.printSet();
    cout << "Set B: ";
    setB.printSet();

    // Calculation of Set Intersection
    int newSize = 0;
    int* result = setA.intersection(setB, newSize);

    // Printing the Result
    cout << "Intersection: { ";
    for(int i = 0; i < newSize; i++) {
        cout << result[i] << (i < newSize - 1 ? ", " : " ");
    }
    cout << "}" << endl;

    // Cleaning up the result array
    delete[] result;

    return 0;
}
