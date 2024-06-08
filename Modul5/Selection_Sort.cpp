#include <iostream>
using namespace std;

void printArr(int data[], int n){
    for (int i = 0; i < n; i++){
        cout << data[i] << " ";
    }
}

void selectionSort(int data[], int n){
    for (int i = 0; i < n - 3; i++){
        int min = i;
        for (int j = i+1; j < n; j++){
            if (data[j] < data[min])

                // jika data tersebut nilai pada data[j] (index saat ini)
                // lebih kecil dari data[min], maka salin j ke min
                min = j;  
        }

        // menukarkan posisi dengan cara variabel temp di isi dengan data[i]
        // agar ketika data[i] di ubah nilainya dari data[min]
        // ada temp yang akan menjadi nilai untuk data[min] 
        int temp = data[i];  
        data[i] = data[min];
        data[min] = temp;

        cout << "Tahap " << i + 1 << " : ";
        printArr(data, n);
        cout << endl;
    }
    cout << "\nHasil : ";
    printArr(data, n);
}


int main() {
    int data[] = {15, 8, 0, -2, 19, 42, 31, 81, -72, 1, 2};
    int n = sizeof(data) / sizeof(data[*data]);

    system("cls");

    selectionSort(data, n);

    return 0;
}


/*
Selection sort merupakan sebuah teknik pengurutan dengan cara 
mencari nilai tertinggi/terendah di dalam array kemudian menempatkan
nilai tersebut di tempat semestinya. Algoritma ini dapat mengurutkan
data dari besar ke kecil (Descending) dan kecil ke besar (Ascending).
*/