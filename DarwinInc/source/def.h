#pragma once

#define QUOTEME(x) #x
#define TOSTRING(x) QUOTEME(x)

#define __FILELINE__ __FILE__ ":" TOSTRING(__LINE__)

#define assert_msg(expression, message) IwAssertMsg(MYAPP, (expression), (message __FILELINE__));
#define assert(expression) assert_msg(expression, TOSTRING(expression))

template<typename T>
struct shared
{
  void Add()
  {
    users++;
  }
  void Remove()
  {
    users--;
    if (!users)
      delete this;
  }
  T *data = nullptr;
private:
  int users = 1;

  ~shared()
  {
    if (data)
      delete data;
  }
};