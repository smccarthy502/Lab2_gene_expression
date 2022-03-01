
#include "mccarthys_k_means.hpp"

cluster::cluster(){}

std::string cluster::getname(){
	return this->cluster_name;
}

void cluster::setname(std::string sname){
	this->cluster_name = sname;
	return;
}

float cluster::getmean(){
	return this->cluster_mean;
}

void cluster::setmean(float smean){
	this->cluster_mean = smean;
	return;
}

float cluster::distance(float point){
	return std::abs(cluster_mean - point);
}

int main(void){

	//read in data file named log_ratio_input.dat
	float num;
	std::vector<float> data;
	std::ifstream infile("log_ratio_input.dat");
	
	//check if datafile exists
	//if is does, read in data
	if(infile.is_open()){
		while(infile >> num){
			data.push_back(num);
		}
		//infile.close();
	}
	//if file cannot be found, print error message and termiante data analysis 
	else{
		std::cout << "Could not open file. Data analysis termianting.\n";
		exit(EXIT_FAILURE);
	}

	//initialize 3 clusters: 
	//suppressed with mean -0.5
	//stationary with mean 0.0
	//expressed with mean 0.5
	cluster suppressed;
	suppressed.setname("suppressed");
	suppressed.setmean(-0.5);

	cluster stationary;
	stationary.setname("stationary");
	stationary.setmean(0.0);

	cluster expressed;
	expressed.setname("expressed");
	expressed.setmean(0.5);

	float sum_means = 100000;
	float dis_sup, dis_stat, dis_exp, sup_mean, stat_mean, exp_mean;
	while(sum_means > 0.0001){
		//clearing the clusters
		suppressed.cluster_data.clear();
		stationary.cluster_data.clear();
		expressed.cluster_data.clear();

		//assign each data point to cluster that has the closest mean
		for(int i = 0; i < data.size(); i ++){
			dis_sup = suppressed.distance(data.at(i));
			dis_stat = stationary.distance(data.at(i));
			dis_exp = expressed.distance(data.at(i));

			if((dis_sup < dis_stat) && (dis_sup < dis_exp)){
			       suppressed.cluster_data.push_back(data.at(i));
			}
	 		else if((dis_stat <= dis_stat) && (dis_stat <= dis_exp)){
				stationary.cluster_data.push_back(data.at(i));
			}
			else{
				expressed.cluster_data.push_back(data.at(i));
			}	
		}
		
		//calculate new cluster means 
		sup_mean = statsS::statsC::mean(suppressed.cluster_data);
		stat_mean = statsS::statsC::mean(stationary.cluster_data);
		exp_mean = statsS::statsC::mean(expressed.cluster_data);

		//calc absolute difference of the previous and current means
		sum_means = std::abs(suppressed.getmean()-sup_mean) + std::abs(stationary.getmean()-stat_mean) + std::abs(expressed.getmean()-exp_mean);

		//set new means 
		suppressed.setmean(sup_mean);
		stationary.setmean(stat_mean);
		expressed.setmean(exp_mean);
	}

	//output final cluster means 
	std::cout << "suppressed mean: " << suppressed.getmean() << "\n";
	std::cout << "stationary mean: " << stationary.getmean() << "\n";
	std::cout << "expressed mean: " << expressed.getmean() << "\n";

	//separate genes into their appropriate cluster files 
	float stat_min = statsS::statsC::min(stationary.cluster_data);
	float stat_max = statsS::statsC::max(stationary.cluster_data);

	char gene_string[100];

	infile.clear();
	infile.seekg(0);
	std::ifstream genefile("microarray/gene_list.txt");
	std::ofstream supfile("suppressed_genes.txt");
	std::ofstream statfile("stationary_genes.txt");
	std::ofstream expfile("expressed_genes.txt");

	if(infile.is_open() && genefile.is_open()){
		while(infile >> num){
			genefile >> gene_string;
			if(num < stat_min){
				//write to suppressed file
				supfile << gene_string << " " << num << "\n";
			}
			else if(num > stat_max){
				//write to expressed file
				expfile << gene_string << " " << num << "\n";
			}
			else{
				//write to stationary file
				statfile << gene_string << " " << num << "\n";
			}
		}
		infile.close();
		genefile.close();
		supfile.close();
		statfile.close();
		expfile.close();
	}
	else{
		std::cout << "Could not open log ratio or gene_list file.\n";
		exit(EXIT_FAILURE);
	}



	return 0;
}

