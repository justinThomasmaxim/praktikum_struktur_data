#include <iostream>
using namespace std;

void printArr(int data[], int n){
    for (int i = 0; i < n; i++){
        cout << data[i] << " ";
    }
}

void insertionSort(int data[], int n){
    for (int i = 0; i < n; i++){
        int temp = data[i];
        int j = i-1;

        while (j >= 0 && data[j] > temp){
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = temp;

        cout << "Tahap " << i + 1 << " : ";
        printArr(data, n);
        cout << endl;
    }
    cout << "\nHasil : ";
    printArr(data, n);
}


int main() {
    int data[] = {15, 8, 0, -2, 19, 42, 31, 81, -72, 1, 2};
    int n = sizeof(data) / sizeof(data[0]);

    system("cls");

    insertionSort(data, n);

    return 0;
}


/*
Insertion sort adalah metode pengurutan dengan cara menyisipkan elemen data pada
posisi yang tepat. Pencarian posisi yang tepat dilakukan dengan melakukan pencarian berurutan di dalam 
barisan elemen, selama pencarian posisi yang tepat dilakukan pergeseran elemen.
*/