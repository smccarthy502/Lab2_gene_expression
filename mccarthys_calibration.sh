#author: Sarah McCarthy 
#created: March 10, 2021

#!/bin/bash

dir=microarray

echo How many microarray points will be processed?
read num_points

cfun=preprocessing

if [ -f "summary_cluster.txt" ] 
then 
	rm "summary_cluster.txt"
fi

for(( i=0;i<=6;i++ ))
do
	#call preprocessing function for each time point 
	./$cfun $dir/red_$i.dat $dir/red_background_$i.dat $dir/green_$i.dat $dir/green_background_$i.dat log_ratio_$i.dat $num_points	
	
	if [[ $? -ne 0 ]] 
	then 
		echo something went wrogn during preprocessing time $i
		exit 1
	fi

	#copy output of preprocessing function to log_ratio_input.dat
	cp log_ratio_$i.dat log_ratio_input.dat

	echo TIME POINT $i: >> summary_cluster.txt

	#call clustering program 
	clustering >> summary_cluster.txt

	#copy outputs of clustering program to file that indicates time point 
	cp expressed_genes.txt expressed_genes_$i.txt
	cp stationary_genes.txt stationary_genes_$i.txt
	cp suppressed_genes.txt suppressed_genes_$i.txt
	
	#write number genes in each cluster for summary file 
	echo number of suppressed genes: $(wc -l suppressed_genes.txt | cut -d ' ' -f 1) >> summary_cluster.txt 
	echo number of stationary genes: $(wc -l stationary_genes.txt | cut -d ' ' -f 1) >> summary_cluster.txt
	echo number of expressed genes: $(wc -l expressed_genes.txt | cut -d ' ' -f 1) >> summary_cluster.txt
	echo >> summary_cluster.txt


done






