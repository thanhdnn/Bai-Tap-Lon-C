#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include "student.h"
#define location "./SV2021.dat"

void ktrong()
{
    for (int i = 0; i < 28; i++)
    {
        putchar('-');
    }
    printf("\n");
}

void interface()
{
    printf("\n 1.Xem danh sach sinh vien");
    printf("\n 2.Nhap them sinh vien");
    printf("\n 3.Tim sinh vien theo ten");
    printf("\n 4.Thoat \n");
}

void demuc()
{
    ktrong();
    printf("|%-20s|%5s|\n", "Ten", "Diem");
    ktrong();
}

void inthemhs(HS hs)
{
    FILE *file = fopen(location, "ab+");
    int result = fwrite(&hs, sizeof(HS), 1, file);
    assert(result != 0);
    fclose(file);
}

void themhs()
{
    HS new_hsdent;
    char ten[255];

    printf("Nhap ten:   ");
    fflush(stdin);
    fgets(ten, 255, stdin);
    strtok(ten, "\n");

    strcpy(new_hsdent.ten, ten);

    printf("Nhap diem:  ");
    scanf(" %f", &new_hsdent.diem);

    inthemhs(new_hsdent);
    ktrong();
    printf("Them thanh cong %s voi so diem %.2f!  \n", new_hsdent.ten, new_hsdent.diem);
    ktrong();
}

void dshs(char *query)
{
    FILE *file = fopen(location, "r");
    HS y;
    while (fread(&y, sizeof(HS), 1, file))
    {
        if (!strstr(y.ten, query))
            continue;
        printf("|%-20s|%5.2f|\n", y.ten, y.diem);
        ktrong();
    }
    fclose(file);
}

void timkiem()
{
    printf("Nhap ten can tim:   ");
    char x[255];

    fflush(stdin);
    fgets(x, 255, stdin);
    strtok(x, "\n");

    printf("Ket qua tim kiem: \n");
    demuc();
    dshs(x);
}

void inhang()
{
    FILE *file = fopen(location, "r");
    HS x;
    while (fread(&x, sizeof(HS), 1, file) )
    {
        printf("|%-20s|%5.2f|\n", x.ten, x.diem);
        ktrong();
    }
    fclose(file);
}

int main()
{
    int function;
    do
    {
        interface();
        scanf(" %d", &function);
        switch (function)
        {
        case 1:
            demuc();
            inhang();
            break;
        case 2:
            themhs();
            break;
        case 3:
            timkiem();
            break;
        case 4:
            return 0;
        default:
            printf("Xin hay chon lai!");
            break;
        }
    } while (function != 4);
}
