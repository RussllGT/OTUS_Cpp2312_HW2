#include "readwrite.h"
#include "ip_address.h"
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <exception>
#include <algorithm>
#include <stdlib.h>

//#define TEST_IN
//#define TEST_OUT

int main()
{
    try
    {

#ifdef TEST_IN
        tsk_ip::source_data container = tsk_ip::read_test();
#else
        tsk_ip::source_data container = tsk_ip::read_stream(std::cin);
#endif // TEST_IN
        
        std::vector<tsk_ip::ip_address> ips;
        for (const auto& data : container) ips.push_back(std::get<0>(data));

        std::sort(std::rbegin(ips), std::rend(ips));

        std::vector<tsk_ip::ip_address> temp[] = { std::vector<tsk_ip::ip_address>(), std::vector<tsk_ip::ip_address>(), std::vector<tsk_ip::ip_address>() };
        for (const auto& ip : ips)
        {
            if (ip.get_byte(0) == 1) temp[0].push_back(ip);

            if (ip.get_byte(0) == 46 && ip.get_byte(1) == 70)
            {
                temp[1].push_back(ip);
                temp[2].push_back(ip);
            }

            for (int index = 1; index < 4; ++index)
            {
                if (ip.get_byte(index) == 46) temp[2].push_back(ip);
            }
        }

        std::vector<tsk_ip::ip_address> solution (ips);
        for (const auto& vec : temp)
        {
            for (const auto& ip : vec)
            {
                solution.push_back(ip);
            }
        }

#ifdef TEST_OUT
        tsk_ip::write_test(solution);
#else
        tsk_ip::write_stream(std::cout, solution);
#endif // TEST_OUT

    }
    catch(std::exception exception)
    {
        std::cerr << exception.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}