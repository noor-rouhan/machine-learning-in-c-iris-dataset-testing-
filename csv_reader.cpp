#include <iostream>
#include <fstream>

using namespace std;

float iris_param_matrix[150][4];

	string iris_result[150];

	float y[150];

void iris_dataset_loading(){

	ifstream ip("iris.csv");

	if(!ip.is_open()){
		cout << "Error: file is open." << endl;
	}

	//sepal_length,sepal_width,petal_length,petal_width,species
	string sepal_length;
	string sepal_width;
	string petal_length;
	string petal_width;
	string species;

	int i = 0;
	///sepal_length,sepal_width,petal_length,petal_width,species first row has been deleted from iris.csv

	while(ip.good() && i < 150){

		getline(ip,sepal_length,',');
		getline(ip,sepal_width,',');
		getline(ip,petal_length,',');
		getline(ip,petal_width,',');
		getline(ip,species,'\n');

		cout << "sepal_length: " << sepal_length << " ," << species   << endl;

		iris_param_matrix[i][0] = ::atof(sepal_length.c_str());
		iris_param_matrix[i][1] = ::atof(sepal_width.c_str());
		iris_param_matrix[i][2] = ::atof(petal_length.c_str());
		iris_param_matrix[i][3] = ::atof(petal_width.c_str());
		iris_result[i] = species;

		//cout << " float: " << temp <<endl;

		i++;

	}

	ip.close();

	for (int i = 0; i < 150; i++){
		string result = iris_result[i];

		if(result == "setosa"){

			y[i]= 1;

		}
		else{
			y[i] = 0;
		}

	}



	cout<< "sepal_length:" << iris_param_matrix[149][0]
	 << " sepal_width:"<<iris_param_matrix[149][1]<<
	  " petal_length: "<<iris_param_matrix[149][2]<<
	  " petal_width: " <<  iris_param_matrix[149][3] <<
	   " species: " << iris_result[149] << " "<< y[149] << endl;
}

int main(){

	iris_dataset_loading();

	cout << "matrix loading testing" << endl;


	for(int i = 0; i < 150; i++){

		//for(int j = 0; j < 4; j++){

			cout<< "sepal_length:" << iris_param_matrix[i][0]
	 		<< " sepal_width:"<<iris_param_matrix[i][1]<<
	  		" petal_length: "<<iris_param_matrix[i][2]<<
	  		" petal_width: " <<  iris_param_matrix[i][3] <<
	  		" species: " << iris_result[i] << " " << y[i] <<endl;
		//}
	}

	return 0;

}