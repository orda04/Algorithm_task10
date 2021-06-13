/*
**********  10th task on  Algorithm course                                   ****
**********  Filename >main.cpp                                               ****
**********  IDE > QT Creator 4.13.2||CodeBlocks 20.03 + GCC 10.2.0           ****
**********  Created by > "~ORDA~" , Anton Bondarenko                         ****
**********  Date           28.05.2021                                        ****
**********  Modified date  30.05.2021 and 10.06.2021                         ****
*/

//

#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

struct stack
{
        char *bkt = new char;
        int cur;
        stack()
        {
            cur = 0;
        }
        void push(char x)
           {
            bkt[cur++] = x;
           }
        void pop()
           {
            cur--;
           }
        char back()
           {
            return bkt[cur-1];
           }
        int size(){
            return cur;
        }
};

int main()
{
    string brace;
    cin >> brace;
    stack x;
    if(brace[0] == '(' || brace[0] == '{' || brace[0] == '[') x.push(brace[0]); //Correct string in our variant should start only from these symbols/braces
    else
       {
        if(brace == "") cout << "YES";//if no symbol it is OK too
        else cout << "NO";
        return 0;
       }
    for(int i = 1; i < brace.length(); i++)
       {
           if(brace[i] == '(' || brace[i] == '{' || brace[i] == '[') //if starts side - adding into stack
              {
                x.push(brace[i]);
              }
        else if(abs(brace[i] - x.back()) < 3 && x.size() != 0)
             {
               x.pop();
             }
        else
             {
              cout << "NO";
              return 0;
             }
       }
    if(x.size() == 0) cout << "YES";//if get 0 in the end - that means our string is correct
    else cout << "NO";
    return 0;
}
