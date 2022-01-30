#include <stdio.h> ///untuk fungsi input output like printf, scanf
#include <stdlib.h>
#include <conio.h>
#include <windows.h> ///biar windows bisa dimanfaatin (b aja)
#include <string.h>  ///operasi string

/** untuk atur variable global */
COORD coord = {0,0}; /// di kiri paling susdut

/**
    fungsi : gotoxy
    @param input: untuk kordinat x dan y seperti di diagram cartesius
    @param output: kasih pindah cursor ke arah spesifik
*/

void keluar(){
    system("cls");
    system ("color 03");
printf("\n\t\t\t\t\t Selamat tinggal user admin\n");
system("pause");


	exit(0);	
system("cls");
}

void
my_wait(size_t secs)
{
	#ifdef _WIN32
		Sleep(1000 * secs);
	#else
		sleep(secs);
	#endif
}

void
print_progress(size_t count, size_t max)
{
	system("color 02");
	const char prefix[] = "Menghubungkan.";
	const char suffix[] = "";
	const size_t prefix_length = sizeof(prefix) - 1;
	const size_t suffix_length = sizeof(suffix) - 1;
	char *buffer = calloc(max + prefix_length + suffix_length + 1, 1); // +1 for \0
	size_t i = 0;

	strcpy(buffer, prefix);
	for (; i < max; ++i)
	{
		buffer[prefix_length + i] = i < count ? '.' : ' ';
	}

	strcpy(&buffer[prefix_length + i], suffix);
	printf("\b%c[2K\r%s\n", 27, buffer);
	fflush(stdout);
	free(buffer);
  //system("cls");
}

#define NUM_SECS 10

void gotoxy(int x,int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

/** fungsi main */

int main()
{
    system("color 03");
	
	FILE *fp, *ft; /// file pointers
    char another, choice;

    /** structure mahasiswa */
    struct mahasiswa
    {
        char nama[40],kode[40]; ///nama
        int umur; /// umur
        int nim; /// nim
        char fakultas[20]; /// fakultas
    };

    struct mahasiswa e; /// kreasi struktur variabel

    char kode[40]; /// string untuk simpan nama mahasiswa

    long int ukurdat; /// ukuran data setiap mahasiswa

    /** open the file in binary read and write mode
    * if the file EMP.DAT already exists then it open that file in read write mode
    * if the file doesn't exit it simply create a new copy
    */
    fp = fopen("mahasiswa.DAT","rb+");
    if(fp == NULL)
    {
        fp = fopen("mahasiswa.DAT","wb+");
        if(fp == NULL)
        {
            printf("error");
            exit(1);
        }
    }

    /// ukuran tiap data
    ukurdat = sizeof(e);

    /// loopnya jalan terus sampe ada break statement
        char studentID[]="admin", password[]="admin", id[20], p[20];
    int n=1, x, y;







     printf("\n\t\t\t\t\t*tolong masukan username dan password UwU* ");
     // system("cls");
    do
    {
        printf("\n\n Username :");
        scanf("%s", id);

        printf("\n\n Password :");
        scanf("%s", p);




      x=strcmp(id, studentID);
      y=strcmp(p, password);
          system("cls");

    size_t num_secs = 2, max_secs = NUM_SECS;
	printf("%s\n", "");
	print_progress(0, max_secs);
	for (; num_secs <= max_secs; ++num_secs)
	{

		my_wait(1);
		print_progress(num_secs, max_secs);

	}
    system("clear");




  if(x==0 && y==0){
     
        break;
      }else {
        printf("\n\n\t\t\t\t\t .....sandi salah..... ");
            getchar();
            n++;}
            system("pause");
            system("clear");

        if(n>5){
          printf("\n\t\t\t\t\t keknya anda bukan admin maaf \n");
          printf("\n\t\t\t\t\t tekan enter untuk keluar......");
          getchar();
          exit(0);
          }
    system("clear");
     }
     
      while(n<=5);
    while(1)
    {
    	
        system("cls"); 
        system("color 86");
		printf("\nOnline.....\n");
        printf("\n\n\t\t\t\t  Hallo Admin\n");
        printf("\n\t\t\t  ==================================\n");
		gotoxy(30,10); 
        printf("1. registrasi mahasiswa "); 
        gotoxy(30,12);
        printf("2. daftar mahasiswa "); 
        gotoxy(30,14);
        printf("3. update data mahasiswa"); 
        gotoxy(30,16);
        printf("4. hapus data mahasiswa"); 
        gotoxy(30,18);
        printf("5. keluar"); 
        gotoxy(30,20);
        printf("masukan pilihan anda: "); 
        fflush(stdin); ///flush biar gak terjadi memory buffering
        choice  = getche(); 
        switch(choice)
        {
        case '1':  
            system("cls");
            fseek(fp,0,SEEK_END); 
            another = 'y';
            while(another == 'y') 
            {
            	system ("color 06");
                printf("\nkode mahasiswa: ");
                scanf("%s",e.kode);
                printf("\nnama mahasiswa: ");
                scanf("%s",e.nama);
                printf("\numur mahasiswa: ");
                scanf("%d", &e.umur);
                printf("\nnim mahasiswa: ");
                scanf("%d", &e.nim);
                printf("\nnama fakultas: ");
                scanf("%s", e.fakultas);

                fwrite(&e,ukurdat,1,fp); 

                printf("\ningin meregistrasi mahasiswa lagi? (y/n) ");
                fflush(stdin);
               another = getche();
            }
            break;
        case '2':
            system("cls");
            printf("KODE\t|NAMA\t|UMUR\t|NIM\t\t|FAKULTAS\n");
     		printf("---------------------------------------------------------\n");
            rewind(fp); //arahin kursor ke paling awal
            while(fread(&e,ukurdat,1,fp)==1)  /// membaca file yg tersimpan dan kasih keluar satu"
            {
                printf("%s\t|%s\t|%d\t|%d\t|%s\t\n",e.kode,e.nama,e.umur,e.nim,e.fakultas); 
            }
            getch();
            break;

        case '3': 
            system("cls");
            another = 'y';
            while(another == 'y')
            {
                printf("masukan kode mahasiswa yang ingin di edit: ");
                scanf("%s", kode);
                rewind(fp);
                while(fread(&e,ukurdat,1,fp)==1)  /// ambil semua data dari file
                {
                    if(strcmp(e.nama,kode) == 0)  ///cek kalo data yg di input sama dengan file
                    {
                        printf("\nmasukan kode baru,nama , umur, nim, fakultas : ");
                        scanf("%s%s%d%d%s",e.kode,e.nama,&e.umur,&e.nim,e.fakultas);
                        fseek(fp,-ukurdat,SEEK_CUR); /// turun 1 langkah dari kursor awal
                        fwrite(&e,ukurdat,1,fp); /// tulis ulang data
                        break;
                    }
                }
                printf("\napakah anda ingin mengedit data lain?(y/n)");
                fflush(stdin);
               another = getche();
            }
            break;
        case '4':
            system("cls");
            another = 'y';
            while(another == 'y')
            {
                printf("\nmasukan kode mahasiswa yang ingin di hapus: ");
                scanf("%s",kode);
                ft = fopen("Temp.dat","wb");  /// buat penyimpanan sementara
                rewind(fp); /// memindahkan data ke paling awal
                while(fread(&e,ukurdat,1,fp) == 1)  /// scan ulang semua data
                {
                    if(strcmp(e.nama,kode) != 0)  /// kalo data yg di kasih masuk sama
                    {
                        fwrite(&e,ukurdat,1,ft); /// semua file di kasih pindah kecuali data yg di cari
                    }
                }
                fclose(fp);
                fclose(ft);
                remove("mahasiswa.DAT"); /// hapus file original
                rename("Temp.dat","mahasiswa.DAT"); /// ganti ulang file dari sementara ke original
                fp = fopen("mahasiswa.DAT", "rb+");
                printf("apakah anda ingin menghapus data lagi ? (y/n)");
                fflush(stdin);
                another = getche();
            }
            break;
        case '5':keluar();
        remove("mahasiswa.DAT");
fclose(fp);
        break;
        	
        }
    }
    return 0;
}