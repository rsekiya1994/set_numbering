#ifndef _set_numbering_
#define _set_numbering_

#include <tuple>
#include <map>
#include <vector>
#include <iostream>

template <class ...Args>
struct TupleStr{
  TupleStr(Args... args){ values = std::make_tuple(args...); };
  std::tuple<Args...> values;
  bool operator < (const TupleStr<Args...> &rhs) const {
    return std::tie(values) < std::tie(rhs.values);
  }
};

namespace sky{
  template <class ...Args>
    class set_numbering{
  public:
    set_numbering(){ size = sizeof...(Args); };
    ~set_numbering(){};
    void Add(Args...);
    int Index(Args...);
    int Size(){
      return index;
    }
  
    template <std::size_t I>
      typename std::tuple_element<I, std::tuple<Args...> >::type& GetArg(const int index){
      return std::get<I>(vTupleStr[index].values);
    };
  
  private:
    int size;
    std::map<TupleStr<Args...>, int> count_index;
    std::vector<TupleStr<Args...> > vTupleStr;
    int index = 0;
  };

}

template <class... Args>
void sky::set_numbering<Args...>::Add(Args... args){
  TupleStr<Args...> t(args...);
  auto it = count_index.find( t );
  if(it != count_index.end() ){
    std::cout << "Already Constructed" << std::endl;
    return;
  }else{
    count_index[t] = index++;
    vTupleStr.push_back(t);
  }
}

template <class... Args>
int sky::set_numbering<Args...>::Index(Args... args){
  TupleStr<Args...> t(args...);
  auto it = count_index.find(t);
  if(it != count_index.end()){
    return it -> second;
  }else{
    return -1;
  }
}

#endif
