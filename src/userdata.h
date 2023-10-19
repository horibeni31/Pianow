#pragma once
#include <memory>
#include "exerciseresult.h"
class UserData
{
  public:

  void InsertResult(const ExerciseResult& res);
  
  public:
    static UserData& instance();

  private:
    UserData();
    static std::unique_ptr<UserData> _instance;
    void createDB();
};
