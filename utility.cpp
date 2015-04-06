#include "global.h"

using namespace std;

// This file contains:
// 1. I/O Helper Functions
// 2. Statistics Helper Functions (mean, standard deviation, etc.)
// 3. Memory Management Helper Functions (allocation, zap)

// I/O Helper Functions

void openFile(ifstream &stream, string filename)
{
	stream.open(filename.c_str(), ios::in);
	if (!stream)
	{
		cerr << "Error in reading " << filename << ". Exiting..." << endl;
		exit(-1);
	}
	return;
}

void openFile(ofstream &stream, string filename)
{
	stream.open(filename.c_str(), ios::out);
	if (!stream)
	{
		cerr << "Error in reading " << filename << ". Exiting..." << endl;
		exit(-1);
	}
	return;
}

void readFile(data_t &matrix, string filename, int rows, int columns)
{
	ifstream in;
	openFile(in, filename);
	
	matrix.resize(rows, vector<double> (columns));
	
	string tempLine;
	double tempValue = 0.0;
	
	for(int i=0; i < rows; i++) 
	{
		getline(in, tempLine);
		
		stringstream ss(tempLine);
		string field;
		
		for(int j = 0; j < columns; j++)
		{
			getline(ss, field, ',');
			stringstream fs(field);
			fs >> tempValue;

			matrix[i][j] = tempValue;
		}
	}

	in.close();
	return;
}

// Statistics Helper Functions

double average_array (double *data_set, const int length)
{
	double sum = 0.0;

	for (int i = 0; i < length; i++)
	{
		sum += data_set[i];
	}

	return (sum / length);
}

double average_array (vector<double> data, const int length)
{
	double sum = 0.0;
	for (int i = 0; i < length; i++)
	{
		sum += data[i];
	}

	return (sum/length);
}

double average_array_colwise (double **data, int rows, int cols, int col_of_interest)
{
	double dummy_sum = 0.0;
	double average = 0.0;

	for (int row_it = 0; row_it < rows; row_it++)
	{
		dummy_sum = dummy_sum + data[row_it][col_of_interest];
	}

	average = dummy_sum / rows;

	return average;

}

double average_array_colwise (double **data, int rows, int cols, int col_of_interest, int startYear)
{
	double dummy_sum = 0.0;
	double average = 0.0;

	for (int row_it = startYear; row_it < rows; row_it++)
	{
		dummy_sum = dummy_sum + data[row_it][col_of_interest];
	}
	
	average = dummy_sum / (rows-startYear);

	return average;

}


double std_dev_colwise(double **data, int length, int col_of_interest)
{
	double sum = 0.0;

	for (int i = 0; i < length; i++)
	{
		sum += data[i][col_of_interest];
	}

	double mean = sum / length;

	double squared_sum = 0.0;

	for (int i = 0; i < length; i++)
	{
		squared_sum += pow((data[i][col_of_interest]-mean),2.0);
	}

	return sqrt( squared_sum / (length-1) );
}

double std_dev_colwise(double **data, int length, int col_of_interest, int startYear)
{
	double sum = 0.0;

	for (int i = startYear; i < length; i++)
	{
		sum += data[i][col_of_interest];
	}

	double mean = sum / (length-startYear);

	double squared_sum = 0.0;

	for (int i = startYear; i < length; i++)
	{
		squared_sum += pow((data[i][col_of_interest]-mean),2.0);
	}

	return sqrt( squared_sum / (length-1 - startYear) );
}

double maxValue(double d1, double d2, double d3, double d4)
{
	if(d1 > d2 && d1 > d3 && d1 > d4)
		return d1;
	else if (d2 > d3 && d2 > d4)
		return d2;
	else if(d3 > d4)
		return d3;
	else
		return d4;
}
double meanValue(double d1, double d2, double d3, double d4)
{
	return (d1 + d2 + d3 + d4)/4;
}

void zeroes(double **data, const int rows, const int cols)
{
	for (int row_it = 0; row_it<rows; row_it++)
	{
		for (int col_it = 0; col_it<cols; col_it++)
		{
			data[row_it][col_it] = 0.0;
		}
	}
	return;
}

void zeroes(double *data, const int length)
{
	for (int row_it = 0; row_it<length; row_it++)
	{
			data[row_it] = 0.0;
	}
	return;
}

void normalize_array(double **data, double* averaged_values, double* stded_values, double** normalized_values, int rows, int cols)
{
	for (int col_it = 0; col_it < cols; col_it++)
	{
		averaged_values[col_it] =  average_array_colwise(data, rows, cols, col_it);
		stded_values[col_it] = std_dev_colwise(data, rows, col_it);

		for (int row_it = 0; row_it < rows; row_it++)
			normalized_values[row_it][col_it]=(data[row_it][col_it]-averaged_values[col_it])/stded_values[col_it];
		
	}
	return;
}

void index_array(double* indexed_array, const int rows, const int cols, int year_start, double** data)
{
	int a, b;
	for (int x = 0; x<rows; x++)
	{
		a = x*cols;
		b = x+year_start;
		for (int y = 0; y<cols; y++)
			indexed_array[a+y] = data[b][y];
	}
}	

// Memory Management Helper Functions

void general_1d_allocate(double *(&data), int length)
{
	data = new double [length];

	for (int i = 0; i < length; i++) data[i] = 0.0;

	return;
}

void general_1d_allocate(double *(&data), int length, double value)
{
	data = new double [length];

	for (int i = 0; i < length; i++) data[i] = value;

	return;
}

void general_1d_allocate(int *(&data), int length)
{
	data = new int [length];

	for (int i = 0; i < length; i++) data[i] = 0;

	return;
}

void general_1d_allocate(int *(&data), int length, int init_value)
{
	data = new int [length];

	for (int i = 0; i < length; i++) data[i] = init_value;

	return;
}

void general_2d_allocate(double **&data, int rows, int cols)
{
	data = new double *[rows];
	for (int row_it = 0; row_it<rows; row_it++) data[row_it] = new double[cols];

	for (int row_it = 0; row_it < rows; row_it++)
	{
		for (int col_it = 0; col_it < cols; col_it++)
		{
			data[row_it][col_it] = 0.0;
		}
	}
}

void general_2d_allocate(double **&data, int rows, int cols, double value)
{
	data = new double *[rows];
	for (int row_it = 0; row_it<rows; row_it++) data[row_it] = new double[cols];

	for (int row_it = 0; row_it < rows; row_it++)
	{
		for (int col_it = 0; col_it < cols; col_it++)
		{
			data[row_it][col_it] = value;
		}
	}
}


void general_2d_allocate(int **(&data), int rows, int cols)
{
	data = new int *[rows];
	for (int row_it = 0; row_it<rows; row_it++) data[row_it] = new int[cols];

	for (int row_it = 0; row_it < rows; row_it++)
	{
		for (int col_it = 0; col_it < cols; col_it++)
		{
			data[row_it][col_it] = 0;
		}
	}
}

void general_2d_allocate(int **(&data), int rows, int cols, int init_value)
{
	data = new int *[rows];
	for (int row_it = 0; row_it<rows; row_it++) data[row_it] = new int[cols];

	for (int row_it = 0; row_it < rows; row_it++)
	{
		for (int col_it = 0; col_it < cols; col_it++)
		{
			data[row_it][col_it] = init_value;
		}
	}
}

void zap(double *(&data))
{
	if (data != NULL)
	{
		delete [] data;
		data = NULL;
	}

	return;
}

void zap(int *(&data))
{
	if (data != NULL)
	{
		delete [] data;
		data = NULL;
	}

	return;
}

void zap(double **(&data), int rows)
{
	if (data != NULL)
	{
		for (int row_it = 0; row_it < rows; row_it++)
		{
			delete [] data[row_it];
		}
		delete [] data;
		data = NULL;
	}
	return;
}

void zap(int **(&data), int rows)
{
	if (data != NULL)
	{
		for (int row_it = 0; row_it < rows; row_it++)
		{
			delete [] data[row_it];
		}
		delete [] data;
		data = NULL;
	}
	return;
}
