#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int n, m;
unordered_map<int, set<int>> studentRequests;
unordered_map<int, set<int>> studentAssigments;
map<int, vector<int>> results;
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
 
	cin >> n >> m;
 
	int id, length, assigment;
	for(int i=0; i<n; ++i) {
		cin >> id >> length;
		
		for(int j=0; j<length; ++j) {
			cin >> assigment;
			studentRequests[id].insert(assigment);
		}
	}
 
	for(int i=0; i<m; ++i) {
		cin >> id >> length;
		for(int j=0; j<length; ++j) {
			cin >> assigment;
			studentAssigments[id].insert(assigment);
		}
	}
	
	int notRequested = 0, missed = 0;	
	for(const pair<int, set<int>> student: studentRequests) {
		const int id = student.first;
		for(int assigment: student.second) {
			auto it = studentAssigments[id].find(assigment);
			if(it == studentAssigments[id].end()) {
				results[id].push_back(assigment);
				missed++;
			} else {
				studentAssigments[id].erase(it);
			}
		}
	}
 
	for(const pair<int, set<int>> student: studentAssigments) {
		const int id = student.first;
		for(int assigment: student.second) {
			auto it = studentRequests[id].find(assigment);
			if(it == studentRequests[id].end()) {
				results[id].push_back(-assigment);
				notRequested++;
			}
		}
	}
 
	for(pair<int, vector<int>> result: results) {
		const int id = result.first;
		sort(result.second.begin(), result.second.end(), [](int a, int b) {return (abs(a) < abs(b));});
 
		cout << id;
		for(int assigment: result.second) {
			cout << ' ' << (assigment > 0 ? "+" : "") << assigment;
		}
		cout << endl;
	}
 
	if(results.empty())
		cout << "GREAT WORK! NO MISTAKES FOUND!" << endl;
	else
		cout << "MISTAKES IN " << results.size() << " STUDENTS: " << notRequested << " NOT REQUESTED, " << missed << " MISSED" << endl;
 
	return 0;
}

