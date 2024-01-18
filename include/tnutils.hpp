#ifndef __TNUTILS_HPP__
#define __TNUTILS_HPP__

#include <string>
#include <string_view> // C++17

namespace tnUtils
{
    // -----------------------------
    // String Utils
    // -----------------------------
    
    const std::string whitespace = " \t\n\r\v\f"; // basic ASCII whitespace characters. I may expand to UTF-8 if necessary

    template <typename CharT>
    constexpr bool contains(const std::basic_string_view<CharT> line, CharT c)
    {
        for (const auto i : line)
        {
            if (i == c) return true;
        }

        return false;
    }

    template <typename CharT>
    constexpr bool contains(const std::basic_string<CharT>& line, CharT c)
    {
        for (const auto i : line)
        {
            if (i == c) return true;
        }

        return false;
    }

    // remove leading and trailing whitespace
    // creates new chomped string
    std::string chomp(std::string_view line);
    
    // chomps in place
    std::string& chomp(std::string& line);

    // remove all whitespace characters not quote surrounded
    // creates new string
    std::string remove_whitespace(std::string_view line);

    // removes whitespace in place
    std::string& remove_whitespace(std::string& line);

    // possibly add mutible string_view equivalent, depending on whether it seems to be more efficient
}

#endif//__TNUTILS_HPP__
