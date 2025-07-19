#include <bits/stdc++.h>
using namespace std;

class DiscountSystem;
DiscountSystem *g_system;

enum DiscountMode {
	Cash,
	Factor
};


class User {
private:
	unsigned int userid;
	string name;
	string password;
public:
	User(unsigned int id, string name) {
		this->userid = id;
		this->name = name;
	}
	unsigned int UserID() {
		return userid;
	}
	string Name() {
		return name;
	}
	string Password() {
		return password;
	}
};

class StudentUser : public User {
public:
	void GetDiscount() {

	}

	void CheckDiscount() {

	}
	void UseDiscount() {

	}
};

class AdminUser: public User {
public:
	AdminUser(unsigned int id, string name) : User(id, name) {

	}
	bool CreateActivity(int deadline, DiscountMode mode, string identifier) {	
		if (!g_system)
			return false;

		return g_system->CreateActivity(deadline, mode, identifier);
	}
};

class Activity {
private:
	unsigned int actid;
	int num;
	int deadline;
	DiscountMode disconutMode;

	string identifier;

	unsigned int generateID() {
		auto now = std::chrono::system_clock::now();
		auto now_c = std::chrono::system_clock::to_time_t(now);

		// Use tm to break down time into calendar components
		tm now_tm = *std::localtime(&now_c);

		// Use stringstream and put_time to format the date
		stringstream date_stream;
		date_stream << std::put_time(&now_tm, "%Y%m%d") << ++cnt;
		date_stream >> actid;

		return 0;
	}
public:
	static int cnt;
	Activity(int deadline, DiscountMode disconutMode, string identifier) {
		this->actid = generateID();
		this->deadline = deadline;
		this->disconutMode = disconutMode;
		this->identifier  = identifier;
		cnt++;
	}
	int Id() {return actid;}
};


class Coupon {
private:
	int id;
public:
	Coupon(int id) {
		this->id = id;
	}
	int Id() {return id;}
	virtual int calculate(int pay);
};


class CashCoupon : public Coupon {
private:
	int lim;
	int amount;
public:
	CashCoupon(int id, int lim, int amount) : Coupon(id) {
		this->lim = lim;
		this->amount = amount;
	}
	int calculate(int pay) {
		return pay >= lim ? pay - amount : pay;
	}
};

class DiscountCoupon: public Coupon {
private:
	int lim;
	float factor;
public:
	DiscountCoupon(int id, int lim, float discount_factor) : Coupon(id) {
		this->lim = lim;
		this->factor = discount_factor;
	}
	int calculate(int pay) {
		return pay >= lim ? pay * factor : pay;
	}
};

class DiscountSystem {
private:

	vector<User> users;
	vector<AdminUser*> admins;

	vector<Activity> activity;

	map<User*, vector<Coupon>> userCoupon;
	set<User*> onlineUsers;

    DiscountSystem() {

		if (admins.empty()) {
			unsigned int id;
			string name;
			cout << "Admin not found, please create an admin account:" << endl;

			cout << "ID: ";
			cin >> id;

			cin.ignore();
			cout << "Name: ";
			getline(cin, name);

			users.emplace_back(AdminUser(id, name));
			onlineUsers.insert((AdminUser*)&users.front());
			admins.push_back((AdminUser*)&users.front());

			cout << "Admin " << name << '(' << id << ')' << " created";
		}
    }

    DiscountSystem(const DiscountSystem&) = delete;
    DiscountSystem& operator=(const DiscountSystem&) = delete;

public:
	static DiscountSystem& getInstance() {
        static DiscountSystem instance; // Guaranteed to be destroyed and instantiated on first use.
        return instance;
    }

	bool Login(User *user, string password) {
		if (user->Password() == password) {
			cout << "Login as " << user->Name() << endl;
			onlineUsers.insert(user);

			return true;
		} else {
			cout << "Error: Unauthorized login";
			return false;
		}
	}

	bool Login(unsigned int id, string password) {
		for (auto it : users) {
			if (it.UserID() == id) {
				return Login(&it, password);
			}
		}
		cout << "Error: User " << id << " was not found in database";
		return false;
	}

	bool Login(string name, string password) {
		for (auto it : users) {
			if (it.Name() == name) {
				return Login(&it, password);
			}
		}
		cout << "Error: User " << name << " was not found in database";
		return false;
	}

	bool CreateActivity(int deadline, DiscountMode mode, string identifier) {
		activity.emplace_back(deadline, mode, identifier);
		return true;
	}
};


int main() {
	g_system->getInstance();

	return 0;
}