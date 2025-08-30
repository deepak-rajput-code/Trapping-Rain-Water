#include<iostream>
 using namespace std;
   int fill_cube(int [], int);
   int compare_min_element(int [],int [],int [], int);
  int main(){ 
     int size;
      cout<<"enter the size of an array ";
       cin>>size;

       int arr[size];
        for(int i=0;i<size;i++){
            cout<<"enter the element of position "<<i+1<<" :";
            cin>>arr[i];
        }
     int fill_box=fill_cube(arr,size);
        cout<<endl<<"the total filled area by water: =="<<fill_box;
    return 0;
  }
      int fill_cube(int brr[], int length){
           cout<<endl<<"entered array is :"<<endl;
            for(int i=0;i<length;i++){
              cout<<brr[i]<<" ";
            }
           int left_max[length];
           int right_max[length];

             left_max[0]=brr[0];
             right_max[length-1]=brr[length-1];
               
             int left_max_element;
             for(int j=1;j<length;j++){
                left_max_element=brr[j];
               for(int k=j;k>=0;k--){
                  if(left_max_element<=brr[k]){
                       left_max_element=brr[k];
                     left_max[j]=brr[k];
                  }
               }
             }
             cout<<endl<<"left max array: "<<endl;
             for(int m:left_max){
              cout<<m<<" ";
             }
        right_max[length-1]=brr[length-1];
             int right_max_element;
             for(int j=length-2;j>=0;j--){
                right_max_element=brr[j];
               for(int k=j;k<length;k++){
                  if(right_max_element<=brr[k]){
                       right_max_element=brr[k];
                     right_max[j]=brr[k];
                  }
               }
              }
              cout<<endl<<"left max array: "<<endl;
             for(int m:right_max){
              cout<<m<<" ";
             }

             int min_element_arr[length];
               compare_min_element(min_element_arr,left_max,right_max,length);
                  cout<<endl<<"min element array: "<<endl;
                 for(int k:min_element_arr){
                  cout<<k<<" ";
                 }

                 int filled_area=0;
                   for(int i=0;i<length;i++){
                    filled_area+=min_element_arr[i]-brr[i];
                   }
             return filled_area;
      }
         int compare_min_element(int min_element[],int left_max[],int right_max[],int length){
              for(int i=0;i<length;i++){
                 if(left_max[i]<right_max[i]){
                   min_element[i]=left_max[i];
                 }
                 else{
                  min_element[i]=right_max[i];
                 }
              }               
          return 0;
         }