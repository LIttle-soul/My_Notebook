/* Problem E. Compare(Hard Version)
Time limit: 1000ms
Memory limit: 256mb

Description:

You just need to compare the values of /sqrt(a) + /sqrt(b) and /sqrt(c)!

Input:

Thr first line contains a positive integer T - represent the number of data groups.
Then following T lines, each line contains three positive integers a, b, c.
1<=T<=50
1<=a, b, c<=10^9

Output:

For each testcase output one line, and for three different cases output respectively:
1. /sqrt(a) + /sqrt(b) < /sqrt(c), output small;
2. /sqrt(a) + /sqrt(b) = /sqrt(c), output equal;
3. /sqrt(a) + /sqrt(b) > /sqrt(c), output big.

Sample Input:

3 
2 3 9 
2 3 10 
1 16 25

Sample Output:

big
small
equal
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        double a, b, c;
        cin >> a >> b >> c;
        if(a + b + 2 * sqrt(a * b) > c){
            cout << "big" << endl;
        }else if(a + b + 2 * sqrt(a * b) < c){
            cout << "small" << endl;
        }else{
            cout << "equal" << endl;
        }
    }
    return 0;
}