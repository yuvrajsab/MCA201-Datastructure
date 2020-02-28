#include <iostream>

using namespace std;

void arrange(int list[], int size, int index = 0, int odd = 0) {
    if (index == size) {
        return;
    }

    if (list[index] % 2 == 0) {
        int temp = list[odd];
        list[odd] = list[index];
        list[index] = temp;
        odd++;
    }

    arrange(list, size, index + 1, odd);
}

int main() {

    int list[] = {3, 2, 4, 7, 8, 1, 12};

    int size = sizeof(list)/sizeof(list[0]);

    arrange(list, size);

    for (int i = 0; i < size; i++) {
        cout<<list[i]<<' ';
    }

    return 0;
}