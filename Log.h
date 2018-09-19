/*************************************************************************************************/
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/*************************************************************************************************/
/* 
 * File:   Log.h
 * Author: Thong_Laptop
 *
 * Created on September 19, 2018, 10:38 AM
 */
/*************************************************************************************************/
#ifndef LOG_H
#define LOG_H
/*************************************************************************************************/
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
/*************************************************************************************************/
using namespace std;
/*************************************************************************************************/
class Log {
public:
    Log(string link);
    Log(const Log& orig);
    virtual ~Log();
    void write(string tilte, string data);
private:
    ofstream stream;
    bool flag_enable;
};
/*************************************************************************************************/
static Log my_log("/home/sys_log.txt");
#endif /* LOG_H */
/*************************************************************************************************/
