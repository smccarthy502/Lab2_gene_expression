/* author: Sarah McCarthy 
 * created: March 2, 2021
 *
 * used for vector operations 
 * functions include summing all elements, subtracting one array from another element by element, and dividing all members of an array by a constant 
 */

#ifndef VECTOR_OPS
#define VECTOR_OPS

#include <vector>
#include <iostream>
#include <fstream>

namespace vector_opsS {
class vector_opsC {
	public:
		//constructor
		//vector_opsC();

		//returns sum of all elements
		static float getSum(std::vector<float> &data);

		//returns subtraction of two arrays
		static void getSubtraction(std::vector<float> &data1, std::vector<float> &data2, std::vector<float> &outdata);

		//returns array divided by constant
		static void divideBy(std::vector<float> &data, float divisor, std::vector<float> &outdata);

};
}


#endif
