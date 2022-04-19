#include <iostream>
#include <string>
using namespace std;

struct HourlyPaid{
    double HoursWorked;
    double HourlyRate;
};

struct Salaried{
    double Salary;
    double Bonus;
};

union Worker{
    HourlyPaid hourlyPaid;
    Salaried salaried;
};

int main(){
    Worker worker;
    int option;
    double totalSalary;
    while(true){  
        cout << "Please select your option \n";
        cout << "1. For HourlyPaid \n";
        cout << "2. For Salaried \n";
        cout << "3. For Exit \n";
        cin >> option;
        switch(option){
            case 1:
                HourlyPaid hourlyPaid;
                cout << "Enter Number of Hourse Worked: ";
                cin >> hourlyPaid.HoursWorked;
                cout << "Enter Hourly Rate: ";
                cin >> hourlyPaid.HourlyRate;               
                worker.hourlyPaid = hourlyPaid;
              
                totalSalary = worker.hourlyPaid.HoursWorked * worker.hourlyPaid.HourlyRate;
                cout << "Total Salary is :" << totalSalary << endl;
              
                break;
            case 2:
                Salaried salaried;
                cout << "Enter Salary: ";
                cin >> salaried.Salary;
                cout << "Enter Bonus: ";
                cin >> salaried.Bonus;               
                worker.salaried = salaried;
                  
                totalSalary = worker.salaried.Salary + worker.salaried.Bonus;
                cout << "Total Salary is: " << totalSalary << endl;
                break;
            case 3:
                break;
            default:
                cout << "Invalid Option\n";
        }
        if (option==3)
            break;
    }
    cout << "Thank you\n";
    return 0;
}