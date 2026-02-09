# TomSQL

A learning project in building a relational database management system from scratch in C++.

## What's implemented

- **Table creation** -- `Table` class that initializes column metadata and persists schema to binary files
- **Binary storage layer** -- custom serialization of column names and table metadata to disk
- **Database initialization** -- `initDB()` checks for existing structure files, bootstraps from scratch if missing
- **Schema registry** -- binary file tracking all table names, with read-back for schema discovery

## What's in progress

- Dynamic table structure (currently schema is hardcoded)
- Row insertion and binary serialization of row data
- Reading table metadata back from binary (deserialization)

## Why build this

Understanding how databases actually work under the hood -- how schemas are persisted, how data is serialized to disk, how metadata is managed -- by implementing it from first principles rather than just reading about it.

## Stack

C++, Xcode
