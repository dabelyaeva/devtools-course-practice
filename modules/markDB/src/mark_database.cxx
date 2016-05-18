// Copyright 2016 Dolotov Evgeniy

#include <algorithm>
#include <vector>
#include <string>
#include <stdexcept>
#include <utility>

#include "../include/mark_database.h"

using std::find;
using std::string;
using std::vector;
using std::pair;
using std::out_of_range;

MarkDataBase::ReturnCode MarkDataBase::searchStudent(const Student& student,
                                       size_t* index) const {
    auto findStudent = find(students.begin(), students.end(), student);
    if (findStudent != students.end()) {
        if (index != nullptr) {
            *index = distance(students.begin(), findStudent);
        }
        return ReturnCode::Success;
    } else {
        return ReturnCode::StudentNotFound;
    }
}

MarkDataBase::ReturnCode MarkDataBase::searchSubject(const Subject& subject,
                                       size_t* index) const {
    auto findSubject = find(subjects.begin(), subjects.end(), subject);
    if (findSubject != subjects.end()) {
        if (index !=0) {
            *index = distance(subjects.begin(), findSubject);
        }
        return ReturnCode::Success;
    } else {
        return ReturnCode::SubjectNotFound;
    }
}

MarkDataBase::ReturnCode MarkDataBase::addStudent(const Student& student) {
    if (searchStudent(student) == ReturnCode::StudentNotFound) {
        students.push_back(student);
        return ReturnCode::Success;
    } else {
        return ReturnCode::StudentAlreadyExist;
    }
}

MarkDataBase::ReturnCode MarkDataBase::addSubject(const Subject& subject) {
    if (searchSubject(subject) == ReturnCode::SubjectNotFound) {
        subjects.push_back(subject);
        return ReturnCode::Success;
    } else {
        return ReturnCode::SubjectAlreadyExist;
    }
}

MarkDataBase::ReturnCode MarkDataBase::deleteStudent(const Student& student) {
    size_t index;
    if (searchStudent(student, &index) == ReturnCode::Success) {
        students.erase(students.begin() + index);
        for (auto record = records.begin() ; record != records.end(); ) {
            if (record->student == student) {
                record = records.erase(record);
            } else {
                ++record;
            }
        }
        return ReturnCode::Success;
    } else {
        return ReturnCode::StudentNotFound;
    }
}


MarkDataBase::ReturnCode MarkDataBase::deleteSubject(const Subject& subject) {
    size_t index;
    if (searchSubject(subject, &index) == ReturnCode::Success) {
        subjects.erase(subjects.begin() + index);
        for (auto record = records.begin() ; record != records.end(); ) {
            if (record->subject == subject) {
                record = records.erase(record);
            } else {
                ++record;
            }
        }
        return ReturnCode::Success;
    } else {
        return ReturnCode::SubjectNotFound;
    }
}

MarkDataBase::ReturnCode MarkDataBase::addNewRecord(const Student& student,
                                      const Subject& subject,
                                      const int& mark) {
    if (searchStudent(student) == ReturnCode::Success) {
        if (searchSubject(subject) == ReturnCode::Success) {
            if (search(student, subject) == ReturnCode::RecordNotFound) {
                records.push_back(Record(student, subject, mark));
                return ReturnCode::Success;
            } else {
                return ReturnCode::RecordAlreadyExist;
            }
        } else {
            return ReturnCode::SubjectNotFound;
        }
    } else {
        return ReturnCode::StudentNotFound;
    }
}

MarkDataBase::ReturnCode MarkDataBase::deleteRecord(const Student& student,
                                      const Subject& subject) {
    if (search(student, subject) == ReturnCode::Success) {
        Record record(student, subject);
        records.erase(find(records.begin(), records.end(), record));
        return ReturnCode::Success;
    } else {
        return ReturnCode::RecordNotFound;
    }
}

MarkDataBase::ReturnCode MarkDataBase::search(const Student& student,
                                const Subject& subject, size_t* index) const {
    auto findRecord = find(records.begin(), records.end(),
                           Record(student, subject));
    if (findRecord != records.end()) {
        if (index !=nullptr) {
            *index = distance(records.begin(), findRecord);
        }
        return ReturnCode::Success;
    } else {
        return ReturnCode::RecordNotFound;
    }
}

MarkDataBase::ReturnCode MarkDataBase::getRecord(const size_t& indexOfRecord,
                                   Record* record) const {
    if (indexOfRecord < numberOfRecords()) {
        *record = records[indexOfRecord];
        return ReturnCode::Success;
    } else {
        return ReturnCode::WrongIndex;
    }
}

MarkDataBase::ReturnCode MarkDataBase::deleteRecord(const size_t& index) {
    if (index < numberOfRecords()) {
        records.erase(records.begin()+index);
        return ReturnCode::Success;
    } else {
        return ReturnCode::WrongIndex;
    }
}

MarkDataBase::ReturnCode
MarkDataBase::marksOfStudent(const Student& student,
                             vector< pair<Subject, int> >* marks) const {
    if (searchStudent(student) == ReturnCode::Success) {
        for (size_t recID = 0; recID < numberOfRecords(); recID++) {
            Record record = records[recID];
            if (record.student == student) {
                marks->push_back(std::make_pair(record.subject, record.mark));
            }
        }
        return ReturnCode::Success;
    } else {
        return ReturnCode::StudentNotFound;
    }
}

MarkDataBase::ReturnCode
MarkDataBase::marksOnSubject(const Subject& subject,
                             vector< pair<Student, int> >* marks) const {
    if (searchSubject(subject) == ReturnCode::Success) {
        for (size_t recordID = 0; recordID < numberOfRecords(); recordID++) {
            Record record = records[recordID];
            if (record.subject == subject) {
                marks->push_back(std::make_pair(record.student, record.mark));
            }
        }
        return ReturnCode::Success;
    } else {
        return ReturnCode::SubjectNotFound;
    }
}

vector<Student> MarkDataBase::getStudentsList() const {
    return students;
}

vector<Subject> MarkDataBase::getSubjectsList() const {
    return subjects;
}

vector<Record> MarkDataBase::getRecordsList() const {
    return records;
}

size_t MarkDataBase::numberOfStudents() const {
    return students.size();
}

size_t MarkDataBase::numberOfSubjects() const {
    return subjects.size();
}

size_t MarkDataBase::numberOfRecords() const {
    return records.size();
}
