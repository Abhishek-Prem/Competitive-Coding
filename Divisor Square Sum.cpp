#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int sumOfSquaresOfDivisors(int n) {
    int i, sum = 0;
    for(i=1; i<=sqrt(n); i++) {
			if(n%i==0) {
				sum += i*i;
				if(i!=(n/i)) sum += (n/i)*(n/i);
			}
		}
		return sum;
}

bool isAtmostKAway(int sum, int K) {
	int small = floor(sqrt(sum));
	int large = ceil(sqrt(sum));
	int nearestSmallSquare = small * small;
	int nearestLargeSquare = large * large;
	if(abs(sum - nearestSmallSquare)<=K || abs(sum - nearestLargeSquare)<=K)
		return true;
	return false;
}

int main() {
    int q, N, K;
		int i;
    cin>>q;
    while(q--) {
			cin>>N>>K;
			int finalSum = 0;
			for(i=1; i<=N; i++) {
				if(isAtmostKAway(sumOfSquaresOfDivisors(i), K))
					finalSum += i;
			}
			cout<<finalSum<<endl;
		}
		return 0;
}
