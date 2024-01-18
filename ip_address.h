#pragma once

#include <string>
#include <cstdint>

namespace tsk_ip
{
	class ip_address
	{
	public:
		ip_address();
		ip_address(const std::string& str);
		~ip_address() {};

		std::string get_value() const;
		uint8_t get_byte(int index) const;

		bool operator==(const ip_address& other);
		bool operator!=(const ip_address& other);
		bool operator<(const ip_address& other);
		bool operator>(const ip_address& other);

	private:
		uint8_t _address[4];
	};
}