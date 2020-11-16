#ifndef REGISTER_H
#define REGISTER_H
class Register
{
public:
	Register();
	~Register();
	void write(int value);
	int read();
	bool getRead();
	bool getWrote();
	bool clearHistory();
private:
	int value;
	bool read;
	bool wrote;
};
#endif // !REGISTER_H
