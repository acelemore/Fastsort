/*************************************************************************
    > File Name: Fastsort.h
    > Author: tym
    > Mail: 
    > Created Time: Wed 28 Aug 2019 01:55:16 PM CST
 ************************************************************************/

#ifndef _FASTSORT_H

#include<iostream>
#include<vector>
#include<utility>
using namespace std;

template<typename T>
const T& median(vector<T>& a, int left, int right)
{
	//寻找枢纽元
	int center = (left + right)/2;
	if(a[center] < a[left])
		swap(a[left], a[center]);
	if(a[right] < a[left])
		swap(a[left], a[right]);
	if(a[right] < a[center])
		swap(a[center], a[right]);

	//枢纽元置于right-1处
	swap(a[center], a[right - 1]);
	return a[right - 1];
}

template<typename T>
void _fastsort(vector<T>& a, int left, int right)
{
	if(left + 10 <= right)
	{
		const T& pivot = median(a, left, right);
		//meidan()后可确认left小于pivot, right 大于pivot
		int l = left, r = right - 1;
		while(true)
		{
			//确保每次都移动下标，避免死循环
			while(a[++l] < pivot){}
			while(a[--r] > pivot){}
			if(l < r)
				swap(a[l], a[r]);
			else
				break;
		}
		//恢复枢纽元
		swap(a[l], a[right-1]);
		_fastsort(a, left, l-1);
		_fastsort(a, l+1, right);
	}
	else
	{
		//对小数组进行插入排序
		for(int p = left + 1; p <= right; p++)
		{
			T tmp = a[p];
			int j;
			for(j = p; j > left && tmp < a[j - 1]; --j)
				a[j] = a[j - 1];
			a[j] = tmp;
		}
	}
}


template <typename T>
void fastsort(vector<T> &a)
{
	_fastsort(a, 0, a.size() - 1);
}


#define _FASTSORT_H
#endif
