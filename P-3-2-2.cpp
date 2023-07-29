# include <bits/stdc++.h>
using namespace std;

int main(){
    char in[210],ch[7]="([{)]}";
    int s[210],top; // stack
    while(scanf("%s",in)!=EOF){
        top=-1; // clear stack
        int len=strlen(in);
        bool error=false;
        for(int i=0;i<len;i++){
            int k=strchr(ch,in[i])-ch;   // determine position of in[i] in ch[7]
            if(k<3) s[++top]=k;
            else{
                if(top<0 || k!=s[top]+3){
                    error=true;
                    break;
                }
                top--;
            }
        }
        if (top>=0) error=true;
        printf((error)?"no\n":"yes\n");
    }
    return 0;
}