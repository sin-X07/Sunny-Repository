#include<iostream>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include"LAO.h"

using namespace std;

int main() {
    srand((unsigned)time(NULL));
    int iva = (rand() % 99) + 1;
    int ivb = (rand() % 99) + 1;

    if (iva < ivb) swap(iva, ivb);

    LAO lao(iva, ivb);

    cout << "iva = " << iva << "   ivb = " << ivb << endl;

    switch (lao.check()) {
        case 0:
            cout << "iva + ivb = " << lao.add() << endl;
            cout << "iva - ivb = " << lao.sub() << endl;
            cout << "iva * ivb = " << lao.multiply() << endl;
            cout << "iva / ivb = " << lao.division() << endl;       
            break;   
        case 1:
            cout << "iva + ivb = " << lao.add() << endl;
            cout << "iva - ivb = " << lao.sub() << endl;
            cout << "iva * ivb = " << lao.multiply() << endl;
            cout << "Division can't be zero!" << endl;
            break;
        case 2:
            cout << "iva + ivb = " << lao.add() << endl;
            cout << "iva - ivb = " << lao.sub() << endl;
            cout << "iva * ivb = " << lao.multiply() << endl;
            cout << "No integer solution!" << endl;
            break;
        case 3:
            cout << "Beyond range!" << endl;
            break;
    }


    return 0;
}