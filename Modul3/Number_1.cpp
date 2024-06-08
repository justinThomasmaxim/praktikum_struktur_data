#include <iostream>
#include <conio.h>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;

    Mahasiswa *next;
};

Mahasiswa *head, *tail, *cur, *newNode, *del;

bool isEmpty(){
    return head == NULL;
}

// Buat single linked list
void create(string nama, string nim){
    head = new Mahasiswa();
    head->nama = nama;
    head->nim = nim;
    head->next = NULL;
    tail = head;
}

// Tambah data di awal
void addFirst(string nama, string nim){
    newNode = new Mahasiswa();
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = head;
    head = newNode;
}

// Tambah data diakhir
void addLast(string nama, string nim){
    newNode = new Mahasiswa();
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}

void editFirst(string nama, string nim){
    head->nama = nama;
    head->nim = nim;
}

void editLast(string nama, string nim){
    tail->nama = nama;
    tail->nim = nim;
}

void removeFirst(){
    del = head;
    head = head->next;
    delete del;
}

void removeLast(){
    del = tail;
    cur = head;
    // Tranversing
    while(cur->next != tail){
        cur = cur->next;
    }
    tail = cur;
    tail->next = NULL;
    delete del;
}

// Tampilkan 
void display(){
    if(isEmpty()){
        cout << "Data kosong" << endl;
    } else {
        cur = head;
        int i = 1;
        // Tranversing
        while(cur != NULL){
            cout << "----Data Ke-" << i << "----" << endl;
            cout << "Nama = " << cur->nama << endl;
            cout << "NIM  = " << cur->nim << endl << endl;

            cur = cur->next;

            i++;
        }
    }
}
int main() {
    int menu;
    string nama, nim;
    system("cls");
    do{
        cout << "\n1. Tambah "<< endl;
        cout << "2. Ubah   "<< endl;
        cout << "3. Tampil "<< endl;
        cout << "4. Hapus  "<< endl;
        cout << "5. Exit   "<< endl;
        cout << "----------"<< endl;
        cout << "Pilih : ";
        cin >> menu;
        switch (menu){
        case 1:
            if(isEmpty()){
                // create single 
                cout << "\n--Buat Single linked list--" << endl;
                cout << "\nMasukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM  : ";
                cin >> nim;
                create(nama, nim);
            } else {
                int pilih;
                system("cls");
                cout << "1. Awal  "<< endl;
                cout << "2. Akhir "<< endl;
                cout << "----------"<< endl;
                cout << "Pilih : ";
                cin >> pilih;
                switch (pilih){
                case 1:
                    cout << "\nMasukkan Nama : ";
                    cin >> nama;
                    cout << "Masukkan NIM  : ";
                    cin >> nim;
                    addFirst(nama, nim);
                    break;
                case 2:
                    cout << "\nMasukkan Nama : ";
                    cin >> nama;
                    cout << "Masukkan NIM  : ";
                    cin >> nim;
                    addLast(nama, nim);
                    break;
                default:
                    cout << "Pilihan tidak ada " << endl;
                    break;
                }
            }
            break;
        case 2:
            if(isEmpty()){
                cout << "Data sudah kosong" << endl;
            } else {
                int pilih;
                system("cls");
                display();
                cout << "1. Awal  "<< endl;
                cout << "2. Akhir "<< endl;
                cout << "----------"<< endl;
                cout << "Pilih : ";
                cin >> pilih;
                switch (pilih){
                case 1:
                    cout << "\nMasukkan Nama : ";
                    cin >> nama;
                    cout << "Masukkan NIM  : ";
                    cin >> nim;
                    editFirst(nama, nim);
                    break;
                case 2:
                    cout << "\nMasukkan Nama : ";
                    cin >> nama;
                    cout << "Masukkan NIM  : ";
                    cin >> nim;
                    editLast(nama, nim);
                    break;
                default:
                    cout << "Pilihan tidak ada " << endl;
                    break;
                }
                break;
            }
        case 3:
            system("cls");
            display();
            break;
        case 4:
            if(isEmpty()){
                cout << "Data sudah kosong" << endl;
            } else {
                int pilih;
                system("cls");
                display();
                cout << "1. Awal  "<< endl;
                cout << "2. Akhir "<< endl;
                cout << "----------"<< endl;
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
                    cout << "Pilihan tidak ada " << endl;
                    break;
                }
            }
            break;
        case 5:
            cout << "Anda akan keluar dari program " << endl;
            break;
        default:
            cout << "Pilihan Anda tidak sesuai " << endl;
            break;
       }
       cout << "\nTekan Enter untuk lanjut : " ;
       getch();
    } while (menu != 5);
    return 0;
}
