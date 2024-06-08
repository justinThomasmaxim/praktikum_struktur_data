void binarySearch(string kalimat, string kata) {

    int kiri = 0, kanan = kalimat.length() - 1;
    bool ditemukan = false;
    while (kiri <= kanan) {
        int tengah = kiri + (kanan - kiri) / 2;
        if (kalimat.substr(tengah, kata.length()) < kata) {
            kiri = tengah + 1;
        } else if (kalimat.substr(tengah, kata.length()) < kata){
            kanan = tengah - 1;
        } else {
            cout << "Kata " << kata << " ditemukan pada index ke-" << tengah << endl;
            ditemukan = true;
            break;
        }
        
    } // akhir while

    // Menampilkan hasil pencarian
    if (ditemukan == false){
        cout << "Kata " << kata << " tidak ditemukan" << endl;
    }
}