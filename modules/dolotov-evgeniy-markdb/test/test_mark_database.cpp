// Copyright 2016 Dolotov Evgeniy

#include <gtest/gtest.h>

#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>

#include "include/mark_database.h"


TEST(Record, Can_Create) {
    // Arrange
    Record* recordPtr;

    // Act
    recordPtr = new Record("Alexander Pitts", "Math", Mark::A);

    // Assert
    EXPECT_NE(nullptr, recordPtr);

    delete recordPtr;
}

TEST(Record, Can_Compare_Identical_Records) {
    // Arrange
    Record record1("Alexander Pitts", "Math", Mark::A);
    Record record2("Alexander Pitts", "Math", Mark::A);

    // Act && Assert
    EXPECT_EQ(true, record1 == record2);
}

TEST(Record, Can_Compare_Not_Identical_Records) {
    // Arrange
    Record record1("Alexander Pitts", "Math", Mark::A);
    Record record2("Alexander Pitts", "Biology", Mark::A);

    // Act && Assert
    EXPECT_NE(true, record1 == record2);
}

class MarkDatabaseTest : public ::testing::Test {
 protected:
    virtual void SetUp() {
        students.push_back("Alexander Pitts");
        students.push_back("Jesse Perkins");
        students.push_back("Brice McDowell");

        subjects.push_back("Math");
        subjects.push_back("Biology");
        subjects.push_back("Geography");

        for (int i = 0; i < 3; i++) {
            base.addStudent(students[i]);
            base.addSubject(subjects[i]);
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                base.addNewRecord(students[i], subjects[j], Mark::A);
                records.push_back(Record(students[i], subjects[j], Mark::A));
            }
        }
    }
    MarkDatabase base;
    std::vector<Student> students;
    std::vector<Subject> subjects;
    std::vector<Record> records;
};

TEST_F(MarkDatabaseTest, Can_Create) {
    // Arrange
    MarkDatabase* basePtr;

    // Act
    basePtr = new MarkDatabase;

    // Assert
    EXPECT_NE(nullptr, basePtr);

    delete basePtr;
}

TEST_F(MarkDatabaseTest, Can_Add_Not_Exist_Student) {
    // Arrange
    Student student = "Brian Butler";

    // Act
    base.addStudent(student);

    // Assert
    EXPECT_EQ(MarkDatabase::ReturnCode::Success,
              base.searchStudent(student));
}

TEST_F(MarkDatabaseTest, Can_Not_Add_Exist_Student) {
    // Arrange
    Student student = students[0];

    // Act & Assert
    EXPECT_EQ(MarkDatabase::ReturnCode::StudentAlreadyExist,
              base.addStudent(student));
}

TEST_F(MarkDatabaseTest, Can_Delete_Exist_Student) {
    // Arrange
    Student student = students[0];

    // Act
    base.deleteStudent(student);

    // Assert
    EXPECT_EQ(MarkDatabase::ReturnCode::StudentNotFound,
              base.searchStudent(student));
}

TEST_F(MarkDatabaseTest, Can_Not_Delete_Not_Exist_Student) {
    // Arrange
    Student student = "Brian Butler";

    // Act & Assert
    EXPECT_EQ(MarkDatabase::ReturnCode::StudentNotFound,
              base.deleteStudent(student));
}

TEST_F(MarkDatabaseTest, Can_Count_Students) {
    // Act & Assert
    EXPECT_EQ(students.size(), base.numberOfStudents());
}

TEST_F(MarkDatabaseTest, Can_Add_Not_Exist_Subject) {
    // Arrange
    Subject subject = "Psychology";

    // Act
    base.addSubject(subject);

    // Assert
    EXPECT_EQ(MarkDatabase::ReturnCode::Success,
              base.searchSubject(subject));
}

TEST_F(MarkDatabaseTest, Can_Not_Add_Exist_Subject) {
    // Arrange
    Subject subject = subjects[0];

    // Act & Assert
    EXPECT_EQ(MarkDatabase::ReturnCode::SubjectAlreadyExist,
              base.addSubject(subject));
}

TEST_F(MarkDatabaseTest, Can_Delete_Exist_Subject) {
    // Arrange
    Subject subject = subjects[0];

    // Act
    base.deleteSubject(subject);

    // Assert
    EXPECT_EQ(MarkDatabase::ReturnCode::SubjectNotFound,
              base.searchSubject(subject));
}

TEST_F(MarkDatabaseTest, Can_Not_Delete_Not_Exist_Subject) {
    // Arrange
    Subject subject = "Psychology";

    // Act & Assert
    EXPECT_EQ(MarkDatabase::ReturnCode::SubjectNotFound,
              base.deleteSubject(subject));
}

TEST_F(MarkDatabaseTest, Can_Count_Subjects) {
    // Act & Assert
    EXPECT_EQ(subjects.size(), base.numberOfSubjects());
}

TEST_F(MarkDatabaseTest, Can_Not_Add_Record_With_Not_Exist_Student) {
    // Arrange
    Student student = "Brian Butler";
    Subject subject = subjects[0];
    Mark mark = Mark::A;

    // Act & Assert
    EXPECT_EQ(MarkDatabase::ReturnCode::StudentNotFound,
              base.addNewRecord(student, subject, mark));
}

TEST_F(MarkDatabaseTest, Can_Not_Add_Record_With_Not_Exist_Subject) {
    // Arrange
    Student student = students[0];
    Subject subject = "Psychology";
    Mark mark = Mark::A;

    // Act & Assert
    EXPECT_EQ(MarkDatabase::ReturnCode::SubjectNotFound,
              base.addNewRecord(student, subject, mark));
}

TEST_F(MarkDatabaseTest, Can_Not_Add_Exist_Record) {
    // Arrange
    Student student = students[0];
    Subject subject = subjects[0];
    Mark mark = Mark::A;

    // Act & Assert
    EXPECT_EQ(MarkDatabase::ReturnCode::RecordAlreadyExist,
              base.addNewRecord(student, subject, mark));
}

TEST_F(MarkDatabaseTest, Can_Add_Not_Exist_Record) {
    // Arrange
    Student student = "Brian Butler";
    Subject subject = "Psychology";
    Mark mark = Mark::A;

    base.addStudent(student);
    base.addSubject(subject);

    // Act
    base.addNewRecord(student, subject, mark);

    // Assert
    size_t index;
    EXPECT_NE(MarkDatabase::ReturnCode::RecordNotFound,
              base.search(student, subject, &index));
}

TEST_F(MarkDatabaseTest, Can_Delete_Exist_Record) {
    // Arrange
    Student student = students[0];
    Subject subject = subjects[0];

    // Act
    base.deleteRecord(student, subject);

    // Assert
    size_t index;
    EXPECT_EQ(MarkDatabase::ReturnCode::RecordNotFound,
              base.search(student, subject, &index));
}

TEST_F(MarkDatabaseTest, Can_Not_Delete_Not_Exist_Record) {
    // Arrange
    Student student = "Brian Butler";
    Subject subject = "Psychology";

    base.addStudent(student);
    base.addSubject(subject);

    // Act & Assert
    EXPECT_EQ(MarkDatabase::ReturnCode::RecordNotFound,
              base.deleteRecord(student, subject));
}

TEST_F(MarkDatabaseTest, Can_Count_Records) {
    // Act && Assert
    EXPECT_EQ(records.size(), base.numberOfRecords());
}

TEST_F(MarkDatabaseTest, Can_Search_Exist_Record) {
    // Arrange
    Student student = students[0];
    Subject subject = subjects[0];
    Mark mark = Mark::A;
    // Act
    size_t index;
    base.search(student, subject, &index);

    // Assert
    std::vector<Record> records = base.getRecordsList();
    Record record(student, subject, mark);
    EXPECT_EQ(true, records[index] == record);
}

TEST_F(MarkDatabaseTest, Can_Not_Search_Not_Exist_Record) {
    // Arrange
    Student student = "Brian Butler";
    Subject subject = "Psychology";

    base.addStudent(student);
    base.addSubject(subject);

    // Act & Assert
    size_t index;
    EXPECT_EQ(MarkDatabase::ReturnCode::RecordNotFound,
              base.search(student, subject, &index));
}

TEST_F(MarkDatabaseTest, Can_Get_Record_By_Index) {
    // Arrange
    Student student = students[0];
    Subject subject = subjects[0];
    Mark mark = Mark::A;

    // Act
    size_t index;
    base.search(student, subject, &index);
    Record record;
    base.getRecord(index, &record);

    // Assert
    EXPECT_EQ(true, record == Record(student, subject, mark));
}

TEST_F(MarkDatabaseTest, Can_Get_Record_By_Wrong_Index) {
    // Act && Assert
    int count = base.numberOfRecords();
    Record record;
    EXPECT_EQ(MarkDatabase::ReturnCode::WrongIndex,
              base.getRecord(count+1, &record));
}

TEST_F(MarkDatabaseTest, Can_Delete_Exist_Record_By_Index) {
    // Arrange
    Student student = students[0];
    Subject subject = subjects[0];

    // Act
    size_t index;
    base.search(student, subject, &index);
    base.deleteRecord(index);

    // Assert
    size_t tempIndex;
    EXPECT_EQ(MarkDatabase::ReturnCode::RecordNotFound,
              base.search(student, subject, &tempIndex));
}

TEST_F(MarkDatabaseTest, Can_Delete_Not_Exist_Record_By_Index) {
    // Act && Assert
    int count = base.numberOfRecords();
    EXPECT_EQ(MarkDatabase::ReturnCode::WrongIndex,
              base.deleteRecord(count+1));
}

TEST_F(MarkDatabaseTest, Can_Not_Get_Marks_Of_Not_Exist_Student) {
    // Arrange
    Student student = "Brian Butler";

    // Act & Assert
    std::vector< std::pair<Subject, Mark> > marks;
    EXPECT_EQ(MarkDatabase::ReturnCode::StudentNotFound,
              base.marksOfStudent(student, &marks));
}

TEST_F(MarkDatabaseTest, Can_Get_Marks_Of_Exist_Student) {
    // Arrange
    Student student = students[0];
    Mark mark = Mark::A;
    // Act
    std::vector< std::pair<Subject, Mark> > marks;
    base.marksOfStudent(student, &marks);

    // Assert
    size_t numberOfCoincidences = 0;
    for (size_t i = 0; i < subjects.size(); i++) {
        for (size_t j = 0; j < marks.size(); j++) {
            if (marks[j].first == subjects[i] && marks[j].second == mark) {
                numberOfCoincidences++;
            }
        }
    }

    EXPECT_EQ(true, subjects.size() == numberOfCoincidences);
    EXPECT_EQ(true, subjects.size() == marks.size());
}

TEST_F(MarkDatabaseTest, Can_Not_Get_Marks_On_Not_Exist_Subject) {
    // Arrange
    Subject subject = "Psychology";

    // Act & Assert
    std::vector< std::pair<Student, Mark> > marks;
    EXPECT_EQ(MarkDatabase::ReturnCode::SubjectNotFound,
              base.marksOnSubject(subject, &marks));
}

TEST_F(MarkDatabaseTest, Can_Get_Marks_On_Exist_Subject) {
    // Arrange
    Subject subject = subjects[0];
    Mark mark = Mark::A;

    // Act
    std::vector< std::pair<Student, Mark> > marks;
    base.marksOnSubject(subject, &marks);

    // Assert
    size_t numberOfCoincidences = 0;
    for (size_t i = 0; i < students.size(); i++)
        for (size_t j = 0; j < marks.size(); j++) {
            if (marks[j].first == students[i] && marks[j].second == mark) {
                numberOfCoincidences++;
            }
        }

    EXPECT_EQ(true, numberOfCoincidences == students.size());
    EXPECT_EQ(true, marks.size() == students.size());
}

TEST_F(MarkDatabaseTest, Can_Get_Students_List) {
    // Act
    std::vector<Student> getStudents = base.getStudentsList();

    // Assert
    EXPECT_EQ(true, getStudents == students);
}

TEST_F(MarkDatabaseTest, Can_Get_Subjects_List) {
    // Act
    std::vector<Student> getSubjects = base.getSubjectsList();

    // Assert
    EXPECT_EQ(true, getSubjects == subjects);
}

TEST_F(MarkDatabaseTest, Can_Get_Record_List) {
    // Act
    std::vector<Record> getRecords = base.getRecordsList();

    // Assert
    EXPECT_EQ(true, records == getRecords);
}
