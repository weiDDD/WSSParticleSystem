#pragma once
#ifndef __FILE_CENTER_H__
#define __FILE_CENTER_H__

#include "cocos2d.h"
#include "mjson/rapidjson.h"
#include "mjson/document.h"
#include "mjson/writer.h"
#include "mjson/stringbuffer.h"

#include "ParticleEmitter.h"

using namespace m_rapidjson;
using namespace pp;

struct fileCacheValue {
	fileCacheValue() {
		value = nullptr;
		isAgainWrited = false;
	}

	m_rapidjson::Document* value;
	bool isAgainWrited;
};

class FileCenter {
public:
	static FileCenter* instance;
	static FileCenter* getInstance();
	bool writeJsonData(std::string fileName , pp::ParticleEmitter* fireData);
	m_rapidjson::Document& readJsonData(std::string fileName);

	std::map<std::string, fileCacheValue> jsonCacheData;

private:

};



#endif // !__FILE_CENTER_H__
