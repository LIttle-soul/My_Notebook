- C/C++输入输出加速
```c++
ios::sync_with_stdio(false);
cin.tie(NULL);
const int maxn = 110;
const int INF = 0x3f3f3f3f;
```



# 1. 快读
```c++
inline int read(){
    int re=0,k=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-'){
            k=-1;
        }
        ch=getchar();
    }
    return re*k;
}
```
# 2. 快写
```c++
inline void write(int x){
    if(X<10){
        putchar(x+48);
        retrun;
    }
    write(x/10);
    write(x%10);
}
```

> __int128占16字节，可存的数据范围达到了long long的平方: $ 10^32 $，不能用cin，需要用手写快读快写（其实也可以用scanf和printf）
```c++
// 快读
__int128 read(){
    __int128 x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')f=-1;
    while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
    return f*x;
}
// 快写
void print(__int128 x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);//注意这里是x>9不是x>10 (2019.10 wa哭了回来标记一下)
    putchar(x%10+'0');
}
```