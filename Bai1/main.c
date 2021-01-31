#include <stdio.h>
#include <stdlib.h>
#define ll long long

ll tohop(ll n, ll k)
{
    float kq = 0;
    if (k > n)
        return (ll)kq;
    else if (n >= 0 && k >= 0)
    {
        kq = 1;
        while (k >= 1)
        {
            kq = kq * (float)n/k;
            k--;
            n--;
        }
    }
    else
    {
        printf("So lieu khong hop le\n");
    }
    if (kq-(ll)kq >= 0.5)
    {
        kq++;
    }
    return (ll)kq;
}

int main()
{
    ll n, k;
    FILE *input = fopen("./tohop.input", "r");
    FILE *output = fopen("tohop.output", "w");
    if(input == NULL)
       {
           printf("Error!\n");
           exit(1);
       }
    while(!feof(input))
    {
        fscanf(input, "%lld %lld\n", &n, &k);
        fprintf(output, "%lld\n", tohop(n, k));
    }
    fclose(input);
    fclose(output);
    return 0;
}
