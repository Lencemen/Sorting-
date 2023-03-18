#include <iostream>
#define MAX 100
using namespace std;
void mergesortedsubarray(int a[],int lb,int le,int re){
    int na,nb,nc,c[MAX];
    na=lb;
    nb=le+1;
    nc=lb;
    while(na<=le && nb<=re){
        if(a[na]<a[nb]){
            c[nc]=a[na];
            nc++;
            na++;
        }
        else{
            c[nc]=a[nb];
            nc++;
            nb++;
        }
    }
    if(na>le){
        while(nb<=re){
            c[nc++]=a[nb++];
        }
    }
    if(nb>re){
        while(na<=lb){
            c[nc++]=a[na++];
        }
    }
    for(int i=lb;i<=re;i++){
        a[i]=c[i];
    }
}
void mergesort(int a[],int lb,int ub){
    int mid;
    if(lb<ub){
        mid=(lb+ub)/2;
        mergesort(a,lb,mid);
        mergesort(a,mid+1,ub);
        mergesortedsubarray(a,lb,mid,ub);
    }
}
