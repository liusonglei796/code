#include<stdio.h>
#include<stdlib.h>
int main(){
char c;
    int n;
    scanf("%c",&c);
    scanf("%d",&n);
char**str=(char**)malloc(n*sizeof(char*));
    for(int i=0;i<n;++i){
        str[i]=(char*)malloc(n*sizeof(char));
    }
for(int i=0;i<n;++i){
    for(int j=0;j<n;++j){
        scanf("%c",&str[i][j]);
    }
}
    int flag=0;
    for(int i=0;i<n/2;++i){
for(int j=0;j<n;++j){
    if(str[i][j]!=str[n-1-i][j]){
        flag=1;
    }
}
    }
       for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(str[i][j]=='@'){
                    str[i][j]=c;
                }
            }
        }
    if(!flag){
printf("buyongdaole\n");
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
              printf("%c"，str[i][j]);
            }
            printf("\n");
        }
    }
else{
for(int i=n-1;i>=0;++i){
    for(int j=0;j<n;++j){
        printf("%c",str[i][j]);
    }
    printf("\n");
}
}

    
}
    return 0;
}