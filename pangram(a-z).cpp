#include <iostream>
using namespace std;

int main() {
    string str;
    getline(cin, str);

    int mask = 0;

    for(int i = 0; str[i]; i++) {
        char ch = str[i];

        if(ch >= 'a' && ch <= 'z') {
            mask |= (1 << (ch - 'a'));
        }
    }

    if(mask == (1 << 26) - 1)
        cout << "All lowercase alphabets are present";
    else
        cout << "Not all lowercase alphabets are present";

    return 0;
}
