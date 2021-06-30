// Encapsulation, Abstrtaction, Inheritance, Polymorphism 
//The most common use of Polymorphism is when a parent class reference is used to 
// refer to a child class object

#include<bits/stdc++.h>
using namespace std;
class abstractemp{ //Contract abstract class
    virtual void afp() =0; 
};
class employee:abstractemp{ // employee class signed Contract abstractemp 
private:                    // SDince it signed the Contract need to provide implementation for afp
   // string name;//Encapsulated Properties    
    string comp;//Encapsulated Properties    
    int age;    //private Not accesible by derived class also
protected:
    string name; //Same as private but protected is accesible to derived class as well
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
    virtual void work(){//Checks if implementation is in derived classes.
        cout<<name<<"is checking email\n";
    }
};//public employee lets us acess functions in employee outside developer class like afp();
class developer:public employee{//developer is a derived class(child) && employee super and parent class
public:// developer has all employee class Property    
    string langp;
    developer(string Name, string Company, int Age, string Langp)
        :employee( Name, Company, Age){
            langp = Langp;
    }
    void fixbug(){
        cout<<name<<" age "<<getage()<<" fixed bug using "<<langp<<"\n";
    }
    void work(){ //Polymorphism many forms work also in employee 
        cout<<name<<" is coding in "<<langp<<'\n';
    }
};
class teacher:public developer{
    public:
    string sub;
    teacher(string Name, string Company, int Age, string Langp, string Sub)
        :developer(Name, Company, Age, Langp){
            sub = Sub;
        }
    void preparelesson(){
        cout<<name<<" is prepaeing "<<sub<<"\n";
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
    developer d = developer("Alex","nit",19,"C++");
    d.fixbug();
    d.afp();
    teacher t = teacher("SJDB","SDIJVB",13,"DFSDF","ksdjvn");
    t.preparelesson();
    d.afp();
    d.work();
    employee *e = &d;//Pointer to base class can hold reference to derived class d deep down is employee
    employee *e2 = &t;
    e->work();
    e2->work();
    
}
