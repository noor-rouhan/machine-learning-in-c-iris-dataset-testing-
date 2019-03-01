#include <iostream>
#include<math.h>
#include <fstream>

using namespace std;

typedef unsigned char U8;
typedef unsigned short int U16;

const U16 flatten_length_of_image = 784;
///////////////////////////////////
float iris_param_matrix[150][4];
string iris_result[150];
float y[150]; //encoded output//
//Here serosa is 1 and other species are encoded as 0. ////
////binary classifier//////////////
///////////////////////////////////

float sigmoid(float z){
 // return 1/(1+exp(-z));
    //return (1/(1+exp(-z)))-0.001;
    float sig = ((1/(1+exp(-z)))-0.001);
    return sig<0?sig*-1:sig;
}

///iris dataset loading///
void iris_dataset_loading_csv(){
 
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

    string result = iris_result[i];

    if(result == "setosa"){y[i]= 1;}
    else{y[i] = 0;}

    i++;
  }

  ip.close();
  cout<< "sepal_length:" << iris_param_matrix[149][0]
   << " sepal_width:"<<iris_param_matrix[149][1]<< 
   " petal_length: "<<iris_param_matrix[149][2]
  <<" petal_width: " <<  iris_param_matrix[149][3] 
  << " species: " << iris_result[149] << endl;

}

int main(){

  float learning_rate = .0007;
  float mat_weights[4];
  float mat_weights_dw[4];
  float b,z,dz_db,A,cost;
  ///////////////////////////
  iris_dataset_loading_csv();
  ///////////////////////////

  ////initializing weights////////////////////////
  for(U16 i = 0; i < 4; i++){
  ////mat_weights[i] = (float)(rand()%100)/100;
    mat_weights[i] = (float)0;
  } b = 0;
  ////end initializing weights and bias///////////

///getting iris parameter row one by one////////
  for(int i = 0; i < 150; i++){
////// calculating z = w transpose X + b ///////
    for (int j = 0; j < 4; j++ ){   
      z = z+ mat_weights[j]*iris_param_matrix[i][j];;
    } z = z + b;
    ////end caculation of z/////

  A = sigmoid(z); // A = y hat = sigmoid(z) computed/// sigmoid function/////
  cost = -(y[i]*log(A) + (1-y[i])*log(1-A)); // cost function
  cout << "prediction: " << A << " ,cost: " <<cost << " ,y=" << y[i]<<endl;
  dz_db = A - y[i];  /// calculate dz= db = A-y /////////

/////////optimization///////////////////////////////
    for (U16 j = 0; j < 4; j++){
      mat_weights_dw[j] = iris_param_matrix[i][j]*dz_db;
      mat_weights[j] = mat_weights[j] - learning_rate * mat_weights_dw[j];
  } b = b - learning_rate * dz_db;
  ///////end optimization////////////////////

  /// accuracy ////

}
///// end outer loop//////

//prediction///
    return 0;
}



