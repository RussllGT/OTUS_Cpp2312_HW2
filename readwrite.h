#pragma once

#include "ip_address.h"
#include <string>
#include <vector>
#include <tuple>

namespace tsk_ip
{
	using source_data = std::vector<std::tuple<ip_address, std::string, std::string>>;

	source_data read_stream(std::istream& stream);
	source_data read_file(const std::string& filename);
	source_data read_test();

	void write_stream(std::ostream& stream, const std::vector<ip_address>& ips);
	void write_file(const std::string& filename, const std::vector<ip_address>& ips);
	void write_test(const std::vector<ip_address>& ips);
}