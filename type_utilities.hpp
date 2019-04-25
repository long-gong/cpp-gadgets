#include <string>
#include <typeinfo>
#include <regex>

using namespace std;

namespace type_utilities {

	namespace literals {
		const std::regex hyphen_re("\\s*_+\\s*", std::regex_constants::ECMAScript | std::regex_constants::icase);
		const std::regex quantifier_re("class|struct", std::regex_constants::ECMAScript | std::regex_constants::icase);
		const std::regex whitespace_be_re("(^\\s+)|(\\s+$)", std::regex_constants::ECMAScript | std::regex_constants::icase);
	}// end namespace literals

	
template <class T>
inline constexpr string type_name(bool remove_quatifier = true) {
		auto str = std::string(typeid(T).name());
		if (remove_quatifier)
			str = std::regex_replace(str.c_str(), literals::quantifier_re, "");
		str = std::regex_replace(str.c_str(), literals::hyphen_re, "_");
		str = std::regex_replace(str.c_str(), literals::whitespace_be_re, "");
		return str;
	}
}// end namespace type_utilities
