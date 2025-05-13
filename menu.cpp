#include <iostream>
#include <conio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dataArray; // Array dinamis global


void info(){
  system("cls");
  cout <<"indonesia Hebat , Poliban juara";
  getch();
}
void dMenu(){
system("cls");
cout<<"Aplikasi Tampilan Menu"<<"\n";       
cout<<"1. Menu Pertama"<<"\n";            
cout<<"2. Menu Kedua"<<"\n";            
cout<<"3. Menu Ketiga"<<"\n";           
cout<<"4. Informasi"<<"\n";            
cout<<"5. Exit"<<"\n";           
cout<<"Masukan angka :";        

}

void mPertama(string pesan){
  system("cls");
  cout<<"Hallo, saya menu "<<pesan;
  getch();
}

// Menu 1: Masukkan nilai ke array
void masukkanNilai() {
  system("cls");
  int nilai;
  cout << "Masukkan nilai (angka): ";
  cin >> nilai;
  dataArray.push_back(nilai);
  cout << "Nilai berhasil ditambahkan ke array.";
  getch();
}

// Menu 2: Tampilkan array
void tampilkanArray() {
  system("cls");
  if (dataArray.empty()) {
    cout << "Array masih kosong.";
  } else {
    cout << "Isi array: ";
    for (int val : dataArray)
      cout << val << " ";
  }
  getch();
}

// Menu 3: Sortir array
void sortirArray() {
  system("cls");
  if (dataArray.empty()) {
    cout << "Array masih kosong. Tidak bisa disortir.";
  } else {
    sort(dataArray.begin(), dataArray.end());
    cout << "Array berhasil diurutkan.";
  }
  getch();
}


int main() {
char pl;
do
{
    dMenu();
    pl=getch();
  switch (pl)
  {
   case '1':
    /* code */
    mPertama("pertama");
    break;
   case '2':
    mPertama("ke- dua");
    /* code */ 
    break;  
   case '3':
    mPertama("ke- tiga");
    /* code */
    break;  
   case '4': 
    info();
    /* code */
    break;  
  case '5':
    /* code */
    break;
  
  default:
    system("cls");
    cout<<"Pilihan Tidak Tersedia";
    getch();
    break;
  }


} while (pl!='5');
  return 0;
}