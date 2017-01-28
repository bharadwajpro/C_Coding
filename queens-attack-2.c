#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long int mins(long int a, long int b)
{
    if(a>b) return b;
    return a;
}

int main()
{
    long int n, k, r, c, temp;
    long long int ans = 0;
    scanf("%ld %ld", &n, &k);
    scanf("%ld %ld", &r, &c);
    long int min[8], x, p, q;
    min[0] = n-r;
    min[2] = n-c;
    min[4] = r-1;
    min[6] = c-1;
    min[1] = mins(min[0], min[2]);
    min[3] = mins(min[2], min[4]);
    min[5] = mins(min[4], min[6]);
    min[7] = mins(min[6], min[0]);
    if(n==1)
    {
        printf("0\n");
        return 0;
    }
    while(k--)
    {
        scanf("%ld %ld", &p, &q);
        if(p==r)
        {
            if(q>c) //min[0]
            {
                temp = q-c-1;
                if(temp<min[0]) min[0] = temp;
            }
            else //min[4]
            {
                temp = c-q-1;
                if(temp<min[4]) min[4] = temp;
            }
        }
        else if(q==c)
        {
            if(p>r) //min[2]
            {
                temp = p-r-1;
                if(temp<min[2]) min[2] = temp;
            }
            else //min[6]
            {
                temp = r-p-1;
                if(temp<min[6]) min[6] = temp;
            }
        }
        else
        {
            double num = abs(p-r), den = abs(q-c);
            long int top = ceil(num/den);
            long int bot = floor(num/den);
            if(top==bot && top==1)
            {
                if(p>r && q>c) //min[1]
                {
                    temp = p-r-1;
                    if(temp<min[1]) min[1] = temp;
                }
                else if(p>r && q<c) //min[3]
                {
                    temp = p-r-1;
                    if(temp<min[3]) min[3] = temp;
                }
                else if(p<r && q<c) //min[5]
                {
                    temp = r-p-1;
                    if(temp<min[5]) min[5] = temp;
                }
                else if(p<r && q>c) //min[7]
                {
                    temp = r-p-1;
                    if(temp<min[7]) min[7] = temp;
                }
            }
        }
    }
    for(x=0; x<8; x++) ans+=min[x];
    printf("%lld\n", ans);
    return 0;
}
