#ifndef DZ_4_STUDENT_HPP
#define DZ_4_STUDENT_HPP

using namespace std;

class Student {
public:
    Student(char *name = nullptr,
            char *patronymic = nullptr,
            char *surname = nullptr,
            int birthdate = 0,
            char *adress = nullptr,
            char *telephone = nullptr,
            char *faculty = nullptr,
            int course = 0
    );

    Student(const Student &rhs);

    ~Student();

    Student &operator=(const Student &rhs);

    void show();

    char *get_faculty() const;

    char *get_name() const;

    char *get_patronymic() const;

    char *get_surname() const;

    int get_birthdate() const;

    char *get_adress();

    char *get_telephone() const;

    int get_course() const;

private:
    char *name;
    char *patronymic;
    char *surname;
    int birthdate;
    char *adress;
    char *telephone;
    char *faculty;
    int course;
};


#endif //DZ_4_STUDENT_HPP
