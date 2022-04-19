#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Employee{
    string name1;           //first name
    string name2;           //last name
    string address;
    string city;
    string state;
    int zip;
    string telephoneNum;    //to make sure that any type of input enters (- or ())
    string position;
    string jobTitle;
    string paymentType;
};

void displayMenu(){
    cout << endl;
    cout << "0 = Close Program\n";
    cout << "1 = Add New Employee\n";
    cout << "2 = Display Existing Employees\n";
    cout << "3 = Delete Employees\n";
    cout << "4 = Edit Existing Employees\n";
    cout << "5 = Display Whole File\n" << endl << endl; 
}

void addRecord(){
    fstream file("Employee.txt", ios::out | ios::app);
    Employee emp;

    cout << "Enter data of the new employee.\n";
    getchar();

    do{
        cout << "First Name: ";
        getline(cin,emp.name1);
    }
    while (emp.name1 == "");
    
    do{
        cout << "Last Name: ";
        getline(cin,emp.name2);
    }
    while (emp.name2 == "");

    do{
        cout << "Address: ";
        getline(cin,emp.address);
    }
    while (emp.address == "");
    
    do{
        cout << "City: ";
        getline(cin,emp.city);
    }
    while (emp.city == "");
    
    do{
        cout << "State: ";
        getline(cin,emp.state);
    }
    while (emp.state == "");

    do{
        cout << "ZIP Code: ";
        cin >> emp.zip;
    }
    while (emp.zip < 0);
    getchar();

    do{
        cout << "Telephone Number: ";
        getline(cin,emp.telephoneNum);
    }
    while (emp.telephoneNum == "");
    
    do{
        cout << "Position: ";
        getline(cin,emp.position);
    }
    while (emp.position == "");
    do{
        cout << "Job Title: ";
        getline(cin,emp.jobTitle);
    }
    while (emp.jobTitle == "");
    do{
        cout << "Payment Type: ";
        getline(cin,emp.paymentType);
    }
    while (emp.paymentType == "");

    file << emp.name1 << endl;
    file << emp.name2 << endl;
    file << emp.address << endl;
    file << emp.city << endl;
    file << emp.state << endl;
    file << emp.zip << endl;
    file << emp.telephoneNum << endl;
    file << emp.position << endl;
    file << emp.jobTitle << endl;
    file << emp.paymentType << endl;

    file.close();
}

void displayRecord(){
    fstream file("Employee.txt", ios::in);

    if (file.fail())
        cout << "The file doesn't exist" << endl;
    else{
        string name1;
        string name2;
        Employee emp;

        cout << "Enter name of the employee\n";
        cout << "First Name: ";
        getchar();
        getline(cin, name1);
        cout << "\nLast Name: ";
        getchar();
        getline(cin, name2);
        cout << endl;

        while(!file.eof()){
            getline(file, emp.name1);
            getline(file, emp.name2);
            getline(file, emp.address);
            getline(file, emp.city);
            getline(file, emp.state);
            file >> emp.zip;
            file.get();
            getline(file, emp.telephoneNum);
            getline(file, emp.position);
            getline(file, emp.jobTitle);
            getline(file, emp.paymentType);

            if (name1 == emp.name1){
                    /*if (name2 == emp.name2){*/
                cout << "Employee's name: " << emp.name1 << " " << emp.name2 << endl;
                cout << "Address: " << emp.address << endl;
                cout << "City: " << emp.city << endl;
                cout << "State: " << emp.state << endl;
                cout << "ZIP Code: " << emp.zip << endl;
                cout << "Telephone Number: " << emp.telephoneNum << endl;
                cout << "Position: " << emp.position << endl;
                cout << "Job Title: " << emp.jobTitle << endl;
                cout << "Payment Type: " << emp.paymentType << endl << endl;
                break;
                /*}*/
            }
        }
    }
    file.close();
}

void deleteRecord(){
    fstream file("Employee.txt", ios::in);
    fstream copy("copy.txt", ios::out);

    string name1;
    string name2;
    Employee tmp;

    cout << "Enter First Name: ";
    getchar();
    getline(cin, name1);

    cout << "\nEnter Last Name: ";
    getchar();
    getline(cin, name2);

    string line;

    while (!file.eof()) {
        getline(file, line);
        copy << line << endl;
    }
    file.close();
    file.open("Employee.txt", ios::out);
    copy.close();
    copy.open("copy.txt", ios::in);
    copy.seekg(0, ios::beg);

    while (!copy.eof()){
        getline(copy, tmp.name1);
        getline(copy,tmp.name2);
        getline(copy, tmp.city);
        getline(copy, tmp.state);
        copy >> tmp.zip;
        copy.get();
        getline(copy, tmp.telephoneNum);
        getline(copy, tmp.position);
        getline(copy, tmp.jobTitle);
        getline(copy, tmp.paymentType);

        if (name1 != tmp.name1){
            /*if (name2 != tmp.name2){*/
                file << tmp.name1 << endl;
                file << tmp.name2 << endl;
                file << tmp.address << endl;
                file << tmp.city << endl;
                file << tmp.state << endl;
                file << tmp.zip << endl;
                file << tmp.telephoneNum << endl;
                file << tmp.position << endl;
                file << tmp.jobTitle << endl;
                file << tmp.paymentType << endl << endl;
            /*}*/
        }
    }

    file.close();
    copy.clear();
    copy.close();
}

void changeRecord(){
    fstream file("Employee.txt", ios::in);
    fstream copy("copy.txt", ios::out);

    string name1;
    string name2;
    Employee tmp, emp;
    cout << "Enter the first name of the employee: ";
    getline(cin, name1);
    cout << "Enter the last name of the employee: ";
    getline(cin, name2);

    cout << "Enter new data for that account.\n";
    getchar();
    do{
        cout << "First Name: ";
        getline(cin,emp.name1);
    }
    while (emp.name1 == "");
    
    do{
        cout << "Last Name: ";
        getline(cin,emp.name2);
    }
    while (emp.name2 == "");

    do{
        cout << "Address: ";
        getline(cin,emp.address);
    }
    while (emp.address == "");
    
    do{
        cout << "City: ";
        getline(cin,emp.city);
    }
    while (emp.city == "");
    
    do{
        cout << "State: ";
        getline(cin,emp.state);
    }
    while (emp.state == "");

    do{
        cout << "ZIP Code: ";
        cin >> emp.zip;
    }
    while (emp.zip < 0);
    getchar();
    
    do{
        cout << "Telephone Number: ";
        getline(cin,emp.telephoneNum);
    }
    while (emp.telephoneNum == "");
    
    do{
        cout << "Position: ";
        getline(cin,emp.position);
    }
    while (emp.position == "");
    do{
        cout << "Job Title: ";
        getline(cin,emp.jobTitle);
    }
    while (emp.jobTitle == "");
    do{
        cout << "Payment Type: ";
        getline(cin,emp.paymentType);
    }
    while (emp.paymentType == "");

    string line;
    while(!file.eof()){
        getline(file, line);
        copy << line << endl;
    }

    file.close();
    file.open("Employee.txt", ios::out);
    copy.close();
    copy.open("copy.txt", ios::in);
    copy.seekg(0, ios::beg);

    while (!copy.eof()){
        getline(copy, tmp.name1);
        getline(copy,tmp.name2);
        getline(copy, tmp.city);
        getline(copy, tmp.state);
        copy >> tmp.zip;
        copy.get();
        getline(copy, tmp.telephoneNum);
        getline(copy, tmp.position);
        getline(copy, tmp.jobTitle);
        getline(copy, tmp.paymentType);

        if (name1 == tmp.name1){
            /*if(name2 == tmp.name2){*/
                file << emp.name1 << endl;
                file << emp.name2 << endl;
                file << emp.address << endl;
                file << emp.city << endl;
                file << emp.state << endl;
                file << emp.zip << endl;
                file << emp.telephoneNum << endl;
                file << emp.position << endl;
                file << emp.jobTitle << endl;
                file << emp.paymentType << endl;
            /*}*/
        }
        else{
            file << tmp.name1 << endl;
            file << tmp.name2 << endl;
            file << tmp.address << endl;
            file << tmp.city << endl;
            file << tmp.state << endl;
            file << tmp.zip << endl;
            file << tmp.telephoneNum << endl;
            file << tmp.position << endl;
            file << tmp.jobTitle << endl;
            file << tmp.paymentType << endl << endl;
        }
    }
    file.close();
    copy.clear();
    copy.close();
}

void displayFile(){
    fstream file("Employee.txt", ios::in);

    if(file.fail())
        cout << "The file doesn't exist...\n";
    else{
        Employee emp;

        while(!file.eof()){
            getline(file, emp.name1);
            getline(file, emp.name2);
            getline(file, emp.address);
            getline(file, emp.city);
            getline(file, emp.state);
            file >> emp.zip;
            file.get();
            getline(file, emp.telephoneNum);
            getline(file, emp.position);
            getline(file, emp.jobTitle);
            getline(file, emp.paymentType);

            cout << "Employee's name: " << emp.name1 << " " << emp.name2 << endl;
            cout << "Address: " << emp.address << endl;
            cout << "City: " << emp.city << endl;
            cout << "State: " << emp.state << endl;
            cout << "ZIP Code: " << emp.zip << endl;
            cout << "Telephone Number: " << emp.telephoneNum << endl;
            cout << "Position: " << emp.position << endl;
            cout << "Job Title: " << emp.jobTitle << endl;
            cout << "Payment Type: " << emp.paymentType << endl << endl;
        }
    }
    file.close();
}

int main(){
    fstream file ("Employee.txt", ios::out);
    file.clear();
    file.close();

    int choice = 0;
    do{
        displayMenu();
        cin >> choice;

        switch (choice){
            case 1:
                addRecord();
                break;
            case 2:
                displayRecord();
                break;
            case 3:
                deleteRecord();
                break;
            case 4:
                changeRecord();
                break;
            case 5:
                displayFile();
                break;
            default:
                break;
        }
        cout << endl;
    }
    while (choice != 0);

    return 0;
}