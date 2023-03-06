#include<bits/stdc++.h>

using namespace std;
int main(){
	int num, kil;
	map<int, int> all;
	cin>>num>>kil;
	for(int i = 1; i<=num; i++){
		all[i] = 1;
	}
	int current = kil - 1;
	int times = num;
	while(times!=0){
		if(all[current] == 0) current++;
		else if(current>=num) current = current%times;
		else {
			all[current] = 0;
			cout<<current+1<<'\n';
			times--;	
			current+=kil;	
		}

	}

}






