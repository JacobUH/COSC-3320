// c12b8c31-5462-4efa-94b3-e71e3ff624ab

#include <iostream>
#include <string>
#include <stack>
using namespace std;

// PRIORITIES:
int priority(char c) {
  if (c == '/' || c == '*')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return 0;
}

string inToPost(string s) { 
  stack<char> st;
  string postfix;
 
  for (char c: s) {
    if (c == ' ')
      continue;

    else if (isdigit(c))
      postfix += c;
    else if (c == '(')
      st.push('(');
    else if (c == ')') {
      while (st.top() != '(') {
        postfix += st.top();
        st.pop();
      }
      st.pop();
    }
    else {
      while (!st.empty() && priority(c) <= priority(st.top())) {
          postfix += st.top();
          st.pop();
      }
      st.push(c);
    }
  }
  while (!st.empty()) {
    postfix += st.top();
    st.pop();
  }
  return postfix;
}

int eval(string s) {
  stack<int> st;

  for (char c: s){
    if (isdigit(c))
      st.push(c - '0');
    else {
      int val1 = st.top(); st.pop();
      int val2 = st.top(); st.pop();
      switch (c) {
        case '+': st.push(val2 + val1); break;
        case '-': st.push(val2 - val1); break;
        case '*': st.push(val2 * val1); break;
        case '/': st.push(val2 / val1); break;
      }
    }
  }
  return st.top();
}

int main() {
  string exp;
  getline(cin, exp);
  //cin >> exp;
  cout << eval(inToPost(exp));
}