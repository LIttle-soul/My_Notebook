/* Problem A. Chess Game
Time limit: 1000ms
Memory limit: 256mb

Description:

Suzukaze and Yukikaze are playing an interesting chess game.
In an infinite two-dimensional plane, there are two chess pieces A, B, whose coordinates are (xA, yA), (xB, yB). Now, Suzukaze wants to move the two pieces into the same coordinate. He can move the piece A in four directions(up, down, left and right) one unit in one turn, which means:
1. Move the chess up one unit:  (xA, yA)->(xA, yA+1)；
2. Move the chess down one unit:  (xA, yA)->(xA, yA-1)；
3. Move the chess left one unit:  (xA, yA)->(xA-1, yA)；
4. Move the chess right one unit:  (xA, yA)->(xA+1, yA)。
But Yukikaze, as Suzukaze's nemesis, doesn't want him to win easily. Therefore, every time Suzukaze moves one step, Yukikaze can choose an arbitary coordinate except the coordinate of the current chess piece A and B, and cover it with a superglue. If the chess piece moves to this coordinate which covered by a superglue, it will be stucked and can't move on. Does Suzukaze have a winning strategy?

Input:

The first line contains one integer T - the number of test cases.
Each test case consists of a single line containing four integers xA, yA, xB, yB - the coordinates of chess pieces A and B. It is guaranteed that the coordinates of A and B do not overlap.
1<=T<=10000
1<=xA, xB, yA, yB<=10

Output:

For each test case, print one line. If Suzukaze must win, then output Suzukaze, if Yukikaze must win, then output Yukikaze.

Sample Input:

3
1 1 2 1
1 1 2 2
1 1 3 3

Sample Output:

Suzukaze
Suzukaze
Yukikaze

Hint:

Suzukaze can only move chess piece A.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int x = abs(x2 - x1);
        int y = abs(y2 - y1);
        if((x <= 2 && y < 2) || (x < 2 && y <= 2)){
            cout << "Suzukaze" << endl;
        } else {
            cout << "Yukikaze" << endl;
        }
    }
    return 0;
}