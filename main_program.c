/*
Program Proyek Akhir
Mata Kuliah Algoritma & Pemrograman
Sistem Reservasi Jadwal Praktikum
Nama/NPM Angggota Kelompok : 
1. Anthony Ivan Sunardi / 1306405111 
2. Rahmad Nurcahya / 1306369806
*/

/*
Praktikum dijalankan selama 1 bulan atau 4 minggu. Setiap kelompok yang terdiri dari 2 orang harus memasukan dulu data-datanya pada program, 
termasuk jadwal lab kelompok tersebut setiap minggunya. 
Setiap kelompok harus mengambil 1 modul setiap minggunya, tidak boleh lebih atau kurang dari 1. 
Setiap minggu modul yang diambil harus berbeda, dan boleh tidak berurutan.
Pada Praktikum ini, ada 4 modul yang harus diambil setiap kelompok, dan diberikan waktu 1 bulan untuk mengambil semua modul tersebut.
Dalam 1 minggu praktikum dapat dilaksanakan dari hari senin hingga jumat, dengan total 4 shift perhari.
1 shift pada praktikum ini hanya dapat diambil oleh 1 kelompok, tidak boleh ada 2 atau lebih kelompok yang mengambil modul yang sama di jadwal yang sama
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct data{//structure yang digunakan untuk penyimpan data kelompok dan jadwal praktikum kelompok tersebut
    char nomerkelompok[100];
    char namaanggota1[100];
    char namaanggota2[100];
    char hari[100];
	char hari1[100];
	char hari2[100];
	char hari3[100];
	char hari4[100];
	char shift[100];
    char shift1[100];
    char shift2[100];
    char shift3[100];
    char shift4[100];
    char modul[100];
    char modul1[100];
    char modul2[100];
    char modul3[100];
    char modul4[100];
}content;

char input[10][100];
/*
input[0] = input menu utama
input[1] = input mengulang pilihan atau tidak
input[2] = input nomer kelompok yang ingin dihapus, digunakan pada pilihan 2
input[3] = input nomer kelompok untuk pilihan 3, dan pilihan 4 
input[4] = input pilihan mode untuk pilihan 2
input[5] = input pilihan untuk pilihan 4
*/

//Prototype untuk program
void title(int* status, int size);
void help(int* status, int size);
void tabel_jadwal(content *ptrpraktikum, int* status, int size, int *ptrjumlahkelompok);
void mengubah_data_kelompok(content *ptrpraktikum, int* status, int size, int *ptrjumlahkelompok);
void search_data_kelompok(content *ptrpraktikum, int* status, int size, int *ptrjumlahkelompok);
void edit_data_kelompok(content *ptrpraktikum, int* status, int size, int *ptrjumlahkelompok);
void menampilkan_seluruh_data(content *ptrpraktikum, int* status, int size, int *ptrjumlahkelompok);

//Menu Utama
int main(){
	int i,status[10],jumlahkelompok=0;//
	/*
	status[0] = status loop menu utama
	status[1] = status loop menu pilihan 2,3,4
	status[2] = status menunjukan apakah data yang ingin dihapus pada pilihan 2 ada dalam program
	status[3] = indikator apakah data yang dicari ada atau tidak pada pilihan 3 & 4
	status[4] & status[5] = menunjukan apakah ada data double ketika ingin memasukan input pada pilihan 2 dan 4
	status[6] = menunjukan apakah data yang dicari ditemukan atau tidak dalam program
	status[7] = pengulangan sub pilihan pada pilihan 4
	status[8] = untuk pilihan tabel, menunjukan apakah ada kelompok pada jadwal yang sedang di print
	status[9] = status apakah input salah atau tidak
	*/
	for(i = 0;i < 10; i++){/*Mengkosongkan nilai variabel" dalam array status dan input agar tidak terjadi error dalam program*/
			status[i] = 0;
			strcpy(input[i],"\0");
	}
	while(status[0]==0){
		content praktikum[100];//Mendefinisikan nama untu type struct data. Maksimum 100 kelompok yang digunakan untuk program.
		system("cls");
		title(status,10);
		for(i = 0;i < 10; i++){/*Semua variabel dalam array status akan di reset kembali menjadi 0*/
			status[i] = 0;
		}
		printf("Pilihan : \n\n\t1.\tMenampilkan Tabel Jadwal\n\n\t2.\tMenambah/Mengurangi Data Kelompok\n\n\t3.\tMelihat Data Kelompok\n\n");
		printf("\t4.\tMengubah Detail atau Jadwal Praktikum Kelompok\n\n\t5.\tHelp!\n\n\t6.\tMenampilkan Seluruh Data Kelompok di Program\n\n\t7.\tMengakhiri Program!\n\n");
 		printf("Masukan Pilihan yang ingin diakses(Masukan Angka dari pilihan): ");
 		scanf("%s",input[0]);//Meminta Pengguna untuk memasukan pilihan yang ingin diakses
 		switch(atoi(input[0])){
 			
			case 1:
				tabel_jadwal(praktikum,status,10,&jumlahkelompok);//Function untuk pilihan 1
				break;
			
			case 2:
				mengubah_data_kelompok(praktikum,status,10,&jumlahkelompok);//Function untuk pilihan 2
				break;	
			
			case 3:
				search_data_kelompok(praktikum,status,10,&jumlahkelompok);//Function untuk pilihan 3
				break;	
			
			case 4:
				edit_data_kelompok(praktikum,status,10,&jumlahkelompok);//Function untuk pilihan 4
				break;
			
			case 5:
				help(status,10);//Function untuk pilihan 5
				break;
			
			case 6:
				menampilkan_seluruh_data(praktikum,status,10,&jumlahkelompok);//function untuk pilihan 6
				break;
				
			
			case 7:/*Mengakhiri Program*/
				printf("\n\t\t\tTerima Kasih!\n\n");
				status[0] = 1;
				break;
			
			default://Input Salah!
				status[9] = 1;
				break;
		}
	}
	system("PAUSE");
	return(0);
}

//Function untuk menunjukan judul program, yang ditampilkan tergantung nilai status[9] yang digunakan 
void title(int* status, int size){
	if(status[9]==0){
		printf("=============PROGRAM RESERVASI JADWAL PRAKTIKUM=============");
 		printf("\n\nTujuan = Menfasilitasi Mahasiswa dalam Reservasi Jadwal Praktikum");
		printf("\n\nLABORATORIUM KENDALI TEGANGAN TINGGI\n\n");		
	}
	else if(status[9]==1){
		printf("=============PROGRAM RESERVASI JADWAL PRAKTIKUM=============");
 		printf("\n\nTujuan = Menfasilitasi Mahasiswa dalam Reservasi Jadwal Praktikum");
		printf("\n\nLABORATORIUM KENDALI TEGANGAN TINGGI\n\n");	
		printf("Input salah, ulangi kembali!\n\n");	
	}
	else if(status[9]==2){
		printf("=============PROGRAM RESERVASI JADWAL PRAKTIKUM=============");
 		printf("\n\nTujuan = Menfasilitasi Mahasiswa dalam Reservasi Jadwal Praktikum");
		printf("\n\nLABORATORIUM KENDALI TEGANGAN TINGGI\n\n");	
		printf("Nomer Kelompok Telah digunakan! \n\n");	
	}
	else if(status[9]==3){
		printf("=============PROGRAM RESERVASI JADWAL PRAKTIKUM=============");
 		printf("\n\nTujuan = Menfasilitasi Mahasiswa dalam Reservasi Jadwal Praktikum");
		printf("\n\nLABORATORIUM KENDALI TEGANGAN TINGGI\n\n");	
		printf("Nama anggota tersebut telah digunakan! Masukan nama anggota yang lain!\n\n");	
	}
	else if(status[9]==4){
		printf("=============PROGRAM RESERVASI JADWAL PRAKTIKUM=============");
 		printf("\n\nTujuan = Menfasilitasi Mahasiswa dalam Reservasi Jadwal Praktikum");
		printf("\n\nLABORATORIUM KENDALI TEGANGAN TINGGI\n\n");	
		printf("Jadwal tersebut telah digunakan oleh kelompok lain\n\natau modul sudah diambil oleh kelompok!Gunakan jadwal yang lain!\n\n");	
	}
	else if(status[9]==7){
		printf("=============PROGRAM RESERVASI JADWAL PRAKTIKUM=============");
 		printf("\n\nTujuan = Menfasilitasi Mahasiswa dalam Reservasi Jadwal Praktikum");
		printf("\n\nLABORATORIUM KENDALI TEGANGAN TINGGI\n\n");	
		printf("Data berhasil disimpan!\n\n");	
	}
	return;
}

//Pilihan 1, menampilkan tabel jadwal praktikum dari laboratorium
void tabel_jadwal(content *ptrpraktikum, int* status, int size, int *ptrjumlahkelompok){
	int i,j,k,l,m;
	system("cls");
	title(status,10);
	printf("Tabel Jadwal Praktikum Laboratiorium Kendali Tegangan Tinggi\n\n");
	for(m = 1; m <=4 ; m++){//looping untuk setiap minggu, yang totalnya ada 4
		switch(m){
			case 1:
				printf("\nMinggu 1\n");
				break;
			case 2:
				printf("\n\n\n\nMinggu 2\n");
				break;
			case 3:
				printf("\n\n\n\nMinggu 3\n");
				break;
			case 4:
				printf("\n\n\n\nMinggu 4\n");
				break;
			default:
				break;	
		}
		printf("\t\t\t\tModul\n\n");
		for(i = 1;i <= 5;i++){//looping hari, yang totalnya ada 5 yaitu senin hingga jumat
			switch(i){
				case 1:
					printf("\t\t\t1\t2\t3\t4\n\nSenin\t");
					break;
				case 2:
					printf("\n\n\nSelasa\t");
					break;
				case 3:
					printf("\n\n\nRabu\t");
					break;
				case 4:
					printf("\n\n\nKamis\t");
					break;
				case 5:
					printf("\n\n\nJumat\t");
					break;
				default:
					break;	
			}
			for(j = 1;j <= 4;j++){//pada jadwal praktikum ini, ada 4 shift
				switch(j){
					case 1:
						printf("\n\n08:00-09:50\t");
						break;
					case 2:
						printf("\n\n10:00-11:50\t");
						break;
					case 3:
						printf("\n\n14:00-16:50\t");
						break;
					case 4:
						printf("\n\n17:00-19:50\t");
						break;
					default:
						break;
				}
				for(k = 1;k <= 4;k++){//total modul yang harus diambil ada 4 buah, 1 modul diambil oleh seorang kelompok setiap minggunya
					for(l = 1; l <= *ptrjumlahkelompok; l++){//mencari apakah ada kelompok yang menggunakan jadwal tersebut, jika ada maka akan ditampilkan nilainya pada tabel
						switch(m){
							case 1://Minggu 1
								//Jika ditemukan kelompok yang mengisi jadwalnya di jadwal tertentu
								if(atoi(ptrpraktikum[l].hari1)==i && atoi(ptrpraktikum[l].shift1)==j && atoi(ptrpraktikum[l].modul1)==k){
									printf("\t%s",ptrpraktikum[l].nomerkelompok);		
									l = *ptrjumlahkelompok + 1;	
									status[8] = 1;			
								}
								break;
							case 2://Minggu 2
								//Jika ditemukan kelompok yang mengisi jadwalnya di jadwal tertentu
								if(atoi(ptrpraktikum[l].hari2)==i && atoi(ptrpraktikum[l].shift2)==j && atoi(ptrpraktikum[l].modul2)==k){
									printf("\t%s",ptrpraktikum[l].nomerkelompok);		
									l = *ptrjumlahkelompok + 1;	
									status[8] = 1;			
								}
								break;
							case 3://Minggu 3
								//Jika ditemukan kelompok yang mengisi jadwalnya di jadwal tertentu
								if(atoi(ptrpraktikum[l].hari3)==i && atoi(ptrpraktikum[l].shift3)==j && atoi(ptrpraktikum[l].modul3)==k){
									printf("\t%s",ptrpraktikum[l].nomerkelompok);		
									l = *ptrjumlahkelompok + 1;	
									status[8] = 1;			
								}
								break;
							case 4://Minggu 4
								if(atoi(ptrpraktikum[l].hari4)==i && atoi(ptrpraktikum[l].shift4)==j && atoi(ptrpraktikum[l].modul4)==k){
									printf("\t%s",ptrpraktikum[l].nomerkelompok);		
									l = *ptrjumlahkelompok + 1;	
									status[8] = 1;			
								}
								break;
							default:
								break;
						}	
					}
					if(l == *ptrjumlahkelompok + 1 && status[8] != 1){
						printf("\t-");
						l = 1;
					}
					status[8]=0;
				}	
			}
		}
	}
	printf("\n\nKembali ke menu utama...\n\n");
	system("PAUSE");
	status[8]=0;
	return;
}

//Pilihan 2, menambahkan atau mengurangi data kelompok 
void mengubah_data_kelompok(content *ptrpraktikum, int* status, int size, int *ptrjumlahkelompok){
	int i,j,k,u=0;
	while(status[1]==0){//Jika nilai status[1] != 0, maka akan kembali ke menu utama
		system("cls");
		title(status,10);
		status[9]=0;
		i = 1;
		content temp;//structure sementara untuk melakukan pengecekan input sebelum disimpan dalam typedef struct data content praktikum
		printf("Jumlah kelompok yang ada dalam data : %d\n\n",*ptrjumlahkelompok);
		printf("Menu Menambah/Mengurangi Data Kelompok\n\n");	
		printf("\t1.\tMenambah Data\n\n\t2.\tMengurangi Data\n\n\t3.\tKembali kemenu utama\n\n");
		printf("Masukan pilihan yang ingin dilakukan(Masukan angka dari pilihan) : ");
		scanf("%s",&input[4]);
		switch(atoi(input[4])){
			case 1://Menambahkan data kelompok ke program
				*ptrjumlahkelompok = *ptrjumlahkelompok + 1;//Jumlah Kelompok dalam program bertambah 1
				
				//Input Nomer Kelompok
				system("cls");
				title(status,10);
				printf("\t\n\nMasukan Nomer Kelompok (Nomer Maksimum adalah 100): ");
				scanf("%s",temp.nomerkelompok);
				while(status[4]==0){
					if(strcmp(temp.nomerkelompok,"9")<=0 && strcmp(temp.nomerkelompok,"1")>=0 && atoi(temp.nomerkelompok)>=1 && atoi(temp.nomerkelompok)<=100){
						for(i = 1 ; i <= *ptrjumlahkelompok ; i++){//Menentukan apakah nomer kelompok telah digunakan
							if(strcmp(ptrpraktikum[i].nomerkelompok,temp.nomerkelompok)==0){//Jika ternyata nomer kelompok telah digunakan
								system("cls");
								title(status,10);
								status[5]=1;
								break;
							}
						}
						if(status[5]==0){
							strcpy(ptrpraktikum[*ptrjumlahkelompok].nomerkelompok,temp.nomerkelompok);
							status[4]=1;
						}
						else if(status[5]==1){
							status[9]=2;
							system("cls");
							title(status,10);
							printf("Masukan nomer kelompok yang lain (Nomer Maksimum adalah 100): ");
							scanf("%s",temp.nomerkelompok);
							status[9]=0;	
							status[5]=0;
						}
					}
					else{
						//apabila input ada yang tidak sesuai dengan yang diminta
						status[9]=1;
						system("cls");
						title(status,10);
						printf("\t\n\nMasukan Nomer Kelompok (Nomer Maksimum adalah 100): ");
						scanf("%s",temp.nomerkelompok);
						status[9]=0;	
					}
				}				
				i = 1;
				status[4]=0;
				status[9]=0;
				system("cls");
				title(status,10);
				printf("\tNomer Kelompok : %s\n\n\t",ptrpraktikum[*ptrjumlahkelompok].nomerkelompok);
						
				//Input Nama anggota 1 dari kelompok
				printf("\t\n\nMasukan Nama Anggota 1 : ");
				scanf("%s",temp.namaanggota1);
				while(status[4]==0){
					if(strcmp(temp.namaanggota1,"A")>=0){
						for(i = 1 ; i <= *ptrjumlahkelompok ; i++){//Menentukan apakah nama tersebut telah ada dalam data kelompok lain
							//Jika nama yang dimasukan telah digunakan dalam data kelompok lain
							if(strcmp(ptrpraktikum[i].namaanggota1,temp.namaanggota1)==0||strcmp(ptrpraktikum[i].namaanggota2,temp.namaanggota1)==0){
								system("cls");
								title(status,10);
								status[5]=1;
								break;
							}
						}
						if(status[5]==0){
							strcpy(ptrpraktikum[*ptrjumlahkelompok].namaanggota1,temp.namaanggota1);
							status[4]=1;
						}
						else if(status[5]==1){
							status[9]=3;
							system("cls");
							title(status,10);
							printf("\tNomer Kelompok : %s\n\n",ptrpraktikum[*ptrjumlahkelompok].nomerkelompok);
							printf("Masukan nama baru yang tidak ada pada kelompok lain : ");
							scanf("%s",temp.namaanggota1);
							status[9]=0;	
							status[5]=0;
						}
					}
					else{
						//apabila input ada yang tidak sesuai dengan yang diminta
						status[9]=1;
						system("cls");
						title(status,10);
						printf("\tNomer Kelompok : %s\n\n",ptrpraktikum[*ptrjumlahkelompok].nomerkelompok);
						printf("Masukan nama anggota 1 : ");
						scanf("%s",temp.namaanggota1);
						status[9]=0;	
					}
				}	
				i = 1;			
				status[4]=0;
				status[9]=0;
				system("cls");
				title(status,10);
				printf("\tNomer Kelompok : %s\n\n\t",ptrpraktikum[*ptrjumlahkelompok].nomerkelompok);
				printf("Nama Anggota 1 : %s\n\n\t",ptrpraktikum[*ptrjumlahkelompok].namaanggota1);
				
				//Input Nama anggota 2 dari kelompok
				printf("\t\n\nMasukan Nama Anggota 2 : ");
				scanf("%s",temp.namaanggota2);
				while(status[4]==0){
					if(strcmp(temp.namaanggota2,"A")>=0){
						for(i = 1 ; i <= *ptrjumlahkelompok ; i++){//Menentukan apakah nama tersebut telah ada dalam data kelompok lain
							//Jika nama yang dimasukan telah digunakan dalam data kelompok lain
							if(strcmp(ptrpraktikum[i].namaanggota2,temp.namaanggota2)==0||strcmp(ptrpraktikum[i].namaanggota1,temp.namaanggota2)==0){
								system("cls");
								title(status,10);
								status[5]=1;
								break;
							}
						}
						if(status[5]==0){
							strcpy(ptrpraktikum[*ptrjumlahkelompok].namaanggota2,temp.namaanggota2);
							status[4]=1;
						}
						else if(status[5]==1){
							status[9]=3;
							system("cls");
							title(status,10);
							printf("\tNomer Kelompok : %s\n\n\t",ptrpraktikum[*ptrjumlahkelompok].nomerkelompok);
							printf("Nama Anggota 1 : %s\n\n",ptrpraktikum[*ptrjumlahkelompok].namaanggota1);
							printf("Masukan nama baru yang tidak ada pada kelompok lain : ");
							scanf("%s",temp.namaanggota2);
							status[9]=0;	
							status[5]=0;
						}
					}
					else{
						//apabila input ada yang tidak sesuai dengan yang diminta
						status[9]=1;
						system("cls");
						title(status,10);
						printf("\tNomer Kelompok : %s\n\n\t",ptrpraktikum[*ptrjumlahkelompok].nomerkelompok);
						printf("Nama Anggota 1 : %s\n\n",ptrpraktikum[*ptrjumlahkelompok].namaanggota1);
						printf("Masukan nama anggota 2 : ");
						scanf("%s",temp.namaanggota2);
						status[9]=0;	
					}
				}			
				i = 1;	
				status[4]=0;
				status[9]=0;
				
				//jadwal praktikum kelompok
				while(status[4]==0){
					for(k = 1;k <= 4;k++){
						u=0;
						while(u==0){
							system("cls");
							title(status,10);
							status[9]=0;
							printf("\tNomer Kelompok : %s\n\n\t",ptrpraktikum[*ptrjumlahkelompok].nomerkelompok);
							printf("Nama Anggota 1 : %s\n\n\t",ptrpraktikum[*ptrjumlahkelompok].namaanggota1);
							printf("Nama Anggota 2 : %s\n\n",ptrpraktikum[*ptrjumlahkelompok].namaanggota2);
							switch(k){
								case 1:
									printf("Minggu 1!");
									break;
								case 2:
									printf("Minggu 2!");
									break;
								case 3:
									printf("Minggu 3!");
									break;
								case 4:
									printf("Minggu 4!");
									break;
								default:
									break;	
							}
							printf("\n\n(1.senin, 2.selasa, 3.rabu, 4.kamis, atau 5.jumat)\n\nMasukan Hari Praktikum Kelompok\n(dapat masukan angka hari jika diinginkan): ");
							scanf("%s",temp.hari);
							printf("\n\nShift 1 Jam 08:00-09:50 WIB\n\nShift 2 Jam 10:00-11:50 WIB\n\nShift 3 Jam 14:00-16:50 WIB\n\nShift 4 Jam 17:00-19:50 WIB");
							printf("\n\nMasukan Shift (1,2,3,atau 4) Praktikum Kelompok : ");
							scanf("%s",temp.shift);
							printf("\n\nMasukan Modul (1,2,3, atau 4) Praktikum Kelompok : ");
							scanf("%s",temp.modul);
							
							if(//Mengecek apakah input hari, shift, dan modul sesuai yang di minta
							(strcmp(temp.hari,"senin")==0 || strcmp(temp.hari,"selasa")==0 || strcmp(temp.hari,"rabu")==0 || strcmp(temp.hari,"kamis")==0 || strcmp(temp.hari,"jumat")==0 ||
							strcmp(temp.hari,"Senin")==0 || strcmp(temp.hari,"Selasa")==0 || strcmp(temp.hari,"Rabu")==0 || strcmp(temp.hari,"Kamis")==0 || strcmp(temp.hari,"Jumat")==0 ||
							strcmp(temp.hari,"1")==0 || strcmp(temp.hari,"2")==0 || strcmp(temp.hari,"3")==0 || strcmp(temp.hari,"4")==0 || strcmp(temp.hari,"5")==0) 
							&& (strcmp(temp.shift,"9")<=0 && strcmp(temp.shift,"1")>=0 && atoi(temp.shift)>=1 && atoi(temp.shift)<=4)
							&& (strcmp(temp.modul,"9")<=0 && strcmp(temp.modul,"1")>=0 && atoi(temp.modul)>=1 && atoi(temp.modul)<=4)){
								if(strcmp(temp.hari,"senin")==0 || strcmp(temp.hari,"Senin")==0){
									strcpy(temp.hari,"1");
								}
								else if(strcmp(temp.hari,"selasa")==0 || strcmp(temp.hari,"Selasa")==0){
									strcpy(temp.hari,"2");
								}
								else if(strcmp(temp.hari,"rabu")==0 || strcmp(temp.hari,"Rabu")==0){
									strcpy(temp.hari,"3");
								}
								else if(strcmp(temp.hari,"kamis")==0 || strcmp(temp.hari,"Kamis")==0){
									strcpy(temp.hari,"4");
								}
								else if(strcmp(temp.hari,"jumat")==0 || strcmp(temp.hari,"Jumat")==0){
									strcpy(temp.hari,"5");
								}
								for(i = 1 ; i <= *ptrjumlahkelompok ; i++){
									//Jika jadwal yang diinput untuk kelompok tersebut telah digunakan kelompok lain
									switch(k){
										case 1://Pengecekan untuk minggu 1
											if(strcmp(ptrpraktikum[i].hari1,temp.hari)==0 && strcmp(ptrpraktikum[i].shift1,temp.shift)==0 
											&& strcmp(ptrpraktikum[i].modul1,temp.modul)==0){
												system("cls");
												title(status,10);
												status[5]=1;
												i = *ptrjumlahkelompok + 1;
											}
											break;
										case 2:
											if(strcmp(ptrpraktikum[i].hari2,temp.hari)==0 && strcmp(ptrpraktikum[i].shift2,temp.shift)==0 
											&& strcmp(ptrpraktikum[i].modul2,temp.modul)==0 || (strcmp(ptrpraktikum[*ptrjumlahkelompok].modul1,temp.modul)==0)){
												system("cls");
												title(status,10);
												status[5]=1;
												i = *ptrjumlahkelompok + 1;
											}
											break;
										case 3:
											if(strcmp(ptrpraktikum[i].hari3,temp.hari)==0 && strcmp(ptrpraktikum[i].shift3,temp.shift)==0 
											&& strcmp(ptrpraktikum[i].modul3,temp.modul)==0 ||(strcmp(ptrpraktikum[*ptrjumlahkelompok].modul1,temp.modul)==0)
											||(strcmp(ptrpraktikum[*ptrjumlahkelompok].modul2,temp.modul)==0)){
												system("cls");
												title(status,10);
												status[5]=1;
												i = *ptrjumlahkelompok + 1;
											}
											break;
										case 4:
											if(strcmp(ptrpraktikum[i].hari4,temp.hari)==0 && strcmp(ptrpraktikum[i].shift4,temp.shift)==0 
											&& strcmp(ptrpraktikum[i].modul4,temp.modul)==0 ||(strcmp(ptrpraktikum[*ptrjumlahkelompok].modul1,temp.modul)==0)
											||(strcmp(ptrpraktikum[*ptrjumlahkelompok].modul2,temp.modul)==0)
											||(strcmp(ptrpraktikum[*ptrjumlahkelompok].modul3,temp.modul)==0)){
												system("cls");
												title(status,10);
												status[5]=1;
												i = *ptrjumlahkelompok + 1;
											}
											break;
										default:
											break;	
									}
								}
								i = 1;
								
								//Jika jadwal yang dipilih kosong
								if(status[5]==0){
									switch(k){
										case 1:
											strcpy(ptrpraktikum[*ptrjumlahkelompok].hari1,temp.hari);
											strcpy(ptrpraktikum[*ptrjumlahkelompok].shift1,temp.shift);
											strcpy(ptrpraktikum[*ptrjumlahkelompok].modul1,temp.modul);
											u = 1;
											break;
										case 2:
											strcpy(ptrpraktikum[*ptrjumlahkelompok].hari2,temp.hari);
											strcpy(ptrpraktikum[*ptrjumlahkelompok].shift2,temp.shift);
											strcpy(ptrpraktikum[*ptrjumlahkelompok].modul2,temp.modul);
											u = 1;
											break;
										case 3:
											strcpy(ptrpraktikum[*ptrjumlahkelompok].hari3,temp.hari);
											strcpy(ptrpraktikum[*ptrjumlahkelompok].shift3,temp.shift);
											strcpy(ptrpraktikum[*ptrjumlahkelompok].modul3,temp.modul);
											u = 1;
											break;
										case 4:
											strcpy(ptrpraktikum[*ptrjumlahkelompok].hari4,temp.hari);
											strcpy(ptrpraktikum[*ptrjumlahkelompok].shift4,temp.shift);
											strcpy(ptrpraktikum[*ptrjumlahkelompok].modul4,temp.modul);
											status[4]=1;
											u = 1;
											break;
										default:
											break;
									}
									
								}
								
								//Jika jadwal yang diinput untuk kelompok tersebut telah digunakan kelompok lain
								else if(status[5]==1){
									status[9]=4;
									status[5]=0;
								}	
							}
							else{
								//apabila input ada yang tidak sesuai dengan yang diminta
								status[9]=1;		
							}
						}
					}
				}
				
				//Menampilkan data yang telah dimasukan 
				status[9]=7;
				system("cls");
				title(status,10);
				printf("Jumlah kelompok yang ada dalam data : %d\n\n",*ptrjumlahkelompok);
				printf("Data:\n\n");
				printf("\tNomer Kelompok : %s\n\n\t",ptrpraktikum[*ptrjumlahkelompok].nomerkelompok);
				printf("Nama Anggota 1 : %s\n\n\t",ptrpraktikum[*ptrjumlahkelompok].namaanggota1);
				printf("Nama Anggota 2 : %s\n\nKeterangan Hari : \n\n",ptrpraktikum[*ptrjumlahkelompok].namaanggota2);
				
				for(k = 1;k <= 4;k++){
					switch(k){
						case 1:
							printf("1 = Senin, 2 = Selasa, 3 = Rabu, 4 = Kamis, 5 = Jumat\n\nKeterangan Shift : \n\n");
							printf("1 = Jam 08:00-09:50 WIB\n\n2 = Jam 10:00-11:50 WIB\n\n3 = Jam 14:00-16:50 WIB\n\n4 = Jam 17:00-19:50 WIB\n\nMingggu 1!\n\n\t");
							printf("Hari Praktikum : %s\n\n\t",ptrpraktikum[*ptrjumlahkelompok].hari1);
							printf("Shift Praktikum : %s\n\n\t",ptrpraktikum[*ptrjumlahkelompok].shift1);
							printf("Modul Praktikum : %s\n\n",ptrpraktikum[*ptrjumlahkelompok].modul1); 
							break;
						case 2:
							printf("Mingggu 2!\n\n\tHari Praktikum : %s\n\n\t",ptrpraktikum[*ptrjumlahkelompok].hari2);
							printf("Shift Praktikum : %s\n\n\t",ptrpraktikum[*ptrjumlahkelompok].shift2);
							printf("Modul Praktikum : %s\n\n",ptrpraktikum[*ptrjumlahkelompok].modul2); 
							break;
						case 3:
							printf("Minggu 3!\n\n\tHari Praktikum : %s\n\n\t",ptrpraktikum[*ptrjumlahkelompok].hari3);
							printf("Shift Praktikum : %s\n\n\t",ptrpraktikum[*ptrjumlahkelompok].shift3);
							printf("Modul Praktikum : %s\n\n",ptrpraktikum[*ptrjumlahkelompok].modul3); 
							break;
						case 4:
							printf("minggu 4!\n\n\tHari Praktikum : %s\n\n\t",ptrpraktikum[*ptrjumlahkelompok].hari4);
							printf("Shift Praktikum : %s\n\n\t",ptrpraktikum[*ptrjumlahkelompok].shift4);
							printf("Modul Praktikum : %s\n\n",ptrpraktikum[*ptrjumlahkelompok].modul4); 
							break;
						default:
							break;	
					}
				}
				printf("\n\nApakah pilihan ini ingin diulang?(masukan angka 1 jika iya)");
				scanf("%s",input[1]);//Menentukan apakah diulang pilihan 2 atau tidak
				status[1] = atoi(input[1])-1;
				status[9]=0;
				status[4]=0;
				break;
			
			case 2://Mengurangi Data kelompok pada program
				status[2] = 0;
				if(*ptrjumlahkelompok<=0){//Jika belum ada data kelompok yang tersimpan
					printf("\n\nBelum ada data kelompok yang telah dimasukan!");
					printf("\n\nApakah pilihan ini ingin diulang?(masukan angka 1 jika iya)");
					scanf("%s",input[1]);//Menentukan apakah diulang pilihan 2 atau tidak
					status[1] = atoi(input[1])-1;
				}
				else{//Jika ada data kelompok yang telah tersimpan
					printf("\n\nMasukan nomer kelompok yang ingin dihapus : ");
					scanf("%s",input[2]);//Input nomer kelompok yang ingin dihapus datanya dari program
					for(i = 1 ; i <= *ptrjumlahkelompok ; i++){//Mencari nomer kelompok tersebut dalam typedef struct data
						if(strcmp(ptrpraktikum[i].nomerkelompok,input[2])==0){//Jika data nomer kelompok yang ingin dihapus ditemukan telah tersimpan dalam program
							for(j = i;j <= *ptrjumlahkelompok ;j++){
								strcpy(ptrpraktikum[j].nomerkelompok,ptrpraktikum[j+1].nomerkelompok);
								strcpy(ptrpraktikum[j].namaanggota1,ptrpraktikum[j+1].namaanggota1);
								strcpy(ptrpraktikum[j].namaanggota2,ptrpraktikum[j+1].namaanggota2);
								strcpy(ptrpraktikum[j].hari,ptrpraktikum[j+1].hari1);
								strcpy(ptrpraktikum[j].hari,ptrpraktikum[j+1].hari2);
								strcpy(ptrpraktikum[j].hari,ptrpraktikum[j+1].hari3);
								strcpy(ptrpraktikum[j].hari,ptrpraktikum[j+1].hari4);
								strcpy(ptrpraktikum[j].shift,ptrpraktikum[j+1].shift1);
								strcpy(ptrpraktikum[j].shift,ptrpraktikum[j+1].shift2);
								strcpy(ptrpraktikum[j].shift,ptrpraktikum[j+1].shift3);
								strcpy(ptrpraktikum[j].shift,ptrpraktikum[j+1].shift4);
								strcpy(ptrpraktikum[j].modul,ptrpraktikum[j+1].modul1);
								strcpy(ptrpraktikum[j].modul,ptrpraktikum[j+1].modul2);
								strcpy(ptrpraktikum[j].modul,ptrpraktikum[j+1].modul3);
								strcpy(ptrpraktikum[j].modul,ptrpraktikum[j+1].modul4);
							}
							*ptrjumlahkelompok = *ptrjumlahkelompok - 1;
							system("cls");
							title(status,10);
							printf("Jumlah kelompok yang ada dalam data : %d\n\n",*ptrjumlahkelompok);
							printf("Data berhasil dihapus!");
							status[2] = 1;
							break;
						}
					}
					if(status[2] != 1){//Jika data nomer kelompok yang ingin dihapus tidak ditemukan telah tersimpan dalam program
						printf("\n\nTidak ada nomer kelompok tersebut dalam data!");
					}
					printf("\n\nApakah pilihan ini ingin diulang?(masukan angka 1 jika iya)");
					scanf("%s",input[1]);//Menentukan apakah diulang pilihan 2 atau tidak
					status[1] = atoi(input[1])-1;
				}
				break;
			
			case 3://kembali ke menu utama secara langsung
				status[1]=1;
			
			default://Input salah!
				status[9]=1;
				break;
		}
	}
	/*Ketika akan kembali kemenu utama, semua variabel dalam array status dan input akan di reset kembali menjadi 0*/
	for(i = 0;i < 10; i++){
		status[i] = 0;
		strcpy(input[i],"");
	}
	return;
}

//Pilihan 3, searching data kelompok yang ada pada program
void search_data_kelompok(content * ptrpraktikum, int* status, int size, int *ptrjumlahkelompok){
	int i,j,k;
	while(status[1]==0){//jika nilai tidak 0, maka pilihan ini tidak akan diulang
		system("cls");
		title(status,10);
		printf("Jumlah kelompok yang ada dalam data : %d\n\n",*ptrjumlahkelompok);
		printf("Menu Mencari Data Kelompok\n\n");
		if(*ptrjumlahkelompok == 0){
			printf("Tidak ada data kelompok yang tersimpan dalam program!\n\nKembali ke menu utama...\n\n");//Tidak ada data yang telah tersimpan, dipaksa kembali ke menu utama
			status[1] = 1;
			system("PAUSE");
		}
		else{
			printf("Masukan Nomer Kelompok yang ingin ditampilkan datanya : ");
			scanf("%s",input[3]);//input nomer kelompok yang ingin di cari datanya.
			for(i = 1;i <= *ptrjumlahkelompok; i++){
				if(strcmp(ptrpraktikum[i].nomerkelompok,input[3])==0){//jika menemukan data kelompok yang ingin ditampilkan, data-data tersebut akan ditampilkan
					printf("Data:\n\n");
					status[3]=1;
					printf("\tNomer Kelompok : %s\n\n\t",ptrpraktikum[i].nomerkelompok);
					printf("Nama Anggota 1 : %s\n\n\t",ptrpraktikum[i].namaanggota1);
					printf("Nama Anggota 2 : %s\n\nKeterangan Hari : \n\n",ptrpraktikum[i].namaanggota2);
					for(k = 1;k <= 4;k++){
						switch(k){
							case 1:
								printf("1 = Senin, 2 = Selasa, 3 = Rabu, 4 = Kamis, 5 = Jumat\n\nKeterangan Shift : \n\n");
								printf("1 = Jam 08:00-09:50 WIB\n\n2 = Jam 10:00-11:50 WIB\n\n3 = Jam 14:00-16:50 WIB\n\n4 = Jam 17:00-19:50 WIB\n\nMingggu 1!\n\n\t");
								printf("Hari Praktikum : %s\n\n\t",ptrpraktikum[i].hari1);
								printf("Shift Praktikum : %s\n\n\t",ptrpraktikum[i].shift1);
								printf("Modul Praktikum : %s\n\n",ptrpraktikum[i].modul1); 
								break;
							case 2:
								printf("Mingggu 2!\n\n\tHari Praktikum : %s\n\n\t",ptrpraktikum[i].hari2);
								printf("Shift Praktikum : %s\n\n\t",ptrpraktikum[i].shift2);
								printf("Modul Praktikum : %s\n\n\t",ptrpraktikum[i].modul2); 
								break;
							case 3:
								printf("Minggu 3!\n\n\tHari Praktikum : %s\n\n\t",ptrpraktikum[i].hari3);
								printf("Shift Praktikum : %s\n\n\t",ptrpraktikum[i].shift3);
								printf("Modul Praktikum : %s\n\n",ptrpraktikum[i].modul3); 
								break;
							case 4:
								printf("minggu 4!\n\n\tHari Praktikum : %s\n\n\t",ptrpraktikum[i].hari4);
								printf("Shift Praktikum : %s\n\n\t",ptrpraktikum[i].shift4);
								printf("Modul Praktikum : %s\n\n",ptrpraktikum[i].modul4); 
								break;
							default:
								break;	
						}
					}
					break;
				}
			}
			if(status[3]!=1){
				printf("\n\nData Kelompok tersebut tidak ada dalam program!");
			}
			printf("\n\nApakah pilihan ini ingin diulang?(masukan angka 1 jika iya)");
			scanf("%s",input[1]);//Menentukan apakah diulang pilihan 3 atau tidak
			status[1] = atoi(input[1])-1;	
			status[3]=0;
		}
	}
	/*Ketika akan kembali kemenu utama, semua variabel dalam array statu dan input akan di reset kembali menjadi 0*/
	for(i = 0;i < 10; i++){
		status[i] = 0;
		strcpy(input[i],"");
	}
	return;
}

//Pilihan 4, mengubah detail kelompok, atau mengubah jadwal kelompok 
void edit_data_kelompok(content *ptrpraktikum, int* status, int size, int *ptrjumlahkelompok){
	int i,j,k;
	content temp;//structure sementara untuk melakukan pengecekan input sebelum disimpan dalam typedef struct data content praktikum
	while(status[1]==0){//jika nilai tidak 0, maka pilihan ini tidak akan diulang
		system("cls");
		title(status,10);
		printf("Jumlah kelompok yang ada dalam data : %d\n\n",*ptrjumlahkelompok);
		printf("Menu Mengubah Detail Data Kelompok atau Jadwal Kelompok\n\n");
		if(*ptrjumlahkelompok == 0){
			printf("Tidak ada data kelompok yang tersimpan dalam program!\n\nKembali ke menu utama...\n\n");//Tidak ada data yang telah tersimpan, dipaksa kembali ke menu utama
			status[1] = 1;
			system("PAUSE");
		}
		else{
			printf("Masukan Nomer Kelompok yang ingin diubah detail data / jadwal praktikumnya : ");
			scanf("%s",input[3]);//input nomer kelompok yang ingin diubah data atau jadwalnya.
			for(i = 1;i <= *ptrjumlahkelompok; i++){
				if(strcmp(ptrpraktikum[i].nomerkelompok,input[3])==0){//jika menemukan data kelompok yang ingin diubah detail atau jadwalnya
					status[3]=1;
					printf("Nomer Kelompok yang ingin diubah detailnya / jadwalnya : %s\n\n",ptrpraktikum[i].nomerkelompok);
					printf("Pilihan :\n\n\t1.Ubah Nama Anggota 1 dari kelompok \n\n\t2.Ubah Nama Anggota 2 dari kelompok\n\n\t");
					printf("3.Ubah Jadwal Praktikum Kelompok\n\n\t4.Kembali kemenu utama\n\n");
					printf("Masukan nomer pilihan yang ingin digunakan : ");
					scanf("%s",&input[5]);
					switch(atoi(input[5])){
						case 1:{//Pilihan 1 : Mengubah nama anggota 1 dari kelompok yang telah dipilih
							while(status[4]==0){
								system("cls");
								title(status,10);
								status[9]=0;
								printf("Nomer Kelompok yang ingin diubah detailnya / jadwalnya : %s\n\n",ptrpraktikum[i].nomerkelompok);
								printf("Pilihan : 1.Ubah Nama Anggota 1\n\n");
								printf("Nama Anggota 1 Kelompok %s : %s\n\n",ptrpraktikum[i].nomerkelompok,ptrpraktikum[i].namaanggota1);
								printf("Nama Anggota 1 kelompok &s yang baru : ",ptrpraktikum[i].nomerkelompok);
								scanf("%s",&temp.namaanggota1);
								if(strcmp(temp.namaanggota1,"A")>=0){
									for(j = 1 ; j<=*ptrjumlahkelompok ;j++){	
										//Jika nama anggota telah digunakan pada kelompok lain
										if(strcmp(temp.namaanggota1,ptrpraktikum[j].namaanggota1)==0 || strcmp(temp.namaanggota1,ptrpraktikum[j].namaanggota2)==0){
											status[5]=1;
											break;
										}	
									}
									if(status[5]==0){//Jika nama anggota belum digunakan pada kelompok lain
										strcpy(ptrpraktikum[i].namaanggota1,temp.namaanggota1);
										status[4]=1;
										printf("\n\nNama Anggota 1 dari Kelompok %s Berhasil Diubah!", ptrpraktikum[i].nomerkelompok);
									}
									else if(status[5]==1){//Jika nama anggota telah digunakan pada kelompok lain
										status[9]=3;
										status[5]=0;
									}
								}
								else{
									status[9]=1;
								}
							}
							status[4]=0;
							break;
						}
						
						case 2:{//Pilihan 2 : Mengubah nama anggota kedua dari kelompok yang dipilih
							while(status[4]==0){
								system("cls");
								title(status,10);
								status[9]=0;
								printf("Nomer Kelompok yang ingin diubah detailnya / jadwalnya : %s\n\n",ptrpraktikum[i].nomerkelompok);
								printf("Pilihan : 2.Ubah Nama Anggota 2\n\n");
								printf("Nama Anggota 2 Kelompok %s : %s\n\n",ptrpraktikum[i].nomerkelompok,ptrpraktikum[i].namaanggota2);
								printf("Nama Anggota 2 kelompok %s yang baru : ",ptrpraktikum[i].nomerkelompok);
								scanf("%s",&temp.namaanggota2);
								if(strcmp(temp.namaanggota2,"A")>=0){
									for(j = 1 ; j<=*ptrjumlahkelompok ;j++){	
										//Jika nama anggota telah digunakan pada kelompok lain
										if(strcmp(temp.namaanggota2,ptrpraktikum[j].namaanggota2)==0 || strcmp(temp.namaanggota2,ptrpraktikum[j].namaanggota1)==0){
											status[5]=1;
											break;
										}	
									}
									if(status[5]==0){//Jika nama anggota belum digunakan pada kelompok lain
										strcpy(ptrpraktikum[i].namaanggota2,temp.namaanggota2);
										status[4]=1;
										printf("\n\nNama Anggota 2 dari Kelompok %s Berhasil Diubah!", ptrpraktikum[i].nomerkelompok);
									}
									else if(status[5]==1){//Jika nama anggota telah digunakan pada kelompok lain
										status[9]=3;
										status[5]=0;
									}
								}
								else{
									status[9]=1;
								}
							}
							status[4]=0;
							break;
						}	
						
						case 3:{//Pilihan 3 :  Mengubah jadwal praktikum dari kelompok yang telah dipilih
							for(k = 1;k <= 4; k++){
								while(status[4]==0){
									system("cls");
									title(status,10);
									status[9]=0;
									printf("Nomer Kelompok yang ingin diubah detailnya / jadwalnya : %s\n\n",ptrpraktikum[i].nomerkelompok);
									printf("Pilihan : 3.Mengubah Jadwal Praktikum Dari Kelompok\n\n");
									printf("\n\nShift 1 Jam 08:00-09:50 WIB\n\nShift 2 Jam 10:00-11:50 WIB\n\nShift 3 Jam 14:00-16:50 WIB\n\nShift 4 Jam 17:00-19:50 WIB");
									printf("\n\nhari 1 = Senin\n\nhari 2 =  Selasa\n\nhari 3 = Rabu\n\nhari 4 = Kamis\n\nhari 5 = Jumat\n\n");
									switch(k){
										case 1:
											printf("Minggu %d!\n\n",k);
											printf("Hari Praktikum Kelompok %s : %s\n\n",ptrpraktikum[i].nomerkelompok,ptrpraktikum[i].hari1);
											printf("Shift Praktikum Kelompok %s : %s\n\n",ptrpraktikum[i].nomerkelompok,ptrpraktikum[i].shift1);
											printf("Modul Praktikum Kelompok %s : %s\n\n",ptrpraktikum[i].nomerkelompok,ptrpraktikum[i].modul1);
											break;
										case 2:
											printf("Minggu %d!\n\n",k);
											printf("Hari Praktikum Kelompok %s : %s\n\n",ptrpraktikum[i].nomerkelompok,ptrpraktikum[i].hari2);
											printf("Shift Praktikum Kelompok %s : %s\n\n",ptrpraktikum[i].nomerkelompok,ptrpraktikum[i].shift2);
											printf("Modul Praktikum Kelompok %s : %s\n\n",ptrpraktikum[i].nomerkelompok,ptrpraktikum[i].modul2);
											break;
										case 3:
											printf("Minggu %d!\n\n",k);
											printf("Hari Praktikum Kelompok %s : %s\n\n",ptrpraktikum[i].nomerkelompok,ptrpraktikum[i].hari3);
											printf("Shift Praktikum Kelompok %s : %s\n\n",ptrpraktikum[i].nomerkelompok,ptrpraktikum[i].shift3);
											printf("Modul Praktikum Kelompok %s : %s\n\n",ptrpraktikum[i].nomerkelompok,ptrpraktikum[i].modul3);
											break;
										case 4:
											printf("Minggu %d!\n\n",k);
											printf("Hari Praktikum Kelompok %s : %s\n\n",ptrpraktikum[i].nomerkelompok,ptrpraktikum[i].hari4);
											printf("Shift Praktikum Kelompok %s : %s\n\n",ptrpraktikum[i].nomerkelompok,ptrpraktikum[i].shift4);
											printf("Modul Praktikum Kelompok %s : %s\n\n",ptrpraktikum[i].nomerkelompok,ptrpraktikum[i].modul4);
											break;	
									}
									
									printf("Hari Praktikum kelompok &s yang baru : ",ptrpraktikum[i].nomerkelompok);
									scanf("%s",&temp.hari);
									printf("\n\nShift Praktikum kelompok &s yang baru : ",ptrpraktikum[i].nomerkelompok);
									scanf("%s",&temp.shift);
									printf("\n\nModul Praktikum kelompok &s yang baru : ",ptrpraktikum[i].nomerkelompok);
									scanf("%s",&temp.modul);
									if((strcmp(temp.hari,"senin")==0 || strcmp(temp.hari,"selasa")==0 || strcmp(temp.hari,"rabu")==0 || strcmp(temp.hari,"kamis")==0 || 
									strcmp(temp.hari,"jumat")==0 || strcmp(temp.hari,"Senin")==0 || strcmp(temp.hari,"Selasa")==0 || strcmp(temp.hari,"Rabu")==0 || 
									strcmp(temp.hari,"Kamis")==0 || strcmp(temp.hari,"Jumat")==0 || strcmp(temp.hari,"1")==0 || strcmp(temp.hari,"2")==0 || 
									strcmp(temp.hari,"3")==0 || strcmp(temp.hari,"4")==0 || strcmp(temp.hari,"5")==0 ) 
									&& (strcmp(temp.shift,"9")<=0 && strcmp(temp.shift,"1")>=0 && atoi(temp.shift)>=1 && atoi(temp.shift)<=4)
									&& (strcmp(temp.modul,"9")<=0 && strcmp(temp.modul,"1")>=0 && atoi(temp.modul)>=1 && atoi(temp.modul)<=4)
									){
										if(strcmp(temp.hari,"senin")==0 || strcmp(temp.hari,"Senin")==0){
											strcpy(temp.hari,"1");
										}
										else if(strcmp(temp.hari,"selasa")==0 || strcmp(temp.hari,"Selasa")==0){
											strcpy(temp.hari,"2");
										}
										else if(strcmp(temp.hari,"rabu")==0 || strcmp(temp.hari,"Rabu")==0){
											strcpy(temp.hari,"3");
										}
										else if(strcmp(temp.hari,"kamis")==0 || strcmp(temp.hari,"Kamis")==0){
											strcpy(temp.hari,"4");
										}
										else if(strcmp(temp.hari,"jumat")==0 || strcmp(temp.hari,"Jumat")==0){
											strcpy(temp.hari,"5");
										}
										
										for(j = 1 ; j<=*ptrjumlahkelompok ;j++){
											//Jika jadwal yang diinput untuk kelompok tersebut telah digunakan kelompok lain
											switch(k){
												case 1://Pengecekan untuk minggu 1
													if(strcmp(ptrpraktikum[j].hari1,temp.hari)==0 && strcmp(ptrpraktikum[j].shift1,temp.shift)==0 
													&& (strcmp(ptrpraktikum[j].modul1,temp.modul)==0)){
														status[5]=1;
														j = *ptrjumlahkelompok + 1;
													}
													break;
												case 2:
													if(strcmp(ptrpraktikum[j].hari2,temp.hari)==0 && strcmp(ptrpraktikum[j].shift2,temp.shift)==0 
													&& strcmp(ptrpraktikum[j].modul2,temp.modul)==0 || (strcmp(ptrpraktikum[i].modul1,temp.modul)==0)){
														status[5]=1;
														j = *ptrjumlahkelompok + 1;
													}
													break;
												case 3:
													if(strcmp(ptrpraktikum[j].hari3,temp.hari)==0 && strcmp(ptrpraktikum[j].shift3,temp.shift)==0 
													&& strcmp(ptrpraktikum[j].modul3,temp.modul)==0 ||(strcmp(ptrpraktikum[i].modul1,temp.modul)==0)
													||(strcmp(ptrpraktikum[i].modul2,temp.modul)==0)){
														status[5]=1;
														j = *ptrjumlahkelompok + 1;
													}
													break;
												case 4:
													if(strcmp(ptrpraktikum[j].hari4,temp.hari)==0 && strcmp(ptrpraktikum[j].shift4,temp.shift)==0 
													&& strcmp(ptrpraktikum[j].modul4,temp.modul)==0 ||(strcmp(ptrpraktikum[i].modul1,temp.modul)==0)
													||(strcmp(ptrpraktikum[i].modul2,temp.modul)==0)
													||(strcmp(ptrpraktikum[i].modul3,temp.modul)==0)){
														status[5]=1;
														j = *ptrjumlahkelompok + 1;
													}
													break;
												default:
													break;	
											}
										}
										j = 1;
										
										if(status[5]==0){//Jika jadwal belum digunakan pada kelompok lain
											switch(k){
												case 1:
													strcpy(ptrpraktikum[i].hari1,temp.hari);
													strcpy(ptrpraktikum[i].shift1,temp.shift);
													strcpy(ptrpraktikum[i].modul1,temp.modul);
													break;
												case 2:
													strcpy(ptrpraktikum[i].hari2,temp.hari);
													strcpy(ptrpraktikum[i].shift2,temp.shift);
													strcpy(ptrpraktikum[i].modul2,temp.modul);
													break;
												case 3:
													strcpy(ptrpraktikum[i].hari3,temp.hari);
													strcpy(ptrpraktikum[i].shift3,temp.shift);
													strcpy(ptrpraktikum[i].modul3,temp.modul);
													break;
												case 4:
													strcpy(ptrpraktikum[i].hari4,temp.hari);
													strcpy(ptrpraktikum[i].shift4,temp.shift);
													strcpy(ptrpraktikum[i].modul4,temp.modul);
													break;
												default:
													break;	
											}
											status[4]=1;
										}
										else if(status[5]==1){//Jika jadwal telah digunakan pada kelompok lain
											status[9]=4;
											status[5]=0;
										}
									}
									else{
										status[9]=1;
									}
								}	
								status[4]=0;		
							}
							printf("\n\nJadwal dari Kelompok %s Berhasil Diubah!", ptrpraktikum[i].nomerkelompok);
							break;
						}
						case 4:{//Keluar dari pilihan 4
							status[1]=1;
							i = *ptrjumlahkelompok + 1;
 							break;
						}
						default:{//Input salah!
							status[9]=1;
							system("cls");
							title(status,10);
							status[9]=0;
							i = 1;
							break;
						}	
					}
				}
			}
			if(status[3]!=1){
				printf("\n\nData Kelompok tersebut tidak ada dalam program!");
			}
			printf("\n\nApakah pilihan ini ingin diulang?(masukan angka 1 jika iya)");
			scanf("%s",input[1]);//Menentukan apakah diulang pilihan 3 atau tidak
			status[1] = atoi(input[1])-1;	
			status[3]=0;
			status[9]=0;
		}
	}
	/*Ketika akan kembali kemenu utama, semua variabel dalam array statu dan input akan di reset kembali menjadi 0*/
	for(i = 0;i < 10; i++){
		status[i] = 0;
		strcpy(input[i],"");
	}
	return;
}

//Pilihan 5, menu help
void help(int* status, int size){
	system("cls");
	title(status,10);
	printf("Menu HELP\n\n");
	printf("\t>Untuk Menampilkan Tabel Data, gunakan pilihan 1\n\n\t>Untuk mengisi data anggota kelompok dan juga jadwalnya,\n\tgunakan pilihan 2\n\n");
	printf("\t>Untuk melihat data kelompok, gunakan pilihan 3\n\n");
	printf("\t>Untuk mengubah detail kelompok atau jadwal praktikum kelompok,\n\tgunakan pilihan 4.\n\n");
	printf("Kembali kemenu utama...");
	system("PAUSE");
	return;
}

//Pilihan 6, menampilkan seluruh data kelompok yang telah dimasukan
void menampilkan_seluruh_data(content *ptrpraktikum, int* status, int size, int *ptrjumlahkelompok){
	int i,j;
	content temp;//structure sementara untuk melakukan sorting data kelompok
	//Melakukan sorting dengan metode bubble sort 
	for(i = 1; i <= *ptrjumlahkelompok ; i++){
		for(j = 1;j <= *ptrjumlahkelompok - 1; j++){
			if(strcmp(ptrpraktikum[j].nomerkelompok,ptrpraktikum[j+1].nomerkelompok)==1){//Jika data belum urut
				temp = ptrpraktikum[j];
				ptrpraktikum[j] = ptrpraktikum[j+1];
				ptrpraktikum[j+1] = temp;
			}
		}
	}
	system("cls");
	title(status,10);
	printf("Seluruh data kelompok yang telah disimpan dalam program! (telah diurutkan berdasarkan nomer kelompok)\n\n");
	if(*ptrjumlahkelompok == 0){//Jika belum ada data dalam program
		printf("Tidak ada data yang tersimpan dalam program!\n\nKembali ke menu utama...");
		system("PAUSE");
	}
	else{//Jika ada data kelompok dalam program
		printf("DATA :\n\n");
		for(i = 1; i <= *ptrjumlahkelompok; i++){//yang ditampilkan hanya nomer kelompok dan anggota-anggotanya
			printf("Nomer Kelompok : %s\n\n\t",ptrpraktikum[i].nomerkelompok);
			printf("Nama Anggota 1 : %s\n\n\t",ptrpraktikum[i].namaanggota1);
			printf("Nama Anggota 2 : %s\n\n\n",ptrpraktikum[i].namaanggota2);
		}
		printf("Kembali ke menu utama...\n\n");
		system("PAUSE");
	}
	return;
}
