/* Nomor Kelompok : 02 */
/* Nama file : tubes2048_02.c*/
/* Deskripsi : realisasi fungsi dan procedure */

#include "tubes2048_02.h"


/* ********** DEFINISI PROTOTIPE PRIMITIF ***********/

void InitList (List *L)
/*Melakukan inisialisasi list*/
{
    First(*L)=Nil;
}

address Alokasi (int i)
/*Mengalokasi list, diinisialisasi dengan info bernilai 0*/
{
	/*ALGORITMA*/
	address P = (address) malloc (sizeof(ElmtList));
	if (P != Nil) {
		Info(P) = 0 ;
		Position(P) = i;
		Right(P) = Nil;
		Left(P) =Nil;
		Up(P)=Nil;
		Down(P)=Nil;
	}
	return P;
}

void Gabung (List *L1, List *L2)
/*Menggabungkan antara list1 dengan list2*/
{
    address P1,P2;
    /*ALGORITMA*/
    P1=First(*L1);
    P2=First(*L2);
    Down(P1)=P2;
    Up(P2)=P1;
    do {
        Down(Right(P1))=Right(P2);
        Up(Right(P2))=Right(P1);
        P1=Right(P1);
        P2=Right(P2);
    } while (Right(P1)!=Nil);
}

void CreateBoard (List *L1, List *L2, List *L3, List *L4)
/*Menginisialisai papan permainan (linked list)*/
{
    address Prev,Next;

    /*ALGORITMA*/
    InitList(&(*L1));
    InitList(&(*L2));
    InitList(&(*L3));
    InitList(&(*L4));
    int i=1;
    do {
        Next=Alokasi(i);
        if (i==1){
            First(*L1)=Next;
            Prev=First(*L1);}
        else{ if (i==5)
        {
            Right(Prev)=Nil;
        }
        else
        {
            Right(Prev)=Next;
            Left(Next)=Prev;
            Prev=Right(Prev);
        }
        }
        i++;
    } while (i<=5);
    i=5;
    do {
        Next=Alokasi(i);
        if (i==5){
            First(*L2)=Next;
            Prev=First(*L2);}
        else{ if (i==9)
        {
            Right(Prev)=Nil;
        }
        else
        {
            Right(Prev)=Next;
            Left(Next)=Prev;
            Prev=Right(Prev);
        }
        }
        i++;
    } while (i<=9);
    i=9;
    do {
        Next=Alokasi(i);
        if (i==9){
            First(*L3)=Next;
            Prev=First(*L3);}
        else{ if (i==13)
        {
            Right(Prev)=Nil;
        }
        else
        {
            Right(Prev)=Next;
            Left(Next)=Prev;
            Prev=Right(Prev);
        }
        }
        i++;
    } while (i<=13);
    i=13;
    do {
        Next=Alokasi(i);
        if (i==13){
            First(*L4)=Next;
            Prev=First(*L4);}
        else{ if (i==17)
        {
            Right(Prev)=Nil;
        }
        else
        {
            Right(Prev)=Next;
            Left(Next)=Prev;
            Prev=Right(Prev);
        }
        }
        i++;
    } while (i<=17);
    Gabung(&(*L1),&(*L2));
    Gabung(&(*L2),&(*L3));
    Gabung(&(*L3),&(*L4));
}

void CetakList (List L)
/*I.S list sudah terdefinisi
F.S mencetak hasil list ke layar */
{
	/*KAMUS LOKAL*/
	address P;
	/*ALGORITMA*/
	system("Color 73");
	P = First(L);
	printf("            ");
	printf(" ");
	printf("   ");
	if (P != Nil) {
        if (Info(P)==0) {
            printf(" ");
        }
        else {
		printf("%d", Info(P));
        }
		do {
			printf ("   ");
			printf("|");
			printf("   ");
			P = Right(P);
			if (Info(P)==0) {
                printf(" ");
			}
			else {
			printf("%d", Info(P));
			}
		} while (Right(P) != Nil);
	}
	printf ("   ");
	printf(" \n");
    printf("            ");
	printf("=================================");
}

void MoveUp (List L1, List L2, List L3, List L4, int *scoreUp)
/*melakukan pergerakan ke atas*/
{
    address p1,p2,p3,p4;
    int a1=0,a2=0,a3=0,a4=0,a5=0,a6=0,a7=0,a8=0,a9=0,a10=0;
    int a11=0,a12=0,a13=0,a14=0,a15=0,a16=0,a17=0,a18=0,a19=0,a20=0;
    int s=0;

    p1=First(L1);
    p2=First(L2);
    p3=First(L3);
    p4=First(L4);


    if (CanMoveUp(L1,L2,L3,L4)==true) {

        while (((p1)!=Nil)&&((p2)!=Nil)&&((p3)!=Nil)&&((p4)!=Nil))
        {

            if ((Info(p4)!=0)&&(Info(p1)==0)&&(Info(p2)==0)&&(Info(p3)==0)) {
                Info(p1)=Info(p4);
                Info(p4)=0;
            }
            else if ((Info(p4)==0)&&(Info(p1)==0)&&(Info(p2)==0)&&(Info(p3)!=0)) {
                Info(p1)=Info(p3);
                Info(p3)=0;
            }
            else if ((Info(p4)==0)&&(Info(p1)==0)&&(Info(p2)!=0)&&(Info(p3)==0)) {
                Info(p1)=Info(p2);
                Info(p2)=0;
            }

            //Ada 2 elemen, kotak 1 selalu ada isi


            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)==0)&&(Info(p4)==0)&&(Info(p1)==Info(p2))) { //Kalo sama
                Info(p1)=Info(p1)*2;
                Info(p2)=0;
                a1+=Info(p1);
            }
            else if ((Info(p1)!=0)&&(Info(p2)==0)&&(Info(p3)!=0)&&(Info(p4)==0)&&(Info(p1)==Info(p3))) { //Kalo sama
                Info(p1)=Info(p1)*2;
                Info(p3)=0;
                a2+=Info(p1);
            }
            else if ((Info(p1)!=0)&&(Info(p2)==0)&&(Info(p3)!=0)&&(Info(p4)==0)&&(Info(p1)!=Info(p3))) { //Kalo beda
                Info(p2)=Info(p3);
                Info(p3)=0;
            }
            else if ((Info(p1)!=0)&&(Info(p2)==0)&&(Info(p3)==0)&&(Info(p4)!=0)&&(Info(p1)==Info(p4))) { //Kalo sama
                Info(p1)=Info(p1)*2;
                Info(p4)=0;
                a3+=Info(p1);
            }
             else if ((Info(p1)!=0)&&(Info(p2)==0)&&(Info(p3)==0)&&(Info(p4)!=0)&&(Info(p1)!=Info(p4))) { //Kalo sama
                Info(p2)=Info(p4);
                Info(p4)=0;
            }

            //Kotak ke-2 selalu ada isi
            else if ((Info(p1)==0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)==0)&&(Info(p3)==Info(p2))) { //Kalo sama
                Info(p1)=Info(p2)*2;
                Info(p2)=0;
                Info(p3)=0;
                a5+=Info(p1);
            }
             else if ((Info(p1)==0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)==0)&&(Info(p3)!=Info(p2))) { //Kalo beda
                Info(p1)=Info(p2);
                Info(p2)=Info(p3);
                Info(p3)=0;
            }
            else if ((Info(p1)==0)&&(Info(p2)!=0)&&(Info(p3)==0)&&(Info(p4)!=0)&&(Info(p4)==Info(p2))) { //Kalo sama
                Info(p1)=Info(p2)*2;
                Info(p2)=0;
                Info(p4)=0;
                a6+=Info(p1);
            }
            else if ((Info(p1)==0)&&(Info(p2)!=0)&&(Info(p3)==0)&&(Info(p4)!=0)&&(Info(p4)!=Info(p2))) { //Kalo beda
                Info(p1)=Info(p2);
                Info(p2)=Info(p4);
                Info(p4)=0;
            }
            //Kalo kotak 3 pasti ada isi
             else if ((Info(p1)==0)&&(Info(p2)==0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p4)==Info(p3))) { //Kalo sama
                Info(p1)=Info(p3)*2;
                Info(p3)=0;
                Info(p4)=0;
                a7+=Info(p1);
            }
            else if ((Info(p1)==0)&&(Info(p2)==0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p4)!=Info(p3))) { //Kalo beda
                Info(p1)=Info(p3);
                Info(p2)=Info(p4);
                Info(p3)=0;
                Info(p4)=0;
            }

            //Kalo ada 3 elemen, kotak 4 kosong

             else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)==0)&&(Info(p1)==Info(p2))) { //Kalo p1=p2
                Info(p1)=Info(p1)*2;
                Info(p2)=Info(p3);
                Info(p3)=0;
                Info(p4)=0;
                a8+=Info(p1);
            }
            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)==0)&&(Info(p2)==Info(p3))) { //Kalo p2=p3
                Info(p1)=Info(p1);
                Info(p2)=Info(p2)*2;
                Info(p3)=0;
                Info(p4)=0;
                a9+=Info(p2);
            }

            //Kalo ada 3 elemen, kotak 1 kosong
            else if ((Info(p1)==0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p2)!=Info(p3))&&(Info(p3)!=Info(p4))) { //Kalo p2=p3
                Info(p1)=Info(p2);
                Info(p2)=Info(p3);
                Info(p3)=Info(p4);
                Info(p4)=0;
            }
            else if ((Info(p1)==0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p2)==Info(p3))) { //Kalo p2=p3
                Info(p1)=Info(p2)*2;
                Info(p2)=Info(p4);
                Info(p3)=0;
                Info(p4)=0;
                a10+=Info(p1);
            }
            else if ((Info(p1)==0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p3)==Info(p4))) { //Kalo p3=p4
                Info(p1)=Info(p2);
                Info(p2)=Info(p3)*2;
                Info(p3)=0;
                Info(p4)=0;
                a11+=Info(p2);
            }

            //3 elemen, Kotak 2 kosong
            else if ((Info(p1)!=0)&&(Info(p2)==0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p3)==Info(p1))) {
                Info(p1)=Info(p1)*2;
                Info(p2)=Info(p4);
                Info(p3)=0;
                Info(p4)=0;
                a12+=Info(p1);
            }
            else if ((Info(p1)!=0)&&(Info(p2)==0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p3)!=Info(p1))&&(Info(p3)==Info(p4))) {
                Info(p1)=Info(p1);
                Info(p2)=Info(p3)*2;
                Info(p3)=0;
                Info(p4)=0;
                a13+=Info(p2);
            }
            else if ((Info(p1)!=0)&&(Info(p2)==0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p3)!=Info(p1))&&(Info(p3)!=Info(p4))) {
                Info(p1)=Info(p1);
                Info(p2)=Info(p3);
                Info(p3)=Info(p4);
                Info(p4)=0;

            }

            //3 elemen, kotak 3 kosong
            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)==0)&&(Info(p4)!=0)&&(Info(p1)==Info(p2))) {
                Info(p1)=Info(p1)*2;
                Info(p2)=Info(p4);
                Info(p3)=0;
                Info(p4)=0;
                a14+=Info(p1);
            }
            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)==0)&&(Info(p4)!=0)&&(Info(p1)!=Info(p2))&&(Info(p2)==Info(p4))) {
                Info(p1)=Info(p1);
                Info(p2)=Info(p2)*2;
                Info(p3)=0;
                Info(p4)=0;
                a15+=Info(p2);
            }
            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)==0)&&(Info(p4)!=0)&&(Info(p1)!=Info(p2))&&(Info(p2)!=Info(p4))) {
                Info(p1)=Info(p1);
                Info(p2)=Info(p2);
                Info(p3)=Info(p4);
                Info(p4)=0;
            }


            //Kalo 4 elemen
            //Kalo sama semua
            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p1)==Info(p2))&&(Info(p3)==Info(p4))) {
                Info(p1)=Info(p1)*2;
                Info(p2)=Info(p3)*2;
                Info(p3)=0;
                Info(p4)=0;
                a16+=Info(p1);
                a17+=Info(p2);
                s+=a16+a17;
            }
            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p1)==Info(p2))&&(Info(p3)!=Info(p4))) {
                Info(p1)=Info(p1)*2;
                Info(p2)=Info(p3);
                Info(p3)=Info(p4);
                Info(p4)=0;
                a18+=Info(p1);
            }
            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p1)!=Info(p2))&&(Info(p3)==Info(p4))&&(Info(p2)!=Info(p3))) {
                Info(p1)=Info(p1);
                Info(p2)=Info(p2);
                Info(p3)=Info(p3)*2;
                Info(p4)=0;
                a19+=Info(p3);
            }
            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p1)!=Info(p2))&&(Info(p2)==Info(p3))) {
                Info(p1)=Info(p1);
                Info(p2)=Info(p2)*2;
                Info(p3)=Info(p4);
                Info(p4)=0;
                a20+=Info(p2);
            }

       // (*scoreUp)=(a1+a2+a3+a4+a5+a6+a7+a8+a9+a10+a11+a12+a13+a14+a15+s+a18+a19+a20);

        p1=Right(p1);
        p2=Right(p2);
        p3=Right(p3);
        p4=Right(p4);


        }

        (*scoreUp)+=a1+a2+a3+a4+a5+a6+a7+a8+a9+a10+a11+a12+a13+a14+a15+s+a18+a19+a20;

        AddRandom(L1,L2,L3,L4);

        CetakList(L1);
        printf("\n");
        CetakList(L2);
        printf("\n");
        CetakList(L3);
        printf("\n");
        CetakList(L4);
        printf("\n");
    }
    else {
        CetakList(L1);
        printf("\n");
        CetakList(L2);
        printf("\n");
        CetakList(L3);
        printf("\n");
        CetakList(L4);
        printf("\n");
    }
}

void MoveDown (List L1, List L2, List L3, List L4, int *scoreDown)
/*melakukan pergerakan ke bawah*/
{
    address p1,p2,p3,p4;
    int a1=0,a2=0,a3=0,a4=0,a5=0,a6=0,a7=0,a8=0,a9=0,a10=0;
    int a11=0,a12=0,a13=0,a14=0,a15=0,a16=0,a17=0,a18=0,a19=0;
    int s=0;

    p1=First(L1);
    p2=First(L2);
    p3=First(L3);
    p4=First(L4);

    if (CanMoveDown(L1,L2,L3,L4))
    {

        while (((p1)!=Nil)&&((p2)!=Nil)&&((p3)!=Nil)&&((p4)!=Nil))
        {

            if ((Info(p4)==0)&&(Info(p1)!=0)&&(Info(p2)==0)&&(Info(p3)==0)) {
                Info(p4)=Info(p1);
                Info(p1)=0;
            }
            else if ((Info(p4)==0)&&(Info(p1)==0)&&(Info(p2)!=0)&&(Info(p3)==0)) {
                Info(p4)=Info(p2);
                Info(p2)=0;
            }
            else if ((Info(p4)==0)&&(Info(p1)==0)&&(Info(p2)==0)&&(Info(p3)!=0)) {
                Info(p4)=Info(p3);
                Info(p3)=0;
            }

            //Ada 2 elemen, kotak 4 selalu ada isi


            else if ((Info(p1)==0)&&(Info(p2)==0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p4)==Info(p3))) { //Kalo sama
                Info(p4)=Info(p4)*2;
                Info(p3)=0;
                a1+=Info(p4);
            }
            else if ((Info(p1)==0)&&(Info(p2)!=0)&&(Info(p3)==0)&&(Info(p4)!=0)&&(Info(p4)==Info(p2))) { //Kalo sama
                Info(p4)=Info(p4)*2;
                Info(p2)=0;
                a2+=Info(p4);
            }
            else if ((Info(p1)==0)&&(Info(p2)!=0)&&(Info(p3)==0)&&(Info(p4)!=0)&&(Info(p4)!=Info(p2))) { //Kalo beda
                Info(p3)=Info(p2);
                Info(p2)=0;
            }
            else if ((Info(p1)!=0)&&(Info(p2)==0)&&(Info(p3)==0)&&(Info(p4)!=0)&&(Info(p1)==Info(p4))) { //Kalo sama
                Info(p4)=Info(p4)*2;
                Info(p1)=0;
                a3+=Info(p4);
            }
             else if ((Info(p1)!=0)&&(Info(p2)==0)&&(Info(p3)==0)&&(Info(p4)!=0)&&(Info(p1)!=Info(p4))) { //Kalo sama
                Info(p3)=Info(p1);
                Info(p1)=0;
            }

            //Kotak ke-3 selalu ada isi
            else if ((Info(p1)==0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)==0)&&(Info(p3)==Info(p2))) { //Kalo sama
                Info(p4)=Info(p3)*2;
                Info(p2)=0;
                Info(p3)=0;
                a4+=Info(p4);
            }
             else if ((Info(p1)==0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)==0)&&(Info(p3)!=Info(p2))) { //Kalo beda
                Info(p4)=Info(p3);
                Info(p3)=Info(p2);
                Info(p2)=0;
            }
            else if ((Info(p1)!=0)&&(Info(p2)==0)&&(Info(p3)!=0)&&(Info(p4)==0)&&(Info(p3)==Info(p1))) { //Kalo sama
                Info(p4)=Info(p3)*2;
                Info(p3)=0;
                Info(p1)=0;
                a5+=Info(p4);
            }
            else if ((Info(p1)!=0)&&(Info(p2)==0)&&(Info(p3)!=0)&&(Info(p4)==0)&&(Info(p3)!=Info(p1))) { //Kalo beda
                Info(p4)=Info(p3);
                Info(p3)=Info(p1);
                Info(p1)=0;
            }
            //Kalo kotak 2 pasti ada isi
             else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)==0)&&(Info(p4)==0)&&(Info(p1)==Info(p2))) { //Kalo sama
                Info(p4)=Info(p2)*2;
                Info(p2)=0;
                Info(p1)=0;
                a6+=Info(p4);
            }
            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)==0)&&(Info(p4)==0)&&(Info(p1)!=Info(p2))) { //Kalo beda
                Info(p4)=Info(p2);
                Info(p3)=Info(p1);
                Info(p2)=0;
                Info(p1)=0;
            }

            //Kalo ada 3 elemen, kotak 1 kosong

             else if ((Info(p1)==0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p3)==Info(p4))) { //Kalo p1=p2
                Info(p4)=Info(p4)*2;
                Info(p3)=Info(p2);
                Info(p2)=0;
                Info(p1)=0;
                a7+=Info(p4);
            }
            else if ((Info(p1)==0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p2)==Info(p3))) { //Kalo p2=p3
                Info(p4)=Info(p4);
                Info(p3)=Info(p3)*2;
                Info(p2)=0;
                Info(p1)=0;
                a8+=Info(p3);
            }

            //Kalo ada 3 elemen, kotak 4 kosong

            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)==0)&&(Info(p2)==Info(p3))) { //Kalo p2=p3
                Info(p4)=Info(p3)*2;
                Info(p3)=Info(p1);
                Info(p2)=0;
                Info(p1)=0;
                a9+=Info(p4);
            }
            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)==0)&&(Info(p2)==Info(p1))) { //Kalo p3=p4
                Info(p4)=Info(p3);
                Info(p3)=Info(p2)*2;
                Info(p2)=0;
                Info(p1)=0;
                a10+=Info(p3);
            }
            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)==0)&&(Info(p2)!=Info(p1))&&(Info(p2)!=Info(p3))) { //Kalo p3=p4
                Info(p4)=Info(p3);
                Info(p3)=Info(p2);
                Info(p2)=Info(p1);
                Info(p1)=0;
            }

            //3 elemen, Kotak 3 kosong
            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)==0)&&(Info(p4)!=0)&&(Info(p4)==Info(p2))) {
                Info(p4)=Info(p4)*2;
                Info(p3)=Info(p1);
                Info(p2)=0;
                Info(p1)=0;
                a11+=Info(p4);
            }
            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)==0)&&(Info(p4)!=0)&&(Info(p4)!=Info(p2))&&(Info(p2)==Info(p1))) {
                Info(p4)=Info(p4);
                Info(p3)=Info(p2)*2;
                Info(p2)=0;
                Info(p1)=0;
                a12+=Info(p3);
            }
            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)==0)&&(Info(p4)!=0)&&(Info(p4)!=Info(p2))&&(Info(p2)!=Info(p1))) {
                Info(p4)=Info(p4);
                Info(p3)=Info(p2);
                Info(p2)=Info(p1);
                Info(p1)=0;
            }

            //3 elemen, kotak 2 kosong
            else if ((Info(p1)!=0)&&(Info(p2)==0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p4)==Info(p3))) {
                Info(p4)=Info(p4)*2;
                Info(p3)=Info(p1);
                Info(p2)=0;
                Info(p1)=0;
                a13+=Info(p4);
            }
            else if ((Info(p1)!=0)&&(Info(p2)==0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p4)!=Info(p3))&&(Info(p3)==Info(p1))) {
                Info(p4)=Info(p4);
                Info(p3)=Info(p3)*2;
                Info(p2)=0;
                Info(p1)=0;
                a14+=Info(p3);
            }
            else if ((Info(p1)!=0)&&(Info(p2)==0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p4)!=Info(p3))&&(Info(p3)!=Info(p1))) {
                Info(p4)=Info(p4);
                Info(p3)=Info(p3);
                Info(p2)=Info(p1);
                Info(p1)=0;
            }

            //Kalo 4 elemen
            //Kalo sama semua
            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p1)==Info(p2))&&(Info(p3)==Info(p4))) {
                Info(p4)=Info(p4)*2;
                Info(p3)=Info(p2)*2;
                Info(p2)=0;
                Info(p1)=0;
                a15+=Info(p4);
                a16+=Info(p3);
                s+=(a15+a16);
            }
            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p4)==Info(p3))&&(Info(p1)!=Info(p2))) {
                Info(p4)=Info(p4)*2;
                Info(p3)=Info(p2);
                Info(p2)=Info(p1);
                Info(p1)=0;
                a17+=Info(p4);
            }
            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p4)!=Info(p3))&&(Info(p1)==Info(p2))&&(Info(p2)!=Info(p3))) {
                Info(p4)=Info(p4);
                Info(p3)=Info(p3);
                Info(p2)=Info(p2)*2;
                Info(p1)=0;
                a18+=Info(p2);
            }
            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p4)!=Info(p3))&&(Info(p3)==Info(p2))) {
                Info(p4)=Info(p4);
                Info(p3)=Info(p3)*2;
                Info(p2)=Info(p1);
                Info(p1)=0;
                a19+=Info(p3);
            }


        p1=Right(p1);
        p2=Right(p2);
        p3=Right(p3);
        p4=Right(p4);

        }

        AddRandom(L1,L2,L3,L4);

        (*scoreDown)+=a1+a2+a3+a4+a5+a6+a7+a8+a9+a10+a11+a12+a13+a14+a15+s+a18+a19;

        CetakList(L1);
        printf("\n");
        CetakList(L2);
        printf("\n");
        CetakList(L3);
        printf("\n");
        CetakList(L4);
        printf("\n");

    }
    else {

        CetakList(L1);
        printf("\n");
        CetakList(L2);
        printf("\n");
        CetakList(L3);
        printf("\n");
        CetakList(L4);
        printf("\n");
    }
}

void MoveLeft (List L1, List L2, List L3, List L4,int *scoreLeft)
/*melakukan pergerakan ke kiri*/
{
    address p1,p2,p3,p4;
    int a1=0,a2=0,a3=0,a5=0,a6=0,a7=0,a8=0,a9=0,a10=0;
    int a11=0,a12=0,a13=0,a14=0,a15=0,a16=0,a17=0,a18=0,a19=0,a20=0;
    int s=0;

    p1=First(L1);
    p2=Right(p1);
    p3=Right(p2);
    p4=Right(p3);

    if (CanMoveLeft(L1,L2,L3,L4))
    {

                while (((p1)!=Nil)&&((p2)!=Nil)&&((p3)!=Nil)&&((p4)!=Nil))
        {

            if ((Info(p4)!=0)&&(Info(p1)==0)&&(Info(p2)==0)&&(Info(p3)==0)) {
                Info(p1)=Info(p4);
                Info(p4)=0;
            }
            else if ((Info(p4)==0)&&(Info(p1)==0)&&(Info(p2)==0)&&(Info(p3)!=0)) {
                Info(p1)=Info(p3);
                Info(p3)=0;
            }
            else if ((Info(p4)==0)&&(Info(p1)==0)&&(Info(p2)!=0)&&(Info(p3)==0)) {
                Info(p1)=Info(p2);
                Info(p2)=0;
            }

            //Ada 2 elemen, kotak 1 selalu ada isi


            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)==0)&&(Info(p4)==0)&&(Info(p1)==Info(p2))) { //Kalo sama
                Info(p1)=Info(p1)*2;
                Info(p2)=0;
                a1+=Info(p1);
            }
            else if ((Info(p1)!=0)&&(Info(p2)==0)&&(Info(p3)!=0)&&(Info(p4)==0)&&(Info(p1)==Info(p3))) { //Kalo sama
                Info(p1)=Info(p1)*2;
                Info(p3)=0;
                a2+=Info(p1);
            }
            else if ((Info(p1)!=0)&&(Info(p2)==0)&&(Info(p3)!=0)&&(Info(p4)==0)&&(Info(p1)!=Info(p3))) { //Kalo beda
                Info(p2)=Info(p3);
                Info(p3)=0;
            }
            else if ((Info(p1)!=0)&&(Info(p2)==0)&&(Info(p3)==0)&&(Info(p4)!=0)&&(Info(p1)==Info(p4))) { //Kalo sama
                Info(p1)=Info(p1)*2;
                Info(p4)=0;
                a3+=Info(p1);
            }
             else if ((Info(p1)!=0)&&(Info(p2)==0)&&(Info(p3)==0)&&(Info(p4)!=0)&&(Info(p1)!=Info(p4))) { //Kalo sama
                Info(p2)=Info(p4);
                Info(p4)=0;
            }

            //Kotak ke-2 selalu ada isi
            else if ((Info(p1)==0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)==0)&&(Info(p3)==Info(p2))) { //Kalo sama
                Info(p1)=Info(p2)*2;
                Info(p2)=0;
                Info(p3)=0;
                a5+=Info(p1);
            }
             else if ((Info(p1)==0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)==0)&&(Info(p3)!=Info(p2))) { //Kalo beda
                Info(p1)=Info(p2);
                Info(p2)=Info(p3);
                Info(p3)=0;
            }
            else if ((Info(p1)==0)&&(Info(p2)!=0)&&(Info(p3)==0)&&(Info(p4)!=0)&&(Info(p4)==Info(p2))) { //Kalo sama
                Info(p1)=Info(p2)*2;
                Info(p2)=0;
                Info(p4)=0;
                a6+=Info(p1);
            }
            else if ((Info(p1)==0)&&(Info(p2)!=0)&&(Info(p3)==0)&&(Info(p4)!=0)&&(Info(p4)!=Info(p2))) { //Kalo beda
                Info(p1)=Info(p2);
                Info(p2)=Info(p4);
                Info(p4)=0;
            }
            //Kalo kotak 3 pasti ada isi
             else if ((Info(p1)==0)&&(Info(p2)==0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p4)==Info(p3))) { //Kalo sama
                Info(p1)=Info(p3)*2;
                Info(p3)=0;
                Info(p4)=0;
                a7+=Info(p1);
            }
            else if ((Info(p1)==0)&&(Info(p2)==0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p4)!=Info(p3))) { //Kalo beda
                Info(p1)=Info(p3);
                Info(p2)=Info(p4);
                Info(p3)=0;
                Info(p4)=0;
            }

            //Kalo ada 3 elemen, kotak 4 kosong

             else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)==0)&&(Info(p1)==Info(p2))) { //Kalo p1=p2
                Info(p1)=Info(p1)*2;
                Info(p2)=Info(p3);
                Info(p3)=0;
                Info(p4)=0;
                a8+=Info(p1);
            }
            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)==0)&&(Info(p2)==Info(p3))) { //Kalo p2=p3
                Info(p1)=Info(p1);
                Info(p2)=Info(p2)*2;
                Info(p3)=0;
                Info(p4)=0;
                a9+=Info(p2);
            }

            //Kalo ada 3 elemen, kotak 1 kosong
            else if ((Info(p1)==0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p2)!=Info(p3))&&(Info(p3)!=Info(p4))) { //Kalo p2=p3
                Info(p1)=Info(p2);
                Info(p2)=Info(p3);
                Info(p3)=Info(p4);
                Info(p4)=0;
            }
            else if ((Info(p1)==0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p2)==Info(p3))) { //Kalo p2=p3
                Info(p1)=Info(p2)*2;
                Info(p2)=Info(p4);
                Info(p3)=0;
                Info(p4)=0;
                a10+=Info(p1);
            }
            else if ((Info(p1)==0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p3)==Info(p4))) { //Kalo p3=p4
                Info(p1)=Info(p2);
                Info(p2)=Info(p3)*2;
                Info(p3)=0;
                Info(p4)=0;
                a11+=Info(p2);
            }

            //3 elemen, Kotak 2 kosong
            else if ((Info(p1)!=0)&&(Info(p2)==0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p3)==Info(p1))) {
                Info(p1)=Info(p1)*2;
                Info(p2)=Info(p4);
                Info(p3)=0;
                Info(p4)=0;
                a12+=Info(p1);
            }
            else if ((Info(p1)!=0)&&(Info(p2)==0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p3)!=Info(p1))&&(Info(p3)==Info(p4))) {
                Info(p1)=Info(p1);
                Info(p2)=Info(p3)*2;
                Info(p3)=0;
                Info(p4)=0;
                a13+=Info(p2);
            }
            else if ((Info(p1)!=0)&&(Info(p2)==0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p3)!=Info(p1))&&(Info(p3)!=Info(p4))) {
                Info(p1)=Info(p1);
                Info(p2)=Info(p3);
                Info(p3)=Info(p4);
                Info(p4)=0;

            }

            //3 elemen, kotak 3 kosong
            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)==0)&&(Info(p4)!=0)&&(Info(p1)==Info(p2))) {
                Info(p1)=Info(p1)*2;
                Info(p2)=Info(p4);
                Info(p3)=0;
                Info(p4)=0;
                a14+=Info(p1);
            }
            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)==0)&&(Info(p4)!=0)&&(Info(p1)!=Info(p2))&&(Info(p2)==Info(p4))) {
                Info(p1)=Info(p1);
                Info(p2)=Info(p2)*2;
                Info(p3)=0;
                Info(p4)=0;
                a15+=Info(p2);
            }
            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)==0)&&(Info(p4)!=0)&&(Info(p1)!=Info(p2))&&(Info(p2)!=Info(p4))) {
                Info(p1)=Info(p1);
                Info(p2)=Info(p2);
                Info(p3)=Info(p4);
                Info(p4)=0;
            }


            //Kalo 4 elemen
            //Kalo sama semua
            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p1)==Info(p2))&&(Info(p3)==Info(p4))) {
                Info(p1)=Info(p1)*2;
                Info(p2)=Info(p3)*2;
                Info(p3)=0;
                Info(p4)=0;
                a16+=Info(p1);
                a17+=Info(p2);
                s+=a16+a17;
            }
            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p1)==Info(p2))&&(Info(p3)!=Info(p4))) {
                Info(p1)=Info(p1)*2;
                Info(p2)=Info(p3);
                Info(p3)=Info(p4);
                Info(p4)=0;
                a18+=Info(p1);
            }
            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p1)!=Info(p2))&&(Info(p3)==Info(p4))&&(Info(p2)!=Info(p3))) {
                Info(p1)=Info(p1);
                Info(p2)=Info(p2);
                Info(p3)=Info(p3)*2;
                Info(p4)=0;
                a19+=Info(p3);
            }
            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p1)!=Info(p2))&&(Info(p2)==Info(p3))) {
                Info(p1)=Info(p1);
                Info(p2)=Info(p2)*2;
                Info(p3)=Info(p4);
                Info(p4)=0;
                a20+=Info(p2);
            }

       // (*scoreUp)=(a1+a2+a3+a4+a5+a6+a7+a8+a9+a10+a11+a12+a13+a14+a15+s+a18+a19+a20);

        p1=Down(p1);
        p2=Down(p2);
        p3=Down(p3);
        p4=Down(p4);


        }

        (*scoreLeft)+=a1+a2+a3+a5+a6+a7+a8+a9+a10+a11+a12+a13+a14+a15+s+a18+a19+a20;

        AddRandom(L1,L2,L3,L4);

        CetakList(L1);
        printf("\n");
        CetakList(L2);
        printf("\n");
        CetakList(L3);
        printf("\n");
        CetakList(L4);
        printf("\n");
    }
    else {
        CetakList(L1);
        printf("\n");
        CetakList(L2);
        printf("\n");
        CetakList(L3);
        printf("\n");
        CetakList(L4);
        printf("\n");
    }
}

void MoveRight (List L1, List L2, List L3, List L4,int *scoreRight)
/*melakukan pergerakan ke kanan*/
{
    address p1,p2,p3,p4;
    int a1=0,a2=0,a3=0,a4=0,a5=0,a6=0,a7=0,a8=0,a9=0,a10=0;
    int a11=0,a12=0,a13=0,a14=0,a15=0,a16=0,a17=0,a18=0,a19=0;
    int s=0;

    p1=First(L4);
    p2=Right(p1);
    p3=Right(p2);
    p4=Right(p3);

    if (CanMoveRight(L1,L2,L3,L4))
    {

        while (((p1)!=Nil)&&((p2)!=Nil)&&((p3)!=Nil)&&((p4)!=Nil))
        {

            if ((Info(p4)==0)&&(Info(p1)!=0)&&(Info(p2)==0)&&(Info(p3)==0)) {
                Info(p4)=Info(p1);
                Info(p1)=0;
            }
            else if ((Info(p4)==0)&&(Info(p1)==0)&&(Info(p2)!=0)&&(Info(p3)==0)) {
                Info(p4)=Info(p2);
                Info(p2)=0;
            }
            else if ((Info(p4)==0)&&(Info(p1)==0)&&(Info(p2)==0)&&(Info(p3)!=0)) {
                Info(p4)=Info(p3);
                Info(p3)=0;
            }

            //Ada 2 elemen, kotak 4 selalu ada isi


            else if ((Info(p1)==0)&&(Info(p2)==0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p4)==Info(p3))) { //Kalo sama
                Info(p4)=Info(p4)*2;
                Info(p3)=0;
                a1+=Info(p4);
            }
            else if ((Info(p1)==0)&&(Info(p2)!=0)&&(Info(p3)==0)&&(Info(p4)!=0)&&(Info(p4)==Info(p2))) { //Kalo sama
                Info(p4)=Info(p4)*2;
                Info(p2)=0;
                a2+=Info(p4);
            }
            else if ((Info(p1)==0)&&(Info(p2)!=0)&&(Info(p3)==0)&&(Info(p4)!=0)&&(Info(p4)!=Info(p2))) { //Kalo beda
                Info(p3)=Info(p2);
                Info(p2)=0;
            }
            else if ((Info(p1)!=0)&&(Info(p2)==0)&&(Info(p3)==0)&&(Info(p4)!=0)&&(Info(p1)==Info(p4))) { //Kalo sama
                Info(p4)=Info(p4)*2;
                Info(p1)=0;
                a3+=Info(p4);
            }
             else if ((Info(p1)!=0)&&(Info(p2)==0)&&(Info(p3)==0)&&(Info(p4)!=0)&&(Info(p1)!=Info(p4))) { //Kalo sama
                Info(p3)=Info(p1);
                Info(p1)=0;
            }

            //Kotak ke-3 selalu ada isi
            else if ((Info(p1)==0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)==0)&&(Info(p3)==Info(p2))) { //Kalo sama
                Info(p4)=Info(p3)*2;
                Info(p2)=0;
                Info(p3)=0;
                a4+=Info(p4);
            }
             else if ((Info(p1)==0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)==0)&&(Info(p3)!=Info(p2))) { //Kalo beda
                Info(p4)=Info(p3);
                Info(p3)=Info(p2);
                Info(p2)=0;
            }
            else if ((Info(p1)!=0)&&(Info(p2)==0)&&(Info(p3)!=0)&&(Info(p4)==0)&&(Info(p3)==Info(p1))) { //Kalo sama
                Info(p4)=Info(p3)*2;
                Info(p3)=0;
                Info(p1)=0;
                a5+=Info(p4);
            }
            else if ((Info(p1)!=0)&&(Info(p2)==0)&&(Info(p3)!=0)&&(Info(p4)==0)&&(Info(p3)!=Info(p1))) { //Kalo beda
                Info(p4)=Info(p3);
                Info(p3)=Info(p1);
                Info(p1)=0;
            }
            //Kalo kotak 2 pasti ada isi
             else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)==0)&&(Info(p4)==0)&&(Info(p1)==Info(p2))) { //Kalo sama
                Info(p4)=Info(p2)*2;
                Info(p2)=0;
                Info(p1)=0;
                a6+=Info(p4);
            }
            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)==0)&&(Info(p4)==0)&&(Info(p1)!=Info(p2))) { //Kalo beda
                Info(p4)=Info(p2);
                Info(p3)=Info(p1);
                Info(p2)=0;
                Info(p1)=0;
            }

            //Kalo ada 3 elemen, kotak 1 kosong

             else if ((Info(p1)==0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p3)==Info(p4))) { //Kalo p1=p2
                Info(p4)=Info(p4)*2;
                Info(p3)=Info(p2);
                Info(p2)=0;
                Info(p1)=0;
                a7+=Info(p4);
            }
            else if ((Info(p1)==0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p2)==Info(p3))) { //Kalo p2=p3
                Info(p4)=Info(p4);
                Info(p3)=Info(p3)*2;
                Info(p2)=0;
                Info(p1)=0;
                a8+=Info(p3);
            }

            //Kalo ada 3 elemen, kotak 4 kosong

            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)==0)&&(Info(p2)==Info(p3))) { //Kalo p2=p3
                Info(p4)=Info(p3)*2;
                Info(p3)=Info(p1);
                Info(p2)=0;
                Info(p1)=0;
                a9+=Info(p4);
            }
            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)==0)&&(Info(p2)==Info(p1))) { //Kalo p3=p4
                Info(p4)=Info(p3);
                Info(p3)=Info(p2)*2;
                Info(p2)=0;
                Info(p1)=0;
                a10+=Info(p3);
            }
            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)==0)&&(Info(p2)!=Info(p1))&&(Info(p2)!=Info(p3))) { //Kalo p3=p4
                Info(p4)=Info(p3);
                Info(p3)=Info(p2);
                Info(p2)=Info(p1);
                Info(p1)=0;
            }

            //3 elemen, Kotak 3 kosong
            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)==0)&&(Info(p4)!=0)&&(Info(p4)==Info(p2))) {
                Info(p4)=Info(p4)*2;
                Info(p3)=Info(p1);
                Info(p2)=0;
                Info(p1)=0;
                a11+=Info(p4);
            }
            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)==0)&&(Info(p4)!=0)&&(Info(p4)!=Info(p2))&&(Info(p2)==Info(p1))) {
                Info(p4)=Info(p4);
                Info(p3)=Info(p2)*2;
                Info(p2)=0;
                Info(p1)=0;
                a12+=Info(p3);
            }
            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)==0)&&(Info(p4)!=0)&&(Info(p4)!=Info(p2))&&(Info(p2)!=Info(p1))) {
                Info(p4)=Info(p4);
                Info(p3)=Info(p2);
                Info(p2)=Info(p1);
                Info(p1)=0;
            }

            //3 elemen, kotak 2 kosong
            else if ((Info(p1)!=0)&&(Info(p2)==0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p4)==Info(p3))) {
                Info(p4)=Info(p4)*2;
                Info(p3)=Info(p1);
                Info(p2)=0;
                Info(p1)=0;
                a13+=Info(p4);
            }
            else if ((Info(p1)!=0)&&(Info(p2)==0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p4)!=Info(p3))&&(Info(p3)==Info(p1))) {
                Info(p4)=Info(p4);
                Info(p3)=Info(p3)*2;
                Info(p2)=0;
                Info(p1)=0;
                a14+=Info(p3);
            }
            else if ((Info(p1)!=0)&&(Info(p2)==0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p4)!=Info(p3))&&(Info(p3)!=Info(p1))) {
                Info(p4)=Info(p4);
                Info(p3)=Info(p3);
                Info(p2)=Info(p1);
                Info(p1)=0;
            }

            //Kalo 4 elemen
            //Kalo sama semua
            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p1)==Info(p2))&&(Info(p3)==Info(p4))) {
                Info(p4)=Info(p4)*2;
                Info(p3)=Info(p2)*2;
                Info(p2)=0;
                Info(p1)=0;
                a15+=Info(p4);
                a16+=Info(p3);
                s+=(a15+a16);
            }
            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p4)==Info(p3))&&(Info(p1)!=Info(p2))) {
                Info(p4)=Info(p4)*2;
                Info(p3)=Info(p2);
                Info(p2)=Info(p1);
                Info(p1)=0;
                a17+=Info(p4);
            }
            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p4)!=Info(p3))&&(Info(p1)==Info(p2))&&(Info(p2)!=Info(p3))) {
                Info(p4)=Info(p4);
                Info(p3)=Info(p3);
                Info(p2)=Info(p2)*2;
                Info(p1)=0;
                a18+=Info(p2);
            }
            else if ((Info(p1)!=0)&&(Info(p2)!=0)&&(Info(p3)!=0)&&(Info(p4)!=0)&&(Info(p4)!=Info(p3))&&(Info(p3)==Info(p2))) {
                Info(p4)=Info(p4);
                Info(p3)=Info(p3)*2;
                Info(p2)=Info(p1);
                Info(p1)=0;
                a19+=Info(p3);
            }


        p1=Up(p1);
        p2=Up(p2);
        p3=Up(p3);
        p4=Up(p4);

        }

        AddRandom(L1,L2,L3,L4);

        (*scoreRight)+=a1+a2+a3+a4+a5+a6+a7+a8+a9+a10+a11+a12+a13+a14+a15+s+a18+a19;

        CetakList(L1);
        printf("\n");
        CetakList(L2);
        printf("\n");
        CetakList(L3);
        printf("\n");
        CetakList(L4);
        printf("\n");

    }
    else {
        CetakList(L1);
        printf("\n");
        CetakList(L2);
        printf("\n");
        CetakList(L3);
        printf("\n");
        CetakList(L4);
        printf("\n");
    }

}

int AngkaRandom ()
/*memunculkan angka random*/
{
        int a;
        time_t t;
        a=0;
        srand((unsigned) time(&t));
        a=rand() % 5;
        if ((a==0)||(a==1)||(a==2))
        {
            a=2;
        }
        else
        {
            a=4;
        }
        return a;
}

bool isZero(address P)
/*pengecekkan apakah info dari address tertentu kosong atau tidak*/
{
    int z;
    z=Info(P);
    if (z==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void ListtoArray (List L1, List L2, List L3, List L4, TabInt *T)
/*pengolahan list menjadi array*/
{
    int a;
    (*T).Neff=16;
    for (a=1;a<=16;a++)
    {
        if (a==1)
        {
            (*T).TI[a]=Info(First(L1));
        }
        else if (a==2)
        {
             (*T).TI[a]=Info(Right(First(L1)));
        }
        else if (a==3)
        {
             (*T).TI[a]=Info(Right(Right(First(L1))));
        }
        else if (a==4)
        {
             (*T).TI[a]=Info(Right(Right(Right(First(L1)))));
        }
        else if (a==5)
        {
             (*T).TI[a]=Info(First(L2));
        }
        else if (a==6)
        {
             (*T).TI[a]=Info(Right(First(L2)));
        }
        else if (a==7)
        {
             (*T).TI[a]=Info(Right(Right(First(L2))));
        }
        else if (a==8)
        {
             (*T).TI[a]=Info(Right(Right(Right(First(L2)))));
        }
        else if (a==9)
        {
             (*T).TI[a]=Info(First(L3));
        }
        else if (a==10)
        {
             (*T).TI[a]=Info(Right(First(L3)));
        }
        else if (a==11)
        {
             (*T).TI[a]=Info(Right(Right(First(L3))));
        }
        else if (a==12)
        {
             (*T).TI[a]=Info(Right(Right(Right(First(L3)))));
        }
        else if (a==13)
        {
             (*T).TI[a]=Info(First(L4));
        }
        else if (a==14)
        {
             (*T).TI[a]=Info(Right(First(L4)));
        }
        else if (a==15)
        {
             (*T).TI[a]=Info(Right(Right(First(L4))));
        }
        else if (a==16)
        {
             (*T).TI[a]=Info(Right(Right(Right(First(L4)))));
        }
    }
}

address InttoAddress (List L1, List L2, List L3, List L4, int a)
{
    address P1;
    if (a==1)
        {
            P1=First(L1);
        }
    else if (a==2)
        {
            P1=Right(First(L1));
        }
    else if (a==3)
        {
            P1=Right(Right(First(L1)));
        }
    else if (a==4)
        {
            P1=Right(Right(Right(First(L1))));
        }
    else if (a==5)
        {
            P1=First(L2);
        }
    else if (a==6)
        {
            P1=Right(First(L2));
        }
    else if (a==7)
        {
            P1=Right(Right(First(L2)));
        }
    else if (a==8)
        {
            P1=Right(Right(Right(First(L2))));
        }
    else if (a==9)
        {
            P1=First(L3);
        }
    else if (a==10)
        {
            P1=Right(First(L3));
        }
    else if (a==11)
        {
            P1=Right(Right(First(L3)));
        }
    else if (a==12)
        {
            P1=Right(Right(Right(First(L3))));
        }
    else if (a==13)
        {
            P1=First(L4);
        }
    else if (a==14)
        {
            P1=Right(First(L4));
        }
    else if (a==15)
        {
            P1=Right(Right(First(L4)));
        }
    else if (a==16)
        {
            P1=Right(Right(Right(First(L4))));
        }
    return P1;
}

void EmptyAddress (List L1, List L2, List L3, List L4, TabInt *T)
{
    int i,a;
    address P;

    a=1;
    ListtoArray(L1,L2,L3,L4,&(*T));
    for (i=1; i<=16;i++)
    {
        if (isZero(InttoAddress(L1,L2,L3,L4,i)))
        {
            (*T).TI[a]=i;
            (*T).Neff=a;
            a++;
        }
    }
}

address RandomEmptyAddress (List L1, List L2, List L3, List L4)
{
        TabInt TNol;
        int i,a,RandIndex;
        address P;
        time_t t;

        EmptyAddress(L1,L2,L3,L4,&TNol);
        a=TNol.Neff;
        srand ((unsigned) time(&t));
        RandIndex = (1+rand() % a);
        i= TNol.TI[RandIndex];
        P=InttoAddress(L1,L2,L3,L4,i);

        return P;
}

void AddRandom (List L1,List L2,List L3,List L4)
{
    address P1;
    int a;

    P1=RandomEmptyAddress(L1,L2,L3,L4);
    a=AngkaRandom();
    Info(P1)=a;
}

//PENGECEKAN KONDISI KALAH
bool CanMoveUp (List L1, List L2, List L3, List L4)
{
    address P4a = First(L4);
    address P3a = First(L3);
    address P2a = First(L2);
    address P1a = First(L1);
    infotype P1,P2,P3,P4;
    boolean CanIt=false;
    while (((P1a!=Nil)&&(P2a!=Nil)&&(P3a!=Nil)&&(P4a!=Nil))&&(CanIt==false))
    {
        P1=Info(P1a);
        P2=Info(P2a);
        P3=Info(P3a);
        P4=Info(P4a);
        if ((P1==0)&&(P2==0)&&(P3==0)&&(P4==0))
            CanIt = false;
        else
        {
        if ((P1!=0)&&(P2==0)&&(P3==0)&&(P4==0))
            CanIt = false;
        else
        {
            if ((P1!=0)&&(P2!=0)&&(P3==0)&&(P4==0)&&(P1!=P2))
                CanIt = false;
            else
            {
                if ((P1!=0)&&(P2!=0)&&(P3!=0)&&(P4==0)&&(P3!=P2)&&(P2!=P1))
                    CanIt = false;
                else
                {
                    if ((P1!=0)&&(P2!=0)&&(P3!=0)&&(P4!=0)&&(P3!=P4)&&(P3!=P2)&&(P1!=P2))
                        CanIt = false;
                    else
                        CanIt = true;
                }
            }
        }
        }
    P1a=Right(P1a);
    P2a=Right(P2a);
    P3a=Right(P3a);
    P4a=Right(P4a);
    }
    return (CanIt);
}

bool CanMoveDown (List L1, List L2, List L3, List L4)
{
    address P4a = First(L4);
    address P3a = First(L3);
    address P2a = First(L2);
    address P1a = First(L1);
    infotype P1,P2,P3,P4;
    boolean CanIt=false;
    while (((P1a!=Nil)&&(P2a!=Nil)&&(P3a!=Nil)&&(P4a!=Nil))&&(CanIt==false))
    {
        P1=Info(P1a);
        P2=Info(P2a);
        P3=Info(P3a);
        P4=Info(P4a);
        if ((P1==0)&&(P2==0)&&(P3==0)&&(P4==0))
            CanIt = false;
        else
        {
        if ((P1==0)&&(P2==0)&&(P3==0)&&(P4!=0))
            CanIt = false;
        else
        {
            if ((P1==0)&&(P2==0)&&(P3!=0)&&(P4!=0)&&(P4!=P3))
                CanIt = false;
            else
            {
                if ((P1==0)&&(P2!=0)&&(P3!=0)&&(P4!=0)&&(P3!=P2)&&(P3!=P4))
                    CanIt = false;
                else
                {
                    if ((P1!=0)&&(P2!=0)&&(P3!=0)&&(P4!=0)&&(P3!=P4)&&(P3!=P2)&&(P1!=P2))
                        CanIt = false;
                    else
                        CanIt = true;
                }
            }
        }
        }
    P1a=Right(P1a);
    P2a=Right(P2a);
    P3a=Right(P3a);
    P4a=Right(P4a);
    }
    return (CanIt);
}

bool CanMoveRight (List L1, List L2, List L3, List L4)
{
    address P = First(L1);
    infotype P1,P2,P3,P4;
    boolean CanIt=false;
    while ((P!=Nil)&&(CanIt==false))
    {
        P1=Info(P);
        P2=Info(Right(P));
        P3=Info(Right(Right(P)));
        P4=Info(Right(Right(Right(P))));
        if ((P1==0)&&(P2==0)&&(P3==0)&&(P4==0))
            CanIt = false;
        else
        {
        if ((P1==0)&&(P2==0)&&(P3==0)&&(P4!=0))
            CanIt = false;
        else
        {
            if ((P1==0)&&(P2==0)&&(P3!=0)&&(P4!=0)&&(P4!=P3))
                CanIt = false;
            else
            {
                if ((P1==0)&&(P2!=0)&&(P3!=0)&&(P4!=0)&&(P3!=P2)&&(P3!=P4))
                    CanIt = false;
                else
                {
                    if ((P1!=0)&&(P2!=0)&&(P3!=0)&&(P4!=0)&&(P3!=P4)&&(P3!=P2)&&(P1!=P2))
                        CanIt = false;
                    else
                        CanIt = true;
                }
            }
        }
        }
    P=Down(P);
    }
    return (CanIt);
}

bool CanMoveLeft (List L1, List L2, List L3, List L4)
{
    address P = First(L1);
    infotype P1,P2,P3,P4;
    boolean CanIt=false;
    while ((P!=Nil)&&(CanIt==false))
    {
        P1=Info(P);
        P2=Info(Right(P));
        P3=Info(Right(Right(P)));
        P4=Info(Right(Right(Right(P))));
        if ((P1==0)&&(P2==0)&&(P3==0)&&(P4==0))
            CanIt = false;
        else
        {
        if ((P1!=0)&&(P2==0)&&(P3==0)&&(P4==0))
            CanIt = false;
        else
        {
            if ((P1!=0)&&(P2!=0)&&(P3==0)&&(P4==0)&&(P1!=P2))
                CanIt = false;
            else
            {
                if ((P1!=0)&&(P2!=0)&&(P3!=0)&&(P4==0)&&(P3!=P2)&&(P2!=P1))
                    CanIt = false;
                else
                {
                    if ((P1!=0)&&(P2!=0)&&(P3!=0)&&(P4!=0)&&(P3!=P4)&&(P3!=P2)&&(P1!=P2))
                        CanIt = false;
                    else
                        CanIt = true;
                }
            }
        }
        }
    P=Down(P);
    }
    return (CanIt);


}
//SETTING INTERFACE
void setcolor2 ()
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,6);
}

void setcolor0 ()
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,8);
}

void setcolor4()
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,2);
}

void setcolor8 ()
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,3);
}

void awal ()
{
    // ANGKA 2
    setcolor2();
    gotoxy(10,1);
    printf(" ######### ");
    gotoxy(18,2);
    printf(" # ");
    gotoxy(18,3);
    printf(" # ");
    gotoxy(18,4);
    printf(" # ");
    gotoxy(10,5);
    printf(" ######### ");
    gotoxy(10,6);
    printf(" # ");
    gotoxy(10,7);
    printf(" # ");
    gotoxy(10,8);
    printf(" # ");
    gotoxy(10,9);
    printf(" ######### ");

    // ANGKA 0
    setcolor0();
    gotoxy(23,1);
    printf(" ######### ");
    gotoxy(23,2); printf(" # ");
    gotoxy(23,3); printf(" # ");
    gotoxy(23,4); printf(" # ");
    gotoxy(23,5); printf(" # ");
    gotoxy(23,6); printf(" # ");
    gotoxy(23,7); printf(" # ");
    gotoxy(23,8); printf(" # ");
    gotoxy(31,2); printf(" # ");
    gotoxy(31,3); printf(" # ");
    gotoxy(31,4); printf(" # ");
    gotoxy(31,5); printf(" # ");
    gotoxy(31,6); printf(" # ");
    gotoxy(31,7); printf(" # ");
    gotoxy(31,8); printf(" # ");
    gotoxy(23,9);
    printf(" ######### ");

    // ANGKA 4
    setcolor4();
    gotoxy(36,1); printf(" # ");
    gotoxy(36,2); printf(" # ");
    gotoxy(36,3); printf(" # ");
    gotoxy(36,4); printf(" # ");
    gotoxy(44,1); printf(" # ");
    gotoxy(44,2); printf(" # ");
    gotoxy(44,3); printf(" # ");
    gotoxy(44,4); printf(" # ");
    gotoxy(36,5);
    printf(" ######### ");
    gotoxy(44,6); printf(" # ");
    gotoxy(44,7); printf(" # ");
    gotoxy(44,8); printf(" # ");
    gotoxy(44,9); printf(" # ");

    //ANGKA 8
    setcolor8();
    gotoxy(49,1);
    printf(" ######### ");
    gotoxy(49,2); printf(" # ");
    gotoxy(49,3); printf(" # ");
    gotoxy(49,4); printf(" # ");
    gotoxy(49,5);
    printf(" ######### ");
    gotoxy(49,6); printf(" # ");
    gotoxy(49,7); printf(" # ");
    gotoxy(49,8); printf(" # ");
    gotoxy(57,2); printf(" # ");
    gotoxy(57,3); printf(" # ");
    gotoxy(57,4); printf(" # ");
    gotoxy(57,6); printf(" # ");
    gotoxy(57,7); printf(" # ");
    gotoxy(57,8); printf(" # ");
    gotoxy(49,9);
    printf(" ######### ");

}

void highscore()
/*Menghitung high score*/
{
    typedef struct
    {
        int Nilai;
        char Nama;
    } TScore;
    int i, j, k, jmax, x ;
    TScore temp;
    TScore Score[30000];
    int retval;
    FILE *fileku;

    // Algortima

    x=1;
    i=1;
    fileku = fopen("score.txt", "r");
    retval = fscanf(fileku, "%s %d", &Score[x].Nama, &Score[x].Nilai);
    gotoxy(25,12);
    printf("==== SCOREBOARD ====");
    while (retval != EOF)
    {
        ++x;
        ++i;
        retval = fscanf(fileku,"%s %d", &Score[x].Nama, &Score[x].Nilai);
    }
    for (j=1; j <= i; j++)
    {
        jmax=j;
        for(k = j+1; k <= i; k++)
        {
            if (Score[k].Nilai > Score[jmax].Nilai)
            {
                jmax = k;
            }
        }
        temp = Score[jmax];
        Score[jmax]= Score[j];
        Score[j]=temp;
    }
    for (j=1; j <= 10; j++)
    {
        gotoxy(32,12+j);
        printf("%s %d \n", &Score[j].Nama, Score[j].Nilai);
    }
    fclose(fileku);
}

void gotoxy(int x, int y)
{
    HANDLE hConsoleOutput;
    COORD dwCursorPosition;
    dwCursorPosition.X = x;
    dwCursorPosition.Y = y;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
}

//MENYIMPAN PADA FILE EKSTERNAL
void SaveLastGrid( List L1, List L2, List L3, List L4, int Score)
{
    int i;
    TabInt T;
    int retval;
    FILE *fileku;
    // ALGORITMA
    ListtoArray(L1,L2,L3,L4,&T);
    fileku = fopen("saveload.txt", "w");
    for ( i = 1; i<= 16; i++)
    {
        retval = fprintf(fileku,"%d\n", T.TI[i]);
    }
    fprintf(fileku,"%d\n", Score);
    fclose(fileku);
}

void SaveLastGrid1( List L1, List L2, List L3, List L4, int Score)
{
    int i;
    TabInt T;
    int retval;
    FILE *fileku1;
    // ALGORITMA
    ListtoArray(L1,L2,L3,L4,&T);
    fileku1 = fopen("saveload1.txt", "w");
    for ( i = 1; i<= 16; i++)
    {
        retval = fprintf(fileku1,"%d\n", T.TI[i]);
    }
    fprintf(fileku1,"%d\n", Score);
    fclose(fileku1);
}

void setColor(int color)
{
	#ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    #endif
}

void setcolor(unsigned short color)
{
HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hCon,color);
}

void OptionKey ()
/*Menampilkan optional key*/
{
    gotoxy(50,12);
	printf("OPTION KEYS:");
	gotoxy(50,13);
	printf(" A : Left");
	gotoxy(50,14);
	printf(" S : Down");
	gotoxy(50,15);
	printf(" D : Right");
	gotoxy(50,16);
	printf(" W : Up");
	gotoxy(50,17);
	printf(" U : Undo");
	gotoxy(50,18);
	printf(" Q : Quit and Save");
}

void ArraytoList (List *L1, List *L2, List *L3, List *L4, TabInt T)
/*Pengolahan array menjadi list*/
{
    Info(First(*L1))=T.TI[1];
    Info(Right(First(*L1)))=T.TI[2];
    Info(Right(Right(First(*L1))))=T.TI[3];
    Info(Right(Right(Right(First(*L1)))))=T.TI[4];
    Info(First(*L2))=T.TI[5];
    Info(Right(First(*L2)))=T.TI[6];
    Info(Right(Right(First(*L2))))=T.TI[7];
    Info(Right(Right(Right(First(*L2)))))=T.TI[8];
    Info(First(*L3))=T.TI[9];
    Info(Right(First(*L3)))=T.TI[10];
    Info(Right(Right(First(*L3))))=T.TI[11];
    Info(Right(Right(Right(First(*L3)))))=T.TI[12];
    Info(First(*L4))=T.TI[13];
    Info(Right(First(*L4)))=T.TI[14];
    Info(Right(Right(First(*L4))))=T.TI[15];
    Info(Right(Right(Right(First(*L4)))))=T.TI[16];
}

void LoadLastGrid(List *L1, List *L2, List *L3, List *L4,int *score)
/*Mengload data dari file eksternal untuk LOAD GAME*/
{
    int i;
    TabInt T;
    int retval;
    FILE *fileku;
    // ALGORITMA
    fileku = fopen("saveload.txt", "r");
    i=1;
    while(!feof(fileku))
    {
        retval = fscanf(fileku,"%d", &T.TI[i]);
        i++;;
    }
    fclose(fileku);
    ArraytoList(&(*L1),&(*L2),&(*L3),&(*L4),T);
    (*score) = T.TI[17];
}

void LoadLastGrid1(List *L1, List *L2, List *L3, List *L4,int *score)
/*Mengload data dari file eksternal untuk UNDO*/
{
    int i;
    TabInt T;
    int retval;
    FILE *fileku1;
    // ALGORITMA
    fileku1 = fopen("saveload1.txt", "r");
    i=1;
    while(!feof(fileku1))
    {
        retval = fscanf(fileku1,"%d", &T.TI[i]);
        i++;;
    }
    fclose(fileku1);
    ArraytoList(&(*L1),&(*L2),&(*L3),&(*L4),T);
    (*score) = T.TI[17];
}

bool isFull(List L1, List L2, List L3, List L4)
/*pengecekan kondisi list penuh*/
{
    TabInt T;
    bool found = true;
    ListtoArray(L1,L2,L3,L4,&T);
    int i=1;
    while ((i<=16)&&(found)){
        if (T.TI[i]==0)
            return false;
        else
            i++;
    }
    return (found);
}

bool Kalah (List L1, List L2, List L3, List L4)
/*Pengecekan kondisi kalah*/
{
    return ((isFull(L1,L2,L3,L4))&&(!CanMoveDown(L1,L2,L3,L4))&&(!CanMoveUp(L1,L2,L3,L4))&&(!CanMoveLeft(L1,L2,L3,L4))&&(!CanMoveRight(L1,L2,L3,L4)));
}

int Max (List L1, List L2, List L3, List L4)
{
    TabInt T;
    ListtoArray(L1,L2,L3,L4,&T);
    int i=1;
    int max=T.TI[1];
    while (i<=16){
        if (T.TI[i]>max)
            max=T.TI[i];
        i++;
    }
    return max;
}

bool Menang (int currentmax)
/*Pengecekan kondisi menang jika sudah mencapai 2048*/
{
    return (currentmax==2048);
}

void SaveScore (int scoreTotal)
/*Menyimpan score ke file eksternal dan menampilkan 10 tertinggi*/
{
    // Kamus
     typedef struct
    {
        int Nilai;
        char Nama;
    } TScore;
    int i, j, k, jmax  ;
    TScore Temp;
    TScore Score[30000];
    int retval;
    FILE *fileku;

    // ALgoritma
    // Mengubah file keternal menjadi array
    i=1;
    fileku = fopen("score.txt", "r");
    retval = fscanf(fileku, "%s %d", &Score[i].Nama, &Score[i].Nilai);
    while (retval != EOF)
    {
        ++i;
        retval = fscanf(fileku,"%s %d", &Score[i].Nama, &Score[i].Nilai);
    }
    fclose(fileku);
    printf("                 ");
    printf("Masukan username : "); scanf("%s",&Score[i].Nama);
    Score[i].Nilai = scoreTotal;

    for (j=1; j<=i; j++)
    {
        jmax=j;
        for(k=j+1;k<=i;k++)
        {
            if(Score[k].Nilai > Score[jmax].Nilai)
            {
                jmax=k;
            }
        }
        Temp = Score[jmax];
        Score[jmax]=Score[j];
        Score[j]=Temp;
    }
    fileku = fopen("score.txt","w");
    for (j=1; j<=i; j++)
    {
        retval = fprintf(fileku,"%s %d\n", &Score[j].Nama, Score[j].Nilai);
    }
    fclose(fileku);
}

void game ()
/*PERMAINAN UTAMA 2048*/
{
    /*KAMUS*/
    List L1,L2,L3,L4;
    int max=0;
    int ch;
    int score1=0;
    int scoreTotal=0;
    int a, scoreUp=0, scoreDown=0, scoreLeft=0, scoreRight=0;
    address p1,p2,p3,p4;
    bool f;

    /*ALGORITMA*/
    CreateBoard(&L1,&L2,&L3,&L4);

    AddRandom(L1,L2,L3,L4);
    AddRandom(L1,L2,L3,L4);

    awal();
    gotoxy(0,12);
    system("Color 73");
    printf("            ");
	printf("=================================\n");
    CetakList(L1);
    printf("\n");
    CetakList(L2);
    printf("\n");
    CetakList(L3);
    printf("\n");
    CetakList(L4);
    printf("\n");

    OptionKey();
    bool M=false;
    f=false;
    while ((!Kalah(L1,L2,L3,L4))&&(f==false)&&(M==false)){

        gotoxy(0,23);
        printf("Perpindahan : ");

        do{
            ch=getchar();
            printf("\n");
        } while (ch!='W' && ch!='w' && ch!='A' && ch!='a' && ch!='D' && ch!='d' && ch!='S' && ch!='s' && ch!='Q' && ch!='q' && ch!='U' && ch!='u' && ch!='E' && ch!='e' && ch!='R' && ch!='r' && ch!='t' && ch!='T' && ch!='y' && ch!='Y' && ch!='I' && ch!='i' && ch!='o' && ch!='O' && ch!='p' && ch!='P' && ch!='f' && ch!='F' && ch!='g' && ch!='G' && ch!='h' && ch!='H' && ch!='j' && ch!='J' && ch!='k' && ch!='K' && ch!='l' && ch!='L' && ch!='z' && ch!='Z' && ch!='x' && ch!='X' && ch!='c' && ch!='C' && ch!='v' && ch!='V' && ch!='b' && ch!='B' && ch!='n' && ch!='N' && ch!='M' && ch!='m');

        switch (ch) {
            case 'W' :  system("cls");
                        system("Color 73");
                        awal();
                        SaveLastGrid1(L1,L2,L3,L4,scoreTotal);
                        OptionKey();
                        gotoxy(0,12);
                        printf("            ");
                        printf("=================================\n");
                        MoveUp(L1,L2,L3,L4,&scoreUp);
                        max=Max(L1,L2,L3,L4);
                        scoreTotal=(scoreUp+scoreDown+scoreLeft+scoreRight);
                        printf("\n");
                        printf("score total : ");
                        printf("%d\n",scoreTotal);
                        printf("\n");
                        SaveLastGrid(L1,L2,L3,L4,scoreTotal);
            break;
            case 'w' :  system("cls");
                        system("Color 73");
                        awal();
                        SaveLastGrid1(L1,L2,L3,L4,scoreTotal);
                        OptionKey();
                        gotoxy(0,12);
                        printf("            ");
                        printf("=================================\n");
                        MoveUp(L1,L2,L3,L4,&scoreUp);
                        max=Max(L1,L2,L3,L4);
                        scoreTotal=(scoreUp+scoreDown+scoreLeft+scoreRight);
                        printf("\n");
                        printf("score total : ");
                        printf("%d\n",scoreTotal);
                        printf("\n");
                        SaveLastGrid(L1,L2,L3,L4,scoreTotal);


            break;

            case 'S' :  system("cls");
                        system("Color 73");
                        awal();
                        SaveLastGrid1(L1,L2,L3,L4,scoreTotal);
                        OptionKey();
                        gotoxy(0,12);
                        printf("            ");
                        printf("=================================\n");
                        MoveDown(L1,L2,L3,L4,&scoreDown);
                        max=Max(L1,L2,L3,L4);
                        scoreTotal=(scoreUp+scoreDown+scoreLeft+scoreRight);
                        printf("\n");
                        printf("score total : ");
                        printf("%d\n",scoreTotal);
                        printf("\n");
                        SaveLastGrid(L1,L2,L3,L4,scoreTotal);
            break;
            case 's' :  system("cls");
                        system("Color 73");
                        awal();
                        SaveLastGrid1(L1,L2,L3,L4,scoreTotal);
                        OptionKey();
                        gotoxy(0,12);
                        printf("            ");
                        printf("=================================\n");
                        MoveDown(L1,L2,L3,L4,&scoreDown);
                        max=Max(L1,L2,L3,L4);
                        scoreTotal=(scoreUp+scoreDown+scoreLeft+scoreRight);
                        printf("\n");
                        printf("score total : ");
                        printf("%d\n",scoreTotal);
                        printf("\n");
                        SaveLastGrid(L1,L2,L3,L4,scoreTotal);
            break;

            case 'A' :  system("cls");
                        system("Color 73");
                        awal();
                        SaveLastGrid1(L1,L2,L3,L4,scoreTotal);
                        OptionKey();
                        gotoxy(0,12);
                        printf("            ");
                        printf("=================================\n");
                        MoveLeft(L1,L2,L3,L4,&scoreLeft);
                        max=Max(L1,L2,L3,L4);
                        scoreTotal=(scoreUp+scoreDown+scoreLeft+scoreRight);
                        printf("\n");
                        printf("score total : ");
                        printf("%d\n",scoreTotal);
                        printf("\n");
                        SaveLastGrid(L1,L2,L3,L4,scoreTotal);
            break;
            case 'a' :  system("cls");
                        system("Color 73");
                        awal();
                        SaveLastGrid1(L1,L2,L3,L4,scoreTotal);
                        OptionKey();
                        gotoxy(0,12);
                        printf("            ");
                        printf("=================================\n");
                        MoveLeft(L1,L2,L3,L4,&scoreLeft);
                        max=Max(L1,L2,L3,L4);
                        scoreTotal=(scoreUp+scoreDown+scoreLeft+scoreRight);
                        printf("\n");
                        printf("score total : ");
                        printf("%d\n",scoreTotal);
                        printf("\n");
                        SaveLastGrid(L1,L2,L3,L4,scoreTotal);
            break;

            case 'D' :  system("cls");
                        system("Color 73");
                        awal();
                        SaveLastGrid1(L1,L2,L3,L4,scoreTotal);
                        OptionKey();
                        gotoxy(0,12);
                        printf("            ");
                        printf("=================================\n");
                        MoveRight(L1,L2,L3,L4,&scoreRight);
                        max=Max(L1,L2,L3,L4);
                        scoreTotal=(scoreUp+scoreDown+scoreLeft+scoreRight);
                        printf("\n");
                        printf("score total : ");
                        printf("%d\n",scoreTotal);
                        printf("\n");
                        SaveLastGrid(L1,L2,L3,L4,scoreTotal);
            break;
            case 'd' :  system("cls");
                        system("Color 73");
                        awal();
                        SaveLastGrid1(L1,L2,L3,L4,scoreTotal);
                        OptionKey();
                        gotoxy(0,12);
                        printf("            ");
                        printf("=================================\n");
                        MoveRight(L1,L2,L3,L4,&scoreRight);
                        max=Max(L1,L2,L3,L4);
                        scoreTotal=(scoreUp+scoreDown+scoreLeft+scoreRight);
                        printf("\n");
                        printf("score total : ");
                        printf("%d\n",scoreTotal);
                        printf("\n");
                        SaveLastGrid(L1,L2,L3,L4,scoreTotal);
            break;

            case 'Q' :  f=true;
                        SaveLastGrid(L1,L2,L3,L4,scoreTotal);
                        printf("Goodbye!\n");
                        setcolor(7);
            break;
            case 'q' :  f=true;
                        SaveLastGrid(L1,L2,L3,L4,scoreTotal);
                        printf("Goodbye!\n");
                        setcolor(7);
            break;

            case'U' :   LoadLastGrid1(&L1,&L2,&L3,&L4,&score1);
                        awal();
                        gotoxy(0,12);
                        system("Color 73");
                        printf("            ");
                        printf("=================================\n");
                        CetakList(L1);
                        printf("\n");
                        CetakList(L2);
                        printf("\n");
                        CetakList(L3);
                        printf("\n");
                        CetakList(L4);
                        printf("\n");
                        scoreTotal=(score1);
                        printf("\n");
                        printf("score total : ");
                        printf("%d\n",scoreTotal);
                        printf("\n");

            break;
            case 'u' :  LoadLastGrid1(&L1,&L2,&L3,&L4,&score1);
                        awal();
                        gotoxy(0,12);
                        system("Color 73");
                        printf("            ");
                        printf("=================================\n");
                        CetakList(L1);
                        printf("\n");
                        CetakList(L2);
                        printf("\n");
                        CetakList(L3);
                        printf("\n");
                        CetakList(L4);
                        printf("\n");
                        scoreTotal=(score1);
                        printf("\n");
                        printf("score total : ");
                        printf("%d\n",scoreTotal);
                        printf("\n");
            break;

            default :   printf("\n");
                        printf("Warning! Wrong input!!\n");
            break;
            }
        if (Menang(max))
            M=true;
    }
        if (M==true)
        {
            system("cls");
            awal();
            printf("\n");
            gotoxy(13,13);
            printf("****************** YOU WON ******************");
            gotoxy(25,15);
            printf("1.Keep playing\n");
            gotoxy(25,16);
            printf("2.Quit and save score\n");
            gotoxy(25,18);
            printf("Pilihan anda: ");
            int pil;
            scanf("%d", &pil);
            switch (pil)
            {
                case 1:
                        system("cls");
                        load();
                break;
                default:
                        system("cls");
                        awal();
                        printf("\n");
                        printf("            \n");
                        printf("         ****************** GAME OVER ******************\n\n");
                        SaveScore(scoreTotal);
                break;
            }
        }
    else{
    if (f==false)
    {
        system("cls");
        awal();
        printf("\n");
        printf("            \n");
        printf("         ****************** GAME OVER ******************\n\n");
        SaveScore(scoreTotal);
    }
    printf("\n");}
}

void load ()
/*PERMAINAN SETELAH LOAD*/
{
    // KAMUS
    List L1, L2, L3, L4;
    int ch;
    int score;
    int max=0;
    bool M=false;
    bool M1=false;
    int score1;
    int scoreTotal;
    int a, scoreUp=0, scoreDown=0, scoreLeft=0, scoreRight=0;
    address p1,p2,p3,p4;
    bool f;

    // ALGORITMA
    CreateBoard(&L1,&L2,&L3,&L4);
    LoadLastGrid(&L1,&L2,&L3,&L4,&score);
    max=Max(L1,L2,L3,L4);
    if (Menang(max))
        M1=true;

    if (!Kalah(L1,L2,L3,L4)) {

        awal();
        gotoxy(0,12);
        system("Color 73");
        printf("            ");
        printf("=================================\n");
        CetakList(L1);
        printf("\n");
        CetakList(L2);
        printf("\n");
        CetakList(L3);
        printf("\n");
        CetakList(L4);
        printf("\n");

        OptionKey();

        f=false;

        while ((!Kalah(L1,L2,L3,L4))&&(f==false)&&(M==false)) {

        gotoxy(0,23);
        printf("Perpindahan : ");

        do{
            ch=getchar();
            printf("\n");
        } while (ch!='W' && ch!='w' && ch!='A' && ch!='a' && ch!='D' && ch!='d' && ch!='S' && ch!='s' && ch!='Q' && ch!='q' && ch!='U' && ch!='u' && ch!='E' && ch!='e' && ch!='R' && ch!='r' && ch!='t' && ch!='T' && ch!='y' && ch!='Y' && ch!='I' && ch!='i' && ch!='o' && ch!='O' && ch!='p' && ch!='P' && ch!='f' && ch!='F' && ch!='g' && ch!='G' && ch!='h' && ch!='H' && ch!='j' && ch!='J' && ch!='k' && ch!='K' && ch!='l' && ch!='L' && ch!='z' && ch!='Z' && ch!='x' && ch!='X' && ch!='c' && ch!='C' && ch!='v' && ch!='V' && ch!='b' && ch!='B' && ch!='n' && ch!='N' && ch!='M' && ch!='m');

        switch (ch) {
            case 'W' :  system("cls");
                        system("Color 73");
                        awal();
                        SaveLastGrid1(L1,L2,L3,L4,scoreTotal);
                        OptionKey();
                        gotoxy(0,12);
                        printf("            ");
                        printf("=================================\n");
                        MoveUp(L1,L2,L3,L4,&scoreUp);
                        max=Max(L1,L2,L3,L4);
                        scoreTotal=(scoreUp+scoreDown+scoreLeft+scoreRight+score);
                        printf("\n");
                        printf("score total : ");
                        printf("%d\n",scoreTotal);
                        printf("\n");
                        SaveLastGrid(L1,L2,L3,L4,scoreTotal);
            break;
            case 'w' :  system("cls");
                        system("Color 73");
                        awal();
                        SaveLastGrid1(L1,L2,L3,L4,scoreTotal);
                        OptionKey();
                        gotoxy(0,12);
                        printf("            ");
                        printf("=================================\n");
                        MoveUp(L1,L2,L3,L4,&scoreUp);
                        max=Max(L1,L2,L3,L4);
                        scoreTotal=(scoreUp+scoreDown+scoreLeft+scoreRight+score);
                        printf("\n");
                        printf("score total : ");
                        printf("%d\n",scoreTotal);
                        printf("\n");
                        SaveLastGrid(L1,L2,L3,L4,scoreTotal);
            break;

            case 'S' :  system("cls");
                        system("Color 73");
                        awal();
                        SaveLastGrid1(L1,L2,L3,L4,scoreTotal);
                        OptionKey();
                        gotoxy(0,12);
                        printf("            ");
                        printf("=================================\n");
                        MoveDown(L1,L2,L3,L4,&scoreDown);
                        max=Max(L1,L2,L3,L4);
                        scoreTotal=(scoreUp+scoreDown+scoreLeft+scoreRight+score);
                        printf("\n");
                        printf("score total : ");
                        printf("%d\n",scoreTotal);
                        printf("\n");
                        SaveLastGrid(L1,L2,L3,L4,scoreTotal);
            break;
            case 's' :  system("cls");
                        system("Color 73");
                        awal();
                        SaveLastGrid1(L1,L2,L3,L4,scoreTotal);
                        OptionKey();
                        gotoxy(0,12);
                        printf("            ");
                        printf("=================================\n");
                        MoveDown(L1,L2,L3,L4,&scoreDown);
                        max=Max(L1,L2,L3,L4);
                        scoreTotal=(scoreUp+scoreDown+scoreLeft+scoreRight+score);
                        printf("\n");
                        printf("score total : ");
                        printf("%d\n",scoreTotal);
                        printf("\n");
                        SaveLastGrid(L1,L2,L3,L4,scoreTotal);
            break;

            case 'A' :  system("cls");
                        system("Color 73");
                        awal();
                        SaveLastGrid1(L1,L2,L3,L4,scoreTotal);
                        OptionKey();
                        gotoxy(0,12);
                        printf("            ");
                        printf("=================================\n");
                        MoveLeft(L1,L2,L3,L4,&scoreLeft);
                        max=Max(L1,L2,L3,L4);
                        scoreTotal=(scoreUp+scoreDown+scoreLeft+scoreRight+score);
                        printf("\n");
                        printf("score total : ");
                        printf("%d\n",scoreTotal);
                        printf("\n");
                        SaveLastGrid(L1,L2,L3,L4,scoreTotal);
            break;
            case 'a' :  system("cls");
                        system("Color 73");
                        awal();
                        SaveLastGrid1(L1,L2,L3,L4,scoreTotal);
                        OptionKey();
                        gotoxy(0,12);
                        printf("            ");
                        printf("=================================\n");
                        MoveLeft(L1,L2,L3,L4,&scoreLeft);
                        max=Max(L1,L2,L3,L4);
                        scoreTotal=(scoreUp+scoreDown+scoreLeft+scoreRight+score);
                        printf("\n");
                        printf("score total : ");
                        printf("%d\n",scoreTotal);
                        printf("\n");
                        SaveLastGrid(L1,L2,L3,L4,scoreTotal);
            break;

            case 'D' :  system("cls");
                        system("Color 73");
                        awal();
                        SaveLastGrid1(L1,L2,L3,L4,scoreTotal);
                        OptionKey();
                        gotoxy(0,12);
                        printf("            ");
                        printf("=================================\n");
                        MoveRight(L1,L2,L3,L4,&scoreRight);
                        max=Max(L1,L2,L3,L4);
                        scoreTotal=(scoreUp+scoreDown+scoreLeft+scoreRight+score);
                        printf("\n");
                        printf("score total : ");
                        printf("%d\n",scoreTotal);
                        printf("\n");
                        SaveLastGrid(L1,L2,L3,L4,scoreTotal);
            break;
            case 'd' :  system("cls");
                        system("Color 73");
                        awal();
                        SaveLastGrid1(L1,L2,L3,L4,scoreTotal);
                        OptionKey();
                        gotoxy(0,12);
                        printf("            ");
                        printf("=================================\n");
                        MoveRight(L1,L2,L3,L4,&scoreRight);
                        max=Max(L1,L2,L3,L4);
                        scoreTotal=(scoreUp+scoreDown+scoreLeft+scoreRight+score);
                        printf("\n");
                        printf("score total : ");
                        printf("%d\n",scoreTotal);
                        printf("\n");
                        SaveLastGrid(L1,L2,L3,L4,scoreTotal);
            break;

            case 'Q' :  f=true;
                        SaveLastGrid(L1,L2,L3,L4,scoreTotal);
                        printf("Goodbye!\n");
                        setcolor(7);
            break;
            case 'q' :  f=true;
                        SaveLastGrid(L1,L2,L3,L4,scoreTotal);
                        printf("Goodbye!\n");
                        setcolor(7);
            break;

            case'U' :   LoadLastGrid1(&L1,&L2,&L3,&L4,&score1);
                        awal();
                        gotoxy(0,12);
                        system("Color 73");
                        printf("            ");
                        printf("=================================\n");
                        CetakList(L1);
                        printf("\n");
                        CetakList(L2);
                        printf("\n");
                        CetakList(L3);
                        printf("\n");
                        CetakList(L4);
                        printf("\n");
                        scoreTotal=(score1);
                        printf("\n");
                        printf("score total : ");
                        printf("%d\n",scoreTotal);
                        printf("\n");
            break;
            case 'u' :  LoadLastGrid1(&L1,&L2,&L3,&L4,&score1);
                        awal();
                        gotoxy(0,12);
                        system("Color 73");
                        printf("            ");
                        printf("=================================\n");
                        CetakList(L1);
                        printf("\n");
                        CetakList(L2);
                        printf("\n");
                        CetakList(L3);
                        printf("\n");
                        CetakList(L4);
                        printf("\n");
                        scoreTotal=(score1);
                        printf("\n");
                        printf("score total : ");
                        printf("%d\n",scoreTotal);
                        printf("\n");
            break;

            default :   printf("\n");
                        printf("Warning! Wrong input!!\n");
            break;
            }
            if (!M1){
            if (Menang(max))
                M=true;}
        }
        if (M==true)
        {
            system("cls");
            awal();
            printf("\n");
            gotoxy(13,13);
            printf("****************** YOU WON ******************");
            gotoxy(25,15);
            printf("1.Keep playing\n");
            gotoxy(25,16);
            printf("2.Quit and save score\n");
            gotoxy(25,18);
            printf("Pilihan anda: ");
            int pil;
            scanf("%d", &pil);
            switch (pil)
            {
                case 1:
                        system("cls");
                        load();
                break;
                default:
                        system("cls");
                        awal();
                        printf("\n");
                        printf("            \n");
                        printf("         ****************** GAME OVER ******************\n\n");
                        SaveScore(scoreTotal);
                break;
            }
        }
        else{
        if (f==false)
        {
            system("cls");
            awal();
            printf("\n");
            printf("            \n");
            printf("         ****************** GAME OVER ******************\n\n");
            SaveScore(scoreTotal);
        }
        printf("\n");}
    }
}

