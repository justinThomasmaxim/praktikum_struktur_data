#include <iostream>
#include <conio.h>
#define MAX 5
using namespace std;

struct mahasiswa{
    string judul[MAX];
    string penyanyi[MAX];
    int front;  // elemen depan
    int rear;   // elemen terakhir
} data_Musik;

void inisialisasi(){
    data_Musik.front = -1;
    data_Musik.rear = -1;
}

bool isFull(){
    return data_Musik.rear == MAX - 1;  //data penuh
}

bool isEmpty(){
    return data_Musik.rear == - 1;  // data kosong
}

// Menambahkan elemen
void input(string Judul, string Penyanyi, mahasiswa *Q){
	// Parameter ini akan bersifat by reference yang artinya apa yang dikirimkan 
    // sebagai parameter adalah alamat variabelnya, bukan nilainnya
    // Karena menggunakkan pointer, perubahan nilai yang terjadi didalam fungsi
    // akan mengubah juga variabel alamat aslinya
    if(isFull()){
		cout <<"Elemen Sudah Penuh "<< endl;
	} else{
        // Jika elemen masih kosong (isEmpty), maka front dan rear bernilai 0
        if(isEmpty()){
            Q->front = Q->rear = 0; // Artinya elemen sudah terisi
            Q->judul[Q->rear] = Judul;
            Q->penyanyi[Q->rear] = Penyanyi;
            // rear bertambah
            Q->rear++;
        // Jika pada elemen tidak kosong, maka hanya menambahkan rear saja
        }else{
            Q->judul[Q->rear] = Judul;
            Q->penyanyi[Q->rear] = Penyanyi;
            // rear bertambah
            Q->rear++;
        }
	}
}

// Menghapus dari elemen depan
void dequeue(mahasiswa *Q){
	if(isEmpty()){
		cout <<"Elemen Sudah kosong "<< endl;
	}else{
         cout << "------List Musik------" << endl;
        // Menghapus dari elemen depan
        cout <<" Judul    = "<< Q->judul[Q->front] << endl;
        cout <<" Penyanyi = "<< Q->penyanyi[Q->front] << endl;
		for(int i = Q->front; i < Q->rear-1; i++){
			Q->judul[i] = Q->judul[i+1];
			Q->penyanyi[i] = Q->penyanyi[i+1];
		}
        cout << "----------------------" << endl;
        cout << "\nBerhasil dihapus" << endl;
        // Rear berkurang 1
		Q->rear--;
	}
}

// Menghapus dari elemen belakang
void pop(mahasiswa *Q){
	if(isEmpty()){
		cout <<"Elemen sudah kosong "<< endl;
	}
	else{
        // Menghapus dari elemen terakhir
        cout << "------List Musik------" << endl;
        cout << "Judul    = " << Q->judul[Q->rear] << endl;
        cout << "Penyanyi = " << Q->penyanyi[Q->rear] << endl;
        cout << "----------------------" << endl;
        cout << "\nBerhasil dihapus" << endl;
        // Rear berkurang 1
        Q->rear--;
	}
}

void clear(mahasiswa *Q){
    // Untuk menghapus semua elemen,
    // definisikan front dan rear sama dengan -1
    // Penghapusan elemen-elemen tersebut sebenarnya tidak menghapus data pada arraynya,
    // namun hanya mengeset indeks pengaksesannya ke nilai -1 
    // sehingga elemen-elemen tersebut tidak lagi terbaca
    Q->front = Q->rear = -1;
}

// Menampilkan data secara Queue
void printQueue(mahasiswa *Q){
    if(isEmpty()){
		cout <<"Belum Ada Elemen "<< endl;
	}else{
        // Mencetak dari elemen depan sampai elemen terakhir
		for(int i = Q->front; i <= Q->rear-1; i++){ 
			cout <<"----Antrian ke-"<< i+1 <<"----"<< endl; 
            cout <<"Judul    : "<< Q->judul[i] << endl;
            cout <<"Penyanyi : "<< Q->penyanyi[i] << endl;
		}
	}
}

// Menampilkan data secara Stack
void printStack(mahasiswa *Q){
   if (isEmpty()){
		cout <<"Belum ada elemen"<< endl;
	}
	else{
        // Mencetak dari elemen terakhir sampai elemen depan
		for (int i = Q->rear-1; i >= Q->front; i--){
		    cout <<"----Tumpukan ke-"<< i+1 <<"----"<< endl; 
            cout <<"Judul    : "<< Q->judul[i] << endl;
            cout <<"Penyanyi : "<< Q->penyanyi[i] << endl;
        }
	} 
}

int main(){
    int menu;
    string Judul, Penyanyi;
    inisialisasi();
    do{	
        system("cls");
		cout <<"|=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=|"<< endl;
		cout <<"|                           LIST MUSIK                                |"<< endl;
		cout <<"|+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+|"<< endl;
		cout <<"| 1) INPUT                                                            |"<< endl;
		cout <<"| 2) DEQUEUE                                                          |"<< endl;
		cout <<"| 3) POP                                                              |"<< endl;
		cout <<"| 4) CLEAR                                                            |"<< endl;
		cout <<"| 5) PRINT                                                            |"<< endl;
		cout <<"| 6) KELUAR                                                           |"<< endl;
		cout <<"|/////////////////////////////////////////////////////////////////////|"<< endl;
		cout <<"| PILIH : ";
		cin >> menu;
        switch (menu){
            case 1:
                system("cls");
                cout <<" Masukan Judul    : ";       // Memasukkan elemen bertipe data integer
                cin >> Judul;
                cout <<" Masukan Penyanyi : ";  
                cin >> Penyanyi;
                input(Judul, Penyanyi, &data_Musik);
                break;
            case 2:
                system("cls");
                dequeue(&data_Musik);
                break;
            case 3:
                system("cls");
                pop(&data_Musik);
                break;
            case 4:
                system("cls");
                clear(&data_Musik);
                cout << "Semua elemen telah terhapus" << endl;
                break;
            case 5:
                int pilih;
                system("cls");
                cout <<"|+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+|"<< endl;
                cout <<"|                           TAMPILKAN                                 |"<< endl;
                cout <<"|+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+|"<< endl;
                cout <<"| 1) QUEUE                                                            |"<< endl;
                cout <<"| 2) STACK                                                            |"<< endl;
                cout <<"|/////////////////////////////////////////////////////////////////////|"<< endl; 
                cout << "PILIH : ";
                cin >> pilih;
                switch (pilih){
                case 1:
                    system("cls");
                    printQueue(&data_Musik);
                    break;
                case 2:
                    system("cls");
                    printStack(&data_Musik);
                    break;
                default:
                    cout <<"Maaf, pilihan anda tidak ada"<< endl;
                    break;
                }
                break;
            case 6:
                cout << "Anda keluar dari program" << endl;
                break;
            default:
                cout <<"Maaf, pilihan anda tidak ada"<< endl;
                break;
        }
        cout << "\n\nTekan Enter untuk lanjut : ";
        getch();
	}while(menu != 6);
    return 0;
}

