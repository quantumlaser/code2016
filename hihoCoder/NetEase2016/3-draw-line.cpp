#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;
struct Line {
	int type;
	int C;
	int start;
	int stop;
};

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
bool comp(Line *line1, Line *line2) {
	if (line1->type != line2->type) {
		return line1->type < line2->type;
	}
	if (line1->C != line2->C) {
		return line1->C < line2->C;
	}
	return line1->start < line2->start;
}

int drawLine(vector<Line*> vec) {
	int num = vec.size();
	int res = num;
	int type, C;
	unsigned int j;
	int stopPos;
	for (unsigned int i = 0; i < num; ) {
		type = vec[i]->type;
		C = vec[i]->C;
		stopPos = vec[i]->stop;
		j = i + 1;
		while (j < num && vec[j]->type == type && vec[j]->C == C) {
			if (vec[j]->start <= stopPos) {
				res--;
			}
			stopPos = max(stopPos, vec[j]->stop);
			j++;
		}
		i = j;
	}
	return res;
}

int main() {
	// #define Str3
#ifndef Str3
	std::ifstream in("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf();
	std::cin.rdbuf(in.rdbuf());
	// std::ofstream log("output1.txt");
	// std::streambuf* x = std::cout.rdbuf(log.rdbuf());
#endif
	int S;
	int N;
	int x0, y0, x1, y1;
	vector<Line* > vec;
	Line *line;
	/*
	xy.push_back(3);
	vec.push_back(xy);
	xy.clear();
	xy.push_back(4);
	xy.push_back(5);
	vec.push_back(xy);
	xy.clear();
	cout<<vec[0][0]<<" "<<vec[1][1]<<endl;
	*/
	cin >> S;
	while (S--) {
		cin >> N;
		vec.clear();
		while (N--) {
			cin >> x0 >> y0 >> x1 >> y1;
			line = new Line;
			if (x0 == x1) {
				line->type = 0;
				line->C = x0;
				line->start = y0 < y1 ? y0 : y1;
				line->stop = y0 < y1 ? y1 : y0;
			}
			else {
				if (y0 == y1) {
					line->type = 1;
					line->C = y0;

				}
				else {
					if (x0 + y0 == x1 + y1) {
						line->type = 2;
						line->C = x0 + y0;
					} else {
						line->type = 3;
						line->C = x0 - y0;
					}
				}
				line->start = x0 < x1 ? x0 : x1;
				line->stop = x0 < x1 ? x1 : x0;
			}
			vec.push_back(line);
		}
		sort(vec.begin(), vec.end(), comp);
		for (unsigned int i = 0; i<vec.size(); i++) {
			cout << vec[i]->type<< " "<<vec[i]->C<<" ";
			cout << vec[i]->start << " " << vec[i]->stop << endl;
		}
		cout << drawLine(vec) << endl;
		cout << endl;
	}
}