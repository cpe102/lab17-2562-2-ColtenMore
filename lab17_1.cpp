//Write your code here
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<cctype>
using namespace std;

string upper(string x){
    for(int i=0; i<x.size(); i++){
        x[i]=toupper(x[i]);
    }
    return x;
}

int main(){
    vector<string> v_name,v_grade;
    ifstream f("name_score.txt");
    string s;
    int num1,num2,num3,sum;
    char name[100];
    while(getline(f,s)){
        sscanf(s.c_str(),"%[^:]: %d %d %d",name,&num1,&num2,&num3);
        cout<<name<<" : ";
        v_name.push_back(name);
        sum=num1+num2+num3;
        if(sum>=80){
            v_grade.push_back("A");
            cout<<"A\n";
        }else if(sum>=70){
            v_grade.push_back("B");
            cout<<"B\n";
        }else if(sum>=60){
            v_grade.push_back("C");
            cout<<"C\n";
        }else if(sum>=50){
            v_grade.push_back("D");
            cout<<"D\n";
        }else{
            v_grade.push_back("F");
            cout<<"F\n";
        }
    }

    while(1){
        cout<<"Please input your command : ";
        getline(cin,s);
        int idx=s.find_first_of(" ");
        string s1=upper(s.substr(0,idx));
        string s2=upper(s.substr(idx+1,s.size()));
        
        if(s1=="NAME"){
            for(int i=0; i<v_name.size(); i++){
                if(s2==upper(v_name[i])){
                    cout<<v_name[i]<<"'s grade = "<<v_grade[i]<<"\n";
                }
            }
        }else if(s1=="GRADE"){
            for(int i=0; i<v_grade.size(); i++){
                if(s2==upper(v_grade[i])){
                    cout<<v_name[i]<<"\n";
                }
            }
        }else if(s1=="EXIT"){
            break;
        }else cout<<"Invalid command\n";
    }
}