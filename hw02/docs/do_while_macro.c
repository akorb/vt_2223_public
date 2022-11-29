
#define CALL_FUNCS(x) \
{ \
  func1(x); \
  func2(x); \
  func3(x); \
}

#define CALL_FUNCS(x) \
do { \
  func1(x); \
  func2(x); \
  func3(x); \
} while (0)



if (<condition>)
    CALL_FUNCS(a);
else
    bar(a);
