
#include "mccarthys_pre_processing.hpp"

void log_intensity(std::vector<float> &datas, std::vector<float> &datan, std::vector<float> &result){
	for(int i = 0; i < datas.size(); i++){
		result.at(i) = log10( (datas.at(i) / datan.at(i)) );
	}

	return;
}

int main(int argc, char* argv[]){
/*6 arguments to be passed 
 * 	datafile containing sporualting cells (red) 
 * 	datafile containing background red data
 * 	datafile containing nonsporulaing cells (green)
 * 	datafile containing background green data 
 * 	datafile to be written to
 * 	number of genes to be analyzed
 */
       if(argc != 7){
       	std::cout << "Expected 6 arguments. Program terminating.\n";
 	exit(EXIT_FAILURE);
       }

        float num;
	std::vector<float> red_cells;
	std::vector<float> red_back;
	std::vector<float> green_cells;
	std::vector<float> green_back;
	std::string filename;
	//for loop to add data from the 4 input data files into arrays 
	for(int i = 1; i <= 4; i ++){
		filename = argv[i];
		std::ifstream datafile(filename);

		if(datafile.is_open()){
			while(datafile >> num){
				if(i == 1)
					red_cells.push_back(num);
				else if(i == 2)
					red_back.push_back(num);
				else if(i == 3)
					green_cells.push_back(num);
				else if(i == 4)
					green_back.push_back(num);
				else{
					std::cout << "Something went wrong when reading from data files.\n";
					exit(EXIT_FAILURE);
				}
			}
			datafile.close();
		}
		else{
			std::cout << "Could not open file in argument " << i << ".\n";
			exit(EXIT_FAILURE);
		}
	}

	filename = argv[5];
	int num_genes = atoi(argv[6]);
	if((num_genes != red_cells.size()) || (num_genes != red_back.size()) || (num_genes != green_cells.size()) || (num_genes != green_back.size())){
		std::cout << "Number of genes do not match.\n";
		exit(EXIT_FAILURE);
	}

	//subtract corresponding background intensities from green and red datasets
	std::vector<float> corrected_red(num_genes, 0);
	vector_opsS::vector_opsC::getSubtraction(red_cells, red_back, corrected_red);

	std::vector<float> corrected_green(num_genes, 0);
	vector_opsS::vector_opsC::getSubtraction(green_cells, green_back, corrected_green);

	//get mean of corrected data sets
	float red_mean = statsS::statsC::mean(corrected_red);
	float green_mean = statsS::statsC::mean(corrected_green);

	//normalize data by the mean
	std::vector<float> normalized_red(num_genes, 0);
	vector_opsS::vector_opsC::divideBy(corrected_red, red_mean, normalized_red);

	std::vector<float> normalized_green(num_genes, 0);
        vector_opsS::vector_opsC::divideBy(corrected_green, green_mean, normalized_green);

	//calculate log intensity ratio
	std::vector<float> log_ratio(num_genes, 0);
	log_intensity(normalized_red, normalized_green, log_ratio);

	std::ofstream outfile;
	outfile.open(filename);
	for(int i = 0; i < log_ratio.size(); i++){
		outfile << log_ratio.at(i) << "\n";
	}
	outfile.close();

	return 0;
}
