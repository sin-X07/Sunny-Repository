#include<iostream>

using namespace std;

void menu() {
    cout << "Please enter one of the following choices:" << endl;
    cout << "c) carnivore         p) painist" << endl;
    cout << "t) tree              g) game" << endl;
}

int main() {
    menu();
    char ch;
    string ans;
    cin.get(ch);
    switch (ch) {
        case 'c':
            ans = "carnivore";
            break;
        case 'p':
            ans = "painist";
            break;
        case 't':
            ans = "tree";
            break;
        case 'g':
            ans = "game";
            break;
        default:
            cout << "Please enter a c, p, t, or g: ";
    }
    cout << "A maple is a " << ans << "." << endl;

    return 0;
}