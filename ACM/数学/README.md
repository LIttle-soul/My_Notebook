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

