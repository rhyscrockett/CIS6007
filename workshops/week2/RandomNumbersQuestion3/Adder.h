
template<typename T>
class Adder
{
 private:
  T value;

 public:
 Adder(T _val) : value(_val) {}
  T operator() (T item) {
    return item + value;
  }
};
