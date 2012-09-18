#pragma once
#ifndef H_ENCODING
#define H_ENCODING

#include <string>

std::string utf8_to_ansi(const std::string& utf8);
std::string ansi_to_utf8(const std::string& gb2312);

#endif
