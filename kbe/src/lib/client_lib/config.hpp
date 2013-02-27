/*
This source file is part of KBEngine
For the latest info, see http://www.kbengine.org/

Copyright (c) 2008-2012 KBEngine.

KBEngine is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

KBEngine is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.
 
You should have received a copy of the GNU Lesser General Public License
along with KBEngine.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef __CLIENT_CONFIG_H__
#define __CLIENT_CONFIG_H__
// common include
#include "cstdkbe/cstdkbe.hpp"
#if KBE_PLATFORM == PLATFORM_WIN32
#pragma warning (disable : 4996)
#endif

#include "cstdkbe/singleton.hpp"
#include "thread/threadmutex.hpp"
#include "thread/threadguard.hpp"
#include "xmlplus/xmlplus.hpp"	
	
namespace KBEngine{

class Config : public Singleton<Config>
{
public:
	Config();
	~Config();
	
	bool loadConfig(std::string fileName);
	
	inline int16 gameUpdateHertz(void)const { return gameUpdateHertz_;}

	uint32 tcp_SOMAXCONN();

	const char* entryScriptFile()const{ return &entryScriptFile_[0]; }

	const char* accountName()const{ return &accountName_[0]; }

	const char* ip()const{ return &ip_[0]; }
	uint32 port()const{ return port_; }

	void writeAccountName(const char* name);

	bool useLastAccountName()const{ return useLastAccountName_; }
public:
	int16 gameUpdateHertz_;

	uint32 tcp_SOMAXCONN_;									// listen监听队列最大值
	
	uint32 port_;											// 组件的运行后监听的端口
	char ip_[MAX_BUF];										// 组件的运行期ip地址

	char entryScriptFile_[MAX_NAME];						// 组件的入口脚本文件

	float channelInternalTimeout_;
	float channelExternalTimeout_;

	char accountName_[MAX_NAME];

	std::string fileName_;

	bool useLastAccountName_;
};

#define g_kbeConfig Config::getSingleton()
}
#endif
