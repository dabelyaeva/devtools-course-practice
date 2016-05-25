// Copyright 2016 Dolotov Evgeniy

#ifndef MODULES_DOLOTOV_EVGENIY_MARKDB_INCLUDE_RECORD_H_
#define MODULES_DOLOTOV_EVGENIY_MARKDB_INCLUDE_RECORD_H_

#include <string>

enum class Mark : int {
    A = 5,
    B = 4,
    C = 3,
    D = 2,
    E = 1
};

typedef std::string Student;
typedef std::string Subject;

struct Record {
 public:
    explicit Record(Student student = "",
                    Subject subject = "",
                    Mark mark = Mark::A);
    Student student;
    Subject subject;
    Mark mark;
    bool operator==(const Record& record) const;
};

#endif  // MODULES_DOLOTOV_EVGENIY_MARKDB_INCLUDE_RECORD_H_
