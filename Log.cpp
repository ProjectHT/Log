/*************************************************************************************************/
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/*************************************************************************************************/
/* 
 * File:   Log.cpp
 * Author: Thong_Laptop
 * 
 * Created on September 19, 2018, 10:38 AM
 */
/*************************************************************************************************/
#include "Log.h"
/*************************************************************************************************/
Log::Log(string link) {
    stream = ofstream(link.c_str(), ofstream::out | ofstream::app);
    if (stream) {
        flag_enable = true;
    }
    else {
        flag_enable = false;
    }
}
/*************************************************************************************************/
Log::Log(const Log& orig) {
}
/*************************************************************************************************/
Log::~Log() {
    if (flag_enable == true) {
        stream.close();
    }
}
/*************************************************************************************************/
void Log::write(string tilte, string data) {
    if (flag_enable) {
        time_t tt;
        time(&tt);
        tm TM = *localtime(&tt);
        char* temp_time = new char[25];
        sprintf(temp_time, "%02d-%02d-%04d_%02d:%02d:%02d", TM.tm_mday, TM.tm_mon + 1, TM.tm_year + 1900, TM.tm_hour, TM.tm_min, TM.tm_sec);
        string time(temp_time);
        stream << time << "|" << tilte << "|" << data << "\r\n";
        stream.flush();
        delete[] temp_time;
    }
}
/*************************************************************************************************/
