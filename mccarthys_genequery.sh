#find specific gene in clusters
#!/bin/bash

gene=$1

echo $gene
#echo in suppressed:
#if [ $(grep $gene suppressed_genes_0.txt) ] 
#then 
#	echo found in suppressed
#fi
#echo in expressed:
#if [ $(grep $gene expressed_genes_0.txt) ] 
#then 
#	echo found in expressed
#fi

for ((i=0;i<=6;i++ )) 
do
	if [[ $(grep -w $gene suppressed_genes_$i.txt) ]] 
	then 
		echo time point $i: suppressed
	elif [[ $(grep -w $gene stationary_genes_$i.txt) ]] 
	then 
		echo time point $i: stationary
	elif [[ $(grep -w $gene expressed_genes_$i.txt) ]] 
	then 	
		echo time point $i: expressed 
	fi
done


