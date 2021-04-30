#include<bits/stdc++.h>
using namespace std;

int main(){
    int ans1 = 0, ans2 = 0;
    for(int i = 0; i < 5; i++){
        int temp;
        cin >> temp;
        ans1 += temp;
    }
    for(int i = 0; i < 5; i++){
        int temp;
        cin >> temp;
        ans2 += temp;
    }
    if(ans1 >= ans2) puts("Blue");
    else puts("Red");
    return 0;
}
