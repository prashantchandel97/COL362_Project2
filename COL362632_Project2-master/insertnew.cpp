//Sample file for students to get their code running
#include<bits/stdc++.h>
#include "file_manager.h"
#include "errors.h"
#include<cstring>

using namespace std;
typedef pair<int, pair<int, int> > ppi;
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
    if(output_position!=4092)
    {
    int tempr=INT_MIN;
    memcpy(&data2[output_position],&tempr,sizeof(int));
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
                      q2=0;
                    while(q2!=39)
                    {
                        string str1="temp"+to_string(iter*39+q2)+".txt";
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
                        // cout<<"quant "<<quant<<"\n";
                       for (int i = 0; i < 39; i++)
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
                           // cout<<tempallocation<<"\n";
                          output_position+=4;
                          if(output_position==4088)
                          {
                            int tempr=INT_MIN;
                            memcpy(&data2[output_position],&tempr,sizeof(int));
                            fh2.MarkDirty(pagenumber);
                            fh2.FlushPages();
                            fh2.UnpinPage(pagenumber);
                            ph2=fh2.NewPage();
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
                          else
                          {
                            int pgno=ph1[i].GetPageNum();
                            int flag=0;
                            try
                            {
                              ph1[i]=fh1[i].NextPage(pgno);
                            }
                            catch(...)
                            {
                                flag=1;
                            }
                            if(flag==0)
                            {
                              cout<<i<<pgno<<ph1[i].GetPageNum()<<"\n";
                            data1[i]=ph1[i].GetData();
                            memcpy(&num,&data1[i][0],sizeof(int));
                            if(num!=INT_MIN)
                            pq.push({ num, { i,0 } });
                            fh1[i].UnpinPage(pgno);
                            }
                          }
                        }
                        if(output_position!=4092)
                        {
                        int tempr=INT_MIN;
                        memcpy(&data2[output_position],&tempr,sizeof(int));
                      }
                      q2=0;
                      while(q2!=39)
                      {
                        string str1="temp"+to_string(q2)+".txt";
                       char char_array1[str1.length()+1];
                       strcpy(char_array1,str1.c_str());
                        fm.DestroyFile(char_array1);
                        q2++;
                      }
                      fm.CloseFile(fh2);
                      string str1="temp"+to_string(iter)+".txt";
                     char char_array1[str1.length()+1];
                     strcpy(char_array1,str1.c_str());
                      rename("output.txt",char_array1 );


                        fm.ClearBuffer();
                     }
                     else if(iter==times-1)
                     {
                             int q2=0;
                            int quant1=number_initial_runs-(times-1)*39;

                            while(q2!=quant1)
                            {
                                string str1="temp"+to_string(iter*39+q2)+".txt";
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
                                // cout<<"quant "<<quant<<"\n";
                               for (int i = 0; i < quant1; i++)
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
                                   // cout<<tempallocation<<"\n";
                                  output_position+=4;
                                  if(output_position==4088)
                                  {
                                    int tempr=INT_MIN;
                                    memcpy(&data2[output_position],&tempr,sizeof(int));
                                    fh2.MarkDirty(pagenumber);
                                    fh2.FlushPages();
                                    fh2.UnpinPage(pagenumber);
                                    ph2=fh2.NewPage();
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
                                  else
                                  {
                                    int pgno=ph1[i].GetPageNum();
                                    int flag=0;
                                    try
                                    {
                                      ph1[i]=fh1[i].NextPage(pgno);
                                    }
                                    catch(...)
                                    {
                                        flag=1;
                                    }
                                    if(flag==0)
                                    {
                                      cout<<i<<pgno<<ph1[i].GetPageNum()<<"\n";
                                    data1[i]=ph1[i].GetData();
                                    memcpy(&num,&data1[i][0],sizeof(int));
                                    if(num!=INT_MIN)
                                    pq.push({ num, { i,0 } });
                                    fh1[i].UnpinPage(pgno);
                                    }
                                  }
                                }
                                if(output_position!=4092)
                                {
                                int tempr=INT_MIN;
                                memcpy(&data2[output_position],&tempr,sizeof(int));
                              }
                              q2=0;
                              while(q2!=quant1)
                              {
                                string str1="temp"+to_string(iter*39+q2)+".txt";
                               char char_array1[str1.length()+1];
                               strcpy(char_array1,str1.c_str());
                                fm.DestroyFile(char_array1);
                                q2++;
                              }
                              fm.CloseFile(fh2);
                              string str1="temp"+to_string(iter)+".txt";
                              char char_array1[str1.length()+1];
                              strcpy(char_array1,str1.c_str());
                               rename("output.txt",char_array1);
                               fm.ClearBuffer();
                               quant=iter+1;
                     }

                  }
                  times=(int)ceil((times+1)/39.0);//reasonfor one?
  }//when times=1 then 1 wala case
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
    ph1[q2]=fh1[q2].PageAt(0);
    data1[q2]=ph1[q2].GetData();
    q2++;
  }
    num=1;
    priority_queue<ppi, vector<ppi>, greater<ppi> > pq;
    cout<<"quant "<<quant<<"\n";
   for (int i = 0; i < quant; i++)
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
       // cout<<tempallocation<<"\n";
      output_position+=4;
      if(output_position==4088)
      {
        int tempr=INT_MIN;
        memcpy(&data2[output_position],&tempr,sizeof(int));
        fh2.MarkDirty(pagenumber);
        fh2.FlushPages();
        fh2.UnpinPage(pagenumber);
        ph2=fh2.NewPage();
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
      else
      {
        int pgno=ph1[i].GetPageNum();
        int flag=0;
        try
        {
          ph1[i]=fh1[i].NextPage(pgno);
        }
        catch(...)
        {
            flag=1;
        }
        if(flag==0)
        {
          cout<<i<<pgno<<ph1[i].GetPageNum()<<"\n";
        data1[i]=ph1[i].GetData();
        memcpy(&num,&data1[i][0],sizeof(int));
        if(num!=INT_MIN)
        pq.push({ num, { i,0 } });
        fh1[i].UnpinPage(pgno);
        }
      }
    }
    if(output_position!=4092)
    {
    int tempr=INT_MIN;
    memcpy(&data2[output_position],&tempr,sizeof(int));
  }
  q2=0;
  while(q2!=quant)
  {
    string str1="temp"+to_string(q2)+".txt";
   char char_array1[str1.length()+1];
   strcpy(char_array1,str1.c_str());
    fm.DestroyFile(char_array1);
    q2++;
  }
  fm.CloseFile(fh2);
}

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
  while(num!=INT_MIN ){
  // memcpy (&arr[i/4], &data[i], sizeof(int));
  memcpy (&num, &data2[i], sizeof(int));
  // if(num!=INT_MIN
  if(i==0 || i==4084)
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
