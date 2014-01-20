#if ! defined ( STRINGEXT_H_ )
#define STRINGEXT_H_

#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<string> &split(const string &s, char delim, vector<string> &elems);
vector<string> split(const string &s, char delim);
bool is_number(const string& s);

#endif // STRINGEXT_H_
