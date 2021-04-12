/* Problem I. Meet in Another World, Enjoy Delicious
Time limit: 1000ms
Memory limit: 256mb

Description:

"Give him a two-dimensional Box!"
Xiao Ming recently heard that KFC is linked with his favorite game, so he went to queue to buy Genshin Box for N days ( N is an odd number). The event is extremely hot, but there is only one KFC in the city where Xiao Ming is located. The probability of him buying the Genshin Box successfully on the i day is pi. What is the probability that he can buy a Genshin Box successfully for more days than he can't in these n days.

Input:

The first line contains one integer N - the number of days.
The second line contains N floating numbers - the ith number represents the probability of him buying the Genshin Box successfully on the ith day.
1<=N<=2999 
0<pi<1

Output:

Output the probability that he can successfully buy a Genshin Box for more days than he can't in these n days. Output the probability with 3 digits after the decimal point.

Sample Input 1:

3
0.30 0.60 0.80

Sample Output 1:

0.612

Sample Input 2:

1
0.50

Sample Output 2:

0.500

Sample Input 3:

5
0.42 0.01 0.42 0.99 0.42

Sample Output 3:

0.382
*/

#include<bits/stdc++.h>
using namespace std;

double C[3005][3005] = {0}, p[3005];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> p[i];
    }
    for(int i = 0; i <= n; i++){
        C[i][0] = 1;
        for(int j = 1; j <= i; j++){
            C[i][j] = C[i - 1][j - 1] * p[i] + C[i - 1][j] * (1 - p[i]);
            // cout << i << "-" << j << ": " << C[i][j] << " \t";
        }
        // cout << endl;
    }
    // cout << C[n][(n+1)/2] <<endl;
    printf("%.3lf\n", C[n][(n+1)/2]);
    return 0;
}