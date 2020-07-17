#include "headers/main.hpp"
#include "headers/includes.hpp"
#include<stack>
#include<cstdio>
#include<cstdlib>

// using namespace std;
void showhelp(const char* path) {
    // 输入程序路径
    printf("Usage:%s [options]... [arguments]...\n", path);
    printf(" -h, --help              show help information\n");
    printf(" -H, --hex               input a HEX number\n");
    printf(" -O, --oct               input a OCT number\n");
    printf(" -B, --bin               input a bindary number\n");
    printf(" -D, --dec               input a dec number\n");
    //printf("-W, --write             input a file name to save output\n");
    printf(" -o, --output            output with input hex\n");
}

void execnum(int stage_option_num, char* stage_arg_num, char* stage_arg_o) {
    // 先判断输入进制如果输入为十进制则直接调用DecToany函数
    // 如果不是则先调用anyToDEc函数，如果输出为10进制则直接输出
    // 如果不是则调用DecToany在调用函数输出
    // 调用的的进制宏都定义在main.hpp头文件内
    std::string ans;
    switch (stage_option_num)
    {
    case 'H':
    //16进制
        if(atoi(stage_arg_o) == 10)                     // 输出为10进制
            std::cout << HEX << "进制" << stage_arg_num << "转换为10进制的结果为" << anyToDec(HEX, stage_arg_num) << std::endl;
        else{
            ans = anyToDec(HEX, stage_arg_num);
            std::cout << HEX << "进制" << stage_arg_num << "转换为" << atoi(stage_arg_o) << "进制的结果为" 
                << DecToany(atoi(stage_arg_o), ans) << std::endl;
        }
        break;
    case 'O':
    // 8进制
        if(atoi(stage_arg_o) == 10)                     // 输出为10进制
            std::cout << OCT << "进制" << stage_arg_num << "转换为10进制的结果为" << anyToDec(HEX, stage_arg_num) << std::endl;
        else{
            ans = anyToDec(OCT, stage_arg_num);
            std::cout << OCT << "进制" << stage_arg_num << "转换为" << atoi(stage_arg_o) << "进制的结果为" << DecToany(atoi(stage_arg_o), ans) << std::endl;
        }
        break;
    case 'B':
    // 二进制
        if(atoi(stage_arg_o) == 10)                     // 输出为10进制
            std::cout << BIN << "进制" << stage_arg_num << "转换为10进制的结果为" << anyToDec(HEX, stage_arg_num) << std::endl;
        else{
            ans = anyToDec(BIN, stage_arg_num);
            std::cout << BIN << "进制" << stage_arg_num << "转换为" << atoi(stage_arg_o) << "进制的结果为" << DecToany(atoi(stage_arg_o), ans) << std::endl;
        }
        break;
    case 'D':
    //十进制
        std::cout << DEC << "进制" << stage_arg_num << "转换为" << atoi(stage_arg_o) << "进制的结果为" << DecToany(atoi(stage_arg_o), ans) << std::endl;
        break;
    default:
        printf("格式错误\n");
        break;
    }


}

inline std::string anyToDec(int src, char* num) {
#ifdef STRING_CODE
    string num = to_string(atoi(stage_arg_num));
    int i = 0, ans = 0;
    while (num.size() != i)
    {
        ans *= src;
        ans += num[i] - '0';
        i++;
    }
    return ans;
#endif
// #ifdef SS_CODE
    int n;
    std::stringstream ssSrc, ssDes;
    ssSrc << num;
    switch (src)
    {
    case HEX:
        ssSrc >> std::hex >> n;
        ssDes << n;
        break;
    case OCT:
        ssSrc >> std::oct >> n;
        ssDes << n;
        break;
    case BIN:
        n = std::stoi(ssSrc.str(), nullptr, 2);
        ssDes << n;
        break;
    default:
        std::cout << "输入和输出进制不能一样" << std::endl;
        exit(EXIT_FAILURE);
        break;
    }
    return ssDes.str();
// #endif
}

inline std::string DecToany(int dec, std::string num) {
#ifdef STRING_CODE
    std::stack<int> s;
    std::string ans;
    while(num) {
        s.push(num % dec);
        num /= dec;
    }
    while(!s.empty()) {
        switch (s.top())
        {
        case 10:
            ans = ans + 'A';
            break;
        case 11:
            ans = ans + 'B';
            break;
        case 12:
            ans = ans + 'C';
            break;
        case 13:
            ans = ans + 'D';
            break;
        case 14:
            ans = ans + 'E';
            break;
        case 15:
            ans = ans + 'F';
            break;
        default:
            ans.append(std::to_string(s.top()));
            break;
        }
        s.pop();
    }
    return ans;
#endif
// #ifdef SS_CODE
    int n;
    std::stringstream ssSrc;
    std::stringstream ssDes;
    std::string s;
    ssSrc << num;
	if(dec == HEX){
		ssDes << std::hex << ssSrc.str();
	}
	else if(dec == OCT) 
	{
		ssDes << std::oct << ssSrc.str();
	}
	else if(dec == BIN)
	{
		ssSrc >> n;
		
		std::bitset<NUMSIZE> bitInt(n);
		s = bitInt.to_string();
		ssDes << s;
	}
    else{
        std::cout << "输入和输出进制不能一样" << std::endl;
        exit(EXIT_FAILURE);
    }
    return ssDes.str();
// #endif
}