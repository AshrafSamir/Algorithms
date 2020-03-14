// GROUP:   CS_1
// ID:      20170053
// Assign:  04
// Assign:  CountInv
// UVA:     10810
// Name:    Ashraf samir ali abdelhafez

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

long long CountInvMerge(long long* a, int n);
long long CountInv(long long* a, int n);
long long _mergeSort(long long* a, long long* temp, int left, int right);
long long myMerge(long long* a, long long* temp, int left,int mid , int right);

void printArr(long long* arr, int siz) {
	for (int i = 0; i < siz; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    long long c = 0;
    vector<long long> ans;
    int n=1,n1;
    while(true){

        cin>>n;
        if(n==0)break;
        c++;
        long long *a = new long long[n];
        for(int i=0;i<n;i++){
          cin>>n1;
          a[i] = n1;
        }
        ans.push_back(CountInvMerge(a, n));
        //printArr(a,n);
    }
    for( int i=0;i<c;i++){
        cout<<ans[i]<<endl;
    }

	return 0;
}

long long CountInv(long long* a, int n){

    long long invCount = 0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                invCount++;
            }
        }
    }
    return invCount;
}

long long CountInvMerge(long long* a, int n){

    long long *temp = new long long[n] ;
    return _mergeSort(a, temp, 0, n-1);

}

long long _mergeSort(long long* a, long long* temp, int left, int right){

    int mid;
    long long  invCount = 0;

    if(right > left){

        mid = (left+right)/2;

        invCount += _mergeSort(a, temp, left, mid);
        invCount += _mergeSort(a, temp, mid+1, right);

        invCount += myMerge(a, temp, left, mid+1, right);
    }

    return invCount;
}

long long myMerge(long long* a, long long* temp, int left,int mid , int right){

    int i, j, k;
    long long invCount = 0;

    i = left;
    j = mid;
    k = left;

    while((i<=mid-1)&&(j<=right)){
        if(a[i] <= a[j]){
            temp[k++] = a[i++];
        }
        else{
            temp[k++] = a[j++];
            invCount = invCount + (mid-i);
        }
    }

    while(i<=(mid-1))temp[k++] = a[i++];
    while(j<=(right))temp[k++] = a[j++];
    for(int i=left;i<=right;i++)a[i] = temp[i];

    return invCount;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////
