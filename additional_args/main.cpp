#include <iostream>

using namespace std;

enum class selector {
	option1, option2, option3, option_none
};


template<selector>
class additional_args{ public:int& z() { return m_z; }
};

template<>
class additional_args<selector::option1> {

private:
	
public:
	additional_args() {}

};

template<>
class additional_args<selector::option2>{

private:
	int  m_y;

public:
	additional_args() {}

	additional_args(int y) : m_y(y) {}

	int& y() { return m_y; }

};

template<>
class additional_args<selector::option3> {

private:
	int  m_y, m_z;

public:
	additional_args(int y, int z) : m_y(y), m_z(z) {}

	int& y() { return m_y; }
	int& z() { return m_z; }

};

void do_stuff(int x, additional_args<selector::option1> aa) {
	
	cout << "option1: " << x << endl;
	cout << "aa :: y, z not defined" << endl;

}

void do_stuff(int x, additional_args<selector::option2> aa) {
	cout << "option2: " << x;
	cout << "y is : " << aa.y();
	cout << "aa :: z not defined" << endl;
}

void do_stuff(int x, additional_args<selector::option3> aa) {
	cout << "option3: " << x;
	cout << "y is: " << aa.y();
	cout << "z is: " << aa.z();
}

int main() {

	do_stuff(5, additional_args<selector::option1>());

	return 0;
}