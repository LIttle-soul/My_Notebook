## 筛质数

### 埃氏筛法(埃拉托斯特尼筛法)

```c++
const int N = 1e7;//筛的范围
bool st[N + 10];//判断是否为质数 初始为false false为质数 true为非质数
int save[N + 10], idx = 0;//用来存储质数
st[0] = st[1] = true; 
for (int i = 2; i <= N; i ++ ){
	if (!st[i]) save[idx ++ ] = i;
	else continue;//优化循环节省时间
	for (int j = i * 2; j <= N; j += i )
		st[j] = true;
}
idx --;
```

### 线性筛法(欧拉筛法)

```c++
const int N = 1e7;//筛要的范围
bool st[N + 10];//判断是否为质数 初始为false false为质数 true为非质数
int save[N + 10], idx = 0;//用来存储质数
a[0] = a[1] = true; 
for (int i = 2; i <= N; i ++ ){
	if (!st[i]) save[idx ++ ] = i;
	for (int j = 0; save[j] * i <= N; j ++ ){
        st[save[j]*i] = true;
        if (i % save[j] == 0) break;//优化循环节省时间 每个数只删一次
    }
		
}
idx --;
```

# 博弈论详解

## 一. 巴什博奕（Bash Game）
> 只有一堆n个物品， 两人轮流从这堆物品中取物，规定每次至少取一个，最多取m个。最后取光者得胜。

```c++
#include<bits/stdc++.h>
#define _MAX 10000
using namespace std;

int a[_MAX], b[_MAX];

int bash(int N, int K){
	if(N % (K + 1) == 0){
		return 2;
	}
	return 1;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int i = 0; i < T; i++){
		scanf("%d%d", a + i, b + i);
	}
	for(int i = 0; i < T; i++){
		if(bash(a[i], b[i]) == 1){
			puts("A");
		}else{
			puts("B");
		}
	}
	return 0;
}

```

## 二. 威佐夫博弈（Wythoff Game）
> 有两堆各若干个物品，两个人轮流从某一堆或同时从两堆中取同样多的物品，规定每次至少取一个，多者不限，最后取光者得胜。

```c++
#include<bits/stdc++.h>
using namespace std;

int main(){
	int t, a, b, m, k;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &a, &b);
        if(a > b){
            a ^= b;
            b ^= a;
            a ^= b;
        }
        m = b - a;
        k = (int)(m * (1 + sqrt(5)) / 2.0);
        printf("%s\n", a == k ? "B" : "A");
    }
	return 0;
}
```

## 三. 尼姆博弈（Nimm Game）
> 有三堆各若干个物品，两个人轮流从某一堆取任意多的物品，规定每次至少取一个，多者不限，最后取光者获胜。

```c++
#include<bits/stdc++.h>
using namespace std;

int main(){
	int N, stone, tag = 0;
    scanf("%d", &N);
    while(N--){
        scanf("%d", &stone);
        tag ^= stone;
    }
    printf("%c\n", tag == 0 ? 'B' : 'A');
	return 0;
}
```

## 四. SG函数

- SG打表
```c++
const int MAX_DIG = 64;

int f[MAX_DIG];         // 可以取走的石子个数
int sg[MAX_DIG];        // 0~n的SG函数值
int has[MAX_DIG];       // mex{}

void getSG(int n){
    memset(sg, 0, sizeof(sg));
    for(int i = 1; i <= n; i++){
        memset(has,0,sizeof(has));
        for(int j = 1; f[j] <= i; j++){
            has[sg[i - f[j]]] = 1;
        }
        for(int j = 0; j <= n; j++){        // 求mes{}中未出现的最小的非负整数
            if(has[j] == 0){
                sg[i] = j;
                break;
            }
        }
    }
}
```

- SG DFS
```c++
const int MAX_DIG = 64;

// DFS
// 注意S数组要按从小到大排序SG函数要初始化为-1 对于每个集合只需初始化1遍
// n是集合s的大小S[i]是定义的特殊取法规则数组
int s[MAX_DIG];
int sg[MAX_DIG * 100];
int n;

int SG_dfs(int x){
    if(sg[x] != -1){
        return sg[x];
    }
    bool vis[MAX_DIG];
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n; i++){
        if(x >= s[i]){
            SG_dfs(x - s[i]);
            vis[sg[x - s[i]]] = 1;
        }
    }
    int e;
    for(int i = 0;;i++){
        if(!vis[i]){
            e = i;
            break;
        }
    }
    return sg[x] = e;
}
```