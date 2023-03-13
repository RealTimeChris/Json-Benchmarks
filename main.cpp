// Glaze Library
// For the license information refer to glaze.hpp

// Dummy target since interface targets dont show up in some ides

#include "glaze/glaze.hpp"
#include <jsonifier/Jsonifier.hpp>

static constexpr std::string_view json0 = R"(
{
   "fixed_object": {
      "int_array": [0, 1, 2, 3, 4, 5, 6],
      "float_array": [0.1, 0.2, 0.3, 0.4, 0.5, 0.6],
      "double_array": [3288398.238, 233e22, 289e-1, 0.928759872, 0.22222848, 0.1, 0.2, 0.3, 0.4]
   },
   "fixed_name_object": {
      "name0": "James",
      "name1": "Abraham",
      "name2": "Susan",
      "name3": "Frank",
      "name4": "Alicia"
   },
   "another_object": {
      "string": "here is some text",
      "another_string": "Hello World",
      "boolean": false,
      "nested_object": {
         "v3s": [[0.12345, 0.23456, 0.001345],
                  [0.3894675, 97.39827, 297.92387],
                  [18.18, 87.289, 2988.298]],
         "id": "298728949872"
      }
   },
   "string_array": ["Cat", "Dog", "Elephant", "Tiger"],
   "string": "Hello world",
   "number": 3.14,
   "boolean": true,
   "another_bool": false
}
)";

#include <chrono>
#include <iostream>
#include <unordered_map>

#include "fmt/format.h"

struct fixed_object_t {
	std::vector<int> int_array;
	std::vector<double> float_array;
	std::vector<double> double_array;
};

struct fixed_name_object_t {
	std::string name0{};
	std::string name1{};
	std::string name2{};
	std::string name3{};
	std::string name4{};
};

struct nested_object_t {
	std::vector<std::array<double, 3>> v3s{};
	std::string id{};
};

struct another_object_t {
	std::string string{};
	std::string another_string{};
	bool boolean{};
	nested_object_t nested_object{};
};

struct obj_t {
	fixed_object_t fixed_object{};
	fixed_name_object_t fixed_name_object{};
	another_object_t another_object{};
	std::vector<std::string> string_array{};
	std::string string{};
	double number{};
	bool boolean{};
	bool another_bool{};
};
 
template<> struct glz::meta<fixed_object_t> {
	using T = fixed_object_t;
	static constexpr auto value = object("int_array", &T::int_array, "float_array", &T::float_array, "double_array", &T::double_array);
};

template<> struct glz::meta<fixed_name_object_t> {
	using T = fixed_name_object_t;
	static constexpr auto value = object("name0", &T::name0, "name1", &T::name1, "name2", &T::name2, "name3", &T::name3, "name4", &T::name4);
};

template<> struct glz::meta<nested_object_t> {
	using T = nested_object_t;
	static constexpr auto value = object("v3s", &T::v3s, "id", &T::id);
};

template<> struct glz::meta<another_object_t> {
	using T = another_object_t;
	static constexpr auto value =
		object("string", &T::string, "another_string", &T::another_string, "boolean", &T::boolean, "nested_object", &T::nested_object);
};

template<> struct glz::meta<obj_t> {
	using T = obj_t;
	static constexpr auto value =
		object("fixed_object", &T::fixed_object, "fixed_name_object", &T::fixed_name_object, "another_object", &T::another_object, "string_array",
			&T::string_array, "string", &T::string, "number", &T::number, "boolean", &T::boolean, "another_bool", &T::another_bool);
};
 
template<> struct Jsonifier::Core<fixed_object_t> {
	using T = fixed_object_t;
	static constexpr auto value = object("int_array", &T::int_array, "float_array", &T::float_array, "double_array", &T::double_array);
};

template<> struct Jsonifier::Core<fixed_name_object_t> {
	using T = fixed_name_object_t;
	static constexpr auto value = object("name0", &T::name0, "name1", &T::name1, "name2", &T::name2, "name3", &T::name3, "name4", &T::name4);
};

template<> struct Jsonifier::Core<nested_object_t> {
	using T = nested_object_t;
	static constexpr auto value = object("v3s", &T::v3s, "id", &T::id);
};

template<> struct Jsonifier::Core<another_object_t> {
	using T = another_object_t;
	static constexpr auto value =
		object("string", &T::string, "another_string", &T::another_string, "boolean", &T::boolean, "nested_object", &T::nested_object);
};

template<> struct Jsonifier::Core<obj_t> {
	using T = obj_t;
	static constexpr auto value =
		object("fixed_object", &T::fixed_object, "fixed_name_object", &T::fixed_name_object, "another_object", &T::another_object, "string_array",
			&T::string_array, "string", &T::string, "number", &T::number, "boolean", &T::boolean, "another_bool", &T::another_bool);
};

struct abc_t {
	std::vector<std::string> a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;

	abc_t() {
		auto fill = [](auto& v) {
			v.resize(1000);
			for (size_t x = 0; x < 1000; ++x) {
				v[x] = std::to_string(x + 10000000000);
			}
		};

		fill(a);
		fill(b);
		fill(c);
		fill(d);
		fill(e);
		fill(f);
		fill(g);
		fill(h);
		fill(i);
		fill(j);
		fill(k);
		fill(l);
		fill(m);
		fill(n);
		fill(o);
		fill(p);
		fill(q);
		fill(r);
		fill(s);
		fill(t);
		fill(u);
		fill(v);
		fill(w);
		fill(x);
		fill(y);
		fill(z);
	}
};

struct abc_t2 {
	std::vector<std::string> a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;

	abc_t2(){};
};

template<> struct glz::meta<abc_t> {
	using T = abc_t;
	static constexpr auto value = object("z", &T::z, "y", &T::y, "x", &T::x, "w", &T::w, "v", &T::v, "u", &T::u, "t", &T::t, "s", &T::s, "r", &T::r,
		"q", &T::q, "p", &T::p, "o", &T::o, "n", &T::n, "m", &T::m, "l", &T::l, "k", &T::k, "j", &T::j, "i", &T::i, "h", &T::h, "g", &T::g, "f",
		&T::f, "e", &T::e, "d", &T::d, "c", &T::c, "b", &T::b, "a", &T::a);
};

template<> struct glz::meta<abc_t2> {
	using T = abc_t2;
	static constexpr auto value = object("z", &T::z, "y", &T::y, "x", &T::x, "w", &T::w, "v", &T::v, "u", &T::u, "t", &T::t, "s", &T::s, "r", &T::r,
		"q", &T::q, "p", &T::p, "o", &T::o, "n", &T::n, "m", &T::m, "l", &T::l, "k", &T::k, "j", &T::j, "i", &T::i, "h", &T::h, "g", &T::g, "f",
		&T::f, "e", &T::e, "d", &T::d, "c", &T::c, "b", &T::b, "a", &T::a);
};

template<> struct Jsonifier::Core<abc_t> {
	using T = abc_t;
	static constexpr auto value = object("z", &T::z, "y", &T::y, "x", &T::x, "w", &T::w, "v", &T::v, "u", &T::u, "t", &T::t, "s", &T::s, "r", &T::r,
		"q", &T::q, "p", &T::p, "o", &T::o, "n", &T::n, "m", &T::m, "l", &T::l, "k", &T::k, "j", &T::j, "i", &T::i, "h", &T::h, "g", &T::g, "f",
		&T::f, "e", &T::e, "d", &T::d, "c", &T::c, "b", &T::b, "a", &T::a);
};

template<> struct Jsonifier::Core<abc_t2> {
	using T = abc_t2;
	static constexpr auto value = object("z", &T::z, "y", &T::y, "x", &T::x, "w", &T::w, "v", &T::v, "u", &T::u, "t", &T::t, "s", &T::s, "r", &T::r,
		"q", &T::q, "p", &T::p, "o", &T::o, "n", &T::n, "m", &T::m, "l", &T::l, "k", &T::k, "j", &T::j, "i", &T::i, "h", &T::h, "g", &T::g, "f",
		&T::f, "e", &T::e, "d", &T::d, "c", &T::c, "b", &T::b, "a", &T::a);
};

static constexpr std::string_view table_header01 = R"(| Library: )";
static constexpr std::string_view table_header02 = R"(| ----------------------------------------------------------------------- |)";

struct results {
	std::string_view name{};
	std::string_view url{};
	size_t iterations{};

	size_t json_byte_length{};
	double json_read{};
	double json_write{};
	double json_roundtrip{};

	size_t binary_byte_length{};
	double binary_write{};
	double binary_read{};
	double binary_roundtrip{};

	void print() {
		std::cout << table_header01 << name << std::endl;
		std::cout << table_header02 << std::endl;
		if (json_roundtrip) {
			std::cout << "    " << name << " json roundtrip: " << json_roundtrip << " s\n";
		}

		if (json_byte_length) {
			std::cout << "    " << name << " json byte length: " << json_byte_length << '\n';
		}

		if (json_write) {
			if (json_byte_length) {
				const auto MBs = iterations * json_byte_length / (json_write * 1048576);
				std::cout << "    " << name << " json write: " << json_write << " s, " << MBs << " MB/s\n";
			} else {
				std::cout << "    " << name << " json write: " << json_write << " s\n";
			}
		}

		if (json_read) {
			if (json_byte_length) {
				const auto MBs = iterations * json_byte_length / (json_read * 1048576);
				std::cout <<"    " << name << " json Read: " << json_read << " s, " << MBs << " MB/s\n";
			} else {
				std::cout << "    " << name << " json Read: " << json_read << " s\n";
			}
		}

		if (binary_roundtrip) {
			std::cout << '\n';
			std::cout << "    " << name << " binary roundtrip: " << binary_roundtrip << " s\n";
		}

		if (binary_byte_length) {
			std::cout << "    " << name << " binary byte length: " << binary_byte_length << '\n';
		}

		if (binary_write) {
			if (binary_byte_length) {
				const auto MBs = iterations * binary_byte_length / (binary_write * 1048576);
				std::cout << "    " << name << " binary write: " << binary_write << " s, " << MBs << " MB/s\n";
			} else {
				std::cout << "    " << name << " binary write: " << binary_write << " s\n";
			}
		}

		if (binary_read) {
			if (binary_byte_length) {
				const auto MBs = iterations * binary_byte_length / (binary_read * 1048576);
				std::cout << "    " << name << " binary Read: " << binary_read << " s, " << MBs << " MB/s\n";
			} else {
				std::cout << "    " << name << " binary Read: " << binary_read << " s\n";
			}
		}

		std::cout << "\n---\n" << std::endl;
	}
};

#ifdef NDEBUG
static constexpr size_t iterations = 1000000;
static constexpr size_t iterations_abc = 1000;
#else
static constexpr size_t iterations = 1;
static constexpr size_t iterations_abc = 1;
#endif

#include "simdjson.h"

// Note: the on demand parser does not allow multiple instances of the same key with different data specified

using namespace simdjson;

struct on_demand_abc {
	bool Read(abc_t& obj, const padded_string& json);

  private:
	ondemand::parser parser{};
};

#define SIMD_PULL(x) \
	ondemand::array x = doc[#x]; \
	obj.x.clear(); \
	for (uint64_t value: x) { \
		obj.x.emplace_back(value); \
	}

bool on_demand_abc::Read(abc_t& obj, const padded_string& json) {
	auto doc = parser.iterate(json);
	/*
	SIMD_PULL(a);
	SIMD_PULL(b);
	SIMD_PULL(c);
	SIMD_PULL(d);
	SIMD_PULL(e);
	SIMD_PULL(f);
	SIMD_PULL(g);
	SIMD_PULL(h);
	SIMD_PULL(i);
	SIMD_PULL(j);
	SIMD_PULL(k);
	SIMD_PULL(l);
	SIMD_PULL(m);
	SIMD_PULL(n);
	SIMD_PULL(o);
	SIMD_PULL(p);
	SIMD_PULL(q);
	SIMD_PULL(r);
	SIMD_PULL(s);
	SIMD_PULL(t);
	SIMD_PULL(u);
	SIMD_PULL(v);
	SIMD_PULL(w);
	SIMD_PULL(x);
	SIMD_PULL(y);
	SIMD_PULL(z);
	*/
	
	return false;
}

auto simdjson_abc_test() {
	abc_t obj{};

	std::string buffer = glz::write_json(obj);
	std::string minified = buffer;

	size_t new_length{};// It will receive the minified length.
	[[maybe_unused]] auto error = simdjson::minify(buffer.data(), buffer.size(), minified.data(), new_length);
	minified.resize(new_length);

	padded_string padded = minified;

	on_demand_abc parser{};

	auto t0 = std::chrono::steady_clock::now();

	try {
		for (size_t i = 0; i < iterations_abc; ++i) {
			const auto error = parser.Read(obj, padded);
			if (error) {
				std::cerr << "simdjson error" << std::endl;
			}
		}
	} catch (const std::exception& e) {
		std::cout << "simdjson exception error: " << e.what() << '\n';
	}

	auto t1 = std::chrono::steady_clock::now();

	results r{ "simdjson (on demand)", "https://github.com/simdjson/simdjson", iterations_abc };

	r.json_byte_length = padded.size();
	r.json_read = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count() * 1e-6;

	r.print();

	return r;
}

auto glaze_abc_test() {
	std::string buffer{};
	
	abc_t obj{};

	results r{ "glaze", "https://github.com/stephenberry/glaze", iterations_abc };
	// write performance

	auto t0 = std::chrono::steady_clock::now();

	for (size_t i = 0; i < iterations_abc; ++i) {
		glz::write_json(obj, buffer);
	}

	auto t1 = std::chrono::steady_clock::now();
	
	r.json_byte_length = buffer.size();
	r.json_write = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count() * 1e-6;
	// Read performance

	t0 = std::chrono::steady_clock::now();
	for (size_t i = 0; i < iterations_abc; ++i) {
		if (glz::read_json(obj, buffer)) {
			std::cout << "glaze error!\n";
			break;
		}
	}
	t1 = std::chrono::steady_clock::now();

	r.json_read = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count() * 1e-6;

	r.print();

	return r;
}

auto Jsonifier_abc_test() {
	std::string buffer{};

	abc_t obj{};
	Jsonifier::Serializer serializer{};

	results r{ "Jsonifier", "https://github.com/RealTimeChris/Jsonifier", iterations_abc };
	// write performance

	auto t0 = std::chrono::steady_clock::now();

	for (size_t i = 0; i < iterations_abc; ++i) {
		serializer.serializeJson(obj, buffer);
		
	}

	auto t1 = std::chrono::steady_clock::now();

	r.json_byte_length = buffer.size();
	r.json_write = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count() * 1e-6;
	// Read performance
	Jsonifier::Parser parser{ buffer };
	t0 = std::chrono::steady_clock::now();
	for (size_t i = 0; i < iterations_abc; ++i) {
		parser.parseJson(obj, buffer);
	}
	t1 = std::chrono::steady_clock::now();

	r.json_read = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count() * 1e-6;

	r.print();

	return r;
}

auto Jsonifier_test() {
	std::string buffer{ json0 };

	obj_t obj{};
	Jsonifier::Serializer serializer{};

	results r{ "Jsonifier", "https://github.com/RealTimeChris/Jsonifier", iterations };
	// write performance

	Jsonifier::Parser parser{ buffer };
	auto t0 = std::chrono::steady_clock::now();
	for (size_t i = 0; i < iterations; ++i) {
		parser.parseJson(obj, buffer);
	}
	
	auto t1 = std::chrono::steady_clock::now();

	r.json_read = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count() * 1e-6;


	t0 = std::chrono::steady_clock::now();

	for (size_t i = 0; i < iterations; ++i) {
		serializer.serializeJson(obj, buffer);
	}

	t1 = std::chrono::steady_clock::now();

	r.json_byte_length = buffer.size();
	r.json_write = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count() * 1e-6;
	// Read performance

	

	r.print();

	return r;
}

void abc_test() {
	glaze_abc_test();
	Jsonifier_abc_test();
	simdjson_abc_test();
}

void test0() {
	Jsonifier_test();
	//glaze_test();
}

template<typename OTy>
concept CheckedForSize = Jsonifier::StringT<OTy> || Jsonifier::JsonifierStringT<OTy> || std::same_as<OTy, std::string>;

template<typename OTy>
concept HasSize = requires(OTy object) { object.size(); };

template<HasSize T> constexpr size_t size_of_member(const T& member) {
	return member.size() * sizeof(typename T::value_type) ;
}

template<typename T> constexpr size_t checkForSize(const T& member) {
	return 0;
}

template<CheckedForSize T> constexpr size_t checkForSize(const T& member) {
	return size_of_member(member);
}

template<typename Tuple, std::size_t... Is> constexpr size_t size_of_tuple_impl(const Tuple& tup, std::index_sequence<Is...>) {
	return (checkForSize(Jsonifier::Tuplet::get<Is>(tup)) + ...);
}

template<typename... Ts> constexpr size_t size_of_tuple(const Jsonifier::Tuplet::Tuple<Ts...>& tup) {
	return size_of_tuple_impl(tup, std::make_index_sequence<sizeof...(Ts)>());
}

struct testStruct {
	std::string testString{ "TESTING" };
	std::vector<int32_t> vector{ 34 };
};

int main() {
	std::string v1{ "TESTING TESTING" };
	std::cout << "TOTAL SIZE: " << sizeof(v1) + v1.size() << std::endl;
	std::vector<int> v2{ 4, 5 };
	std::cout << "TOTAL SIZE: " << sizeof(v2) + (v2.size() * sizeof(int)) << std::endl;
	Jsonifier::Tuplet::Tuple t{ v1, v2, testStruct{} };
	std::cout << size_of_tuple(t) << '\n';
	abc_test();
	test0();

	return 0;
}

