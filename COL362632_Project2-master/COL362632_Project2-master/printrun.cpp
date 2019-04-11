


#include<bits/stdc++.h>
#include "errors.h"
 #include "file_manager.h"
#include<cstring>

using namespace std;


int main() {
	FileManager fm;
	int xyz=INT_MIN;
	// Create a brand new file
	FileHandler fh = fm.CreateFile("testcaseprashant.txt");
	cout << "File created " << endl;

int q=1;
	// Create a new page
	while(q!=45)
	{
	PageHandler ph = fh.NewPage ();
	char *data = ph.GetData ();

	// Store an integer at the very first location
	int num = 5;
	int i=0;
	while(i!=4088)
	{
		num=60000-(i/4)-(q-1)*1022;
	memcpy (&data[i], &num, sizeof(int));
	i+=4;
	}
	if(i==4088)
	{
	memcpy (&data[i], &xyz, sizeof(int));
	}
	// Flush the page
	cout << "Data written and flushed" << endl;
	fm.PrintBuffer();
	//fh.MarkDirty(q);
	//fh.UnpinPage(q);
	fh.MarkDirty(q);
	fh.FlushPages();
	fh.UnpinPage(q);
		q++;
		// if(q==40)
		// {
		// }
}
	// Close the file
	fm.CloseFile(fh);

 FileHandler fh2 = fm.OpenFile ("testcaseprashant.txt");
	// FileHandler fh = fm.OpenFile ("./testcases/merge_sort/sort_input1.txt");
	cout << "File opened" << endl;
	 q=0;
	PageHandler ph2 = fh2.PageAt (0);
	while(q!=-1)
	{
	char *data;
	data = ph2.GetData ();
	cout<<ph2.GetPageNum ()<<"\n";
	int i=0;
	int num=5;
	//int *ptr=arr;
	while(num!=INT_MIN  ){
	// memcpy (&arr[i/4], &data[i], sizeof(int))
	memcpy (&num, &data[i], sizeof(int));
	if(num!=INT_MIN)
	{
	cout <<i/4+1<< "th number: "<<num<< endl;
	i+=4;
}}
try{
	ph2=fh2.NextPage(q);
}
catch(...)
{
// 	cout<<"Error caught\n";
	break;
}
fh2.UnpinPage(q);
q++;
}
// fm.DestroyFile ("testcaseprashant.txt");
}
