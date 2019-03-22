#include"pch.h"
#include<iostream>
#include<cstdio>
#include<string>
#include<stack>
#include<queue>
#include<map>

using namespace std;

struct node {
	double num;
	char op;
	bool flag;
};

string str;
stack<node> s;//操作符栈
queue<node> q;//后缀表达式
map<char, int> op;

void change() {
	node temp;
	for (int i = 0; i < str.length();) {
		if (str[i] >= '0' && str[i] <= '9') {
			temp.flag = true;
			temp.num = str[i++] - '0';
			while (i < str.length() && str[i] >= '0'&&str[i] <= '9') {
				temp.num = temp.num * 10 + (str[i] - '0');
				i++;
			}
			q.push(temp);
		}
		else {
			temp.flag = false;
			while (!s.empty() && op[str[i]] <= op[s.top().op]) {
				q.push(s.top());
				s.pop();
			}
			temp.op = str[i];
			s.push(temp);
			i++;
		}
	}
	while (!s.empty()) {
		q.push(s.top());
		s.pop();
	}
}

void cal() {
	node cur, temp;
	double temp1, temp2;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		if (cur.flag == true) {
			s.push(cur);
		}
		else {
			temp1 = s.top().num;
			s.pop();
			temp2 = s.top().num;
			s.pop();
			switch (cur.op) {
			case '+':
				temp.num = temp1 + temp2;
				temp.flag = true;
				break;
			case '-':
				temp.num = temp2 - temp1;
				temp.flag = true;
				break;
			case '*':
				temp.num = temp1 * temp2;
				temp.flag = true;
				break;
			case '/':
				temp.num = temp2 / temp1;
				temp.flag = true;
				break;
			}
			s.push(temp);
		}
	}
 }

int main() {
	op['+'] = op['-'] = 1;
	op['*'] = op['/'] = 2;
	cin >> str;
	while (!s.empty()) {
		s.pop();
	}
	change();
	cal();
	printf(".2f", s.top().num);
}