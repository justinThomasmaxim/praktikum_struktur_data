#include <iostream>
#include <conio.h>
using namespace std;

//------------------------(SINGLE LINKED LISRT)------------------------

struct dataPegawai
{
    string nama;
    int umur;
    string pekerjaan;

    dataPegawai *next;
};

dataPegawai *head, *tail, *cur, *newNode, *del;

bool isEmpty(){
    return head == NULL;
}

// Buat single linked list
void create(string nama, string pekerjaan, int umur){
    head = new dataPegawai();
    head->nama = nama;
    head->umur = umur;
    head->pekerjaan = pekerjaan;
    head->next = NULL;
    tail = head;
}

// Tambah data di awal
void addFirst(string nama, string pekerjaan, int umur){
    newNode = new dataPegawai();
    newNode->nama = nama;
    newNode->umur = umur;
    newNode->pekerjaan = pekerjaan;
    newNode->next = head;
    head = newNode;
}

// Tambah data diakhir
void addLast(string nama, string pekerjaan, int umur){
    newNode = new dataPegawai();
    newNode->nama = nama;
    newNode->umur = umur;
    newNode->pekerjaan = pekerjaan;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}

// Hapus depan
void removeFirst()
{
    // Variabel head di salin ke variabel del
    del = head;
    // Node pertama di di tunjuk ke node selanjutnya
    head = head->next;
    delete del;
}

// Hapus belakang
void removeLast()
{
    del = tail;
    cur = head;
    // Tranversing
    while (cur->next != tail)
    {
        cur = cur->next;
    }
    tail = cur;
    tail->next = NULL;
    delete del;
}

// Mengurutkan data menggunakan metode Bubble Sort
void bubbleSort(){
    cur = head;
    while (cur != NULL){
        dataPegawai *temp = head;
        while (temp->next != NULL){
            if (temp->nama > temp->next->nama){
                // swap(temp->name, temp->next->name);
                // swap(temp->age, temp->next->age);
                // swap(temp->job, temp->next->job);
                temp->nama = temp->next->nama;
                temp->umur = temp->next->umur;
                temp->pekerjaan = temp->next->pekerjaan;
            }
            temp = temp->next;
        }
        cur = cur->next;
    }
    cout << "Data berhasil diurutkan" << endl;
}

// Tampilkan
void display(){
    if (isEmpty()){
        cout << "Data kosong" << endl;
    } else{    
        cur = head;
        int i = 1;
        // Tranversing
        while (cur != NULL){
            cout << "----Data Pegawai Ke-" << i << "----" << endl;
            cout << "Nama       = " << cur->nama << endl;
            cout << "Umur       = " << cur->umur << endl;
            cout << "Pekerjaan  = " << cur->pekerjaan << endl << endl;

            cur = cur->next;

            i++;
        }
    }
}
int main(){
    int menu, umur;
    string nama, pekerjaan;
    do{
        system("cls");
        cout << "|----RESPONSI----|" << endl;
        cout << "|-STRUKTUR DATA--|" << endl;
        cout << "|----------------| " << endl;
        cout << "|1. Tambah       |" << endl;
        cout << "|2. Hapus        |" << endl;
        cout << "|3. Cari         |" << endl;
        cout << "|4. Urutkan      |" << endl;
        cout << "|5. Tampil       |" << endl;
        cout << "|6. Exit         |" << endl;
        cout << "|----------------|" << endl;
        cout << "Pilih : ";
        cin >> menu;
        switch (menu){
        case 1:
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
            } else{
                int pilih;
                system("cls");
                cout << "1. Tambhh Depan  " << endl;
                cout << "2. Tambah Belakang" << endl;
                cout << "----------" << endl;
                cout << "Pilih : ";
                cin >> pilih;
                cout << "\n-------Data Pegawai--------" << endl;
                cout << "Masukkan Nama      : ";
                cin >> nama;
                cout << "Masukkan Umur      : ";
                cin >> umur;
                cout << "Masukkan Pekerjaan : ";
                cin >> pekerjaan;
                switch (pilih)
                {
                case 1:
                    addFirst(nama, pekerjaan, umur);
                    break;
                case 2:
                    addLast(nama, pekerjaan, umur);
                    break;
                default:
                    cout << "Pilihan tidak valid. Silahkan pilih menu yang tersedia " << endl;
                    break;
                }
            }
            break;
        case 2:
            if (isEmpty()){
                cout << "Data sudah kosong" << endl;
            } else{
                int pilih;
                system("cls");
                display();
                cout << "1. Hapus Depan  " << endl;
                cout << "2. Hapus Belakang" << endl;
                cout << "----------" << endl;
                cout << "Pilih : ";
                cin >> pilih;
                switch (pilih){
                case 1:
                    removeFirst();
                    cout << "Data berhasil dihapus " << endl;
                    break;
                case 2:
                    removeLast();
                    cout << "Data berhasil dihapus " << endl;
                    break;
                default:
                    cout << "Pilihan tidak valid. Silahkan pilih menu yang tersedia " << endl;
                    break;
                }
            }
            break;
        // case 3:
        //     break;
        case 4:
            bubbleSort();
            break;
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
    cout << "\nSelesai" << endl;
    return 0;
}
