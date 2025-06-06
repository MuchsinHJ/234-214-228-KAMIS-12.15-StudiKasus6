#include <iostream>
using namespace std;

struct Data
{
  string nama;
  int nim;
  int alpro, matdis, pweb, aljabar;
  int nilai[100];
  float nilaiAkhir = 0;
  char huruf;
  string status;
};

class Mahasiswa{
  private:
  int jumlah, pilih;
  Data mhs[100];

  public:
  void alur(){
    cout << "Masukkan jumlah Mahasiswa: ";
    cin >> jumlah;
    cout << endl;
    tampilMenu();
  }
  void tampilMenu(){
    cout << "+====================================+" << endl;
    cout << "|                MENU                |" << endl;
    cout << "+====================================+" << endl;
    cout << "| 1. Input Nilai                     |" << endl;
    cout << "| 2. Tampilkan Data Nilai            |" << endl;
    cout << "| 3. Keluar                          |" << endl;
    cout << "+====================================+" << endl;
    cout << "| Masukkan Pilihan : ";
    cin >> pilih;
    cout << "+====================================+" << endl;
    cout << endl;
    
    switch (pilih)
    {
      case 1:
        inputNilai();
      break;
      case 2:
        dataMahasiswa();
      break;
      case 3:
      cout << endl;
      cout << "Terima Kasih" << endl;
      return;
      break;
      
      default:
      break;
    }
  }
  
  void inputNilai(){
    cout << "+====================================+" << endl;
    cout << "|       INPUT NILAI MAHASISWA        |" << endl;
    cout << "+====================================+" << endl;
    for (int i = 0; i < jumlah; i++)
    {
      cout << "| Masukkan Nama Mahasiswa Ke-" << i+1 << " : ";
      cin.ignore();
      getline(cin, mhs[i].nama);
      cout << "| Masukkan NIM "<< mhs[i].nama << " : ";
      cin >> mhs[i].nim;
      cout << "|" << endl;
      cout << "| Input Nilai Alpro "<< mhs[i].nama << " : ";
      cin >> mhs[i].nilai[0];
      cout << "| Input Nilai Matdis "<< mhs[i].nama << " : ";
      cin >> mhs[i].nilai[1];
      cout << "| Input Nilai Pweb "<< mhs[i].nama << " : ";
      cin >> mhs[i].nilai[2];
      cout << "| Input Nilai Aljabar "<< mhs[i].nama << " : ";
      cin >> mhs[i].nilai[3];
      hitungNilai(i);
      cout << "+====================================+" << endl;
      
    }
    cout << "|  NILAI MAHASISWA BERHASIL DIINPUT  |" << endl;
    cout << "+====================================+" << endl;
    cout << endl;
    tampilMenu();
  }

  void hitungNilai(int n){
    float total = 0;
    for (int i = 0; i < 4; i++)
    {
        total += mhs[n].nilai[i];
    }
    mhs[n].nilaiAkhir = total / 4;
    if(mhs[n].nilaiAkhir >= 85){
      mhs[n].huruf = 'A';
      mhs[n].status = "LULUS";
    } else if(mhs[n].nilaiAkhir >= 75 && mhs[n].nilaiAkhir < 85){
      mhs[n].huruf = 'B';
      mhs[n].status = "LULUS";
    } else if(mhs[n].nilaiAkhir >= 60 && mhs[n].nilaiAkhir < 75 ){
      mhs[n].huruf = 'C';
      mhs[n].status = "TIDAK LULUS";
    } else if(mhs[n].nilaiAkhir < 60) {
      mhs[n].huruf = 'D';
      mhs[n].status = "TIDAK LULUS";
    } else {
      mhs[n].huruf = '-';
      mhs[n].status = "TIDAK LULUS";
    }
  }

  float hitungTotal(){
    float total = 0;
    for (int i = 0; i < jumlah; i++)
    {
      total += mhs[i].nilaiAkhir;
    }
    return total;
  }
  
  void dataMahasiswa(){
    cout << "+====================================+" << endl;
    cout << "|        DATA NILAI MAHASISWA        |" << endl;
    cout << "+====================================+" << endl;
    for (int i = 0; i < jumlah; i++)
    {
      cout << "| Nama                  : " << mhs[i].nama << endl;
      cout << "| NIM                   : " << mhs[i].nim << endl;
      cout << "| Nilai Akhir Mahasiswa : " << mhs[i].nilaiAkhir << endl;
      cout << "| Huruf                 : " << mhs[i].huruf << endl;
      cout << "| Kelulusan             : " << mhs[i].status << endl;
      cout << "+====================================+" << endl;
    }
    cout << "| Jumlah Mahasiswa          : " << jumlah << endl;
    cout << "| Total Nilai Mahasiswa     : " << hitungTotal() << endl;
    cout << "| Rata-rata nilai Mahasiswa : " << (hitungTotal() / jumlah) << endl;
    cout << "+====================================+" << endl;
    cout << endl;
    tampilMenu();
  }
};

int main(){
  Mahasiswa mhs;
  mhs.alur();

  return 0;
}