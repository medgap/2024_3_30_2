#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>
#include<map>
#include<string>
#include<ctime>
#include<vector>

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

using namespace std;

class Person {
public:
	Person(){}
	string name;
	int welfare;
};


void createPerson(vector<Person>& v) {
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++) {
		Person p;
		string name = "Ա��";
		p.name = name + nameSeed[i];
		p.welfare = rand() % 10000 + 10000;
		v.push_back(p);
	}
}

void setGroup(vector<Person>& v, multimap<int, Person>& m) {
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		int depId = rand() % 3;
		m.insert(make_pair(depId, *it));
	}
}

void showInfoByGroup(multimap<int, Person>& m) {
	int num = 0;
	//�߻�
	cout << "�߻����ţ�" << endl;
	multimap<int, Person>::iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA);
	for (num = 0; num < count && pos != m.end(); pos++, num++) {
		cout << "����:   " << pos->second.name << " ����:  " << pos->second.welfare << endl;
	}

	cout << "----------------------" << endl;
	cout << "�������ţ� " << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU);
	for (num = 0; num < count && pos != m.end(); pos++, num++) {
		cout << "����:   " << pos->second.name << " ����:  " << pos->second.welfare << endl;
	}

	cout << "----------------------" << endl;
	cout << "�з����ţ� " << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA);
	for (num = 0; num < count && pos != m.end(); pos++, num++) {
		cout << "����:   " << pos->second.name << " ����:  " << pos->second.welfare << endl;
	}
}

int main() {
	srand((unsigned int)time(NULL));
	vector<Person> v;
	createPerson(v);
	//test
	/*for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "Ա������ :  " << it->name << "  Ա������ :  " << it->welfare << endl;
	}*/
	multimap<int, Person> mp;
	setGroup(v, mp);
	showInfoByGroup(mp);
	return 0;
}