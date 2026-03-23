#pragma once

// std
#include <string>
#include <vector>
#include <string_view>

class LogParser {
public:
	LogParser(std::string_view filename, std::string_view level);

	void analyze();
	std::string get_report() const;

private:
	std::string_view filename;
	std::string_view level;
	std::vector<std::string> savedLogs;
	size_t matchCount = 0;
	size_t totalLines = 0;
};