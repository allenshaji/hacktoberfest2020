#include <iostream>
using namespace std;

void countingsort(int a[],int n,int k,int b[]){
	int c[k];
	int i;
	for(i=0;i<k;i++){
		c[i]=0;
	}
	for(i=0;i<n;i++){
		c[a[i]]++;
	}
	for(i=1;i<k;i++){
		c[i]=c[i]+c[i-1];
	}
	for(i=n-1;i>=0;i--){
		b[c[a[i]]-1]=a[i];
		c[a[i]]--;
	}
}


int main(){

	int a[] = {5,3,7,8,3,4,1,2,6,7,2,3,9,0,5,6,4,3,6,7 };
	int b[20];

	countingsort(a,20,10,b);

	for (int i = 0; i < 20; i++) {
			cout << b[i] << endl;
		}

	return 0;
}
