#include<bits/stdc++.h>
using namespace std;
class abstractemp{ //Contract abstract class
    virtual void afp() =0; 
};
class employee:abstractemp{ // employee class signed Contract abstractemp 
private:                    // SDince it signed the Contract need to provide implementation for afp
    string name;//Encapsulated Properties    
    string comp;//Encapsulated Properties    
    int age;    //Encapsulated Properties
    
public:
    void setname(string Name){
        name = Name;            // Property Encapsulated here
    }
    string getname(){
        return name;
    }
    void setcomp(string Comp){
        comp = Comp;
    }
    string getcomp(){
        return comp;
    }
    void setage(int Age){
        age = Age;
    }
    int getage(){
        return age;
    }
    void intro(){
        cout<<name<<age<<comp;
    }
    //Constructor usually public && no return type && same name as class 
    employee(string Name, string Company, int Age){ //Also used to acess private data
        name = Name;
        comp = Company;
        age = Age;

    }
    void afp(){
        if(age>10){
            cout<<"Promoted \n";
        }
        else cout<<"NO\n";
    }
};
int main(){
    employee e1 = employee("Paritosh","IIT",22);
 //   e1.name = "Paritosh";
 //   e1.age =22;
 //   e1.comp = "IIT";
    e1.setage(11);
    e1.intro();
    e1.afp();
}
