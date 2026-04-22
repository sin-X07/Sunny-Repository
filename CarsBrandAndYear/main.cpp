#include<iostream>
#include"Car.h"

using namespace std;

int main() {
    int n;
    cout << "how many cars do you wish to catalog? ";
    cin >> n;
    cin.ignore();
    
    CarsInformation* cars = new CarsInformation[n];

    for (int i=0; i<n; i++) {
        cout << "Car #" << i + 1 << ":" << endl;
        cout << "Please enter the make: ";
        getline(cin, cars[i].brand);
        cout << "Please enter the year made: ";
        cin >> cars[i].year;
        cin.ignore();
    }

    cout << "Here is your collection:" << endl;
    for (int i=0; i<n; i++) {
        cout << cars[i].year << " " << cars[i].brand << endl;
    }
    
    return 0;
}