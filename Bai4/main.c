#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int f;
    int s;
} xiepcap;

xiepcap make_xiepcap(int _f, int _s)
{
    xiepcap tralai;
    tralai.f = _f;
    tralai.s = _s;
    return tralai;
}

int x[13][4];

char *giaima(int chat)
{
    switch (chat)
    {
    case 0:
        return "co";
    case 1:
        return "ro";
    case 2:
        return "bich";
    case 3:
        return "tep";
    default:
        assert(1 != 1);
        break;
    }
    return "";
}
char *ttbai(int chat)
{
    switch (chat)
    {
    case 0:
        return "A";
    case 1:
        return "2";
    case 2:
        return "3";
    case 3:
        return "4";
    case 4:
        return "5";
    case 5:
        return "6";
    case 6:
        return "7";
    case 7:
        return "8";
    case 8:
        return "9";
    case 9:
        return "10";
    case 10:
        return "J";
    case 11:
        return "Q";
    case 12:
        return "K";
    default:
        assert(1 != 1);
        break;
    }
    return "";
}

xiepcap chiabai()
{
    int r = rand() % 52;
    int cot = r / 4;
    int hang = r % 4;
    while (x[cot][hang] == 1)
    {
        r = (r == 51) ? 0 : r + 1;
        cot = r / 4;
        hang = r % 4;
    }
    x[cot][hang] = 1;
    return make_xiepcap(cot, hang);
}

void tuquy(xiepcap bai[])
{
    int count[13];
    memset(count, 0, sizeof(int) * 13);
    for (int i = 0; i < 13; i++)
    {
        count[bai[i].f]++;
    }
    for (int i = 0; i < 13; i++)
    {
        if (count[i] < 4)
            continue;
        printf("\n Tu quy %s", ttbai(i));
    }
}

void ktrong()
{
    printf("\n");
    for (int i = 0; i < 60; i++)
    {
        putchar('-');
    }
    printf("\n");
}

void inbai(xiepcap bai)
{
    char *rank = ttbai(bai.f);
    char *suite = giaima(bai.s);
    printf("|%s %s|", rank, suite);
}

void inbobai(xiepcap labai[])
{
    for (int i = 0; i < 13; i++)
    {
        inbai(labai[i]);
    }
    tuquy(labai);
    ktrong();
}

int main()
{
    memset(x, 0, sizeof(int) * 13 * 4);
    time_t t;

    xiepcap Nguoi_choi_1_labai[13];
    xiepcap Nguoi_choi_2_labai[13];
    xiepcap Nguoi_choi_3_labai[13];
    xiepcap Nguoi_choi_4_labai[13];
    srand((unsigned)time(&t));

    for (int i = 0; i < 13; i++)
    {
        Nguoi_choi_1_labai[i] = chiabai();
        Nguoi_choi_2_labai[i] = chiabai();
        Nguoi_choi_3_labai[i] = chiabai();
        Nguoi_choi_4_labai[i] = chiabai();
    }

    printf("Nguoi choi 1 co :\n");
    inbobai(Nguoi_choi_1_labai);

    printf("\nNguoi choi 2 co :\n");
    inbobai(Nguoi_choi_2_labai);

    printf("\nNguoi choi 3 co :\n");
    inbobai(Nguoi_choi_3_labai);

    printf("\nNguoi choi 4 co :\n");
    inbobai(Nguoi_choi_4_labai);
    return 0;
}
