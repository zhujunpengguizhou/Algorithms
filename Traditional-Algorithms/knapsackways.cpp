/**
有 N 件物品和一个容量是 V 的背包。每件物品只能使用一次。
第 i 件物品的体积是 vi，价值是 wi。
求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
输出 字典序最小的方案。这里的字典序是指：所选物品的编号所构成的序列。物品的编号范围是 1…N。
输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品数量和背包容积。
接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i 件物品的体积和价值。
输出格式
输出一行，包含若干个用空格隔开的整数，表示最优解中所选物品的编号序列，且该编号序列的字典序最小。
物品编号范围是 1…N。
数据范围
0<N,V≤1000
0<vi,wi≤1000
输入样例
4 5
1 2
2 4
3 4
4 6
输出样例：
1 4
*/

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1010;
int v[N], w[N];
int f[N][N];
int n, m;

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d%d", &v[i], &w[i]);
    for(int i = n; i >= 1; i--){   //一定要注意，这里是从大到小搜索
        for(int j = m; j >= 0; j--){
            f[i][j] = f[i+1][j];
            if(j >= v[i]) f[i][j] = max(f[i][j], f[i+1][j-v[i]] + w[i]);
        }
    }
    
    int j = m;
    for(int i = 1; i <= n; i++){  //从小到大求解结果
        if(j >= v[i] && f[i][j] == f[i+1][j-v[i]]+w[i]){
            cout << i << ' ';
            j -= v[i];
        }
    }
    return 0;
}