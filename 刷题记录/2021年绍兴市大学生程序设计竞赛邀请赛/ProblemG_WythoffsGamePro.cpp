/* Problem G. Wythoff's Game Pro
Time limit: 1000ms
Memory limit: 256mb

Description:

Smart Xiao Ming is eager to become a game master. When he saw the Wythoff's game, he thought it was too easy. After that, he created the Wythoff's game pro and played the game with Xiaohong.
The rule of Wythoff's game pro is：
There are three piles of stones, two players take turns. Each turn player can take any positive number of stones from one pile, or take the same positive number of stones from all of three piles. It's not allowed to take zero stones. The player who cannot take any stone lose (that means, the other player win).
In the game, Xiaoming always take first. Supposing that both players play optimally, who will win the game?

Input:

The first line contains a single integer T - the number of test cases.
The next T lines contains three integers a, b, c.
1<=T<=103
1<=a, b, c<=107

Output:

Print "xiaoming" (without quotes) if Xiaoming will win, or "xiaohong" (without quotes) if Xiaohong will win. Note the output characters are case-sensitive.

Sample Input:

5
1 1 1
3 2 1
2 3 4
10 20 30
9 6 3

Sample Output:

xiaoming
xiaohong
xiaoming
xiaohong
xiaoming
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n, ans = 0;
        for(int i = 1; i <= 3; i++){
            cin >> n;
            ans ^= n;
        }
        cout << (ans ? "xiaoming" : "xiaohong") << endl;
    }
    return 0;
}