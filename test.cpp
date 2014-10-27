#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 200002
//vector<string> list;
int main(){
  char A[MAX],B[MAX],s1[MAX],s2[MAX],s3[MAX];
  int i,L,flag,k;
  while(scanf("%s",A)!=EOF)
  {
    flag=0;
    //list.clear();
    scanf("%s",B);
    L=strlen(A);
    for(i=0;i<L;i++)
    {
      if(A[i] > B[0])
        break;
      else if(A[i]<B[0])
        printf("%c",A[i]);
      else 
      { 
        //char *s1,*s2,*s3;
        int j,L2=strlen(B);
        //char c[2];
        j=i;
        //s3=(char*)malloc(sizeof(char)*MAX);
        //s1=(char*)malloc(sizeof(char)*MAX);
        //s3=(char*)malloc(sizeof(char)*MAX);       
        for(k=0;k<L-j+L2;k++)
          s3[k]='9';
        s3[L-j+L2]='\0';
        for(;i<L;i++)
        {
          s1[i-j]=A[i];
          s1[i-j+1]='\0';
          //s2=(char*)malloc(sizeof(char)*MAX);
          strcpy(s2,s1);
          strcat(s2,B);
          if( strcmp(s3,s2) > 0)
          {
            //free(s3);
            strcpy(s3,s2);
          }
        }
        L=strlen(s3)-strlen(B)-j;
        printf("%s%s\n",s3,A+L);
        flag=1;
        break;
      }
    }
    if(flag)
      continue;
    printf("%s",B);
    for(;i<L;i++)
      printf("%c",A[i]);
    printf("\n");
  }
  return 0;
}