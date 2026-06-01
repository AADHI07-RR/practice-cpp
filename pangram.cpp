#include <iostream>
using namespace std;

int main() {
    string str;
    getline(cin, str);

    int lowerFlag = 0;
    int upperFlag = 0;
    int digitFlag = 0;

    for(int i = 0; str[i]; i++) {
        char ch = str[i];

        if(ch >= 'a' && ch <= 'z') {
            lowerFlag |= (1 << (ch - 'a'));
        }
        else if(ch >= 'A' && ch <= 'Z') {
            upperFlag |= (1 << (ch - 'A'));
        }
        else if(ch >= '0' && ch <= '9') {
            digitFlag |= (1 << (ch - '0'));
        }
    }

    bool lower = (lowerFlag == (1 << 26) - 1);
    bool upper = (upperFlag == (1 << 26) - 1);
    bool digits = (digitFlag == (1 << 10) - 1);

    if(lower)
        cout << "All lowercase alphabets are present\n";
    else
        cout << "Not all lowercase alphabets are present\n";

    if(upper)
        cout << "All uppercase alphabets are present\n";
    else
        cout << "Not all uppercase alphabets are present\n";

    if(digits)
        cout << "All digits (0-9) are present\n";
    else
        cout << "Not all digits (0-9) are present\n";

    return 0;
}
//Add bitmasking solution for alph
