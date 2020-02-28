#include <iostream>

using namespace std;

void reverse(string str) {
    int n = str.size();

    if (n == 1) {
        cout<<str<<endl;
    } else {
        cout<<str[n - 1];
        reverse(str.substr(0, n - 1));
    }

}

int main() {
    string str;
    cout<<"Enter a string ";
    cin>>str;

    reverse(str);
    
    return 0;
}