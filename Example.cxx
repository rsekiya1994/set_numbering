#include "set_numbering.h"
#include <iostream>
#include <string>

int main(){
  sky::set_numbering<int, std::string> A;
  A.Add(1, "a");
  A.Add(2, "a");
  A.Add(3, "b");
  std::cout << "(1, \"a\") : " << A.Index(1, "a") << std::endl;
  std::cout << "(2, \"a\") : " << A.Index(2, "a") << std::endl;
  std::cout << "(1, \"b\") : " << A.Index(1, "b") << std::endl;
  for(int i = 0 ; i < 3 ; i++){
    std::cout << A.GetArg<0>(i)	<< std::endl;
  }
  return 0;
}

// -- 出力
// (1, "a") : 0
// (2, "a") : 1
// (1, "b") : -1
// 1
// 2
// 3
