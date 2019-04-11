//Sample file for students to get their code running
#include<bits/stdc++.h>
#include "file_manager.h"
#include "errors.h"
#include<cstring>

using namespace std;

typedef pair<int, pair<int, int> > ppi;

// This function takes an array of arrays as an
// argument and all arrays are assumed to be
// sorted. It merges them together and prints
// the final sorted output.
vector<int> mergeKArrays(vector<vector<int> > arr,int size)
{
    vector<int> output;

    // Create a min heap with k heap nodes. Every
    // heap node has first element of an array
    priority_queue<ppi, vector<ppi>, greater<ppi> > pq;

    for (int i = 0; i < size; i++)
        pq.push({ arr[i][0], { i, 0 } });

    // Now one by one get the minimum element
    // from min heap and replace it with next
    // element of its array
    while (pq.empty() == false) {
        ppi curr = pq.top();
        pq.pop();

        // i ==> Array Number
        // j ==> Index in the array number
        int i = curr.second.first;
        int j = curr.second.second;

        output.push_back(curr.first);

        // The next element belongs to same array as
        // current.
        if (j + 1 < arr[i].size())
            pq.push({ arr[i][j + 1], { i, j + 1 } });
    }

    return output;
}


int main() {
	FileManager fm;
	int num = 5;
	FileHandler fh = fm.OpenFile ("./testcases/merge_sort/sort_input2.txt");
	cout << "File opened" << endl;
	int q=0;
	PageHandler ph = fh.PageAt (q);
	while(q!=-1)
	{
	char *data;
  data = ph.GetData ();
	cout<<ph.GetPageNum ()<<"\n";
	int i=0;
	int arr[1024];
	// int *ptr=arr;
  while(num!=INT_MIN &&i!=3680 ){
	// memcpy (&arr[i/4], &data[i], sizeof(int));
	memcpy (&num, &data[i], sizeof(int));
	if(num!=INT_MIN)
	arr[i/4]=num;
	if(arr[i/4]!=INT_MIN)
	cout <<i/4+1<< "th number: " <<arr[i/4] <<" "<<num<< endl;
	i+=4;
}
