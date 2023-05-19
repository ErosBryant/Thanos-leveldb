//
// Created by daiyi on 2020/02/02.
//

#include <util/mutexlock.h>
#include "util.h"
#include "map"
#include <x86intrin.h>

using std::to_string;

namespace adgMod {

    bool MOD = 0 ;
    bool string_mode = true;
   
    int key_size;
    int value_size;
    leveldb::Env* env;
    leveldb::DBImpl* db;
    leveldb::ReadOptions read_options;
    leveldb::WriteOptions write_options;

    bool fresh_write = false;


//./db_bench --benchmarks="fillrandom" --mod=8  --db=/home/eros/workspace/Bourbon/tmp1 --value_size=4096

    std::atomic<int> num_read(0);
    std::atomic<int> num_write(0);


    leveldb::port::Mutex compaction_counter_mutex;
    leveldb::port::Mutex file_stats_mutex;


    int compare(const Slice& slice, const string& string) {
        return memcmp((void*) slice.data(), string.c_str(), slice.size());
    }

    bool operator<(const Slice& slice, const string& string) {
        return memcmp((void*) slice.data(), string.c_str(), slice.size()) < 0;
    }
    bool operator>(const Slice& slice, const string& string) {
        return memcmp((void*) slice.data(), string.c_str(), slice.size()) > 0;
    }
    bool operator<=(const Slice& slice, const string& string) {
        return memcmp((void*) slice.data(), string.c_str(), slice.size()) <= 0;
    }
    bool operator>=(const Slice& slice, const string& string) {
        return memcmp((void*) slice.data(), string.c_str(), slice.size()) >= 0;
    }

    uint64_t get_time_difference(timespec start, timespec stop) {
        return (stop.tv_sec - start.tv_sec) * 1000000000 + stop.tv_nsec - start.tv_nsec;
    }


}