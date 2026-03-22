#include "LogParser.hpp"

// std
#include <fstream>
#include <iostream>

LogParser::LogParser(std::string_view filename, std::string_view level) : filename(filename), level(level) {}

void LogParser::analyze() {
	std::ifstream file(filename.data());
	if (!file.is_open()) {
		std::cerr << "Error: can't open file\n";
		return;
	}
	std::string line;
	while (std::getline(file, line)) {
		totalLines++;
		if (line.find(level) != std::string::npos) {
			matchCount++;
			if (savedLogs.size() < 5) {
				savedLogs.push_back(line);
			}
		}
	}
}

void LogParser::print_report() const {
	std::cout << "--- Отчет анализа логов\n"
			  << "Всего проанализировано строк: " << totalLines << "\n"
			  << "Найдено совпадений по уровню '" << level << "': " << matchCount << "\n\n"
			  << "Первые совпадения:\n";

	int i = 1;
	for (const auto& log : savedLogs) {
		std::cout << i++ << ". " << log << "\n";
	}
}