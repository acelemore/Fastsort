/*************************************************************************
    > File Name: main.cpp
    > Author: tym
    > Mail: 
    > Created Time: Tue 27 Aug 2019 05:17:07 PM CST
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include"Fastsort.h"
using std::cout;
using std::endl;
int main()
{
	srand(time(NULL));
	vector<int> arr(100);
	cout<<"arr:"<<endl;
	for(int i = 0; i < 100; i++)
	{
		arr[i] = rand() % 1000;
		cout<<arr[i]<<", ";
	}
	cout<<endl;

	fastsort(arr);
	cout<<"arr:"<<endl;
	for(int i = 0; i < 100; i++)
	{
		cout<<arr[i]<<", ";
	}
	cout<<endl;

	return 0;
}
