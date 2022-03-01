
#include "mccarthy_stats.hpp"

//returns the max value of the data
float statsS::statsC::max(std::vector<float> data){
	//set max to a ridiculous number that is lower than what we will deal with
        float max = -1000000000;

        //go through all data, if bigger than previous max set it as the new max
        for(int i = 0; i < data.size(); i++){
                if(data.at(i) > max){
                        max = data.at(i);
                }
        }

        return max;
}

//returns the min value of the data
float statsS::statsC::min(std::vector<float> data){
	//set min to a ridiculous number
        float min = 100000000;

        //go through all data, if less than previous set as new min
        for(int i = 0; i < data.size(); i++){
                if(data.at(i) < min){
                        min = data.at(i);
                }
        }

        return min;
}

//returns the mean of the data
float statsS::statsC::mean(std::vector<float> data){
	float sum = 0;
        float mean;

        //find sum of all data
        for(int i = 0; i < data.size(); i++){
                sum += data.at(i);
        }

        //divide sum by the number of elements
        mean = sum / data.size();
        return mean;
}

//returns the standard deviation of the data
float statsS::statsC::stdDeviation(std::vector<float> data){
	float sum = 0;
        float mean;

        //find sum of all data
        for(int i = 0; i < data.size(); i++){
                sum += data.at(i);
        }

        //divide sum by the number of elements
        mean = sum / data.size();
        
	sum = 0;
	float stddev;

        //find sum of each the square of the difference between each point and the mean
        for(int i = 0; i < data.size(); i++){
                sum +=  pow((data.at(i) - mean), 2.0);
        }

        //divide the sum by number of points and take square root
        stddev = pow((sum / data.size()), 0.5);
        return stddev;
}


//returns the histogram of the data
void statsS::statsC::histogram(std::vector<float> data){
	std::vector<int> hist(15, 0);

	float sum = 0;
        float avg;

        //find sum of all data
        for(int i = 0; i < data.size(); i++){
                sum += data.at(i);
        }

        //divide sum by the number of elements
        avg = sum / data.size();

	sum = 0;
	float stddev;

        //find sum of each the square of the difference between each point and the mean
        for(int i = 0; i < data.size(); i++){
                sum +=  pow((data.at(i) - avg), 2.0);
        }

        //divide the sum by number of points and take square root
        stddev = pow((sum / data.size()), 0.5);

        //go through each point and figure out which bin it belongs to
        for(int i = 0; i < data.size(); i++){
                if(data.at(i) < (avg - (3*stddev))){
                        hist.at(0)++;
                }
                else if((data.at(i) < (avg - (2.2*stddev)))&&(data.at(i) >= (avg - (2.6*stddev)))){
                        hist.at(1)++;
                }
                else if((data.at(i) < (avg - (1.8*stddev)))&&(data.at(i) >= (avg - (2.2*stddev)))){
                        hist.at(2)++;
                }
                else if((data.at(i) < (avg - (1.4*stddev)))&&(data.at(i) >= (avg - (1.8*stddev)))){
                        hist.at(3)++;
                }
                else if((data.at(i) < (avg - (1.0*stddev)))&&(data.at(i) >= (avg - (1.4*stddev)))){
                        hist.at(4)++;
                }
                else if((data.at(i) < (avg - (0.6*stddev)))&&(data.at(i) >= (avg - (1.0*stddev)))){
                        hist.at(5)++;
                }
                else if((data.at(i) < (avg - (0.2*stddev)))&&(data.at(i) >= (avg - (0.6*stddev)))){
                        hist.at(6)++;
                }
                else if((data.at(i) < (avg + (0.2*stddev)))&&(data.at(i) >= (avg - (0.2*stddev)))){
                        hist.at(7)++;
                }
                else if((data.at(i) < (avg + (0.6*stddev)))&&(data.at(i) >= (avg + (0.2*stddev)))){
                        hist.at(8)++;
                }
 		else if((data.at(i) < (avg + (1.0*stddev)))&&(data.at(i) >= (avg + (0.6*stddev)))){
                        hist.at(9)++;
                }
                else if((data.at(i) < (avg + (1.4*stddev)))&&(data.at(i) >= (avg + (1.0*stddev)))){
                        hist.at(10)++;
                }
                else if((data.at(i) < (avg + (1.8*stddev)))&&(data.at(i) >= (avg + (1.4*stddev)))){
                        hist.at(11)++;
                }
                else if((data.at(i) < (avg + (2.2*stddev)))&&(data.at(i) >= (avg + (1.8*stddev)))){
                        hist.at(12)++;
                }
                else if((data.at(i) < (avg + (2.6*stddev)))&&(data.at(i) >= (avg + (2.2*stddev)))){
                        hist.at(13)++;
                }
                else{
                        hist.at(14)++;
                }
        }

        //find the max number of points in a bin
        float max = -1;
        for(int i = 0; i < 15; i++){
                if(hist.at(i) > max){
                        max = hist.at(i);
                }
        }

        std::cout << "\n";
 	//print the histogram
        //bin with max number of points will have 20 stars
        //every other bin is based on percentage of the max number of points in a bin
        for(int i = 20; i > 0; i--){
                for(int j = 0; j < 15; j++){
                        //insert print statements
                        if(((hist.at(j) / max)* 20) > i){
                                std::cout << "* ";
                        }
                        else{
                                std::cout << "  ";
                        }
                }
                std::cout << "\n";
        }

        for(int i = 0; i < 15; i++){
                std::cout << "- ";
        }

        std::cout << "\neach * represents about " << round((max/20)) << " data points \n\n";

        return;
}

