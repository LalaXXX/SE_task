#pragma once
#include <string>
#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;
#define MAX 100
typedef struct StuNode {
	string StudentName;				//学生姓名
	string ParentName;				//父母姓名
	string BirthTime;				//出生日期、时刻
	string Sex;						//性别
	int Score;						//高考分数
	struct StuNode *NextStu;		//节点指针
	int count;						//头节点记录学生数量
} StuNode;
typedef struct MbNode {				//多胞胎邻接表节点
	int count;
	StuNode *NextStu;
}MbNode;
class StuInfo {
	StuNode *ListHead;
	MbNode MbStuHead[10];
public:
	StuInfo();							//构造函数
	~StuInfo();							//析构函数
	void CreatInfo();					//创建学生信息
	void StuInsert(StuNode *p);			//添加学生信息
	void StuRead();						//从文件读入学生信息
	void StuDelete(string SName);		//删除学生信息
	StuNode* StuFind(string SName);		//查询学生信息
	void StuUpdate(StuNode *p);			//修改学生信息
	void StuSort1();					//按父母姓名将学生排序
	void StuSort2();					//按学生出生时刻将学生排序
	void StuIdentify();					//识别多胞胎学生
};
StuInfo::StuInfo()	//构造函数
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
	cout << "\t\t******   多 胞 胎 新 生 识 别 系 统  ******" << endl;
	cout << "\t\t******       (首次使用请选择1)       ******" << endl;
	cout << "\t\t******       1.录入新的学生信息      ******" << endl;
	cout << "\t\t******       2.添加新的学生信息	  ******" << endl;
	cout << "\t\t******       3.文件读入学生信息	  ******" << endl;
	cout << "\t\t******       4.识别出多胞胎新生信息  ******" << endl;
	cout << "\t\t******       5.删除已有新生信息      ******" << endl;
	cout << "\t\t******       6.查找已有新生信息      ******" << endl;
	cout << "\t\t******       7.修改已有新生信息      ******" << endl;
	cout << "\t\t******       0.安全退出系统          ******" << endl;
	cout << "\t\t*******************************************" << endl;
	cout << "\n\t\n\t\t请选择：";
}
void StuInfo::CreatInfo()		//创建学生信息表 （尾插法）
{
	system("CLS");
	int n;
	StuNode *p = ListHead, *q;
	while (1) {
		q = new StuNode;
		cout << "请输入学生姓名： " << endl;
		cin >> q->StudentName;
		cout << "\n请输入学生父母姓名（父亲姓名在前，中间用&隔开）:  " << endl;
		cin >> q->ParentName;
		cout << "\n请输入学生出生日期、时刻 （请按照格式为xxxx-xx-xx@xx:xx:xx输入）:  " << endl;
		cin >> q->BirthTime;
		cout << "\n请输入学生性别: " << endl;
		cin >> q->Sex;
		cout << "\n请输入学生高考分数: " << endl;
		cin >> q->Score;
		q->NextStu = NULL;
		p->NextStu = q;
		ListHead->count++;
		p = p->NextStu;
		cout << "继续录入请输入1， 停止录入请输入0" << endl;
		cin >> n;
		if (!n) break;
		system("CLS");
	}
}
void StuInfo::StuInsert(StuNode *p)	//添加学生信息 （头插法）
{
	p->NextStu = ListHead->NextStu;
	ListHead->NextStu = p;
	ListHead->count++;
}
void StuInfo::StuRead()		//从文件读取学生信息
{
	system("CLS");
	ifstream file("StudentInfo.txt");
	if (!file) {
		cout << "未找到学生信息" << endl;
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
	q = ListHead;		//q为p的跟随指针
	p = q->NextStu;
	while (p && p->StudentName != SName) {
		q = p;
		p = p->NextStu;
	}
	if (p->StudentName == SName) {
		q->NextStu = p->NextStu;
		ListHead->count--;
		cout << "删除成功" << endl;
		delete p;
	}
	else {
		cout << "未查到该学生信息" << endl;
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
		cout << "未找到此学生信息！" << endl;
		return NULL;
	}
}
void StuInfo::StuUpdate(StuNode *p)	//修改学生信息
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
void StuInfo::StuSort1()		//按父母姓名排序
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
void StuInfo::StuSort2()		//按学生姓名排序
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
void StuInfo::StuIdentify()							//多细胞识别
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
			strcpy(s1, p->BirthTime.c_str());			//将string类转换成char*
			strcpy(s2, q->BirthTime.c_str());
			a1 = (s1[0] - '0') * 10000000000000 + (s1[1] - '0') * 1000000000000 + (s1[2] - '0') * 100000000000 + (s1[3] - '0') * 10000000000 + (s1[5] - '0') * 1000000000 + (s1[6] - '0') * 100000000 + (s1[8] - '0') * 10000000 + (s1[9] - '0') * 1000000 + (s1[11] - '0') * 100000 + (s1[12] - '0') * 10000 + (s1[14] - '0') * 1000 + (s1[15] - '0') * 100 + (s1[17] - '0') * 10 + s1[18] - '0';		//出生时刻加权用于比较
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
			cout << "\t\t\t第" << n++ << "组多胞胎如下：" << endl;
			StuNode *p = MbStuHead[i].NextStu;
			for (int j = 0; j < MbStuHead[i].count; ++j) {
				cout << "\t\t\t学生姓名：" << p->StudentName << endl << "\t\t\t父母姓名：" << p->ParentName << endl << "\t\t\t出生时刻：" << p->BirthTime << endl << "\t\t\t学生性别：" << p->Sex << endl << "\t\t\t高考分数：" << p->Score << endl << endl;
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
		cout << "\t\t\t请输入用户名：";
		cin >> name;
		cout << "\n\t\t\t请输入密码：";
		cin >> pass;
		if (name != username || pass != password) {
			num--;
			if (num) {
				cout << "\t\t用户名或密码错误! 你还有" << num << "次机会尝试输入" << endl;
			}
			else {
				cout << "\t\t坏人！用户名或密码错误" << endl, exit(0);
			}
		}
		else {
			cout << "********************成功登入********************" << endl << endl;
			return 1;
		}
	}
}

