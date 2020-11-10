#ifndef _set_numbering_
#define _set_numbering_

#include <tuple>
#include <map>
#include <vector>
#include <iostream>

namespace sky{
  template <class ...Args>
  class set_numbering{
  public:
    set_numbering(){};
    ~set_numbering(){};
    void add(Args...args){
      auto it = set1.find( {args...} );
      if( it == set1.end() ){
	set1[ {args...} ] = id++;
	vtuple.push_back( {args...} );
      }else{
	std::cout << "error: already constructed." << std::endl;
      }
    }
    void add(const std::tuple<Args...> &key){
      auto it = set1.find( key );
      if( it == set1.end() ){
	set1[ key ] = id++;
	vtuple.push_back( key );
      }else{
	std::cout << "error: already constructed." << std::endl;
      }
    }
    int size(){
      return id;
    }
    int index(Args... args){
      auto it = set1.find( {args...} );
      if(it != set1.end()){
	return it -> second;
      }else{
	return -1;
      }
    }
    int index(const std::tuple<Args...> &rhs){
      auto it = set1.find( rhs );
      if( it != set1.end() ){
	return it -> second;
      }else{
	return -1;
      }
    }
    int operator [](const std::tuple<Args...> &arg){
      auto it = set1.find( arg );
      if( it != set1.end() ){
	return it -> second;
      }else{
	return -1;
      }
    }
    template <std::size_t I>
    typename std::tuple_element<I, std::tuple<Args...> >::type& get_arg(const int index){
      return std::get<I>( vtuple[index] );
    }
  private:
    std::map<std::tuple<Args...>, int> set1;
    std::vector<std::tuple<Args...> > vtuple;
    int id = 0;
  };
}
#endif
