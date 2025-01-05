#include<bits/stdc++.h>
using namespace std;
struct student{
    int id;
    string name;
    double cgpa;

};

int Partition(vector<student>& a,int low,int high) {
    int index = low - 1;
    double pivot = a[high].cgpa;

    for (int i = low; i < high; i++) {
        if (a[i].cgpa <= pivot) {
            index++;
            swap(a[i], a[index]);
        }
    }

    swap(a[high], a[index + 1]);
    return index + 1;
}
void quickSort(vector<student>& a,int low,int hi){
    if(low<hi){
       int p = Partition(a, low, hi);
        quickSort(a,low,p-1);
        quickSort(a,p+1,hi);
    }
}
int main(){
cout<<"enter the number of students"<<endl;
int n;
cin>>n;

vector<student>students(n);

for(int i=0;i<n;i++){
    cout<<"enter your ID, NAME, CGPA of student "<<i+1<<": ";
    cin>>students[i].id>>students[i].name>>students[i].cgpa;
}

quickSort(students,0,n-1);

for(int i=0;i<n;i++){
    cout<<"ID: "<< students[i].id << " NAME: " <<students[i].name<< " CGPA: "<<students[i].cgpa<< endl;
}
}
