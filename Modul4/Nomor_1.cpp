#include <iostream>
// include <conio.h> dihapus karena tidak digunakkan
using namespace std;

// struct *node diubah menjadi struct node karena struktur node
// tidak perlu menggunakkan pointer
struct node{     
    // char data dimasukkan ke dalam struct node
    char data;   
    node *kiri;
    node *kanan;
};

node *akar = NULL;

// Baru = data-> isi dihapus karena variabel data tidak didefinisikan
node *addNode(node *akar, char isi){
    if(akar == NULL){
        node *baru = new node;
        baru->data = isi;
        baru->kiri = NULL;
        baru->kanan = NULL;
        akar = baru;
    }
    // Ditambahkan return akar untuk mengembalikan nilai
    // akar yang sudah ditambahkan node
    return akar;
}

// (====================(node *) diubah menjadi void====================)
void preOrder(node *akar){
    if(akar != NULL){
        // cin << " " << akar->data diubah menjadi cout << akar->data << " "
        // karena output yang ditampilkan adalah nilai dari
        // akar->data, bukan input dari pengguna
        cout << akar->data << " ";
        preOrder(akar->kiri);
        preOrder(akar->kanan);
    }
}

void inOrder(node *akar){
    if(akar != NULL){
        inOrder(akar->kiri);
        cout << akar->data << " ";
        // Penulisan inOrder(akar = kanan) diubah menjadi inOrder(akar->kanan)
        // karena akar->kanan adalah ponter ke node kanan, bukan pernyataan
        inOrder(akar->kanan);
    }
}

void postOrder(node *akar){
    if (akar != NULL){
        postOrder(akar->kiri);
        postOrder(akar->kanan);
        cout << akar->data << " ";
    }
}
// ()===================================================================)

int main(){
    system("cls");
    cout << "\n\n\t Posisi Awal Tree : \n\n";
    cout << "\t      A\n\t     /\\\n\t    B  C\n\t   /\n\t  D\n\t /\\\n\tE  F\n\n";
    akar = addNode(akar, 'A');
    akar->kanan = addNode(akar->kanan, 'B');
    akar->kiri = addNode(akar->kiri, 'C');
    akar->kiri->kanan = addNode(akar->kiri->kanan, 'D');
    akar->kiri->kanan->kiri = addNode(akar->kiri->kanan->kiri, 'E');
    akar->kiri->kanan->kanan = addNode(akar->kiri->kanan->kanan, 'F');
    
    cout << "Tampilan PreOrder  : ";
    preOrder(akar);
    cout << "\nTampilan InOrder   : ";
    inOrder(akar);
    cout << "\nTampilan PostOrder : ";
    postOrder(akar);
    return 0;
}
