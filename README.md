# detect-cancer-dna-sequence
Detect cancerous and non-cancerous DNA sequences from datasets, Using cpp programming language. One of application of LCS


## Dataset Description: 
Dataset consists of all types of cancer and its respective DNA Sequences. It consists of 152 types of cancer.

## Approach Used:
The program accepts a 22-character-long string of a person's DNA sequence as input. It now looks for Longest Common Subsequences (LCS), which are similar to Cancer Genomes, which are also DNA Sequences. If the matched subsequence is found in more than 40% of cancer genomes, it concludes that cancer has been found and also indicates which cancer and stage it is in. Also data visualization is also done with help of Matplotlib of which primary cancers are in what stage. 

## Algorithm Used:
Using Dynamic Programming to find LCS
The following steps are followed for finding the longest common subsequence.
1.	Create a table of dimension n+1*m+1 where n and m are the lengths of X and Y respectively. The first row and the first column are filled with zeros.

Fill each cell of the table using the following logic.
2.	If the character corresponding to the current row and current column are matching, then fill the current cell by adding one to the diagonal element. Point an arrow to the diagonal cell.
3.	Else take the maximum value from the previous column and previous row element for filling the current cell. Point an arrow to the cell with maximum value. If they are equal, point to any of them.
4.	Step 2 is repeated until the table is filled.
5.	The value in the last row and the last column is the length of the longest common subsequence.
6.	In order to find the longest common subsequence, start from the last element and follow the direction of the arrow. The elements corresponding to () symbol form the longest common subsequence.

## Time Complexity:
In the dynamic algorithm, the results obtained from each comparison between elements of X and the elements of Y are stored in a table so that they can be used in future computations.

So, the time taken by a dynamic approach is the time taken to fill the table (ie. O(m*n)).
