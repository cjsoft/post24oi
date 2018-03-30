//二分搜索法 边界是low>high 
#include <stdio.h>
int binarySearch(int a[],int searchKey,int low,int high);
int main(){
    int n;  
    
    int num[n];
    printf("Pleas input n:");
    scanf("%d",&n);
    printf("Please inpur integers:");
    int i=0;
    for(i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    printf("Please input searchKey:");
    int searchKey;
    scanf("%d",&searchKey);
    int low=num[0],high=num[n-1];
    printf("The result is:%d",binarySearch(num,searchKey,0,n-1));
}
int binarySearch(int a[],int searchKey,int low,int high){
    int middle;
    while(low<=high){
        middle=(low+high)/2;
        if(searchKey==a[middle]) return a[middle];
        else if(searchKey<a[middle]) high=middle-1;
        else low=middle+1;
    }
    return -1;//没找到 
} 