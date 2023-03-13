## [Benchmarks](https://github.com/RealTimeChris/Json-Benchmarks/blob/main/main.cpp):
### Parsing the [following](https://github.com/RealTimeChris/Json-Benchmarks/tree/main/Benchmarking/refsnp-unsupported35000.json) data (refsnp-unsupported35000.json):
----
#### Windows 11 Results:
---- 
#### A total of 200 times, for a number of parsed bytes of 93089183, per iteration:
----
- Jsonifier = 37498252 nanoseconds average per iteration.   
- simdjson = 48184695 nanoseconds average per iteration.   
----
### Parsing the [following](https://github.com/RealTimeChris/Json-Benchmarks/tree/main/Benchmarking/test_data.json) data (test_data.json):
----
#### Windows 11 Results:
----
#### A total of 200 times, for a number of parsed bytes of 314269, per iteration:
----
- Jsonifier = 621185 nanoseconds average per iteration.   
- simdjson = 742660 nanoseconds average per iteration.   
----
### Parsing the [following](https://github.com/RealTimeChris/Json-Benchmarks/blob/main/Benchmarking/canada.json) data (canada.json):
----
#### Windows 11 Results:
----
#### A total of 200 times, for a number of parsed bytes of 2251051, per iteration:
----
- Jsonifier = 806090 nanoseconds average per iteration.   
- simdjson = 1086572 nanoseconds average per iteration.   
----
### Parsing the [following](https://github.com/RealTimeChris/Json-Benchmarks/blob/main/Benchmarking/citm_catalog.json) data (citm-catalog.json):
----
#### Windows 11 Results:
----
#### A total of 200 times, for a number of parsed bytes of 1727204, per iteration:
----
- Jsonifier = 556205 nanoseconds average per iteration.   
- simdjson = 785127 nanoseconds average per iteration.   
----
### Parsing the [following](https://github.com/RealTimeChris/Json-Benchmarks/blob/main/Benchmarking/twitter.json) data (twitter.json):
----
#### Windows 11 Results:
----
#### A total of 200 times, for a number of parsed bytes of 631514, per iteration:
----
- Jsonifier = 190005 nanoseconds average per iteration.   
- simdjson = 305012 nanoseconds average per iteration.   
----
## Benchmark - Serializing the following data into a json string:
```cpp
{"d":{"intents":131071,"large_threshold":250,"presence":{"afk":false,"since":0,"status":""},"properties":{"browser":"DiscordCoreAPI","device":"DiscordCoreAPI","os":"Windows"},"shard":[0,1],"token":""},"op":2}
```
### Using the following setup:
```cpp
Jsonifier::StopWatch<std::chrono::milliseconds> stopWatch{ std::chrono::milliseconds{ 1 } };
std::vector<std::string> vector{};
uint64_t totalTime{};
size_t size{};
WebSocketIdentifyData data{};
auto serializer = data.operator Jsonifier::Serializer();
//stopWatch.resetTimer();

for (uint32_t x = 0; x < 50; ++x) {
	//stopWatch.resetTimer();
	for (uint32_t x = 0; x < 1024 * 128; ++x) {
		serializer["d"]["intents"] = x;
		serializer.refreshString(Jsonifier::JsonifierSerializeType::Json);
		vector.push_back(serializer.operator std::string());
		size += vector.back().size();
	}

	totalTime += //stopWatch.totalTimePassed();
	}
//std::cout << "The time it took (In milliseconds, on average): " << totalTime / 50 << ", with a total number of bytes serialized: " << size << std::endl;
		
vector.clear();
totalTime = 0;
size = 0;
WebSocketIdentifyDataTwo dataOne{};
nlohmann::json stringBufferTwo = dataOne;
//stopWatch.resetTimer();
for (uint32_t x = 0; x < 50; ++x) {
	//stopWatch.resetTimer();
	for (uint32_t x = 0; x < 1024 * 128; ++x) {
		stringBufferTwo["d"]["intents"] = x;
		vector.push_back(stringBufferTwo.dump());
		size += vector.back().size();
	}
	totalTime += //stopWatch.totalTimePassed();
	}
//std::cout << "The time it took (In milliseconds, on average): " << totalTime / 50 << ", with a total number of bytes serialized: " << size << std::endl;

vector.clear();
totalTime = 0;
size = 0;
WebSocketIdentifyDataThree dataTwo{};
rapidjson::StringBuffer stringBuffer = dataTwo;
//stopWatch.resetTimer();
for (uint32_t x = 0; x < 50; ++x) {			
	//stopWatch.resetTimer();
	for (uint32_t x = 0; x < 1024 * 128 ; ++x) {
		dataTwo.intents = x;
		stringBuffer = dataTwo;
		std::string string{ stringBuffer.GetString() };
		vector.push_back(string);
		size += vector.back().size();
	}
	totalTime += //stopWatch.totalTimePassed();
	}
//std::cout << "The time it took (In milliseconds, on average): " << totalTime / 50 << ", with a total number of bytes serialized: " << size << std::endl;
```
### Windows 11 Results:
----
### A total of 131,072 times, over 50 iterations, for a total number of serialized bytes of 1357593300:
- Jsonifier = 85 milliseconds average per iteration.   
- rapidjson = 113 milliseconds average per iteration.   
- Nlohmann-Json = 234 milliseconds average per iteration.   
### Ubuntu 22.04 Results:
----
### A total of 131,072 times, over 50 iterations, for a total number of serialized bytes of 2091596500:  
- Jsonifier = 238 milliseconds average per iteration.   
- Nlohmann-Json = 451 milliseconds average per iteration.   
