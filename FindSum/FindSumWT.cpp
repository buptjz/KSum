//
//  FindSumWT.cpp
//  LeetCode
//
//  Created by WangJZ on 14-2-27.
//  Copyright (c) 2014年 WangJZ. All rights reserved.
//

/*
 大仙给我出了一道难题，在下面这些书中，找出若干个数，这些数的和是一个指定的值
 穷举方法几乎行不通，因为20！我们已然算不了了，但是大仙给出了一些线索，他时从下向上找出这些数的！解虽然可能不止一个，但是能找到一个就行
 
 所以穷举+剪枝方法，最终奇迹般的解决了这个问题：
 
 值得注意的两点：
 1)DFS搜索时候，level不适用level+1,而是用i+1,因为下一个位置上得数的候选者是从数i开始的
 2）浮点数用 == 表达式的时候要特别注意，一般都是绝对值小于一个非常小的数，不然精度不够
 
 */

#include "FindSumWT.h"
#include <vector>
using namespace std;
double WTtarget = 357641.3;
double all_num[] = {17409.30,114864.40,113256.00,7776.20,22558.00,7264.00,12096.40,59056.80,64231.20,67684.00,45096.00,158610.00,22634.00,40956.50,18656.80,13520.10,34348.90,77789.40,252330.40,56616.20,9084.00,9221.70,825.00,17914.40,6754.70,27583.80,190347.10,36554.00,24337.60,115967.50,358399.70,107004.40,57283.20,12096.40,6080.00,13320.00,13320.00,1040.00,6845.00,6845.00,6845.00,26600.00,39376.00,40060.00,19460.00,79260.00,21048.00,41500.00,174800.00,13320.00,22800.00,75624.00,56129.20,1824.00,30928.80,12900.00,94200.00,9595.80,15445.00,38920.00,25713.10,7600.00,69052.00,51600.00,3252.00,3252.00,13148.00,13152.50,6845.00,6845.00,9730.00,9730.00,16748.00,20328.00,19604.00,724.00,1598.00,5240.00,5240.00,10737.00,19366.10,6147.00,10737.00,43040.60,9848.00,9848.00,14765.00,3207.20,3252.00,3252.00
};

int NN;
vector<double> numbers;
int COUNT;

int compare(vector<double> &tmp,double target){
    //0代表找到，1代表tmp大，-1代表tmp小
    double total = 0;
    for (int i = 0; i < tmp.size(); i++) {
        total += tmp[i];
    }
    if ((total - target) * (total - target) < 0.01) {//如果找到，打印出来
        printf("!!!FIND!!!---");
        for (int i = 0; i < tmp.size(); i++) {
            printf("%f\t",tmp[i]);
        }
        printf("\n");
        return 0;
    }
    if(total > target){
        return 1;
    }else{
        return -1;
    }
}

void findSumHelper(vector<double> &tmp,double target,int level){
    if(COUNT % 100000000 == 0){
        printf("FIND %d\n",COUNT);
    }
    COUNT++;
    
    int result = compare(tmp, target);
    if (result != -1) {//找到或者超出
        return;
    }else{
        for (int i = level; i < NN; i++) {
            tmp.push_back(numbers[i]);
            findSumHelper(tmp, target, i+1);
            tmp.pop_back();
        }
    }
}

void JZfind_sum(){
    //j减去后11个数
    for (int i = 89; i >= 79; i--) {
        WTtarget -= all_num[i];
    }
    
    for (int i = 78; i > 29; i--) {
        numbers.push_back(all_num[i]);
    }
    NN = (int)numbers.size();
    vector<double>tmp;
    findSumHelper(tmp, WTtarget, 0);
    COUNT = 0;
}

