
#ifdef _DEBUG
#pragma comment( lib, "lua5.1_D.lib")
#else
#pragma comment( lib, "lua5.1.lib")
#endif

#include "LuaTest.h"

#include <iostream>
#include <assert.h>
#include <lua.hpp>
#include <luabind/luabind.hpp>

using namespace std;

test::test() :
	a( 0),
	L( NULL)
{}

test::~test()
{
	lua_getglobal( L, "Destruct");
	if( lua_pcall( L, 0, 0, NULL) != 0){
		cout << lua_tostring( L, -1) << endl;
		lua_pop( L, 1);
	}

	lua_close( L);
}

void test::Init()
{
	L = lua_open();

	if( luaL_dofile( L, "LuaTest.lua") != 0){
		cout << lua_tostring( L, -1) << endl;
		exit( -1);
	}
	
	luaL_openlibs( L);

	luabind::open( L);

	luabind::module( L) [
		luabind::class_< test >( "test")
			.def(luabind::constructor<>() )
			.def( "test1",&test::test1)
			.def( "test2",&test::test2)
			.def( "test3",&test::test3)
			.def( "Set",&test::Set)
	];

	luabind::call_function<void>( L, "Init");
}

void test::test1()
{
	cout << a << endl;
}

void test::test2(int i)
{
	cout << i << endl;
}

void test::test3(const char *string)
{
	cout << string << endl;
}

void test::Set(int i)
{
	a = i;
}

void test::Execute()
{
	luabind::call_function<void>( L, "Execute", this);
}