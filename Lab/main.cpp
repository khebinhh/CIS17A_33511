#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    string filename;

    const int MONTHS = 3;

    cout << "\nEnter filename with monthly data: ";
    cin >> filename;

    fstream file(filename, ios::in);

    if (!file)
    {
        cerr << "\nCouldn't open file for reading!!!\nExiting...\n";
        return 0;
    }

    string month_names[3];
    float rain_fall[3];

    float avg_rain_fall = 0;

    for (int i = 0; i < 3; ++i)
    {
        file >> month_names[i];
        file >> rain_fall[i];

        avg_rain_fall += rain_fall[i];
    }

    // Dividing by total
    avg_rain_fall /= MONTHS;

    cout << "The average rainfall for " << month_names[0] << ", " << month_names[1] << ", and " << month_names[2]
         << " is: " << fixed << setprecision(2) << avg_rain_fall << endl;

    return 0;
}
