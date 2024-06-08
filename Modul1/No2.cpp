// #include <iostream>
// #define max 50
// using namespace std;

// int* fibo(int n) {
//     int *arr = new int[n];
//     arr[0] = 1;
//     arr[1] = 1;
//     for (int i = 2; i < n; i++) {
//         arr[i] = arr[i - 1] + arr[i - 2];
//     }
//     return arr;
// }

// int main() {
//     int num, *ptr;
//     system("cls");
//     cout << "jumlah bilangan fibonacci : ";
//     cin >> num;
//     ptr = fibo(num);
//     for (int i = 0; i < num; i++) {
//         cout << ptr[i] << " ";
//     }
//     return 0;
// }



// #include <iostream>
// using namespace std;
// int main() {
//     int nilaiArray[3] = {1,2,3}; 
//     int *pointerArray; 
//     system("cls");
//     pointerArray = nilaiArray; 
//     for (int i = 0; i<3; i++){
//         cout<<"index [" << i << "] = ";
//         cout<<*(pointerArray+i)<<endl;
//     }
// }
