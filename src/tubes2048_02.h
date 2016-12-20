/* Nomor Kelompok : 02 */
/* Nama file : tubes2048_02.h*/
/* Deskripsi : header */


#ifndef list_H
#define list_H
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


/*Konstanta*/
#define Nil NULL

/*Selektor*/
#define Position(P) (P)->position
#define Info(P) (P)->info
#define Right(P) (P)->right
#define First(L) ((L).First)
#define Left(P) (P)->left
#define Up(P) (P)->up
#define Down(P) (P)->down

// Untuk Kotak
#define BROWN BACKGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY
#define YELLOW BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY
#define PURPLE BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY
#define GREEN BACKGROUND_GREEN|BACKGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY
#define BLUE BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY
#define TEXTBLUE FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY
#define TEXTPURPLE FOREGROUND_RED|FOREGROUND_BLUE
#define TEXTYELLOW FOREGROUND_GREEN|FOREGROUND_RED

/*Konstanta*/
typedef int infotype;
typedef int id;
typedef int coordinate;
typedef struct tElmtList *address;
typedef struct tElmtList {
    coordinate position;
    infotype info;
    address right;
    address left;
    address up;
    address down;
} ElmtList;
typedef struct {
    address First;
}List;

typedef struct
    {
        int TI[20]; //memori tempat penyimpan elemen
        int Neff; //banyaknya elemen efektif
    } TabInt;

/*FUNGSI & PROSEDUR*/

void InitList (List *L);
/*Melakukan inisialisasi list*/

void CreateBoard (List *L1, List *L2, List *L3, List *L4);
/*Menginisialisai papan permainan (linked list)*/

void CetakList (List L);
/*I.S list sudah terdefinisi
F.S mencetak hasil list ke layar */

address Alokasi (int i);
/*Mengalokasi list, diinisialisasi dengan info bernilai 0*/

void Gabung (List *L1, List *L2);
/*Menggabungkan antara list1 dengan list2*/

void MoveUp (List L1, List L2, List L3, List L4, int *scoreUp);
/*melakukan pergerakan ke atas*/

void MoveDown (List L1, List L2, List L3, List L4, int *scoreDown);
/*melakukan pergerakan ke bawah*/

void MoveLeft (List L1, List L2, List L3, List L4,int *scoreLeft);
/*melakukan pergerakan ke atas*/

void MoveRight (List L1, List L2, List L3, List L4, int *scoreRight);
/*melakukan pergerakan ke bawah*/

int AngkaRandom ();
/*memunculkan angka random*/

bool isZero(address P);
/*memeriksa apakah kotak kosong atau bukan, jika kosong akan ditambahkan angka random*/

void ListtoArray (List L1, List L2, List L3, List L4, TabInt *T);
/*mengubah list menjadi array*/

address InttoAddress (List L1, List L2, List L3, List L4, int a);
/*menghasilkan address dari list*/

void EmptyAddress (List L1, List L2, List L3, List L4, TabInt *T);
/*menghasilkan address yang info nya kosong*/

address RandomEmptyAddress (List L1, List L2, List L3, List L4);
/*menghasilkan angka random pada address yang info nya kosong*/

void AddRandom (List L1,List L2,List L3,List L4);
/*menambahkan angka random*/

bool CanMoveUp (List L1, List L2, List L3, List L4);
/*pengecekan kondisi apakah bisa bergerak ke atas atau tidak*/

bool CanMoveDown (List L1, List L2, List L3, List L4);
/*pengecekan kondisi apakah bisa bergerak ke bawah atau tidak*/

bool CanMoveRight (List L1, List L2, List L3, List L4);
/*pengecekan kondisi apakah bisa bergerak ke kanan atau tidak*/

bool CanMoveLeft (List L1, List L2, List L3, List L4);
/*pengecekan kondisi apakah bisa bergerak ke kiri atau tidak*/

void ArraytoList (List *L1, List *L2, List *L3, List *L4, TabInt T);
/*mengubah array menjadi list*/

bool isFull (List L1, List L2, List L3, List L4);
/*mengecek apakah List sudah penuh terisi atau belum*/

bool Kalah (List L1, List L2, List L3, List L4);
/*pengecekan kondisi kalah*/

int Max (List L1, List L2, List L3, List L4);
/*menghitung isi elemen list terbesar*/

bool Menang (int currentmax);
/*pengecekan kondisi menang*/

void SaveScore (int scoreTotal);
/*menyimpan score ke file eksternal dan menampilkan 10 score terbesar*/

void setcolor2 ();
/*untuk setting warna*/

void setcolor0 ();
/*untuk setting warna*/

void setcolor4 ();
/*untuk setting warna*/

void setcolor8 ();
/*untuk setting warna*/

void awal();
/*menampilkan interface*/

void highscore();
/*menghitung score tertinggi*/

void gotoxy();
/*setting tampilan pada layar*/

void SaveLastGrid();
/*menyimpan move dan score ke file eksternal (untuk load game)*/

void SaveLastGrid1();
/*menyimpan move dan score untuk undo ke file eksternal*/

void LoadLastGrid();
/*mengload game*/

void LoadLastGrid1();
/*untuk undo */

void setColor(int color);
/*untuk setting warna*/

void setcolor(unsigned short color);
/*untuk setting warna*/

void OptionKey();
/*menampilkan option key pada layar */

void game();
/*permainan utama 2048*/

void load();
/*permainan utama 2048 setelah melakukan load, jika kondisi kalah, game tidak dapat di load lagi*/

#endif
