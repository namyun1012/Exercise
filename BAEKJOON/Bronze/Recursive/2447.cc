#include <iostream>


void star(int N, int x, int y) {
	if( N == 1 ) {
		std::cout << "*";
		return ;
	}
	// x, y값이 N 초과시 보정
	if(x > N) x = x % N;
	if(y > N) y = y % N;
	if (x == 0) x = N;
	if(y == 0) y == N;

	// 왠만하면 정수로 처리
	if(x > (N/3) && y > (N/3) && x <= 2*(N/3) && y <= 2*(N/3) ) {
		std::cout << " ";
		return ;

	}

	star(N/3, x, y);

}

int main() {
	int N;
	std::cin >> N;
	for(int j = 1; j <= N; j++) {
		for(int i =1 ; i <= N; i++) {
			star(N, i ,j);
		}
		std::cout << "\n";

	}
	

}
