#include <iostream>
#include <string>
#include <algorithm>
#include <conio.h>

using namespace std;

void sequentialSearch(string kalimat, string kata) {
    bool ditemukan = false;
    for (int i = 0; i < kalimat.length(); i++) {
        // Mencari kata pada kalimat dengan membandingkan substring sepanjang kata
        if (kalimat.substr(i, kata.length()) == kata) {
            cout << "Kata " << kata << " ditemukan pada indeks ke-" << i << endl;
            ditemukan = true;
            break;
        }
    }

    // Menampilkan hasil pencarian
    if (ditemukan == false){
        cout << "Kata " << kata << " tidak ditemukan" << endl;
    }
}

void computeLPS(string pattern, int lps[]) {
    int len = 0;
    int i = 1;
    lps[0] = 0;

    while (i < pattern.length()) {

        // jika nilai pada index sekarang (i) sama dengan nilai pada index sebelumnya (len)
        if (pattern[i] == pattern[len]) {

            // maka len akan bertambah 1 lalu len akan disalin ke array lps[i]
            // dan index akan bertambah 1
            len++;
            lps[i] = len;
            i++;
        } else {

            // jika tidak sama pattern[i] tidak sama dengan pattern[len]
            if (len != 0) {

                // jika len tidak sama dengan 0
                // maka salin nilai pada array lps[len - 1] ke len
                len = lps[len - 1];
            } else {

                // jika sama dengan 0
                // nilai pada array lps[i] akan bernilai 0
                // dan kemudian index bertambah 1
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmpSearch(string text, string pattern) {

    // Menghitung panjang text dan pattern kemudian salin ke n dan m
    int n = text.length();    
    int m = pattern.length(); 

    // Membuat array LPS
    int lps[m];
    computeLPS(pattern, lps);

    int i = 0;  // Index untuk text
    int j = 0;  // Index untuk pattern

    while (i < n) {

        // Jika karakter pada pattern[j] sama dengan karakter pada text[i] 
        // maka index i dan j di increment
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        // Jika indeks j sama dengan panjang M dari pattern
        // maka akan tampil pesan bahwa kata telah ditemukan pada index ke i-j
        // dan mengubah j = lps[j - 1] 
        if (j == m) {
            cout << "Kata \"" << pattern << "\" ditemukan pada indeks ke-" << i - j << endl;
            j = lps[j - 1];

        // Jika i kurang dari n dan karakter pada pattern[j] tidak sama dengan karakter pada text[i]    
        } else if (i < n && pattern[j] != text[i]) {

            // maka cek jika j tidak sama dengan 0
            // maka ubah j = lps[j - 1]
            if (j != 0) {
                j = lps[j - 1];

            // jika j sama dengan 0
            // maka ubah i = i + 1    
            } else {
                i = i + 1;
            }
        }
    }
}

int main() {
    string kalimat = "mimpimu memiliki akhir yang tidak terbatas, tarik napas yang dalam dan coba lagi";
    string kata1, kata2, temp;
    int menu, idx, index;
    do {
        system("cls");
        cout << kalimat << endl;
        cout << "-----------------------------------" << endl;
        cout << "        Menu Pencarian Kata        " << endl;
        cout << "-----------------------------------" << endl;
        cout << "1. Sequential Search               " << endl;
        cout << "2. Knuth-Morris-Pratt String Search" << endl;
        cout << "3. Keluar                          " << endl;
        cout << "-----------------------------------" << endl;
        cout << "Pilih menu: ";
        cin >> menu;
        cout << endl;
        if (menu != 4){
            cout << "Masukkan kata pertama yang ingin dicari\t: ";
            cin >> kata1;
            cout << "Masukkan kata kedua yang ingin dicari\t: ";
            cin >> kata2;
            cout << endl;
        }    

        switch (menu) {
            case 1:
                sequentialSearch(kalimat, kata1);
                sequentialSearch(kalimat, kata2);
                break;
            case 2:
                kmpSearch(kalimat, kata1);
                kmpSearch(kalimat, kata2);
                break;
            case 3:
                cout << "Anda keluar dari program" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih menu yang tersedia." << endl;
                break;
        }
        cout << "-----------------------------------" << endl;
        cout << endl;
        cout << "\nTekan Enter untuk lanjut : ";

        // Input sembarang untuk lanjut
        getch();
    } while (menu != 3);
    cout << "Selesai" << endl;
    return 0;
}
