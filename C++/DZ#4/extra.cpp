#include <cstdio>
#include <iostream>
#include <cstring>
#include "Student.hpp"
#include "extra.hpp"

Student *fill_students(FILE *fp) {
    Student *array = new Student[ARRAY_SIZE];
    char *name = new char[255];
    char *patronymic = new char[255];
    char *surname = new char[255];
    int birthdate = 0;
    char *telephone = new char[255];
    char *adress = new char[255];
    char *faculty = new char[255];
    int course;
    int i = 0;
    while (fscanf(fp, "%s %s %s %d %s %s %s %d", name, patronymic, surname, &birthdate, telephone, adress,
                  faculty, &course) == 8) {
        if (i > ARRAY_SIZE) {
            break;
        }
        Student *st = new Student(
                name,
                patronymic,
                surname,
                birthdate,
                adress,
                telephone,
                faculty,
                course
        );
        array[i] = *st;
        i++;
    }
    return array;
}

void filter_by_faculty(Student *array, char *faculty) {
    cout << "Filtered by Faculty " << faculty << ":" << endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        Student that = array[i];
        if (strcmp(array[i].get_faculty(), faculty) == 0) {
            that.show();
        }
    }
}

//int cmp(const void *ptr1, const void *ptr2) {
//    Student *st1 = *(Student **) ptr1;
//    Student *st2 = *(Student **) ptr2;
//    return strcmp(st1->get_faculty(), st2->get_faculty()) + (st1->get_course() < st2->get_course()) ? st2->get_course()
//                                                                                                    : st1->get_course();
//}

void filter_by_year(Student *array, int year) {
    cout << "Filtered by Year " << year << ":" << endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        Student that = array[i];
        if (that.get_birthdate() > year) {
            that.show();
            cout << endl;
        }
    }
}

void show_sorted(Student *array) {}