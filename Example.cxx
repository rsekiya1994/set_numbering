#include "set_numbering.h"
#include <iostream>
#include <string>

int main(){
  sky::set_numbering<int, std::string> A;
  A.add(1, "a"); // 要素を加えていく。
  A.add(2, "a");
  A.add( {3, "b"} ); //初期化子リストでも可
  std::cout << "(1, \"a\") : " << A.index(1, "a") << std::endl; // {1, "a"}のindexを取得
  std::cout << "(2, \"a\") : " << A.index(2, "a") << std::endl; // {2, "a"}のindexを取得
  std::cout << "(1, \"b\") : " << A.index( {1, "b"} ) << std::endl; // 初期化子リストでも検索可。{1, "b"}はaddされてないので -1 が返る。
  for(int i = 0 ; i < 3 ; i++){
    // indexから集合の要素を取得
    std::cout << A.get_arg<0>(i) << " " << A.get_arg<1>(i) << std::endl;
  }
  return 0;
}

// -- 出力
// (1, "a") : 0
// (2, "a") : 1
// (1, "b") : -1
// 1 a
// 2 a
// 3 b
