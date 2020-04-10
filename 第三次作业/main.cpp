#include "MultipleBirthsSystem.h"
int main()
{
	StuInfo stu;
	cout << "\t\t**************************************************" << endl;
	cout << "\t\t**************************************************" << endl;
	cout << "\t\t*******                                    *******" << endl;
	cout << "\t\t*******   欢迎进入多胞胎新生自动识别系统   *******" << endl;
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
			stu.CreatInfo();	//批量输入学生信息
			break;
		case 2:
			system("CLS");
			cout << "请输入学生姓名： " << endl;
			cin >> q->StudentName;
			cout << "\n请输入学生父母姓名（父亲姓名在前，中间用&隔开）：	" << endl;
			cin >> q->ParentName;
			cout << "\n请输入学生出生日期、时刻 （请按照格式为xxxx-xx-xx@xx:xx:xx输入）: " << endl;
			cin >> q->BirthTime;
			cout << "\n请输入学生性别: " << endl;
			cin >> q->Sex;
			cout << "\n请输入学生高考分数: " << endl;
			cin >> q->Score;
			stu.StuInsert(q);		//添加学生信息
			break;
		case 3:
			stu.StuRead();			//文件读取学生信息
			break;
		case 4:
			stu.StuIdentify();		//多胞胎自动识别功能
			break;
		case 5:
			system("CLS");
			cout << "请输入要删除学生姓名： " << endl;
			cin >> name;
			stu.StuDelete(name);		//删除该学生信息
			break;
		case 6:
			system("CLS");
			cout << "请输入要查找学生姓名： " << endl;
			cin >> name;
			q = stu.StuFind(name);		//查询学生信息
			cout << "该学生的姓名为： " << q->StudentName << endl;
			cout << "该学生的父母姓名为： " << q->ParentName << endl;
			cout << "该学生的出生时刻为： " << q->BirthTime << endl;
			cout << "该学生的学生性别为： " << q->Sex << endl;
			cout << "该学生的高考分数为： " << q->Score << endl;
			break;
		case 7:
			system("CLS");
			cout << "请输入需要修改的学生姓名： " << endl;
			cin >> q->StudentName;
			cout << "\n请输入学生父母姓名（父亲姓名在前，中间用&隔开）:	" << endl;
			cin >> q->ParentName;
			cout << "\n请输入学生出生日期、时刻 （请按照格式为xxxx-xx-xx@xx:xx:xx输入）: " << endl;
			cin >> q->BirthTime;
			cout << "\n请输入学生性别: " << endl;
			cin >> q->Sex;
			cout << "\n请输入学生高考分数: " << endl;
			cin >> q->Score;
			stu.StuUpdate(q);			//修改学生信息
			break;
		case 0:
			break;
		default:
			cout << "输入错误，请按规定输入！";
			break;
		}
		if (!n)	break;
		cout << "\n\t\t\t 返回上层首页请输入1, 退出系统请输入0:" ;
		cin >> x;
	}
}
