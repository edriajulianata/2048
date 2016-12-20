/* Nomor Kelompok : 02 */
/* Nama file : driver_02.c*/
/* Deskripsi : main program 2048 */



#include "tubes2048_02.c"
int main ()
{
   int pil;
   int button;
   int a;
   int scoreTotal;
   // Algoritma
   system("cls");
   awal();
   gotoxy(29,11);
   printf("START THE GAME!");
   gotoxy(22,12);
   printf("[ push '1' then 'enter' button ]");
   scanf("%d", &button);

   // MASUK KE MENU UTAMA
   while (pil != 6)
   {
    balik:
       system("cls");
       awal();
       gotoxy(23,11);
       printf(" ****** CHOOSE IT! ****** ");
       gotoxy(24,12);
       printf("1. START A NEW GAME!");
       gotoxy(24,13);
       printf("2. LOAD GAME!");
       gotoxy(24,14);
       printf("3. HIGHSCORE BOARD");
       gotoxy(24,15);
       printf("4. HOW TO PLAY");
       gotoxy(24,16);
       printf("5. ABOUT");
       gotoxy(24,17);
       printf("6. EXIT");
       gotoxy(1,18);
       printf(" =======>> WHAT'S YOUR CHOICE?");
       scanf("%d", &pil);
       switch(pil)
       {
        case 1: system("cls");
                game();
            break;
        case 2:system("cls");
               load();
            break;
        case 3: system("cls");
                awal();printf("\n");
                highscore();
                printf("PRESS 1 TO BACK:");
                scanf("%d", &a);
                while (a != 1)
                {
                    system("cls");
                    awal();
                    highscore();
                    printf("PRESS 1 TO BACK:");
                    scanf("%d", &a);
                }
            break;
        case 4: system("cls");
                awal();
                gotoxy(23,11);
                printf("=== HOW TO PLAY ===");
                gotoxy(0,12);
                printf("2048 is played on a 4x4 grid, with numbered tiles that slide\n");
                printf("smoothly when a player moves them using the four arrows key.\n");
                printf("Every turn, a new tile will randomly appear in an empty spot on\n");
                printf("the board with a value of either 2 or 4. If two tiles of the same\n");
                printf("number collide while moving, they will merge into a tile with the \n");
                printf("total value of the two tiles that collided. The function of keys:\n");
                printf("The A key : Left move\n");
                printf("The S key : Down move\n");
                printf("The D key : Right move\n");
                printf("The W key : Up move\n");
                printf("PRESS 1 TO BACK:");
                scanf("%d", &a);
                while (a != 1)
                {
                  system("cls");
                awal();
                gotoxy(23,11);
                printf("=== HOW TO PLAY ===");
                gotoxy(0,12);
                printf("2048 is played on a 4x4 grid, with numbered tiles that slide\n");
                printf("smoothly when a player moves them using the four arrows key.\n");
                printf("Every turn, a new tile will randomly appear in an empty spot on\n");
                printf("the board with a value of either 2 or 4. If two tiles of the same\n");
                printf("number collide while moving, they will merge into a tile with the \n");
                printf("total value of the two tiles that collided. The function of keys:\n");
                printf("The A key : Left move\n");
                printf("The S key : Down move\n");
                printf("The D key : Right move\n");
                printf("The W key : Up move\n");
                printf("PRESS 1 TO BACK:");
                scanf("%d", &a);
                }
            break;
        case 5: system("cls");
                awal();
                gotoxy(25,13);
                printf("2048 GAME FREE v1.0");
                gotoxy(15,14);
                printf("A game developed and published by SuicideSquad Co., Ltd");
                gotoxy(25,17);
                printf("--- Programmer ---");
                gotoxy(21,18); printf(" Jessy Josephine N [18214021] ");
                gotoxy(21,19); printf(" Nafisah Andina P  [18214025] ");
                gotoxy(21,20); printf(" Katriel Ester A   [18214047] ");
                gotoxy(21,21); printf(" Edria Julianata   [18214050] ");
                gotoxy(20,23);
                printf("Copyright © 2015 by SuicideSquad Co., Ltd\n");
                printf("====>> PRESS 1 TO BACK:");
                scanf("%d", &a);
                while(a!= 1)
                {
                system("cls");
                awal();
                gotoxy(25,13);
                printf("2048 GAME FREE v1.0");
                gotoxy(15,14);
                printf("A game developed and published by SuicideSquad Co., Ltd");
                gotoxy(25,17);
                printf("--- Programmer ---");
                gotoxy(21,18); printf(" Jessy Josephine N [18214021] ");
                gotoxy(21,19); printf(" Nafisah Andina P  [18214025] ");
                gotoxy(21,20); printf(" Katriel Ester A   [18214047] ");
                gotoxy(21,21); printf(" Edria Julianata   [18214050] ");
                gotoxy(20,23);
                printf("Copyright © 2015 by SuicideSquad Co., Ltd\n");
                printf("====>> PRESS 1 TO BACK:");
                scanf("%d", &a);
                }
            break;
        case 6: system("cls");
                awal();
                gotoxy(18,13);
                printf("===================================");
                gotoxy(18,14);
                printf("||            BYE BYE!           ||");
                gotoxy(18,15);
                printf("||         SEE YOU LATER!        ||");
                gotoxy(18,16);
                printf("|| THANKS FOR PLAYING THIS GAME! ||");
                gotoxy(18,17);
                printf("===================================");
                gotoxy(20,21);
                printf("Copyright © 2015 by SuicideSquad Co., Ltd\n");
            break;
        default:break;
       }
   }

}
