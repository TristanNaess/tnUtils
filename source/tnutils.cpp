#include "tnutils.hpp"

std::string tnUtils::chomp(std::string_view line)
{
    std::size_t start = line.find_first_not_of(tnUtils::whitespace);
    if (start < line.size()) line.remove_prefix(start);
    std::size_t end = line.size() - line.find_last_not_of(tnUtils::whitespace);
    if (end < line.size()) line.remove_suffix(end);
    return std::string{line};
}

std::string& tnUtils::chomp(std::string& line)
{
    std::size_t start = line.find_first_not_of(tnUtils::whitespace);
    if (start < line.size()) line.erase(0, start);
    std::size_t end = line.size() - line.find_last_not_of(tnUtils::whitespace);
    if (end < line.size()) line.erase(end, std::string::npos);

    return line;
}

std::string tnUtils::remove_whitespace(std::string_view line)
{
    std::string new_line;
    new_line.reserve(line.size());

    bool in_quotes = false;
    bool escaped = false;
    for (const auto c: line)
    {
        if (tnUtils::contains(tnUtils::whitespace, c) && !in_quotes);
        else
        {
            if (c == '"' && !escaped) in_quotes = !in_quotes;
            if (c == '\\') escaped = !escaped;

            new_line.push_back(c);
        }
    }

    return new_line;
}

std::string& tnUtils::remove_whitespace(std::string& line)
{
    line = tnUtils::remove_whitespace(std::string_view(line)); // I think this is efficient?
    return line;
}
