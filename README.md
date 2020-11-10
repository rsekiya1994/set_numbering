# set_numbering
多変数引数に対して自然数を割り振るクラス  
使い方はExample.cxxをみれば大体わかるはず。
複数の引数を与えて初めて値や出力が決まるようなデータを扱う時に便利。  

```c++:set_numbering
  namespace sky{  
    template<class... Args>  
    class set_numbering;  
  }
```

メンバ関数  
・add  
`void add(Args... args);`  
`void add(const std::tuple<Args...> &key);`  
・size  
`int size();`  
・index  
`int index(Args... args);`  
`int index(const std::tuple<Args...> &key);`  
・get_arg  
`template <std::size_t I>  
 typename std::tuple_element<I, std::tuple<Args...> >::type& get_arg(const int index);
`
