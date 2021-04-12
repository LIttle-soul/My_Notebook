/* Problem C. Compare(Easy Version)
Time limit: 1000ms
Memory limit: 256mb

Description:

You just need to compare the values of a+b and c!

Input:

Thr first line contains a positive integer T - represent the number of data groups.
Then following T lines, each line contains three positive integers a, b, c.
1<=T<=50
1<=a, b, c<=100

Output:

For each testcase output one line, and for three different cases output respectively:
1. a+b<c, output small;
2. a+b=c, output equal;
3. a+b>c, output big.

Sample Input:

3 
2 3 4 
2 3 6 
1 16 17

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
        int a, b, c;
        cin >> a >> b >> c;
        if(a + b > c){
            cout << "big" << endl;
        }else if(a + b < c){
            cout << "small" << endl;
        }else{
            cout << "equal" << endl;
        }
    }
    return 0;
}