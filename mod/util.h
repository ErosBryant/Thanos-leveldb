//
// Created by daiyi on 2020/02/02.
// a collection of global variables and flags/states/parameters

#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "db/db_impl.h"
#include "leveldb/slice.h"
#include "leveldb/env.h"
#include "Counter.h"

#include <x86intrin.h>


using std::string;
using std::vector;
//using std::map;
using leveldb::Slice;


namespace adgMod {

    //vlog =1 
    extern bool MOD;

    extern bool string_mode;

    // some variables and pointers made global
    extern int key_size;
    extern int value_size;
    extern leveldb::Env* env;
    extern leveldb::DBImpl* db;
    extern leveldb::ReadOptions read_options;
    extern leveldb::WriteOptions write_options;

    extern bool fresh_write;


    int compare(const Slice& slice, const string& string);
    bool operator<(const Slice& slice, const string& string);
    bool operator>(const Slice& slice, const string& string);
    bool operator<=(const Slice& slice, const string& string);
    bool operator>=(const Slice& slice, const string& string);
    uint64_t get_time_difference(timespec start, timespec stop);

}



