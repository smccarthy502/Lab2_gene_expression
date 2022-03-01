/* author: Sarah McCarthy 
 * created: March 11, 2021 
 *
 * this program takes in a data file and creates 3 clusters; the cluster means are standard output 
 */

#ifndef K_MEANS
#define K_MEANS 

#include <vector> 
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include "mccarthy_stats.hpp"

class cluster {
	public: 
		//constructor 
		cluster();

		//get name of cluster
		std::string getname();

		//set name of cluster 
		void setname(std::string sname);

		//get the mean of the cluster 
		float getmean();

		//set the mean of the cluster
		void setmean(float smean);

		//find the distance from the mean to the point 
		float distance(float point);

		//datapoint asociated with the cluster 
		std::vector<float> cluster_data;

	private: 
		//name of the cluster
		std::string cluster_name;

		//mean of the cluster 
		float cluster_mean;

};

#endif
