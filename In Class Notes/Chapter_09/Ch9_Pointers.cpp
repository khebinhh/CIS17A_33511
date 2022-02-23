#include <iostream>

using namespace std;

/*
9.1
    Getting the Address of a Variable
        Each variable in program is stored at a unique address
        Use address operator & to get address of a variable:

        int num = -99;
        cout << &num;       // prints address in hexadecimal

9.2 Pointer Variables
        Pointer variable: Often just called a pointer, it's a variable that holds an address.
        Because a pointer variable holds the address of another piece of data, it "points" to the data.
    Something Like Pointers: Arrays


*/

void showNumbers(int numbers[], int size){
    for (int i = 0; i < size; i++){
        cout << numbers[i] << " ";

    }
    cout << endl;
}

int main(){
    
    int x = 10;
    int *xptr = &x;

    int numbers[4] = {1, 2, 3, 4};


    cout << "X = " << x << endl;
    cout << "The address of x is " << &x << endl;
    cout << "The address of x is " << xptr << endl;
    
    showNumbers(numbers, 4);
        return 0;
}