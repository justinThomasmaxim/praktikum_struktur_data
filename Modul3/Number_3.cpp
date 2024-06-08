#include <iostream>
#include <conio.h>
using namespace std;

struct Mahasiswa {
    string username;
    string email;
    string password;

    Mahasiswa *prev;  // Elemen sebelum elemen(node) tersebut
    Mahasiswa *next;  // Elemen setelah elemen(node) tersebut
};

Mahasiswa *head, *tail, *cur, *newNode, *del, *afterNode;

// Pengkondisian isEmpty untuk mengecek apakah data kosong atau tidak
bool isEmpty(){
    return head == NULL;
}

// Function untuk mengetahui jumlah data 
int count(){
    cur = head;
    int jumlahData = 0;
    while(cur != NULL){
        jumlahData++;
        
        cur = cur->next;
    }
    return jumlahData;
}

// Buat single linked list
void create(string username, string email, string password){
    head = new Mahasiswa();
    head->username = username;
    head->email = email;
    head->password = password;
    // next dan prev adalah NULL (tidak elemen)
    head->next = NULL;
    head->prev = NULL;
    tail = head;
}

// Tambah data di awal
void addFirst(string username, string email, string password){
    newNode = new Mahasiswa();
    newNode->username = username;
    newNode->email = email;
    newNode->password = password;
    // Memasukkan data pada node yang prev nya menunjuk NULL dan next menunjuk head (node pertama)
    newNode->prev = NULL;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// Tambah data diakhir
void addLast(string username, string email, string password){
    newNode = new Mahasiswa();
    newNode->username = username;
    newNode->email = email;
    newNode->password = password;
    // Memasukkan data pada node yang prev nya menunjuk tail (node terakhir) dan next menunjuk NULL
    newNode->prev = tail;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}

// Hapus dari tengah
void removeMiddle(int posisi){
    if(isEmpty()){
        cout << "Data sudah kosong" << endl;
    } else {
        if (posisi == 1 || posisi == count()){
            cout << "Bukan posisi tengah" << endl;
        } else if (posisi < 1 || posisi > count()){
            cout << "Posisi diluar jangkauan" << endl;
        } else {
            int nomor = 1;
            cur = head;
            while(nomor < posisi - 1){
                cur = cur->next;
                nomor++;
            }
            // Menghapus data pada node tengah 
            del = cur->next;
            afterNode = del->next;
            cur->next = afterNode;
            afterNode->prev = cur;
            delete del;

            cout << "Data berhasil dihapus " << endl;
        }   
    }
}

// Tampilkan 
void display(){
    if(isEmpty()){
        cout << "Data kosong" << endl;
    } else {
        cur = head;
        int i = 1;
        // Tranversing
        // Mencetak data dari node pertama (head) sampai node terakhir (tail yang next nya menunjuk NULL) 
        while(cur != NULL){
            cout << "----Data Ke-" << i << "----" << endl;
            cout << "Username = " << cur->username << endl;
            cout << "E-mail   = " << cur->email << endl;
            cout << "Password = " << cur->password << endl << endl;

            cur = cur->next;

            i++;
        }
    }
}

// Program Utama
int main() {
    int menu;
    string username, email, password;
    do{
        system("cls");
        cout << "1. Tambah "<< endl;
        cout << "2. Tampil "<< endl;
        cout << "3. Hapus (dari tengah)  "<< endl;
        cout << "4. Exit   "<< endl;
        cout << "----------"<< endl;
        cout << "Pilih : ";
        cin >> menu;
        switch (menu){
        case 1:
            if(isEmpty()){
                // create single linked list
                cout << "\n--Buat Double linked list--" << endl;
                cout << "Masukkan Username : ";
                cin >> username;
                cout << "Masukkan E-mail   : ";
                cin >> email;
                cout << "Masukkan Password : ";
                cin >> password;
                create(username, email, password);
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
                    cout << "\nMasukkan Username : ";
                    cin >> username;
                    cout << "Masukkan E-mail   : ";
                    cin >> email;
                    cout << "Masukkan Password : ";
                    cin >> password;
                    addFirst(username, email, password);
                    break;
                case 2:
                    cout << "\nMasukkan Username : ";
                    cin >> username;
                    cout << "Masukkan E-mail   : ";
                    cin >> email;
                    cout << "Masukkan Password : ";
                    cin >> password;
                    addLast(username, email, password);
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
            system("cls");
            int posisi;
            display();
            cout << "\nMasukkan Posisi data : ";
            cin >> posisi;
            removeMiddle(posisi);
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
