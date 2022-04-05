#include <iostream>


using namespace std;

int *arrayExpander(int[], int size);

int main(){
    int arr[] = { 1, 2, 3, 4, 5};
    int size = 5;
    
    int *arrPtr = arrayExpander(arr, size);
    
    for (int i = 0; i < size * 2; i++){
        cout << arrPtr[i] << endl;
    }
    
    return 0;
}
int *arrayExpander(int arr[], int size){
    int *expanderArr = new int[size * 2];
    
    for (int i = 0; i < size * 2; i++){
        expanderArr[i] = arr[i];
    }
    
    return expanderArr;
}