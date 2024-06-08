#include <iostream>
#include <conio.h>
using namespace std;

struct listMusik {
    string judul;
    string penyanyi;
    int tahun_terbit;

    listMusik *next;
};

listMusik *head, *tail, *cur, *newNode, *del;

bool isEmpty(){
    return head == NULL;
}

// Buat single linked list
void create(string judul, string penyanyi, int tahun){
    head = new listMusik();
    head->judul = judul;
    head->penyanyi = penyanyi;
    head->tahun_terbit = tahun;
    head->next = NULL;
    tail = head;
}

// Tambah data di awal
void addFirst(string judul, string penyanyi, int tahun){
    newNode = new listMusik();
    newNode->judul = judul;
    newNode->penyanyi = penyanyi;
    newNode->tahun_terbit = tahun;
    newNode->next = head;
    head = newNode;
}

// Tambah data diakhir
void addLast(string judul, string penyanyi, int tahun){
    newNode = new listMusik();
    newNode->judul = judul;
    newNode->penyanyi = penyanyi;
    newNode->tahun_terbit = tahun;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}

void removeFirst(){
	// Variabel head di salin ke variabel del
    del = head;
    // Node pertama di di tunjuk ke node selanjutnya
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
            cout << "Judul        = " << cur->judul << endl;
            cout << "Penyanyi     = " << cur->penyanyi << endl;
            cout << "Tahun Terbit = " << cur->tahun_terbit << endl << endl;

            cur = cur->next;

            i++;
        }
    }
}
int main() {
    int menu, tahun_terbit;
    string judul, penyanyi;
    do{
        system("cls");
        cout << "1. Tambah "<< endl;
        cout << "2. Tampil "<< endl;
        cout << "3. Hapus  "<< endl;
        cout << "4. Exit   "<< endl;
        cout << "----------"<< endl;
        cout << "Pilih : ";
        cin >> menu;
        switch (menu){
        case 1:
            if(isEmpty()){
                // create single linked list
                cout << "\n--Buat Single linked list--" << endl;
                cout << "Masukkan Judul        : ";
                cin >> judul;
                cout << "Masukkan Penyanyi     : ";
                cin >> penyanyi;
                cout << "Masukkan Tahun Terbit : ";
                cin >> tahun_terbit;
                create(judul, penyanyi, tahun_terbit);
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
                    cout << "\nMasukkan Judul        : ";
                    cin >> judul;
                    cout << "Masukkan Penyanyi     : ";
                    cin >> penyanyi;
                    cout << "Masukkan Tahun Terbit : ";
                    cin >> tahun_terbit;
                    addFirst(judul, penyanyi, tahun_terbit);
                    break;
                case 2:
                    cout << "\nMasukkan Judul        : ";
                    cin >> judul;
                    cout << "Masukkan Penyanyi     : ";
                    cin >> penyanyi;
                    cout << "Masukkan Tahun Terbit : ";
                    cin >> tahun_terbit;
                    addLast(judul, penyanyi, tahun_terbit);
                    break;
                default:
                    cout << "Pilihan tidak ada " << endl;
                    break;
                }
            }
            break;
        case 2:
            system("cls");
            display();
            break;
        case 3:
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
        case 4:
            cout << "Anda akan keluar dari program " << endl;
            break;
        default:
            cout << "Pilihan Anda tidak sesuai " << endl;
            break;
       }
       cout << "\nTekan Enter untuk lanjut : " ;
       getch();
    } while (menu != 4);
    return 0;
}
