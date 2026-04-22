#include<iostream>
#include"LAO.h"

using namespace std;

    LAO::LAO(int iva, int ivb) : iva(iva), ivb(ivb) {}

    int LAO::add() const {
        return iva + ivb;
    }

    int LAO::sub() const {
        return iva + ivb;
    }

    int LAO::multiply() const {
        return iva * ivb;
    }

    int LAO::division() const {
        return iva / ivb;
    }

    int LAO::check() {
        if (ivb == 0) {
            //cout << "Division can't be zero!" << endl;
            return 1;
        }else if (iva % ivb != 0) {
            //cout << "No integer solution!" << endl;
            return 2;
        }else if (iva <= 0 || iva >= 100 || ivb <= 0 || ivb >= 100) {
            //cout << "Beyond range!" << endl;
            return 3;
        }else {
            return 0;
        }
    }