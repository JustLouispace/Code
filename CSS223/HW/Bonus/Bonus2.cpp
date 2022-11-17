#include <iostream>
#include <cstdlib>
#include <math.h>
#include <time.h>

using namespace std;

struct students
{
    string name;
    int score;
} student[10];

string FindMax(students student[10])
{
    string maxname = student[0].name;
    int maxscore = student[0].score;
    for (int i = 0; i < 10; i++)
    {
        if (student[i].score > maxscore)
        {
            maxscore = student[i].score;
            maxname = student[i].name;
        }
    }
    return maxname;
}

string FindMin(students student[10])
{
    string minname = student[0].name;
    int minscore = student[0].score;
    for (int i = 0; i < 10; i++)
    {
        if (student[i].score < minscore)
        {
            minscore = student[i].score;
            minname = student[i].name;
        }
    }
    return minname;
}

int AverageScore(students student[10])
{
    string avrname = student[0].name;
    int avrscore = student[0].score;
    int sum = 0;
    float avrScore = 0.0;
    for (int i = 0; i < 10; i++)
        sum += student[i].score;
    avrScore = sum / 10;
    return avrScore;
}

int ModeScore(students student[10])
{
    string modename = student[0].name;
    int modescore = student[0].score;
    int counter = 1;
    int max = 0;
    int mode = student[0].score;
    for (int i = 0; i < 10; i++)
    {
        if (student[i].score == student[i + 1].score)
        {
            counter++;
            if (counter > max)
            {
                max = counter;
                mode = student[i].score;
            }
        }
        else
            counter = 1;
    }
    return mode;
}

float MedianScore(students student[10])
{
    string medname = student[0].name;
    int medscore = student[0].score;
    int median = (student[4].score + student[5].score) / 2;
    return median;
}

float SDScore(students student[10])
{
    float sumSD = 0.0;
    string sdname = student[0].name;
    int sdscore = student[0].score;
    float sum = 0.0;
    float avrScore = 0.0;
    for (int i = 0; i < 10; i++)
    {
        sum += student[i].score;
    }
    avrScore = sum / 10;
    for (int i = 0; i < 10; i++)
    {
        sumSD += pow(student[i].score - avrScore, 2);
    }
    return sqrt(sumSD / 10);
}

string FindGradeA(students student[10])
{
    string GAname = student[0].name;
    int GAscore = student[0].score;
    float GradeA = AverageScore(student) + 2 * SDScore(student);
    string studentA = "";
    for (int i = 0; i < 10; i++)
    {
        if (student[i].score >= GradeA)
        {
            studentA += student[i].name + " ";
        }
    }
    if (studentA == "")
        studentA = "None";
    return studentA;
}

string FindGradeB(students student[10])
{
    string GBname = student[0].name;
    int GBscore = student[0].score;
    float GradeA = AverageScore(student) + 2 * SDScore(student);
    float GradeB = AverageScore(student) + SDScore(student);
    string studentB = "";
    for (int i = 0; i < 10; i++)
    {
        if ((student[i].score >= GradeB) && (student[i].score < GradeA))
        {
            studentB += student[i].name + " ";
        }
    }
    if (studentB == "")
        studentB = "None";
    return studentB;
}
string FindGradeC(students student[10])
{
    string GCname = student[0].name;
    int GCscore = student[0].score;
    float GradeB = AverageScore(student) + SDScore(student);
    float GradeC = AverageScore(student);
    string studentC = "";
    for (int i = 0; i < 10; i++)
    {
        if ((student[i].score >= GradeC) && (student[i].score < GradeB))
        {
            studentC += student[i].name + " ";
        }
    }
    if (studentC == "")
        studentC = "None";
    return studentC;
}
string FindGradeD(students student[10])
{
    string GDname = student[0].name;
    int GDscore = student[0].score;
    float GradeC = AverageScore(student);
    float GradeD = AverageScore(student) - SDScore(student);
    string studentD = "";
    for (int i = 0; i < 10; i++)
    {
        if ((student[i].score >= GradeD) && (student[i].score < GradeC))
        {
            studentD += student[i].name + " ";
        }
    }
    if (studentD == "")
        studentD = "None";
    return studentD;
}
string FindGradeF(students student[10])
{
    string GFname = student[0].name;
    int GFscore = student[0].score;
    float GradeD = AverageScore(student) - SDScore(student);
    string studentF = "";
    for (int i = 0; i < 10; i++)
    {
        if (student[i].score < GradeD)
        {
            studentF += student[i].name + " ";
        }
    }
    if (studentF == "")
        studentF = "None";
    return studentF;
}
int main()
{
    srand(time(NULL));
    string name[10] = {"Pumipat", "Awirut", "Chaninat", "Kollawat", "Pakawat", "Kantapon", "Sirawit", "Siraphat", "Thanyapisit", "Punnapa"};
    int score[10] = {1 + (rand() % 100), 1 + (rand() % 100), 1 + (rand() % 100), 1 + (rand() % 100), 1 + (rand() % 100), 1 + (rand() % 100), 1 + (rand() % 100), 1 + (rand() % 100), 1 + (rand() % 100), 1 + (rand() % 100)};
    // Sorting
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10 - i - 1; j++)
        {
            if (score[j] > score[j + 1])
            {
                int temp = score[j];
                score[j] = score[j + 1];
                score[j + 1] = temp;
                string tempname = name[j];
                name[j] = name[j + 1];
                name[j + 1] = tempname;
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        student[i].name = name[i];
        student[i].score = score[i];
        // cout << student[i].name << " " << student[i].score << endl;
    }
    if (ModeScore(student) == student[0].score)
    {
        cout << "Maximum: " << FindMax(student) << endl;
        cout << "Minimum: " << FindMin(student) << endl;
        cout << "Average: " << AverageScore(student) << endl;
        cout << "Mode: " << "None" << endl;
        cout << "Median: " << MedianScore(student) << endl;
        cout << "SDScore: " << SDScore(student) << endl;
        cout << "Student Grade A: " << FindGradeA(student) << endl;
        cout << "Student Grade B: " << FindGradeB(student) << endl;
        cout << "Student Grade C: " << FindGradeC(student) << endl;
        cout << "Student Grade D: " << FindGradeD(student) << endl;
        cout << "Student Grade F: " << FindGradeF(student) << endl;
    }
    else
    {
        cout << "Maximum: " << FindMax(student) << endl;
        cout << "Minimum: " << FindMin(student) << endl;
        cout << "Average: " << AverageScore(student) << endl;
        cout << "Mode: " << ModeScore(student) << endl;
        cout << "Median: " << MedianScore(student) << endl;
        cout << "SDScore: " << SDScore(student) << endl;
        cout << "Student Grade A: " << FindGradeA(student) << endl;
        cout << "Student Grade B: " << FindGradeB(student) << endl;
        cout << "Student Grade C: " << FindGradeC(student) << endl;
        cout << "Student Grade D: " << FindGradeD(student) << endl;
        cout << "Student Grade F: " << FindGradeF(student) << endl;
    }
}
