# Const Correctness

## Functionality

Program introduces a fibonacci class to count the number series to a defined number with cache functionality of the previous iterations. It is bypassing const correctness on purpose to allow changes in the recursive calls.

> Const's can forced as following:

### Constant Function:

```c
long calc(long i) const {  // "calc" is a constant function
  // ...
}
```

### Constant Member Variables:

```c
private:
  const long start;  // "start" is a constant long
  const long cache_n;  // "cache_n" is a constant long
  const long cache_result;  // "cache_result" is a constant long

```

### Constant Constructor

```c
Fibonacci() const {  // Constructor is a constant function
  start = 1;
  cache_n = -1;
}
```
