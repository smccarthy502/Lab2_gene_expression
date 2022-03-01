/* author: Sarah McCarthy 
 * created March 9, 2021
 *
 * header file for calculating stats
 * implemented in mccarthy_stats.cpp
 */


#ifndef STATS
#define STATS

#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>

namespace statsS{
class statsC {
        public:

                //returns the max value of the data
                static float max(std::vector<float> data);

                //returns the min value of the data
                static float min(std::vector<float> data);

                //returns the mean of the data
                static float mean(std::vector<float> data);

                //returns the standard deviation of the data
                static float stdDeviation(std::vector<float> data);

                //returns the histogram of the data
                static void histogram(std::vector<float> data);

};
}
#endif


