#pragma once
#ifndef __FILE_CENTER_H__
#define __FILE_CENTER_H__

#include "cocos2d.h"
#include "json/rapidjson.h"
#include "json/document.h"
#include "json/writer.h"
#include "json/stringbuffer.h"

#include "ParticleEmitter.h"

using namespace rapidjson;
using namespace pp;

struct fileCacheValue {
	fileCacheValue() {
		value = nullptr;
		isAgainWrited = false;
	}

	rapidjson::Document* value;
	bool isAgainWrited;
};

class FileCenter {
public:
	static FileCenter* instance;
	static FileCenter* getInstance();
	bool writeJsonData(std::string fileName , pp::ParticleEmitter* fireData);
	rapidjson::Document& readJsonData(std::string fileName);

	std::map<std::string, fileCacheValue> jsonCacheData;

private:

};



#endif // !__FILE_CENTER_H__
