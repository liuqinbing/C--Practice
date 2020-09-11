/* 联合体union和枚举enum*/
#include<iostream>
#include<string>
using namespace std;

class ExamInfo{
public:
	ExamInfo(string name, char grade):name(name),mode(Grade),grade(grade){}
	ExamInfo(string name, bool pass):name(name),mode(Pass),pass(pass){}
	ExamInfo(string name, int percent):name(name),mode(Percent),percent(percent){}
	void show();

private:
	string name;
	enum{
		Grade,
		Pass,
		Percent
	}mode;
	union{
		char grade;
		bool pass;
		int percent;
	};
};

void ExamInfo::show(){
	cout<<name<<":";
	switch (mode){
	case Grade: 
		cout<<grade;
		break;
	case Pass: 
		cout<<(pass?"PASS":"FALSE");
		break;
	case Percent: 
		cout<<percent;
		break;
	}
	cout<<endl;
}

void main()
{
	ExamInfo a("English",'B');
	ExamInfo b("Math",90);
	ExamInfo c("Chinese",true);

	a.show();
	b.show();
	c.show();
}

