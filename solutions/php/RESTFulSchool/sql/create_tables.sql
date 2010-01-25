CREATE TABLE Subjects(
    subjectID INTEGER NOT NULL,
    subjectName VARCHAR(64),
    subjectTeacher VARCHAR(128),
    PRIMARY KEY(subjectID)
);

CREATE TABLE Students(
    studentID INTEGER NOT NULL,
    studentName VARCHAR(128),
    studentAge INTEGER,
    studentAddress VARCHAR(128),
    PRIMARY KEY(studentID)
);

CREATE TABLE Marks(
    subjectId INTEGER,
    studentID INTEGER,
    marks INTEGER,
    PRIMARY KEY(studentID,subjectId)
);
