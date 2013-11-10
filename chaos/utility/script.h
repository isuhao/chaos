/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _CHAOS_SCRIPT_H_
#define _CHAOS_SCRIPT_H_

/*!
 *  @file           script.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date           2013.11.9
 *  @brief          script
 *  @last changed
 *
 */

#include <string>

#include <chaos/utility/noncopyable.h>
#include <chaos/deps/lua_tinker/lua_tinker.h>

namespace chaos
{

namespace utility
{

using namespace std;

class script : private noncopyable_t
{
public:
	script();
    virtual ~script();
    void add_package_path(const string& path_);
	void run_script(const char *);
	void do_file(const char *);
	void reload();

    virtual void register_lua_interface();

protected:
	lua_State * _L;
    std::string _pkg_path;
	std::string _scriptName;

public:
	lua_tinker::table get_table();
	lua_tinker::table get_table(int index);
	lua_tinker::table get_table(const char * name);

	template<typename T>
	void set(const char* name, T object);

	template<typename T>
	T get(const char* name);

	template<typename F>
	void def(const char * name, F func);

	template<typename T>
	void decl(const char* name, T object);

	template<typename RVal>
	RVal call(const char* name);
	template<typename RVal, typename T1>
	RVal call(const char* name, T1 arg1);
	template<typename RVal, typename T1, typename T2>
	RVal call(const char* name, T1 arg1, T2 arg2);
	template<typename RVal, typename T1, typename T2, typename T3>
	RVal call(const char* name, T1 arg1, T2 arg2, T3 arg3);
	template<typename RVal, typename T1, typename T2, typename T3, typename T4>
	RVal call(const char* name, T1 arg1, T2 arg2, T3 arg3, T4 arg4);
	template<typename RVal, typename T1, typename T2, typename T3, typename T4, typename T5>
	RVal call(const char* name, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5);

	template<typename T>
	void class_add(const char * name);

	template<typename T, typename P>
	void class_inh();

	template<typename T, typename F>
	void class_con(F func);

	template<typename T, typename F>
	void class_def(const char * name, F func);

	template<typename T, typename BASE, typename VAR>
	void class_mem(const char* name, VAR BASE::*val);
};

template<typename T>
T script::get( const char* name )
{
	return lua_tinker::get<T>(_L, name);
}

template<typename T>
void script::set( const char* name, T object )
{
	lua_tinker::set(_L, name, object);
}

template<typename RVal>
RVal script::call( const char* name )
{
	return lua_tinker::call<RVal>(_L, name);
}

template<typename RVal, typename T1>
RVal script::call(const char* name, T1 arg1)
{
	return lua_tinker::call<RVal>(_L, name, arg1);
}

template<typename RVal, typename T1, typename T2>
RVal script::call(const char* name, T1 arg1, T2 arg2)
{
	return lua_tinker::call<RVal>(_L, name, arg1, arg2);
}

template<typename RVal, typename T1, typename T2, typename T3>
RVal script::call(const char* name, T1 arg1, T2 arg2, T3 arg3)
{
	return lua_tinker::call<RVal>(_L, name, arg1, arg2, arg3);
}

template<typename RVal, typename T1, typename T2, typename T3, typename T4>
RVal script::call(const char* name, T1 arg1, T2 arg2, T3 arg3, T4 arg4)
{
	return lua_tinker::call<RVal>(_L, name, arg1, arg2, arg3, arg4);
}

template<typename RVal, typename T1, typename T2, typename T3, typename T4, typename T5>
RVal script::call(const char* name, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5)
{
	return lua_tinker::call<RVal>(_L, name, arg1, arg2, arg3, arg4, arg5);
}

template<typename T>
void script::decl( const char* name, T object )
{
	return lua_tinker::decl(_L, name, object);
}

template<typename F>
void script::def( const char * name, F func )
{
	lua_tinker::def(_L, name, func);
}

template<typename T, typename F>
void script::class_def( const char * name, F func )
{
	lua_tinker::class_def<T>(_L, name, func);
}

template<typename T, typename F>
void script::class_con( F func )
{
	lua_tinker::class_con<T>(_L, func);
}

template<typename T, typename P>
void script::class_inh()
{
	lua_tinker::class_inh<T, P>(_L);
}

template<typename T>
void script::class_add( const char * name )
{
	lua_tinker::class_add<T>(_L, name);
}

template<typename T, typename BASE, typename VAR>
void script::class_mem( const char* name, VAR BASE::*val )
{
	lua_tinker::class_mem<T>(_L, name, val);
}

}

}

#endif // _CHAOS_SCRIPT_H_
