#ifndef MSORT_H
#define MSORT_H

#include <iostream>
#include <string>
#include <cctype>
#include <vector>

template <typename T, class Comparator>
void msort(std::vector<T>& list, int start, int end, Comparator comp)
{
	//Base case
	if(start >= end){return;}
	int mid = (start+end)/2;

	//First half
	msort(list, start, mid, comp);
	//Second half
	msort(list, mid+1, end, comp);
	//Merge uses Comp to compare each individual array
	merge(list, start, mid, end, comp);
	return;
}

template <typename T, class Comparator>
void mergeSort(std::vector<T>& list, Comparator comp)
{
	msort(list, 0, list.size()-1, comp);
	return;
}

template <typename T, class Comparator>
void merge(std::vector<T>& list, int start, int mid, int end, Comparator comp)
{
	int i=start;
	int j=mid+1; 
	int k=start;

	std::vector<T> output(list.size());

	while(i<=mid && j<=end)
	{
		if(comp(list[i], list[j]))
		{
			output[k] = list[i];
			k++; i++;
		}
		else
		{
			output[k] = list[j];
			k++; j++;
		}
	}

	while(i<=mid)
	{
		output[k] = list[i];
		k++; i++;
	}

	while(j<=end)
	{
		output[k] = list[j];
		k++; j++;
	}

	for(int z=start; z <= end; z++)
	{
		list[z] = output[z];
	}
	return;
}
#endif