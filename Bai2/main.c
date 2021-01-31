
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int khoiluong;
    int gtri;
    int sl;
    float giatri;
    char ten;
} dovat;

int sosanh(const void *x, const void *y)
{
    dovat dv1 = *(dovat *)x;
    dovat dv2 = *(dovat *)y;
    return (dv1.giatri < dv2.giatri) - (dv1.giatri > dv2.giatri);
}

dovat *capphatbonho(int size)
{
    return (dovat *)malloc(size * sizeof(dovat));
}

void printdovat(dovat dv)
{
    printf("%c : %d \n", dv.ten, dv.sl);
}

int main()
{
    int N, a;
    FILE *input = fopen("./BAG.INP", "r");
    FILE *output = fopen("BAG.OUP", "w");
    
    if (input == NULL)
    {
        printf("Error!\n");
        exit(1);
    }
    fscanf(input, "%d %d", &N, &a);
    dovat *dvs = capphatbonho(N);
    
    for (int i = 0; i < N; i++)
    {
        dovat x;
        fscanf(input, "%d %d %c", &x.khoiluong, &x.gtri, &x.ten);
        x.giatri = (float)(x.gtri) / (float)(x.khoiluong);
        dvs[i] = x;
    }
    qsort(dvs, N, sizeof(dovat), sosanh);
    int kl = a;
    int tong = 0;

    for (int i = 0; i < N; i++)
    {
        div_t chia = div(kl, dvs[i].khoiluong);
        int dem = chia.quot;

        tong += dem * dvs[i].gtri;
        kl = chia.rem;
        dvs[i].sl = dem;
    }
    fprintf(output, "%d \n", tong);
    for (int i = 0; i < N; i++)
    {
        if (!dvs[i].sl)
            continue;
        fprintf(output, "%c %d \n", dvs[i].ten, dvs[i].sl);
    }
    fclose(output);
    fclose(input);
    free(dvs);
    return 0;
}

