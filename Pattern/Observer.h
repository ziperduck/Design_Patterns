#pragma once
#include <iostream>
#include <vector>

class Observer {
public:
	~Observer() = default;
	virtual void OnNotify(std::string st) = 0;
};

class Achievements_Alphbet : public Observer {
public:
	void OnNotify(const std::string st) final {
		if ('a' <= st.front() && 'z' >= st.front())
		{
			printf("key pressed %c clear\n", st.front());
		}
	}
};

class Achievements_a : public Observer {
public:
	void OnNotify(const std::string st)final {
		if ('a' == st.front())
		{
			printf("yes your pressed a\n");
		}
	}
};

class Subject {
public:
	void addObserver(Observer* obs) {
		ob.push_back(obs);
	}
	void removeObserver(Observer* obs) {
		const auto fin = std::find(ob.begin(), ob.end(), obs);
		if (fin != ob.end())
		{
		ob.erase(fin);
		}
	}

	void notify(std::string st) {
		for (auto i = ob.begin(); i != ob.end(); i++)
		{
			(*i)->OnNotify(st);
		}
	}
private:
	std::vector<Observer*> ob;
};

class Player_Keyboard {
public:
	Player_Keyboard(Subject* su) : sb(su){

	}
	bool PressedKey(const std::string st) {
		printf("Pressed Key %c \n", st.front());
		if ('a' <= st.front() && 'z' >= st.front())
		{
			sb->notify(st);
			return true;
		}
		return false;
	}
private:
	Subject* sb;
};

void Observer_Main() {
	Achievements_a a;
	Achievements_Alphbet al;
	Subject su;
	su.addObserver(&a);
	su.addObserver(&al);
	Player_Keyboard pk{ &su };
	std::string st;
	st.push_back(getchar());
	getchar();

	while (pk.PressedKey(st))
	{
		st.clear();
		st.push_back(getchar());
		getchar();
	}
}