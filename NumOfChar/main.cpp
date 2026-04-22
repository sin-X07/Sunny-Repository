#include<iostream>
#include<cstring>

using namespace std;

int main() {
    char* word = new char[50];
    int cnt = 0;
    const char* target = "done";

    cout << "Enter words (to stop, type the word done): ";
    cin >> word;
    cin.ignore();
    while (strcmp(word, target) != 0) {
        cin >> word;
        cnt++;
        cin.ignore();
    }
    cout << "You entered a totle of " << cnt << " words." <<endl;

    return 0;
}