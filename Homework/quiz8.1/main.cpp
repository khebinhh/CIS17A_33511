#include <iostream>
using namespace std;

//function prototype
int searchList(const int [], int, int);
const int k = 10;

int main(){
    int nMembers[k] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int currentMembers;
    int memberID;
    
    //get memberID to search
    cout << "Please enter your Member ID: ";
    cin >> memberID;
    
    //Search
    nMembers = searchList(nMembers, k, memberID);
    
    if (nMembers == -1)
        cout << "That Member ID does not exist. \n";
    else{
        cout << nMembers <<  " is found!\n";
    }
    return 0;
}

int searchList(const int list[], int numElems, int value){
    int index = 0, 
        position = -1;
    bool isAMember = false;
    
    while (index < numElems&& !isAMember){
        if (list[index] == value){
            isAMember = true;
            position = index;
        }
        index++;
    }
    return position;
}