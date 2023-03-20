#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std;
void loginpegawai();
void registr();
void pegawai();
void pegawai_status();
void pegawai_permintaan();
void pegawai_permintaan1();
void pegawai_permintaan2();
void pegawai_pengadaan();
void pegawai_pengadaan1();
void pegawai_pengadaan2();
void siswa();
void siswa_pinjam();
void siswa_minta();
void siswa_minta1();
void siswa_minta2();
void siswa_minta3();

#define name 60
#define name2 60
#define name3 60
char brg[name], mnt[name2], mnt2[name3];
int global1=0, global2=0, global3=0, global4=0, banyak, extra=0, minta, n1=0, n2=0;
string barang[100]={"buku absensi", "lcd", "layar proyektor", "cd", "spidol", "penghapus", "penggaris", "busur", "jangka", "papan tulis", "speaker", "jam", "foto presiden", "kursi", "meja"};
int kuantitas[100]={90, 20, 20, 50, 200, 50, 20, 20, 10, 10, 10, 20, 20, 80, 40};
int pinjam[100]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
string status1[100], pengajuan[100], pengadaan1[100], pengadaan2[100], status2[100], kosong[100];
int jumlahpengajuan[100], jumlahpengadaan[100], tambah[100];
int list1=15;
int list2=15;

main()
{
    int role;

    cout << "\n================================================================================================================" << endl;
    cout << "                                           SELAMAT DATANG DI SILOSE                                               " << endl;
    cout << "================================================================================================================" << endl;

    cout << "\nSilahkan pilih sebagai apa anda akan masuk:" << endl;
    cout << "1. Pegawai\n2. Siswa\n3. Exit" << endl;
    cout << "Pilih salah satu" << endl;
    cin >> role;

    if (role==1){
        system("cls");
        int choice;

        cout << "Anda masuk sebagai pegawai" << endl;
        cout << "1. Login" << endl;
        cout << "2. Sign in"<< endl;
        cout << "3. Exit" << endl;
        cout << "\nMasukkan pilihan anda :";
        cin >> choice;
        cout << endl;

        switch(choice){
        case 1:
            loginpegawai();
            break;
        case 2:
            registr();
            break;
        case 3:
            cout<<"\n*****Thanks for using this program*****\n" << endl;
            break;
        default:
            system("cls");
            cout<<"You've made a mistake , give it a try again\n"<<endl;
            main();
        }
    } else if (role==2){
        int counter;
        system("cls");
        string usersiswa, passsiswa, us, ps;
        cout << "Anda masuk sebagai siswa" << endl;
        cout << "Username : "; cin >> usersiswa;
        cout << "Password : "; cin >> passsiswa;

        ifstream datasiswa("database.txt");
        while(datasiswa>>us>>ps){
                if(us==usersiswa && ps==passsiswa){
                    counter=1;
                    system("cls");
                }
        }
        datasiswa.close();
        if(counter==1){
            cout<<"\nHello "<<usersiswa<<"\nLOGIN SUCESS\nThanks for logging in\n";
            cin.get();
            cin.get();
            siswa();
        } else {
            system("cls");
            cout <<"\nLOGIN ERROR\n" << endl;
            cout <<"Please check your username and password\n" << endl;;
            main();
        }
    } else if (role==3){
        system("cls");
        cout<<"\n*****Thanks for using this program*****\n" << endl;
    } else {
        system("cls");
        cout << "\nERROR\n" << endl;
        main();
    }
}

void pegawai ()
{
    int menupegawai;

    cout << "\n================================================================================================================" << endl;
    cout << "                                                  MENU PEGAWAI                                                     " << endl;
    cout << "================================================================================================================" << endl;
    cout << "\nPilih menu di bawah ini" << endl;
    cout << "1. Status barang" << endl;
    cout << "2. Daftar permintaan barang baru" << endl;
    cout << "3. Daftar barang dalam proses" << endl;
    cout << "4. Kembali" << endl;
    cout << "Menu yang dipilih : "; cin >> menupegawai;

    switch (menupegawai){
    case 1:
        system("cls");
        pegawai_status();
        break;
    case 2:
        system("cls");
        pegawai_permintaan();
        break;
    case 3:
        system("cls");
        pegawai_pengadaan();
        break;
    case 4:
        system("cls");
        main();
        break;
    default:
        system("cls");
        cout << "ERROR" << endl;
        cout << "Your request cannot be processed\n" << endl;
        pegawai();
    }
}

void pegawai_status()
{
    string kembali;
    cout << "\n================================================================================================================" << endl;
    cout << "                                                 STATUS BARANG                                                  " << endl;
    cout << "================================================================================================================" << endl;
    cout << endl;
    for (int i=0;i<list1;i++){
        cout << "Nama barang    :\t" << barang[i] << endl;
        cout << "Tersedia       :\t" << kuantitas[i] << endl;
        cout << "Diambil/pinjam :\t" << pinjam[i]<< "\n" << endl;
    }
    cout << "Kembali ke menu?(Y/T): "; cin >> kembali;
    if (kembali=="Y"){
        system("cls");
        pegawai();
    } else if (kembali=="T"){
        system("cls");
        loginpegawai();
    } else {
        system("cls");
        cout << "\n*****Your request cannot be processed*****\n" << endl;
        main();
    }
}

void pegawai_permintaan()
{
    int choice;
    cout << "\n================================================================================================================" << endl;
    cout << "                                         DAFTAR PERMINTAAN BARANG SISWA                                         " << endl;
    cout << "================================================================================================================" << endl;
    cout << "\nPilih menu berikut" << endl;
    cout << "1. Barang baru" << endl;
    cout << "2. Penambahan ketersediaan" << endl;
    cout << "3. Kembali" << endl;
    cout << "Menu yang anda pilih: "; cin >> choice;

    switch (choice){
    case 1:
        system("cls");
        pegawai_permintaan1();
        break;
    case 2:
        system("cls");
        pegawai_permintaan2();
        break;
    case 3:
        system("cls");
        pegawai();
        break;
    default:
        system("cls");
        cout<<"\n*****You've made a mistake , give it a try again*****\n"<<endl;
        main();
    }
}

void pegawai_permintaan1()
{
    string kembali, keputusan, tambah, ganti, pengajuanlokal[100], statuslokal[100];
    int a=0, i, j=0, indeks, jumlahpengajuanlokal[100];

    if (global1>0){
        cout << "Daftar barang baru yang diminta" << endl;
        for (i=0; i<global1; i++){
            cout << i+1 << ". Barang diminta\t: " << pengajuan[i] << endl;
            cout << "   Kuantitas\t\t: " << jumlahpengajuan[i] << endl;
        }
        cout << "Persetujuan pengadaan barang" << endl;
        ulang:
        cout << "\nBarang dipilih: "; cin >> i;
        if (i>global1){
            system("cls");
            cout << "\n*****Option is not available, please select according to the condition*****\n" << endl;
            pegawai_permintaan1();
        } else {
        cout << "Nama barang\t: " << pengajuan[i-1] << endl;
        cout << "Kuantitas\t: " << jumlahpengajuan[i-1] << endl;
        cout << "Status persetujuan" << endl;
        cout << "Y = permintaan disetujui\nT = permintaan ditolak" << endl;
        cout << "Masukkan pilihan anda: "; cin >> keputusan;
        if (keputusan=="Y"){
            statuslokal[j]="Disetujui";
            pengajuanlokal[j]=pengajuan[i-1];
            jumlahpengajuanlokal[j]=jumlahpengajuan[i-1];
            j++;
        } else if (keputusan=="T"){
            statuslokal[j]="Ditolak";
            pengajuanlokal[j]=pengajuan[i-1];
            jumlahpengajuanlokal[j]=jumlahpengajuan[i-1];
            j++;
        } else {
            system("cls");
            cout << "\n*****Option is not available, please select according to the condition*****\n" << endl;
            pegawai_permintaan1();
        }
        cout << "\nApakah ada barang lain yang perlu disetujui (Y/T): "; cin >> tambah;
        if (tambah=="Y"){
            goto ulang;
        } else if (tambah=="T"){
            system("cls");
            konfirmasi:
            cout << "Konfirmasi" << endl;
            for (i=0; i<j; i++){
                cout << i+1 << ". Barang diminta\t: " << pengajuanlokal[i] << endl;
                cout << "   Kuantitas\t\t: " << jumlahpengajuanlokal[i] << endl;
                cout << "   Status\t\t: " << statuslokal[i] << endl;
            }
            cout << "\nApakah ada data yang perlu diubah? (Y/T) "; cin >> ganti;
            if (ganti=="Y"){
                cout << "\nPilih indeks data yang ingin anda ubah: "; cin >> indeks;
                cout << "\nBarang diminta\t: " << pengajuanlokal[indeks-1] << endl;
                cout << "Kuantitas\t: " << jumlahpengajuanlokal[indeks-1] << endl;

                persetujuan:
                cout << "\nStatus persetujuan" << endl;
                cout << "Y = permintaan disetujui\nT = permintaan ditolak" << endl;
                cout << "Masukkan pilihan anda: "; cin >> keputusan;
                if (keputusan=="Y"){
                    statuslokal[indeks-1]="Disetujui";
                } else if (keputusan=="T"){
                    statuslokal[indeks-1]="Ditolak";
                } else {
                    cout << "\n*****Option is not available, please select according to the condition*****\n" << endl;
                    goto persetujuan;
                }
                system("cls");
                cout << "Data berhasil diubah" << endl;
                goto konfirmasi;
            } else if (ganti=="T"){
                system("cls");
                cout << "Data telah disimpan" << endl;
                for (i=0; i<j; i++){
                    for (int k=0; k<global1; k++){
                        if (pengajuanlokal[i]==pengajuan[k]){
                            status1[k]=statuslokal[i];
                            if (status1[k]=="Disetujui"){
                                pengadaan1[a]=pengajuan[k];
                                jumlahpengadaan[a]=jumlahpengajuan[k];
                                a++;
                                global3++;
                            }
                        }
                    }
                }
                pegawai_permintaan();
            } else {
                system("cls");
                cout << "\n*****Option is not available, please select according to the condition*****\n" << endl;
                goto konfirmasi;
            }
        } else {
            system("cls");
            cout << "\n*****Option is not available, please select according to the condition*****\n" << endl;
            pegawai_permintaan1();
        }
        }
    } else {
        cout << "\n*****Tidak ada daftar permintaan*****\n" << endl;
        pegawai_permintaan();
    }
}

void pegawai_permintaan2()
{
    string kembali, keputusan, statuslokal[100], baranglokal[100];
    int a=0, i=0, j=0, indeks, counter[100], kuantitaslokal[100], tambahlokal[100];
    cout << "Daftar penambahan kuantitas barang tersedia" << endl;
    if (global2>0){
        for (i=0; i<list1; i++){
            if (tambah[i]>0){
            cout << j+1 << ". Barang diminta\t: " << barang[i] << endl;
            cout << "   Kuantitas awal\t: " << kuantitas[i] << endl;
            cout << "   Kuantitas tambahan\t: " << tambah[i] << endl;
            counter[j]=i;
            j++;
            }
        }
        cout << "Persetujuan penambahan kuantitas barang" << endl;
        i=0;
        ulang:
        cout << "\nBarang dipilih: "; cin >> j;
        cout << "Nama barang\t\t: " << barang[counter[j-1]] << endl;
        cout << "Kuantitas tambahan\t: " << tambah[counter[j-1]] << endl;
        cout << "Status persetujuan" << endl;
        cout << "Y = permintaan disetujui\nT = permintaan ditolak" << endl;
        cout << "Masukkan pilihan anda: "; cin >> keputusan;
        if (keputusan=="Y"){
            statuslokal[i]="Disetujui";
            baranglokal[i]=barang[counter[j-1]];
            kuantitaslokal[i]=kuantitas[counter[j-1]];
            tambahlokal[i]=tambah[counter[j-1]];
            i++;
        } else if (keputusan=="T"){
            statuslokal[i]="Ditolak";
            baranglokal[i]=barang[counter[j-1]];
            kuantitaslokal[i]=kuantitas[counter[j-1]];
            tambahlokal[i]=tambah[counter[j-1]];
            i++;
        } else {
            system("cls");
            cout << "\n*****Option is not available, please select according to the condition*****\n" << endl;
            pegawai_permintaan2();
        }
        cout << "\nApakah ada barang lain yang perlu disetujui (Y/T): "; cin >> keputusan;
        if (keputusan=="Y"){
            goto ulang;
        } else if (keputusan=="T"){
            system("cls");
            konfirmasi:
            cout << "Konfirmasi" << endl;
            for (j=0; j<i; j++){
                cout << j+1 << ". Barang dipilih\t: " << baranglokal[j] << endl;
                cout << "   Kuantitas tambahan\t: " << tambahlokal[j] << endl;
                cout << "   Status\t\t: " << statuslokal[j] << endl;
            }
            cout << "\nApakah ada data yang perlu diubah? (Y/T) "; cin >> keputusan;
            if (keputusan=="Y"){
                cout << "\nPilih indeks data yang ingin anda ubah: "; cin >> indeks;
                cout << "\nBarang dipilih\t\t: " << baranglokal[indeks-1] << endl;
                cout << "Kuantitas awal\t\t: " << kuantitaslokal[indeks-1] << endl;
                cout << "Kuantitas tambahan\t: " << tambahlokal[indeks-1] << endl;

                persetujuan:
                cout << "\nStatus persetujuan" << endl;
                cout << "Y = permintaan disetujui\nT = permintaan ditolak" << endl;
                cout << "Masukkan pilihan anda: "; cin >> keputusan;
                if (keputusan=="Y"){
                    statuslokal[indeks-1]="Disetujui";
                } else if (keputusan=="T"){
                    statuslokal[indeks-1]="Ditolak";
                } else {
                    cout << "\n*****Option is not available, please select according to the condition*****\n" << endl;
                    goto persetujuan;
                }
                system("cls");
                cout << "Data berhasil diubah" << endl;
                goto konfirmasi;
            } else if (keputusan=="T"){
                system("cls");
                cout << "Data telah disimpan" << endl;
                for (j=0; j<i; j++){
                    for (int k=0; k<list1; k++){
                        if (baranglokal[j]==barang[k]){
                            status2[k]=statuslokal[j];
                            if (status2[k]=="Disetujui"){
                                pengadaan2[a]=barang[k];
                                a++;
                                global4++;
                            }
                        }
                    }
                }
            }
            pegawai_permintaan();
        } else {
            cout << "\n*****Option is not available, please select according to the condition*****\n" << endl;
            goto ulang;
        }
    } else {
        system("cls");
        cout << "\n*****Tidak ada daftar permintaan*****\n" << endl;
        pegawai_permintaan();
    }
}

void pegawai_pengadaan()
{
    int choice;

    cout << "\n================================================================================================================" << endl;
    cout << "                               PENGELOLAAN BARANG BARU DAN KETERSEDIAAN BARANG                                  " << endl;
    cout << "================================================================================================================" << endl;
    cout << "\nPERHATIAN" << endl;
    cout << "1. Pastikan barang dalam daftar sesuai dengan ketersediaan sekolah" << endl;
    cout << "2. Semua barang dalam daftar yang sedang diproses hanya di 'selesai' kan saat barang yang diminta telah tersedia" << endl;
    cout << "3. Lakukan pengecekan kembali saat melakukan konfirmasi penyelesaian barang" << endl;
    cout << "4. Barang yang telah 'selesai' akan dihapus dari daftar pengajuan" << endl;
    cout << "5. Kesalahan setelah melakukan konfirmasi tidak dapat diubah" << endl;
    cout << "6. Apabila terjadi kesalahan dapat melakukan konfirmasi secara langsung pada pihak yang bersangkutan" << endl;
    cout << "================================================================================================================" << endl;

    cout << "Pilih jenis daftar dalam pemrosesan" << endl;
    cout << "1. Barang baru" << endl;
    cout << "2. Penambahan kuantitas barang" << endl;
    cout << "3. Kembali" << endl;
    cout << "Menu yang dipilih: "; cin >> choice;

    switch (choice){
    case 1:
        system("cls");
        pegawai_pengadaan1();
        break;
    case 2:
        system("cls");
        pegawai_pengadaan2();
        break;
    case 3:
        system("cls");
        pegawai();
        break;
    default:
        system("cls");
        cout << "\nOption is not available, please select according to the condition\n" << endl;
        main();
    }
}

void pegawai_pengadaan1()
{
    int i, j=0, indeks, jumlahpengadaanlokal[100];
    string lanjut, keputusan, tambah, ganti, pengadaanlokal[100], statuslokal[100];
    cout << "\n================================================================================================================" << endl;
    cout << "                                       DAFTAR BARANG BARU DALAM PROSES                                          " << endl;
    cout << "================================================================================================================\n" << endl;
    switch (global3){
    case 0:
        system("cls");
        cout << "\n*****Tidak ada barang baru yang sedang diproses*****" << endl;
        pegawai_pengadaan();
        break;
    default:
        for (i=0; i<global3; i++){
            cout << i+1 << ". Nama barang\t: " << pengadaan1[i] << endl;
            cout << "   Kuantitas\t: " << jumlahpengadaan[i] << endl;
        }
        cout << "Tekan 'Y' untuk melanjutkan program: "; cin >> lanjut;
        if (lanjut=="Y"){
            cout << "Konfirmasi barang telah selesai diproses" << endl;
            ulang:
            cout << "\nBarang dipilih: "; cin >> i;
            if (i>global3){
                system("cls");
                cout << "\n*****Option is not available, please select according to the condition*****\n" << endl;
                pegawai_pengadaan1();
            } else {
                cout << "Nama barang\t: " << pengadaan1[i-1] << endl;
                cout << "Kuantitas\t: " << jumlahpengadaan[i-1] << endl;
                cout << "Status barang" << endl;
                cout << "Ketik 'selesai' untuk menyelesaikan status barang" << endl;
                cout << "Status: "; cin >> keputusan;
                if (keputusan=="selesai"){
                    statuslokal[j]="selesai";
                    pengadaanlokal[j]=pengadaan1[i-1];
                    jumlahpengadaanlokal[j]=jumlahpengadaan[i-1];
                    j++;
                } else {
                    cout<<"\n*****You've made a mistake , give it a try again*****\n"<<endl;
                    goto ulang;
                }
                cout << "\nApakah ada barang lain yang telah selesai diproses (Y/T): "; cin >> tambah;
                if (tambah=="Y"){
                    goto ulang;
                } else if (tambah=="T"){
                    system("cls");
                    konfirmasi:
                    cout << "Konfirmasi" << endl;
                    for (i=0; i<j; i++){
                        cout << i+1 << ". Nama barang\t: " << pengadaanlokal[i] << endl;
                        cout << "   Kuantitas\t: " << jumlahpengadaanlokal[i] << endl;
                        cout << "   Status\t: " << statuslokal[i] << endl;
                    }
                    cout << "\nApakah ada data yang perlu diubah? (Y/T) "; cin >> ganti;
                    if (ganti=="Y"){
                        cout << "\nPilih indeks data yang ingin anda ubah: "; cin >> indeks;
                        cout << "\nNama barang\t: " << pengadaanlokal[indeks-1] << endl;
                        cout << "Kuantitas\t: " << jumlahpengadaanlokal[indeks-1] << endl;

                        persetujuan:
                        cout << "\nStatus: selesai" << endl;
                        cout << "'Y' untuk lanjut menyelesaikan" << endl;
                        cout << "'T' untuk membatalkan" << endl;
                        cout << "Masukkan pilihan anda: "; cin >> keputusan;
                        if (keputusan=="Y"){
                            system("cls");
                            cout << "Data berhasil diubah" << endl;
                            goto konfirmasi;
                        } else if (keputusan=="T"){
                            for (indeks=indeks; indeks<j; indeks++){
                                statuslokal[indeks-1]=statuslokal[indeks];
                                pengadaanlokal[indeks-1]=pengadaanlokal[indeks];
                                jumlahpengadaanlokal[indeks-1]=jumlahpengadaanlokal[indeks];
                            }
                            j--;
                        } else {
                            cout << "\n*****Option is not available, please select according to the condition*****\n" << endl;
                            goto persetujuan;
                        }
                        system("cls");
                        cout << "Data berhasil diubah" << endl;
                        goto konfirmasi;
                    } else if (ganti=="T"){
                        system("cls");
                        cout << "Data telah disimpan" << endl;
                        int x=list1;
                        for (i=0; i<j; i++){
                            for (int k=0; k<global3; k++){
                                if (pengadaanlokal[i]==pengadaan1[k]){
                                    for (k=k; k<global3; k++){
                                        pengadaan1[k]=pengadaan1[k+1];
                                        jumlahpengadaan[k]=jumlahpengadaan[k+1];
                                    }
                                    list1++;
                                    list2++;
                                    global3--;
                                }
                            }
                            for (int m=0; m<global1; m++){
                                if (pengadaanlokal[i]==pengajuan[m]){
                                    for (m=m; m<global1; m++){
                                        pengajuan[m]=pengajuan[m+1];
                                        jumlahpengajuan[m]=jumlahpengajuan[m+1];
                                        status1[m]=status1[m+1];
                                    }
                                    global1--;
                                }
                            }
                        }
                        for (i=0; i<j; i++){
                            if (x<list1){
                                barang[x]=pengadaanlokal[i];
                                kuantitas[x]=jumlahpengadaanlokal[i];
                            }
                            x++;
                        }
                        pegawai_pengadaan();
                    } else {
                        system("cls");
                        cout << "\n*****Option is not available, please select according to the condition*****\n" << endl;
                        goto konfirmasi;
                    }
                } else {
                    system("cls");
                    cout << "\n*****Option is not available, please select according to the condition*****\n" << endl;
                    pegawai_pengadaan1();
                }
            }
        } else {
            system("cls");
            pegawai_pengadaan();
        }
    }
}

void pegawai_pengadaan2()
{
    int i=0, j=0, indeks, tambahlokal[100];
    string lanjut, keputusan, ganti, pengadaanlokal[100], statuslokal[100];
    switch (global4){
    case 0:
        system("cls");
        cout << "\n*****Tidak ada barang baru yang sedang diproses*****" << endl;
        pegawai_pengadaan();
        break;
    default:
        cout << "Daftar penambahan barang dalam proses" << endl;

       // for (i=0; i<list1; i++){
         //   if (status2[i]=="Disetujui"){
           //    counter[a]=i;
             //   for (int k=0; k<global4; k++){
               //     if (barang[i]==pengadaan2[k]){
                 //       tambahlokal[k]=tambah[i];
               //     }
            //    }
          //      a++;
       //     }
    //    }
        for (i=0; i<global4; i++){
            for (j=0; j<list1; j++){
                if (pengadaan2[i]==barang[j]){
                    tambahlokal[i]=tambah[j];
                }
            }
        }
        j=0;
        for (i=0; i<global4; i++){
            cout << i+1 << ". Nama barang\t: " << pengadaan2[i] << endl;
            cout << "   Kuantitas\t: " << tambahlokal[i] << endl;
        }
        cout << "Tekan 'Y' untuk melanjutkan program: "; cin >> lanjut;
        if (lanjut=="Y"){
            cout << "Konfirmasi barang telah selesai diproses" << endl;
            ulang:
            cout << "\nBarang dipilih: "; cin >> i;
            if (i>global4){
                system("cls");
                cout << "\n*****Option is not available, please select according to the condition*****\n" << endl;
                pegawai_pengadaan2();
            } else {
                cout << "Nama barang\t: " << pengadaan2[i-1] << endl;
                cout << "Kuantitas\t: " << tambahlokal[i-1] << endl;
                cout << "Status barang" << endl;
                cout << "Ketik 'selesai' untuk menyelesaikan status barang" << endl;
                cout << "Status: "; cin >> keputusan;
                if (keputusan=="selesai"){
                    statuslokal[j]="selesai";
                    pengadaanlokal[j]=pengadaan2[i-1];
                    j++;
                } else {
                    cout<<"\n*****You've made a mistake , give it a try again*****\n"<<endl;
                    goto ulang;
                }
                cout << "\nApakah ada barang lain yang telah selesai diproses (Y/T): "; cin >> keputusan;
                if (keputusan=="Y"){
                    goto ulang;
                } else if (keputusan=="T"){
                    system("cls");
                    konfirmasi:
                    cout << "Konfirmasi" << endl;
                    for (i=0; i<j; i++){
                        cout << i+1 << ". Nama barang\t: " << pengadaanlokal[i] << endl;
                        cout << "   Kuantitas\t: " << tambahlokal[i] << endl;
                        cout << "   Status\t: " << statuslokal[i] << endl;
                    }
                    cout << "\nApakah ada data yang perlu diubah? (Y/T) "; cin >> ganti;
                    if (ganti=="Y"){
                        cout << "\nPilih indeks data yang ingin anda ubah: "; cin >> indeks;
                        cout << "\nNama barang\t: " << pengadaanlokal[indeks-1] << endl;
                        cout << "Kuantitas\t: " << tambahlokal[indeks-1] << endl;

                        persetujuan:
                        cout << "\nStatus: selesai" << endl;
                        cout << "'Y' untuk lanjut menyelesaikan" << endl;
                        cout << "'T' untuk membatalkan" << endl;
                        cout << "Masukkan pilihan anda: "; cin >> keputusan;
                        if (keputusan=="Y"){
                            system("cls");
                            cout << "Data berhasil diubah" << endl;
                            goto konfirmasi;
                        } else if (keputusan=="T"){
                            for (indeks=indeks; indeks<j; indeks++){
                                statuslokal[indeks-1]=statuslokal[indeks];
                                pengadaanlokal[indeks-1]=pengadaanlokal[indeks];
                                tambahlokal[indeks-1]=tambahlokal[indeks];
                            }
                            j--;
                        } else {
                            cout << "\n*****Option is not available, please select according to the condition*****\n" << endl;
                            goto persetujuan;
                        }
                        system("cls");
                        cout << "Data berhasil diubah" << endl;
                        goto konfirmasi;
                    } else if (ganti=="T"){
                        system("cls");
                        cout << "Data telah disimpan" << endl;
                        for (i=0; i<j; i++){
                            for (int k=0; k<global4; k++){
                                if (pengadaanlokal[i]==pengadaan2[k]){
                                    for (k=k; k<global4; k++){
                                        pengadaan2[k]=pengadaan2[k+1];
                                    }
                                    global4--;
                                }
                            }
                            for (int m=0; m<list1; m++){
                                if (pengadaanlokal[i]==barang[m]){
                                    kuantitas[m]=kuantitas[m]+tambah[m];
                                    tambah[m]=0;
                                    global2--;
                                }
                            }
                        }
                        pegawai_pengadaan();
                    } else {
                        system("cls");
                        cout << "\n*****Option is not available, please select according to the condition*****\n" << endl;
                        goto konfirmasi;
                    }
                } else {
                    system("cls");
                    cout << "\n*****Option is not available, please select according to the condition*****\n" << endl;
                    pegawai_pengadaan2();
                }
            }
        } else {
            system("cls");
            pegawai_pengadaan();
        }
    }
}

void siswa()
{
    int menusiswa;
    cout << "\n================================================================================================================" << endl;
    cout << "                                                   MENU SISWA                                                     " << endl;
    cout << "================================================================================================================" << endl;
    cout << "\nPilih menu di bawah ini" << endl;
    cout << "1. Ambil/pinjam" << endl;
    cout << "2. Pengajuan barang" << endl;
    cout << "3. Kembali" << endl;
    cout << "Menu yang dipilih : "; cin >> menusiswa;

    switch (menusiswa){
    case 1:
        system("cls");
        siswa_pinjam();
        break;
    case 2:
        system("cls");
        siswa_minta();
        break;
    case 3:
        system("cls");
        main();
        break;
    default:
        system("cls");
        cout << "ERROR" << endl;
        cout << "Your request cannot be processed\n" << endl;
        siswa();
    }
}

void siswa_pinjam()
{
    int simpan=0;
    string kembali;

    cout << "Barang tersedia" << endl;
    for (int i=0;i<list1;i++){
        cout << "Nama barang    :\t" << barang[i] << endl;
        cout << "Tersedia       :\t" << kuantitas[i] << endl;
        cout << endl;
    }
    cout << "Banyak jenis barang yang ingin anda ambil/pinjam: "; cin >> banyak;
    if (banyak>list1){
        system("cls");

        cout << "\nBanyak barang yang anda minta melebihi persediaan\n" << endl;
        siswa_pinjam();
    } else {
        system("cls");

        string nama[list1];
        int i,j, tampung1[list2], tampung2[list2];
        cout << "Barang yang akan dipinjam:" << endl;
        for (int i=0; i<banyak; i++){
            cin.getline(brg, name);
            cout << i+1 << ". Nama barang\t:";
            cin.getline(brg, name);
            nama[i]=brg;
            cout << "   Kuantitas\t:";
            cin >> tampung1[i];
        }
        system("cls");
        cout << "Konfirmasi\n" << endl;
        for (i=0; i<banyak; i++){
            for (j=0; j<list1; j++){
                if (nama[i]==barang[j]){
                    simpan = 1;
                    cout << "Barang yang diambil/pinjam\t: " << nama[i]<< endl;
                    if (tampung1[i]>kuantitas[j]){
                        cout << "Kuantitas yang anda minta melebihi persediaan\n" << endl;
                    } else {
                        cout << "Kuantitas: " << tampung1[i] << " buah\n" << endl;
                        pinjam[j]=pinjam[j]+tampung1[i];
                        tampung2[j]=tampung1[i];
                        tampung1[i]=0;
                    }
                } else {simpan=simpan;}
            }
            if (simpan==0){
                cout << "Barang yang anda minta\t\t: " << nama[i] << "\nsedang tidak tersedia\n" << endl;
            }
            simpan=0;
        }
        cout << "Apakah ada data yang ingin anda ubah? (Y/T): "; cin >> kembali;
        if (kembali=="Y"){
            system("cls");
            siswa_pinjam();
        } else if (kembali=="T"){
            for (i=0; i<banyak; i++){
                for (j=0; j<list1; j++){
                    if (nama[i]==barang[j]){
                        kuantitas[j]=kuantitas[j]-tampung2[j];
                    }
                }
            }
            system("cls");
            cout << ">>>>> Data telah disimpan <<<<<" << endl;
            cout << "Silahkan ke bagian tata usaha untuk melakukan konfirmasi pengambilan\n" << endl;
            siswa();
        } else {
            system("cls");
            cout << "\n*****Your request cannot be processed*****\n" << endl;
        }
    }
}

void siswa_minta()
{
    cout << "\n================================================================================================================" << endl;
    cout << "Anda memasuki menu pengadaan barang\n" << endl;
    cout << "Ketentuan penggunaan:" << endl;
    cout << "1. Menu ini digunakan untuk mengajukan permintaan pengadaan barang baru atau barang habis" << endl;
    cout << "2. Setiap kelas dapat mengajukan barang sesuai kebutuhan" << endl;
    cout << "3. Gunakan huruf kecil untuk memasukkan input barang" << endl;
    cout << "4. Keputusan persetujuan pengadaan barang akan diserahkan sepenuhnya pada pihak sekolah" << endl;
    cout << "5. Permintaan yang tidak disetujui akan ditampilkan pada status" << endl;
    cout << "6. Apabila terjadi kesalahan input bisa melapor pada admin sekolah atau wali kelas yang bersangkutan" << endl;
    cout << "================================================================================================================" << endl;
    cout << "\nMohon gunakan menu ini dengan sebaik mungkin" << endl;

    int choice;
    cout << "\nSilahkan pilih menu berikut" << endl;
    cout << "1. Pengadaan barang" << endl;
    cout << "2. Tambah kuantitas barang tersedia" << endl;
    cout << "3. Status" << endl;
    cout << "4. Kembali" << endl;
    cout << "Menu dipilih:"; cin >> choice;

    switch(choice){
    case 1:
        system("cls");
        siswa_minta1();
        break;
    case 2:
        system("cls");
        siswa_minta2();
        break;
    case 3:
        system("cls");
        siswa_minta3();
        break;
    case 4:
        system("cls");
        siswa();
        break;
    default:
        system("cls");
        cout<<"You've made a mistake , give it a try again\n"<<endl;
        main();
    }
}

void siswa_minta1()
{
    string kembali, pengajuanlokal[100];
    int simpan=0, dobel=0, jumlahpengajuanlokal[100];
    cout << "\n================================================================================================================" << endl;
    cout << "                                          MENU PENGADAAN BARANG BARU                                            " << endl;
    cout << "================================================================================================================" << endl;
    cout << "\nBanyak jenis barang yang diminta: "; cin >> minta;

    cout << "Barang yang diminta untuk diadakan:" << endl;
    for (int i=0; i<minta; i++){
        cin.getline(mnt, name2);
        cout << i+1 << ". Nama barang\t:";
        cin.getline(mnt, name2);
        pengajuanlokal[i+n1]=mnt;
        cout << "   Kuantitas\t:"; cin >> jumlahpengajuanlokal[i+n1];
    }
    system("cls");
    cout << "\nKonfirmasi" << endl;
    for (int i=0; i<minta; i++){
        for (int j=0; j<list1; j++){
            if (pengajuanlokal[i+n1]==barang[j]){
                dobel=1;
                cout << "\nBarang yang anda minta: " << pengajuanlokal[i+n1] << endl;
                cout << "Telah ada dalam daftar" << endl;
            } else {
                dobel=dobel;}
        }
        if (dobel==0){
            cout << "\nBarang yang anda minta: " << pengajuanlokal[i+n1] << endl;
            cout << "Kuantitas: " << jumlahpengajuanlokal[i+n1] << endl;
        }
        dobel=0;
    }
    cout << "\nApakah ada data yang ingin anda ubah? (Y/T): "; cin >> kembali;
    if (kembali=="Y"){
        system ("cls");
        siswa_minta1();
    } else if (kembali=="T"){
        for (int i=0; i<minta; i++){
            for (int j=0; j<list1; j++){
                if (pengajuanlokal[i+n1]==barang[j]){
                    dobel=1;
                } else {
                    dobel=dobel;}
            }
            if (dobel==0){
                pengajuan[simpan+n1]=pengajuanlokal[i+n1];
                jumlahpengajuan[simpan+n1]=jumlahpengajuanlokal[i+n1];
                simpan++;
            }
            dobel=0;
        }
        n1=minta;
        global1=global1+simpan;
        system("cls");
        cout << "Data telah disimpan" << endl;
        cout << "Silahkan menunggu permintaan diproses\n" << endl;
        siswa_minta();
    } else {
        main();
    }
}

void siswa_minta2()
{
    string choice;
    int simpan=0, dobel=0;
    cout << "\n================================================================================================================" << endl;
    cout << "                                       MENU PENAMBAHAN KUANTITAS BARANG                                         " << endl;
    cout << "================================================================================================================" << endl;
    cout << "\nSilahkan pilih barang dalam daftar yang ingin ditambah kuantitasnya\n" << endl;
    cout << "Barang tersedia" << endl;
    for (int i=0;i<list1;i++){
        cout << i+1 << ". Nama barang    :\t" << barang[i] << endl;
        cout << "   Tersedia       :\t" << kuantitas[i] << endl;
        cout << endl;
    }
    ulang:
    cout << "Banyak jenis barang yang ingin ditambah: "; cin >> banyak;
    if (banyak>list1){
        system("cls");

        cout << "\nBanyak barang yang anda minta melebihi persediaan\n" << endl;
        siswa_minta2();
    } else {
        system("cls");

        string nama[list1];
        int i,j, tampung[list2];
        cout << "Barang yang ingin ditambah kuantitasnya:" << endl;
        for (i=0; i<banyak; i++){
            cin.getline(mnt2, name3);
            cout << i+1 << ". Nama barang\t\t:";
            cin.getline(mnt2, name3);
            nama[i+n2]=mnt2;
            cout << "   Kuantitas tambahan\t:"; cin >> tampung[i+n2];
        }
        system("cls");
        cout << "Konfirmasi" << endl;
        for (i=0; i<banyak; i++){
            for (j=0; j<list1; j++){
                if (nama[i+n2]==barang[j]){
                    dobel=1;
                    cout << i+1 << ". Barang yang diminta\t: " << barang[j] << endl;
                    cout << "   Kuantitas awal\t: " << kuantitas[j] << endl;
                    cout << "   Kuantitas tambahan\t: " << tampung[i+n2] << endl;
                } else {
                    dobel=dobel;
                }
            } if (dobel==0){
                cout << i+1 << ". Barang yang diminta\t: " << nama[i+n2] << endl;
                cout << "   Tidak tersedia" << endl;
            }
            dobel=0;
        }
        cout << "Apakah ada data yang ingin anda ubah? (Y/T) "; cin >> choice;
        if (choice=="Y"){
            system("cls");
            goto ulang;
        } else if (choice=="T"){
            system("cls");
            for (i=0; i<banyak; i++){
                for (j=0; j<list1; j++){
                    if (nama[i+n2]==barang[j]){
                        tambah[j]=tampung[i+n2];
                        tampung[i+n2]=0;
                        simpan++;
                    }
                }
            }
            n2=banyak;
            global2=global2+simpan;
            cout << "Data telah disimpan" << endl;
            cout << "Silahkan tunggu sampai permintaan anda disetujui\n" << endl;
            siswa_minta();
        } else {
            system("cls");
            cout << "Your request cannot be processed\n" << endl;
            siswa_minta2();
        }
    }
}

void siswa_minta3()
{
    string kembali;
    int j=0, choice;
    cout << "\n================================================================================================================" << endl;
    cout << "                                           STATUS PERMINTAAN BARANG                                             " << endl;
    cout << "================================================================================================================" << endl;
    cout << endl;
    cout << "1. Pengadaan barang baru" << endl;
    cout << "2. Penambahan kuantitas barang" << endl;
    cout << "3. Kembali" << endl;
    cout << "\nPilih menu yang tersedia: "; cin >> choice;

    switch(choice){
    case 1:
        system("cls");
        checkpoint1:
        if (global1>0){
            for (int i=0; i<global1; i++){
                cout << i+1 << ". Barang diminta\t: " << pengajuan[i] << endl;
                cout << "   Kuantitas\t\t: " << jumlahpengajuan[i] << endl;
            if (status1[i]=="Disetujui" || status1[i]=="Ditolak"){
                cout << "   Status\t\t: " << status1[i] << "\n" << endl;
                } else {
                    cout << "   Status\t\t: Menunggu persetujuan\n" << endl;
                }
            }
            cout << "Tekan 'Y' untuk kembali: "; cin >> kembali;
            if (kembali=="Y"){
                system("cls");
                siswa_minta3();
            } else {
                system("cls");
                cout<<"You've made a mistake , give it a try again\n"<<endl;
                goto checkpoint1;
            }
        } else {
            cout << "Anda belum mengajukan barang apapun" << endl;
            siswa_minta();
        }
        break;
    case 2:
        system("cls");
        checkpoint2:
        if (global2>0){
            for (int i=0; i<list1; i++){
                if (tambah[i]>0){
                    cout << j+1 << ". Barang diminta\t: " << barang[i] << endl;
                    cout << "   Kuantitas awal\t: " << kuantitas[i] << endl;
                    cout << "   Kuantitas tambahan\t: " << tambah[i] << endl;
                    if (status2[i]=="Disetujui" || status2[i]=="Ditolak"){
                        cout << "   Status\t\t: " << status2[i] << "\n" << endl;
                    } else {
                        cout << "   Status\t\t: Menunggu persetujuan\n" << endl;
                    }
                    j++;
                }
            }
            cout << "Tekan 'Y' untuk kembali: "; cin >> kembali;
            if (kembali=="Y"){
                system("cls");
                siswa_minta3();
            } else {
                system("cls");
                cout<<"You've made a mistake , give it a try again\n"<<endl;
                goto checkpoint2;;
            }
        } else {
            cout << "Anda belum mengajukan penambahan barang apapun" << endl;
            siswa_minta();
        }
        break;
    case 3:
        system("cls");
        siswa_minta();
        break;
    default:
        system("cls");
        cout<<"You've made a mistake , give it a try again\n"<<endl;
        siswa_minta();
    }
}

void loginpegawai()
{
        int count;
        string user,pass,u,p;
        system("cls");
        cout << "Login Pegawai" << endl;
        cout << "Masukkan data berikut :"<<endl;
        cout << "Username :";
        cin >> user;
        cout << "Password :";
        cin >> pass;


        ifstream input("admin.txt");
        while(input>>u>>p){
            if(u==user && p==pass){
                count=1;
                system("cls");
            }
        }
        input.close();
        if(count==1){
            cout<<"\nHello "<<user<<"\nLOGIN SUCESS\nThanks for logging in\n";
            cin.get();
            cin.get();
            pegawai();
        } else {
            system("cls");
            cout << "\nLOGIN ERROR\n" << endl;
            cout << "Please check your username and password\n" << endl;
            main();
        }
}

void registr()
{
        string reguser,regpass,ru,rp;
        system("cls");
        cout << "Masukkan data anda" << endl;
        cout << "Enter the username :";
        cin >> reguser;
        cout << "\nEnter the password :";
        cin >> regpass;

        ofstream reg("admin.txt",ios::app);
        reg<<reguser<<' '<<regpass<<endl;
        system("cls");
        cout << "\nRegistration Sucessful\n";
        main();
}
