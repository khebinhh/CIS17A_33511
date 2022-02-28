/*
    This program demonstrates the searchList function, which
    performs a linear search on an integer array.
*/
#include <iostream>
using namespace std;

//Function prototype
int searchList(const int [], int, int);
const int SIZE = 5;

int main(){
    int tests[SIZE] = {87, 75, 98, 100, 82};
    int results;

    //Search the array for 100.
    results = searchList(tests, SIZE, 100);

    //If searchList returned -1, then 100 was not found.
    if (results == -1)
    cout << "You did not earch 100 points on any test...\n";
    else{
        cout << "You earned 100 points on test ";
        cout << (results + 1) << endl;
    }
    return 0;
}

int searchList(const int list[], int NumElems, int value){
    int index = 0;          //used as a subscript to search array
    int position = -1;       //to record position of search value
    bool found = false;     //flag to indicate if the value was found

    while (index < NumElems && !found){
        if (list[index] == value){
            found = true;
            position = index;
        }
        index++;
    }
    return position;
}
