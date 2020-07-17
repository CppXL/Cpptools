#pragma once

#include<getopt.h>
#include<iostream>
#include<string>

static struct option long_options[] = {
            {"help",    no_argument ,       0,  'h'},
            {"hex",     required_argument,  0,  'H'},
            {"oct",     required_argument,  0,  'O'},
            {"bin",     required_argument,  0,  'B'},
            {"dec",     required_argument,  0,  'D'},
            {"write",   required_argument,  0,  'W'},
            {"output",  required_argument,  0,  'o'}
};


// help页面
void showhelp(const char* path);

void execnum(int stage_option_num, char* stage_arg_num, char* stage_arg_o);
// 任何进制转换为十进制，src为原进制，num为输入的数
inline std::string anyToDec(int src, char* num);
// 十进制到任意进制，返回值为转换后的数，dec是目标进制，num是输入的数
inline std::string DecToany(int dec, std::string num);