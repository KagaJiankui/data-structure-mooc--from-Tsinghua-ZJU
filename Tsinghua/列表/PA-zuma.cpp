#include<iostream>
using namespace std;
int main() {
	string zuma;
	getline(cin,zuma);
	int n;
	cin>>n;
	for(int i=0; i<n; i++) {
		int t;
		char tmp;
		scanf("%d %c",&t,&tmp);
		zuma.insert(t,1,tmp);
		int cnt = 1;
		if(zuma.length()<3) {
			if(zuma.length()==0) {
				cout<<"-"<<endl;
			} else
				cout<<zuma<<endl;
		} else {
			for(int j=zuma.length()-1; j>=2&&zuma.length()>=3; j--) {
				cnt = 1;
				for(int q = j-1; q>=0; q--) {
					if(zuma[q]==zuma[j]) cnt++;
					else break;
				}
				if(cnt>=3) {
					zuma.erase(j-cnt+1,cnt);
				}
			}
			if(zuma.empty()) {
				cout<<"-"<<endl;
			} else
				cout<<zuma<<endl;
		}
	}
}
