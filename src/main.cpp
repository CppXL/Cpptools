#include "headers/includes.hpp"// 引入头文件
#include "headers/main.hpp"

#include<stdio.h>


// execnum(option, optarg);
int main(int argc, char** argv) {
    
    int option;
    // int digit_optind = 0;
    int option_index = 0;
    int stage_option_num = -1;
    int stage_option_o = -1;
    char* stage_arg_num = NULL;
    char* stage_arg_o = NULL;
    /*
        引入变量记录整个命令行传递的参数，实现乱序命令也能解析的功能
        后面判断是否为零或者null检测输入
    */
    while (1) {
#ifdef DEBUG
int this_option_optind = optind ? optind : 1;
#endif
        // 获取命令输入的选项使用only避免歧义
        option = getopt_long_only(argc, argv, "hH:O:B:D:W:o:", long_options, &option_index);
        if (option == -1) {
            break;
        }
        switch (option)
        {
        case 'h':
            showhelp(argv[0]);
            stage_option_num = option;
            break;
        // 选择输入16、10、8、2进制都统一把操作和值赋给定义好的变量后面传入参数之中
        case 'H':
        case 'O':
        case 'B':
        case 'D':
        //case 'W':
#ifdef DEBUG
printf("option:%d\n", option);
printf("%s with arg %s and index %d\n", long_options[option_index].name, optarg, option_index);
#endif
            stage_option_num = option;
            stage_arg_num = optarg;
#ifdef DEBUG
            std::cout << "XXXX" << stage_option_num << std::endl;
#endif
            break;
        // 选择输出也一样用变量保存
        case 'o':
            stage_arg_o = optarg;
            stage_option_o = option;
            break;
        // 无效选项输出错误
        case '?':
            printf("Unknow Options %c\n", optopt);
            break;
        default:
            printf("getopt returned character code 0%o\n", option);
            break;
        }
    }
    // std::cout << stage_option_num << " " << stage_arg_num << " " << stage_option_o << " " << stage_arg_o << std::endl;

    if (optind < argc) {
            printf("non-option ARGV-elements: ");
            while (optind < argc)
            {
                printf("%s ", argv[optind++]); 
            }
            printf("\n");
    }
    // 判断选项值以此判断用户是否输入数值和做出选项
    if(stage_option_num == 'h')
    {
        return 0;
    }
    if(stage_option_num == -1 || stage_option_o == -1 || stage_arg_o == NULL || stage_arg_num == NULL)
    {
        showhelp(argv[0]);
        exit(EXIT_FAILURE);
    }
    // if(
    //     // 如果输入进制和选择的输出进制一样则报错
    //     (stage_option_num = 'H' && atoi(stage_arg_o) == 16) || 
    //     (stage_option_num == 'O' && atoi(stage_arg_o) == 8) || 
    //     (stage_option_num == 'B' && atoi(stage_arg_o) == 2) ||
    //     (stage_option_num == 'D' && atoi(stage_arg_o) == 10)
    // ) {
    //     printf("输入进制和输出进制不能相同\n");
    //     showhelp(argv[0]);
    //     exit(EXIT_FAILURE);
    // }
    // else {
        // 过了以上条件则进入处理函数，把值传入参数之中
        // 函数在includes.hpp头文件定义，在func.cpp实现
#ifdef DEBUG
        std::cout << stage_option_num << " " << stage_arg_num << " " << stage_option_o << " " << stage_arg_o << std::endl;
#endif
        execnum(stage_option_num, stage_arg_num, stage_arg_o);
    // }
    return 0;
}
