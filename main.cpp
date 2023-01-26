#include "DataParsingFunctions.hpp"
#include <nanobench.h>
#include <fstream>
#include <random>
#include <iostream>
#include <compare>

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

int64_t boolTime{};
int64_t intTime{};
int64_t uintTime{};
int64_t stringTime{};
int64_t floatTime{};
int64_t iterationTime{};
int64_t iterations{};
Jsonifier::StopWatch stopWatch{ std::chrono::nanoseconds{ 1 } };

struct ActivitiesJson {
	ActivitiesJson() noexcept = default;
	ActivitiesJson(Jsonifier::Object value) {
		iterations++;
		stopWatch.resetTimer();
		this->testObject.testObject.TEST_VALUE_09 = Jsonifier::getUint64(value, "TEST_VALUE_29");
		uintTime += stopWatch.totalTimePassed().count();
		stopWatch.resetTimer();
		this->testObject.testObject.TEST_VALUE_03 = Jsonifier::getInt64(value, "TEST_VALUE_28");
		intTime += stopWatch.totalTimePassed().count();
		stopWatch.resetTimer();
		this->testObject.testObject.TEST_VALUE_07 = Jsonifier::getString(value, "TEST_VALUE_27");
		stringTime += stopWatch.totalTimePassed().count();
		stopWatch.resetTimer();
		this->testObject.testObject.TEST_VALUE_01 = Jsonifier::getBool(value, "TEST_VALUE_26");
		boolTime += stopWatch.totalTimePassed().count();
		stopWatch.resetTimer();
		this->testObject.testObject.TEST_VALUE_06 = Jsonifier::getFloat(value, "TEST_VALUE_25");
		floatTime += stopWatch.totalTimePassed().count();
		stopWatch.resetTimer();
		this->testObject.testObject.TEST_VALUE_09 = Jsonifier::getUint64(value, "TEST_VALUE_24");
		uintTime += stopWatch.totalTimePassed().count();
		stopWatch.resetTimer();
		this->testObject.testObject.TEST_VALUE_03 = Jsonifier::getInt64(value, "TEST_VALUE_23");
		intTime += stopWatch.totalTimePassed().count();
		stopWatch.resetTimer();
		this->testObject.testObject.TEST_VALUE_07 = Jsonifier::getString(value, "TEST_VALUE_22");
		stringTime += stopWatch.totalTimePassed().count();
		stopWatch.resetTimer();
		this->testObject.testObject.TEST_VALUE_01 = Jsonifier::getBool(value, "TEST_VALUE_21");
		boolTime += stopWatch.totalTimePassed().count();
		stopWatch.resetTimer();
		this->testObject.testObject.TEST_VALUE_06 = Jsonifier::getFloat(value, "TEST_VALUE_20");
		floatTime += stopWatch.totalTimePassed().count();
		stopWatch.resetTimer();
		this->testObject.testObject.TEST_VALUE_09 = Jsonifier::getUint64(value, "TEST_VALUE_19");
		uintTime += stopWatch.totalTimePassed().count();
		stopWatch.resetTimer();
		this->testObject.testObject.TEST_VALUE_03 = Jsonifier::getInt64(value, "TEST_VALUE_18");
		intTime += stopWatch.totalTimePassed().count();;
		stopWatch.resetTimer();
		this->testObject.testObject.TEST_VALUE_07 = Jsonifier::getString(value, "TEST_VALUE_17");
		stringTime += stopWatch.totalTimePassed().count();
		stopWatch.resetTimer();
		this->testObject.testObject.TEST_VALUE_01 = Jsonifier::getBool(value, "TEST_VALUE_16");
		boolTime += stopWatch.totalTimePassed().count();
		stopWatch.resetTimer();
		this->testObject.testObject.TEST_VALUE_06 = Jsonifier::getFloat(value, "TEST_VALUE_15");
		floatTime += stopWatch.totalTimePassed().count();
		stopWatch.resetTimer();
		this->testObject.testObject.TEST_VALUE_09 = Jsonifier::getUint64(value, "TEST_VALUE_14");
		uintTime += stopWatch.totalTimePassed().count();
		stopWatch.resetTimer();
		this->testObject.testObject.TEST_VALUE_03 = Jsonifier::getInt64(value, "TEST_VALUE_13");
		intTime += stopWatch.totalTimePassed().count();
		stopWatch.resetTimer();
		this->testObject.testObject.TEST_VALUE_07 = Jsonifier::getString(value, "TEST_VALUE_12");
		stringTime += stopWatch.totalTimePassed().count();
		stopWatch.resetTimer();
		this->testObject.testObject.TEST_VALUE_01 = Jsonifier::getBool(value, "TEST_VALUE_11");
		boolTime += stopWatch.totalTimePassed().count();
		stopWatch.resetTimer();
		this->testObject.testObject.TEST_VALUE_06 = Jsonifier::getFloat(value, "TEST_VALUE_10");
		floatTime += stopWatch.totalTimePassed().count();
		stopWatch.resetTimer();
		this->testObject.testObject.TEST_VALUE_09 = Jsonifier::getUint64(value, "TEST_VALUE_09");
		uintTime += stopWatch.totalTimePassed().count();
		stopWatch.resetTimer();
		this->testObject.testObject.TEST_VALUE_03 = Jsonifier::getInt64(value, "TEST_VALUE_08");
		intTime += stopWatch.totalTimePassed().count();
		stopWatch.resetTimer();
		this->testObject.testObject.TEST_VALUE_07 = Jsonifier::getString(value, "TEST_VALUE_07");
		stringTime += stopWatch.totalTimePassed().count();
		stopWatch.resetTimer();
		this->testObject.testObject.TEST_VALUE_01 = Jsonifier::getBool(value, "TEST_VALUE_06");
		boolTime += stopWatch.totalTimePassed().count();
		stopWatch.resetTimer();
		this->testObject.testObject.TEST_VALUE_06 = Jsonifier::getFloat(value, "TEST_VALUE_05");
		floatTime += stopWatch.totalTimePassed().count();
		stopWatch.resetTimer();
		this->testObject.testObject.TEST_VALUE_09 = Jsonifier::getUint64(value, "TEST_VALUE_04");
		uintTime += stopWatch.totalTimePassed().count();
		stopWatch.resetTimer();
		this->testObject.testObject.TEST_VALUE_03 = Jsonifier::getInt64(value, "TEST_VALUE_03");
		intTime += stopWatch.totalTimePassed().count();
		stopWatch.resetTimer();
		this->testObject.testObject.TEST_VALUE_07 = Jsonifier::getString(value, "TEST_VALUE_02");
		stringTime += stopWatch.totalTimePassed().count();
		stopWatch.resetTimer();
		this->testObject.testObject.TEST_VALUE_01 = Jsonifier::getBool(value, "TEST_VALUE_01");
		boolTime += stopWatch.totalTimePassed().count();
		stopWatch.resetTimer();
		this->testObject.testObject.TEST_VALUE_06 = Jsonifier::getFloat(value, "TEST_VALUE_00");
		floatTime += stopWatch.totalTimePassed().count();
	}
	TestObject02 testObject{};
};

struct TheValuesJson {
	
	TheValuesJson() noexcept = default;
	TheValuesJson(Jsonifier::JsonData value) {
		Jsonifier::Object newObject{ value };
		Jsonifier::Array newArray = newObject["TEST_VALUES_REAL"]["TEST_VALUES"];
		boolTime = 0;
		intTime = 0;
		uintTime = 0;
		stringTime = 0;
		floatTime = 0;
		iterationTime = 0;
		iterations = 0;
		for (Jsonifier::Element &valueNewer: newArray) {
			strings.emplace_back(valueNewer["TEST_OBJECT_01"]);
		}
		//std::cout << "AVERAGE FLOAT TIME (Jsonifier): " << floatTime / iterations << std::endl;
		//std::cout << "AVERAGE BOOL TIME (Jsonifier): " << boolTime / iterations << std::endl;
		//std::cout << "AVERAGE STRING TIME (Jsonifier): " << stringTime / iterations << std::endl;
		//std::cout << "AVERAGE INT TIME (Jsonifier): " << intTime / iterations << std::endl;
		//std::cout << "AVERAGE UINT TIME (Jsonifier): " << uintTime / iterations << std::endl;
	};

	std::vector<ActivitiesJson> strings{};
};

struct TheValueJson {
	TheValueJson() noexcept = default;
	
	TheValueJson(Jsonifier::Object value) {
		this->values = TheValuesJson{ std::move(value) };
	}
	TheValuesJson values{};
};

struct Activities {
	Activities() noexcept = default;
	Activities(simdjson::ondemand::value value) {
		if (!value["TEST_OBJECT_01"].get(value)) {
			iterations++;
			stopWatch.resetTimer();
			this->testObject.testObject.TEST_VALUE_09 = Jsonifier::getUint64(value, "TEST_VALUE_29");
			uintTime += stopWatch.totalTimePassed().count();
			stopWatch.resetTimer();
			this->testObject.testObject.TEST_VALUE_03 = Jsonifier::getInt64(value, "TEST_VALUE_28");
			intTime += stopWatch.totalTimePassed().count();
			stopWatch.resetTimer();
			this->testObject.testObject.TEST_VALUE_07 = Jsonifier::getString(value, "TEST_VALUE_27");
			stringTime += stopWatch.totalTimePassed().count();
			stopWatch.resetTimer();
			this->testObject.testObject.TEST_VALUE_01 = Jsonifier::getBool(value, "TEST_VALUE_26");
			boolTime += stopWatch.totalTimePassed().count();
			stopWatch.resetTimer();
			this->testObject.testObject.TEST_VALUE_06 = Jsonifier::getFloat(value, "TEST_VALUE_25");
			floatTime += stopWatch.totalTimePassed().count();
			stopWatch.resetTimer();
			this->testObject.testObject.TEST_VALUE_09 = Jsonifier::getUint64(value, "TEST_VALUE_24");
			uintTime += stopWatch.totalTimePassed().count();
			stopWatch.resetTimer();
			this->testObject.testObject.TEST_VALUE_03 = Jsonifier::getInt64(value, "TEST_VALUE_23");
			intTime += stopWatch.totalTimePassed().count();
			stopWatch.resetTimer();
			this->testObject.testObject.TEST_VALUE_07 = Jsonifier::getString(value, "TEST_VALUE_22");
			stringTime += stopWatch.totalTimePassed().count();
			stopWatch.resetTimer();
			this->testObject.testObject.TEST_VALUE_01 = Jsonifier::getBool(value, "TEST_VALUE_21");
			boolTime += stopWatch.totalTimePassed().count();
			stopWatch.resetTimer();
			this->testObject.testObject.TEST_VALUE_06 = Jsonifier::getFloat(value, "TEST_VALUE_20");
			floatTime += stopWatch.totalTimePassed().count();
			stopWatch.resetTimer();
			this->testObject.testObject.TEST_VALUE_09 = Jsonifier::getUint64(value, "TEST_VALUE_19");
			uintTime += stopWatch.totalTimePassed().count();
			stopWatch.resetTimer();
			this->testObject.testObject.TEST_VALUE_03 = Jsonifier::getInt64(value, "TEST_VALUE_18");
			intTime += stopWatch.totalTimePassed().count();
			stopWatch.resetTimer();
			this->testObject.testObject.TEST_VALUE_07 = Jsonifier::getString(value, "TEST_VALUE_17");
			stringTime += stopWatch.totalTimePassed().count();
			stopWatch.resetTimer();
			this->testObject.testObject.TEST_VALUE_01 = Jsonifier::getBool(value, "TEST_VALUE_16");
			boolTime += stopWatch.totalTimePassed().count();
			stopWatch.resetTimer();
			this->testObject.testObject.TEST_VALUE_06 = Jsonifier::getFloat(value, "TEST_VALUE_15");
			floatTime += stopWatch.totalTimePassed().count();
			stopWatch.resetTimer();
			this->testObject.testObject.TEST_VALUE_09 = Jsonifier::getUint64(value, "TEST_VALUE_14");
			uintTime += stopWatch.totalTimePassed().count();
			stopWatch.resetTimer();
			this->testObject.testObject.TEST_VALUE_03 = Jsonifier::getInt64(value, "TEST_VALUE_13");
			intTime += stopWatch.totalTimePassed().count();
			stopWatch.resetTimer();
			this->testObject.testObject.TEST_VALUE_07 = Jsonifier::getString(value, "TEST_VALUE_12");
			stringTime += stopWatch.totalTimePassed().count();
			stopWatch.resetTimer();
			this->testObject.testObject.TEST_VALUE_01 = Jsonifier::getBool(value, "TEST_VALUE_11");
			boolTime += stopWatch.totalTimePassed().count();
			stopWatch.resetTimer();
			this->testObject.testObject.TEST_VALUE_06 = Jsonifier::getFloat(value, "TEST_VALUE_10");
			floatTime += stopWatch.totalTimePassed().count();
			stopWatch.resetTimer();
			this->testObject.testObject.TEST_VALUE_09 = Jsonifier::getUint64(value, "TEST_VALUE_09");
			uintTime += stopWatch.totalTimePassed().count();
			stopWatch.resetTimer();
			this->testObject.testObject.TEST_VALUE_03 = Jsonifier::getInt64(value, "TEST_VALUE_08");
			intTime += stopWatch.totalTimePassed().count();
			stopWatch.resetTimer();
			this->testObject.testObject.TEST_VALUE_07 = Jsonifier::getString(value, "TEST_VALUE_07");
			stringTime += stopWatch.totalTimePassed().count();
			stopWatch.resetTimer();
			this->testObject.testObject.TEST_VALUE_01 = Jsonifier::getBool(value, "TEST_VALUE_06");
			boolTime += stopWatch.totalTimePassed().count();
			stopWatch.resetTimer();
			this->testObject.testObject.TEST_VALUE_06 = Jsonifier::getFloat(value, "TEST_VALUE_05");
			floatTime += stopWatch.totalTimePassed().count();
			stopWatch.resetTimer();
			this->testObject.testObject.TEST_VALUE_09 = Jsonifier::getUint64(value, "TEST_VALUE_04");
			uintTime += stopWatch.totalTimePassed().count();
			stopWatch.resetTimer();
			this->testObject.testObject.TEST_VALUE_03 = Jsonifier::getInt64(value, "TEST_VALUE_03");
			intTime += stopWatch.totalTimePassed().count();
			stopWatch.resetTimer();
			this->testObject.testObject.TEST_VALUE_07 = Jsonifier::getString(value, "TEST_VALUE_02");
			stringTime += stopWatch.totalTimePassed().count();
			stopWatch.resetTimer();
			this->testObject.testObject.TEST_VALUE_01 = Jsonifier::getBool(value, "TEST_VALUE_01");
			boolTime += stopWatch.totalTimePassed().count();
			stopWatch.resetTimer();
			this->testObject.testObject.TEST_VALUE_06 = Jsonifier::getFloat(value, "TEST_VALUE_00");
			floatTime += stopWatch.totalTimePassed().count();
		}
	};
	TestObject02 testObject{};
};

struct TheValues {
	TheValues() noexcept = default;
	TheValues(simdjson::ondemand::document value) {
		boolTime = 0;
		intTime = 0;
		uintTime = 0;
		stringTime = 0;
		floatTime = 0;
		iterationTime = 0;
		iterations = 0;
		simdjson::ondemand::array valueNew{};
		value["TEST_VALUES_REAL"]["TEST_VALUES"].get(valueNew);
		for (auto valueIterator: valueNew) {
			strings.emplace_back(std::move(valueIterator));
		}

		//std::cout << "AVERAGE FLOAT TIME (simdjson): " << floatTime / iterations << std::endl;
		//std::cout << "AVERAGE BOOL TIME (simdjson): " << boolTime / iterations << std::endl;
		//std::cout << "AVERAGE STRING TIME (simdjson): " << stringTime / iterations << std::endl;
		//std::cout << "AVERAGE INT TIME (simdjson): " << intTime / iterations << std::endl;
		//std::cout << "AVERAGE UINT TIME (simdjson): " << uintTime / iterations << std::endl;
	}
	std::vector<Activities> strings{};
};

struct TheValue {
	TheValue() noexcept = default;
	TheValue(simdjson::ondemand::document value) {
		this->values = TheValues{ std::forward<simdjson::ondemand::document>(value) };
	}
	TheValues values{};
};

class FileLoader {
  public:
	__forceinline FileLoader(const char* filePath) {
		std::ofstream theStream{ filePath, std::ios::out | std::ios::in };
		std::stringstream inputStream{};
		inputStream << theStream.rdbuf();
		this->fileContents = inputStream.str();
	}

	__forceinline operator std::string() {
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
class TestClass01 {
  public:
	size_t testString{344  };
};
class TestClass02 : public TestClass01 {
  public:
	std::string testString{ "TEST_VALUES" };
};

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
			testObject["TEST_VALUE_10"] = randomDouble();
			testObject["TEST_VALUE_11"] = randomBool();
			testObject["TEST_VALUE_12"] = randomString();
			testObject["TEST_VALUE_13"] = randomInt64();
			testObject["TEST_VALUE_14"] = randomUint64();
			testObject["TEST_VALUE_15"] = randomDouble();
			testObject["TEST_VALUE_16"] = randomBool();
			testObject["TEST_VALUE_17"] = randomString();
			testObject["TEST_VALUE_18"] = randomInt64();
			testObject["TEST_VALUE_19"] = randomUint64();
			testObject["TEST_VALUE_20"] = randomDouble();
			testObject["TEST_VALUE_21"] = randomBool();
			testObject["TEST_VALUE_22"] = randomString();
			testObject["TEST_VALUE_23"] = randomInt64();
			testObject["TEST_VALUE_24"] = randomUint64();
			testObject["TEST_VALUE_25"] = randomDouble();
			testObject["TEST_VALUE_26"] = randomBool();
			testObject["TEST_VALUE_27"] = randomString();
			testObject["TEST_VALUE_28"] = randomInt64();
			testObject["TEST_VALUE_29"] = randomUint64();
			arrayValueNew["TEST_OBJECT_01"] = testObject;
			serializer["TEST_VALUES_REAL"]["TEST_VALUES"].emplaceBack(arrayValueNew);
		}
		
		serializer.refreshString(Jsonifier::JsonifierSerializeType::Json);
		
		std::string refsnp_unsupported35000{ FileLoader{ "../../Benchmarking/refsnp-unsupported35000.json" } };
		std::string refsnp_unsupported35000Newer = refsnp_unsupported35000;

		refsnp_unsupported35000Newer.reserve(refsnp_unsupported35000Newer.size() + simdjson::SIMDJSON_PADDING);
		ankerl::nanobench::Bench().epochs(1).run("simdjson refsnp-unsupported35000 Benchmark", [&] {
			simdjson::ondemand::parser simdjsonParser{};
			auto jsonData = simdjsonParser.iterate(refsnp_unsupported35000Newer.data(), refsnp_unsupported35000Newer.size(),
				refsnp_unsupported35000Newer.capacity());
		});

		ankerl::nanobench::Bench().epochs(1).run("Jsonifier refsnp-unsupported35000 Benchmark", [&] {
			Jsonifier::Parser jsonifierParser{};
			auto jsonData = jsonifierParser.parseJson(refsnp_unsupported35000);	
		});
		
		std::string test_data{ serializer.operator std::string&&() };
		std::string test_dataNewer = test_data;
		
		test_dataNewer.reserve(test_dataNewer.size() + simdjson::SIMDJSON_PADDING);
		ankerl::nanobench::Bench().epochIterations(1).epochs(1).run("simdjson test_data Benchmark", [&] {
			simdjson::ondemand::parser simdjsonParser{};
			auto jsonData = simdjsonParser.iterate(test_dataNewer.data(), test_dataNewer.size(), test_dataNewer.capacity());
			TheValues value{ std::move(jsonData) };
		});
				
		TheValuesJson value{};
		ankerl::nanobench::Bench().epochIterations(1).epochs(1).run("Jsonifier test_data Benchmark", [&] {
			Jsonifier::Parser jsonifierParser{};
			auto jsonData = jsonifierParser.parseJson(test_data.data(), test_data.size());
			value = { jsonData };
		});

		std::string canada{ FileLoader{ "../../Benchmarking/canada.json" } };
		std::string canadaNewer = canada;
		canadaNewer.reserve(canadaNewer.size() + simdjson::SIMDJSON_PADDING);	
		ankerl::nanobench::Bench().epochs(1).run("simdjson canada Benchmark", [&] {
			simdjson::ondemand::parser simdjsonParser{};
			
			auto jsonData = simdjsonParser.iterate(canadaNewer.data(), canadaNewer.size(), canadaNewer.capacity());
		});

		ankerl::nanobench::Bench().epochs(1).run("Jsonifier canada Benchmark", [&] {
			Jsonifier::Parser jsonifierParser{};
			auto jsonData = jsonifierParser.parseJson(canada.data(), canada.size());
		});

		std::string citm_catalog{ FileLoader{ "../../Benchmarking/citm_catalog.json" } };
		std::string citm_catalogNewer = citm_catalog;
		citm_catalogNewer.reserve(citm_catalogNewer.size() + simdjson::SIMDJSON_PADDING);	
		ankerl::nanobench::Bench().epochs(1).run("simdjson citm_catalog Benchmark", [&] {
			simdjson::ondemand::parser simdjsonParser{};
			
			auto jsonData = simdjsonParser.iterate(citm_catalogNewer.data(), citm_catalogNewer.size(), citm_catalogNewer.capacity());
		});

		ankerl::nanobench::Bench().epochs(1).run("Jsonifier citm_catalog Benchmark", [&] {
			Jsonifier::Parser jsonifierParser{};
			auto jsonData = jsonifierParser.parseJson(citm_catalog.data(), citm_catalog.size());
		});

		std::string twitter{ FileLoader{ "../../Benchmarking/twitter.json" } };
		std::string twitterNewer = twitter;
		twitterNewer.reserve(twitterNewer.size() + simdjson::SIMDJSON_PADDING);	
		ankerl::nanobench::Bench().epochs(1).run("simdjson twitter Benchmark", [&] {
			simdjson::ondemand::parser simdjsonParser{};
			
			auto jsonData = simdjsonParser.iterate(twitterNewer.data(), twitterNewer.size(), twitterNewer.capacity());
		});

		ankerl::nanobench::Bench().epochs(1).run("Jsonifier twitter Benchmark", [&] {
			Jsonifier::Parser jsonifierParser{};
			auto jsonData = jsonifierParser.parseJson(twitter.data(), twitter.size());
		});

		
	} catch (std::runtime_error& e) {
		std::cout << e.what() << std::endl;
		std::rethrow_exception(std::current_exception());
	}
	return {};
};

