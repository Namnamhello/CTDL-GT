#include <bits/stdc++.h>

using namespace std;

void swap(int &a,int &b){
	int x=a;
	a=b;
	b=x;
}

//NOi bot
void Sapxep(int a[], int n)
{
    for (int i = 0; i<n - 2; i++){
        for (int j = n - 1; j>i; j--){
            if (a[j] < a[j - 1]){
                int x=a[j];a[j]=a[j - 1];a[j - 1]=x;
            }
        }
	}
}

//Chen
void chen(int a[],int n){
	for(int i=1;i<n;i++){
		int t=i;
		while(t>=0){
			if(a[t]<a[t-1]){
				swap(a[t],a[t-1]);
				t-=1;
			}
			else{break;
			}
		}
		cout<<"B"<<i+1<<": ";
        for (int j=0;j<12;j++){
        	cout<<a[j]<<" ";
		} 
		cout<<endl;
	}
}

//inslection sort
void slection(int a[],int n){
	for(int i=0;i<n-1;i++){
		int min=a[i],vt=i;
		for(int j=i+1;j<n;j++){
			if (a[j]<min){
				min=a[j];vt=j;
			}
		}
		swap(a[i],a[vt]);
		cout<<"B"<<i+1<<": ";
        for (int j=0;j<12;j++){
        	cout<<a[j]<<" ";
		} 
		cout<<endl;
	}
}

int main(){
	int a[4]={15,30,201,303};
	int b[8]={5,7,10,27,98,121,204,308};
	int s_a=sizeof(a)/sizeof(a[0]),s_b=sizeof(b)/sizeof(b[0]);
	int x=s_a+s_b;
	int c[x],i=0,j=0,t=0;

	while(t<x){
		if (i<s_a&&j<s_b&&a[i]<b[j]){
			c[t]=a[i];t++;i++;
		}
		if(i<s_a&&j<s_b&&a[i]>b[j]){
			c[t]=b[j];t++;j++;
		}
		if (i==s_a){
			for(int n=j;n<s_b;n++){
				c[t]=b[n];t++;
			}
			break;
		}
		if (j==s_b){
			for(int n=i;n<s_b;n++){
				c[t]=a[n];t++;
			}
			break;
		}
	}
	for(int i=0;i<x;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}