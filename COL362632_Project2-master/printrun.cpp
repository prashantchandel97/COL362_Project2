//Sample file for students to get their code running
#include<bits/stdc++.h>
#include "file_manager.h"
#include "errors.h"
#include<cstring>

using namespace std;
int main() {
	FileManager fm;
	int num = 5;
	FileHandler fh = fm.OpenFile ("./testcases/merge_sort/sort_input2.txt");
	// FileHandler fh = fm.OpenFile ("./testcases/merge_sort/sort_input1.txt");
	cout << "File opened" << endl;
	int q=0;
	PageHandler ph = fh.PageAt (q);
	while(q!=-1)
	{
	char *data;
	data = ph.GetData ();
	cout<<ph.GetPageNum ()<<"\n";
	int i=0;
	// int *ptr=arr;
	while(num!=INT_MIN &&i!=4092 ){
	// memcpy (&arr[i/4], &data[i], sizeof(int));
	memcpy (&num, &data[i], sizeof(int));
	if(num!=INT_MIN)
	// if(arr[i/4]!=INT_MIN)
	cout <<i/4+1<< "th number: "<<num<< endl;
	i+=4;
}
try{
	ph=fh.NextPage(q);
}
catch(...)
{
// 	cout<<"Error caught\n";
	break;
}
q++;}}
