/* ʵ��һ���򵥵Ĳ˵���������ʱ��ʾ"Menu: A(dd) D(elete) S(ort) Q(uit)�� Select 
one:"��ʾ�û����룬A��ʾ���ӣ�D��ʾɾ����S��ʾ����Q��ʾ�˳�������ΪA��D��Sʱ�ֱ���ʾ"�����Ѿ����ӡ�ɾ��������"����ΪQʱ���������Ҫ��ʹ��if 
�� else�������жϣ���break��continue���Ƴ������̡� */
#include<iostream>
using namespace std;

void useContinue()
{
	char choice;
	while(1)
	{
		cout << "Menu: A(dd) D(elete) S(ort) Q(uit)�� Select one:";
		cin >> choice;
		if (choice == 'A')
		{
			cout << "�����Ѿ�����" << endl;
			continue;
		}
		else if (choice == 'D')
		{
			cout << "�����Ѿ�ɾ��" << endl;
			continue;
		}
		else if (choice == 'S')
		{
			cout << "�����Ѿ�����" << endl;
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
	cout << "Menu: A(dd) D(elete) S(ort) Q(uit)�� Select one:";
	cin >> choice;
	switch(choice)
	{
	case 'A':
		cout << "�����Ѿ�����. " << endl;
		break;
	case 'D':
		cout << "�����Ѿ�ɾ��. " << endl;
		break;
	case 'S':
		cout << "�����Ѿ�����. " << endl;
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
