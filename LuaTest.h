#pragma once

struct lua_State;

class test
{
public:
	test();
	~test();

	void Init();

	void test1();
	void test2(int i);
	void test3(const char* string);

	void Set( int i);

	void Execute();

private:
	int a;
	lua_State* L;
};