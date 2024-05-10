#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>
/*
Imagine you are conducting a survey among the residents of a city on the topic
of "Your favorite season". The answers are collected in the form of a string, 
where each letter represents the respondent's choice:

W for winter,
S for spring,
U for summer, and
A for autumn.
Your task is to analyze the survey results using an std::vector<char> container 
to store the responses and STL algorithms to process them.

Tasks to Implement:
- Fill the std::vector<char> responses with the survey results.
- Use std::accumulate to count the total number of responses.
- Find the most popular season using a combination of std::count_if and 
  comparing the results.
- Use std::find_if to find the first response that chose summer (U).
Output the obtained results: the total number of responses, the most and least 
popular seasons, and the position of the first response choosing summer.
*/

int main() {
  std::vector<char> responses = {'W', 'S', 'U', 'A', 'W', 'S', 'U',
                                 'A', 'S', 'U', 'A', 'W', 'S', 'U', 'A', 'W'};

  int totalResponses = std::accumulate(responses.begin(), responses.end(), 0);

  std::cout << "Total number of responses: " << totalResponses << std::endl;

  std::map<char, int> seasonCounts;
  for (char response : responses) {
    ++seasonCounts[response];
  }

  char mostPopularSeason = ' ';
  int maxCount = 0;
  for (const auto& pair : seasonCounts) {
    if (pair.second > maxCount) {
      maxCount = pair.second;
      mostPopularSeason = pair.first;
    }
  }

  std::cout << "Most popular season: " << mostPopularSeason << std::endl;

  char leastPopularSeason = ' ';
  int minCount = totalResponses;
  for (const auto& pair : seasonCounts) {
    if (pair.second < minCount) {
      minCount = pair.second;
      leastPopularSeason = pair.first;
    }
  }

  std::cout << "Least popular season: " << leastPopularSeason << std::endl;

  auto summerResponseIter = std::find_if(responses.begin(), responses.end(),
                                         [](char response) { return response == 'U'; });

  int summerResponsePosition = std::distance(responses.begin(), summerResponseIter) + 1;

  std::cout << "Position of the first response choosing summer: " << summerResponsePosition << std::endl;

  return 0;
}