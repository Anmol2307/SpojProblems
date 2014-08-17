#include <cstdio>

int main()
{
  int a[1000001];
  int i=1,j=2,number=1;
  a[1] = 1;
  number=2;
  while(j<1000001)
  {
    int count=a[i];
    while(count>0 && j<1000001)
    {
      a[j]=number;
      j++;
      count--;
    }
    number++;
    i++;
  }

  int t,n;
  scanf("%d",&t);
  for(i=1;i<=t;i++)
  {
    scanf("%d",&n);
    printf("Case #%d: %d\n",i,a[n]);
  }

  return 0;
}