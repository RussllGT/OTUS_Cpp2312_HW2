#include "readwrite.h"
#include "auxiliary.h"
#include <fstream>
#include <exception>
#include <iostream>

namespace tsk_ip
{
	const std::string test_source_file = R"(d:\Programming\C++\OTUS C++ 2023-12\2024-01-11 C++11. auto, lambda, tuple\ip_filter.tsv)";
	const std::string test_result_file = R"(d:\Programming\C++\OTUS C++ 2023-12\2024-01-11 C++11. auto, lambda, tuple\ip_filter_result.tsv)";

	source_data read_stream(std::istream& stream)
	{
		source_data result;

		std::string line;
		std::vector<std::string> data;
		while (std::getline(stream, line))
		{
			data = aux::split_string(line, '\t');
			if (data.size() != 3) throw new std::exception("Incorrect input");

			result.push_back(std::make_tuple(ip_address(data[0]), data[1], data[2]));
		}

		return result;
	}

	source_data read_file(const std::string& filename)
	{
		std::ifstream filestream(filename);

		if (filestream.is_open())
		{
			source_data result = read_stream(filestream);
			filestream.close();
			return result;
		}
		else
		{
			throw new std::exception("Incorrect file");
		}
	}

	source_data read_test()
	{
		return read_file(test_source_file);
	}

	void write_stream(std::ostream& stream, const std::vector<ip_address>& ips)
	{
		for (const auto& ip : ips) stream << ip.get_value() << std::endl;
	}

	void write_file(const std::string& filename, const std::vector<ip_address>& ips)
	{
		std::ofstream filestream;
		filestream.open(filename);

		if (filestream.is_open())
		{
			write_stream(filestream, ips);
			filestream.close();
		}
		else
		{
			throw new std::exception("Incorrect file");
		}
	}

	void write_test(const std::vector<ip_address>& ips)
	{
		write_file(test_result_file, ips);
	}
}