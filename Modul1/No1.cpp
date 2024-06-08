#include <iostream> // Menggunakkkan cout, cin, dan system(cls)
#include <conio.h>  // Menggunakkan getch()
#define MAX_MAHASISWA 5
using namespace std;

struct Mahasiswa {
  string nama;
  string nim;
  string email;
};
int jumlahMahasiswa;
Mahasiswa mhs[MAX_MAHASISWA];

void tambah(int banyak_data) {
  jumlahMahasiswa = 0;
  system("cls");
  if ( banyak_data <= MAX_MAHASISWA ) {
    for(int i = 0; i <= banyak_data - 1; i++){
      cout << "----Data ke-"<<i+1<<"----"<< endl;
      cout << "Masukkan nama   : ";
      cin >> mhs[i].nama;
      cout << "Masukkan NIM    : ";
      cin >> mhs[i].nim;
      cout << "Masukkan E-mail : ";
      cin >> mhs[i].email;
      cout << "\n";
      jumlahMahasiswa++;
    }
    cout << "Mahasiswa berhasil ditambahkan." << endl;
  }else {
    cout << "Batas Input maksimal 5. Coba lagi" << endl<<endl;
  }
}
void tampil() {
	system("cls");
  cout << "Daftar mahasiswa:" << endl;
  cout << "NIM\t\t|Nama\t\t|E-mail"<<endl<<endl;
  for (int i = 0; i < jumlahMahasiswa; i++) {
    cout << mhs[i].nim << "\t\t|" << mhs[i].nama << "\t\t|"<< mhs[i].email << endl;
  }
}
int main() {
    int menu, n; // n sebagai banyak data yang ingin di input
    do{
      system("cls");
      cout << "----------------------" << endl;
      cout << "         MENU         " << endl;
      cout << "----------------------" << endl;
      cout << " 1. Tambah            " << endl;
      cout << " 2. Tampil            " << endl;
      cout << " 3. Exit              " << endl;
      cout << "----------------------" << endl;
      cout << "Pilih : ";
      cin >> menu;
      switch (menu){
      case 1:
          cout << "Masukkan banyak data : ";
          cin >> n;
          tambah(n);
          break;
      case 2:
          tampil();
          break;
      case 3:
        cout << "Anda keluar dari program\n\n----------------------" << endl;
        break;
      default:
          cout << "Pilihan tidak ada";
          break;
      }
      cout << "Tekan Enter untuk lanjut : ";
      getch();
    } while(menu != 3);
    return 0;
}
