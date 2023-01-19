/// DataParsingFunctions.cpp - Source file for the data-parsing functions.
/// Oct 1, 2021
/// https://github.com/RealTimeChris/Json-Benchmarks
/// \file DataParsingFunctions.cpp

#include "DataParsingFunctions.hpp"

namespace Jsonifier {

	int64_t getInt64(simdjson::ondemand::value jsonData, const char* key) {
		int64_t value{};
		if (jsonData[key].get(value) == simdjson::SUCCESS) {
			return int64_t{ value };
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	int32_t getInt32(simdjson::ondemand::value jsonData, const char* key) {
		int64_t value{};
		if (jsonData[key].get(value) == simdjson::SUCCESS) {
			return static_cast<int32_t>(value);
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	int16_t getInt16(simdjson::ondemand::value jsonData, const char* key) {
		int64_t value{};
		if (jsonData[key].get(value) == simdjson::SUCCESS) {
			return static_cast<int16_t>(value);
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	int8_t getInt8(simdjson::ondemand::value jsonData, const char* key) {
		int64_t value{};
		if (jsonData[key].get(value) == simdjson::SUCCESS) {
			return static_cast<int8_t>(value);
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	uint64_t getUint64(simdjson::ondemand::value jsonData, const char* key) {
		uint64_t value{};
		simdjson::ondemand::object newValue{};
		if (jsonData[key].get(value) == simdjson::SUCCESS) {
			return uint64_t{ static_cast<uint64_t>(value) };
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	uint32_t getUint32(simdjson::ondemand::value jsonData, const char* key) {
		uint64_t value{};
		if (jsonData[key].get(value) == simdjson::SUCCESS) {
			return static_cast<uint32_t>(value);
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	uint16_t getUint16(simdjson::ondemand::value jsonData, const char* key) {
		uint64_t value{};
		if (jsonData[key].get(value) == simdjson::SUCCESS) {
			return static_cast<uint16_t>(value);
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	uint8_t getUint8(simdjson::ondemand::value jsonData, const char* key) {
		uint64_t value{};
		if (jsonData[key].get(value) == simdjson::SUCCESS) {
			return static_cast<uint8_t>(value);
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	float getFloat(simdjson::ondemand::value jsonData, const char* key) {
		double value{};
		if (jsonData[key].get(value) == simdjson::SUCCESS) {
			return double{ value };
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	bool getBool(simdjson::ondemand::value jsonData, const char* key) {
		bool value{};
		if (jsonData[key].get(value) == simdjson::SUCCESS) {
			return bool{ value };
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	std::string getString(simdjson::ondemand::value jsonData, const char* key) {
		std::string_view value{};
		if (jsonData[key].get(value) == simdjson::SUCCESS) {
			return std::string{ value.data(), value.size() };
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	bool getObject(simdjson::ondemand::value& object, const char* key, simdjson::ondemand::value jsonObjectData) {
		if (jsonObjectData[key].get(object) == simdjson::SUCCESS) {
			return true;
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	bool getArray(simdjson::ondemand::array& array, const char* key, simdjson::ondemand::value jsonObjectData) {
		if (jsonObjectData[key].get(array) == simdjson::SUCCESS) {
			return true;
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	bool getArray(simdjson::ondemand::array& array, simdjson::ondemand::value jsonObjectData) {
		if (jsonObjectData.get(array) == simdjson::SUCCESS) {
			return true;
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	std::string getString(ObjectReturnData jsonData, const char* key) {
		std::string_view value{};
		if (jsonData.didItSucceed && jsonData.object[key].get(value) == simdjson::SUCCESS) {
			return static_cast<std::string>(value);
		}
		return static_cast<std::string>(value);
	}

	std::string getString(simdjson::ondemand::value jsonData) {
		std::string_view value{};
		if (jsonData.get(value) == simdjson::SUCCESS) {
			return std::string{ value.data(), value.size() };
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	ObjectReturnData getObject(simdjson::ondemand::value jsonData, const char* objectName) {
		ObjectReturnData value{};
		if (jsonData[objectName].get(value.object) == simdjson::SUCCESS) {
			value.didItSucceed = true;
		}
		throw std::runtime_error{ "Failed to parse that value." };
	}
	/*
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

	ArrayReturnData getArray(simdjson::ondemand::value jsonData, const char* arrayName) {
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

	int64_t getInt64(Value jsonData, const char* key) {
		int64_t value{};
		if (jsonData[key].get(value) == ErrorCode::Success) {
			return value;
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	int32_t getInt32(Value jsonData, const char* key) {
		int64_t value{};
		if (jsonData[key].get(value) == ErrorCode::Success) {
			return static_cast<int32_t>(value);
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	int16_t getInt16(Value jsonData, const char* key) {
		int64_t value{};
		if (jsonData[key].get(value) == ErrorCode::Success) {
			return static_cast<int16_t>(value);
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	int8_t getInt8(Value jsonData, const char* key) {
		int64_t value{};
		if (jsonData[key].get(value) == ErrorCode::Success) {
			return static_cast<int8_t>(value);
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	uint64_t getUint64(Value jsonData, const char* key) {
		uint64_t value{};
		if (jsonData[key].get(value) == ErrorCode::Success) {
			return static_cast<uint64_t>(value);
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	uint32_t getUint32(Value jsonData, const char* key) {
		uint64_t value{};
		if (jsonData[key].get(value) == ErrorCode::Success) {
			return static_cast<uint32_t>(value);
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	uint16_t getUint16(Value jsonData, const char* key) {
		uint64_t value{};
		if (jsonData[key].get(value) == ErrorCode::Success) {
			return static_cast<uint16_t>(value);
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	uint8_t getUint8(Value jsonData, const char* key) {
		uint64_t value{};
		if (jsonData[key].get(value) == ErrorCode::Success) {
			return static_cast<uint8_t>(value);
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	float getFloat(Value jsonData, const char* key) {
		double value{};
		if (jsonData[key].get(value) == ErrorCode::Success) {
			return double{ value };
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	bool getBool(Value jsonData, const char* key) {
		bool value{};
		if (jsonData[key].get(value) == ErrorCode::Success) {
			return bool{ value };
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	std::string getString(Value jsonData, const char* key) {
		std::string_view value{};
		if (jsonData[key].get(value) == ErrorCode::Success) {
			return std::string{ value.data(), value.size() };
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
			;
		}
	}

	bool getObject(Object& object, const char* key, Value jsonData) {
		if (jsonData[key].get(object) == ErrorCode::Success) {
			return true;
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	bool getObject(Value& object, const char* key, Value jsonData) {
		if (jsonData[key].get(object) == ErrorCode::Success) {
			return true;
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	bool getArray(Array& array, const char* key, Value jsonData) {
		if (jsonData[key].get(array) == ErrorCode::Success) {
			return true;
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	bool getArray(Array& array, Value jsonData) {
		if (jsonData.get(array) == ErrorCode::Success) {
			return true;
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}

	std::string getString(Value jsonData) {
		std::string_view value{};
		if (jsonData.get(value) == ErrorCode::Success) {
			return std::string{ value.data(), value.size() };
		} else {
			throw std::runtime_error{ "Failed to parse that value." };
		}
	}
	*/
};
