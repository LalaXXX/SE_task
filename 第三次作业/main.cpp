#include "MultipleBirthsSystem.h"
int main()
{
	StuInfo stu;
	cout << "\t\t**************************************************" << endl;
	cout << "\t\t**************************************************" << endl;
	cout << "\t\t*******                                    *******" << endl;
	cout << "\t\t*******   ��ӭ������̥�����Զ�ʶ��ϵͳ   *******" << endl;
	cout << "\t\t*******                                    *******" << endl;
	cout << "\t\t**************************************************" << endl;
	cout << "\t\t**************************************************" << endl;
	login();
	int x = 1;
	string name;
	while (x){
		StuNode *q = new StuNode;
		ShowMenu();
		int n;
		cin >> n;
		switch (n) {
		case 1:
			stu.CreatInfo();	//��������ѧ����Ϣ
			break;
		case 2:
			system("CLS");
			cout << "������ѧ�������� " << endl;
			cin >> q->StudentName;
			cout << "\n������ѧ����ĸ����������������ǰ���м���&��������	" << endl;
			cin >> q->ParentName;
			cout << "\n������ѧ���������ڡ�ʱ�� ���밴�ո�ʽΪxxxx-xx-xx@xx:xx:xx���룩: " << endl;
			cin >> q->BirthTime;
			cout << "\n������ѧ���Ա�: " << endl;
			cin >> q->Sex;
			cout << "\n������ѧ���߿�����: " << endl;
			cin >> q->Score;
			stu.StuInsert(q);		//���ѧ����Ϣ
			break;
		case 3:
			stu.StuRead();			//�ļ���ȡѧ����Ϣ
			break;
		case 4:
			stu.StuIdentify();		//���̥�Զ�ʶ����
			break;
		case 5:
			system("CLS");
			cout << "������Ҫɾ��ѧ�������� " << endl;
			cin >> name;
			stu.StuDelete(name);		//ɾ����ѧ����Ϣ
			break;
		case 6:
			system("CLS");
			cout << "������Ҫ����ѧ�������� " << endl;
			cin >> name;
			q = stu.StuFind(name);		//��ѯѧ����Ϣ
			cout << "��ѧ��������Ϊ�� " << q->StudentName << endl;
			cout << "��ѧ���ĸ�ĸ����Ϊ�� " << q->ParentName << endl;
			cout << "��ѧ���ĳ���ʱ��Ϊ�� " << q->BirthTime << endl;
			cout << "��ѧ����ѧ���Ա�Ϊ�� " << q->Sex << endl;
			cout << "��ѧ���ĸ߿�����Ϊ�� " << q->Score << endl;
			break;
		case 7:
			system("CLS");
			cout << "��������Ҫ�޸ĵ�ѧ�������� " << endl;
			cin >> q->StudentName;
			cout << "\n������ѧ����ĸ����������������ǰ���м���&������:	" << endl;
			cin >> q->ParentName;
			cout << "\n������ѧ���������ڡ�ʱ�� ���밴�ո�ʽΪxxxx-xx-xx@xx:xx:xx���룩: " << endl;
			cin >> q->BirthTime;
			cout << "\n������ѧ���Ա�: " << endl;
			cin >> q->Sex;
			cout << "\n������ѧ���߿�����: " << endl;
			cin >> q->Score;
			stu.StuUpdate(q);			//�޸�ѧ����Ϣ
			break;
		case 0:
			break;
		default:
			cout << "��������밴�涨���룡";
			break;
		}
		if (!n)	break;
		cout << "\n\t\t\t �����ϲ���ҳ������1, �˳�ϵͳ������0:" ;
		cin >> x;
	}
}
