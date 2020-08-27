/* 实现一个简单的菜单程序，运行时显示"Menu: A(dd) D(elete) S(ort) Q(uit)， Select 
one:"提示用户输入，A表示增加，D表示删除，S表示排序，Q表示退出，输入为A、D、S时分别提示"数据已经增加、删除、排序。"输入为Q时程序结束。要求使用if 
… else语句进行判断，用break、continue控制程序流程。 */
#include<iostream>
using namespace std;

void useContinue()
{
	char choice;
	while(1)
	{
		cout << "Menu: A(dd) D(elete) S(ort) Q(uit)， Select one:";
		cin >> choice;
		if (choice == 'A')
		{
			cout << "数据已经增加" << endl;
			continue;
		}
		else if (choice == 'D')
		{
			cout << "数据已经删除" << endl;
			continue;
		}
		else if (choice == 'S')
		{
			cout << "数据已经排序" << endl;
			continue;
		}
		else if (choice == 'Q')
			break;
		else 
			continue;
	}
}

void useBreak()
{
	char choice;
	cout << "Menu: A(dd) D(elete) S(ort) Q(uit)， Select one:";
	cin >> choice;
	switch(choice)
	{
	case 'A':
		cout << "数据已经增加. " << endl;
		break;
	case 'D':
		cout << "数据已经删除. " << endl;
		break;
	case 'S':
		cout << "数据已经排序. " << endl;
		break;
	case 'Q':
		exit(0);
		break;
	default:
		;
	}
}

void main()
{
	//useBreak();
	useContinue();
	return;
}
