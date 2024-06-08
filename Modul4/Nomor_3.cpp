#include <iostream>
#include <conio.h>

using namespace std;

// Struktur Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

bool isEmpty(Node *root){
    return root == NULL;
}

// Fungsi untuk membuat Node baru pada pohon
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Fungsi untuk memasukkan nilai pada pohon biner
Node* insert(Node* root, int data) {
    if (isEmpty(root)) {
        root = createNode(data);
    }
    // menambahkan nilai yang kecil di akar kiri
    // sehingga pada akar kiri ini terdapat nilai minimumnya
    else if (data <= root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Fungsi untuk melakukan traversal preOrder pada pohon biner
void preOrder(Node* root) {
    if (!isEmpty(root)) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Fungsi untuk melakukan traversal inOrder pada pohon biner
void inOrder(Node* root) {
    if (!isEmpty(root)) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

// Fungsi untuk melakukan traversal postOrder pada pohon biner
void postOrder(Node* root) {
    if (!isEmpty(root)) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

// Fungsi untuk mencari nilai node minimum (terkecil) pada pohon biner
int findMin(Node* root) {
	// mengecek nilai pada akar kiri saja
	// karena nilai nya paling kecil
    if (root->left == NULL) {
        return root->data;
    } else {
        return findMin(root->left);
    }
}

int main() {
    // Membuat pohon biner
    Node* root = NULL;

    int menu, nilai;
    do{
        system("cls");
        cout << "1. Tambah "<< endl;
        cout << "2. Nilai Minimum "<< endl;
        cout << "3. Tampil   "<< endl;
        cout << "4. Exit   "<< endl;
        cout << "----------"<< endl;
        cout << "Pilih : ";
        cin >> menu;
        switch (menu){
        case 1:
            cout << "Masukkan nilai : ";
            cin >> nilai;
            root = insert(root, nilai);
            break;
        case 2:
            if (isEmpty(root)){
                cout << "\nPohon Kosong" << endl;
            } else {
                // Mencetak nilai node minimum (terkecil) pada pohon biner
                cout << "Nilai node minimum pada pohon biner: " << findMin(root) << endl;
            }
            break;
        case 3:
            int pilih;
            system("cls");
            cout << "1. PreOrder "<< endl;
            cout << "2. InOrder "<< endl;
            cout << "3. PostOrder "<< endl;
            cout << "----------"<< endl;
            cout << "Pilih : ";
            cin >> pilih;
            switch (pilih){
            case 1:
                // Traversal inOrder pada pohon biner
                cout << "\nTraversal preOrder  : ";
                preOrder(root);
                cout << endl;
                break;
            case 2:
                // Traversal inOrder pada pohon biner
                cout << "\nTraversal ineOrder  : ";
                inOrder(root);
                cout << endl;
                break;
            case 3:
                // Traversal inOrder pada pohon biner
                cout << "\nTraversal posteOrder  : ";
                postOrder(root);
                cout << endl;
                break;
            default:
                cout << "Pilihan Anda tidak sesuai " << endl;
                break;
            }
            break;
        case 4:
            cout << "Anda keluar dari program  " << endl;
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
