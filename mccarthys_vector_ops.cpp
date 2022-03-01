
#include "mccarthys_vector_ops.hpp"



//vector_opsS::vector_opsC::vector_opsC(){}

float vector_opsS::vector_opsC::getSum(std::vector<float> &data){
	float sum = 0;

	for(int i = 0; i < data.size(); i++){
		sum += data.at(i);
	}

	return sum;
}

void vector_opsS::vector_opsC::getSubtraction(std::vector<float> &data1, std::vector<float> &data2, std::vector<float> &outdata){

	for(int i = 0; i < data1.size(); i++){
		outdata.at(i) = data1.at(i) - data2.at(i);
		//std::cout << outdata.at(i) << "\n";
	}

	return;
}

void vector_opsS::vector_opsC::divideBy(std::vector<float> &data, float divisor, std::vector<float> &outdata){

	for(int i = 0; i < data.size(); i++){
		outdata.at(i) = data.at(i) / divisor;
	}
	
	return;
}

