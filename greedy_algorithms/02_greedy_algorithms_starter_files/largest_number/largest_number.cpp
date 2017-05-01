#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool IsGreaterOrEqual(std::string digit,std::string maxdigit){
	for(size_t i =0;i<std::min(digit.size(),maxdigit.size());i++){
		if(digit.substr(i,1).compare(maxdigit.substr(i,1))>0)
			return true;
	}
	if(digit.size()<maxdigit.size())
		return true;
	else
		return false;

}

string largest_number(vector<string> a) {
  vector<string> b;
  while(a.size()){
	  std::string maxdigit=a[0];
	  size_t j = 0;
	  for(size_t i =1; i<a.size();i++){
		  if(IsGreaterOrEqual(a[i],maxdigit)){
			  maxdigit = a[i];
			  j = i;
		  }
	  }
	  b.push_back(maxdigit);
	  a.erase(a.begin()+j);
  }




  std::stringstream ret;
  for (size_t i = 0; i < b.size(); i++) {
    ret << b[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
