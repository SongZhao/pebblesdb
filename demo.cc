#include <iostream>
#include "pebblesdb/db.h"

int main()
{
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true; 

    leveldb::Status status = leveldb::DB::Open(options, "testdb", &db);

    std::string key = "key123";
    std::string value = "value123";

    status = db->Put(leveldb::WriteOptions(), key, value);
    assert(status.ok());
    std::cout << "stat:" << status.ToString() << std::endl;

    std::string value1;
    status = db->Get(leveldb::ReadOptions(), key, &value1);
    assert(status.ok());
    std::cout << "stat:" << status.ToString() << std::endl;
    std::cout << "get, key1:" << key << " value1:" << value1 << std::endl;
    std::string key1 = "key456";
    status = db->Put(leveldb::WriteOptions(), key1, value1);
    assert(status.ok());

    status = db->Delete(leveldb::WriteOptions(), key1);
    assert(status.ok());


    delete db;
    return 0;
}
