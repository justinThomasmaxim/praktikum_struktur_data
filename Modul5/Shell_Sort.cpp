#include <iostream>
using namespace std;

void printArr(int data[], int n){
    for (int i = 0; i < n ; i++){
        cout << data[i] << " ";
    }
}

// 
void shellSort(int data[], int n) {
    int step = n , urut = 1;

    // akan terus diulang sampai nilai jarak perbandingan = 1
    while (step > 1) {   

        // jarak yang diperoleh sebelumnya dibagi 2
        // sampai jarak = 1
        step = step / 2;  

        for (int i = 0; i < step; i++) {
            for (int j = i + step; j < n; j += step) {
                int temp = data[j];
                int k = j;
                while (k >= step && data[k - step] > temp) {
                    data[k] = data[k - step];
                    k -= step;
                }
                data[k] = temp;

                cout << "Tahap " << urut << " : ";
                urut++;
                printArr(data, n);
                cout << endl;
            }
        }
    }

    cout << "\nHasil : ";
    printArr(data, n);
}


int main() {
    int data[] = {15, 8, 0, -2, 19, 42, 31, 81, -72, 1, 2};
    int n = sizeof(data) / sizeof(data[*data]);  // jumlah elemen pada array

    system("cls");

    shellSort(data, n);


    return 0;
}


/*
Shell sort biasa disebut dengan algoritma pertambahan menurun. Metode ini mirip dengan 
metode buble sort, hanya saja perbandingan dilakukan bukan antara dua bilangan yang berurutan, 
akan tetapi antara dua bilangan dengan jarak tertentu. Lakukan pertukaran tempat jika setiap kali
perbandingan terhadap keseluruhan elemen selesai dilakukan, maka perbandingan yang baru dilakukan 
kembali dimana (jarak diperoleh dari nilai jarak sebelumnya)/2 . Perbandingan keseluruhan dilakukan 
sampai nilai jarak sama dengan 1.
*/