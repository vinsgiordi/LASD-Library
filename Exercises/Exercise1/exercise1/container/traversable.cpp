
namespace lasd {

/* ************************************************************************** */

// Specific member function (TraversableContainer)
template <typename Data, typename Accumulator>
using FoldFun = typename TraversableContainer<Data>::template FoldFun<Accumulator>;

template <typename Data>
template <typename Accumulator>
inline Accumulator TraversableContainer<Data>::Fold(FoldFun<Accumulator> fun, Accumulator acc) const {
  Traverse(
    [fun, &acc](const Data & data) {
      acc = fun(data, acc);
    }
  );
  return acc;
}

template <typename Data>
inline bool TraversableContainer<Data>::Exists(const Data& data) const noexcept {
  bool exists = false;
  Traverse(
    [data, &exists](const Data & curr) {
      exists |= (data == curr);
    }
  );
  return exists;
}

/* ************************************************************************** */

// Specific member function (PreOrderTraversableContainer)
template <typename Data>
inline void PreOrderTraversableContainer<Data>::Traverse(TraverseFun fun) const {
  PreOrderTraverse(fun);
}

template <typename Data>
template <typename Accumulator>
inline Accumulator PreOrderTraversableContainer<Data>::PreOrderFold(FoldFun<Accumulator> fun, Accumulator acc) const {
  PreOrderTraverse(
    [fun, &acc](const Data & data) {
      acc = fun(data, acc);
    }
  );
  return acc;
}

/* ************************************************************************** */

// Specific member function (PostOrderTraversableContainer)
template <typename Data>
inline void PostOrderTraversableContainer<Data>::Traverse(TraverseFun fun) const {
  PostOrderTraverse(fun);
}

template <typename Data>
template <typename Accumulator>
inline Accumulator PostOrderTraversableContainer<Data>::PostOrderFold(FoldFun<Accumulator> fun, Accumulator acc) const {
  PostOrderTraverse(
    [&fun, &acc](const Data & data) {
      acc = fun(data, acc);
    }
  );
  return acc;
}

/* ************************************************************************** */

// Specific member function (InOrderTraversableContainer)

/* ************************************************************************** */

// Specific member function (BreadthTraversableContainer)

/* ************************************************************************** */

}
