# Lab2_gene_expression

This code analyzes data collected on gene expression of yeast cells during sporualtion. Data was collected using microarray analysis, which determines the amount of mRNA produced at different points of time. The amount of mRNA produced indicates which genes are expressed or surpressed. Using code from mccarthy_vector_ops.cpp, data was processed in mccarthy_preprocessing.cpp to account for factors that could affect fluorescence of the microarray chips. The results of mccarthy_preprocessing.cpp were then used in mccarthys_k_means.cpp for clustering. The clusters formed indicate which genes are suppressed, stationary, or expressed. mccarthys_calibration.sh is a bash file used to run the preprocessing and the clustering program. mccarthys_genequery.sh is a bash file used to return the status of the gene at all 7 time points.


CODE FILES:
mccarthys_vector_ops.cpp -- vector operations
mccarthys_preprocessing.cpp -- process data
mccarthy_k_means.cpp -- clustering 
mccarthys_calibration.sh -- running processing 
mccarthys_genequery.sh
