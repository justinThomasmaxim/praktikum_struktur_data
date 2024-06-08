#include <iostream>
using namespace std;

void printArr(int data[], int n){
    for (int i = 0; i < n; i++){
        cout << data[i] << " ";
    }
}

void bubleSort(int data[], int n){
    // looping sebanyak n
    // di gunakkan untuk looping bertahapnya
    for (int i = 0; i < n - 3; i++){
        
        // disetiap tahapnya akan dilakukan pertukaran data
        // jika data saat ini (data[j]) lebih besar dari data selanjutnya (data[j+1])
        for (int j = 0; j < n - i - 1; j++){

            // Terjadi proses pertukaran data
            if (data[j] > data[j + 1]){

                // variabel temp di isi dengan data[j]
                // agar ketika data[j] di ubah nilainya dari data[j+1]
                // ada temp yang akan menjadi nilai untuk data[j+1]
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
                
                cout << "\nTahap " << i + 1 << " : ";
                printArr(data, n);
            } 
        }
    }
    cout << "\n\nHasil : ";
    printArr(data, n);
}

int main(){
    int data[] = {15, 8, 0, -2, 19, 42, 31, 81, -72, 1, 2};

    int n = sizeof(data) / sizeof(data[*data]);

    system("cls");

    bubleSort(data, n);

    return 0;
}

/*
Bubble sort adalah metode pengurutan algoritma dengan cara melakukan
penukaran data secara terus sampai bisa dipastikan dalam suatu iterasi
tertentu tidak ada lagi perubahan/penukaran.
*/
