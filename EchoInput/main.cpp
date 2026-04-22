#include<iostream>
#include<cctype>
#include<string>

using namespace std;

int main() {
    string ans;
    char ch;
    cout << "Input context: ";
    while (cin.get(ch)) {
        if (isdigit(ch)) continue;
        if (ch == '@') break;
        if (islower(ch)) {
            ch = toupper(ch);
        } else {
        ch = tolower(ch);
        }
        ans += ch;
    }
    cout << "Echo input: " << ans << endl;
    
    return 0;
}