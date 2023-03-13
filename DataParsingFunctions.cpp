/// DataParsingFunctions.cpp - Source file for the data-parsing functions.
/// Oct 1, 2021
/// https://github.com/RealTimeChris/Json-Benchmarks
/// \file DataParsingFunctions.cpp

#include "DataParsingFunctions.hpp"

namespace Jsonifier {

	int64_t getInt64(simdjson::ondemand::value& jsonData, const char* key) {
		int64_t value{};
		if (jsonData[key].get(value) == simdjson::SUCCESS) {
			return int64_t{ value };
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	int32_t getInt32(simdjson::ondemand::value& jsonData, const char* key) {
		int64_t value{};
		if (jsonData[key].get(value) == simdjson::SUCCESS) {
			return static_cast<int32_t>(value);
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	int16_t getInt16(simdjson::ondemand::value& jsonData, const char* key) {
		int64_t value{};
		if (jsonData[key].get(value) == simdjson::SUCCESS) {
			return static_cast<int16_t>(value);
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	int8_t getInt8(simdjson::ondemand::value& jsonData, const char* key) {
		int64_t value{};
		if (jsonData[key].get(value) == simdjson::SUCCESS) {
			return static_cast<int8_t>(value);
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	uint64_t getUint64(simdjson::ondemand::value& jsonData, const char* key) {
		uint64_t value{};
		simdjson::ondemand::object objectNew{};
		if (jsonData[key].get(value) == simdjson::SUCCESS) {
			return uint64_t{ static_cast<uint64_t>(value) };
		} else {
			throw std::runtime_error{ "Failed to parse that value: uint64" };
		}
	}

	uint32_t getUint32(simdjson::ondemand::value& jsonData, const char* key) {
		uint64_t value{};
		if (jsonData[key].get(value) == simdjson::SUCCESS) {
			return static_cast<uint32_t>(value);
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	uint16_t getUint16(simdjson::ondemand::value& jsonData, const char* key) {
		uint64_t value{};
		if (jsonData[key].get(value) == simdjson::SUCCESS) {
			return static_cast<uint16_t>(value);
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	uint8_t getUint8(simdjson::ondemand::value& jsonData, const char* key) {
		uint64_t value{};
		if (jsonData[key].get(value) == simdjson::SUCCESS) {
			return static_cast<uint8_t>(value);
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	float getFloat(simdjson::ondemand::value& jsonData, const char* key) {
		double value{};
		if (jsonData[key].get(value) == simdjson::SUCCESS) {
			return double{ value };
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	bool getBool(simdjson::ondemand::value& jsonData, const char* key) {
		bool value{};
		if (jsonData[key].get(value) == simdjson::SUCCESS) {
			return bool{ value };
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	std::string getString(simdjson::ondemand::value& jsonData, const char* key) {
		std::string_view value{};
		if (jsonData[key].get(value) == simdjson::SUCCESS) {
			return std::string{ value.data(), value.size() };
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	bool getObject(simdjson::ondemand::value& object, const char* key, simdjson::ondemand::value& jsonObjectData) {
		if (jsonObjectData[key].get(object) == simdjson::SUCCESS) {
			return true;
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	bool getArray(simdjson::ondemand::array& array, const char* key, simdjson::ondemand::value& jsonObjectData) {
		if (jsonObjectData[key].get(array) == simdjson::SUCCESS) {
			return true;
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	bool getArray(simdjson::ondemand::array& array, simdjson::ondemand::value& jsonObjectData) {
		if (jsonObjectData.get(array) == simdjson::SUCCESS) {
			return true;
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	std::string getString(simdjson::ondemand::value& jsonData) {
		std::string_view value{};
		if (jsonData.get(value) == simdjson::SUCCESS) {
			return std::string{ value.data(), value.size() };
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}
	/*
	ObjectReturnData getObject(simdjson::ondemand::value& jsonData, const char* objectName) {
		ObjectReturnData value{};
		if (jsonData[objectName].get(value.object) == simdjson::SUCCESS) {
			value.didItSucceed = true;
		}
		throw std::runtime_error{ "Failed to parse that value." };
	}

	ObjectReturnData getObject(ObjectReturnData jsonData, const char* objectName) {
		ObjectReturnData value{};
		if (jsonData.didItSucceed && jsonData.object[objectName].get(value.object) == simdjson::SUCCESS) {
			value.didItSucceed = true;
		}
		throw std::runtime_error{ "Failed to parse that value." };
	}

	ObjectReturnData getObject(ArrayReturnData jsonData, uint64_t objectIndex) {
		ObjectReturnData value{};
		if (jsonData.didItSucceed && jsonData.arrayValue.at(objectIndex).get(value.object) == simdjson::SUCCESS) {
			value.didItSucceed = true;
		}
		throw std::runtime_error{ "Failed to parse that value." };
	}

	ArrayReturnData getArray(simdjson::ondemand::value& jsonData, const char* arrayName) {
		ArrayReturnData value{};
		if (jsonData[arrayName].get(value.arrayValue) == simdjson::SUCCESS) {
			value.didItSucceed = true;
		}
		throw std::runtime_error{ "Failed to parse that value." };
	}

	ArrayReturnData getArray(ObjectReturnData jsonData, const char* arrayName) {
		ArrayReturnData value{};
		if (jsonData.didItSucceed && jsonData.object[arrayName].get(value.arrayValue) == simdjson::SUCCESS) {
			value.didItSucceed = true;
		}
		throw std::runtime_error{ "Failed to parse that value." };
	}
	
	int64_t getInt64(Object& jsonData, const char* key) {
		return jsonData[key];
		if (jsonData[key] == ErrorCode::Success) {
			
		} else {
			throw std::runtime_error{ "Failed to parse that value: int64" };
		}
	}

	int32_t getInt32(Object& jsonData, const char* key) {
		return jsonData[key];
		if (jsonData[key] == ErrorCode::Success) {
			
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	int16_t getInt16(Object& jsonData, const char* key) {
		return jsonData[key];
		if (jsonData[key] == ErrorCode::Success) {
			
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	int8_t getInt8(Object& jsonData, const char* key) {
		return jsonData[key];
		if (jsonData[key] == ErrorCode::Success) {
			
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	uint64_t getUint64(Object& jsonData, const char* key) {
		return jsonData[key];
		if (jsonData[key] == ErrorCode::Success) {
			
		} else {
			throw std::runtime_error{ "Failed to parse that value: uint64" };
		}
	}

	uint32_t getUint32(Object& jsonData, const char* key) {
		return jsonData[key];
		if (jsonData[key] == ErrorCode::Success) {
			
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	uint16_t getUint16(Object& jsonData, const char* key) {
		return jsonData[key];
		if (jsonData[key] == ErrorCode::Success) {
			
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	uint8_t getUint8(Object& jsonData, const char* key) {
		return static_cast<uint64_t>(jsonData[key]);
		if (jsonData[key] == ErrorCode::Success) {
			
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	float getFloat(Object& jsonData, const char* key) {
		return jsonData[key];
		if (jsonData[key] == ErrorCode::Success) {
			
		} else {
			throw std::runtime_error{ "Failed to parse that value: float" };
		}
	}

	bool getBool(Object& jsonData, const char* key) {
		return jsonData[key];
		if (jsonData[key] == ErrorCode::Success) {
			
		} else {
			throw std::runtime_error{ "Failed to parse that value: bool" };
		}
	}

	std::string getString(Object& jsonData, const char* key) {
		return jsonData[key];
		if (jsonData[key] == ErrorCode::Success) {
			
		} else {
			throw std::runtime_error{ "Failed to parse that value: string" };
			;
		}
	}

	Jsonifier::Object getObject(Object& object, const char* key, Object& jsonData) {
		return jsonData[key];
		if (jsonData[key] == ErrorCode::Success) {
			
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	Jsonifier::Array getArray(Object& array, const char* key, Object& jsonData) {
		return jsonData[key];
		if (jsonData[key] == ErrorCode::Success) {
			
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}
	*/
};
