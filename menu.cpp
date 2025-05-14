#include <iostream>
#include <conio.h>
using namespace std;

const int MAKS = 100;
int dataArray[MAKS];
int jumlahData = 0;


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

void mPertama(const char* pesan) {
    system("cls");
    cout << "Hallo, saya menu " << pesan;
    getch();
}

// Menu 1: Masukkan nilai ke array 
void masukkanNilai() {
    system("cls");
    int n;
    cout << "Berapa banyak angka yang ingin dimasukkan? ";
    cin >> n;

    if (jumlahData + n > MAKS) {
        cout << "Jumlah melebihi kapasitas array (maks " << MAKS << ").";
    } else {
        for (int i = 0; i < n; i++) {
            cout << "Masukkan angka ke-" << (i + 1) << ": ";
            cin >> dataArray[jumlahData++];
        }
        cout << "Nilai berhasil ditambahkan ke array.";
    }
    getch();
}

// Menu 2: Tampilkan array
void tampilkanArray() {
    system("cls");
    if (jumlahData == 0) {
        cout << "Array masih kosong.";
    } else {
        cout << "Isi array: ";
        for (int i = 0; i < jumlahData; i++)
            cout << dataArray[i] << " ";
    }
    getch();
}

// Menu 3: Sortir array secara ASCENDING tanpa fungsi tukar
void sortirArray() {
    system("cls");
    if (jumlahData == 0) {
        cout << "Array masih kosong. Tidak bisa disortir.";
    } else {
        for (int i = 0; i < jumlahData - 1; i++) {
            int pos = i;
            for (int j = i + 1; j < jumlahData; j++) {
                if (dataArray[j] < dataArray[pos]) // ascending
                    pos = j;
            }
            if (pos != i) {
                // Pertukaran langsung tanpa fungsi tukar
                int temp = dataArray[pos];
                dataArray[pos] = dataArray[i];
                dataArray[i] = temp;
            }
        }
        cout << "Array berhasil diurutkan secara ascending.";
    }
    getch();
}

// Menu 4: Menampilkan info
void menampilkanInfo() {
    system("cls");
    cout << "Jumlah elemen dalam array: " << jumlahData << "\n";
    if (jumlahData > 0) {
        int terkecil = dataArray[0];
        int terbesar = dataArray[0];
        for (int i = 1; i < jumlahData; i++) {
            if (dataArray[i] < terkecil)
                terkecil = dataArray[i];
            if (dataArray[i] > terbesar)
                terbesar = dataArray[i];
        }
        cout << "Nilai terkecil: " << terkecil << "\n";
        cout << "Nilai terbesar: " << terbesar << "\n";
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