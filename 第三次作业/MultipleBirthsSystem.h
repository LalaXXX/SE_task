#pragma once
#include <string>
#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;
#define MAX 100
typedef struct StuNode {
	string StudentName;				//ѧ������
	string ParentName;				//��ĸ����
	string BirthTime;				//�������ڡ�ʱ��
	string Sex;						//�Ա�
	int Score;						//�߿�����
	struct StuNode *NextStu;		//�ڵ�ָ��
	int count;						//ͷ�ڵ��¼ѧ������
} StuNode;
typedef struct MbNode {				//���̥�ڽӱ�ڵ�
	int count;
	StuNode *NextStu;
}MbNode;
class StuInfo {
	StuNode *ListHead;
	MbNode MbStuHead[10];
public:
	StuInfo();							//���캯��
	~StuInfo();							//��������
	void CreatInfo();					//����ѧ����Ϣ
	void StuInsert(StuNode *p);			//���ѧ����Ϣ
	void StuRead();						//���ļ�����ѧ����Ϣ
	void StuDelete(string SName);		//ɾ��ѧ����Ϣ
	StuNode* StuFind(string SName);		//��ѯѧ����Ϣ
	void StuUpdate(StuNode *p);			//�޸�ѧ����Ϣ
	void StuSort1();					//����ĸ������ѧ������
	void StuSort2();					//��ѧ������ʱ�̽�ѧ������
	void StuIdentify();					//ʶ����̥ѧ��
};
StuInfo::StuInfo()	//���캯��
{
	ListHead = new StuNode;
	ListHead->NextStu = NULL;
	ListHead->count = 0;
}
StuInfo::~StuInfo()
{
	StuNode *p;
	while (ListHead) {
		p = ListHead;
		ListHead = ListHead->NextStu;
		delete p;
	}
	ListHead = NULL;
}
void ShowMenu()
{
	system("CLS");
	cout << "\t\t*******************************************" << endl;
	cout << "\t\t******   �� �� ̥ �� �� ʶ �� ϵ ͳ  ******" << endl;
	cout << "\t\t******       (�״�ʹ����ѡ��1)       ******" << endl;
	cout << "\t\t******       1.¼���µ�ѧ����Ϣ      ******" << endl;
	cout << "\t\t******       2.����µ�ѧ����Ϣ	  ******" << endl;
	cout << "\t\t******       3.�ļ�����ѧ����Ϣ	  ******" << endl;
	cout << "\t\t******       4.ʶ������̥������Ϣ  ******" << endl;
	cout << "\t\t******       5.ɾ������������Ϣ      ******" << endl;
	cout << "\t\t******       6.��������������Ϣ      ******" << endl;
	cout << "\t\t******       7.�޸�����������Ϣ      ******" << endl;
	cout << "\t\t******       0.��ȫ�˳�ϵͳ          ******" << endl;
	cout << "\t\t*******************************************" << endl;
	cout << "\n\t\n\t\t��ѡ��";
}
void StuInfo::CreatInfo()		//����ѧ����Ϣ�� ��β�巨��
{
	system("CLS");
	int n;
	StuNode *p = ListHead, *q;
	while (1) {
		q = new StuNode;
		cout << "������ѧ�������� " << endl;
		cin >> q->StudentName;
		cout << "\n������ѧ����ĸ����������������ǰ���м���&������:  " << endl;
		cin >> q->ParentName;
		cout << "\n������ѧ���������ڡ�ʱ�� ���밴�ո�ʽΪxxxx-xx-xx@xx:xx:xx���룩:  " << endl;
		cin >> q->BirthTime;
		cout << "\n������ѧ���Ա�: " << endl;
		cin >> q->Sex;
		cout << "\n������ѧ���߿�����: " << endl;
		cin >> q->Score;
		q->NextStu = NULL;
		p->NextStu = q;
		ListHead->count++;
		p = p->NextStu;
		cout << "����¼��������1�� ֹͣ¼��������0" << endl;
		cin >> n;
		if (!n) break;
		system("CLS");
	}
}
void StuInfo::StuInsert(StuNode *p)	//���ѧ����Ϣ ��ͷ�巨��
{
	p->NextStu = ListHead->NextStu;
	ListHead->NextStu = p;
	ListHead->count++;
}
void StuInfo::StuRead()		//���ļ���ȡѧ����Ϣ
{
	system("CLS");
	ifstream file("StudentInfo.txt");
	if (!file) {
		cout << "δ�ҵ�ѧ����Ϣ" << endl;
		return;
	}
	while (!file.eof()) {
		StuNode *p = new StuNode;
		file >> p->StudentName >> p->ParentName >> p->BirthTime >> p->Sex >> p->Score;
		StuInsert(p);
	}
}
void StuInfo::StuDelete(string SName)
{
	system("CLS");
	StuNode *p, *q;
	q = ListHead;		//qΪp�ĸ���ָ��
	p = q->NextStu;
	while (p && p->StudentName != SName) {
		q = p;
		p = p->NextStu;
	}
	if (p->StudentName == SName) {
		q->NextStu = p->NextStu;
		ListHead->count--;
		cout << "ɾ���ɹ�" << endl;
		delete p;
	}
	else {
		cout << "δ�鵽��ѧ����Ϣ" << endl;
	}
}
StuNode *StuInfo::StuFind(string SName)
{
	system("CLS");
	StuNode *p = ListHead->NextStu;
	while (p && p->StudentName != SName) {
		p = p->NextStu;
	}
	if (p->StudentName == SName) {
		return p;
	}
	else {
		cout << "δ�ҵ���ѧ����Ϣ��" << endl;
		return NULL;
	}
}
void StuInfo::StuUpdate(StuNode *p)	//�޸�ѧ����Ϣ
{
	system("CLS");
	StuNode *q = StuFind(p->StudentName);
	if (q) {
		q->StudentName = p->StudentName;
		q->ParentName = p->ParentName;
		q->BirthTime = p->BirthTime;
		q->Sex = p->Sex;
		q->Score = p->Score;
	}
}
void StuInfo::StuSort1()		//����ĸ��������
{
	for (int i = 0; i < ListHead->count - 1; ++i) {
		StuNode *p = ListHead->NextStu, *q = p->NextStu;
		for (int j = 0; j < ListHead->count - 1 - i; ++j) {
			if (p->ParentName > q->ParentName) {
				string SN = p->StudentName, PN = p->ParentName, BT = p->BirthTime, S = p->Sex;
				int Score = p->Score;
				p->BirthTime = q->BirthTime, p->ParentName = q->ParentName, p->Score = q->Score, p->Sex = q->Sex, p->StudentName = q->StudentName;
				q->BirthTime = BT, q->ParentName = PN, q->Score = Score, q->Sex = S, q->StudentName = SN;
			}
			p = q;
			q = q->NextStu;
		}
	}
}
void StuInfo::StuSort2()		//��ѧ����������
{
	for (int i = 0; i < MAX; ++i) {
		if (MbStuHead[i].count == 0) break;
		for (int j = 0; j < MbStuHead[i].count - 1; ++j) {
			StuNode *p = MbStuHead[i].NextStu, *q = p->NextStu;
			for (int k = 0; k < MbStuHead[i].count - 1 - j; ++k) {
				if (p->StudentName > q->StudentName) {
					string SN = p->StudentName, PN = p->ParentName, BT = p->BirthTime, S = p->Sex;
					int Score = p->Score;
					p->BirthTime = q->BirthTime, p->ParentName = q->ParentName, p->Score = q->Score, p->Sex = q->Sex, p->StudentName = q->StudentName;
					q->BirthTime = BT, q->ParentName = PN, q->Score = Score, q->Sex = S, q->StudentName = SN;
				}
				p = q;
				q = q->NextStu;
			}
		}
	}
}
void StuInfo::StuIdentify()							//��ϸ��ʶ��
{
	system("CLS");
	StuSort1();
	int index = 0;
	MbStuHead[0].count = 0;
	char s1[50], s2[50];
	long long a1, a2;
	for (StuNode *p = ListHead->NextStu; p; p = p->NextStu) {
		if (!MbStuHead[index].count)
			MbStuHead[index].NextStu = p;
		MbStuHead[index].count++;
		StuNode *q = p->NextStu;
		if (q) {
			strcpy(s1, p->BirthTime.c_str());			//��string��ת����char*
			strcpy(s2, q->BirthTime.c_str());
			a1 = (s1[0] - '0') * 10000000000000 + (s1[1] - '0') * 1000000000000 + (s1[2] - '0') * 100000000000 + (s1[3] - '0') * 10000000000 + (s1[5] - '0') * 1000000000 + (s1[6] - '0') * 100000000 + (s1[8] - '0') * 10000000 + (s1[9] - '0') * 1000000 + (s1[11] - '0') * 100000 + (s1[12] - '0') * 10000 + (s1[14] - '0') * 1000 + (s1[15] - '0') * 100 + (s1[17] - '0') * 10 + s1[18] - '0';		//����ʱ�̼�Ȩ���ڱȽ�
			a2 = (s2[0] - '0') * 10000000000000 + (s2[1] - '0') * 1000000000000 + (s2[2] - '0') * 100000000000 + (s2[3] - '0') * 10000000000 + (s2[5] - '0') * 1000000000 + (s2[6] - '0') * 100000000 + (s2[8] - '0') * 10000000 + (s2[9] - '0') * 1000000 + (s2[11] - '0') * 100000 + (s2[12] - '0') * 10000 + (s2[14] - '0') * 1000 + (s2[15] - '0') * 100 + (s2[17] - '0') * 10 + s2[18] - '0';
			if ((q->ParentName != p->ParentName) || (a2 - a1 > 500) || (a2 - a1 < -500)) {
				index++;
				MbStuHead[index].count = 0;
			}
		}
	}
	MbStuHead[index + 1].count = 0;
	StuSort2();
	int n = 1;
	for (int i = 0; i < MAX; ++i) {
		if (!MbStuHead[i].count)
			break;
		if (MbStuHead[i].count != 1) {
			cout << "\t\t\t===================================" << endl;
			cout << "\t\t\t��" << n++ << "����̥���£�" << endl;
			StuNode *p = MbStuHead[i].NextStu;
			for (int j = 0; j < MbStuHead[i].count; ++j) {
				cout << "\t\t\tѧ��������" << p->StudentName << endl << "\t\t\t��ĸ������" << p->ParentName << endl << "\t\t\t����ʱ�̣�" << p->BirthTime << endl << "\t\t\tѧ���Ա�" << p->Sex << endl << "\t\t\t�߿�������" << p->Score << endl << endl;
				p = p->NextStu;
			}
		}
	}
}
int login()
{
	string username = "admin", password = "admin";
	string name, pass;
	int num = 5;
	while (1) {
		cout << "\t\t\t�������û�����";
		cin >> name;
		cout << "\n\t\t\t���������룺";
		cin >> pass;
		if (name != username || pass != password) {
			num--;
			if (num) {
				cout << "\t\t�û������������! �㻹��" << num << "�λ��᳢������" << endl;
			}
			else {
				cout << "\t\t���ˣ��û������������" << endl, exit(0);
			}
		}
		else {
			cout << "********************�ɹ�����********************" << endl << endl;
			return 1;
		}
	}
}

