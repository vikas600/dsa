#include<iostream>
 #include<fstream>
 #include<cstdio>
 
using namespace std;
 
class Student
 {
   public:
    int rollno;
    char name[50];
    char addr[50];
 
 
 
    void setData()
    {
        cout << "\nEnter roll no. : ";
        cin >> rollno;
        cout << "Enter Name : ";
        cin>>name;
        cout<<"Enter Address : ";
        cin>>addr;
    }
 
    void showData()
    {
        cout<<"\n*Student Roll No  : " << rollno;
        cout<<"\n*Student Name : " << name;
        cout<<"\n*Address : "<<addr<<endl;
    }
 
 
    int retrollno()
    {
        return rollno;
    }
 };
 
 
void write_record()
 {
    ofstream outFile;
    outFile.open("Student.dat", ios::binary | ios::app);
 
    Student obj;
    obj.setData();
 
    outFile.write((char*)&obj, sizeof(obj));// obj is sender
 
 
    outFile.close();
 }
 
void display()  //display of complete file
 {
    ifstream inFile;
    inFile.open("Student.dat", ios::binary);
 
    Student obj;
 
    while(inFile.read((char*)&obj, sizeof(obj))) // obj is receiver
    {
        obj.showData();
    }
 
    inFile.close();
 }
 
int search(int n){
    ifstream inFile;
    bool flag= false;
    inFile.open("Student.dat", ios::binary);
 
    Student obj;
 
    while(inFile.read((char*)&obj, sizeof(obj)))
    {
        if(obj.rollno == n)
        {
    flag= true;
            obj.showData();
    return 1;
            break;
        }
    }
 if(flag == false)
 {
    cout<<" Record for roll no." << n << " not found in file";
 return 0;
 }
    return 0;
    inFile.close();
 }
 
void delete_record(int n)  
{
    Student obj;
  //  bool flag= true;
    ifstream inFile;
    inFile.open("Student.dat", ios::binary); //original/ before
 
    ofstream outFile;
    outFile.open("temp.dat", ios::out | ios::binary);//new/after
   
 
int a= search(n);
 if(a == 1 )
 {
 
 
    while(inFile.read((char*)&obj, sizeof(obj)))
    {
        if(obj.retrollno() != n)
        {
 // flag= false;
            outFile.write((char*)&obj, sizeof(obj));
        }
    }
    inFile.close();
    outFile.close();
    remove("Student.dat");    // to delete student file
    rename("temp.dat", "Student.dat"); 
}
 else
 {
 cout<<"This roll no data is not present in the file so cant apply delete operation";
 }
 }
 
 
 int main()
 {
 int ch;
 do{
    cout<<"\n\n\n***********File operations*************** \n1. Add record \n2. Display records \n3. Search record \n4. Delete record";
    cout<<"\n\nEnter your choice : ";
    cin>>ch;
    switch(ch){
 
case 1:
            cout<<"Enter number of records : ";
    int n;
    cin>>n;
    for(int i = 0; i <n; i++)
       write_record();
    break;
 case 2:
 cout << "\nList of records";
 display();
 break;
 case 3:
    cout<<"Enter Student Roll No : ";
    int s;
    cin>>s;
    search(s);
 break;
 case 4:
    cout<<"Enter no. to be deleted : ";
    int d;
    cin>>d;
    delete_record(d);
    cout << "\nRecord Deleted";
    break;
    case 5:
            return 0;
    }
    }while(ch!=6);
 return 0;
 }