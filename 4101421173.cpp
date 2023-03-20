#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cout << "===============Program IPK Mahasiswa===============" << endl;
    cout << "===================================================" << endl;
    cout << "Tugas UTS Mochamad Ibnu Humam Arief" << endl;

    string nama, nim, prodi;
    int sks[8];
    cout << "Nama mahasiswa: "; getline(cin, nama);
    cout << "NIM           : "; cin >> nim;
    cout << "Prodi         : "; cin >> prodi;

    //Mata kuliah kewirausahaan
    float UH1, UTS1, UAS1, tugas1, nilai1, bobot1;
    string huruf1, kode1;
    cout << "----------------------------------------------------" << endl;
    cout << "Mata Kuliah Kewirausahaan" << endl;
    cout << "Input nilai UH    : "; cin >> UH1;
    cout << "Input nilai UTS   : "; cin >> UTS1;
    cout << "Input nilai Tugas : "; cin >> tugas1;
    cout << "Input nilai UAS   : "; cin >> UAS1;
    kode1= "20F00027";
    sks[0]=2;
    nilai1=(3*UH1+2*UTS1+3*UAS1+2*tugas1)/10;


    //Mata kuliah DasPros
    float UH2, UTS2, UAS2, tugas2, nilai2;
    string kode2;
    cout << "----------------------------------------------------" << endl;
    cout << "Mata Kuliah Dasar dan Proses Pembelajaran Matematika" << endl;
    cout << "Input nilai UH    : "; cin >> UH2;
    cout << "Input nilai UTS   : "; cin >> UTS2;
    cout << "Input nilai Tugas : "; cin >> tugas2;
    cout << "Input nilai UAS   : "; cin >> UAS2;
    kode2= "20P03620";
    sks[1]=3;
    nilai2=(3*UH2+2*UTS2+3*UAS2+2*tugas2)/10;

    //Mata kuliah MPM
    float UH3, UTS3, UAS3, tugas3, nilai3;
    string kode3;
    cout << "----------------------------------------------------" << endl;
    cout << "Mata Kuliah Media Pendidikan Matematika" << endl;
    cout << "Input nilai UH    : "; cin >> UH3;
    cout << "Input nilai UTS   : "; cin >> UTS3;
    cout << "Input nilai Tugas : "; cin >> tugas3;
    cout << "Input nilai UAS   : "; cin >> UAS3;
    kode3= "20P03626";
    sks[2]=3;
    nilai3=(3*UH3+2*UTS3+3*UAS3+2*tugas3)/10;

    //Mata kuliah Kalkulus Peubah Banyak
    float UH4, UTS4, UAS4, tugas4, nilai4;
    string kode4;
    cout << "----------------------------------------------------" << endl;
    cout << "Mata Kuliah Kalkulus Peubah Banyak" << endl;
    cout << "Input nilai UH    : "; cin >> UH4;
    cout << "Input nilai UTS   : "; cin >> UTS4;
    cout << "Input nilai Tugas : "; cin >> tugas4;
    cout << "Input nilai UAS   : "; cin >> UAS4;
    kode4= "20P03648";
    sks[3]=3;
    nilai4=(3*UH4+2*UTS4+3*UAS4+2*tugas4)/10;

    //Mata kuliah Algoritma Pemrograman
    float UH5, UTS5, UAS5, tugas5, nilai5;
    string kode5;
    cout << "----------------------------------------------------" << endl;
    cout << "Mata Kuliah Algoritma Pemrograman" << endl;
    cout << "Input nilai UH    : "; cin >> UH5;
    cout << "Input nilai UTS   : "; cin >> UTS5;
    cout << "Input nilai Tugas : "; cin >> tugas5;
    cout << "Input nilai UAS   : "; cin >> UAS5;
    kode5= "20P03649";
    sks[4]=3;
    nilai5=(3*UH5+2*UTS5+3*UAS5+2*tugas5)/10;

    //Mata kuliah Asesmen Pembelajaran Matematika
    float UH6, UTS6, UAS6, tugas6, nilai6;
    string kode6;
    cout << "----------------------------------------------------" << endl;
    cout << "Mata Kuliah Asesmen Pembelajaran Matematika" << endl;
    cout << "Input nilai UH    : "; cin >> UH6;
    cout << "Input nilai UTS   : "; cin >> UTS6;
    cout << "Input nilai Tugas : "; cin >> tugas6;
    cout << "Input nilai UAS   : "; cin >> UAS6;
    kode6= "20P03653";
    sks[5]=3;
    nilai6=(3*UH6+2*UTS6+3*UAS6+2*tugas6)/10;

    //Mata kuliah Statistika Lanjut
    float UH7, UTS7, UAS7, tugas7, nilai7;
    string kode7;
    cout << "----------------------------------------------------" << endl;
    cout << "Mata Kuliah Statistika Lanjut" << endl;
    cout << "Input nilai UH    : "; cin >> UH7;
    cout << "Input nilai UTS   : "; cin >> UTS7;
    cout << "Input nilai Tugas : "; cin >> tugas7;
    cout << "Input nilai UAS   : "; cin >> UAS7;
    kode7= "20P03654";
    sks[6]=3;
    nilai7=(3*UH7+2*UTS7+3*UAS7+2*tugas7)/10;

    //Mata kuliah Bahasa Indonesia
    float UH8, UTS8, UAS8, tugas8, nilai8;
    string kode8;
    cout << "----------------------------------------------------" << endl;
    cout << "Mata Kuliah Bahasa Indonesia" << endl;
    cout << "Input nilai UH    : "; cin >> UH8;
    cout << "Input nilai UTS   : "; cin >> UTS8;
    cout << "Input nilai Tugas : "; cin >> tugas8;
    cout << "Input nilai UAS   : "; cin >> UAS8;
    kode8= "20U00008";
    sks[7]=2;
    nilai8=(3*UH8+2*UTS8+3*UAS8+2*tugas8)/10;

    //Menghitung nilai huruf dan bobot
    float IPK=0, bobot[8]={nilai1,nilai2,nilai3,nilai4,nilai5,nilai6,nilai7,nilai8};
    string huruf[8];
    int i, j, matkul=8;

    for (i=0; i<matkul; i++){
        if (bobot[i]>=86){
            bobot[i]=4;
            huruf[i]="A";
        } else if (bobot[i]>=81){
                   bobot[i]=3.5;
                   huruf[i]="AB";
          } else if (bobot[i]>=71){
                     bobot[i]=3;
                     huruf[i]="B";
            } else if (bobot[i]>=66){
                       bobot[i]=2.5;
                       huruf[i]="BC";
              } else if (bobot[i]>=61){
                         bobot[i]=2;
                         huruf[i]="C";
                } else if (bobot[i]>=56){
                           bobot[i]=1;
                    } else {bobot[i]=0;
                            huruf[i]="E";}
    }

    for (i=0; i<matkul; i++){
        j=bobot[i]*sks[i];
        IPK=IPK+j;}
    system("cls");
    //Output
    cout << "Nama Mahasiswa         : " << nama << endl;
    cout << "NIM                    : " << nim << endl;
    cout << "Program Studi          : " << prodi << endl;
    cout << endl;

    cout << "Mata Kuliah Kewirausahaan" << endl;
    cout << "Kode        : " << kode1 << endl;
    cout << "SKS         : " << sks[0] << endl;
    cout << "Nilai angka : " << bobot[0] << endl;
    cout << "Nilai huruf : " << huruf[0] << endl;
    cout << endl;
    cout << "Mata Kuliah Dasar dan Proses Pembelajaran Matematika" << endl;
    cout << "Kode        : " << kode2 << endl;
    cout << "SKS         : " << sks[1] << endl;
    cout << "Nilai angka : " << bobot[1] << endl;
    cout << "Nilai huruf : " << huruf[1] << endl;
    cout << endl;
    cout << "Mata Kuliah Media Pendidikan Matematika" << endl;
    cout << "Kode        : " << kode3 << endl;
    cout << "SKS         : " << sks[2] << endl;
    cout << "Nilai angka : " << bobot[2] << endl;
    cout << "Nilai huruf : " << huruf[2] << endl;
    cout << endl;
    cout << "Mata Kuliah Kalkulus Peubah Banyak" << endl;
    cout << "Kode        : " << kode4 << endl;
    cout << "SKS         : " << sks[3] << endl;
    cout << "Nilai angka : " << bobot[3] << endl;
    cout << "Nilai huruf : " << huruf[3] << endl;
    cout << endl;
    cout << "Mata Kuliah Algoritma Pemrograman" << endl;
    cout << "Kode        : " << kode5 << endl;
    cout << "SKS         : " << sks[4] << endl;
    cout << "Nilai angka : " << bobot[4] << endl;
    cout << "Nilai huruf : " << huruf[4] << endl;
    cout << endl;
    cout << "Mata Kuliah Asesmen Pembelajaran Matematika" << endl;
    cout << "Kode        : " << kode6 << endl;
    cout << "SKS         : " << sks[5] << endl;
    cout << "Nilai angka : " << bobot[5] << endl;
    cout << "Nilai huruf : " << huruf[5] << endl;
    cout << endl;
    cout << "Mata Kuliah Statistika Lanjut" << endl;
    cout << "Kode        : " << kode7 << endl;
    cout << "SKS         : " << sks[6] << endl;
    cout << "Nilai angka : " << bobot[6] << endl;
    cout << "Nilai huruf : " << huruf[6] << endl;
    cout << endl;
    cout << "Mata Kuliah Bahasa Indonesia" << endl;
    cout << "Kode        : " << kode8 << endl;
    cout << "SKS         : " << sks[7] << endl;
    cout << "Nilai angka : " << bobot[7] << endl;
    cout << "Nilai huruf : " << huruf[7] << endl;
    cout << endl;
    cout << "IPK : " << IPK/22 << endl;
    cin.get();
    cin.get();
    return 0;
}

