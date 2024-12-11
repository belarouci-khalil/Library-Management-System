cmake_minimum_required(VERSION 3.30)

# Define the project name
project(untitled)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)

# Include directories for SQLite3 and sqlite_orm
include_directories(
        ${CMAKE_SOURCE_DIR}/sqlite                  # Path to SQLite3 headers
        ${CMAKE_SOURCE_DIR}/lib/sqlite_orm/include/sqlite_orm # Path to sqlite_orm headers
        ${CMAKE_SOURCE_DIR}/include                    # Path to project headers

)

# Add the SQLite3 source file
add_library(sqlite3 STATIC
        ${CMAKE_SOURCE_DIR}/sqlite/sqlite3.c
        include/database.h
        include/book.h
        include/author.h
        include/borrower.h
        include/borrow_record.h
)

# Add the executable target
add_executable(untitled
        src/main.cpp
        src/database.cpp
        src/book.cpp
        src/author.cpp
        src/borrower.cpp
        src/borrow_record.cpp
)

# Link the SQLite3 library to the executable
target_link_libraries(untitled sqlite3)
