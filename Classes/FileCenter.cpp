#include "FileCenter.h"

using namespace cocos2d;

FileCenter* FileCenter::instance = nullptr;
FileCenter* FileCenter::getInstance() {
	if (!instance) {
		instance = new FileCenter();
	}
	return instance;
}


bool FileCenter::writeJsonData(std::string fileName, pp::ParticleEmitter* fireData) {
	rapidjson::Document* writedoc;


	writedoc = new rapidjson::Document();
	writedoc->SetArray();
	
	auto itor = jsonCacheData.find(fileName);
	if (itor != jsonCacheData.end()) {
		itor->second.isAgainWrited = true;
	}
		

	//rapidjson::Document writedoc;
	//
	
	rapidjson::Document::AllocatorType allocator = writedoc->GetAllocator();

	//rapidjson::Value object(rapidjson::kObjectType);

	if (fireData) {
		bool isSuc = fireData->writeJsonData(*writedoc, allocator);
	}

	////添加一个对象
	//writedoc.AddMember("data", object, allocator);

	StringBuffer buffer;
	rapidjson::Writer<StringBuffer> writer(buffer);
	writedoc->Accept(writer);

	auto path = FileUtils::getInstance()->getWritablePath();
	path.append(fileName);  

	//FILE* file = fopen(path.c_str(), "wb+");
	FILE* file = fopen(fileName.c_str(), "wb+");
	if (file) {
		fputs(buffer.GetString(), file);
		fclose(file);
	}
	CCLOG("%s", buffer.GetString());

	

	return true;
}

rapidjson::Document& FileCenter::readJsonData(std::string fileName) {
	//auto path = FileUtils::getInstance()->getWritablePath();
	//path.append(fileName);

	auto path = fileName;

	//////读取json文件
	//static rapidjson::Document readdoc;
	
	rapidjson::Document* readdoc = nullptr;

	auto itor = jsonCacheData.find(fileName);
	if (itor != jsonCacheData.end()) {
		if (!itor->second.isAgainWrited) {
			readdoc = itor->second.value;
			return *readdoc;
		}
		else {
			readdoc = itor->second.value;
			itor->second.isAgainWrited = false;
		}
	}
	else{
		readdoc = new rapidjson::Document();
		fileCacheValue cacheValue;
		cacheValue.value = readdoc;
		jsonCacheData.insert(std::make_pair(fileName, cacheValue));
	}


	ssize_t size = 0;
	std::string load_str;
	////getFileData 如果不指定，读取根目录是Resource文件夹
	unsigned char* titlech = FileUtils::getInstance()->getFileData(path, "r", &size);
	load_str = std::string((const char*)titlech, size);

	readdoc->Parse<0>(load_str.c_str());
	if (readdoc->HasParseError())
	{
		CCLOG("GetParseError%s\n", readdoc->GetParseError());
	}

	return *readdoc;
}



