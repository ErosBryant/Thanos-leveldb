## Make the Thanos-DB for Fast 24

Just do it!!!!!

### `Wisceky`
```
benchmarks 
- stats        -- Print DB stats & time
- vlog_stats   -- Print vlog bufer size

```

```
-- vlog        -- use wisckey

```
./db_bench --benchmarks="readseq" --num=100000 --vlog=1 --db=/home/eros/workspace/Thanos-leveldb/tmp --use_existing_db=1

- ./db_bench --benchmarks="fillrandom,stats,vlog_stats" --vlog=1   
- ./db_bench --benchmarks="readrandom,stats,vlog_stats"  --db=