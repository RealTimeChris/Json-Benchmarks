#include "DataParsingFunctions.hpp"
#include <nanobench.h>
#include <fstream>
#include <random>
#include <iostream>

struct TestObject01 {
	double TEST_VALUE_00{};
	bool TEST_VALUE_01{};
	std::string TEST_VALUE_02{};
	int64_t TEST_VALUE_03{};
	uint64_t TEST_VALUE_04{};
	double TEST_VALUE_05{};
	bool TEST_VALUE_06{};
	std::string TEST_VALUE_07{};
	int64_t TEST_VALUE_08{};
	uint64_t TEST_VALUE_09{};
};

struct TestObject02 {
	TestObject01 testObject{};
};

struct ActivitiesJson {
	ActivitiesJson() noexcept = default;
	ActivitiesJson(Jsonifier::Value value) {
		Jsonifier::Value newValue01{};
		value["TEST_OBJECT_01"].get(newValue01);
		newValue01["TEST_OBJECT_02"].get(newValue01);
		this->testObject.testObject.TEST_VALUE_00 = Jsonifier::getFloat(newValue01, "TEST_VALUE_00");
		this->testObject.testObject.TEST_VALUE_01 = Jsonifier::getBool(newValue01, "TEST_VALUE_01");
		this->testObject.testObject.TEST_VALUE_02 = Jsonifier::getString(newValue01, "TEST_VALUE_02");
		this->testObject.testObject.TEST_VALUE_03 = Jsonifier::getInt64(newValue01, "TEST_VALUE_03");
		this->testObject.testObject.TEST_VALUE_04 = Jsonifier::getUint64(newValue01, "TEST_VALUE_04");
		this->testObject.testObject.TEST_VALUE_05 = Jsonifier::getFloat(newValue01, "TEST_VALUE_05");
		this->testObject.testObject.TEST_VALUE_06 = Jsonifier::getBool(newValue01, "TEST_VALUE_06");
		this->testObject.testObject.TEST_VALUE_07 = Jsonifier::getString(newValue01, "TEST_VALUE_07");
		this->testObject.testObject.TEST_VALUE_08 = Jsonifier::getInt64(newValue01, "TEST_VALUE_08");
		this->testObject.testObject.TEST_VALUE_09 = Jsonifier::getUint64(newValue01, "TEST_VALUE_09");
	};
	TestObject02 testObject{};
};

struct TheValuesJson {
	TheValuesJson() noexcept = default;
	TheValuesJson(Jsonifier::Document value) {
		Jsonifier::Array valueNew{};
		if (!value["TEST_VALUES_REAL"]["TEST_VALUES"].get(valueNew)) {
			for (const auto& valueIterator: valueNew) {
				strings.emplace_back(valueIterator.valueUnsafe());
			}
		};
	};

	std::vector<ActivitiesJson> strings{};
};

struct TheValueJson {
	TheValueJson(Jsonifier::Document value) {
		this->values = TheValuesJson{ std::forward<Jsonifier::Document>(value) };
	}
	TheValuesJson values{};
};

struct Activities {
	Activities() noexcept = default;
	Activities(simdjson::ondemand::value value) {
		simdjson::ondemand::value newValue01{};
		value["TEST_OBJECT_01"].get(newValue01);
		newValue01["TEST_OBJECT_02"].get(newValue01);
		this->testObject.testObject.TEST_VALUE_00 = Jsonifier::getFloat(newValue01, "TEST_VALUE_00");
		this->testObject.testObject.TEST_VALUE_01 = Jsonifier::getBool(newValue01, "TEST_VALUE_01");
		this->testObject.testObject.TEST_VALUE_02 = Jsonifier::getString(newValue01, "TEST_VALUE_02");
		this->testObject.testObject.TEST_VALUE_03 = Jsonifier::getInt64(newValue01, "TEST_VALUE_03");
		this->testObject.testObject.TEST_VALUE_04 = Jsonifier::getUint64(newValue01, "TEST_VALUE_04");
		this->testObject.testObject.TEST_VALUE_05 = Jsonifier::getFloat(newValue01, "TEST_VALUE_05");
		this->testObject.testObject.TEST_VALUE_06 = Jsonifier::getBool(newValue01, "TEST_VALUE_06");
		this->testObject.testObject.TEST_VALUE_07 = Jsonifier::getString(newValue01, "TEST_VALUE_07");
		this->testObject.testObject.TEST_VALUE_08 = Jsonifier::getInt64(newValue01, "TEST_VALUE_08");
		this->testObject.testObject.TEST_VALUE_09 = Jsonifier::getUint64(newValue01, "TEST_VALUE_09");
	};
	TestObject02 testObject{};
};

struct TheValues {
	TheValues() noexcept = default;
	TheValues(simdjson::ondemand::document value) {
		simdjson::ondemand::array valueNew{};
		value["TEST_VALUES_REAL"]["TEST_VALUES"].get(valueNew);
		for (auto valueIterator: valueNew) {
			strings.emplace_back(valueIterator.value_unsafe());
		}
	}
	std::vector<Activities> strings{};
};

struct TheValue {
	TheValue(simdjson::ondemand::document value) {
		this->values = TheValues{ std::forward<simdjson::ondemand::document>(value) };
	}
	TheValues values{};
};

class FileLoader {
  public:
	FileLoader(const char* filePath) {
		std::ofstream theStream{ filePath, std::ios::out | std::ios::in };
		std::stringstream inputStream{};
		inputStream << theStream.rdbuf();
		this->fileContents = inputStream.str();
	}

	operator std::string() {
		return this->fileContents;
	}

  protected:
	std::string fileContents{};
};

uint64_t randomUint64() {
	std::random_device randomDevice{};
	std::mt19937 generator{ randomDevice() };
	std::normal_distribution<> distribution{ 0, static_cast<double>(std::numeric_limits<uint64_t>::max() / 2) };
	uint64_t returnValue{ static_cast<uint64_t>(std::round(distribution(generator))) };
	return returnValue;
}

std::string randomString() {
	char stringPossibleChars[52]{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
		'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y',
		'Z' };
	std::mt19937_64 randomGenerator{ static_cast<uint64_t>(std::chrono::high_resolution_clock::now().time_since_epoch().count()) };
	uint64_t stringLength{ static_cast<uint64_t>((static_cast<float>(randomGenerator()) / static_cast<float>(randomGenerator.max())) * 30) + 1 };
	std::string returnValue{};
	for (size_t x = 0; x < stringLength; ++x) {
		returnValue.push_back(stringPossibleChars[static_cast<char>(
			static_cast<char>(static_cast<float>(randomGenerator() / static_cast<float>(randomGenerator.max())) * 52))]);
	}
	return returnValue;
}

bool randomBool() {
	std::random_device randomDevice{};
	std::mt19937 generator{ randomDevice() };
	std::normal_distribution<> distribution{ 0, 1 };
	bool returnValue{ static_cast<bool>(std::round(distribution(generator))) };
	return returnValue;
}

int64_t randomInt64() {
	std::random_device randomDevice{};
	std::mt19937 generator{ randomDevice() };
	std::normal_distribution<> distribution{ 0, static_cast<double>(std::numeric_limits<int64_t>::max() / 2) };
	int64_t returnValue{ static_cast<int64_t>(std::round(distribution(generator))) };
	return returnValue;
}

double randomDouble() {
	std::random_device randomDevice{};
	std::mt19937 generator{ randomDevice() };
	std::normal_distribution<> distribution{ 0, static_cast<double>(std::numeric_limits<uint64_t>::max() / 2) };
	double returnValue{ static_cast<double>(std::round(distribution(generator))) };
	return returnValue;
}

int32_t main() {
	try {
		Jsonifier::Serializer serializer{};
		for (size_t x = 0; x < 30; ++x) {
			Jsonifier::Serializer testObject{};
			Jsonifier::Serializer arrayValueNew{};
			testObject["TEST_VALUE_00"] = randomDouble();
			testObject["TEST_VALUE_01"] = randomBool();
			testObject["TEST_VALUE_02"] = randomString();
			testObject["TEST_VALUE_03"] = randomInt64();
			testObject["TEST_VALUE_04"] = randomUint64();
			testObject["TEST_VALUE_05"] = randomDouble();
			testObject["TEST_VALUE_06"] = randomBool();
			testObject["TEST_VALUE_07"] = randomString();
			testObject["TEST_VALUE_08"] = randomInt64();
			testObject["TEST_VALUE_09"] = randomUint64();
			arrayValueNew["TEST_OBJECT_01"]["TEST_OBJECT_02"] = testObject;
			serializer["TEST_VALUES_REAL"]["TEST_VALUES"].emplaceBack(arrayValueNew);
		}
		serializer.refreshString(Jsonifier::JsonifierSerializeType::Json);

		std::string refsnp_unsupported35000{ FileLoader{ "../../Benchmarking/refsnp-unsupported35000.json" } };
		std::string refsnp_unsupported35000Newer = refsnp_unsupported35000;

		ankerl::nanobench::Bench().epochs(1).run("simdjson refsnp-unsupported35000 Benchmark", [&] {
			simdjson::ondemand::parser simdjsonParser{};
			refsnp_unsupported35000Newer.reserve(refsnp_unsupported35000Newer.size() + simdjson::SIMDJSON_PADDING);
			auto jsonData = simdjsonParser.iterate(refsnp_unsupported35000Newer.data(), refsnp_unsupported35000Newer.size(),
				refsnp_unsupported35000Newer.capacity());
		});
				
		ankerl::nanobench::Bench().epochs(1).run("Jsonifier refsnp-unsupported35000 Benchmark", [&] {
			Jsonifier::Parser jsonifierParser{};
			auto jsonData = jsonifierParser.parseJson(refsnp_unsupported35000.data(), refsnp_unsupported35000.size());
		});

		std::string test_data{ serializer.operator std::string&&() };
		std::string test_dataNewer = test_data;

		ankerl::nanobench::Bench().epochs(1).run("simdjson test_data Benchmark", [&] {
			simdjson::ondemand::parser simdjsonParser{};
			test_dataNewer.reserve(test_dataNewer.size() + simdjson::SIMDJSON_PADDING);
			auto jsonData = simdjsonParser.iterate(test_dataNewer.data(), test_dataNewer.size(), test_dataNewer.capacity());
			TheValue value{ std::move(jsonData) };
		});

		ankerl::nanobench::Bench().epochs(1).run("Jsonifier test_data Benchmark", [&] {
			Jsonifier::Parser jsonifierParser{};
			auto jsonData = jsonifierParser.parseJson(test_data.data(), test_data.size());
			TheValueJson value{ std::move(jsonData) };
		});

		std::string canada{ FileLoader{ "../../Benchmarking/canada.json" } };
		std::string canadaNewer = canada;
		
		ankerl::nanobench::Bench().epochs(1).run("simdjson canada Benchmark", [&] {
			simdjson::ondemand::parser simdjsonParser{};
			canadaNewer.reserve(canadaNewer.size() + simdjson::SIMDJSON_PADDING);	
			auto jsonData = simdjsonParser.iterate(canadaNewer.data(), canadaNewer.size(), canadaNewer.capacity());
		});

		ankerl::nanobench::Bench().epochs(1).run("Jsonifier canada Benchmark", [&] {
			Jsonifier::Parser jsonifierParser{};
			auto jsonData = jsonifierParser.parseJson(canada.data(), canada.size());
		});

		std::string citm_catalog{ FileLoader{ "../../Benchmarking/citm_catalog.json" } };
		std::string citm_catalogNewer = citm_catalog;
		
		ankerl::nanobench::Bench().epochs(1).run("simdjson citm_catalog Benchmark", [&] {
			simdjson::ondemand::parser simdjsonParser{};
			citm_catalogNewer.reserve(citm_catalogNewer.size() + simdjson::SIMDJSON_PADDING);	
			auto jsonData = simdjsonParser.iterate(citm_catalogNewer.data(), citm_catalogNewer.size(), citm_catalogNewer.capacity());
		});

		ankerl::nanobench::Bench().epochs(1).run("Jsonifier citm_catalog Benchmark", [&] {
			Jsonifier::Parser jsonifierParser{};
			auto jsonData = jsonifierParser.parseJson(citm_catalog.data(), citm_catalog.size());
		});

		std::string twitter{ FileLoader{ "../../Benchmarking/twitter.json" } };
		std::string twitterNewer = twitter;
		
		ankerl::nanobench::Bench().epochs(1).run("simdjson twitter Benchmark", [&] {
			simdjson::ondemand::parser simdjsonParser{};
			twitterNewer.reserve(twitterNewer.size() + simdjson::SIMDJSON_PADDING);	
			auto jsonData = simdjsonParser.iterate(twitterNewer.data(), twitterNewer.size(), twitterNewer.capacity());
		});

		ankerl::nanobench::Bench().epochs(1).run("Jsonifier twitter Benchmark", [&] {
			Jsonifier::Parser jsonifierParser{};
			auto jsonData = jsonifierParser.parseJson(twitter.data(), twitter.size());
		});

	} catch (std::runtime_error& e) { std::cout << e.what() << std::endl; }
	return {};
};
