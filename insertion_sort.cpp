#include <iostream>

using namespace std;

int main() {
    int arr[] = { 10, 7, 8, 9, 4, 5, 6, 1, 2, 3 };
        int key, j;

        for (int i = 1; i < sizeof(arr)/sizeof(*arr); i++) {
            key = arr[i];
            j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }

            arr[j + 1] = key;
        }

        for (int i = 0; i < sizeof(arr)/sizeof(*arr); i++) {
	        cout<<arr[i]<<" ";
        }

    return 0;
}