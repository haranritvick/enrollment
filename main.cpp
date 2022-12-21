#include<iostream>
#include<vector>
#include<string>
using namespace std;

class student
{
    protected:
        int roll;
        string name;
    public:
        void set_student(int roll,string name)
        {
            this->roll=roll;
            this->name=name;
        }
        int get_roll()
        {
            return roll;
        }
        virtual void display() = 0;
};

class pg_student: public virtual student
{
    protected:
        string course1;
        string course2;
        string course3;
    public:
        void set_pg_student(string course1,string course2,string course3,int roll,string name)
        {   
            set_student(roll,name);
            this->course1=course1;
            this->course2=course2;
            this->course3=course3;
        }
        void display()
        {   
            cout<<"Roll Number : "<<roll<<endl;
            cout<<"Name : "<<name<<endl;
            cout<<"Course 1 : "<<course1<<endl;
            cout<<"Course 2 : "<<course2<<endl;
            cout<<"Course 3 : "<<course3<<endl;
        }
};

class research_student : public virtual student
{
    protected:
        string course1;
        string research_area;
    public:
        void set_research_student(string course1,string research_area,int roll,string name)
        {   
            set_student(roll,name);
            this->course1=course1;
            this->research_area=research_area;
        }
        void display()
        {   
            cout<<"Roll Number : "<<roll<<endl;
            cout<<"Name : "<<name<<endl;
            cout<<"Course 1 : "<<course1<<endl;
            cout<<"Research Area : "<<research_area<<endl;
        }
};

class ta : public pg_student,public research_student
{
    private:
        string course_assigned;
        string role;
    public:
        void set_ta(string course_assigned,string role,string course1,string course2,string course3,int roll,string name)
        {
            set_pg_student(course1,course2,course3,roll,name);
            this->course_assigned=course_assigned;
            this->role=role;
        }
        void set_ta(string course_assigned,string role,string course1,string research_area,int roll,string name)
        {
            set_research_student(course1,research_area,roll,name);
            this->course_assigned=course_assigned;
            this->role=role;
        }
        void display()
        {   
            if(role=="PG student")
            {
                pg_student::display();
            }
            else if(role=="Research student")
            {
                research_student::display();
            }
            cout<<"Course Assigned : "<<course_assigned<<endl;
            cout<<"Role : "<<role<<endl;
        }
};

int main()
{
    int choice=0;
    vector<ta> arr;
    int roll,flag=0,val;
    string name,role,course1,course2,course3,research_area,course_assigned;
    while(choice!=3)
    {
        cout<<"1. Set Details\n2. Display\n3. Exit\n";
        cout<<"Choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Roll Number : ";
                cin>>roll;
                flag=1;
                for(auto student:arr)
                {
                    if(student.get_roll()==roll)
                    {
                        flag=0;
                        break;
                    }
                }
                
                if(flag)
                {
                    cout<<"Name : ";
                    cin>>name;
                    flag=1;
                    
                    while(flag)
                    {
                        cout<<"Role 1.PG student 2.Research student\nEnter 1 or 2 : ";
                        cin>>val;
                        
                        if(val==1)
                        {   
                            role="PG student";
                            cout<<"Course 1 : ";
                            cin>>course1;
                            cout<<"Course 2 : ";
                            cin>>course2;
                            cout<<"Course 3 : ";
                            cin>>course3;
                            
                            while(flag)
                            {
                                cout<<"Course Assigned : ";
                                cin>>course_assigned;
                                
                                if(course_assigned==course1||course_assigned==course2||course_assigned==course3)
                                {
                                    cout<<"Course Assigned cannot be same as Course (Enter again)\n";
                                }
                                else
                                {
                                    ta new_ta;
                                    new_ta.set_ta(course_assigned,role,course1,course2,course3,roll,name);
                                    arr.push_back(new_ta);
                                    flag=0;
                                }
                            }
                            
                        }
                        
                        else if(val==2)
                        {   
                            role="Research student";
                            cout<<"Course 1 : ";
                            cin>>course1;
                            cout<<"Research Area : ";
                            cin>>research_area;
                            
                            while(flag)
                            {
                                cout<<"Course Assigned : ";
                                cin>>course_assigned;
                                
                                if(course_assigned==course1)
                                {
                                    cout<<"Course Assigned cannot be same as Course (Enter again)\n";
                                }
                                else
                                {
                                    ta new_ta;
                                    new_ta.set_ta(course_assigned,role,course1,research_area,roll,name);
                                    arr.push_back(new_ta);
                                    flag=0;
                                }
                            }
                        }
                        
                        else
                        {
                            cout<<"Enter a valid role\n";
                        }
                    }
                    
                }
                
                else
                {
                    cout<<"Entered roll number already exists\n";
                }
                break;
                
            case 2:
                cout<<"Roll Number : ";
                cin>>roll;
                flag=0;
                for(auto student:arr)
                {
                    if(student.get_roll()==roll)
                    {
                        student.display();
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    cout<<"Entered roll number does not exist\n";
                }
                break;
                
            case 3:
                break;
            default:
                cout<<"Invalid choice\n";
                break;
                
        }
    }
}
