#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  ifstream source;
  ofstream target;
  source.open("example.txt", ios::in);
  target.open("result.txt", ios::out);
  string s;
  char c;
  while((c = source.get()) != EOF) {
    s += c;
  }
  int pos = 0;
  int len = s.length();
  int start = 0;
  int end = 0;
  bool is_tag = false;
  for (int i = 0; i < len; ++i) {
    if(s[i] == '<') {
      end = i;
      is_tag = true;
      int j, k;
      for (j = start, k = start; j < end; ++j, ++k) {
        if(s[j] != '\n' && s[j] != '\r' && s[j] != ' ') {
          if((isdigit(s[j]) && !isdigit(s[j - 1])) && (s[j + 1] == '.'||s[j + 2] == '.')) {target << endl;}
          target << s[j];
          --k;
        }
      }
      if(k != end) {target << endl;}
    }
    if(s[i] == '>') {
      start = i + 1;
      is_tag = false;
      continue;
    }
  }
  source.close();
  target.close();
  return 0;   
}
