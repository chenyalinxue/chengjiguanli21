#include <iostream>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include<windows.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void menu()
{  cout<<"��ӭʹ��ѧ���ɼ�����ϵͳ2.0\n";
	cout << "    1. ���ѧ���ĳɼ���\n";
	cout << "    2. ��ÿ�˵�ƽ����\n";
	cout << "    3. ��ÿ�ſε�ƽ����\n";
	
	
	cout << "    7. �������ļ�\n";
	cout << "    0. �˳�\n\n";
	cout << "���������ѡ��(0-7)��\n" ;
}
  

void input(int a[][4] ,int m,int n)
{
	int  i, j;
	fstream  infile;
	infile.open("cj1.txt"); 
 	for(i=0; i<m-1; i++)      // i �������� 
    {    
		for(j=0; j<n-1; j++) // j �������� 
        	infile >> a[i][j];   //  �ļ����ݶ��뵽�ڴ�a[i][j] 
    }  
    infile.close();
}

void output(int a[][4] ,int m,int n)
{
  for(int i=0; i<m; i++)      
    {    for(int j=0; j<n; j++) 
              cout << a[i][j]<<" ";  
		cout<<endl;   
     }	
	
}

void fun2(int a[][4],int m,int n)
{
	cout<<"����2����ÿ�˵�ƽ����\n";
	for(int i=0;i<m-1;i++)
	{
		for(int j=0;j<n-1;j++)
		{a[i][3]=a[i][3]+a[i][j];}
		a[i][3]=a[i][3]/3;
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{cout<<a[i][j]<<" ";}
		cout<<endl;
	}
	for(int i=0;i<m;i++)
	a[i][3]=0;

}



void fun3(int a[][4],int m,int n)
{
	cout<<"����3����ÿ�ſε�ƽ����\n";
	for(int j=0;j<n-1;j++)
	{
		for(int i=0;i<m-1;i++)
		{a[4][j]=a[i][j]+a[4][j];}
		a[4][j]=a[4][j]/4;
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{cout<<a[i][j]<<" ";}
		cout<<endl;
	}
	for(int j=0;j<n;j++)
	a[4][j]=0;
}


void fun7(int a[][4],int m,int n)
{
	cout<<"����7: �������ļ�\n";
	for(int i=0;i<m-1;i++)
	{
		for(int j=0;j<n-1;j++)
		{a[i][3]=a[i][3]+a[i][j];}
		a[i][3]=a[i][3]/3;
	}
	for(int j=0;j<n-1;j++)
	{
		for(int i=0;i<m-1;i++)
		{a[4][j]=a[i][j]+a[4][j];}
		a[4][j]=a[4][j]/4;
	}
	ofstream  outfile;
	outfile.open("cj2.txt");
 	for(int i=0; i<5; i++)      
    {    
		for(int j=0; j<4; j++) 
            outfile << a[i][j]<<" ";  
		outfile<<endl;   
    }
    outfile.close(); 
    for(int i=0;i<m;i++)
	a[i][3]=0;
	for(int j=0;j<n;j++)
	a[4][j]=0;
 
}

int main()
{
//int cj[5][4] ={ {89, 78, 56},{88,99,100},{72,80,61}, {60,70,75}}; 

int cj[5][4]={0};    
int  i, j;
int choose;

input(cj,5,4);
menu();

 //choose = -1;
cin >> choose;
while (choose != 0) 
{
// cin >> choose;
// if(choose==0) break;
  switch (choose) 
 {
	case 1:output(cj,5,4);break;
    case 2:fun2(cj,5,4);break;
    case 3:fun3(cj,5,4);break;
    case 7:fun7(cj,5,4);break;

}
system("pause");
 //getchar();

 system("CLS");
 menu(); 
 cin >> choose;
}
return 0;
}

