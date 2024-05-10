#include <iostream>
#include <vector>
#include <algorithm>

/*
You work as an analyst in a company that sells electronics. You are provided 
with monthly sales of products for a year in the form of a vector, where each 
element of the vector represents the sales amount for a month. Your task is 
to analyze the data and perform the following operations:

Find the total sales volume for the year.
Determine the month with the maximum sales volume. If there are multiple months 
with the maximum sales, output the first one.
Calculate the average monthly sales.
Determine whether the sales in each month exceed the average monthly sales. 
For each month, output true or false accordingly.
Find the number of months with sales below the average.

Input Data
Vector std::vector<int> sales = {12000, 15000, 13000, 19000, 17000, 16000, 
                                 18000, 21000, 20000, 17000, 22000, 19000};, 
where each element represents the sales amount for a month.

Tasks to Implement
Implement a function to calculate the total sales volume for the year.
Implement a function to find the month with the maximum sales volume.
Calculate the average monthly sales.
Determine whether the sales in each month exceed the average monthly sales, 
and output the corresponding true or false values.
Find the number of months with sales below the average.

Total sales volume for the year: 204000
Month with maximum sales volume: 11
Average monthly sales: 17000
Sales above average: false false false true true false true true true true true true
Number of months with sales below average: 3
*/

int main() {
  std::vector<int> sales = {12000, 15000, 13000, 19000, 17000, 16000, 
                            18000, 21000, 20000, 17000, 22000, 19000};
  
  int totalSales = 0;
  for (int sale : sales) {
    totalSales += sale;
  }
  std::cout << "Total sales volume for the year: " << totalSales << std::endl;
  
  int maxSales = *std::max_element(sales.begin(), sales.end());
  int maxSalesMonth = 1;
  for (int i = 0; i < sales.size(); ++i) {
    if (sales[i] == maxSales) {
      maxSalesMonth = i + 1;
      break;
    }
  }
  std::cout << "Month with maximum sales volume: " << maxSalesMonth << std::endl;
  
  double averageMonthlySales = static_cast<double>(totalSales) / sales.size();
  std::cout << "Average monthly sales: " << averageMonthlySales << std::endl;
  
  std::cout << "Sales above average: ";
  for (int sale : sales) {
    std::cout << (sale > averageMonthlySales ? "true " : "false ");
  }
  std::cout << std::endl;
  
  int monthsBelowAverage = 0;
  for (int sale : sales) {
    if (sale < averageMonthlySales) {
      ++monthsBelowAverage;
    }
  }
  std::cout << "Number of months with sales below average: " << monthsBelowAverage << std::endl;
  
  return 0;
}