# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main(){
    char k[101];
    char op[101];
    int num[101];
    gets(k);
    int len=strlen(k);
    int rear1=1,rear2=0;
    num[0]=k[0]-'0';
    for(int i=1;i<len;i+=2){
        int a=k[i+1]-'0';
        char b=k[i];
        if(b=='*'){
            int t=num[--rear1];
            num[rear1++]=t*a;
        }
        else if(b=='/'){
            int t=num[--rear1];
            num[rear1++]=t/a;
        }
        else{
            num[rear1++]=a;
            op[rear2++]=b;
        }
    }
    int ans=num[0];
    for(int i=0;i<rear2;i++){
        if(op[i]=='+'){
            ans+=num[i+1];
        }
        else if(op[i]=='-'){
            ans-=num[i+1];
        }
    }
    printf("%d\n",ans);
    return 0;
}