/*changelog 
23.dec.2018 - sedikit penyempurnaan ejaan, penyesuaian pilihan menu, sedikit merapihkan tampilan
25.dec.2018 - sedikit tambahan info pada L:568,596,674,704
*/

#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
//#include <conio.h>
//#include <dir.h>
//#include <process.h>
#include <cstdio>
//#include <filesystem>
//#include <stdio.h>

//#include <direct.h>
//#include <windows.h>
//#include <io.h>

#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>

using namespace std;

//FUNGSI SELAIN MAIN
char estimasi_cout(int nilai_estimasi, int saldo_copy_tetap){
    if (nilai_estimasi == saldo_copy_tetap) {
        cout << "Anda masih kaya" << endl;
    }
    else if(nilai_estimasi > saldo_copy_tetap/2){
        cout << "anda masih kaya" << endl;
    }
    else if(nilai_estimasi == 0){
        cout <<  "uang anda habis";
    }
    else if(nilai_estimasi < saldo_copy_tetap/2){
       cout << "anda mengalami kemiskinan, hemat uang anda" << endl;
    }
    else{
        cout << "uang anda tingggal setangah dari saldo awal anda" << endl;
    }
}

int total_out(int makanan,int kost,int tugas,int utang,int lain){
    int total_out = makanan + tugas + utang + kost + lain;
    return total_out;
}

int total_in(int saku,int gaji,int hutang,int lain){
    int total_in = saku + gaji + hutang + lain;
    return total_in;
}

int convert_string_to_integer(){
  string line;
  string aku;
  ifstream pemasukan ("saldo/saldo.txt");

  //Membaca file dari saldo.txt
  if(pemasukan.is_open()){

    while( getline(pemasukan,line)){
      aku = line;
    }
    pemasukan.close();
  }
  //convert string to integer
  stringstream ss(aku);
  int x;
  ss >> x;
  return x;
}

int saldo_tetap(){
  string line;
  string aku;
  ifstream pemasukan ("saldo/saldo_tetap.txt");

  if(pemasukan.is_open()){

    while( getline(pemasukan,line)){
      aku = line;
    }
    pemasukan.close();
  }
  //convert string to integer
  stringstream ss(aku);
  int x;
  ss >> x;
  return x;
}

//pengecekan isi file
bool pengecekan_isi_file(ifstream&pFile){
  return pFile.peek() == ifstream::traits_type::eof();
}

int total_pengeluaran_dan_pemasukan(string tanggal){
  string line;
  string aku;
  int x = 0;

  char * total = new char[tanggal.length()+1];
  strcpy (total,tanggal.c_str());

  ifstream pemasukan (total);

  if(pemasukan.is_open()){

    while( getline(pemasukan,line)){
      aku = line;
      stringstream ss(aku);
      int tampung;
      ss >> tampung;
      x += tampung;
    }
    pemasukan.close();
  }
  return x;
}

int  proses_saldo_pengeluaran(int total){
	//proses saldo
	int saldo_database;
    saldo_database = convert_string_to_integer();
    saldo_database -= total;
    ofstream buat_saldo("saldo/saldo.txt", ios::out);
    buat_saldo << saldo_database;
}

int proses_saldo_pemasukan(int total){
	//proses saldo
	int saldo_database;
	int saldo_database_tetap;
    saldo_database = convert_string_to_integer();
    saldo_database_tetap = saldo_tetap();
    saldo_database += total;
    saldo_database_tetap += total;
    ofstream buat_saldo("saldo/saldo.txt", ios::out);
    buat_saldo << saldo_database;
    //mengubah database saldo tetap
    ofstream buat_saldo_tetap("saldo/saldo_tetap.txt", ios::out);
    buat_saldo_tetap << saldo_database_tetap;
}

int remove_data_pengeluaran_perbulan(string tanggal){
	for(int i=1;i<=31;i++){
		stringstream tanggal_bulan,tanggal_bulan_total;
		tanggal_bulan << "pengeluaran/Pengeluaran-" << i << "-" << tanggal << ".txt";
		tanggal_bulan_total << "pengeluaran/total/Pengeluaran-" << i << "-" << tanggal << ".txt";
		string bulan = tanggal_bulan.str();
		string bulan_total = tanggal_bulan_total.str();
			
		char * bulan_char = new char[bulan.length()+1];
  		strcpy (bulan_char,bulan.c_str());

		char * bulan_total_char = new char[bulan_total.length()+1];
 		strcpy (bulan_total_char,bulan_total.c_str());
  			
  		ifstream kuku(bulan_char);
 		if (!kuku.fail()) {
 			kuku.close();
			remove(bulan_char);
			remove(bulan_total_char);
			cout << "File " << bulan_char << " berhasil dihapus " << endl;
			cout << "File " << bulan_total_char << " berhasil dihapus " << endl;
  		}
  		//else
  			//cout << "file " << bulan_char << " tidak ditekuman" << endl;
	}
	//cin.get();
}

int remove_data_pemasukan_perbulan(string tanggal){
	for(int i=1;i<=31;i++){
		stringstream tanggal_bulan,tanggal_bulan_total;
		tanggal_bulan << "pemasukan/Pemasukan-" << i << "-" << tanggal << ".txt";
		tanggal_bulan_total << "pemasukan/total/Pemasukan-" << i << "-" << tanggal << ".txt";
		string bulan = tanggal_bulan.str();
		string bulan_total = tanggal_bulan_total.str();
			
		char * bulan_char = new char[bulan.length()+1];
  		strcpy (bulan_char,bulan.c_str());

		char * bulan_total_char = new char[bulan_total.length()+1];
 		strcpy (bulan_total_char,bulan_total.c_str());
  			
  		ifstream kuku(bulan_char);
 		if (!kuku.fail()) {
    		kuku.close();
			remove(bulan_char);
			remove(bulan_total_char);
			cout << "File " << bulan_char << " berhasil dihapus " << endl;
			cout << "File " << bulan_total_char << " berhasil dihapus " << endl;
  		}
  		//else
  			//cout << "file " << bulan_char << " tidak ditekuman" << endl;
	}	
	//cin.get();
}

int remove_pengeluaran_perhari(string tanggal){
	stringstream tanggal_bulan,tanggal_bulan_total;
	tanggal_bulan << "pengeluaran/Pengeluaran-" << tanggal << ".txt";
	tanggal_bulan_total << "pengeluaran/total/Pengeluaran-" << tanggal << ".txt";
	string bulan = tanggal_bulan.str();
	string bulan_total = tanggal_bulan_total.str();
			
	char * bulan_char = new char[bulan.length()+1];
 	strcpy (bulan_char,bulan.c_str());

	char * bulan_total_char = new char[bulan_total.length()+1];
 	strcpy (bulan_total_char,bulan_total.c_str());
  		
  ifstream kuku(bulan_char);
 	if (!kuku.fail()) {
   	kuku.close();
		remove(bulan_char);
		remove(bulan_total_char);
		cout << "File " << bulan_char << " berhasil dihapus " << endl;
		cout << "File " << bulan_total_char << " berhasil dihapus " << endl;
  	}
  	else
  	cout << "file " << bulan_char << " tidak ditekuman" << endl;
}

int remove_pemasukan_perhari(string tanggal){
	stringstream tanggal_bulan,tanggal_bulan_total;
	tanggal_bulan << "pemasukan/Pemasukan-" << tanggal << ".txt";
	tanggal_bulan_total << "pemasukan/total/Pemasukan-" << tanggal << ".txt";
	string bulan = tanggal_bulan.str();
	string bulan_total = tanggal_bulan_total.str();
			
	char * bulan_char = new char[bulan.length()+1];
 	strcpy (bulan_char,bulan.c_str());

	char * bulan_total_char = new char[bulan_total.length()+1];
 	strcpy (bulan_total_char,bulan_total.c_str());
  		
  	ifstream kuku(bulan_char);
 	if (!kuku.fail()) {
   		kuku.close();
		remove(bulan_char);
		remove(bulan_total_char);
		cout << "File " << bulan_char << " berhasil dihapus " << endl;
		cout << "File " << bulan_total_char << " berhasil dihapus " << endl;
  	}
  	else
  		cout << "file " << bulan_char << " tidak ditekuman" << endl;
}

//FUNGSI MAIN
int main(){
  //DEKLARASI
  string detail_info,pemasukan_file,pengeluaran_file,gabungan_total;
  const int *saldo_copy;
  char pilih_detail;
  int pilihan1, pilihan2, saldo,estimasi;
  int total_outmakanan, outmakanan, total_outkost, outkost,total_outtugas,outtugas,oututang,total_oututang, total_outlain, outlain;
  int insaku, total_insaku, ingaji, total_ingaji, inhutang, total_inhutang, inlain, total_inlain;

  //DEKLARASI NILAI DEFAULT
  total_outmakanan = 0; total_outkost = 0; total_outtugas = 0; total_oututang = 0; total_outlain = 0; total_outmakanan = 0;
  total_insaku = 0; total_ingaji = 0; total_inhutang = 0; total_inlain = 0;
  insaku = 0; ingaji = 0; inhutang = 0; inlain = 0;
  outmakanan = 0; outkost = 0; outtugas = 0; oututang = 0; outlain = 0;

  //membuat direktori
  //mkdir(OutputFolder.c_str()
  //system(mkdir \abc\def\ghi\jkl”);
  mkdir("pengeluaran");
  mkdir("pemasukan");
  mkdir("saldo");
  mkdir("pengeluaran/total");
  mkdir("pemasukan/total");

  //membuat tanggal
  time_t now = time(0);
  //convert now to string form
  tm *dt = localtime(&now);
  //merubah tanggal dari INT menjadi String
  int tanggal1 = dt->tm_mday;
  int tanggal2 = 1 + dt->tm_mon;
  int tanggal3 = 1900 + dt->tm_year;
  stringstream ss1,ss2,ss1_total,ss2_total;
  ss1 << "pengeluaran/Pengeluaran-" << tanggal1 << "-" << tanggal2 << "-" << tanggal3 << ".txt";
  ss2 << "pemasukan/Pemasukan-" << tanggal1 << "-" << tanggal2 << "-" << tanggal3 << ".txt";
  ss1_total << "pengeluaran/total/Pengeluaran-" << tanggal1 << "-" << tanggal2 << "-" << tanggal3 << ".txt";
  ss2_total << "pemasukan/total/Pemasukan-" << tanggal1 << "-" << tanggal2 << "-" << tanggal3 << ".txt";
  string tanggal_pengeluaran_string = ss1.str();
  string tanggal_pemasukan_string = ss2.str();
  string tanggal_pengeluaran_total = ss1_total.str();
  string tanggal_pemasukan_total = ss2_total.str();

  //convert string to char
  char * tanggal_pengeluaran = new char[tanggal_pengeluaran_string.length()+1];
  strcpy (tanggal_pengeluaran,tanggal_pengeluaran_string.c_str());

  char * tanggal_pemasukan = new char[tanggal_pemasukan_string.length()+1];
  strcpy (tanggal_pemasukan,tanggal_pemasukan_string.c_str());

  char * tanggal_pengeluaran_total_file = new char[tanggal_pengeluaran_total.length()+1];
  strcpy (tanggal_pengeluaran_total_file,tanggal_pengeluaran_total.c_str());

  char * tanggal_pemasukan_total_file = new char[tanggal_pemasukan_total.length()+1];
  strcpy (tanggal_pemasukan_total_file,tanggal_pemasukan_total.c_str());


  cout << endl << "==== APLIKASI MANAJEMEN KEUANGAN PRIBADI ====" << endl << endl;

  //USER MENGINPUTKAN SALDO AWAL USER
  saldo_baru:
  system("cls");
  ifstream file("saldo/saldo.txt");
  if (!file) {
    cout << "Masukkan Saldo awal : ";
    cin >> saldo;
    //memasukkan nilai saldo ke database
    ofstream buat("saldo/saldo.txt", ios::out);
    ofstream buat_tetap("saldo/saldo_tetap.txt", ios::out);
    buat_tetap << saldo;
    buat << saldo;
  }
  else if(pengecekan_isi_file(file)){
	cout << "Masukkan Saldo awal : ";
    cin >> saldo;
    //memasukkan nilai saldo ke database
    ofstream buat("saldo/saldo.txt", ios::out);
    ofstream buat_tetap("saldo/saldo_tetap.txt", ios::out);
    buat_tetap << saldo;
    buat << saldo;
  }

  start :
  system("cls");
  cout << endl << "==== APLIKASI MANAJEMEN KEUANGAN PRIBADI ====" << endl << endl;
  //USER INFO
  cout << endl << "=========INFO=========" << endl << endl;
  cout << "= Tanggal : " << dt->tm_mday << "-" << dt->tm_mon + 1 << "-" << 1900 + dt->tm_year << endl;
  cout << "= Saldo : " << convert_string_to_integer() << endl;
  cout << "= Status : ";
  cout << estimasi_cout(convert_string_to_integer(), saldo_tetap()) << endl;
  cout << "=======================" << endl << endl;
  //MAIN MENU
  cout << "------------MENU------------" << endl;
  cout << "= (1) Tambahkan Pengeluaran" << endl <<
          "= (2) Tambahkan Pemasukkan" << endl <<
          "= (3) Info Masukan" << endl <<
          "= (4) Info Pengeluaran" << endl <<
          "= (5) Hapus Data" << endl <<
		  "= (6) Keluar"<< endl;
  cout << "Masukkan pilihan : ";
  cin >> pilihan1;


if (pilihan1 == 1) {
  	pengeluaran:
  	system("cls");
    //Tambahkan Pengeluaran
    cout << endl << endl;
    cout << "---=Tambah Pengeluaran=---" << endl;
    cout << "= (1) Makanan \n= (2) Keperluan kost \n= (3) Keperluan Tugas \n= (4) Bayar Hutang \n= (5) Lain-lain (tuliskan sendiri) \n= (6) Kembali"<<endl;
    cout << "Pilih Kategori : ";
    cin >> pilihan2;
    ofstream buat(tanggal_pengeluaran, ios::app);

    if (pilihan2 == 1) {
      cout << "Jumlah pengeluaran untuk makanan : ";
      cin >> outmakanan;
      total_outmakanan = total_outmakanan + outmakanan;
      //memasukkan data ke file
      proses_saldo_pengeluaran(outmakanan);
      ofstream buat(tanggal_pengeluaran, ios::app);
      buat << "Makanan \t= Rp." << outmakanan << endl;
      ofstream buat_total(tanggal_pengeluaran_total_file, ios::app);
      buat_total << outmakanan << endl;
    }
    else if(pilihan2 == 2){
      cout << "Jumlah pengeluaran untuk keperluan kost : ";
      cin >> outkost;
      total_outkost = total_outkost + outkost;
      //memasukkan data ke file
      proses_saldo_pengeluaran(outkost);
      ofstream buat(tanggal_pengeluaran, ios::app);
      buat << "Kost \t\t= Rp." << outkost << endl;
      ofstream buat_total(tanggal_pengeluaran_total_file, ios::app);
      buat_total << outkost << endl;
    }
    else if(pilihan2 == 3){
      cout << "Jumlah pengeluaran untuk tugas :";
      cin >> outtugas;
      total_outtugas = total_outtugas + outtugas;
      //memasukkan data ke file
      proses_saldo_pengeluaran(outtugas);
      ofstream buat(tanggal_pengeluaran, ios::app);
      buat << "Tugas \t\t= Rp." << outtugas << endl;
      ofstream buat_total(tanggal_pengeluaran_total_file, ios::app);
      buat_total << outtugas << endl;
    }
    else if(pilihan2 == 4){
      cout << "Jumlah pengeluaran untuk bayar utang : ";
      cin >> oututang;
      total_oututang = total_oututang + oututang;
      //memasukkan data ke file
      proses_saldo_pengeluaran(oututang);
      ofstream buat(tanggal_pengeluaran, ios::app);
      buat << "Utang \t\t= Rp." << oututang << endl;
      ofstream buat_total(tanggal_pengeluaran_total_file, ios::app);
      buat_total << oututang << endl;
    }
    else if(pilihan2 == 5){
      //menambahkan karakter spasi di string
      string pengeluaran_lain_lain="";
      cout << "Tulis kategori pengeluaran : ";
      cin.ignore();
      getline(cin,pengeluaran_lain_lain);
      
      cout << "Jumlah pengeluaran untuk lain-lain : ";
      cin >> outlain;
      total_outlain = total_outlain + outlain;
      //memasukkan data ke file
      proses_saldo_pengeluaran(outlain);
      ofstream buat(tanggal_pengeluaran, ios::app);
      buat << pengeluaran_lain_lain << " \t= Rp." << outlain << endl;
      ofstream buat_total(tanggal_pengeluaran_total_file, ios::app);
      buat_total << outlain << endl;
    }
    else if(pilihan2 == 6){
		goto start;
	}
	
    else{
        cout << "Input tidak valid";
        system ("pause");
        system ("cls");
        goto pengeluaran;
    }

    //PROMPT BAGI USER APABILA USER INGIN MENCATAT PENGELUARAN LAGI
    pilihan3:
    char pilihan3;
    cout << "Apakah anda ingin mencatat pengeluaran lagi? (y/n) :";
    cin >> pilihan3;
    if (pilihan3=='y'){
    	goto pengeluaran;
	}else if(pilihan3=='n'){
		system("cls");
		goto start;
	}else{
		cout << "Input tidak valid";
		goto pilihan3;
	}

  }

//JIKA USER INGIN MEMBUAT MASUKAN
else if(pilihan1 == 2){
	masukan:
	system("cls");
    //Tambahkan Masukan
    cout << endl << endl;
    cout << "---=Tambah Pemasukkan=---" << endl;
    cout << "= (1) Uang saku \n= (2) Gaji \n= (3) Hutang \n= (4) Lain-Lain \n= (5) Kembali" << endl;
    cout << "Pilih Kategori : ";
    cin >> pilihan2;
    ofstream buat(tanggal_pemasukan, ios::app);
    ofstream buat_total(tanggal_pemasukan_total_file, ios::app);

    if (pilihan2 == 1) {
      cout << "Jumlah masukan dari uang saku : ";
      cin >> insaku;
      total_insaku = total_insaku+insaku;
      //memasukkan data ke file
      proses_saldo_pemasukan(insaku);
      ofstream buat(tanggal_pemasukan, ios::app);
      buat << "Uang Saku \t= Rp." << insaku << endl;
      ofstream buat_total(tanggal_pemasukan_total_file, ios::app);
      buat_total << insaku << endl;
    }
    else if(pilihan2 == 2){
      cout << "Jumlah masukan dari gaji : ";
      cin >> ingaji;
      total_ingaji = total_ingaji + ingaji;
      //memasukkan data ke file
      proses_saldo_pemasukan(ingaji);
      ofstream buat(tanggal_pemasukan, ios::app);
      buat << "Gaji \t\t= Rp." << ingaji << endl;
      ofstream buat_total(tanggal_pemasukan_total_file, ios::app);
      buat_total << ingaji << endl;
    }
    else if(pilihan2 == 3){
      cout << "Jumlah masukan dari hutang` :";
      cin >> inhutang;
      total_inhutang = total_inhutang + inhutang;
      //memasukkan data ke file
      proses_saldo_pemasukan(inhutang);
      ofstream buat(tanggal_pemasukan, ios::app);
      buat << "Hutang \t\t= Rp." << inhutang << endl;
      ofstream buat_total(tanggal_pemasukan_total_file, ios::app);
      buat_total << inhutang << endl;
    }
    else if(pilihan2 == 4){
      //menambahkan karakter spasi di string
      string pemasukan_lain_lain = "";
      cout << "Tulis kategori pemasukan : ";
      cin.ignore();
      getline(cin,pemasukan_lain_lain);
      
      cout << "Jumlah masukan dari lain-lain : ";
      cin >> inlain;
      total_inlain = total_inlain + inlain;
      //memasukkan data ke file
      proses_saldo_pemasukan(inlain);
      ofstream buat(tanggal_pemasukan, ios::app);
      buat << pemasukan_lain_lain << "\t= Rp." << inlain << endl;
      
      ofstream buat_total(tanggal_pemasukan_total_file, ios::app);
      buat_total << inlain << endl;
    }
    else if(pilihan2 == 5){
		goto start;
	}	
    else{
      cout << "Input tidak valid";
      system ("cls");
      goto masukan;
    }
    pilihan4:
    //PROMPT APAKAH USER INGIN MENCATAT MASUKAN LAGI
    cout << "Apakah anda ingin mencatat masukan yang lain? (y/n)";
    char pilihan4;
    cin >> pilihan4;
    if (pilihan4=='y'){
    	system("cls");
    	goto masukan;
	} else if (pilihan4=='n'){
		system ("cls");
		goto start;
	}else{
		cout << "Input tidak valid";
		system("pause");
		goto pilihan4;
	}
  }

else if(pilihan1 == 3){
    percabangan3:
    system("cls");
    cin.get();
    cout << endl << "---=Info Masukan=---" << endl;
    cout << "= (1) Uang Saku : " << total_insaku<<endl;
    cout << "= (2) Gaji : " << total_ingaji<<endl;
    cout << "= (3) Hutang : " << total_inhutang<<endl;
    cout << "= (4) Lain-lain : " << total_inlain<<endl;
    //mengakses File database pemasukan
    cout << "= (5) Ingin melihat detail pemasukan [Y/T] : ";
    cin >> pilih_detail;
    if(pilih_detail == 'Y' || pilih_detail == 'y'){
    	system("cls");
    	int pilih_detail;
        cout << "--==PILIH TAMPILAN DATA==--" << endl;
        cout << "= (1) Detail Perhari " << endl;
        cout << "= (2) Detail Perbulan " << endl;
        cout << "Masukkan pilihan : ";
        cin >> pilih_detail;
        cout << endl;
        
        if(pilih_detail == 1){
        	string line;
        	string aku;
        	string info = "pemasukan/Pemasukan-";
        	cout << "Masukkan data tanggal (HH-BB-TTTT): ";
        	cin >> detail_info;

        	string gabungan = info + detail_info + ".txt";
        	gabungan_total = "pemasukan/total/Pemasukan-" + detail_info + ".txt";

			//merubah string manejadi char
			char * akses_pemasukan = new char[gabungan.length()+1];
  			strcpy (akses_pemasukan,gabungan.c_str());

        	system("cls");
        	cout << detail_info << endl << endl;

        	ifstream pemasukan(akses_pemasukan);
        	if(pemasukan.is_open()){
          		while( getline(pemasukan,line)){
            		cout << line << endl;
          		}
         	pemasukan.close();
        	}
        	cin.get();
		}
		
		else if(pilih_detail==2){
			string data_tanggal_bulan;
			string line;
			string aku;
			
        	cout << "Masukkan data bulan yang akan ditampilkan (BB-TTTT): ";
        	cin >> data_tanggal_bulan;
        	system("cls");

        	for(int i=1;i<=31;i++){
				stringstream tanggal_bulan;
				tanggal_bulan << "pemasukan/Pemasukan-" << i << "-" << data_tanggal_bulan << ".txt";
				string bulan = tanggal_bulan.str();
			
				char * bulan_char = new char[bulan.length()+1];
  				strcpy (bulan_char,bulan.c_str());
  			
        		//cout << bulan_char << endl;

        		ifstream pemasukan1(bulan_char);
  					
  				if(pemasukan1.is_open()){
  					cout << endl;
  					cout << bulan_char << endl;
          			while( getline(pemasukan1,line)){
            			aku = line;
            			cout << aku << endl;
          			}
         		pemasukan1.close();
        		}
			}
			cin.get();
		}
		
		else
			cout << "Masukkan anda salah" <<endl;
			cin.get();
			goto percabangan3;
        
    }
    
    else if(pilih_detail == 'T' || pilih_detail =='t'){
        goto start;
    }
    
    else{
      cout << "Masukkan anda salah [Y/T]" << endl;
      goto percabangan3;
    }
    
    cout << "TOTAL MASUKAN : " << total_pengeluaran_dan_pemasukan(gabungan_total);
    cin.get();
    goto start;
  }

  else if(pilihan1 == 4){
    percabangan4 :
    system("cls");
    cin.get();
    cout << endl << "---=Info Pengeluaran=---" << endl;
    cout << "= (1) Makanan : " << total_outmakanan<<endl;
    cout << "= (2) Keperluan Kost : " << total_outkost<<endl;
    cout << "= (3) Keperluan Tugas : " << total_outtugas<<endl;
    cout << "= (4) Bayar Hutang : " << total_oututang<<endl;
    cout << "= (5) Lain-lain : " << total_outlain<<endl;
    //mengakses File database pengeluaran
    cout << "= (6) Ingin melihat detail pengeluaran [Y/T] : ";
    cin >> pilih_detail;
    
    if(pilih_detail == 'Y' || pilih_detail == 'y'){
    	system("cls");
    	int pilih_detail;
        cout << "--==Pilih Tampilan Data==--" << endl;
        cout << "= (1) Detail Harian " << endl;
        cout << "= (2) Detail Bulanan " << endl;
        cout << "Masukkan pilihan : ";
        cin >> pilih_detail;
        cout << endl;
        
        if(pilih_detail==1){
        	string line;
        	string aku;
        	string info = "pengeluaran/Pengeluaran-";
        	cout << "Masukkan data tanggal (HH-BB-TTTT): ";
        	cin >> detail_info;

        	string gabungan = info + detail_info + ".txt";
        	gabungan_total = "pengeluaran/total/Pengeluaran-" + detail_info + ".txt";

        	system("cls");
        	cout << detail_info << endl << endl;

			//merubah string manejadi char
			char * akses_pengeluaran = new char[gabungan.length()+1];
  			strcpy (akses_pengeluaran,gabungan.c_str());

        	ifstream pemasukan(akses_pengeluaran);

        	if(pemasukan.is_open()){
          		while(getline(pemasukan,line)){
           	 		cout << line << endl;
          		}
          	pemasukan.close();
        	}
        cin.get();
        pemasukan.close();
		}
    	
    	else if(pilih_detail==2){
    		string data_tanggal_bulan;
			string line;
			string aku;
			
        	cout << "Masukkan data bulan yang akan ditampilkan (BB-TTTT): ";
        	cin >> data_tanggal_bulan;
        	system("cls");

        	for(int i=1;i<=31;i++){
				stringstream tanggal_bulan;
				tanggal_bulan << "pengeluaran/Pengeluaran-" << i << "-" << data_tanggal_bulan << ".txt";
				string bulan = tanggal_bulan.str();
			
				char * bulan_char = new char[bulan.length()+1];
  				strcpy (bulan_char,bulan.c_str());
  			
        		//cout << bulan_char << endl;

        		ifstream pemasukan1(bulan_char);
  					
  				if(pemasukan1.is_open()){
  					cout << endl;
  					cout << bulan_char << endl;
          			while( getline(pemasukan1,line)){
            			aku = line;
            			cout << aku << endl;
          			}
         		pemasukan1.close();
        		}
			}
			cin.get();
		}
		else
			cout << "Data yang anda masukan salah" << endl;
			cin.get();
			goto percabangan4;
    	
    }
    else if(pilih_detail == 'T' || pilih_detail =='t'){
        goto start;
    }
    
    else{
      cout << "Masukkan anda salah [Y/T]" << endl;
      goto percabangan4;
    }
    cout << "Totak Pengeluaran : " << total_pengeluaran_dan_pemasukan(gabungan_total);
    //cout << "TOTAL PENGELUARAN : " << total_out(total_outmakanan,total_outkost,total_outtugas,total_oututang,total_outlain) <<endl;
    cin.get();
    goto start;
  }
  
else if(pilihan1 == 5){
	hapus:
	system("cls");
	int pemilihan;
	cout << "---=Pilih Tipe Data=---" << endl << endl;
	cout << "= (1) Hapus data pengeluaran" <<endl;
	cout << "= (2) Hapus data pemasukan" << endl;
	cout << "= (3) Hapus keseluruhan" << endl;
	cout << "= (4) Kembali" << endl;
	cout << "Masukkan pilihan : ";
	cin >> pemilihan;
	
	if(pemilihan==1){
		pemilihan1:
		system("cls");
		int milih;
		cout << "--==Hapus Data Pengeluaran==--" << endl;
		cout << "= (1) Hapus per-Hari" <<endl;
		cout << "= (2) Hapus per-Bulan" << endl;
		//cout << "= (3) Hapus semua data pengeluaran" << endl;
		cout << "= (3) Kembali" << endl;
		cout << "Masukkan pilihan : ";
		cin >> milih;
		//====================pilihan1===========================
		if(milih == 1){
			string data_tanggal;
        	cout << "Masukkan data hari yang akan dihapus : ";
        	cin >> data_tanggal;
        	system("cls");
        	
        	remove_pengeluaran_perhari(data_tanggal);
        	cin.get();
		}
		else if(milih == 2){
			string data_tanggal_bulan;
        	cout << "Masukkan data bulan yang akan dihapus : ";
        	cin >> data_tanggal_bulan;
        	system("cls");
        	
        	remove_data_pengeluaran_perbulan(data_tanggal_bulan);
        	cin.get();
		}
		//else if(milih == 3){
			//remove("pengeluaran/total/Pengeluaran/");
			//remove("pengeluaran/Pengeluaran/");
		//}
		else if(milih == 3){
			goto hapus;
		}
		else
			cout << "Masukkan anda Salah";
			cin.get();
			goto pemilihan1;
	}
	
	//====================pilihan2===========================
	else if(pemilihan == 2){
		pemilihan2:
		system("cls");
		int milih;
		cout << "---=Hapus Data Pemasukkan=---" << endl;
		cout << "= (1) Hapus per-Hari" <<endl;
		cout << "= (2) Hapus per-Bulan" << endl;
		//cout << "= (3) Hapus semua data pemasukan" << endl;
		cout << "= (3) Kembali" << endl;
		cout << "Masukkan pilihan : ";
		cin >> milih;
		if(milih == 1){
			string data_tanggal;
        	cout << "Masukkan data hari yang akan dihapus : ";
        	cin >> data_tanggal;
        	system("cls");
        	
        	remove_pemasukan_perhari(data_tanggal);
        	cin.get();
		}
		else if(milih == 2){
			string data_tanggal_bulan;
        	cout << "Masukkan data bulan yang akan dihapus : ";
        	cin >> data_tanggal_bulan;
        	system("cls");
        	
        	remove_data_pemasukan_perbulan(data_tanggal_bulan);
        	cin.get();
		}
		
		//====================pilihan3===========================
		//else if(milih == 4){

		//}
		
		//====================pilihan4===========================
		else if(milih == 3){
			goto hapus;
		}
		else
			cout << "Masukkan anda Salah";
			cin.get();
			goto pemilihan1;
	}
	else if(pemilihan == 3){
		fstream saldo_masuk;
		fstream saldo_total;
		//menghapus isi file bukan direktori
		saldo_masuk.open("saldo/saldo.txt",ios::out | ios::trunc);
		saldo_total.open("saldo/saldo_tetap.txt",ios::out | ios::trunc);
			
		system("rmdir /s pemasukan");
		system("rmdir /s pengeluaran");
			
		saldo_masuk.close();
		saldo_total.close();
		
		goto saldo_baru;
		system("pause");
	}
	else if(pemilihan == 4){
		goto start;
	}
	else
		cout << "data yang anda masukkan salah";
		cin.get();
		goto hapus;
}

//menu exit
else if(pilihan1 == 6){
  	char keluar;
    	cout << "Apakah anda yakin ingin keluar? (Y/N) : ";
    	cin >> keluar;
    	
    	if (keluar == 'y' || keluar == 'Y'){
    		cout << endl << "Terimakasih! Sampai Jumpa" << endl;
			exit (0);
			
		}else if (keluar == 'n' || keluar == 'N'){
			system("cls");
			goto start;
		}else{
			cout << "Harap Masukkan Inputan yang benar!";
		}
    	
    	
}

else
	cin.get();
	cout << "Data yang anda masukkan salah" << endl;
	cin.get();
	goto start;


return 0;
}
