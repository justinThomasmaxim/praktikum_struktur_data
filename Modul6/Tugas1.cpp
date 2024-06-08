#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void sequentialSearch(int arr[], int n, int cari) {
    bool ditemukan = false;
    cout << endl;
    for (int i = 0; i < n; i++) {
        if (arr[i] == cari) {
            cout << "ID " << cari << " ditemukan pada index ke-" << i << endl;
            ditemukan = true;
            break;
        }
    }

    if (ditemukan == false){
        cout << "ID " << cari << " tidak ditemukan" << endl;
    }
   
}

void binarySearch(int arr[], int n, int cari) {
    int kiri = 0, kanan = n - 1;
    bool ditemukan = false;
    while (kiri <= kanan) {
        int tengah = kiri + (kanan - kiri) / 2;
        if (arr[tengah] == cari){
            cout << "Data " << cari << " ditemukan pada index ke-" << tengah << endl;
            ditemukan = true;
            break;
        }else{
            if (arr[tengah] < cari) {
                kiri = tengah + 1;
            } else {
                kanan = tengah - 1;
            }
        }
    } // akhir while
    if (ditemukan == false){
        cout << "ID " << cari << " tidak ditemukan" << endl;
    }
  
}

void bubleSort(int data[], int n){
    // looping sebanyak n
    // di gunakkan untuk looping bertahapnya
    for (int i = 0; i < n - 1; i++){
        
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
            } 
        }
    }
}

int main() {
    const int n = 10;
    int arr[n];

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int hour = rand() % 24;
        int minute = rand() % 60;
        int second = rand() % 60;
        int id = hour * 10000 + minute * 100 + second;
        arr[i] = id;
    }

    int menu, index, cari;
    bool ulang = true;
    do{
        system("cls");
        cout << "ID Pembeli\t: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << ", ";
        }
        cout << endl;

        cout << "----------------------" << endl;
        cout << "       SEARCHING      " << endl;
        cout << "----------------------" << endl;
        cout << "1. Sequential Search  " << endl;
        cout << "2. Binary Search      " << endl;
        cout << "3. Exit               " << endl;
        cout << "----------------------" << endl;
        cout << "Pilih : ";
        cin >> menu;

        // memasukkan data yang dicari
        cout << "Cari ID   \t: ";
        cin >> cari;
        cout << endl;
        
        switch (menu){
        case 1:
            sequentialSearch(arr, n, cari);
            break;
        case 2:
            int data[n];
            for (int i = 0; i < n; i++){
                data[i] = arr[i];
            }

            bubleSort(data, n);

            cout << "\nData diurutkan" << endl;
            cout << "ID terurut :";
            for (int i = 0; i < n; i++){
                cout << data[i] << ", ";
            }
            cout << endl << endl;
            binarySearch(data, n, cari);
            break;
        case 3:
            cout << "\nAnda keluar dari program" << endl;
            ulang = false;
            break;
        default:
            cout << "\nPilihan tidak valid. Silakan pilih menu yang tersedia." << endl;
            break;
        }
        cout << "----------------------" << endl;
        cout << endl;
        cout << "Tekan Enter untuk lanjut : ";
        cin.ignore();
        cin.get();
    } while (ulang);
    cout << "\nSelesai" << endl;
    return 0;
}
