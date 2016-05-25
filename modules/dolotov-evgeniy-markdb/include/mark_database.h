// Copyright 2016 Dolotov Evgeniy

#ifndef MODULES_DOLOTOV_EVGENIY_MARKDB_INCLUDE_MARK_DATABASE_H_
#define MODULES_DOLOTOV_EVGENIY_MARKDB_INCLUDE_MARK_DATABASE_H_

#include <string>
#include <vector>
#include <utility>
#include <exception>

#include "include/record.h"

class MarkDatabase {
 public:
    enum class ReturnCode {
        StudentNotFound,
        StudentAlreadyExist,
        SubjectNotFound,
        SubjectAlreadyExist,
        RecordNotFound,
        RecordAlreadyExist,
        WrongIndex,
        Success
    };
    ReturnCode addStudent(const Student& student);
    ReturnCode deleteStudent(const Student& student);
    ReturnCode addSubject(const Subject& subject);
    ReturnCode deleteSubject(const Subject& subject);
    ReturnCode searchStudent(const Student& student,
                             size_t* index = nullptr) const;
    ReturnCode searchSubject(const Subject& subject,
                             size_t* index = nullptr) const;
    ReturnCode addNewRecord(const Student& student, const Subject& subject,
                            const Mark& mark);
    ReturnCode deleteRecord(const Student& student, const Subject& subject);
    ReturnCode search(const Student& student, const Subject& subject,
                      size_t* index = 0) const;
    ReturnCode getRecord(const size_t& indexOfRecord, Record* record) const;
    ReturnCode deleteRecord(const size_t& indexOfRecord);
    ReturnCode marksOfStudent(const Student& student,
                       std::vector< std::pair<Subject, Mark> >* marks) const;
    ReturnCode marksOnSubject(const Subject& subject,
                       std::vector< std::pair<Student, Mark> >* marks) const;
    std::vector<Student> getStudentsList() const;
    std::vector<Subject> getSubjectsList() const;
    std::vector<Record> getRecordsList() const;
    size_t numberOfStudents() const;
    size_t numberOfSubjects() const;
    size_t numberOfRecords() const;

 private:
    std::vector<Student> students;
    std::vector<Subject> subjects;
    std::vector<Record> records;
};

#endif  // MODULES_DOLOTOV_EVGENIY_MARKDB_INCLUDE_MARK_DATABASE_H_
