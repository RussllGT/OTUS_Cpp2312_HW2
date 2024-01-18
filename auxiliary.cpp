#include "auxiliary.h"

namespace aux
{
	std::vector<std::string> split_string(const std::string& str, const char& splitter)
	{
		std::vector<std::string> result;
		std::string next;

		for (const char& ch : str)
		{
			if (ch == splitter)
			{
				if (!next.empty())
				{
					result.push_back(next);
					next.clear();
				}
			}
			else
			{
				next += ch;
			}
		}

		if (!next.empty()) result.push_back(next);
		return result;
	}
}