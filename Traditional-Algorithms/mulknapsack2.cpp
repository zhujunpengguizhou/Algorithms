/*  本题如果采用朴素做法，则时间复杂度为1000*1000*2000= 4000000000 40亿一定会TLE，因此只能采用下面的优化算法，将物品重新打包成N*logS大小的物品，将时间复杂度姜维1000*11*2000 < 1e9
有 N 种物品和一个容量是 V 的背包。
第 i 种物品最多有 si 件，每件体积是 vi，价值是 wi。
求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
输出最大价值。
输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品种数和背包容积。
接下来有 N 行，每行三个整数 vi,wi,si，用空格隔开，分别表示第 i 种物品的体积、价值和数量。
输出格式
输出一个整数，表示最大价值。

数据范围
0<N≤1000
0<V≤2000
0<vi,wi,si≤2000
提示：
本题考查多重背包的二进制优化方法。

输入样例
4 5
1 2 3
2 4 1
3 4 3
4 5 2
输出样例：
10
*/

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 15000;
int v[N], w[N];
int f[N]; // 表示体积小于等于j的最大价值
int n, m;
int main(){
    cin >> n >> m;
    
    int cnt = 0;   //打包物品
    for(int i = 1; i <= n; i++){
        int a, b, s;  // a表示物品的体积，b表示物品的价值，c表示物品的数量
        cin >> a >> b >> s;
        int k = 1;
        while(k <= s){
            cnt++;
            v[cnt] = a * k;
            w[cnt] = b * k;
            s -= k;
            k *= 2;
        }
        if(s > 0){
            cnt++;
            v[cnt] = a * s;
            w[cnt] = b * s;
        }
    }
    
    n = cnt;  //打包成了新的物品，做到了logs的优化
    //接着做一遍0-1背包问题即可
    for(int i = 1; i <= n; i++){
        for(int j = m; j >= v[i]; j--){
            f[j] = max(f[j], f[j-v[i]]+w[i]);
        }
    }
    printf("%d\n", f[m]);
    return 0;
}