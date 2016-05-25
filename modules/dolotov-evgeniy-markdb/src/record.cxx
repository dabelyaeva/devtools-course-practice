// Copyright 2016 Dolotov Evgeniy

#include "include/record.h"

bool Record::operator ==(const Record& record) const {
    bool areStudentSame = (this->student == record.student);
    bool areSubjectSame = (this->subject == record.subject);
    return areStudentSame && areSubjectSame;
}

Record::Record(Student student, Subject subject, Mark mark) {
    this->student = student;
    this->subject = subject;
    this->mark = mark;
}
