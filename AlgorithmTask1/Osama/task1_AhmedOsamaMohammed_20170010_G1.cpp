#include <iostream>
#include <vector>
using namespace std;
/*void printArr(long long* arr, int siz) {
	for (int i = 0; i < siz; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;
}*/
long long merge(long long* arr, int start,int mid,int end) {
	//printArr(arr, start + end + 1);
	long long totalSwaps = 0;
	int leftArrSize = mid - start+1;
	int rightArrSize = end - mid;
	int* leftArr = new int[leftArrSize];
	int* rightArr = new int[rightArrSize];
	for (int i = 0; i < leftArrSize; i++)
		leftArr[i] = arr[start + i];
	for (int j = 0; j < rightArrSize; j++)
		rightArr[j] = arr[mid + 1 + j];
	int i = 0, j = 0,k=start;
	while (i < leftArrSize && j < rightArrSize) {
		if (leftArr[i] <= rightArr[j]) {
			arr[k] = leftArr[i];
			i++;
		}
		else {
			arr[k] = rightArr[j];
			j++;
			totalSwaps += leftArrSize-i;
			//cout << totalSwaps << " " << mid << " " << i<<";;"<<endl;
		}
		k++;
	}
	while (i < leftArrSize) {
		arr[k] = leftArr[i];
		k++;
		i++;
	}
	while (j < rightArrSize) {
		arr[k] = rightArr[j];
		k++;
		j++;
	}

	return totalSwaps;
}
long long _mergeSort(long long* arr, int start, int end) {
	long long totalSwaps = 0;
	if (start < end) {
		int mid = (start+end)/ 2;
		totalSwaps+=_mergeSort(arr, start, mid);
		totalSwaps+= _mergeSort(arr, mid + 1, end);
		totalSwaps+=merge(arr, start, mid, end);
	}
	return totalSwaps;

}
//-----------

int main() {
	vector <long long>output;
	while (true) {
		long long size = 0;
		cin >> size;
		if (size == 0)
			break;
		long long* arr = new long long[size];
		for (int i = 0; i < size; i++) {
			cin >> arr[i];
		}
		output.push_back(_mergeSort(arr, 0, size - 1));
	}
	for (auto i = output.begin(); i != output.end(); ++i)
		cout << *i <<endl;
	/*long long arr[] = {9,1,0};
	int siz = sizeof(arr) / sizeof(arr[0]);
	cout<<_mergeSort(arr, 0, siz-1 )<<endl;*/
	//printArr(arr,siz);
	return 0;
}
