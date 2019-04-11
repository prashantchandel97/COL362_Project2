#include "errors.h"
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
		num=(i/4)+(q-1)*4088
	memcpy (&data[i], &num, sizeof(int));
	i+=4
	}
	if(i==4088)
	{
	memcpy (&data[i], &xyz, sizeof(int));
	}
	// Flush the page
	fh.FlushPage(q);
	q++;
	cout << "Data written and flushed" << endl;
}
	// Close the file
	fm.CloseFile(fh);
}
