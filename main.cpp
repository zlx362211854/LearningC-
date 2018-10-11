#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
// 生成随机数公共函数
int createRandom(int low, int high) {
    int a;
    // 生成实际的随机数
    a = (low + rand() % (high - low + 1));
    return a;
}
// 生成问题的公共函数
int createQuestion(int i) {
    int answer;
    int results;
    std::string symbol;
    // 设置随机种子
    srand(time(NULL));
    int num1 = createRandom(0, 100); // 生成第一个参与运算的随机数
    int num2 = createRandom(0, 100); // 生成第二个参与运算的随机数

    /*
    定义规则：
    1: 加法运算
    2: 减法运算
    3: 乘法运算
    4: 除法运算
    */
    int c = createRandom(1, 4); // 生成控制运算规则的随机数；
    switch (c){
    case 1:
        results = num1 + num2;
        symbol = "+";
        break;
    case 2:
        results = num1 - num2;
        symbol = "-";
        break;
    case 3:
        results = num1 * num2;
        symbol = "×";
        break;
    case 4:
        results = num1 / num2;
        symbol = "÷";
        std::cout << " ⚠️ 除法运算只保留整数位..." << std::endl;
        break;
    }

    std::string content = std::to_string(num1) + symbol + std::to_string(num2);
    std::cout << "第"+ std::to_string(i + 1) +"题：" + content + "= ?" << std::endl;
    
    int count = 1;
    while (count <= 3){
    std::cout << "(第"+std::to_string(count)+"次输入)请输入你的答案：";
    std::cin >> answer; // 用户输入答案
        if (answer == results) {
            std::cout << "答案正确!👍" << std::endl;
            break;
        } else if (count == 3) {
            std::cout << "三次机会已用完😫，正确答案为：" << results << std::endl;
            break;
        } else {
            count++;
        }
    }
    return 0;
}
int main() {
    int questionCount = 3; // 默认三道题目
    std::cout << "开始练习！本次练习你想生成几道题目？请输入题目数量：";
    std::cin >> questionCount; // 用户输入题目数
    // 循环生成算数题
    for (int i = 0; i < questionCount; i++){
        createQuestion(i);
    }
}
