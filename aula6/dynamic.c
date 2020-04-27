#include <stdio.h>
#include <assert.h>

int nMult = 0;
int motzkin(int n)
{
    assert(n >= 0);
    int m[n + 1];
    int result ;
    m[0] = m[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        result = 0;
        for (int k = 0; k < i-1; k++)
        {
            nMult++;
            result += m[k] * m[i-2-k];
        }
        m[i] = m[i-1] + result;
    }

    return m[n];
}
int main(void)
{
    printf("%3s| %10s | %6s \n", "n", "Dinamico", "nMult");
    printf("_____________________________\n");
    for (int i = 0; i <= 15; i++)
    {
        int n = motzkin(i);
        printf("%3d| %10d | %6d \n", i, n, nMult);
        nMult = 0;
    }
    return 0;
}
