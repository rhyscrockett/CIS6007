
template<typename T>
class Multiplier {

private:
  T value;

public:
  Multiplier(T _val) : value(_val) {}
  T operator() (T item) {
    return item * value;
  }
};
