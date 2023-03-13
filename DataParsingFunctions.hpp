/// DataParsingFunctions.hpp - Header file for the data-parsing functions.
/// Oct 1, 2021
/// https://github.com/RealTimeChris/Json-Benchmarks
/// \file DataParsingFunctions.hpp
#pragma once

#ifndef DATA_PARSING_FUNCTIONS
	#define DATA_PARSING_FUNCTIONS

	#include <simdjson.h>
	#include <jsonifier/Jsonifier.hpp>
	#include <nanobench.h>

namespace Jsonifier {
	/*
	struct ObjectReturnDataJson {
		Object object{};
		bool didItSucceed{ false };
	};

	struct ArrayReturnDataJson {
		Object arrayValue{};
		bool didItSucceed{ false };
	};
	
	int64_t getInt64(Object& jsonData, const char* key);

	int32_t getInt32(Object&  jsonData, const char* key);

	int16_t getInt16(Object& jsonData, const char* key);

	int8_t getInt8(Object& jsonData, const char* key);

	uint64_t getUint64(Object& jsonData, const char* key);

	uint32_t getUint32(Object& jsonData, const char* key);

	uint16_t getUint16(Object& jsonData, const char* key);

	uint8_t getUint8(Object& jsonData, const char* key);

	float getFloat(Object& jsonData, const char* key);

	bool getBool(Object& jsonData, const char* key);

	std::string getString(Object& jsonData, const char* key);

	std::string getString(ObjectReturnDataJson jsonData, const char* key);

	bool getJsonData(Object&& object, const char* key, Object& jsonJsonDataData);

	bool getArray(Object&& array, const char* key, Object& jsonJsonDataData);

	bool getArray(Object&& array, Object& jsonJsonDataData);

	std::string getString(Object& jsonData);

	ObjectReturnDataJson getJsonData(Object& jsonJsonDataData, const char* objectName);

	ArrayReturnDataJson getArray(Object& jsonJsonDataData, const char* arrayName);

	int64_t getInt64(Object& jsonData, const char* key);

	int32_t getInt32(Object& jsonData, const char* key);

	int16_t getInt16(Object& jsonData, const char* key);

	int8_t getInt8(Object& jsonData, const char* key);

	uint64_t getUint64(Object& jsonData, const char* key);

	uint32_t getUint32(Object& jsonData, const char* key);

	uint16_t getUint16(Object& jsonData, const char* key);

	uint8_t getUint8(Object& jsonData, const char* key);

	float getFloat(Object& jsonData, const char* key);

	bool getBool(Object& jsonData, const char* key);

	std::string getString(Object& jsonData, const char* key);

	std::string getString(ObjectReturnDataJson jsonData, const char* key);

	bool getJsonData(Object&& object, const char* key, Object& jsonJsonDataData);

	bool getArray(Object&& array, const char* key, Object& jsonJsonDataData);

	bool getArray(Object&& array, Object& jsonJsonDataData);

	std::string getString(Object& jsonData);

	ObjectReturnDataJson getJsonData(Object& jsonJsonDataData, const char* objectName);

	ArrayReturnDataJson getArray(Object& jsonJsonDataData, const char* arrayName);

	ObjectReturnDataJson getJsonData(ObjectReturnDataJson jsonJsonDataData, const char* objectName);

	ObjectReturnDataJson getJsonData(ArrayReturnDataJson jsonJsonDataData, uint64_t objectIndex);

	ArrayReturnDataJson getArray(ObjectReturnDataJson jsonJsonDataData, const char* arrayName);
	
*/
}
#endif