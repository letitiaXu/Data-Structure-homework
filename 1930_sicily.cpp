//选择排序
#include <iostream>
using namespace std;
int main() {
	int t,n,times;
	int a[100];
	cin >> t;
	while(t --) {
		cin >> n;
		times = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			int k = i;
			for(int j = i + 1; j < n; j++) {
				if (a[k] > a[j]){
					if(k < j) {
						times++;
					}
					k = j;
				}
			}
			if(k!=i){
				int temp = a[k];
				a[k] = a[i];
				a[i] = temp;
			}
		}
		cout << times<<endl;
	}
	return 0;
}
