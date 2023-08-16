// 通讯录.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#define MAX 1000
using namespace std;

//联系人结构体
struct Person {
	
	string m_name;
	int m_sex;
	int m_age;
	string m_num;
	string m_Addr;

};

//通讯录结构体
struct Addressbooks {
	//保存联系人数组
	struct Person personArray[MAX];

	//当前联系人个数
	int m_Size; 

};



//添加联系人
void addPerson(Addressbooks* abs) {
	//判断通讯录是否为满
	if (abs->m_Size == MAX) {
		cout << "通讯录已满！" << endl;
		return;
	}
	else {
		string name;
		cout << "请输入姓名： " << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_name = name;

		//性别
		cout << "请输入性别： " << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;
		int sex = 0;

		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) { 
				abs->personArray[abs->m_Size].m_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入！" << endl; 
		}
		//年龄
		cout << "请输入年龄： " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_age = age;

		//电话号码
		cout << "请输入电话号码： " << endl;
		string num;
		cin >> num;
		abs->personArray[abs->m_Size].m_num = num;

		//住址
		cout << "请输入家庭住址： " << endl;
		string Addr;
		cin >> Addr;
		abs->personArray[abs->m_Size].m_Addr = Addr;//存放在数组中

		//更新通讯录人数
		abs->m_Size++;

		cout << "添加成功！" << endl;

		system("pause");
		system("cls");//清空

	}
}

//显示联系人
void showPerson(Addressbooks * abs)
{
	if (abs->m_Size == 0) {
		cout << "当前记录为空！" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "姓名： " << abs->personArray[i].m_name << "\t";
			cout << "性别： " << (abs->personArray[i].m_sex == 1 ?"男":"女") << "\t";
			cout << "年龄： " << abs->personArray[i].m_age << "\t";
			cout << "电话： " << abs->personArray[i].m_num << "\t";
			cout << "住址： " << abs->personArray[i].m_Addr << endl;
		}
	}

	system("pause");
	system("cls");
}

//检测联系人是否存在，存在则返回具体位置，不存在返回-1
int isExist(Addressbooks* abs, string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_name == name) {
			return i;//找到了则返回这个人在数组中下表编号
		}
	}
	return -1;//没有找到返回-1
}

//删除联系人
void deletePerson(Addressbooks* abs) {
	cout << "请输入您要删除的联系人" << endl;

	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1) {
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功！" << endl;
	}
	else {
		cout << "查无此人！" << endl;

	}
	system("pause");
	system("cls");
}

//查找联系人信息
void findPerson(Addressbooks* abs) {
	cout << "请输入需要查找的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1) {
		cout << "姓名： " << abs->personArray[ret].m_name << "\t";
		cout << "性别： " << (abs->personArray[ret].m_sex == 1 ? "男" : "女") << "\t";
		cout << "年龄： " << abs->personArray[ret].m_age << "\t";
		cout << "电话： " << abs->personArray[ret].m_num << "\t";
		cout << "住址： " << abs->personArray[ret].m_Addr << endl;
	}
	else {
		cout << "没有找到该联系人！" << endl;
	}
	system("pause");
	system("cls");

}

//修改联系人
void modifyPerson(Addressbooks* abs) {
	cout << "请输入需要修改的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1) {
		//姓名
		cout << "请输入姓名： " << endl;
		string name;
		cin >> name;
		abs->personArray[ret].m_name = name;

		//性别
		cout << "请输入性别： " << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
		if (sex == 1 || sex == 2) {
			abs->personArray[ret].m_sex = sex;
			break;
		}
		cout << "输入有误，重新输入！" << endl;
		}
		
		//年龄
		cout << "请输入年龄： " << endl;
		int age;
		cin >> age;
		abs->personArray[ret].m_age = age;

		//电话
		cout << "请输入联系电话： " << endl;
		string num;
		cin >> num;
		abs->personArray[ret].m_num = num;

		//地址
		cout << "请输入地址： " << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
		
		cout << "修改成功！" << endl;
	}
	else {
		cout << "查无此人！" << endl; 
	}

	system("pause");
	system("cls");

}

//清空所有联系人
void cleanPerson(Addressbooks* abs) {
	abs->m_Size = 0;
	cout << "所有联系人已清空！" << endl;

	system("pause");
	system("cls");
}

void showMenu() {
	cout << "****************************" << endl;
	cout << "*****	1、添加联系人	*****" << endl;
	cout << "*****	2、显示联系人	*****" << endl;
	cout << "*****	3、删除联系人	*****" << endl;
	cout << "*****	4、查找联系人	*****" << endl;
	cout << "*****	5、修改联系人	*****" << endl;
	cout << "*****	6、清空联系人	*****" << endl;
	cout << "*****	0、退出通讯录	*****" << endl;
	cout << "****************************" << endl;

}

int main()
{
	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录中当前人员数
	abs.m_Size = 0;


	int select = 0;
	
	while (true) {
		showMenu();

		cin >> select;
		switch (select)
		{
		case 1:
			addPerson(&abs);//地址传递修饰实参
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3:
			deletePerson(&abs);
			break;
		case 4:
			findPerson(&abs);
			break;
		case 5:
			modifyPerson(&abs);
			break;
		case 6:
			cleanPerson(&abs);
			break;
		case 0:
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	

	system("pause");
	return 0;
	
}

