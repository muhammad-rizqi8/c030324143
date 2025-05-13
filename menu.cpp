#include <iostream>
#include <conio.h>
#include <vector>
#include <algorithm>
#include <sstream> // Untuk stringstream
using namespace std;

vector<int> dataArray; // Array dinamis global

void dMenu() {
  system("cls");
  cout << "Aplikasi Tampilan Menu\n";
  cout << "1. Masukkan nilai ke array\n";
  cout << "2. Tampilkan array\n";
  cout << "3. Sortir array\n";
  cout << "4. Menampilkan info\n";
  cout << "5. Exit\n";
  cout << "Masukan angka: ";
}

void mPertama(string pesan) {
  system("cls");
  cout << "Hallo, saya menu " << pesan;
  getch();
}

// Menu 1: Masukkan nilai ke array (pakai input format 23-45-12)
void masukkanNilai() {
  system("cls");
  string input;
  cout << "Masukkan nilai (angka), pisahkan dengan '-': ";
  cin.ignore(); // Membersihkan buffer sebelum getline
  getline(cin, input); // Baca seluruh baris

  stringstream ss(input);
  string token;

  while (getline(ss, token, '-')) {
    try {
      int nilai = stoi(token); // ubah string ke int
      dataArray.push_back(nilai);
    } catch (...) {
      cout << "Input tidak valid: " << token << "\n";
    }
  }

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

// Menu 4: Menampilkan info
void menampilkanInfo() {
  system("cls");
  cout << "Jumlah elemen dalam array: " << dataArray.size() << "\n";
  if (!dataArray.empty()) {
    cout << "Nilai terkecil: " << *min_element(dataArray.begin(), dataArray.end()) << "\n";
    cout << "Nilai terbesar: " << *max_element(dataArray.begin(), dataArray.end()) << "\n";
  }
  getch();
}


int main() {
  char pl;
  do {
    dMenu();
    pl = getch();
    switch (pl) {
      case '1':
        masukkanNilai();
        break;
      case '2':
        tampilkanArray();
        break;
      case '3':
        sortirArray();
        break;
      case '4':
        menampilkanInfo();
        break;
      case '5':
        break;
      default:
        system("cls");
        cout << "Pilihan Tidak Tersedia";
        getch();
        break;
    }
  } while (pl != '5');

  return 0;
}