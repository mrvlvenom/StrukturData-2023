#include <iostream>
#include <string>

using namespace std;

// Fungsi untuk menyimpan data
struct mahasiswa{
    int NRP;
    string nama;
    int umur;
    string asal;
    double IPK;
};

// Fungsi untuk menampilkan data
void tampilkanData(mahasiswa data[], int jumlahData) {
    cout << "Data mahasiswa yang tersimpan: \n" << endl;
    for (int i = 0; i < jumlahData; i++) {
        cout << "NRP: " << data[i].NRP << endl;
        cout << "Nama: " << data[i].nama << endl;
        cout << "Umur: " << data[i].umur << endl;
        cout << "asal: " << data[i].asal << endl;
        cout << "IPK: " << data[i].IPK << endl;
        cout << "<-----------------> \n" << endl;
    }
}

// Fungsi untuk menambah data baru
void tambahData(mahasiswa data[], int &jumlahData) {
    if (jumlahData < 10) {
        mahasiswa newData;
        cout << "Masukkan NRP: ";
        cin >> newData.NRP;
        cout << "Masukkan Nama: ";
        cin.ignore();
        getline(cin, newData.nama);
        cout << "Masukkan Umur: ";
        cin >> newData.umur;
        cout << "Masukkan asal: ";
        cin >> newData.asal;
        cout << "Masukkan IPK: ";
        cin >> newData.IPK;
        cout<< "<----------------> \n";

        
        data[jumlahData++] = newData;
        cout << "Data berhasil ditambahkan! \n" << endl;
    } else {
        cout << "Jumlah data sudah mencapai batas maksimum (10 data)." << endl;
    }
}

// Fungsi untuk menghapus data
void hapusData(mahasiswa data[], int &jumlahData, int idHapus) {
    bool ditemukan = false;
    for (int i = 0; i < jumlahData; i++) {
        if (data[i].NRP == idHapus) {
            ditemukan = true;
            for (int j = i; j < jumlahData - 1; j++) {
                data[j] = data[j + 1];
            }
            jumlahData--;
            cout << "Data dengan NRP = " << idHapus << " berhasil dihapus. \n" << endl;
            cout<<"<-------------------->";
            break;
        }
    }
    if (!ditemukan) {
        cout << "Data dengan NRP = " << idHapus << " tidak ditemukan." << endl;
    }
}

// Fungsi untuk mengubah data
void ubahData(mahasiswa data[], int jumlahData, int idUbah) {
    for (int i = 0; i < jumlahData; i++) {
        if (data[i].NRP == idUbah) {
            cout << "Masukkan NRP baru: ";
            cin >> data[i].NRP;
            cout << "Masukkan Nama baru: ";
            cin.ignore();
            getline(cin, data[i].nama);
            cout << "Masukkan Umur baru: ";
            cin >> data[i].umur;
            cout << "Masukkan Asal baru: ";
            cin.ignore();
            getline(cin, data[i].asal);
            cout << "Masukkan IPK baru: ";
            cin >> data[i].IPK;
            cout << "<-----------------> \n";
            cout << "Data berhasil diubah! \n" << endl;
            return;
        }
    }
    cout << "Data dengan NRP " << idUbah << " tidak ditemukan." << endl;
}


int main() {
    mahasiswa data[10];
    int jumlahData = 0;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Menampilkan Data" << endl;
        cout << "2. Menambah Data" << endl;
        cout << "3. Menghapus Data" << endl;
        cout << "4. Mengubah Data" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu (1/2/3/4/5): ";
        int pilihan;
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanData(data, jumlahData);
                break;
            case 2:
                tambahData(data, jumlahData);
                break;
            case 3:
                int idHapus;
                cout << "Masukkan NRP data yang akan dihapus: ";
                cin >> idHapus;
                hapusData(data, jumlahData, idHapus);
                break;
            case 4:
                int idUbah;
                cout << "Masukkan NRP data yang akan diubah: ";
                cin >> idUbah;
                ubahData(data, jumlahData, idUbah);
                break;
            case 5:
                return 0;
            default:
                cout << "Pilihan tidak sesuai. Silakan pilih lagi." << endl;
                break;
        }
    }

    return 0;
}
