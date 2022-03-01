
#include "mccarthys_vector_ops.hpp"

int main(void){

	std::vector<float> test1(10, 0);
	std::vector<float> test2(10, 1);
	
	std::cout << "hello\n";

	//vector_opsS::vector_opsC myclass;
	

	for(int i = 0; i < 10; i++){
		test1.at(i) = i;
	}
	
	std::vector<float> sub(10, 0);
	vector_opsS::vector_opsC::getSubtraction(test1, test2, sub);
	//myclass.getSubtraction(test1, test2, sub);

	std::cout << "subtract: \n";
	 for(int i = 0; i < 10; i++){
		 std::cout <<  sub.at(i) << "\n";
        }

	std::vector<float> div(10, 0);
        vector_opsS::vector_opsC::divideBy(test1, 2.0, div);
	//myclass.divideBy(test1, 2.0, div);

        std::cout << "divide by 2: \n";
         for(int i = 0; i < 10; i++){
                 std::cout <<  div.at(i) << "\n";
        }


	

	return 0;
}
