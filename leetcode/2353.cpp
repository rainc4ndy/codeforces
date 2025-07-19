#include <bits/stdc++.h>
using namespace std;

class FoodRatings {

	typedef pair<int, string> P;

	struct cmp {
	    bool operator() (const P& a, const P& b) const {
	        if (a.first == b.first) {
				return a.second < b.second;
			}
			return a.first > b.first;
	    }
	};

	unordered_map<string, int> r; 
	unordered_map<string, string> c;
	unordered_map<string, set<P, cmp>> rbt;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
    	int sz = ratings.size();

    	for (int i = 0; i < sz; i++) {
    		r[foods[i]] = ratings[i];
    		c[foods[i]] = cuisines[i];
    		rbt[cuisines[i]].insert(P(ratings[i], foods[i]));
    	}
    }
    
    void changeRating(string food, int newRating) {
    	string cuisine = c[food];
    	rbt[cuisine].erase(P(r[food], food));
    	rbt[cuisine].insert(P(newRating, food));
    	r[food] = newRating;
    }
    
    string highestRated(string cuisine) {
    	return rbt[cuisine].begin()->second;
    }
};

int main() {
	vector<string> v1 = {
"emgqdbo","jmvfxjohq","qnvseohnoe","yhptazyko","ocqmvmwjq"
	}, v2 = {
"snaxol","snaxol","snaxol","fajbervsj","fajbervsj"
	};

	vector<int> v3 = {
2,6,18,6,5
	};
	FoodRatings f(v1, v2, v3);
	f.changeRating("qnvseohnoe", 11);
	f.changeRating("emgqdbo", 3);
	f.changeRating("jmvfxjohq", 9);
	f.changeRating("emgqdbo", 14);
	cout << f.highestRated("fajbervsj") << endl;
	cout << f.highestRated("snaxol") << endl;
}