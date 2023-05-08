/*
#include <stdint.h>
#include <stdio.h>


namespace wisckey {

struct Options;
struct ReadOptions;
struct WriteOptions;

class DB {


virtual Status Put{ 
    
    long offset = ftell (wk->logfile);
	long size = sizeof(value);
	std::string vlog_offset = std::to_string(offset);
	std::string vlog_size = std::to_string(size);
	std::stringstream vlog_value;
    vlog_value << vlog_offset << "&&" << vlog_size;
    std::string s = vlog_value.str();
    fwrite (&value, sizeof(value),1,wk->logfile);
    return s;
}


}
*/