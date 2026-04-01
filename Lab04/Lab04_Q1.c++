#include <iostream> 
#include <string> 
using namespace std; 

struct Student {
 int id; 
 string name; 
 int chinese; 
 int english; 
 int math; 
 int social; 
 int science; 
}; 

//改成用指標傳遞值
void updateMath(Student *s) { 
 s->math = 100;   //用 -> 存取成員
} 

void printStudent(Student s) {   //輸出改變結果
 cout << "學生編號: " << s.id << endl; 
 cout << "姓名: " << s.name << endl; 
 cout << "數學成績: " << s.math << endl; 
} 

int main() { 
 Student one;

 one.id = 1; 
 one.name = "張小美"; 
 one.chinese = 77; 
 one.english = 83; 
 one.math = 86; 
 one.social = 68; 
 one.science = 91; 

 //傳位址
 updateMath(&one);

 printStudent(one);  

 return 0; 
}

