#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool searchMatrix(vector<vector<ll>>& matrix, ll target) {
	ll i = 0,j=matrix[i].size()-1;
	while(i<(ll)matrix.size() and j >=0){
		if(matrix[i][j]==target){
			return true;
		}else if(matrix[i][j]>target){
			j--;
		}else{
			i++;
		}
	}
	return false;
}

void solve(){
	vector<vector<ll>> matrix(3,vector<ll>(4,0));
	for(int i=0;i<3;++i){
		for(int j=0;j<4;++j){
			cin >> matrix[i][j];
		}
	}	
	cout <<searchMatrix(matrix,4)<<"\n";
}

int main(){
	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
}