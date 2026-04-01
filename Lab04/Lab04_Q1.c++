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

// 改成回傳 Student
Student updateMath(Student s) { 
 s.math = 100;  
 return s;   // 把修改後的資料回傳
} 

void printStudent(Student s) { 
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

 // 接住回傳值！
 one = updateMath(one);

 printStudent(one);  

 return 0; 
}
