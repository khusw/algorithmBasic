/*
    보통은 기본 예제 처럼 정형화된 데이터가 들어오는 것이 아니라,
    객체의 형태로써 데이터가 들어오는 것이 일반적이다.
    객체의 데이터에서 이것을 어떻게 정렬 할 것인지가 관건인데,
    실제적으로 sort 함수를 쓸 때는 어떤식으로 사용되는지 파악해 본다.

    이 예제에서는 여러명의 학생 데이터가 들어올 때,
    학생을 점수별로 어떻게 구분하는지에 대한 예제를 보여준다.
*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Student
{
private:
    string name;
    int score;

public:
    Student(string name, int score)
    {
        this->name = name;
        this->score = score;
    }
    bool operator<(Student &student)
    {
        return this->score < student.score;
    }
    void printName()
    {
        cout << this->name << '\n';
    }
};

int main()
{
    Student students[] = {
        Student("kim", 100),
        Student("shin", 90),
        Student("min", 80),
        Student("park", 70),
        Student("lee", 50),
    };
    sort(students, students + 5);
    for (int i = 0; i < 5; i++)
    {
        students[i].printName();
    }
}