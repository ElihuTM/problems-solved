#include <bits/stdc++.h>

using namespace std;

int main() {
	int player[2], score[2];
	score[0] = score[1] = 0;
	int current = 0, side = 1;

	cin >> player[0] >> player[1];	
	while(score[0] < 1000 && score[1]< 1000) {
		player[current]	= (player[current] + 3*side + 3) % 10;
	}
	return 0;
}
