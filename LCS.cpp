#include<bits/stdc++.h>
using namespace std;
int main() {
    string first,second;
    cin >> first >> second;
    int length1 = first.length();
    int length2 = second.length();
    int answer[length1 + 1][length2 + 2];
    for(int i=0; i<length1 + 1; i++) {
        answer[i][0] = 0;
    }
    for(int i=0; i<= length2; i++) {
        answer[0][i] = 0;
    }
    for(int i=1; i<= length1; i++) {
        for(int j = 1; j <= length2; j++) {
            if(first[i-1] == second[j-1]) {
                answer[i][j] = answer[i-1][j-1] +1;
            }
            else {
                answer[i][j] = max(answer[i][j-1], answer[i-1][j]);
            }
        }
    }
    cout << answer[length1][length2];
    return 0;
}
