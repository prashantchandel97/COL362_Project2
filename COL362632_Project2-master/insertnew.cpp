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
  {
	arr[i/4]=num;
  i+=4;
}
else
break;
	// if(arr[i/4]!=INT_MIN)
	// cout <<i/4+1<< "th number: " <<arr[i/4] <<" "<<num<< endl;

}
int len=i/4;
sort(arr, arr+len);
string str="temp"+to_string(q)+".txt";
char char_array[str.length()+1];
strcpy(char_array,str.c_str());
FileHandler fx = fm.CreateFile(char_array);
cout << "File created " << endl;
int ii=0;
PageHandler pt=fx.NewPage();
char *data1=pt.GetData();
while(ii!=i)
{
		memcpy (&data1[ii], &arr[ii/4], sizeof(int));//write int_min
		ii+=4;
}
if(ii=i){int temp=INT_MIN;
memcpy (&data1[ii], &temp, sizeof(int));}
// fx.DisposePage(q);
// cout<<"1\n";
// fm.PrintBuffer();
// fx.MarkDirty(q);
fx.FlushPage(q);
// fx.DisposePage(q);
// cout<<"2\n";
// fm.PrintBuffer();
fm.CloseFile(fx);
try{
	ph=fh.NextPage(q);
}
catch(...)
{
// 	cout<<"Error caught\n";
	break;
}
q++;}
fm.PrintBuffer();
fm.CloseFile (fh);
fm.ClearBuffer();
fm.PrintBuffer();
	// fm.DestroyFile ("temp.txt");
	q++;//check once for 0 page case
	int q2=0;
  FileHandler fh1[40];
	PageHandler ph1[40];//check the size once
	char *data1[40];
	// int arr1[1024][40];

  if(q<40)
  {
    vector<vector<int> > arr1(40,vector <int>(0,0));
	while(q2!=q)
	{
		 string str1="temp"+to_string(q2)+".txt";
		char char_array1[str1.length()+1];
		strcpy(char_array1,str1.c_str());
    fh1[q2]=fm.OpenFile(char_array1);
		cout<<"File opened "<< str1<<"\n";
    int pageiter=0;
    while(pageiter!=-1)
    {
        		ph1[q2]=fh1[q2].PageAt(pageiter);
        		data1[q2]=ph1[q2].GetData();
        		int i=0;
        		num=1;
        		// cout<<"huehue1\n";
        		while(num!=INT_MIN){//check if int_min being inserted
        		// memcpy (&arr[i/4], &data[i], sizeof(int));
        		memcpy (&num, &data1[q2][i], sizeof(int));
        		if(num!=INT_MIN)
        		{
        		// cout<<"huehue\n";
        		arr1[q2].push_back(num);
        		// if(q2==0)
        		// cout<<arr1[q2][i/4]<<" "<<num<<"\n";
        	  }
        		// if(arr[i/4]!=INT_MIN)
        		// cout <<i/4+1<< "th number: " <<arr[i/4] <<" "<<num<< endl;
        		i+=4;
        	}
          try
          {
            	ph1[q2]=fh1[q2].NextPage(pageiter);
          }
          catch(...)
          {
            break;
          }
          pageiter++;
  }
		q2++;
	}
	 // mergeKArrays(arr1);;
		vector<int> output=mergeKArrays(arr1,q2);
		// cout<<arr1.size()<<q2;
	fm.PrintBuffer();
	q2=0;
  while(q2!=q)
	{
		string str1="temp"+to_string(q2)+".txt";
	 char char_array1[str1.length()+1];
	 strcpy(char_array1,str1.c_str());
		fm.DestroyFile(char_array1);
		q2++;
	}


  FileHandler fh2 = fm.CreateFile("output.txt");
  cout << "File created " << endl;

  // Create a new page
    cout<<"output.size()"<<" "<<output.size()<<"\n";
    int j=0,i=0;
    q=0;
    while(j<output.size() )
    {
      i=0;
      PageHandler ph2 = fh2.NewPage ();
      char *data2 = ph2.GetData ();
    while(i!=4088)
    {
    //cout<<num<<"\n";
    if(j<output.size())
    memcpy (&data2[i], &output[j], sizeof(int));
    else
    {
    int huehue=INT_MIN;
    memcpy (&data2[i], &huehue, sizeof(int));
    break;//check for edgecase
  }i+=4;
    j++;
    }
    if(i==4088)
    {
      int huehue=INT_MIN;
      memcpy (&data2[i], &huehue, sizeof(int));
    }
    cout<<"j-"<<j<<"\n";
    fh2.FlushPage(q);
  }
    fm.CloseFile(fh2);
}
//215-516
else
{
  int quant;
  int times=(int)ceil(q/39);
  while(times!=1)
  {
                  for(int iter=0;iter<times;iter++)
                  {
                    if(iter<times-1)
                    {
                      int q2=0;
                      vector<vector<int> > arr1(40,vector <int>(0,0));
                      while(q2!=39)
                    	{
                    		 string str1="temp"+to_string(iter*39+q2)+".txt";
                    		char char_array1[str1.length()+1];
                    		strcpy(char_array1,str1.c_str());
                        fh1[q2]=fm.OpenFile(char_array1);
                    		cout<<"File opened "<< str1<<"\n";
                        int pageiter=0;
                        while(pageiter!=-1)
                        {
                            		ph1[q2]=fh1[q2].PageAt(pageiter);
                            		data1[q2]=ph1[q2].GetData();
                            		int i=0;
                            		num=1;
                            		// cout<<"huehue1\n";
                            		while(num!=INT_MIN){//check if int_min being inserted
                            		// memcpy (&arr[i/4], &data[i], sizeof(int));
                            		memcpy (&num, &data1[q2][i], sizeof(int));
                            		if(num!=INT_MIN)
                            		{
                            		// cout<<"huehue\n";
                            		arr1[q2].push_back(num);
                            		// if(q2==0)
                            		// cout<<arr1[q2][i/4]<<" "<<num<<"\n";
                            	  }
                            		// if(arr[i/4]!=INT_MIN)
                            		// cout <<i/4+1<< "th number: " <<arr[i/4] <<" "<<num<< endl;
                            		i+=4;
                            	}
                              try
                              {
                                	ph1[q2]=fh1[q2].NextPage(pageiter);
                              }
                              catch(...)
                              {
                                break;
                              }
                              pageiter++;
                      }
                    		q2++;
                    	}
                    	 // mergeKArrays(arr1);;
                    		vector<int> output=mergeKArrays(arr1,q2);
                    		// cout<<arr1.size()<<q2;
                        q2=0;
                    	fm.PrintBuffer();
                      while(q2!=39)
                    	{
                    		string str1="temp"+to_string(iter*39+q2)+".txt";
                    	 char char_array1[str1.length()+1];
                    	 strcpy(char_array1,str1.c_str());
                    		fm.DestroyFile(char_array1);
                    		q2++;
                    	}
                      //write in temp iter

                      string str1="temp"+to_string(iter)+".txt";
                     char char_array1[str1.length()+1];
                     strcpy(char_array1,str1.c_str());
                      FileHandler fh2 = fm.CreateFile(char_array1);
                      cout << "File created " << endl;
                        // count++;
                      // Create a new page
                        cout<<"output.size()"<<" "<<output.size()<<"\n";
                        int j=0,i=0;
                        q=0;
                        while(j<output.size() )
                        {
                          i=0;
                          PageHandler ph2 = fh2.NewPage ();
                          char *data2 = ph2.GetData ();
                        while(i!=4088)
                        {
                        //cout<<num<<"\n";
                        if(j<output.size())
                        memcpy (&data2[i], &output[j], sizeof(int));
                        else
                        {
                        int huehue=INT_MIN;
                        memcpy (&data2[i], &huehue, sizeof(int));
                        break;//check for edgecase
                      }i+=4;
                        j++;
                        }
                        if(i==4088)
                        {
                        int huehue=INT_MIN;
                        memcpy (&data2[i], &huehue, sizeof(int));
                      }
                        cout<<"j-"<<j<<"\n";
                        fh2.FlushPage(q);
                      }
                        fm.CloseFile(fh2);
                        fm.ClearBuffer();
                     }
                     else if(iter==times-1)
                     {
                             int q2=0;
                             vector<vector<int> > arr1(40,vector <int>(0,0));
                             while(q2!=q-(times-1)*39)
                           	{
                           		 string str1="temp"+to_string(iter*39+q2)+".txt";
                           		char char_array1[str1.length()+1];
                           		strcpy(char_array1,str1.c_str());
                               fh1[q2]=fm.OpenFile(char_array1);
                           		cout<<"File opened "<< str1<<"\n";
                               int pageiter=0;
                               while(pageiter!=-1)
                               {
                                   		ph1[q2]=fh1[q2].PageAt(pageiter);
                                   		data1[q2]=ph1[q2].GetData();
                                   		int i=0;
                                   		num=1;
                                   		// cout<<"huehue1\n";
                                   		while(num!=INT_MIN){//check if int_min being inserted
                                   		// memcpy (&arr[i/4], &data[i], sizeof(int));
                                   		memcpy (&num, &data1[q2][i], sizeof(int));
                                   		if(num!=INT_MIN)
                                   		{
                                   		// cout<<"huehue\n";
                                   		arr1[q2].push_back(num);
                                   		// if(q2==0)
                                   		// cout<<arr1[q2][i/4]<<" "<<num<<"\n";
                                   	  }
                                   		// if(arr[i/4]!=INT_MIN)
                                   		// cout <<i/4+1<< "th number: " <<arr[i/4] <<" "<<num<< endl;
                                   		i+=4;
                                   	}
                                     try
                                     {
                                       	ph1[q2]=fh1[q2].NextPage(pageiter);
                                     }
                                     catch(...)
                                     {
                                       break;
                                     }
                                     pageiter++;
                             }
                           		q2++;
                           	}
                           	 // mergeKArrays(arr1);;
                           		vector<int> output=mergeKArrays(arr1,q2);
                           		// cout<<arr1.size()<<q2;
                               q2=0;
                           	fm.PrintBuffer();
                             while(q2!=q-(times-1)*39)
                           	{
                           		string str1="temp"+to_string(iter*39+q2)+".txt";
                           	 char char_array1[str1.length()+1];
                           	 strcpy(char_array1,str1.c_str());
                           		fm.DestroyFile(char_array1);
                           		q2++;
                           	}
                             //write in temp iter

                             string str1="temp"+to_string(iter)+".txt";
                            char char_array1[str1.length()+1];
                            strcpy(char_array1,str1.c_str());
                             FileHandler fh2 = fm.CreateFile(char_array1);
                             cout << "File created " << endl;
                               // count++;
                             // Create a new page
                               cout<<"output.size()"<<" "<<output.size()<<"\n";
                               int j=0,i=0;
                               q=0;
                               while(j<output.size() )
                               {
                                 i=0;
                                 PageHandler ph2 = fh2.NewPage ();
                                 char *data2 = ph2.GetData ();
                               while(i!=4088)
                               {
                               //cout<<num<<"\n";
                               if(j<output.size())
                               memcpy (&data2[i], &output[j], sizeof(int));
                               else
                               {
                               int huehue=INT_MIN;
                               memcpy (&data2[i], &huehue, sizeof(int));
                               break;//check for edgecase
                             }i+=4;
                               j++;
                               }
                               if(i==4088)
                               {
                               int huehue=INT_MIN;
                               memcpy (&data2[i], &huehue, sizeof(int));
                             }
                               cout<<"j-"<<j<<"\n";
                               fh2.FlushPage(q);
                             }
                               fm.CloseFile(fh2);
                               fm.ClearBuffer();
                               quant=iter+1;
                     }

                  }
                  times=(int)ceil((times+1)/39);
  }//when times=1 then 1 wala case
  vector<vector<int> > arr1(40,vector <int>(0,0));
  q2=0;
while(q2!=quant)
{
   string str1="temp"+to_string(q2)+".txt";
  char char_array1[str1.length()+1];
  strcpy(char_array1,str1.c_str());
  fh1[q2]=fm.OpenFile(char_array1);
  cout<<"File opened "<< str1<<"\n";
  int pageiter=0;
  while(pageiter!=-1)
  {
          ph1[q2]=fh1[q2].PageAt(pageiter);
          data1[q2]=ph1[q2].GetData();
          int i=0;
          num=1;
          // cout<<"huehue1\n";
          while(num!=INT_MIN){//check if int_min being inserted
          // memcpy (&arr[i/4], &data[i], sizeof(int));
          memcpy (&num, &data1[q2][i], sizeof(int));
          if(num!=INT_MIN)
          {
          // cout<<"huehue\n";
          arr1[q2].push_back(num);
          // if(q2==0)
          // cout<<arr1[q2][i/4]<<" "<<num<<"\n";
          }
          // if(arr[i/4]!=INT_MIN)
          // cout <<i/4+1<< "th number: " <<arr[i/4] <<" "<<num<< endl;
          i+=4;
        }
        try
        {
            ph1[q2]=fh1[q2].NextPage(pageiter);
        }
        catch(...)
        {
          break;
        }
        pageiter++;
}
  q2++;
}
 // mergeKArrays(arr1);;
  vector<int> output=mergeKArrays(arr1,q2);
  // cout<<arr1.size()<<q2;
fm.PrintBuffer();
q2=0;
while(q2!=quant)
{
  string str1="temp"+to_string(q2)+".txt";
 char char_array1[str1.length()+1];
 strcpy(char_array1,str1.c_str());
  fm.DestroyFile(char_array1);
  q2++;
}


FileHandler fh2 = fm.CreateFile("output.txt");
cout << "File created " << endl;

// Create a new page
  cout<<"output.size()"<<" "<<output.size()<<"\n";
  int j=0,i=0;
  q=0;
  while(j<output.size() )
  {
    i=0;
    PageHandler ph2 = fh2.NewPage ();
    char *data2 = ph2.GetData ();
  while(i!=4088)
  {
  //cout<<num<<"\n";
  if(j<output.size())
  memcpy (&data2[i], &output[j], sizeof(int));
  else
  {
  int huehue=INT_MIN;
  memcpy (&data2[i], &huehue, sizeof(int));
  break;//check for edgecase
}i+=4;
  j++;
  }
  if(i==4088)
  {
    int huehue=INT_MIN;
    memcpy (&data2[i], &huehue, sizeof(int));
  }
  cout<<"j-"<<j<<"\n";
  fh2.FlushPage(q);
}
  fm.CloseFile(fh2);

}
	// for (auto iterator = output.begin(); iterator != output.end(); ++iterator)
	//  		 cout << *iterator <<"\n";

  // if(j>output.size()-1)
  //   break;
  // else if(i==4096)
  // {
  //   ph2=fh2.NewPage();
  //   data2=ph.GetData();
  //   break
  // }

	// cout<<output.size()<<"\n";


  //displaying the output file
   FileHandler fh2 = fm.OpenFile ("output.txt");
  // FileHandler fh = fm.OpenFile ("./testcases/merge_sort/sort_input1.txt");
  cout << "File opened" << endl;
  q=0;
  PageHandler ph2 = fh2.PageAt (q);
  while(q!=-1)
  {
  char *data2;
  data2 = ph2.GetData ();
  cout<<ph2.GetPageNum ()<<"\n";
  int i=0;
  num=1;
  // int *ptr=arr;
  while(num!=INT_MIN &&i!=4092 ){
  // memcpy (&arr[i/4], &data[i], sizeof(int));
  memcpy (&num, &data2[i], sizeof(int));
  if(num!=INT_MIN)
  // if(arr[i/4]!=INT_MIN)
  cout <<i/4+1<< "th number: "<<num<< endl;
  i+=4;
  }
  try{
  ph2=fh2.NextPage(q);
  }
  catch(...)
  {
  // 	cout<<"Error caught\n";
  break;
  }
  q++;}
fm.CloseFile (fh2);
fm.DestroyFile ("output.txt");
}
