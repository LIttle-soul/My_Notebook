/* Problem B. Bracket Matching
Time limit: 1000ms
Memory limit: 256mb

Description:

We all know that a bracket sequence is made up of left brackets and right brackets, and Lecxcy has a bracket sequence which was created in 1982. The sequence is even older than Lecxcy, so some brackets have already blurred. We use asterisks to replace them.
Now Lecxcy only knows that the sequence he has is a valid bracket sequence, and each blurred bracket could only be one of a left bracket, a right bracket and null.
Lecxcy wants to figure out how many sequences can possibly be the original sequence.
Note that a valid bracket sequence should satisfy the following conditions:
1. Null is a valid bracket sequence.
2. If X and Y are valid bracket sequences, then XY  is also a valid bracket sequence.
3. If X is a valid bracket sequence, then (X) is also a valid bracket sequence.

Input:

One line with a string s (no more than 3100 characters) which only contains left brackets, right brackets and asterisks.

Output:

Print one integer, representing the number of valid sequences mod 1000000007. 

Sample Input 1:

()(()())

Sample Output 1:

1

Sample Input 2:

***

Sample Output 2:

4

Hint:

We use X to represent a null character.
Sample input 1 is a valid bracket sequence itself.
Four answers of sample input 2 are: XXX, ()X, (X), X().
*/

#include<bits/stdc++.h>
using namespace std;

const int64_t mod = 1e9+7;
char s[3010];
int64_t dp[3010][3010];

int main(){
    scanf("%s",s);
    int n = strlen(s);
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        if(s[i - 1] == '*'){
            for(int j = 0; j <= n; j++){
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1])%mod;
            }
        } else if (s[i-1]=='(') {
            for(int j = 0; j <= n; j++){
                dp[i][j] = dp[i-1][j-1];
            }
        } else {
            for(int j = 0; j <= n; j++){
                dp[i][j] = dp[i-1][j+1];
            }
        }
    }
    printf("%lld\n", dp[n][0]);
    return 0;
}