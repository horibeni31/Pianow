#ifndef EXERCISE_RESULT_H
#define EXERCISE_RESULT_H
#include <nlohmann/detail/macro_scope.hpp>
#include <nlohmann/json.hpp>
#include <utility>
#include "note.h"
using json = nlohmann::json;
struct ExerciseResult
{
    std::vector<Note> goals;
    std::vector<std::pair<int, int>> tries; 
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(ExerciseResult, goals,tries );

#endif
