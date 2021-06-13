
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

struct stack{
        char *bkt = new char;
        int cur;
        stack(){cur = 0;}
        void push(char x){
            bkt[cur++] = x;
        }
        void pop(){
            cur--;
        }
        char back(){
            return bkt[cur-1];
        }
        int size(){
            return cur;
        }
};

int main() {
    string brace;
    cin >> brace;
    stack x;
    if(brace[0] == '(' || brace[0] == '{' || brace[0] == '[') x.push(brace[0]); //Правильное выражение начинается только с открывающей скобки
    else{
        if(brace == "") cout << "YES";//Выражение без скобок также првильное
        else cout << "NO";
        return 0;
    }
    for(int i = 1; i < brace.length(); i++){
        if(brace[i] == '(' || brace[i] == '{' || brace[i] == '['){ //Любую открывающую скобку добавляем в стек
            x.push(brace[i]);
        }
        else if(abs(brace[i] - x.back()) < 3 && x.size() != 0){//Модуль разницы скобок одного типа меньше трех
            x.pop();
        }
        else{
            cout << "NO";
            return 0;
        }
    }
    if(x.size() == 0) cout << "YES";//Правильное арифметическое выражение получим при пустом стэке
    else cout << "NO";
    return 0;
}
