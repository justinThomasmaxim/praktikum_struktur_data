#include <iostream>  
#include <conio.h>  
using namespace std;

//------------------------(SINGLE LINKED LIST)------------------------

struct dataPegawai{

    // menambahkan komponen nama, umur, dan pekerjaan
    string nama;
    int umur;
    string pekerjaan;

    // membuat variabel pointer next (*next) 
    // dengan tipe data struct itu sendiri 
    dataPegawai *next;
}; 

// mendefinisikan variabel pointer global yaitu *head, *tail, *cur, *newNode, dan *del
dataPegawai *head, *tail, *cur, *newNode, *del;

// method isEmpty untuk mengecek apakah data kosong
bool isEmpty(){

    // mengembalikan nilai boolean (true atau false)
    // jika data itu kosong atau jika mempunyai data
    return head == NULL;
}

// Buat single linked list
void create(string nama, string pekerjaan, int umur){
    head = new dataPegawai();  // membuat object baru

    // Data pada node head (yang pertama) seperti nama, umur, dan pekerjaan 
    // akan diberi nilai dari parameter 
    head->nama      = nama;  
    head->umur      = umur;
    head->pekerjaan = pekerjaan;

    // Penunjuk node head menunjuk Null yang artinya tidak ada node lagi selanjutnya
    // dan tail sebagai data pada ujung linked list diset head
    head->next = NULL;
    tail = head;
}

// Tambah data diawal
void tambahDepan(string nama, string pekerjaan, int umur){
    newNode = new dataPegawai();  // membuat object baru

    // Data pada node newNode (node yang ditambahkan) seperti nama, umur, dan pekerjaan  
    // akan diberi nilai dari parameter 
    newNode->nama = nama;
    newNode->umur = umur;
    newNode->pekerjaan = pekerjaan;

    // Penunjuk newNode menunjuk head yang artinya terdapat node head (data yang akan ditambah)
    // dan head sebagai data pada awal linked list diset newNode
    newNode->next = head;
    head = newNode;
}

// Tambah data diakhir
void tambahAkhir(string nama, string pekerjaan, int umur){
    newNode = new dataPegawai(); 
    newNode->nama      = nama;
    newNode->umur      = umur;
    newNode->pekerjaan = pekerjaan;

    // Perbedaan pada method tambahDepan pada penunjuknya
    // Penunjuk newNode menunjuk NULL yang artinya tidak ada data lagi selanjutnya
    // dan penunjuk tail menunjuk newNode yang artinya terdapat node baru (data yang akan ditambah)
    // Kemudian tail diset newNode
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}

// Hapus depan
void hapusDepan(){
    // Variabel head di salin ke variabel del sebagai data yang ingin dihapus
    del = head;
    // Node head ditunjuk ke node selanjutnya
    // lalu hapus del
    head = head->next;
    delete del;
}

// Hapus belakang
void hapusBelakang(){
    // Variabel tail di salin ke variabel del sebagai data yang ingin dihapus
    del = tail;
    // Variabel head di salin ke variabel cur (node saat ini) 
    cur = head;  // data saat ini berada pada head atau node pertama

    // Tranversing
    // akan melakukan iterasi jika Penunjuk cur (node saat ini) yaitu next 
    // tidak sama dengan tail 
    // maka node saat ini akan diset ke node selanjutnya
    while (cur->next != tail){
        cur = cur->next;
    }

    // Variabel cur di salin ke variabel tail
    // Penunjuk tail menunjuk NULL yang artinya tidak ada data lagi
    // lalu hapus del
    tail = cur;
    tail->next = NULL;
    delete del;
}

// Mencari data dengan menerapkan algortima sequentialSearch
void sequentialSearch(string cariNama){
    // head disalin ke variabel cur
    cur = head;  // data saat ini berada pada head atau node pertama
    bool ditemukan = false;
    int i = 1;

    // akan melakukan iterasi dan berhenti jika node saat adalah NULL (tidak ada data lagi)
    while(cur != NULL){
        // jika nama pada node saat ini sama dengan nama yang dicari
        // maka tampilkan data pada node saat ini
        if(cur->nama == cariNama){
            cout << "\n----Data Pegawai Ke-" << i << "----" << endl;
            cout << "Nama      = " << cur->nama << endl;
            cout << "Umur      = " << cur->umur << endl;
            cout << "Pekerjaan = " << cur->pekerjaan << endl;
            ditemukan = true;
            break; 
        }

        // node saat ini diset ke node selanjutnya
        cur = cur->next;

        i++;
    }

    // jika tidak ditemukan maka tampilkan data tidak ditemukan
    if (ditemukan == false){
        cout << "\nData Pegawai dengan nama " << cariNama << " tidak ditemukan" << endl;
    }
}

// Mengurutkan data (berdasarkan nama) menggunakan metode Bubble Sort
void bubbleSort(){
    cur = head;  // data saat ini berada pada head atau node pertama

    // looping bertahapnya
    while (cur != NULL){

        // mendefinisikan variabel temp sama dengan head
        dataPegawai *temp = head;

        // disetiap tahapnya akan dilakukan pertukaran data
        while (temp->next != NULL){

            // disetiap tahapnya akan dilakukan pertukaran data mengecek nama pada datanya
            // jika data saat ini (temp->nama) lebih besar dari data selanjutnya (temp->next->nama)
            // maka terjadi proses pertukaran data
            if (temp->nama > temp->next->nama){
        
                // variabel tempNama di isi dengan temp->nama
                // agar ketika temp->nama di ubah nilainya menjadi temp->next->nama
                // ada tempNama yang nantinya akan menjadi nilai untuk temp->next->nama
                // begitupun pada pertukaran data pada pekerjaan dan umur

                // Template
                string tempNama       = temp->nama;
                string tempPekerjaan  = temp->pekerjaan;
                int tempUmur          = temp->umur;

                // Proses pertukaran data
                // data saat ini di isi nilai dari data selanjutnya
                // dan sebaliknya data selanjutnya akan di isi nilai dari data saat ini
                temp->nama            = temp->next->nama;
                temp->next->nama      = tempNama;

                temp->umur            = temp->next->umur;
                temp->next->umur      = tempUmur;

                temp->pekerjaan       = temp->next->pekerjaan;
                temp->next->pekerjaan = tempPekerjaan;
            }
            // maka node temp (hasil template dari node head) akan diset ke template selanjutnya
            temp = temp->next; 
        }
        // maka node saat ini akan diset ke node selanjutnya
        cur = cur->next; 
    }
    cout << "Data berhasil diurutkan berdasarkan nama" << endl;
}

// Tampilkan
void display(){

    // jika data kosong maka tampilkan pesan data kosong
    if (isEmpty()){
        cout << "Data kosong" << endl;

    // jika tidak kosong
    } else{    
        cur = head;  // data saat ini berada pada head atau node pertama
        int i = 1;

        // Tranversing
        // akan melakukan iterasi sampai variabel cur sama dengan NULL atau tidak ada data lagi
        while (cur != NULL){
            cout << "----Data Pegawai Ke-" << i << "----" << endl;
            cout << "Nama       = " << cur->nama << endl;
            cout << "Umur       = " << cur->umur << endl;
            cout << "Pekerjaan  = " << cur->pekerjaan << endl << endl;

            // Node saat ini (cur) akan diset ke node selanjutnya
            cur = cur->next;

            i++;
        }
    }
}

// Program Utama
int main(){
    int menu, umur;
    string nama, pekerjaan, cariNama;
    do{

        // terdapat menu yang disediakan untuk dipilih user
        system("cls");
        cout << "|------RESPONSI-----|" << endl;
        cout << "|--------MENU-------|" << endl;
        cout << "|-------------------|" << endl;
        cout << "|1. Tambah Data     |" << endl;
        cout << "|2. Hapus Data      |" << endl;
        cout << "|3. Cari Data       |" << endl;
        cout << "|4. Urutkan Data    |" << endl;
        cout << "|5. Tampilkan Data  |" << endl;
        cout << "|6. Exit            |" << endl;
        cout << "|-------------------|" << endl;

        // kemudian user diminta untuk meinputkan menu yang akan dipilih
        cout << "Pilih : ";
        cin >> menu;

        switch (menu){

        // Buat dan tambah data
        case 1:

            // jika data kosong maka create single linked list
            if (isEmpty()){

                // create single linked list
                cout << "\n--Buat Single linked list--" << endl;
                cout << "\n-------Data Pegawai--------" << endl;
                cout << "Masukkan Nama      : ";
                cin >> nama;
                cout << "Masukkan Umur      : ";
                cin >> umur;
                cout << "Masukkan Pekerjaan : ";
                cin >> pekerjaan;
                create(nama, pekerjaan, umur);

            // jika tidak    
            } else{

                // User mempunyai pilihan menu Tambah data depan atau belakang
                int pilih;
                system("cls");
                cout << "1. Tambah Depan    " << endl;
                cout << "2. Tambah Belakang " << endl;
                cout << "-------------------" << endl;
                cout << "Pilih : ";
                cin >> pilih;
                cout << "\n-------Data Pegawai--------" << endl;
                cout << "Masukkan Nama      : ";
                cin >> nama;
                cout << "Masukkan Umur      : ";
                cin >> umur;
                cout << "Masukkan Pekerjaan : ";
                cin >> pekerjaan;
                switch (pilih){

                // jika 1, maka data depan ditambahkan    
                case 1:
                    tambahDepan(nama, pekerjaan, umur);
                    break;

                // jika 2, maka data belakang ditambahkan  
                case 2:
                    tambahAkhir(nama, pekerjaan, umur);
                    break;
                default:
                    cout << "Pilihan tidak valid. Silahkan pilih menu yang tersedia " << endl;
                    break;
                }
            }
            break;

        // Hapus depan dan belakang    
        case 2:

            // jika data kosong, maka tampilkan pesan data kosong
            if (isEmpty()){
                cout << "\nData sudah kosong" << endl;

            // jika tidak     
            } else{

                // User mempunyai pilihan menu Hapus data depan atau belakang
                int pilih;
                system("cls");
                display();
                cout << "1. Hapus Depan    " << endl;
                cout << "2. Hapus Belakang " << endl;
                cout << "------------------" << endl;
                cout << "Pilih : ";
                cin >> pilih;
                switch (pilih){

                // jika 1, maka data depan dihapus    
                case 1:
                    hapusDepan();
                    cout << "\nData berhasil dihapus " << endl;
                    break;

                // jika 2, maka data belakang dihapus
                case 2:
                    hapusBelakang();
                    cout << "\nData berhasil dihapus " << endl;
                    break;
                default:
                    cout << "\nPilihan tidak valid. Silahkan pilih menu yang tersedia " << endl;
                    break;
                }
            }
            break;

        // Memasukan nama untuk cari data    
        case 3:
            cout << "\nMasukkan Nama yang dicari: ";
            cin >> cariNama;
            sequentialSearch(cariNama);
            break;

        // Mengurutkan data menggunakan metode buble sort
        case 4:
            bubbleSort();
            break;

        // Menampilkan data
        case 5:
            system("cls");
            display();
            break;
        case 6:
            cout << "Anda akan keluar dari program " << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silahkan pilih menu yang tersedia " << endl;
            break;
        }
        cout << "\nTekan Enter untuk lanjut : ";
        getch();
    } while (menu != 6);
    cout << "\n\nSelesai . . . . ." << endl;
    return 0;
}
