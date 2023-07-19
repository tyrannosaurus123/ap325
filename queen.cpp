# include <bits/stdc++.h>
using namespace std;
# define int long long

int nq(int n){
    int p[14],total=0;
    for(int i=0;i<n;i++){   // 陣列的數字代表皇后在第i列的第幾行
        p[i]=i;
    }
    do{
        bool valid =true;
        for(int i=0;i<n;i++){       // 判斷每一列與後列皇后擺放位置是否為對角線
            for(int j=i+1;j<n;j++){
                if(abs(p[i]-p[j])==j-i){
                    valid=false;
                    break;
                }
            }
        }
        if(valid) total++;
    }while (next_permutation(p, p+n));
    return total;
}
signed main(){
    for (int i=1;i<12;i++){
        printf("%lld\n",nq(i));
    }
    return 0;
}