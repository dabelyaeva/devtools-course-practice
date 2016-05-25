// Copyright 2016 Dolotov Evgeniy

#ifndef MODULES_MARKDB_INCLUDE_RECORD_H_
#define MODULES_MARKDB_INCLUDE_RECORD_H_

#include <string>

typedef std::string Student;
typedef std::string Subject;

struct Record {
 public:
    explicit Record(Student student = "",
                    Subject subject = "",
                    int mark = 5);
    Student student;
    Subject subject;
    int mark;
    bool operator==(const Record& record) const;
};

#endif  // MODULES_MARKDB_INCLUDE_RECORD_H_
