#include "LogParser.hpp"

// std
#include <iostream>
#include <chrono>
#include <memory>

int main(int argc, char** argv) {
	auto start = std::chrono::high_resolution_clock::now();
	if (argc != 3) {
		std::cerr << "Error: program need two arguments: ./log-analyzer <file> <level>\n";
		return 1;
	}

	std::unique_ptr<LogParser> logParser = std::make_unique<LogParser>(argv[1], argv[2]);

	logParser->analyze();
	logParser->print_report();

	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

	std::cout << "\n" << "Время выполнения: " << duration << " ms" << std::endl;

	return 0;
}