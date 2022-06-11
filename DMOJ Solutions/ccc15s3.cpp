//i have already solved the problem. this is just testing the editorial solution because i think its not O(Plog(G)) as claimed
#include <stdio.h>
#include <bitset>

int a,b,c,d;
std::bitset<100005> taken;

int main()
{
    taken.flip();
    scanf("%d%d",&a,&b);
    for (int i=0; i<b; i++) {
        scanf("%d",&c);
        d=taken._Find_next(a-c);
        if (d>a) {
            printf("%d\n",i);
            return 0;
        }
        taken[d]=0;
    }
    printf("%d\n",b);
}