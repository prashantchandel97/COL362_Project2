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
	FileHandler fh = fm.OpenFile ("sort_input2.txt");
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
  num=1;
  while(num!=INT_MIN ){
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
fx.MarkDirty(q);
fx.FlushPages();
fx.UnpinPage(q);
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
fh.UnpinPage(q);
q++;
// if(q==40)
// {
//   for(int u=0;u<40;u++)
//   {
//
//   }
// }

}
fm.CloseFile (fh);
fm.ClearBuffer();
	// fm.DestroyFile ("temp.txt");
	q++;//check once for 0 page case
	int q2=0;
  FileHandler fh1[40];
	PageHandler ph1[40];//check the size once
	char *data1[40];
  int number_initial_runs=q;
	// int arr1[1024][40];

  if(q<40)
  {
	while(q2!=q)
	{
		 string str1="temp"+to_string(q2)+".txt";
		char char_array1[str1.length()+1];
		strcpy(char_array1,str1.c_str());
    fh1[q2]=fm.OpenFile(char_array1);
		cout<<"File opened "<< str1<<"\n";
    int pageiter=0;
    ph1[q2]=fh1[q2].PageAt(0);
    data1[q2]=ph1[q2].GetData();
    q2++;
  }
    num=1;
    priority_queue<ppi, vector<ppi>, greater<ppi> > pq;
    cout<<"q "<<q<<"\n";
   for (int i = 0; i < q; i++)
    {
        memcpy(&num,&data1[i][0],sizeof(int));
        cout<<"num-"<<num<<"\n";
        pq.push({ num, { i, 0 } });
    }
    FileHandler fh2 = fm.CreateFile("output.txt");
    cout << "File created " << endl;
    int output_position=0;
    PageHandler ph2=fh2.NewPage();
    char *data2=ph2.GetData();
    int pagenumber=0;
    while(pq.empty()==false)
    {
      ppi curr = pq.top();
      pq.pop();

      // i ==> Array Number
      // j ==> Index in the array number
      int i = curr.second.first;
      int j = curr.second.second;
      int tempallocation=curr.first;
      memcpy(&data2[output_position],&tempallocation,sizeof(int));
      cout<<tempallocation<<"\n";
      output_position+=4;
      if(output_position==4088)
      {
        int tempr=INT_MIN;
        memcpy(&data2[output_position],&tempr,sizeof(int));
        ph2=fh2.NewPage();
        // fh2.MarkDirty(pagenumber);
        // fh2.FlushPages();
        //  fh2.UnpinPage(pagenumber);
        output_position=0;
        data2=ph2.GetData();
        pagenumber++;
      }
      int checker=1;
      memcpy(&checker,&data1[i][(j+1)*4],sizeof(int));
      if (checker!=INT_MIN)
      {
        memcpy(&num,&data1[i][(j+1)*4],sizeof(int));
        pq.push({ num, { i, j+1 } });
      }
    }
	q2=0;
  while(q2!=q)
	{
		string str1="temp"+to_string(q2)+".txt";
	 char char_array1[str1.length()+1];
	 strcpy(char_array1,str1.c_str());
		fm.DestroyFile(char_array1);
		q2++;
	}
  fm.CloseFile(fh2);
}
//215-516
else
{
  int quant;
  cout<<"q-"<<number_initial_runs<<"\n";
  int times=(int)ceil(number_initial_runs/39.0);
  cout<<"times "<<times<<"\n";
  while(times>1)
  {
    cout<<"times-1 "<<times<<"\n";
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
                                cout<<"page numer "<<char_array1<<" ";
                            		data1[q2]=ph1[q2].GetData();
                                cout<<ph1[q2].GetPageNum()<<"\n";
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
                        int qp=0;
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
                        fh2.MarkDirty(qp);
                        fh2.FlushPages();
                        fh2.UnpinPage(qp);
                        q++;
                      }
                        fm.CloseFile(fh2);
                        fm.ClearBuffer();
                     }
                     else if(iter==times-1)
                     {
                             int q2=0;
                             cout<<"noofinitialrun-"<<number_initial_runs<<"\n";
                             vector<vector<int> > arr1(40,vector <int>(0,0));
                             while(q2!=number_initial_runs-(times-1)*39)
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
                             while(q2!=number_initial_runs-(times-1)*39)
                           	{
                           		string str1="temp"+to_string(iter*39+q2)+".txt";
                           	 char char_array1[str1.length()+1];
                           	 strcpy(char_array1,str1.c_str());
                           		fm.DestroyFile(char_array1);
                           		q2++;
                           	}
                            cout<<"here\n";
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
                               fh2.MarkDirty(q);
                               fh2.FlushPages();
                               fh2.UnpinPage(q);
                             }
                               fm.CloseFile(fh2);
                               fm.ClearBuffer();
                               quant=iter+1;
                     }

                  }
                  times=(int)ceil((times+1)/39.0);//reasonfor one?
  }//when times=1 then 1 wala case
  vector<vector<int> > arr1(40,vector <int>(0,0));
  q2=0;
  fm.ClearBuffer();
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
// fm.PrintBuffer();
q2=0;
while(q2!=quant)
{
  string str1="temp"+to_string(q2)+".txt";
 char char_array1[str1.length()+1];
 strcpy(char_array1,str1.c_str());
  fm.DestroyFile(char_array1);
  q2++;
}
fm.ClearBuffer();
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
  fh2.MarkDirty(q);
  fh2.FlushPages();
  fh2.UnpinPage(q);
  q++;
}
  fm.CloseFile(fh2);
  fm.ClearBuffer();

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
  FileHandler  fh2 = fm.OpenFile ("output.txt");
  // FileHandler fh = fm.OpenFile ("./testcases/merge_sort/sort_input1.txt");
  cout << "File opened-final" << endl;
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
  if(i==4084 ||i==0)
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
  fh2.UnpinPage(q);
  q++;}
fm.CloseFile (fh2);
fm.DestroyFile ("output.txt");
}
