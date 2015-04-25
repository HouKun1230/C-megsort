// megsort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include"stdio.h"
#include"string.h" 
void merge(int *arr,int *sarr,int i,int m,int n) {
		int j,k,index;
         for(j=m+1,k=i;i<=m&&j<=n;k++){
         if(arr[i]<=arr[j])
                        sarr[k]=arr[i++];
                else
                        sarr[k]=arr[j++];
        }
         if(i<=m){
                for(index=i;index<=m;index++)
                       sarr[k++]=arr[index];
        }
         if(j<=n){
                for(index=j;index<=n;index++)
                        sarr[k++]=arr[index];
        }
}
 
void Merge_sort(int *arr,int *sarr,int s,int t) {
        int m;
        int sarr2[10]={0};
        if(s==t)
                sarr[s]=arr[s];
        else{
                m=(s+t)/2;               
				Merge_sort(arr,sarr2,s,m);                
				Merge_sort(arr,sarr2,m+1,t);                
				merge(sarr2,sarr,s,m,t);        }
}
 
int main(int argc,char *argv[])
{
        printf("MergeSort:\n");
        int arr[10]={12,324,182,53,12,81,6,8};
        int sarr[10]={0};
        int arrsize=7;
        Merge_sort(arr,sarr,1,arrsize);
        int i;
        printf("Sorted array: ");
        for(i=1;i<=arrsize;i++){
                printf("%d ",sarr[i]);
        }
        printf("\n");
        return 0;
}

