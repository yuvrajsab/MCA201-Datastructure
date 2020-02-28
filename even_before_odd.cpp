#include <iostream>

using namespace std;

int arrange(int list[], int index) {
    int temp;
    if (index > 0) {
        if (list[index] % 2 != 0) {
            temp = list[index];
            list[index] = list[index + 1];
        }
    }
    return arrange(list, index - 1);
}

int main() {

    int arr[] = {3, 2, 4, 7, 8, 4};

    arrange(arr, sizeof(arr)/sizeof(arr[0]));

    return 0;
}